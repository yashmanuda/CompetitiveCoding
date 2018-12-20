#include <bits/stdc++.h>
using namespace std;

int findKthElement(int *arrayAN, int *endAN, int *arrayAM,  int *endAM, int k){
    if(arrayAN == endAN){
        return arrayAM[k];
    }
    if (arrayAM == endAM){
        return arrayAN[k];
    }

    int midArrayAN = (endAN - arrayAN) / 2;
    int midArrayAM = (endAM - arrayAM) / 2;

    if(k > midArrayAM + midArrayAN){
        if(arrayAM[midArrayAM] > arrayAN[midArrayAN]){
            return findKthElement(arrayAN + midArrayAN + 1, endAN, arrayAM, endAM, k - midArrayAN - 1);
        }
        else{
            return findKthElement(arrayAN, endAN, arrayAM + midArrayAM + 1, endAM, k - midArrayAM - 1);
        }
    }
    else{
        if(arrayAM[midArrayAM] > arrayAN[midArrayAN]){
            return findKthElement(arrayAN, endAN, arrayAM, arrayAM + midArrayAM, k);
        }
        else{
            return findKthElement(arrayAN, arrayAN + midArrayAN, arrayAM, endAM, k);
        }
    }

}

int main(){
    int testCases = 0;
    cin >> testCases;
    int k = 0, n = 0, m = 0;
    int kElement = 0;
    for(int i = 0 ; i < testCases; i++){
        cin >> n >> m >> k;
        int arrayAN[n];
        for(int j = 0 ; j < n ; j++){
            cin>>arrayAN[j];
        }

        int arrayAM[m];
        for(int j = 0; j < m; j++){
            cin>>arrayAM[j];
        }

        kElement = findKthElement(arrayAN, arrayAN + n, arrayAM, arrayAM + m, k - 1);
        cout << kElement << endl;
    }
    return 0;
}
