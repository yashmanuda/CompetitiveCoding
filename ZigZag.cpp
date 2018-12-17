#include<bits/stdc++.h>
using namespace std;

void printZigZag(int numArray[], int sizeOfArray){

    //start with increasing
    bool isInc = true;
    for(int i = 0 ; i < sizeOfArray - 1; i++){
        //swap if not increasing
        if(isInc){
            if(numArray[i] > numArray[i + 1]){
                swap(numArray[i],numArray[i + 1]);
            }
        }
        // swap if not decreasing
        else{
            if(numArray[i] < numArray[i + 1]){
                swap(numArray[i],numArray[i + 1]);
            }
        }
        // reverse increasing and decreasing
        isInc = !isInc;
    }

    for(int i = 0;  i < sizeOfArray; i++){
        cout << numArray[i] << " " ;
    }
    cout << endl;
    return;
}


int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray;
        int numArray[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin >> numArray[j];
        }
        printZigZag(numArray,sizeOfArray);
    }
    return 0;
}
