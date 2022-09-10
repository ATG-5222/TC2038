// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 26-08-2022
// =========================================================


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;



//Complejidad
int Sum(string str) {
    int sum = 0;

    for (int i = 0; i <= str.size(); i++) {
        sum += str[i];
    }

    return sum;
}

// Función main -------------------------------------
//Complejidad= O(n^2)
int main(int argc, char* argv[]) {
    vector<vector<char>> M;//Matriz
    string fname; 
    int n; 
    cin >> fname;
    cin >> n;

    // Lectura de archivo
    ifstream arch(fname);
    string str, file_contents;

    vector<int> line;
    char x;
    while (arch.get(x)) {
        line.push_back(x);
    }

    arch.close();


    //Desplegar matriz
    for (int i = 0; i < line.size(); i++){
        vector<char> aux;
        for (int j = 0; j < n; j++) {
            if (i >= line.size()) {
                aux.push_back(char(n));
            }
            if (i <= line.size()){
                aux.push_back(line[i]);
            }
            if(j + 1 < n){
                i++;
            }
        }
        M.push_back(aux);
    }

    // Dispersión (hash)
    int mSize = M.size();
    vector<int> a;

    for (int i = 0; i < mSize; i++) {
        vector<char> v = M[i];
        string str(v.begin(), v.end());

        if ((i + 1) == mSize) {
            str.push_back(char(n));
            a.push_back((Sum(str) % 256));
        } else {
            a.push_back((Sum(str) % 256));
        }
    }

    stringstream res;
    string in;

    for (int i = 0; i < mSize; i++) {
        stringstream Intro;
        Intro << hex << a[i];
        if ((Intro.str()).size() == 1) {
            res << "0";
            res << hex << a[i];
        } else {
            res << hex << a[i];
        }
    }

    string r = res.str();
    for (int i = 0; i < r.size(); i++) {
        r[i] = toupper(r[i]);
    }
    cout << r;

    return 0;
}