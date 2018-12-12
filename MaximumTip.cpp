#include <bits/stdc++.h>
using namespace std;

int getMaximumTip(int xTips[], int yTips[], int xLim, int yLim, int numOrders){
    if(numOrders == 0){
        return 0;
    }

    if(xLim == 0){
        return (yTips[numOrders - 1] + getMaximumTip(xTips, yTips, xLim, yLim - 1, numOrders - 1));
    }

    if(yLim == 0){
        return (xTips[numOrders - 1] + getMaximumTip(xTips, yTips, xLim - 1, yLim, numOrders - 1));
    }
    int ifChooseY = (yTips[numOrders - 1] + getMaximumTip(xTips, yTips, xLim, yLim - 1, numOrders - 1));
    int ifChooseX = (xTips[numOrders - 1] + getMaximumTip(xTips, yTips, xLim - 1, yLim, numOrders - 1));
    return max(ifChooseX, ifChooseY);
}

int main(){
    int testCases = 0;
    cin >> testCases;
    int numOrders = 0;
    int xLim = 0;
    int yLim = 0;
    int maxTip = 0;
    for(int i = 0; i < testCases; i++){
        cin >> numOrders >> xLim >> yLim;
        int xTips[numOrders];
        int yTips[numOrders];
        for(int j = 0; j < numOrders; j++){
            cin >> xTips[j];
        }
        for(int j = 0; j < numOrders; j++){
            cin >> yTips[j];
        }
        maxTip = getMaximumTip(xTips, yTips, xLim, yLim, numOrders);
        cout << maxTip << endl;
    }
    return 0;
}
