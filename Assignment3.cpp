//Assignment 3 PT 1 Section 8
//DATE: 10/1/2025
//CRYSTAL YAP WEN JING A24CS0240
//AW XU YUEN AS24CS0052

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#define SIZE 10
#define MAX_UNIS 18

void getInput(string unis[], int intake[], int enrolment[], int output[]);
void calcTotal(int[], double&);
int getLowest(int[]);
int getHighest(int[]);

int main(){

    string unis[MAX_UNIS];
    int intake[MAX_UNIS], enrolment[MAX_UNIS], output[MAX_UNIS];
    double totalIntake = 0, totalEnrol = 0, totalOutput = 0;
    int lowestIntakeIndex=0, lowestEnrolIndex=0, lowestOutputIndex=0;
    int highestIntakeIndex=0, highestEnrolIndex=0, highestOutputIndex=0;
    
    getInput(unis, intake, enrolment, output); //read Input from the input file
    
    calcTotal(intake, totalIntake);
    calcTotal(enrolment, totalEnrol);
    calcTotal(output, totalOutput);

    lowestIntakeIndex = getLowest(intake);
    lowestEnrolIndex = getLowest(enrolment);
    lowestOutputIndex = getLowest(output);

    highestIntakeIndex = getHighest(intake);
    highestEnrolIndex = getHighest(enrolment);
    highestOutputIndex = getHighest(output);
    
    ofstream outFile ("output.txt");

    outFile << setw(57) << "NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT\n";
    outFile << setw(46) << "IN PUBLIC UNIVERSITIES (2023)\n";
    outFile << "---------------------------------------------------------------\n";
    outFile << "  UNIVERSITY" << setw(18) << "INTAKE" << setw(17) << "ENROLMENT" << setw(13) << "OUTPUT\n";
    outFile << "---------------------------------------------------------------\n";

    for (int i = 0; i < MAX_UNIS; i++) {
        outFile << setw(5) << "";
        outFile << left << setw(10) << unis[i];
        outFile << right << setw(15) << intake[i] << setw(15) << enrolment[i] << setw(15) << output[i] << endl;
    }

    outFile << "---------------------------------------------------------------\n";
    outFile << setw(5) << "";
    outFile << left << setw(10) << "TOTAL";
    outFile << right << setw(15) << totalIntake << setw(15) << totalEnrol << setw(15) << totalOutput << endl;

    outFile << setw(5) << "";
    outFile << left << setw(10) << "AVERAGE";
    outFile << fixed << setprecision(2);
    outFile << right << setw(15) << totalIntake / MAX_UNIS << setw(15) << totalEnrol / MAX_UNIS << setw(15) << totalOutput / MAX_UNIS << endl;
    outFile << "---------------------------------------------------------------\n";

    outFile << "THE LOWEST NUMBER OF STUDENTS' INTAKE    = " << intake[lowestIntakeIndex] << " (" << unis[lowestIntakeIndex] << ")\n";
    outFile << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT = " << enrolment[lowestEnrolIndex] << " (" << unis[lowestEnrolIndex] << ")\n";
    outFile << "THE LOWEST NUMBER OF STUDENTS' OUTPUT    = " << output[lowestOutputIndex] << " (" << unis[lowestOutputIndex] << ")\n\n";
    
    outFile << "THE HIGHEST NUMBER OF STUDENTS' INTAKE    = " << intake[highestIntakeIndex] << " (" << unis[highestIntakeIndex] << ")\n";
    outFile << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT = " << enrolment[highestEnrolIndex] << " (" << unis[highestEnrolIndex] << ")\n";
    outFile << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT    = " << output[highestOutputIndex] << " (" << unis[highestOutputIndex] << ")\n\n";

    outFile << "THE RANGE OF NUMBER OF STUDENTS' INTAKE    = " << intake[highestIntakeIndex] - intake[lowestIntakeIndex] << "\n";
    outFile << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT = " << enrolment[highestEnrolIndex] - enrolment[lowestEnrolIndex] << "\n";
    outFile << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT    = " << output[highestOutputIndex] - output[lowestOutputIndex] << "\n";
    outFile << "---------------------------------------------------------------\n";
    
    return 0;
}

//Task 1
void getInput(string unis[], int intake[], int enrolment[], int output[]){
    
    ifstream inFile("input.txt");

    if(!inFile){       //Input Validation
        cout << "ERROR: Cannot open file\n";
        exit (1);
    }
    else{
        cout<<"Successfully open the file!\n";
        cout<<"Processing data...";
    }

    for(int i=0;i<MAX_UNIS;i++){
        inFile>>unis[i]>>intake[i]>>enrolment[i]>>output[i];
    }
    
    inFile.close();
}

//Task 2
void calcTotal(int number[], double& total){
    for(int i=0;i<MAX_UNIS;i++){
        total+=number[i];
    }
}

//Task 3
int getLowest(int number[]){
    int lowestIndex=0;
    int lowest=number[0];
    for(int i=1;i<MAX_UNIS;i++){
        if(number[i]<lowest){
            lowest=number[i];
            lowestIndex=i;
        }
    }
    return lowestIndex;
}

//Task 4
int getHighest(int number[]){
    int highestIndex=0;
    int highest=number[0];
    for(int i=1;i<MAX_UNIS;i++){
        if(number[i]>highest){
            highest=number[i];
            highestIndex=i;
        }
    }
    return highestIndex;
}