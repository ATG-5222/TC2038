// =========================================================
// File: main.cpp
// Authors:
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Date: 26-08-2022
// =========================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    vector<string> words;
    string t1 = "";
    string l1;
    ifstream txt1(argv[1]);

    while(getline(txt1, l1)){
        t1 = t1 + l1;
    }

    istringstream ss(t1);
    string word; 

    while (ss >> word){
        words.push_back(word);
    }

    for (string i: words){
        cout << i << '-';
    }
}