#include <iostream>
#include <cstring>
using namespace std;

// shift all the elements left by one place
void shiftleft(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        str[i] = str[i + 1];
    }
}

void removex(char *str)
{   
    // Base Case
    if (str[0] == '\0')
    {
        return;
    }

    // if str[0] is x then shift the entire string left by one position, then call the removex function for this small string that we modified
    if (str[0] == 'x')
    {
        shiftleft(str);
        removex(str);
    }
    else {
        // if the element is not x then we call the function giving it the smaller string
        removex(str + 1);
    }
}

int main()
{
    char str[100];
    cin.getline(str, 100);
    removex(str);
    cout << str << endl;
    return 0;
}