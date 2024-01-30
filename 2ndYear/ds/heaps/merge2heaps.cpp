#include <iostream>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

class Heap{
public:
    int *arr;
    int size;
    Heap(){
        arr = new int[100];
        size = 0;
    }
    void insert(int x){
        arr[size] = x;
        int i = size;
        size++;
        while(i > 0){
            int parent = (i - 1) / 2;
            if(parent >= 0 && arr[parent] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[parent];
                arr[parent] = temp;
            }
            else break;
            i = parent;
        }
    }
    void display(){
        for(int i = 0;i<size;i++){
            cout << arr[i] << " ";
        }
    }


};

void heapify(int *arr, int size, int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2; 
    int largest = i;
    if(arr[left] > arr[largest]) largest = left;
    if(arr[right] > arr[largest]) largest = right;
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}

Heap mergeHeaps(Heap h1,Heap h2){
    Heap h3;
    for(int i = 0 ;i < h1.size;i++){
        h3.insert(h1.arr[i]);
    }
    for(int i = 0 ; i < h2.size;i++){
        h3.insert(h2.arr[i]);
    }
    return h3;
}

int main(){
    Heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.display();
    cout << endl;
    Heap h2;
    h2.insert(25);
    h2.insert(30);
    h2.insert(17);
    h2.insert(40);
    h2.display();
    cout << endl;
    Heap h3 = mergeHeaps(h1,h2);
    h3.display();
    cout << endl;
    return 0;        
}