#include <bits/stdc++.h>
using namespace std;

bool comparator(int a, int b){
    string numA = to_string(a);
    string numB = to_string(b);
    string abNUM = numA + numB;
    string baNUM = numB + numA;

    return (stoi(abNUM) > stoi(baNUM));
}

void printLargestNumber(int arrayNum[], int sizeOfArray){
    sort(arrayNum,arrayNum + sizeOfArray, comparator);

    for(int i = 0 ; i < sizeOfArray; i++){
        cout << arrayNum[i];
    }
    cout << endl;
    return;
}

int main(){
    int testCases = 0, sizeOfArray = 0;
    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        printLargestNumber(arrayNum,sizeOfArray);
    }
    return 0;
}
