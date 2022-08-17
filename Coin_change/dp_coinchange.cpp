#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> row;
#define INT_MAX 9999999;

int coinchange(int n,vector<int>& coins) {
    row v(n+1, 0);
    for (int i=1; i<n+1; i++){
        int min = INT_MAX;
        for (int j=0; j<coins.size(); j++) {
            int x = i - coins[j];
            if (x >= 0 && v[x] < min) {
                min = v[x];
            }
        }
        v[i] = 1 + min;
    }
    return v.back();
}

int main() {
    int n; 
    cin >> n;
    vector<int> coins = {17,14,4,20,1,19,8};
    cout << coinchange(n, coins) << endl;
    return 0;
}