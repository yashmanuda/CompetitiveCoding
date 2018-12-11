#include <bits/stdc++.h>
using namespace std;

void printMaxOfSubArray(int arrayNum[], int sizeOfArray, int k){
    // index value is stored in deque
    deque<int> myDeque;

    // maintain highest element at the front of the deque
    for(int j = 0 ; j < sizeOfArray; j++){
        // remove the front ( max ) element if it lies out of window
        if(!myDeque.empty() && (j - k) == myDeque.front()){
            myDeque.pop_front();
        }

        // keep popping all from back which are smaller than current element
        while( !myDeque.empty() && arrayNum[myDeque.back()] < arrayNum[j]){
            myDeque.pop_back();
        }

        // add current at the back, if deque is empty it will automatically be at the front i.e max
        myDeque.push_back(j);

        // print the front once you reach the end of first window
        if(j >= k - 1){
            cout<<arrayNum[myDeque.front()]<<" ";
        }
    }
    cout << endl;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    int k = 0;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray >> k;
        int arrayNum[sizeOfArray];
        for(int j = 0 ; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        printMaxOfSubArray(arrayNum,sizeOfArray, k);
    }
    return 0;
}
