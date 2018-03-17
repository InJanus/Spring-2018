// Brian Culberson

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int> getNums(string fileName){
    vector<int> temp(1);
    int line;
    int count = 0;
    ifstream myfile(fileName);
    //myfile.open();
    if (myfile.is_open()){
        while(!myfile.eof()){       //you need a not here or it wont work
            //cout << "Here!";
            myfile >> line;
            //cout << line << endl;
            temp.at(count) = line;
            count++;
            temp.resize(count+1);
        }
        myfile.close();
        temp.resize(count);
        return temp;
    }else{
        cout << "Unable to open file" << endl;
        return temp;
    }
}

void sendToFile(vector<int> send, string fileName){
    ofstream myfile(fileName);
    if(myfile.is_open()){
        for(unsigned int i = 0; i < send.size(); i++){
            myfile << send.at(i) << "\n";
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

bool isEven(int input){
    return !(input%2);
}

bool isOdd(int input){
    return (input%2);
}

bool isPrime(int input){
    for(unsigned int i = 2; i < (input/4); i++){
        if((input%i) == 0){
            return false;
        }
    }
    return true;
    //6774
}

int max(vector<int> input){
    int temp = input.at(0);
    for(unsigned int i = 1; i < input.size(); i++){
        if(input.at(i) > temp){
            temp = input.at(i);
        }
    }
    return temp;
}

int min(vector<int> input){
    int temp = input.at(0);
        for(unsigned int i = 1; i < input.size(); i++){
        if(input.at(i) < temp){
            temp = input.at(i);
        }
    }
    return temp;
}
int sum(vector<int> input){
    int temp = 0;
    for(unsigned int i = 0; i < input.size(); i++){
        temp = temp + input.at(i);
    }
    return temp;
}

float mean(vector<int> input){
    return static_cast<double>(sum(input)/(double)input.size());
}

float stddev(vector <int> values) {
    if(values.size() != 0){
        float mymean = mean(values);
        float total = 0;
        for(int i = 0; i < values.size();i++){
            total = total + pow(values.at(i) - mymean,2);
        }
        return pow((total/values.size()),0.5);
    }
    return 0.0;
}

int main() {
    string myfileName;
    cout << "Please enter file name: " << endl;
    getline(cin,myfileName);
    vector<int> myNums = getNums(myfileName);
    cout << "Elements in file: " << myNums.size() << endl;
    int evencount = 0;
    int count = 0;
    vector<int> evens(1);
    for(unsigned int i = 0; i < myNums.size(); i++){
        evencount = evencount + isEven(myNums.at(i));
        if(isEven(myNums.at(i))){
            evens.at(count) = myNums.at(i);
            //cout << evens.at(count) << endl;
            count++;
            evens.resize(count+1);
        }
    }
    evens.resize(count);
    sendToFile(evens, "evens.txt");
    cout << "Even Elements: " << evencount << endl;
    int oddcount = 0;
    count = 0;
    vector<int> odds(1);
    for(unsigned int i = 0; i < myNums.size(); i++){
        oddcount = oddcount + isOdd(myNums.at(i));
        if(isOdd(myNums.at(i))){
            odds.at(count) = myNums.at(i);
            count++;
            odds.resize(count+1);
        }
    }
    odds.resize(count);
    sendToFile(odds,"odds.txt");
    cout << "Odd Elements: " << oddcount << endl;
    
    //prime numbers
    int primecount = 0;
    count = 0;
    vector<int> prime(1);
    for(unsigned int i = 0; i < myNums.size(); i++){
        primecount = primecount + isPrime(myNums.at(i));
        if(isPrime(myNums.at(i))){
            prime.at(count) = myNums.at(i);
            count++;
            prime.resize(count+1);
        }
    }
    prime.resize(count);
    sendToFile(prime,"prime.txt");
    cout << "Prime Elements: " << primecount << endl;
    
    cout << "Max Number: " << max(myNums) << endl;
    cout << "Min Number: " << min(myNums) << endl;
    cout << "Sum of Numbers: " << sum(myNums) << endl;
    cout << "Mean Number: " << mean(myNums) << endl;
    cout << "Standard Deviation: " << stddev(myNums) << endl;
    
    return 0;
}
