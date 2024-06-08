#include <bits/stdc++.h>
using namespace std;

int keypad(int n, string output[])
{
    if (n == 0)
    {
        output[0] = "";
        return 1;
    }
    int size = keypad(n / 10, output);
    int digit = n % 10;
    string container;
    switch (digit)
    {
    case 2:
        container = "abc";
        break;
    case 3:
        container = "def";
        break;
    case 4:
        container = "ghi";
        break;
    case 5:
        container = "jkl";
        break;
    case 6:
        container = "mno";
        break;
    case 7:
        container = "pqrs";
        break;
    case 8:
        container = "tuv";
        break;
    case 9:
        container = "wxyz";
        break;
    }
    int p = 0;

    string *original = new string[size];
    for (int i = 0; i < size; i++)
    {
        original[i] = output[i];
    }
    for (int i = 0; i < container.size(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            output[p] = original[j] + container[i];
            p++;
        }
    }

    delete[] original;
    return size * container.size();
}

int main()
{
    int n;
    cin >> n;
    string output[100];
    int size = keypad(n, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}