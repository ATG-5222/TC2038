#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int counter=1;

fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

void greedy(int quantity, vector<int> denominations){
    int cq = quantity;
    sort(denominations.begin(), denominations.end());
    vector<int> change;
    for (int i = denominations.size() - 1; i >= 0; i--) {
        while (cq >= denominations[i]) {
            cq -= denominations[i];
            change.push_back(denominations[i]);
        }
    }
    sort(change.begin(), change.end());
    cout << "GREEDY SOLUTION, TOTAL COINS = " << change.size() << endl;
    map<int,int> frequency;
    for(int i: change){
        frequency[i]++;
    }
    for(const auto& c: frequency){
        cout << "Currency = " << c.first << " AMOUNT = " << c.second << endl;
    }
    cout << endl;
}

int main(int argc, char* argv[]){

    vector<int> quantities;
    fstream fileq(argv[1]);
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
    fstream filed(argv[1]);
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

    cout << "argv[1]" << argv[1] << endl;
    string s = argv[1];

    ofstream myfile;
    if(s=="input1.txt"){
        myfile.open("mysolution1.txt");
    }
    else if(s=="input2.txt"){
        myfile.open("mysolution2.txt");
    }
    else if(s=="input3.txt"){
        myfile.open("mysolution3.txt");
    }
    else{
        myfile.open("mysolution4.txt");
    }

    for (int i = 0; i < quantities.size(); i++) {
        myfile << "QUERY #" << counter <<", CHANGE = " << quantities[i] << endl;
        greedy(quantities[i],denominations);
        counter++;
    }

    return 0;
}