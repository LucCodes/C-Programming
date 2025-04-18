#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// constants
const int STUDENTS = 5;
const int SCORES = 4;

// function prototypes
void getStudentData(string names[], double testScores[][SCORES]);
void calculateResults(double testScores[][SCORES], double averages[], char grades[], double droppedScores[]);
char determineGrade(double average);
void displayResults(string names[], double averages[], char grades[], double droppedScores[]);

int main() {
    // Arrays as specified in the requirements
    string names[STUDENTS];        // Students' names
    char grades[STUDENTS];         // The letter grades
    double averages[STUDENTS];     // The average scores
    double testScores[STUDENTS][SCORES]; // Students' test scores
    double droppedScores[STUDENTS]; // Scores that were dropped
    
    // get student data
    getStudentData(names, testScores);
    
    // calculate averages, grades, and determine dropped scores
    calculateResults(testScores, averages, grades, droppedScores);
    
    // display the results
    displayResults(names, averages, grades, droppedScores);
    
    return 0;
}

// function to get student names and test scores
void getStudentData(string names[], double testScores[][SCORES]) {
    for (int i = 0; i < STUDENTS; i++) {
        cout << "Enter the name of student " << (i + 1) << ": ";
        getline(cin, names[i]);
        
        for (int j = 0; j < SCORES; j++) {
            do {
                cout << "Enter test score " << (j + 1) << " for " << names[i] << ": ";
                cin >> testScores[i][j];
                
                // input validation
                if (testScores[i][j] < 0 || testScores[i][j] > 100) {
                    cout << "Error: Score must be between 0 and 100. Please try again." << endl;
                }
            } while (testScores[i][j] < 0 || testScores[i][j] > 100);
        }
        
        // clear the input buffer
        cin.ignore();
    }
}

// calculate averages, grades, and determine dropped scores
void calculateResults(double testScores[][SCORES], double averages[], char grades[], double droppedScores[]) {
    for (int i = 0; i < STUDENTS; i++) {
        // find the lowest score for this student
        double lowest = testScores[i][0];
        for (int j = 1; j < SCORES; j++) {
            if (testScores[i][j] < lowest) {
                lowest = testScores[i][j];
            }
        }
        
        // store the dropped score
        droppedScores[i] = lowest;
        
        // calculate the average excluding the lowest score
        double sum = 0;
        for (int j = 0; j < SCORES; j++) {
            sum += testScores[i][j];
        }
        sum -= lowest; // Subtract the lowest score
        averages[i] = sum / (SCORES - 1); // Divide by number of scores minus 1
        
        // determine the letter grade
        grades[i] = determineGrade(averages[i]);
    }
}

// determine the letter grade based on the average score
char determineGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// display the results
void displayResults(string names[], double averages[], char grades[], double droppedScores[]) {
    cout << "\nResults:" << endl;
    cout << left << setw(15) << "Student Name" 
         << setw(15) << "Dropped Score" 
         << setw(15) << "Average Score" 
         << "Grade" << endl;
    cout << string(50, '-') << endl;
    
    for (int i = 0; i < STUDENTS; i++) {
        cout << left << setw(15) << names[i] 
             << fixed << setprecision(2) << setw(15) << droppedScores[i] 
             << setw(15) << averages[i] 
             << grades[i] << endl;
    }
}
