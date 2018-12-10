#include <bits/stdc++.h>
using namespace std;

//all positive numbers in the array
struct indices{
        int startI = 0;
        int endI = 0;
        bool foundSubArray = false;
};

struct indices findSubArray(int arrayNum[], int sizeOfArray, int givenSum){
    struct indices result;
    if(sizeOfArray == 1){
        result.foundSubArray = (arrayNum[0] == givenSum);
        return result;
    }
    else{
        int currSum = arrayNum[0];
        while(currSum != givenSum){
            while(currSum < givenSum && result.endI < sizeOfArray){
                currSum += arrayNum[++result.endI];
            }
            while(currSum > givenSum && result.startI < result.endI){
                currSum -= arrayNum[result.startI++];
            }
            while(currSum > givenSum && result.startI == result.endI && result.endI < sizeOfArray){
                currSum = arrayNum[++result.startI];
                result.endI++;
            }

            if(currSum < givenSum && result.endI == sizeOfArray - 1){
                result.foundSubArray = false;
                return result;
            }
        }
        result.foundSubArray = true;
        return result;
    }
}


int main(){
    return 0;
    int testCases = 0;
    cin >> testCases;
    int sizeArray;
    int givenSum;
    for (int i  = 0; i < testCases; i++){
        cin>>sizeArray>>givenSum;
        int arrayNum[sizeArray];
        for(int j = 0; j < sizeArray; j++){
            cin>>arrayNum[j];
        }
        struct indices result = findSubArray(arrayNum,sizeArray,givenSum);
        if(result.foundSubArray == false){
            cout<<"-1\n";
        }
        else{
            cout<<result.startI<<" "<<result.endI<<endl;
        }
    }
}
