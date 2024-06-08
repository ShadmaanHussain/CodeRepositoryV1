#include <iostream>
#include <climits>
using namespace std;

void arr_init(int *, int);
void arr_print(int *, int);
int arr_max(int *, int);
int arr_min(int *, int);
void arr_reverse(int *, int);
int arr_binary_search(int *, int, int);
void arr_selection_sort(int *, int);
void arr_bubble_sort(int *, int);
void swap(int &, int &);
void arr_insertion_sort(int *, int);
int arr_merge_sorted(int*, int, int*, int, int*);

int main()
{
    int a[100], b[100], c[100];
    // Input the number of elements and the array
    int si_a, si_b;
    cin >> si_a >> si_b;
    arr_init(a, si_a);
    arr_init(b, si_b);
    int si_c = arr_merge_sorted(a, si_a, b, si_b, c);
    arr_print(c, si_c);
    return 0;
}

// Function for array initialization
void arr_init(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

// Printing an array
void arr_print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

// Function for returning the maximum element of the array
int arr_max(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

// Function for returning the minimum element of the array
int arr_min(int a[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

// Reversing the same array
void arr_reverse(int a[], int n)
{
    int i = 0;
    int j = n - 1;
    int temp;
    while (j > i)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

// Binary Search
int arr_binary_search(int *a, int n, int x)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        if (x > a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

// Selection Sort
void arr_selection_sort(int *a, int n)
{
    int start = 0;
    // After every iteration the size of the array becomes one less as we start from the next index (or the unsorted part)
    while (start < n)
    {
        int min_index = start;
        // Finding the minimum in the unsorted part
        for (int i = start; i < n; i++)
        {
            if (a[i] < a[min_index])
            {
                min_index = i;
            }
        }
        // Swapping
        int temp = a[start];
        a[start] = a[min_index];
        a[min_index] = temp;
        // Updating start
        start++;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Bubble Sort
void arr_bubble_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Insertion Sort
// My Variation - Long Version
// void arr_insertion_sort(int *a, int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int j, current_card = a[i];
//         // Finding the correct position (j will give us the correct position)
//         for (j = i - 1; j >= 0; j--)
//         {
//             if (current_card >= a[j])
//             {
//                 break;
//             }
//         }
//         j++; // Since for the above loop to be false j will be one less than the correct position.
//         // Shifting all elements from j to i - 1 one place forward
//         for (int k = i - 1; k >= j; k--)
//         {
//             a[k + 1] = a[k];
//         }

//         // Putting current element in the right place
//         a[j] = current_card;
//     }
// }

// Another Variation - Short Version
void arr_insertion_sort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (current < a[j])
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = current;
    }
}

// Merge two Sorted Arrays
int arr_merge_sorted(int* a, int si_a, int* b, int si_b, int* c)
{
    int k = 0, i = 0, j = 0;
    while ((i < si_a) && (j < si_b))
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else {
            c[k] = b[j];
            j++;
            k++;
        }
    }

    if(i == si_a)
    {
        for (; j < si_b; j++)
        {
            c[k] = b[j];
            k++;
        }
    }
    else
    {
        for(; i < si_a; i++)
        {
            c[k] = a[i];
            k++;
        }
    }
    return k;
}