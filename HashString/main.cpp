// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 26-08-2022
// =========================================================

#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void trunc(int l, int n, int v[1000]);
void matrix(int a[1000][1000],int n,int v[1000]);


int main(int argc, char* argv[]) {
    vector<string> words;
    string t1 = "";
    string l1;
    ifstream txt1(argv[1]);
    string texto;
    istringstream ss(t1);
    string word; 

    while(getline(txt1, l1)){
        t1 = t1 + l1;
    }

    int r, v[1000], sum, a[1000][1000];
    float l;

    while (ss >> word){
        words.push_back(word);
    }

    for (string i: words){
        cout << i << ' ';
    }

    while(!arch.eof()){
        getline(words[0], texto);
        for (int i = 0; i < texto.size(); i++){
            v[i] = texto[i];
            sum = sum + (int) texto[i];
        }
        
    }
    arch.close();

    r = stoi(words[1]);
    sum = sum%256;
    l = v.size()/r;
    trunc(l,r,v);
}

void trunc(int l, int n, int v[]){
    if (l%n != 0){
        l = trunc(l);
        int a[l+1][n];
        matrix(a[l+1][n],n,v)
        }
        
    l = trunc(l);
    int a[l][n];
    matrix(a[l][n],n,v);
}

void matrix(int a[1000][1000],int r, int v [1000]){
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