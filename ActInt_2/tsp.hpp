// =========================================================
// File: tsp.hpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 30/11/2022
// =========================================================

#include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

//Complejidad de la función B: O(n²)
void Tsp(vector<int>& graph, int m, int n){
  int G[n][n], c = 0;
  for(int i = 0; i< n; i++){
    for(int j = 0; j< n; j++){
      G[i][j] = graph[c];
      c++;
    }
  }

  vector<int> V; 
  vector<int> v;
  v.push_back(0);

  for (int i = 0; i < n; i++){
    if (i != m)
      V.push_back(i);
  }

  int q = INT_MAX, 
  ans = 0;
  do{
    int p = 0, k = m;
    vector<int> T;
    for (int i = 0; i < V.size(); i++){
      p += G[k][V[i]]; k = V[i];
      T.push_back(V[i]);
    }
    p += G[k][m];
    ans = q;
    q = min(q, p);
    if(ans != q){
      v.clear(); v.push_back(m);
      for(int i = 0; i < T.size(); i++)
        v.push_back(T[i]); v.push_back(m);
      }
      T.clear();
    } 
    while(next_permutation(V.begin(), V.end()));

    if(q < 0){
      cout << "There is no possible route." << endl;
    } 
    else {
      cout << "Minimum cost: " << q << "\nPath: ";
      for(int i = 0; i < v.size(); i++)
      cout << v[i] << " "; cout << endl;
    }
}