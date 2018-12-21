#include <bits/stdc++.h>
using namespace std;

//m x n is the current size of the matrix
void printSpiral(int **numMatrix, int currRow, int currCol, int m, int n){
    if(m <= 0 || n <= 0){
        return;
    }

    if(m == 1 && n == 1){
        cout << numMatrix[currRow][currCol] << " ";
        return;
    }


    // top most
    for(int j = currCol ; j < currCol + n - 1; j++){
        cout << numMatrix[currRow][j] << " ";
        if(j == currCol + n - 2 && m == 1){
            cout << numMatrix[currRow][ j + 1] << " ";
            return;
        }
    }

    //right most
    for(int j = currRow; j < currRow + m - 1; j++){
        cout << numMatrix[j][currCol + n - 1] << " ";
        if(j == currRow + m - 2 && n == 1){
            cout << numMatrix[j + 1][currCol + n - 1] << " ";
        }
    }

    //bottom most
    if(m > 1){
        for(int j = currCol + n - 1; j > currCol; j--){
            cout << numMatrix[currRow + m - 1][j] << " ";
        }
    }

    //left most
    if( n > 1){
        for(int j = currRow + m - 1; j > currRow; j--){
            cout << numMatrix[j][currCol] << " ";
        }
    }

    //recursively calling the inner matrix
    printSpiral(numMatrix, currRow + 1, currCol + 1, m - 2, n - 2);

    return;
}


int main(){
    int testCases = 0, m = 0, n = 0;
    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        cin >> m >> n;
        int *numMatrix[m];
        for(int j = 0; j < m; j++){
            numMatrix[j] = new int[n];
        }

        for(int j = 0; j < m; j++){
            for(int l = 0; l < n; l++){
                cin >> numMatrix[j][l];
            }
        }
        printSpiral(numMatrix, 0 , 0, m, n );
        cout << endl;
    }
    return 0;
}
