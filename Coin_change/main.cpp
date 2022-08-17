#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

void findMin(int quantity, vector<int>& denominations){

    cout << quantity << endl;
    for (int i = 0; i < denominations.size(); i++) {
        cout << denominations[i] << "-";
    }
    /*
    sort(denominations.begin(), denominations.end());
    // Initialize result
    vector<int> change;
    // Traverse through all denomination
    for (int i = num - 1; i >= 0; i--) {
        // Find denominations
        while (num >= denominations[i]) {
            num -= denominations[i];
            change.push_back(denominations[i]);
        }
    }
    // Print result
    cout << "Cambio para: " << num << ": ";
    for (int i = 0; i < change.size(); i++){
        cout << change[i] << " ";
    }*/
}

int main(){

    vector<int> quantities;
    fstream fileq("input1.txt");
    GotoLine(fileq, 4);
    string quan;
    getline(fileq,quan);
    stringstream streamq(quan);
    while(1) {
        int q;
        streamq >> q;
        if(!streamq)
        break;
        quantities.push_back(q);
    }

    vector<int> denominations;
    fstream filed("input1.txt");
    GotoLine(filed, 2);
    string deno;
    getline(filed,deno);
    stringstream streamd(deno);
    while(1) {
        int d;
        streamd >> d;
        if(!streamd)
        break;
        denominations.push_back(d);
    }

    for (int i = 0; i < quantities.size(); i++) {
        //findMin(quantities[i],denominations);
        cout << quantities[i] << "-";
    }

    /*
    cout << endl;
    for (int i = 0; i < denominations.size(); i++) {
        //findMin(quantities[i],denominations);
        cout << denominations[i] << "-";
    }*/

    return 0;
}