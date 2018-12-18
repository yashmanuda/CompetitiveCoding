#include <bits/stdc++.h>
using namespace std;

void printInPendulum(int arrayNum[], int sizeOfArray){
    multiset<int> sortedMultiSet;
    for(int i = 0; i < sizeOfArray; i++){
        sortedMultiSet.insert(arrayNum[i]);
    }

    bool isRight = true;
    int count = 1;
    int middleIndex = (int)(sizeOfArray - 1) / 2;
    for(multiset<int>::iterator it = sortedMultiSet.begin(); it != sortedMultiSet.end(); ++it){
        if(it == sortedMultiSet.begin()){
            arrayNum[middleIndex] = (*it);
        }else{
            if(isRight){
                arrayNum[middleIndex + count] = (*it);
            }else{
                arrayNum[middleIndex - count] = (*it);
                count++;
            }
            isRight = !isRight;
        }
    }

    for(int i = 0; i < sizeOfArray; i++){
        cout << arrayNum[i] << " ";
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
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        printInPendulum(arrayNum,sizeOfArray);
    }
    return 0;
}
