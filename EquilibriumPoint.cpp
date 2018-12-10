#include <bits/stdc++.h>
using namespace std;

void findEquilibriumPoint(int arrayNum[], int sizeOfArray){
    if(sizeOfArray == 1){
        cout<<"1"<<endl;
        return;
    }
    int cumSum[sizeOfArray];
    cumSum[0] = arrayNum[0];
    for(int i = 1; i  < sizeOfArray; i++){
        cumSum[i] = cumSum[i - 1] + arrayNum[i];
    }
    for(int p = 1; p < sizeOfArray - 1; p++){
        if(cumSum[p-1] == (cumSum[sizeOfArray - 1] - cumSum[p])){
            cout<<p + 1<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
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
        findEquilibriumPoint(arrayNum,sizeOfArray);
    }
    return 0;
}
