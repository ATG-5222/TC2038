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

int main(int argc, char* argv[]) {
    ifstream arch;
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

    int sum;
    int l,r;
    vector<string> v = {""};

    while (ss >> word){
        words.push_back(word);
    }

    for (string i: words){
        cout << i << ' ';
    }

    arch.open(words[0], ios::in);

    while(!arch.eof()){
        getline(arch, texto);
        for (int i = 0; i < texto.size(); i++){
            v.resize(v.size() + texto.size());
            v.resize(v.size()-1);
            v[i] = texto[i];
            sum = sum + (int) texto[i];
        }
        
    }
    arch.close();

    r = stoi(words[1]);
    sum = sum%256;
    l = v.size()/r;
    if (v.size()%r != 0){
        l = trunc(l);
        int a[l+1][r];
    }
    if (v.size()%r == 0){
        int a[l][r];
    } 

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