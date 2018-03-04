// Programmer:   FIll me in
// Description:  Fill me in
//


// This is essentially an empty shell

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

string getName() {
    string node_name;
    cout << "Enter Node Name: ";
    cin >> node_name;
   
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



int main() {
    double volts = getVoltage();
    vector<node> mynodes = getNode();
    double total_res = total_resistance(mynodes);
    double series_current = getSeries_Current(volts,total_res);
    double total_power_cons = getTotal_Power_Consumption(series_current,volts);
    calcVoltage_Across(mynodes, series_current);
    calcPower_Consumption(mynodes, series_current);
    print(mynodes,volts, total_res, series_current, total_power_cons);
    
}

