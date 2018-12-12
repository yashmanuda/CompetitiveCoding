#include <bits/stdc++.h>
using namespace std;

void printArray(int arrayNum[], int markLeader[], int sizeOfArray){
    for(int p = 0; p < sizeOfArray; p++){
        if(markLeader[p] == 1){
            cout<< arrayNum[p] << " ";
        }
    }
    cout << endl;
}

void getLeadersInArray(int arrayNum[], int sizeOfArray){
    int currLeader = arrayNum[sizeOfArray - 1];
    int markLeader[sizeOfArray];
    markLeader[sizeOfArray - 1] = 1;
    for(int j = 0; j < sizeOfArray - 1; j++){
        markLeader[j] = 0;
    }
    for(int i = sizeOfArray - 2; i >= 0; i--){
        if(arrayNum[i] >= currLeader){
            currLeader = arrayNum[i];
            markLeader[i] = 1;
        }
    }
    printArray(arrayNum,markLeader,sizeOfArray);

}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    for(int i = 0 ; i < testCases; i++){
        cin>>sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin>>arrayNum[j];
        }
        getLeadersInArray(arrayNum,sizeOfArray);
    }
    return 0;
}
