// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 26-08-2022
// =========================================================

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string>
#include <fstream>


using std::stoi;
using namespace std;


int main(int argc, char* argv[]) {
    ifstream arch;
	string range, file, texto;  
    int r, v[][], sum;
    float l;

	cin >> file >> range;
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

    sum = sum%256;
    l = v.size()/r;
    l = trunc(l);
    int a[l+1][r];

    int e = 0;
    for (int i = 0; i < range; i++){
        for (int j = 0; j < range; j++){
            if (e > (v.size() - 1) ){
                a[i][j] = e;
                }
            a[i][j] = v[e];
            e++;
        }
    }
}