#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int count = 0;

fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

void findMin(int quantity, vector<int> denominations){
    count++;
    int cq = quantity;
    sort(denominations.begin(), denominations.end());
    vector<int> change;
    for (int i = denominations.size() - 1; i >= 0; i--) {
        while (cq >= denominations[i]) {
            cq -= denominations[i];
            change.push_back(denominations[i]);
        }
    }


    cout << "Cambio para " << quantity << ": ";
    for (int i = 0; i < change.size(); i++){
        cout << change[i] << " ";
    }
    cout << endl;
    
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
        findMin(quantities[i],denominations);
    }

    return 0;
}