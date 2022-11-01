// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 07-09-2022
// =========================================================

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){

    //Declaracion de variables iniciales
    int size=0;
    cin>>size;
    vector<vector<bool>> grafo;
    int n = 50; 
    int colors[size];

    // Se llena el vector dependiendo del tamano del grafo
    for (int i = 0; i < size; i++) {
        vector<bool> temp;
        for (int j = 0; j < size; j++) {
            bool tempBool;
            cin>>tempBool;
            temp.push_back(tempBool);
        }
        grafo.push_back(temp);
    }
    
    // Se establece el valor de los colores dependiendo del tamano
    for (int i = 0; i < size; i++){
        colors[i] = 0;
    }

    return 0;
}