#include <iostream>
using namespace std;

int main(){
    string text = "helloworld";
    int key =  3;
    string output;
    for(int i = 0;i < text.size();i++){
        output.push_back(text[i] + key);
    }
    cout << output << endl;
    string decrypt;
    for(int i = 0;i<output.size();i++){
        decrypt.push_back(output[i] - key);
    }
    cout << "decrypted text : " << decrypt << endl;
    return 0;
}