

// Ohms law structure assignment - part a starter code
//
// This code solves the basic case of one resistor and one voltage source
// 
// Please convert this starter code to use functions as much as possible 
// It will become part A of the laboratory
// 
// You need to create at least 5-functions

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// You must use this structure
struct node {
    string name;
    double resistance;
    double voltage_across;
    double power_across;
};

// An Example of the type of function you may want to create
string nodeName() {
    string node_name;
    cout << "Enter Node Name: ";
    cin >> node_name;
   
    return node_name;
}

//
// The comments indicate good places to covvert code to short functions
//
int main() {
    node N1;
    
    // Enter source voltage
    double in_voltage;
    cout << "Enter Source Voltage: ";
    cin >> in_voltage;
    
    // Enter basic Node Information
    N1.name = nodeName();
    cout << "Resistor Value: ";
    cin >> N1.resistance;
   
    // Calculate series current for the one-node network
    double total_resistance = N1.resistance;
    double series_current = source_voltage/ total_resistance;

    // Calculate voltage across the restistor 
    N1.voltage_across = series_current* N1.resistance;
    // Calculate the power across the resistor
    N1.power_across = calcPower(N1.voltage_across, series_current);

    // Display Network Information
    cout << "Series Network: " << endl;
    cout << "Source Voltage: " << sourceVoltage << "-Volts" << endl;
    cout << "Total Resistance: " << total_resistance << "-Ohms" << endl;
    cout << "Series Current: " << series_current << "-Amperes" << endl;
    // Display Node information
    cout << "Node Name: " << node1.name << endl;
    cout << "Node Voltage: " << node1.voltage_across << "-Volts" << endl;
    cout << "Node Resistance: " << node1.resistance << "-Ohms" << endl;
    cout << "Node Power: " << node1.power_across << "-Watts" << endl;

    return 0;
}
