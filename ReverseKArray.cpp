#include<bits/stdc++.h>
using namespace std;

void getArrayInReverse(int arrayNum[], int sizeOfArray, int k){

    stack<int> myStack;
    int count = 0;
    for(int i = 0; i < sizeOfArray;){
        count = 0;
        while ( (count + i) < sizeOfArray && count < k) {
            myStack.push(arrayNum[i + count]);
            count++;
        }
        count = 0;
        while((count + i) < sizeOfArray && count < k){
            arrayNum[i + count] = myStack.top();
            myStack.pop();
            count++;
        }
        i += k;
    }

    for(int j = 0; j < sizeOfArray; j++){
        cout << arrayNum[j]<<" ";
    }
    cout << endl;

    return;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    int k = 0;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray >> k;
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        getArrayInReverse(arrayNum,sizeOfArray,k);
    }
    return 0;
}
