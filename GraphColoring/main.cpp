// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 02-11-2022
// =========================================================

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

//Complejidad general del programa: O(n²)

// Verifica que todo este correcto para el grafo y colores
bool verificar(int size, vector<vector<bool>> grafo, int colors[]){
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (grafo[i][j] && colors[j] == colors[i]){
                return false;
            }
        }
    }
    return true;
}

// Funcion que establece el color dependiendo del nodo
bool colorear(int size, vector<vector<bool>> grafo, int n, int i, int colors[]){

    if (i == size){
        if (verificar(size, grafo, colors)){
            for (int i = 0; i < size; i++){
                cout<<"Node " << i << " <-> Color " << colors[i] << endl;
            }
            return true;
        }
        return false;
    }

    for (int j = 1; j<=n; j++) {
        colors[i] = j;
        if (colorear(size, grafo, n, i+1, colors)){
            return true;
        }
        colors[i] = 0;
    }

    return false;
}

int main(){

    //Declaracion de variables iniciales
    int size=0;
    cin>>size;
    vector<vector<bool>> grafo;
    int n = 50; 
    int colors[size];

    // Se llena el vector dependiendo del tamano del grafo
    for (int i = 0; i < size; i++){
        vector<bool> temp;
        for (int j = 0; j < size; j++){
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

    // Ejecuta la funcion y devuelve un error en caso de que
    // obtengamos un false dentro de las demas funciones
    if (!colorear(size, grafo, n, 0, colors)) {
        cout << "Error en el ingreso del grafo";
    }

    return 0;
}