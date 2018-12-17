#include <bits/stdc++.h>
using namespace std;

void getFirstElement(int arrayNum[], int sizeOfArray){

    int leftMax[sizeOfArray];
    int rightMin[sizeOfArray];

    leftMax[0] = arrayNum[0];
    rightMin[sizeOfArray - 1] = arrayNum[sizeOfArray - 1];

    for(int i = 1; i < sizeOfArray; i++){
        if(arrayNum[i] > leftMax[i - 1]){
            leftMax[i] = arrayNum[i];
        }
        else{
            leftMax[i] = leftMax[i - 1];
        }

        if(arrayNum[sizeOfArray - 1 - i] < rightMin[sizeOfArray - i]){
            rightMin[sizeOfArray - 1 - i] = arrayNum[sizeOfArray - 1 - i];
        }
        else{
            rightMin[sizeOfArray - 1 - i] = rightMin[sizeOfArray - i];
        }
    }
    for(int j = 1; j < sizeOfArray - 1; j++){
        if(leftMax[j - 1] <= arrayNum[j] && arrayNum[j] <= rightMin[j + 1]){
            cout << arrayNum[j] << endl;
            return;
        }
    }
    cout << "-1" << endl;
    return;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0 ; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        getFirstElement(arrayNum,sizeOfArray);
    }
    return 0;
}
