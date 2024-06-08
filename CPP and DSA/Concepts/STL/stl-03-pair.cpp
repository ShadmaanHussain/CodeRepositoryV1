#include <bits/stdc++.h>
using namespace std;

pair<int, int> f()
{
    return {5, 6};
}

int main()
{
    pair<int, string> p = {5, "Shadmaan"};
    cout << p.first << " " << p.second << endl;
    p.first = 19;
    cout << p.first << " " << p.second << endl;
    pair<int, int> q = f();
    cout << q.first << " " << q.second << endl;

    pair<int, int> r[5];
    r[0] = {1, 3};
    r[1] = {3, 7};
    r[2] = {3, 4};
    r[3] = {1, 0};
    r[4] = {5, 1};

    // First sorts on the basis of the first element, if the first element is same, then the second element is seen and the pair with lower value of the second element is kept firsts
    sort(r, r + 5);
    for (int i = 0; i < 5; i++)
    {
        cout << r[i].first << " " << r[i].second << endl;
    }
    return 0;
}