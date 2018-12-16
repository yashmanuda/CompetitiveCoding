#include <iostream>
using namespace std;

void getTrappedWater(int arrayNum[], int sizeOfArray){
    int leftMax[sizeOfArray];
    int rightMax[sizeOfArray];

    leftMax[0] = arrayNum[0];
    rightMax[sizeOfArray - 1] = arrayNum[sizeOfArray - 1];

    for(int i = 1 ; i < sizeOfArray - 1 ; i++){
        if(arrayNum[i] > leftMax[i - 1]){
            leftMax[i] = arrayNum[i];
        }
        else{
            leftMax[i] = leftMax[i - 1];
        }
        if(arrayNum[sizeOfArray - 1 - i] > rightMax[sizeOfArray -  i]){
            rightMax[sizeOfArray - 1 - i] = arrayNum[sizeOfArray - i - 1];
        }
        else{
            rightMax[sizeOfArray - 1 - i] = rightMax[sizeOfArray - i];
        }
    }
    int water = 0;
    int minLR = 0;
    for(int j = 1 ; j < sizeOfArray - 1; j++){
        minLR = min(leftMax[j],rightMax[j]);
        if(arrayNum[j] < minLR){
            water += (minLR - arrayNum[j]);
        }
    }
    cout << water << endl;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    for(int i =0; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        getTrappedWater(arrayNum,sizeOfArray);
    }
}
