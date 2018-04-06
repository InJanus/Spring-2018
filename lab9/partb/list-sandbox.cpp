/*
    Brian Culberson 2018
*/

#include <iostream>
#include <vector>

#include "LList.h"

using namespace std;

int main(){
    LList a;
    for(int i = 0; i < 50; i++){
        a.push_front(45);
    }

    cin.get();
    return 0;

}

