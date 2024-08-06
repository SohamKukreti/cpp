#include <iostream>
#include <bits/stdc++.h>
using namespace std;




int main(){
    string s1 = "hello world";
    vector<vector<char>> table(3, vector<char>(4, ' '));
    int k = 0;
    for(int i = 0;i < table.size();i++){
        for(int j = 0;s1[k] != '\0' && j <table[i].size();j++){
            if(s1[k] == ' ') k++;
            table[i][j] = s1[k++];
        }
    }
    vector<int> key = {1, 2 , 3, 4};
    string output;
    for(int col = 0;col < key.size();col++){
        for(int row = 0;row < table.size();row++){
            if(table[row][key[col] - 1] == ' ') continue;
            output.push_back(table[row][key[col] - 1]);
        }
    }
    cout << output << endl;
    return 0;
}