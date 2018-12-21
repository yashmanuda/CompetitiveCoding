#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n){

    for(int i = 0 ; i < n; i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }
    unordered_map<int,int> uomap;
    int curSum = 0;
    int maxSize = 0;
    unordered_map<int,int>::iterator it;

    for(int i = 0; i < n; i++){
        curSum += arr[i];
        if( (it = uomap.find(curSum)) != uomap.end()){
            maxSize = max(i - (*it).second, maxSize);
        }
        if(curSum  == 0){
            maxSize = max(maxSize, i + 1);
        }
        uomap.insert(pair<int,int> (curSum,i));
    }

    return maxSize;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int n = 0;
    for(int i = 0; i < testCases; i++){
        cin >> n;
        int arr[n];
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }

        int res = maxLen(arr,n);
        cout << res << endl;
    }
}
