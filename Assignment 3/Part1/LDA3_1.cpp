#include <iostream>  
#include <fstream>  
#include <iomanip>  
#include <string>  
using namespace std;  

// validate that input is not negative  
double validateData(double value, string message) {  
    // ask for input until a non-negative value is entered  
    while (value < 0) {  
        cout << "Error! Value cannot be negative." << endl;  
        cout << message;  
        cin >> value;  
    }  
    return value;  
}  

// calculate charges for inpatient  
double patientCharges(int days, double rate, double services, double meds) {  
    double roomCharges = days * rate;  // calculate room charges first  
    double total = roomCharges + services + meds;  // add all charges together and return the total  
    return total;  
}  

// calculate charges for outpatient  
double patientCharges(double services, double meds) {  
    double total = services + meds;  // add services and medication charges  
    return total;  
}  

int main() {  
    // variables for patient data  
    int patientType;  
    int days = 0;  
    double dailyRate = 0.0;  
    double serviceCharges = 0.0;  
    double medicationCharges = 0.0;  
    double totalCharges = 0.0;  
    
    // welcome message  
    cout << "This program will compute patient hospital charges." << endl;  
    
    // patient type
    cout << "Enter 1 for in-patient or 0 for out-patient: ";  
    cin >> patientType;  
    
    // service charges  
    cout << "Lab fees and other service charges: $";  
    cin >> serviceCharges;  
    // validate service charges  
    serviceCharges = validateData(serviceCharges, "Lab fees and other service charges: $");  
    
    // medication charges  
    cout << "Medication charges: $";  
    cin >> medicationCharges;  
    // validate medication charges  
    medicationCharges = validateData(medicationCharges, "Medication charges: $");  
    
    // if inpatient, get additional information  
    if (patientType == 1) {  
        // number of days  
        cout << "Number of days in the hospital: ";  
        cin >> days;  
        // validate days (convert to double for validation function)  
        double daysAsDouble = static_cast<double>(days);  
        daysAsDouble = validateData(daysAsDouble, "Number of days in the hospital: ");  
        days = static_cast<int>(daysAsDouble);  
        
        // daily rate  
        cout << "Daily room rate: $";  
        cin >> dailyRate;  
        // validate daily rate  
        dailyRate = validateData(dailyRate, "Daily room rate: $");  
        
        // calculate total charges using inpatient function  
        totalCharges = patientCharges(days, dailyRate, serviceCharges, medicationCharges);  
    } else {  
        // calculate total charges using outpatient function  
        totalCharges = patientCharges(serviceCharges, medicationCharges);  
    }  
    
    // create and open a file for output  
    ofstream outputFile;  
    outputFile.open("hospital.txt");  
    
    // check if file opened successfully  
    if (outputFile.is_open()) {  
        // set up formatting for dollar amounts  
        outputFile << fixed << setprecision(2);  
        
        // write header to file  
        outputFile << "****************************" << endl;  
        outputFile << "Hospital Billing Statement" << endl;  
        outputFile << "****************************" << endl;  
        
        // write charges - room charges only for inpatients  
        if (patientType == 1) {  
            double roomCharges = days * dailyRate;  
            outputFile << "Room charges    $ " << roomCharges << endl;  
        }  
        
        // write other charges that apply to both patient types  
        outputFile << "Lab & Services  $ " << serviceCharges << endl;  
        outputFile << "Medication      $ " << medicationCharges << endl;  
        outputFile << "Total charges   $ " << totalCharges << endl;  
        outputFile << "****************************" << endl;  
        
        // close the file  
        outputFile.close();  
        
        // inform user that the report has been created  
        cout << "The billing report has been written to the hospital.txt file." << endl;  
    } else {  
        // show error message if file couldn't be opened  
        cout << "Error: Could not open the file for writing." << endl;  
    }  
    
    return 0;  
}  