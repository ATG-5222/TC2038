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


using std::stoi;
using namespace std;


int main(int argc, char* argv[]) {


    string input;

    // Read from the text file
    ifstream input(argv[0]);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText;
    }
}