#include <iostream>
using namespace std;

int maxOf(int a, int b){
  return ((a>b)?a:b);
}
//find the maximum sum sub-array in an array with positive and negative integers
int getMaxSum(int arrayNums[], int sizeOfArray){
    int currMax = arrayNums[0];
    int max = arrayNums[0];

    for(int i = 1; i < sizeOfArray; i++){
        currMax = maxOf(currMax + arrayNums[i], arrayNums[i]);
        max = maxOf(max,currMax);
    }
    return max;
}
int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeArray = 0;
    for(int i = 0; i < testCases; i++){
        cin >> sizeArray;
        int arrayNums[sizeArray];
        for(int j = 0; j < sizeArray; j++){
            cin >> arrayNums[j];
        }
        cout << getMaxSum(arrayNums,sizeArray) << endl;
    }
  return 0;
}
