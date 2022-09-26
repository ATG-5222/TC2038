// ================================================
// Archivo: main.cpp
// Autores:
//      Aldo Tena García - A01275222
//      Renato Sebastían Ramirez Calva - A01275401
// Fecha: 28/09/2022
// ===============================================

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int INF = 99999;

// Parte 1 - Algoritmo de Dijkstra
// Complejidad: O(n²)

void Dijkstra(vector <int> &G, int x){
    printf("\nDijkstra: \n");
    for(int d = 0; d < x; ++d){
        int v = 0;
        vector<int> N(x, INF);
        N[d] = 0;
        for(int n = 0; n < x; ++n){
            v = d + n;
            if(v >= x){
                v = v - x;
            }
            for(int m = 0; m < x; ++m){
                if((G[v * x + m] > 0) && (G[v * x + m] + N[v] < N[m])){
                    N[m] = G[v * x + m] + N[v];
                }
            }
        }
        for(int i = 0; i < x; ++i){
            if(i != d) {
                cout << "node " << d + 1 << " to node " << i + 1 << " : " << N[i] << endl;
            }
        }
    }
}

int main() {
    int x;
    vector<int> G;
    cin >> x;

    for(int i = 0; i < x * x; ++i) {
        int d = 0;
        cin >> d;
        G.push_back(d);
    }
    Dijkstra(G, x);

    return 0;
}