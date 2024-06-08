#include<bits/stdc++.h>
using namespace std;

int main() {
    // Taking the input
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    // Main Algorithm
    unordered_map<int,int> isPresent;
    vector<int> output;
    for(int i = 0; i < n; i++) {
        if(isPresent.count(input[i]) == 0) {
            isPresent[input[i]] = 1;
            output.push_back(input[i]);
        }
    }

    // Displaying the output
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}