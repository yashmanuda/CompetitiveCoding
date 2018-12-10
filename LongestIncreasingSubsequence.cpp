#include <bits/stdc++.h>
using namespace std;

int maxOf(int a, int b){
    return (a>b?a:b);
}

// i , j (for every i, j < i, which j can add more if it's less than i)
void getLengthOfLIS(int arrayNum[], int sizeOfArray){
    int countArray[sizeOfArray];
    for(int i = 0; i < sizeOfArray; i++){
        countArray[i] = 1;
    }
    int overallMax = 1;
    int currentMax = 1;
    for(int i = 1; i < sizeOfArray; i++){
        currentMax = 1;
        for(int j = 0; j < i; j++){
            if(arrayNum[i] > arrayNum[j]){
                currentMax = maxOf(countArray[j] + countArray[i], currentMax);
            }
        }
        countArray[i] = currentMax;
        overallMax = maxOf(overallMax,currentMax);
    }
    cout << overallMax << endl;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin>>arrayNum[j];
        }
    getLengthOfLIS(arrayNum,sizeOfArray);
    }
    return 0;
}
