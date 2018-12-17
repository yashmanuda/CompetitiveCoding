#include <bits/stdc++.h>
using namespace std;

void getRangeOfDays(int arrayNum[], int sizeOfArray){

    int k = 0 ;
    bool isProfit = false;
    for(int i = 0; i < sizeOfArray - 1;){
        k = i + 1;
        while(k < sizeOfArray && arrayNum[k] > arrayNum[k - 1]){
            k++;
        }
        if( k  != i + 1){
            isProfit = true;
            cout << "(" << i <<" " << k - 1 <<") ";
        }
        i = k ;
    }
    if(!isProfit){
        cout << "No Profit";
    }
    cout << endl;

    return;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    for(int i = 0 ; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0 ; j < sizeOfArray ; j++){
            cin >> arrayNum[j];
        }
        getRangeOfDays(arrayNum, sizeOfArray);
    }
    return 0;
}
