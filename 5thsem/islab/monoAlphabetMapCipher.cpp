#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string text = "helloworld";
    string output;
    vector<char> alphabets(26, ' ');
    for(int i = 0;i < alphabets.size();i++){
        alphabets[i] = char(i + 'a');
    }
    random_shuffle(alphabets.begin(), alphabets.end());
    vector<bool> alphabetUsed(26, false);
    map<char, char> keyMap;
    for(int i = 0;i<26;i++){
        cout << alphabets[i] << " ";
        keyMap[char(i + 'a')] = alphabets[i];
    }
    cout << endl;
    // for(int i = 0;i<26;i++){
    //     int idx = rand()%26;
    //     while(alphabetUsed[idx]){
    //         idx = rand()%26;
    //     }
    //     keyMap[char(i + 'a')] = char(idx + 'a');
    //     alphabetUsed[idx] = true;
    // }
    for(int i = 0;i<text.length();i++){
        output.push_back(keyMap[text[i]]);
    }
    string decrypt;
    for(int i = 0;i<output.size();i++){
        for(auto it:keyMap){
            if(it.second == output[i]){
                decrypt.push_back(it.first);
            }
        }
    }
    cout << "Encrypted string is: " << output << endl;
    cout << "Decrypted string is: " << decrypt << endl;
    return 0;
}