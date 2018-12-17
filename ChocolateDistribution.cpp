#include <bits/stdc++.h>
using namespace std;

void getMinDiffPackets(int arrayNum[], int sizeOfArray, int noOfStudents){
    int copyArray[sizeOfArray];

    for(int j = 0; j < sizeOfArray; j++){
        copyArray[j] = arrayNum[j];
    }

    sort(copyArray,copyArray + sizeOfArray);
    int currDiff = copyArray[noOfStudents - 1] - copyArray[0];
    for(int i = 0 ; i <= sizeOfArray - noOfStudents; i++){
        if((copyArray[i + noOfStudents - 1] - copyArray[i]) < currDiff){
            currDiff = (copyArray[i + noOfStudents - 1] - copyArray[i]);
        }
    }
    cout << currDiff << endl;
}

int main(){
    int testCases = 0;
    int sizeOfArray = 0;
    int noOfStudents = 0;
    cin >> testCases;
    for(int i = 0 ; i < testCases ; i++){
        cin >> sizeOfArray ;
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        cin >> noOfStudents;
        getMinDiffPackets(arrayNum, sizeOfArray, noOfStudents);
    }
    return 0;
}
