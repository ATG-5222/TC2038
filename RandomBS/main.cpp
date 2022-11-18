// =========================================================
// Archivo: main.cpp
// Autores:
//      Aldo Tena García - A01275222
// Fecha: 18/11/2022
// =========================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int N;

bool checkValue(int *array, int key){
    int value = 0;
    for (int i = 0; i < N; i++){
        if (array[i] == key){
            value++;
        }
    }
    if (value > 0){
        return true;
    }else{
        return false;
    }
}

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
    if (high > low) {
        mid = low + (rand() % (high - low + 1));
        if (key == array[mid]) {
            return 1;
        } else if (key < array[mid]) {
            return 1 + randomBinarySearch(array, key, low, mid - 1);
        } else {
            return 1 + randomBinarySearch(array, key, mid + 1, high);
        }
    }
    return -1;
} 

int main() {

    cin >> N;
    int firstArray[N];
    for (int i = 0; i < N; i++) {
        cin >> firstArray[i];
    }

    int Q;
    cin >> Q;
    int secondArray[Q];

    for (int i = 0; i < Q; i++) {
        cin >> secondArray[i];
    }

    for (int i = 0; i < Q; i++) {
        int normalBS = binarySearch(firstArray, secondArray[i], 0, secondArray[i] + 1);
        if (normalBS == 0) normalBS = -1;
        int randomBS = randomBinarySearch(firstArray, secondArray[i], 0, secondArray[i] + 1);
        if (randomBS == 0) normalBS = -1;
        cout << "Number = " << secondArray[i] << " using binary search = " << normalBS
        << ", using randomized binary search = " << randomBS << endl;
    }

}