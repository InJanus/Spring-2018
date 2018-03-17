// Place your information here

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string Encode(string input,int value){ 
    string temp;
    char addchar;
    for(unsigned int i = 0; i < input.size(); i++){
        if(isalpha(input.at(i))){
            if(islower(input.at(i))){
                if(input.at(i)>(122-value)){
                    addchar = ((input.at(i)-26)+value);
                    temp = temp + addchar;
                } else {
                    addchar = input.at(i)+value;
                    temp = temp + (addchar);
                }
            } else if(isupper(input.at(i))){
                if(input.at(i)>(90-value)){
                    addchar = ((input.at(i)-26)+value);
                    temp = temp + addchar;
                } else {
                    addchar = input.at(i)+value;
                    temp = temp + (addchar);
                }
            }
        } else {
            temp = temp + input.at(i);
        }    
    }
    return temp;
}

string Decode(string input,int value){
    string temp;
    char addchar;
    for(unsigned int i = 0; i < input.size(); i++){
        if(isalpha(input.at(i))){
            if(islower(input.at(i))){
                if(input.at(i)<(97+value)){
                    addchar = ((input.at(i)+26)-value);
                    temp = temp + addchar;
                } else {
                    addchar = input.at(i)-value;
                    temp = temp + (addchar);
                }
            } else if(isupper(input.at(i))){
                if(input.at(i)<(65+value)){
                    addchar = ((input.at(i)+26)-value);
                    temp = temp + addchar;
                } else {
                    addchar = input.at(i)-value;
                    temp = temp + (addchar);
                }
            }
        } else {
            temp = temp + input.at(i);
        }    
    }
    return temp;
}

void fileWrite(string input, string fileName){
    ofstream myfile(fileName);
    if(myfile.is_open()){
        myfile << input;
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

string fileRead(string fileName){
    string temp;
    ifstream myfile(fileName);
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,temp);
            myfile.close();
        }
    } else {
        cout << "Unable to open file" << endl;
    }
    return temp;
}

void outputToFile(string encodeMesage){
    string fileName;
    int input;
    do{
        cout << "Output to file? (1-Yes|0-No)" << endl;
        cin >> input;
        switch(input){
            case 0:
                break;
            case 1:
                input = 0;
                cout << "File Name: ";
                cin >> fileName;
                fileWrite(encodeMesage,fileName);
                cout << "DONE" << endl;
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
    }while((input!=0));
}
void encodeMenu(){
    int input;
    int factor;
    string fileName;
    string mesage = "";
    do{
        cout << "Encode From Keyboard ---------- 1" << endl;
        cout << "Encode From File -------------- 2" << endl;
        cout << "Quit -------------------------- 0" << endl;
        cin >> input;
        switch(input){
            case 1:{
                cout << endl << "Please Type Mesage to Encode" << endl;
                cin.ignore();
                getline(cin,mesage);
                cout << "Factor: ";
                cin >> factor;
                cout << endl;
                string encodeMesage = Encode(mesage,factor);
                cout << "Endoded Mesage: " << encodeMesage;
                cout << endl;
                outputToFile(encodeMesage);
                break;   //this is for case 1:
            }
            case 2:{
                cout << "File Name: ";
                cin >> fileName;
                string read = fileRead(fileName);
                cout << "Factor: ";
                cin >> factor;
                cout << endl;
                cout << "Mesage: " << read << endl;
                string encodeMesage = Encode(read,factor);
                cout << "Encoded Mesage: " << encodeMesage << endl;
                outputToFile(encodeMesage);
                break; //this is for case 2:
            }
            case 0:
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
        
    }while(input != 0);
}

void decodeMenu(){
    int input;
    int factor;
    string fileName;
    string mesage = "";
    do{
        cout << "Decode From Keyboard ---------- 1" << endl;
        cout << "Decode From File -------------- 2" << endl;
        cout << "Quit -------------------------- 0" << endl;
        cin >> input;
        switch(input){
            case 1:{
                cout << endl << "Please Type Mesage to Decode" << endl;
                cin.ignore();
                getline(cin,mesage);
                cout << "Factor: ";
                cin >> factor;
                cout << endl;
                string encodeMesage = Decode(mesage,factor);
                cout << "Decode Mesage: " << encodeMesage;
                cout << endl;
                outputToFile(encodeMesage);
                break;   //this is for case 1:
            }
            case 2:{
                cout << "File Name: ";
                cin >> fileName;
                string read = fileRead(fileName);
                cout << "Factor: ";
                cin >> factor;
                cout << endl;
                cout << "Mesage: " << read << endl;
                string decodeMesage = Decode(read,factor);
                cout << "Decoded Mesage: " << decodeMesage << endl;
                outputToFile(decodeMesage);
                break; //this is for case 2:
            }
            case 0:
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
        
    }while(input != 0);
    
}


int main() {
    int input;
    string menu = "Encode String ---------- 1\nDecode String ---------- 2\nQuit ------------------- 0\n";
    do{
        cout << menu; 
        cin >> input;
        
        switch(input){
            case 1:
                cout << endl;
                encodeMenu();
                break;
            case 2:
                cout << endl;
                decodeMenu();
                break;
            case 0:
                break;
            default:
                cout << "Invalid Option" << endl;
        }
    }while (input != 0);
    
    return 0;
}

