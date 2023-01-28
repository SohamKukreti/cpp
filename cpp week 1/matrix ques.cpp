#include <iostream>
using namespace std;

int main(){
    int m,n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    bool mat[m][n];
    bool checkmat[m][n];
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cout << "Enter element " << i << " " << j<<": ";
            cin >> mat[i][j];
            checkmat[i][j] = false;
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(mat[i][j] == 1 && checkmat[i][j] == false){
                for(int k = 0;k<m;k++){
                    for(int l = 0;l<n;l++){
                        if(k == i || l == j){
                            mat[k][l] = true;
                            checkmat[k][l] = true;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
    }
