#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &heap, int root){
    int left = 2 * root;
    int right = 2 * root + 1;
    int temp = root;
    if(left < heap.size() && heap[left] < heap[temp]){
        temp = left;
    }
    if(right < heap.size() && heap[right] < heap[temp]){
        temp = right;
    }
    if(temp != root){
        int tempVal = heap[root];
        heap[root] = heap[temp];
        heap[temp] = tempVal;
        heapify(heap, temp);
    }
}

void buildHeap(vector<int> &heap){
    for(int i = heap.size()/2;i>=0;i--){
        heapify(heap, i);
    }
}

int main(){
    vector <int> heap(10, 1);
    for(int i = 0;i<10;i++){
        cin >> heap[i];
    }
    buildHeap(heap);
    for(auto it: heap){
        cout << it << " ";
    }
    return 0;
}