// Programmer:   Brian Culberson

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    string name;
    double resistance;
    double voltage_across;
    double power_across;
};

vector<node> globalmynodes;
double globaltotal_res;
double globalseries_current;
double globaltotal_power_cons;
double globalvolts;


string getName() {
    string node_name;
    cout << "Enter Node Name: ";
    cin.ignore();   //this is to flush the newline char out of the stream
    getline(cin, node_name);
    return node_name;
}

double getVoltage(){
    double voltage;
    cout << "Enter Voltage: ";
    cin >> voltage;
    return voltage;
}

vector<node> getNode(){
    int count = 0;
    vector<node> temp(1);
    double input = 1.0;
    while (input != 0.0){
        temp.at(count).name = getName();
        cout << "Enter Resistance <" << count+1 << "> (0 to exit): ";
        cin >> input;
        temp.at(count).resistance = input;
        count++;
        temp.resize(count+1);
    }
    temp.resize(count-1);
    return temp;
}

double total_resistance(vector<node> temp){
    double total = 0;
    for(int i = 0; i < temp.size();i++){
        total = total + temp.at(i).resistance;
    }
    return total;
}

double getSeries_Current(double source_voltage = 0, double total_resis = 1){
    return source_voltage/total_resis;
}

double getTotal_Power_Consumption(double series_current = 0, double source_voltage = 0){
    return series_current*source_voltage;
}

void calcVoltage_Across(vector<node> &temp, double series_current){
    for(int i = 0; i < temp.size(); i++){
        temp.at(i).voltage_across = series_current*temp.at(i).resistance;
    }
}

void calcPower_Consumption(vector<node> &temp, double series_current){
    for(int i = 0; i < temp.size(); i++){
        temp.at(i).power_across = series_current*temp.at(i).voltage_across;
    }
}

void print(vector<node> n, double volts, double total_res, double series_current, double total_power_cons){
    cout << endl;
    
    cout << "Input Voltage (Volts): " << volts << endl;
    cout << "Total Resistance (Ohms): " << total_res << endl;
    cout << "Series Current (Amps): " << series_current << endl;
    cout << "Total Power Consuption (Watts): " << total_power_cons << endl << endl;
    for(int i = 0; i < n.size();i++){
        cout << "Name <" << i+1 << ">: "<< n.at(i).name << endl;
        cout << "Resistance (Ohms): " << n.at(i).resistance << endl;
        cout << "Voltage Across (Volts): " << n.at(i).voltage_across << endl;
        cout << "Power Across (Watts): " << n.at(i).power_across << endl;
        cout << endl;
    }
}

void changeInputVoltage(){
    cout << endl;
    globalvolts = getVoltage();
    cout << "DONE" << endl << endl;
}

void groupAddResis(){
    int count = globalmynodes.size();
    vector<node> temp = globalmynodes;
    temp.resize(count+1);
    double input = 1.0;
    while (input != 0.0){
        temp.at(count).name = getName();
        cout << "Enter Resistance <" << count+1 << "> (0 to exit): ";
        cin >> input;
        temp.at(count).resistance = input;
        count++;
        temp.resize(count+1);
    }
    temp.resize(count-1);
    globalmynodes = temp;
}

void recalc(){
    globaltotal_res = total_resistance(globalmynodes);
    globalseries_current = getSeries_Current(globalvolts,globaltotal_res);
    globaltotal_power_cons = getTotal_Power_Consumption(globalseries_current,globalvolts);
    calcVoltage_Across(globalmynodes, globalseries_current);
    calcPower_Consumption(globalmynodes, globalseries_current);
}

double getResis(){
    double temp;
    cout << "Enter Resistance: ";
    cin >> temp;
    return temp;
}

void editResis(){

    string select = "";
    int flag = 0;
    do{
        cout << endl;
        for(int i = 0; i < globalmynodes.size();i++){
            cout << "Name: " << globalmynodes.at(i).name << endl << "Resistance: " << globalmynodes.at(i).resistance << endl;
        }
        cout << "\nSelect Resistor to edit (Type \"Quit\" to exit): ";
        cin >> select;
        
        
        if((select == "Quit")||(select == "quit")){
            flag = 1;
        } else {
            for(int i = 0; i < globalmynodes.size(); i++){
                if(select == globalmynodes.at(i).name){
                    globalmynodes.at(i).name = getName();
                    globalmynodes.at(i).resistance = getResis();
                    break;
                } else if((i == globalmynodes.size()-1)&&(globalmynodes.at(i).name != select)){
                    cout << "Invalid Selection: Please choose another" << endl;
                }
            }
        }
    }while(flag != 1);
    
}

