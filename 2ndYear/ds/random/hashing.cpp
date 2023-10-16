#include <iostream>
using namespace std;

struct pair{
    int da
    };

int h1(int x,int len){
    return x%len;
    }

int linearProbing(int *ht, int add,int len){
    int p = ht[add];
    while(ht[add] != 0){
        add += 1;
        add = add%len;
        if(ht[add] == p) return -1;
        }
    return add;
    }

int main(){
    int *hashTable;
    int len;
    cout << "Enter size of hash table : ";
    cin >> len;
    hashTable = new int[len];
    for(int i = 0;i<len;i++){
        hashTable[i] = 0;
    }
    int x;
    while(true){
        cout << "Enter key : ";
        cin >> x;
        if(x == -1) break;
        int add = h1(x,len);
        if(hashTable[add] == 0) hashTable[add] = x;
        else{
            add = linearProbing(hashTable,add,len);
            if(add) hashTable[add] = x;
            else{
                cout << "Cannot insert in hash table." << endl;
                break;
            }
        }
    }
    int key;
    cout << "Enter key you wish to search : ";
    cin >> key;
    int add = h1(key,len);
    cout << hashTable[add];
    cout << endl;
    for(int i = 0;i<len;i++){
        cout << hashTable[i] << " ";
    }
    return 0;
    }
