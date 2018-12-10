#include <bits/stdc++.h>
using namespace std;

int maxOf(int a, int b){
    return (a>b?a:b);
}

void findMaximumSum(int arrayNum[], int sizeOfArray){
    int seqStart = sizeOfArray - 1;
    int sumArr[sizeOfArray];
    sumArr[sizeOfArray - 1] = arrayNum[sizeOfArray - 1];
    int currSmallest = arrayNum[sizeOfArray - 1];
    for(int i = sizeOfArray - 2; i >=0 ; i--){
        // if element is larger than the current sum
        if(arrayNum[i] > sumArr[i + 1]){
            sumArr[i] = arrayNum[i];
            currSmallest = arrayNum[i];
        }
        //add if smaller element
        else if (arrayNum[i] < currSmallest){
            sumArr[i] = sumArr[i + 1] + arrayNum[i];
            currSmallest = arrayNum[i];
        }
        else{
            sumArr[i] = sumArr[i + 1];
        }
    }
    cout<<sumArr[0]<<endl;
    return;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    for(int i = 0 ; i  < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        findMaximumSum(arrayNum,sizeOfArray);
    }
    return 0;
}
