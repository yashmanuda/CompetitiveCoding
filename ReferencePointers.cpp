#include <bits/stdc++.h>
using namespace std;

int main(){
    // declaring an integer
    int x = 10;
    cout << "\nDefining an integer x: " << x << endl;


    // declaring a pointer, which stores address of x
    int *ptr = &x;
    cout << "Defining a pointer ptr which stores address of x: " << ptr << endl;

    // reference of x
    int& ref = x;
    cout << "Defining a ref of x, ref is :  " << ref << endl;

    cout <<"Address of x & ref: "<< ptr << endl << endl;

    cout <<"x is: " << x << " \nPointer pointing to: " << (*ptr) <<" \nref is: " << ref << endl << endl;

    // changed variable

    x = 20;
    cout << "Changed x to: " << x << endl << endl;
    cout <<"x is: " << x << " \nPointer pointing to: " << (*ptr) <<" \nref is: " << ref << endl << endl;

    // changed pointer to reference
    ptr = &ref;
    cout << "Pointer changed to ref instead of x, ptr points to: " << ref << endl;
    // changed reference

    ref = 25;
    cout <<"Changed ref to: " << ref << endl << endl;

    cout <<"x is: " << x << " \nPointer pointing to: " << (*ptr) <<" \nref is: " << ref << endl << endl;
    cout <<"Address of x & ref: "<< ptr << endl;

    // declared reference to the pointer
    int*& ptrRef = ptr;
    cout <<"Defined a reference to ptr, ptrRef stores address of x and ref: " << ptrRef << endl;

    return 0;
}
