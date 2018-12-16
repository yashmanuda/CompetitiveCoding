#include <bits/stdc++.h>
using namespace std;

void isPythagoreanTriplets(int arrayNum[], int sizeOfArray){

    unordered_set<int> uset;
    bool isFound = false;
    float sumRoot = 0;
    float subRoot = 0;
    for(int i = 0 ; i < sizeOfArray - 1; i++){

        for( int j = i + 1; j < sizeOfArray; j++){
            sumRoot = sqrt( pow(arrayNum[i],2) + pow(arrayNum[j],2) ) ;
            subRoot = sqrt( abs(pow(arrayNum[i],2) - pow(arrayNum[j],2)) ) ;
            if( floor(sumRoot) == ceil(sumRoot) && uset.find(floor(sumRoot)) != uset.end() ){
                cout << "Yes" << endl;
                return;
            }
            else if(floor(subRoot) == ceil(subRoot) && uset.find(floor(subRoot)) != uset.end()){
                cout << "Yes" << endl;
                return;
            }
            else{
                uset.insert(arrayNum[i]);
                uset.insert(arrayNum[j]);
            }
        }
    }
    cout << "No" << endl;
    return;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0 ;
    for(int i =0 ; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0 ; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        isPythagoreanTriplets(arrayNum,sizeOfArray);
    }
    return 0;
}
