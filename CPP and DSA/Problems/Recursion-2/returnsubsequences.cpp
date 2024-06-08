#include <bits/stdc++.h>
using namespace std;

int subs(string input, string output[])
{
    if (input.size() == 0)
    {
        output[0] = "";
        return 1;
    }
    string smallStr = input.substr(1);
    int smallOutputSize = subs(smallStr, output);
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return 2 * smallOutputSize;
}

int main()
{
    string input;
    cin >> input;
    int strlen = pow(2, input.size());
    string *output = new string[strlen];
    int size = subs(input, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }
    delete [] output;
    return 0;
}