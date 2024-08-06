#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void remove_duplicates(string &key){
    string temp;
    unordered_set <char> s1;
    for(int i = 0;i<key.size();i++){
        s1.insert(key[i]);
    }
    for(auto it: s1){
        temp.push_back(it);
    }
    key = temp;
    reverse(key.begin(), key.end());
    cout << key << endl ;
 }

vector <vector<char>> generate_keyMatrix(string key){
    vector<vector<char>> output(5, vector<char>(5, ' '));
    vector<bool> character_used(26, false);
    remove_duplicates(key);
    //mark j as used because we dont want to use it
    character_used[9] = true;
    int k = 0;
    int l = 0;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(k < key.size()){
                character_used[key[k] - 'a'] = true;
                output[i][j] = key[k++];
            }
            else{
                while(character_used[l]){
                    l++;
                }
                    output[i][j] = char(l + 'a');
                    character_used[l] = true;
                    l++;
            }
           
        }
        
    }
    return output;
}

void encrypt(string text, vector<vector<char>> matrix){
    vector<string> pairs;
    for(int i = 0;i<text.size();){
        char c1 = text[i];
        char c2;
        if(i + 1 >= text.size()){
            c2 = 'x';
            i++;
        }
        else{
            if(text[i + 1] == c1){
                c2 = 'x';
                i++;
            }
            else{
                c2 = text[i + 1];
                i += 2;
            }
            
        }
        string s1;
        s1.push_back(c1);
        s1.push_back(c2);
        pairs.push_back(s1);
    }
    for(int i = 0;i<pairs.size();i++){
        
    }
}    

int main(){
    string key;
    cout << "Enter key : ";
    cin >> key;
    vector<vector<char>> matrix = generate_keyMatrix(key);
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
     }
     string text;
     cout << "Enter the string you wish to encrypt: ";
     cin >> text;
     encrypt(text, matrix);
    return 0;
}