void addResis(){
    globalmynodes.resize(globalmynodes.size()+1);
    globalmynodes.at(globalmynodes.size()-1).name = getName();
    globalmynodes.at(globalmynodes.size()-1).resistance = getResis();
}

void deleteResis(){
    if(globalmynodes.size() > 1){
        string select = "";
        int flag = 0;
        int count = 0;
        vector<node> temp(globalmynodes.size());
        do{
            select = "";
            flag = 0;
            count = 0;
            //cout << "Here!";
            vector<node> temp(globalmynodes.size()-1);
            //cout << temp.size();
            cout << endl;
            for(int i = 0; i < globalmynodes.size();i++){
                cout << "Name: " << globalmynodes.at(i).name << endl << "Resistance: " << globalmynodes.at(i).resistance << endl;
            }
            cout << "\nSelect Resistor to delete (Type \"Quit\" to exit): ";
            cin >> select;
            //cout << temp.size() << endl;
            //cout << globalmynodes.at(0).name << endl;
            if((select == "Quit")||(select == "quit")){
                flag = 1;
            }else {
                if(temp.size() == 0){
                    globalmynodes = temp;
                    flag = 1;
                } else {
                    for(int i = 0; i < globalmynodes.size(); i++){
                        if(select != globalmynodes.at(i).name){
                            temp.at(count) = globalmynodes.at(i);
                            count++;
                        } else if((i == globalmynodes.size()-1)&&(globalmynodes.at(i).name != select)){
                            cout << "Invalid Selection: Please choose another" << endl;
                        }
                    }
                    globalmynodes = temp;
                }
            }
        }while(flag != 1);
    }
    
    //for(int i = 0; i < globalmynodes.size();i++){
        //cout << globalmynodes.at(i).name << endl;
        //cout << globalmynodes.at(i).resistance << endl;
    //}
}

void menu(){
    cout << "\n";
    int input = 1;
    
    
    while(input != 0){
        cout << "\n";
        cout << "Change Input Voltage --------------- 1" << endl;
        cout << "Add Resistor ----------------------- 2" << endl;
        cout << "Delete Resistor -------------------- 3" << endl;
        cout << "Edit Resistor ---------------------- 4" << endl;
        cout << "Group add Resistors ---------------- 5" << endl;
        cout << "Display Network -------------------- 6" << endl;
        cout << "Quit ------------------------------- 0" << endl;
        cout << endl;
        cout << "Menu Selection: ";
        cin >> input;
        switch (static_cast<int>(input)){
            case 0:
                cout << "Goodbye!" << endl;
                break;
            case 1:
                changeInputVoltage();
                recalc();
                break;
            case 2:
                addResis();
                recalc();
                break;
            case 3:
                deleteResis();
                recalc();
                break;
            case 4:
                editResis();
                recalc();
                break;
            case 5:
                groupAddResis();
                recalc();
                break;
            case 6:
                cout << endl;
                print(globalmynodes,globalvolts,globaltotal_res,globalseries_current,globaltotal_power_cons);
                cout << endl;
                break;
            default:
                cout << endl << "Not valid input" << endl << endl;;
                break;
        }
    }
}

int main() {
    globalvolts = getVoltage();
    globalmynodes = getNode();
    globaltotal_res = total_resistance(globalmynodes);
    globalseries_current = getSeries_Current(globalvolts,globaltotal_res);
    globaltotal_power_cons = getTotal_Power_Consumption(globalseries_current,globalvolts);
    calcVoltage_Across(globalmynodes, globalseries_current);
    calcPower_Consumption(globalmynodes, globalseries_current);
    print(globalmynodes,globalvolts, globaltotal_res, globalseries_current, globaltotal_power_cons);
    
    //this is the start of the menu
    menu();
    
    return 0;
}

