#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <map>

using namespace std;

void dynamic_programming(vector<int> coins, int number, int size) {
	int value_limit = number + 1;
    int aux[value_limit];
    int used_coins[value_limit];
    int valueN=number;
    vector<int> change;

	for (int i = 0; i < value_limit; i++) {
		aux[i] = INT_MAX;
	}
	aux[0] = 0;
    for(int i = 1; i <= number; i++){
        for(int j = 0; j < size; j++){
            if(coins[j] <= i && ( 1+ aux[i - coins[j]] < aux[i]) ){
                aux[i]=1+aux[i - coins[j]];
                used_coins[i]=coins[j];
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
    cout << "DP SOLUTION, TOTAL COINS = " << change.size() << endl;
    map<int,int> frequency;
    for(int i: change){
        frequency[i]++;
    }
    for(const auto& c: frequency){
        cout << "Currency = " << c.first << " AMOUNT = " << c.second << endl;
    }
    cout << "---------";
}


int main(int argc, char* argv[]) {
    int number = 50; 
    vector<int> coins = {17,14,4,20,1,19,8};
    int size = coins.size();
    dynamic_programming(coins,number,size);
    return 0;
}