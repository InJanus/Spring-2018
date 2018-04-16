/*
    Brian Culberson 2018
*/

#include <iostream>
#include <vector>

#include "LList.h"

using namespace std;

int main(){

    LList test;

    for(int i = 0; i < 10; i++){
        test.push_back(i);
    }
    test.pop_back();   //this deletes the front node
    test.setAt(5,1000);
    test = test.reverse();
    test == test;
    for(int i = 0; i < test.size(); i++){
        
        cout << i << " - "<<  test.getAt(i) << endl;
    }
    //cout << test.size() << endl;


    return 0;

}

