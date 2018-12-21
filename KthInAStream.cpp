#include <bits/stdc++.h>
using namespace std;

void printKthLargest(int arrayNum[], int sizeOfArray, int k){
    multiset<int> mset;
    for(int i = 0; i < sizeOfArray; i++){
        mset.insert(arrayNum[i]);
        if(mset.size() >= k){
            if(mset.size() > k){
                mset.erase(mset.begin());
            }
            cout << (*mset.begin()) << " ";
        } else{
            cout << "-1" << " ";
        }
    }
    cout << endl;
    return;
}

int main(){
    int testCases = 0, k = 0, sizeOfArray = 0;
    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        cin >> k >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0 ; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        printKthLargest(arrayNum,sizeOfArray,k);
    }
    return 0;
}
