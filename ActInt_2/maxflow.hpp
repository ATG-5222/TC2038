// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 11/11/2022
// =========================================================

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool B(vector<vector<int>> e, int sta, int end, int p[], int n) {
    bool v[n];
    memset(v, 0, n);
    v[sta] = true;
    p[sta] = -1;
    queue<int> q;
    q.push(sta);
    while(!q.empty()){
        int j = q.front(); 
        q.pop();
        for(int i = 0; i < n; i++){
            if(v[i] == false and e[j][i] > 0){
                if(i == end){
                    p[i] = j;
                    return true;
                }
                q.push(i); 
                p[i] = j; 
                v[i] = true;
            }
        }
    }
    return false;
}

int MaxFlow(vector<vector<int>> G, int sta, int end) {
    int n = G.size();
    vector<vector<int>> e(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            e[i][j] = G[i][j];
        }
    }
    int m = 0, p[n];
    while(B(e, sta, end, p, n)){
        int k = INT_MAX;
        for(int i = end; i != sta; i = p[i]){
            int j = p[i]; 
            k = min(k, e[j][i]);
        }
        for(int i = end; i != sta; i = p[i]){
            int j = p[i];
            e[j][i] -= k;
            e[i][j] += k;
        }
        m += k;
    }
    return m;
}