#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return (a.first < b.first);
    }
    else{
        return a.second > b.second;
    }
}



void printByFrequency(int arrayNum[], int sizeOfArray){
    unordered_map<int,int> uomap;
    vector<pair<int,int>> frequencies;
    //num, and its frequency
    for(int i = 0 ; i < sizeOfArray; i++){
        uomap[arrayNum[i]]++;
    }

    for(unordered_map<int,int>::iterator it = uomap.begin(); it != uomap.end(); ++it){
        frequencies.push_back(make_pair((*it).first, (*it).second));
    }

    sort(frequencies.begin(),frequencies.end(), comparator);

    for(auto x : frequencies){
        for(int num = 0 ; num < x.second; num++){
            cout << x.first << " ";
        }
    }
    cout << endl;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int sizeOfArray = 0;
    for(int i = 0; i < testCases; i++){
        cin >> sizeOfArray;
        int arrayNum[sizeOfArray];
        for(int j = 0 ; j < sizeOfArray; j++){
            cin >> arrayNum[j];
        }
        printByFrequency(arrayNum, sizeOfArray);
    }
    return 0;
}
