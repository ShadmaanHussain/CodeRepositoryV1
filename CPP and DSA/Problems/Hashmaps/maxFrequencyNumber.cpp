#include<bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int n;
    cin >> n;
    vector<int> input(n);
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    // Main Algo
    unordered_map<int,int> freqOf;
    int max = input[0];
    int maxFreq = 1;
    freqOf[input[0]]++;
    for(int i = 1; i < n; i++) {
        freqOf[input[i]]++;
        if(freqOf[input[i]] > maxFreq) {
            maxFreq = freqOf[input[i]];
            max = input[i];
        }
    }

    // Output
    cout << max << endl;
    return 0;
}