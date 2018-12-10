#include <bits/stdc++.h>
using namespace std;

int maxOf(int a, int b){
    return (a>b?a:b);
}

// look and understand LIS first, it's similar to that
// how much can j = 0 to i-1 can contribute to i, choose max of it
void findMaximumSum(int arrayNum[], int sizeOfArray){
    int sumArray[sizeOfArray];
    for(int c = 0; c < sizeOfArray; c++){
        sumArray[c] = arrayNum[c];
    }
    int currentMaxSum = sumArray[0];
    int overallMaxSum = sumArray[0];
    for(int i = 1; i < sizeOfArray; i++){
        currentMaxSum = sumArray[i];
        for(int j = 0; j < i; j++){
            if(arrayNum[i] > arrayNum[j]){
                currentMaxSum = maxOf(sumArray[i] + sumArray[j],currentMaxSum);
            }
        }
        sumArray[i] = currentMaxSum;
        overallMaxSum = maxOf(overallMaxSum,currentMaxSum);
    }

    cout << overallMaxSum << endl;
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
