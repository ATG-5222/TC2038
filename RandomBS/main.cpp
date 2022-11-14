// =========================================================
// Archivo: main.cpp
// Autores:
//      Aldo Tena García - A01275222
// Fecha: 14/11/2022
// =========================================================

#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int part(int elems[], int ini, int fin) {
    int ind = ini;
    for(int i=ini; i<fin; i++) {
        if(elems[i] < elems[fin]) {
            swap(elems[i], elems[ind]);
            ind = ind+1;
        }
    }
    swap(elems[fin], elems[ind]);
    return ind;
}

int getRandomPivot(int elems[], int ini, int fin) {
    int ran = rand();
    int pvt = ini + ran%(fin-ini+1); 
    swap(elems[fin], elems[pvt]);
    return part(elems, ini, fin);
}

void QuickSort(int arr[], int ini, int fin){
    if(ini < fin) {
        int ind = getRandomPivot(arr, ini, fin);
        QuickSort(arr, ini, ind-1);
        QuickSort(arr, ind+1, fin);
    }
}

int main() {
    int n, parr; 
    cin >> n;
    int elems[0xfffff];

    for (int i = 0; i < n; i++) {
        cin >> elems[i];
    }

    parr=n-1;
    QuickSort(elems, 0, parr);
    for (int i=0; i<n; i++) {
        cout<<elems[i]<<" "; 
    }
}