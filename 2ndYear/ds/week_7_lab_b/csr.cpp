#include <iostream>
using namespace std;

int convertCsr(int **arr,int row,int col){
    int size = 0;
    for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(arr[i][j] != 0){
                    size++;
                }
            }
        }
    int csr[3][size];
    int k = 0;
    for(int i = 0 ;i<row;i++){
        for(int j = 0 ;j < col ; j++){
            if(arr[i][j] != 0){
                csr[0][k] = arr[i][j];
                csr[1][k] = j;
                csr[2][k] = i;
                k++;
            }
        }
    }
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cout << csr[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{   
    int row,col;
    cout << "Enter number of rows in array : ";
    cin >> row;
    cout << "Enter number of columns in array : ";
    cin >> col;
    int **arr = new int*[row];
    for(int i = 0;i<row;i++){
        arr[i] = new int[col];
    }
    cout << "Enter array : ";
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin >> arr[i][j];
        }
    }
   
    convertCsr(arr,row,col);

}