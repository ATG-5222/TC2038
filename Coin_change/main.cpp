#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>

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

    int ant=change[0];
    int counter=0;
    int limit = change.size();

    cout << "Limit: " << limit << endl;

    if(limit==1){
        counter++;
        cout << "CURRENCY = " << ant << " AMOUNT = " << counter << endl;
    }
    else{
        for (int i = 0; i < change.size(); i++){
            //cout << i << " : " << change[i] << endl;
            if(ant==change[i]){
                counter++;
            }
            else if(ant!=change[i]){
                cout << "CURRENCY = " << ant << " AMOUNT = " << counter << endl;
                counter=1;
            }
            else if(i+1==limit){
                if(change[i]==change[i+1]){
                    counter++;
                    cout << "CURRENCY = " << change[i] << " AMOUNT = " << counter << endl;
                }
                else{
                    cout << "CURRENCY = " << change[i]+1 << " AMOUNT = 1" << endl;
                }
            }
            ant=change[i];
        }
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
        cout << "QUERY #" << counter <<", CHANGE = " << quantities[i] << endl;
        greedy(quantities[i],denominations);
        counter++;
    }

    return 0;
}