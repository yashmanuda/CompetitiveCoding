#include <bits/stdc++.h>
using namespace std;

void findKthSmallestElement(int arrayNum[], int sizeOfArray, int k){
    // (value, index)
    multimap<int,int> mmap;
    for(int i = 0 ; i < sizeOfArray; i++){
        mmap.insert(pair<int,int>(arrayNum[i],i));
    }
    multimap<int,int>::iterator it = mmap.begin();

    advance(it,k-1);
    cout << it->first << endl;
}

int main(){
    int testCases = 0;
    int k = 0;
    int sizeOfArray = 0;
    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        cin >> k;
        findKthSmallestElement(arrayNum,sizeOfArray,k);
    }

}
