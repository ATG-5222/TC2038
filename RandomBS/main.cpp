// =========================================================
// Archivo: main.cpp
// Autores:
//      Aldo Tena García - A01275222
//      Renato Sebastían Ramirez Calva - A01275401
// Fecha: 20/11/2022
// =========================================================

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int binarySearch(int *array, int key, int low, int high){
    int mid;
    if (high > low){
        mid = low + ((high - low) / 2);
        if (key == array[mid]){
            return 1;
        }else if (key < array[mid]){
            return 1 + binarySearch(array, key, low, mid - 1);
        }else{
            return 1 + binarySearch(array, key, mid + 1, high);
        }
    }
    return -1;
} 

int randomBinarySearch(int *array, int key, int low, int high) {
    int mid;
    if (high > low){
        mid = low + (rand() % (high - low + 1));
        if (key == array[mid]){
            return 1;
        } else if (key < array[mid]){
            return 1 + randomBinarySearch(array, key, low, mid - 1);
        } else{
            return 1 + randomBinarySearch(array, key, mid + 1, high);
        }
    }
    return -1;
} 

int main() {

    int N;
    cin >> N;
    int firstArray[N];
    for (int i = 0; i < N; i++) {
        cin >> firstArray[i];
    }

    int M;
    cin >> M;
    int secondArray[M];
    for (int i = 0; i < M; i++){
        cin >> secondArray[i];
    }

    for (int i = 0; i < M; i++){
        int normalBS = binarySearch(firstArray, secondArray[i], 0, secondArray[i]+1);
        if (normalBS == 0){
            normalBS = -1;
        }
        int randomBS = randomBinarySearch(firstArray, secondArray[i], 0, secondArray[i]+1);
        if (randomBS == 0){
            normalBS = -1;
        }
        cout << "Number = " << secondArray[i] << " using binary search = " << normalBS
        << ", using randomized binary search = " << randomBS << endl;
    }

}