#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

int main(){
    vector<int> nums;
    fstream file("input1.txt");
    GotoLine(file, 4);
    string st;
    getline(file, st);

    stringstream stream(st);
    while(1) {
        int n;
        stream >> n;
        if(!stream)
        break;
        nums.push_back(n);
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}