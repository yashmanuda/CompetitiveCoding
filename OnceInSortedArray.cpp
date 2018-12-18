#include <bits/stdc++.h>
using namespace std;

void getOnceInArray(int arrayNum[], int sizeOfArray){

    if(sizeOfArray == 1){
        cout << arrayNum[sizeOfArray - 1] << endl;
        return;
    }
    int left = 0;
    int right = sizeOfArray - 1;
    int mid = left + (right - left )/ 2;
    while(true){

        if(left == right){
            cout << arrayNum[mid] << endl;
            return;
        }
        else if(mid == 0 && arrayNum[mid + 1] != arrayNum[mid]){
            cout << arrayNum[mid] << endl;
            return;
        }
        else if(mid == sizeOfArray - 1 && arrayNum[mid - 1] != arrayNum[mid]){
            cout << arrayNum[mid] << endl;
            return;
        }
        else if(arrayNum[mid - 1] != arrayNum[mid] && arrayNum[mid + 1] != arrayNum[mid]){
            cout << arrayNum[mid] << endl;
            return;
        }
        if(mid % 2 == 0){
            if(arrayNum[mid] == arrayNum[mid + 1]){
                left = mid + 1;

            } else{
                right = mid - 1;
            }
        }else{
            if(arrayNum[mid] == arrayNum[mid - 1]){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
        mid = left + (right - left )/ 2;
    }
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
        getOnceInArray(arrayNum,sizeOfArray);
    }
    return 0;
}
