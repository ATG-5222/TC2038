#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int counter=1;

fstream& GotoLine(fstream& file,unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

void greedy(int quantity,vector<int> denominations,ofstream& file){
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
    file << "GREEDY SOLUTION, TOTAL COINS = " << change.size() << endl;
    map<int,int> frequency;
    for(int i: change){
        frequency[i]++;
    }
    for(const auto& c: frequency){
        file << "Currency = " << c.first << " AMOUNT = " << c.second << endl;
    }
    file << endl;
}

void dynamic_programming(int quantity,vector<int> denominations,int size,ofstream& file) {
	int value_limit = number + 1;
    int aux[value_limit];
    int used_coins[value_limit];
    int valueN=quantity;
    vector<int> change;

	for (int i = 0; i < value_limit; i++) {
		aux[i] = INT_MAX;
	}
	aux[0] = 0;
    for(int i = 1; i <= quantity; i++){
        for(int j = 0; j < size; j++){
            if(denominations[j] <= i && ( 1+ aux[i - denominations[j]] < aux[i]) ){
                aux[i]=1+aux[i - denominations[j]];
                used_coins[i]=denominations[j];
            }
        }
    }
    for(int i=valueN; i>=1; ){
        change.push_back(used_coins[i]);
        int j=i;
        i=valueN-used_coins[i];
        valueN = valueN - used_coins[j];
    }

    sort(change.begin(), change.end());
    file << "DP SOLUTION, TOTAL COINS = " << change.size() << endl;
    map<int,int> frequency;
    for(int i: change){
        frequency[i]++;
    }
    for(const auto& c: frequency){
        file << "Currency = " << c.first << " AMOUNT = " << c.second << endl;
    }
    file << "---------";
}

int main(int argc,char* argv[]){

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
    GotoLine(filed,2);
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

    string s = argv[1];

    ofstream file;
    if(s=="input1.txt"){
        file.open("mysolution1.txt");
    }
    else if(s=="input2.txt"){
        file.open("mysolution2.txt");
    }
    else if(s=="input3.txt"){
        file.open("mysolution3.txt");
    }
    else{
        file.open("mysolution4.txt");
    }

    int size = denominations.size();

    for (int i = 0; i < quantities.size(); i++) {
        file << "QUERY #" << counter <<", CHANGE = " << quantities[i] << endl;
        greedy(quantities[i],denominations,file);
        dynamic_programming(quantities[i],denominations,size,file);
        counter++;
    }

    return 0;
}