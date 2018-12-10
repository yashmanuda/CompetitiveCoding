#include <iostream>
using namespace std;

long int sumOf(long int num){
    long int sum = 0;
    while(num > 0){
        sum += num;
        num--;
    }
    return sum;
}

int main(){
    int testCases = 0;
    cin >> testCases;
    long int n = 0;
    long int sumOfn = 0;
    long int temp;
    for(int i = 0 ; i < testCases; i++){
        cin >> n;
        sumOfn = sumOf(n);
        for(long int j = 0; j < n; j++){
            cin >> temp;
            sumOfn -= temp;
        }
        cout << sumOfn << endl;
    }
    return 0;
}
