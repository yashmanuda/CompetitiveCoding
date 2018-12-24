#include <bits/stdc++.h>
using namespace std;

void balance(priority_queue<int, vector<int>, less<int> > &lessThan, priority_queue<int, vector<int>, greater<int> > &greaterThan){
    if(lessThan.size() > greaterThan.size()){
        greaterThan.push(lessThan.top());
        lessThan.pop();
    } else if(greaterThan.size() > lessThan.size()){
        lessThan.push(greaterThan.top());
        greaterThan.pop();
    }
}

int main(){
    int num = 0, currNum = 0;
    cin >> num;
    // ascending order
    priority_queue<int, vector<int>, greater<int> > greaterThan;

    // descending order
    priority_queue<int, vector<int>, less<int> > lessThan;

    //current element is eventh or oddth element
    bool isOdd = true;
    for(int i = 0; i < num; i++){
        cin >> currNum;
        if(isOdd){
            if(lessThan.size() == 0 || currNum <= lessThan.top()){
                lessThan.push(currNum);
                cout <<lessThan.top()<< endl;
            } else{
                greaterThan.push(currNum);
                cout << greaterThan.top() << endl;
            }
        } else{
            if(currNum > lessThan.top()){
                greaterThan.push(currNum);
            } else{
                lessThan.push(currNum);
            }
            balance(lessThan, greaterThan);
            cout << (greaterThan.top() + lessThan.top()) / 2 << endl;
        }
        isOdd = !isOdd;
    }
    return 0;
}
