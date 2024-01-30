#include <iostream>
using namespace std;

class Heap{
public:
    int *arr;
    int size;

    Heap(){
        arr = new int[100];
        size = 0;
    }

    void insert(int x){
        size++;
        int index = size;
        arr[size] = x;
        int parent = size/2;
        while(index > 1){
            if(arr[parent] < arr[index]){
                int temp = arr[parent];
                arr[parent] = arr[index];
                arr[index] = temp;
            }
            else break;
            index = parent;
            parent = index/2;
        }
        
    }

    void deletefromHeap(){
        arr[1] = arr[size];
        size--;
        int index = 1;

        while(index < size){
            int lChild = index*2;
            int rChild = 2*index  + 1;
            if(lChild < size && arr[lChild] > arr[index]){
                int temp = arr[index];
                arr[index] = arr[lChild];
                arr[lChild] = temp;
            }
            if(rChild < size && arr[rChild] > arr[index]){
                int temp = arr[index];
                arr[index] = arr[rChild];
                arr[rChild] = temp;
            }
            else{
                break;
            }
        }
    }

    void heapify(int *arr,int size , int i){
        int largest = i;
        int left = 2 * i;   
        int right = 2 * i + 1;
        if(left <= size && arr[left] > arr[largest]) largest = left;
        if(right <= size && arr[right] > arr[largest]) largest = right;
        if(largest != i){
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr,size,largest);
        }


    }

    void heapSort(int *arr,int n){
        int p = n;
        while(p > 1){
            int temp  = arr[1];
            arr[1] = arr[p];
            arr[p] = temp;
            p--;
            heapify(arr,p,1);
        }
    }

};

int main(){
    Heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);

    int arr[] = {-1,54,53,55,52,50};

    int n = 5;

    for(int i = n/2 ; i > 0;i--){
        h1.heapify(arr,n,i);
    }

    h1.heapSort(arr,n);



    cout << endl;
    //h1.heapSort(h1.arr,h1.size);

    for(int i = 1;i<=5;i++){
        cout << arr[i] << " ";
    }
    return 0;
}