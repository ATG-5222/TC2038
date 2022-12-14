// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 26-08-2022
// =========================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;


void trunc(int l, int n);
void matrix(int a[][]);


int main(int argc, char* argv[]) {
    ifstream arch;
	std::string range, file, texto;  
    int r, v[], sum, a[][];
    float l;

	std::cin >> file >> range;
    r = stoi(range);
    arch.open(file, ios::in);

    while(!arch.eof()){
        getline(arch, texto);
        for (int i = 0; i < texto.size(); i++){
            
            v[i] = texto[i];
            sum = sum + (int) texto[i];
        }
        
    }
    arch.close();

    //sum = sum%256;
    l = v.size()/r;
    trunc(l, r);

}

void trunc(int l, int n){
    if (l%n != 0){
        l = trunc(l);
        int a[l+1][n];
        matrix(a[l+1][n])
        }
        
    l = trunc(l);
    int a[l][n];
    matrix(a[l][n], n);
}

void matrix( int a[][], int r){
    int e = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < r; j++){
            if (e > (v.size() - 1) ){
                a[i][j] = e;
                }
            a[i][j] = v[e];
            e++;
        }
    }
}