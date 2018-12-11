#include <bits/stdc++.h>
using namespace std;

void findMinimumPlatforms(int arrival[], int departure[], int numTrains){
    // key value pairs, multiple values can have same key
    // in map, unique keys for all values
    multimap<int,char> mmap;
    // iterator is address, use -> or (*it)
    multimap<int,char> :: iterator it;

    for(int i = 0; i < numTrains; i++){
        mmap.insert(pair<int,char>(arrival[i],'a'));
        mmap.insert(pair<int,char>(departure[i],'d'));
    }

    int maxPlat = 0;
    int currPlat = 0;

    for(it = mmap.begin(); it != mmap.end(); it++){
        //accessing via iterator
        if((*it).second == 'a'){
            currPlat++;
        }
        else{
            currPlat--;
        }
        if(maxPlat < currPlat){
            maxPlat = currPlat;
        }
    }

    cout << maxPlat << endl;

}

int main(){
    int testCases = 0;
    cin >> testCases;
    int numTrains = 0;
    for(int i = 0 ; i < testCases; i++){
        cin >> numTrains;
        int arrival[numTrains];
        int departure[numTrains];

        for(int j = 0 ; j < numTrains; j++){
            cin >> arrival[j];
        }
        for(int k = 0; k < numTrains; k++){
            cin >> departure[k];
        }
        findMinimumPlatforms(arrival,departure,numTrains);
    }
    return 0;
}
