// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 23/11/2022
// =========================================================

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include "kruskal.hpp"
#include "maxflow.hpp"
#include "tsp.hpp"

using namespace std;

int main() {

    vector <int> x;
    vector <int> y;
    vector <vector <int> > z;
    int inicio, fin, n, m, r;
    cin >> n >> inicio >> fin;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> m;
            if(m == -1)
            m = 999999; 
            x.push_back(m);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> m;
                y.push_back(m);
            }
            z.push_back(y); y.clear();
        }
        G res(n);
        cout << "-------------------------------------\nProblem 1" << endl;
        res.Dijkstra(x, n);
        res.Kruskal();
        cout << "-------------------------------------\nProblem 2" << endl;
        Tsp(x, n, inicio);
        cout << "-------------------------------------\nProblem 3" << endl;
        cout << "Maximum flow from " << inicio << " to " << fin << " is " << MaxFlow(z, inicio, fin) << endl;
        cout << "-------------------------------------" << endl;

        return 0;
}