#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function prototypes
double validateData(double, string);
double patientCharges(int, double, double, double); // In-patient
double patientCharges(double, double); // Out-patient
void writeToFile(int, int, double, double, double, double);

int main() {
    int patientType, days = 0;
    double dailyRate = 0.0, labFees = 0.0, medicationCharges = 0.0, totalCharges = 0.0;
    
    cout << "This program will compute patient hospital charges." << endl;
    cout << "Enter 1 for in-patient or 0 for out-patient: ";
    cin >> patientType;
    
    if (patientType == 1) { // In-patient
        cout << "Number of days in the hospital: ";
        cin >> days;
        days = validateData(days, "Number of days");
        
        cout << "Daily room rate: $";
        cin >> dailyRate;
        dailyRate = validateData(dailyRate, "Daily room rate");
        
        cout << "Lab fees and other service charges: $";
        cin >> labFees;
        labFees = validateData(labFees, "Lab fees");
        
        cout << "Medication charges: $";
        cin >> medicationCharges;
        medicationCharges = validateData(medicationCharges, "Medication charges");
        
        totalCharges = patientCharges(days, dailyRate, labFees, medicationCharges);
    } else { // Out-patient
        cout << "Lab fees and other service charges: $";
        cin >> labFees;
        labFees = validateData(labFees, "Lab fees");
        
        cout << "Medication charges: $";
        cin >> medicationCharges;
        medicationCharges = validateData(medicationCharges, "Medication charges");
        
        totalCharges = patientCharges(labFees, medicationCharges);
    }
    
    // Write to file
    writeToFile(patientType, days, dailyRate, labFees, medicationCharges, totalCharges);
    
    cout << "The billing report has been written to the hospital.txt file." << endl;
    
    return 0;
}

// Validation function
double validateData(double value, string dataName) {
    while (value < 0) {
        cout << "ERROR: " << dataName << " cannot be negative." << endl;
        cout << "Please enter a valid " << dataName << ": ";
        cin >> value;
    }
    return value;
}

// In-patient charges calculation
double patientCharges(int days, double dailyRate, double labFees, double medicationCharges) {
    return (days * dailyRate) + labFees + medicationCharges;
}

// Out-patient charges calculation
double patientCharges(double labFees, double medicationCharges) {
    return labFees + medicationCharges;
}

// Write to file function
void writeToFile(int patientType, int days, double dailyRate, double labFees, double medicationCharges, double totalCharges) {
    ofstream outputFile;
    outputFile.open("hospital.txt");
    
    outputFile << "***************************" << endl;
    outputFile << "Hospital Billing Statement" << endl;
    outputFile << "***************************" << endl;
    
    if (patientType == 1) { // In-patient
        outputFile << "Room charges    $ " << fixed << setprecision(2) << (days * dailyRate) << endl;
    }
    
    outputFile << "Lab & Services  $ " << fixed << setprecision(2) << labFees << endl;
    outputFile << "Medication      $ " << fixed << setprecision(2) << medicationCharges << endl;
    outputFile << "Total charges   $ " << fixed << setprecision(2) << totalCharges << endl;
    outputFile << "***************************" << endl;
    
    outputFile.close();
}