#include <bits/stdc++.h>
using namespace std;

void printSortedArray(int arrayNum[], int sizeOfArray){
    int countZero = 0, countOne= 0, countTwo = 0;
    for(int i = 0; i < sizeOfArray; i++){
        if(arrayNum[i] == 0){
            countZero++;
            cout<<"0 ";
        }
        else if(arrayNum[i] == 1){
            countOne++;
        }
        else{
            countTwo++;
        }
    }
    for(int o = 0; o < countOne; o++){
        cout<<"1 ";
    }
    for(int t = 0; t < countTwo; t++){
        cout<<"2 ";
    }
    cout<<endl;
}

int main(){
    int testCases = 0;
    int sizeOfArray = 0;
    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0; j  <sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        printSortedArray(arrayNum,sizeOfArray);
    }
    return 0;
}
