#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string key;
    string plaintext;
    cout << "ENter key : ";
    cin >> key;
    cout << "Enter plaintext : ";
    cin >> plaintext;
    int i = 0;
    while(key.size() <  plaintext.size()){
        key.push_back(plaintext[i++]);
    }
    string encrypt(key.size(), ' ');
    for(int i = 0;i<plaintext.size();i++){
        encrypt[i] = char((plaintext[i] - 'a' + (key[i] - 'a'))%26 + 'A');
    }
    cout << endl;
    cout << "Encrypted text : " <<  encrypt << endl;

    string decrypt(key.size(), ' ');
    for(int i = 0;i<plaintext.size();i++){
        decrypt[i] = char((encrypt[i] - 'A' - (key[i] - 'a') + 26)%26 + 'a');
    }
    cout << "Decrypted text : " << decrypt << endl; 

    return 0;
}