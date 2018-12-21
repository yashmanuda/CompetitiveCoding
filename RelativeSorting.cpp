#include <bits/stdc++.h>
using namespace std;

void getRelativeOrder(int arrayM[], int order[], int m, int n){
    unordered_map<int,int> uomap;
    multimap<int,int> mmap;

    for(int i = 0; i < n; i++){
        uomap.insert(pair<int,int>(order[i], -(n - i)));
    }

    for(int i = 0; i < m; i++){
        if(uomap[arrayM[i]] < 0){
            mmap.insert(pair<int,int>(uomap[arrayM[i]],arrayM[i]));
        } else{
            mmap.insert(pair<int,int>(arrayM[i],arrayM[i]));
        }
    }

    for(multimap<int,int>::iterator it = mmap.begin(); it != mmap.end(); ++it){
        cout << (*it).second << " ";
    }
    cout << endl;
    return;
}

int main(){
    int testCases = 0, m = 0, n = 0;
    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        cin >> m >> n;
        int arrayM[m];
        for(int j = 0; j < m; j++){
            cin >> arrayM[j];
        }
        int order[n];
        for(int j = 0; j < n; j++){
            cin >> order[j];
        }
        getRelativeOrder(arrayM,order, m, n);
    }
    return 0;
}
