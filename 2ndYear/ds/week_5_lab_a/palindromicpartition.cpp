#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s){
    string s2 = "";
    for(int i = s.length() - 1;i>=0;i--){
        s2+=s[i];
    }
    bool flag = true;
    for(int i = 0;i<s.length();i++){
        if(s[i] != s2[i]) flag = false;
    }
    return flag;
}

void palPart(string s,string ans,int index){
    if(ans.length() == s.length()){
        if(checkPalindrome(ans)) cout << ans << endl;
        return ;
    }
    
    
    palPart(s,ans+s[index++],index);
    if(checkPalindrome(ans)) cout << ans << endl;
}

int main(){
    cout << "Enter string  : ";
    string s;
    cin >> s;
    palPart(s,"",0);
}