//Assignment 2 PT 1 Section 8
//DATE: 24/12/2024
//CRYSTAL YAP WEN JING A24CS0240
//AW XU YUEN AS24CS0052

/* 
-------------------------   [ CAR PRICE LIST ]  ----------------------------------
Model	Variant	            Region	                Paint Type	Price(East+2000)
----------------------------------------------------------------------------------
X50	    1.5T Standard	    Peninsular Malaysia	    Metallic	86300
		                    East Malaysia	        Metallic	88300

	    1.5T Executive	    Peninsular Malaysia	    Metallic	93300
		                    East Malaysia		                95300

	    1.5T Premium	    Peninsular Malaysia	    Metallic	101800
		                    East Malaysia		                103800
                            
	    1.5 TGDI Flagship	Peninsular Malaysia	    Metallic	113300
		                    East Malaysia		                115300
----------------------------------------------------------------------------------
Exora	1.6T Executive CVT	Peninsular Malaysia	    Metallic	62800
		                    East Malaysia		                64800

	    1.6T Premium CVT	Peninsular Malaysia	    Metallic	69800
		                    East Malaysia		                71800
----------------------------------------------------------------------------------
Persona	1.6L Standard CVT	Peninsular Malaysia	    Metallic	47800
		                    East Malaysia		                49800

	    1.6L Executive CVT	Peninsular Malaysia	    Metallic	53300
		                    East Malaysia		                55300

	    1.6L Premium CVT	Peninsular Malaysia	    Metallic	58300
		                    East Malaysia		                60300

*/

//----------------------------------------------------------------------------------------------


#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void getCarInfo(int&, char[], int&, int&);
void getVariant(int, char[], int&);
void displayCarInfo(int, char[], int, int, double&);
void getPrice(int, int, int, double&);
void getAmount(double&,double&, double&, double&);
void calcMonthlyInstallment(double,double, double, double);

int main() {
    
    int model, choice, region;
    const int SIZE = 50;
    char variant[SIZE];
    double price, DP, IR, RP;

    getCarInfo(model, variant, choice, region);
    displayCarInfo(model, variant, choice, region, price);
    getAmount(price, DP, IR, RP);
    return 0;

}

void getCarInfo(int& model, char variant[], int& choice, int& region) {

    //Choose car model
    do {
        cout << "Model [1-X50, 2-Exora, 3-Persona]: ";
        cin >> model;
        if (model < 1 || model > 3) {
            cout << "Invalid input! Please enter again.\n";
        }
    } while (model < 1 || model > 3);

    //Choose car variant
    getVariant(model, variant, choice);

    //Choose region
    do {
        cout << "Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
        cin >> region;
        if (region < 1 || region > 2) {
            cout << "Invalid input! Please enter again.\n";
        }
    } while (region < 1 || region > 2);
}

void getVariant(int model, char variant[], int& choice) {
    int maxChoice = 0;
    
    //Display variant menu
    cout << "Variants [";
    switch (model) {
        case 1: 
            cout << "1-1.5T Standard, 2-1.5T Executive, 3-1.5T Premium, 4-1.5 TGDI Flagship"; 
            maxChoice = 4;
            break;
        case 2: 
            cout << "1-1.6T Executive CVT, 2-1.6T Premium CVT"; 
            maxChoice = 2;
            break;
        case 3: 
            cout << "1-1.6L Standard CVT, 2-1.6L Executive CVT, 3-1.6L Premium CVT"; 
            maxChoice = 3;
            break;
    }
    cout << "]: ";
    cin >> choice;

    while (choice < 1 || choice > maxChoice) {
        cout << "Invalid Input! Please enter again: ";
        cin >> choice;
    }

    // Assign variant according to model and variant choice
    switch (model) {
        case 1:
            strcpy(variant, "1.5T ");
            switch (choice) {
                case 1: strcat(variant, "Standard"); break;
                case 2: strcat(variant, "Executive"); break;
                case 3: strcat(variant, "Premium"); break;
                default: strcpy(variant, "1.5 TGDI Flagship"); break;
            }
            break;
        case 2:
            strcpy(variant, "1.6T ");
            switch (choice) {
                case 1: strcat(variant, "Executive"); break;
                default: strcat(variant, "Premium"); break;
            }
            strcat(variant, " CVT");
            break;
        default:
            strcpy(variant, "1.6L ");
            switch (choice) {
                case 1: strcpy(variant, "Standard"); break;
                case 2: strcpy(variant, "Executive"); break;
                default: strcpy(variant, "Premium"); break;
            }
            strcat(variant, " CVT");
            break;
    }
}

void displayCarInfo(int model, char variant[], int choice, int region, double& price) {

    cout << endl << "Car Info" << endl
         << "Model: ";
    switch (model) {
        case 1: cout << "X50"; break;
        case 2: cout << "Exora"; break;
        default: cout << "Persona"; break;
    }

    cout <<"\nVariant: " << variant;

    cout <<"\nRegion: " << (region==1 ? "Peninsular Malaysia" : "East Malaysia");

    cout <<"\nPaint Type: Metallic";
    getPrice(model,choice,region,price);
    cout <<"\nPrice (MYR): "<<fixed<<setprecision(2)<<price<<endl<<endl;
}

void getPrice(int model, int choice, int region, double& price){

    const double prices[3][4]={
        {86300, 93300, 101800, 113300}, // X50
        {62800, 69800, 0, 0},           // Exora
        {47800, 53300, 58300, 0}        // Persona
    };

    price=prices[model-1][choice-1];

    if (region==2) {
        price+=2000; //Price for East Malaysia region
    }
}

void getAmount(double& price, double& DP, double& IR, double& RP) {
    cout << "Down Payment (MYR): ";
    cin >> DP;
    while(DP>price){
        cout<<"Error: Down Payment cannot exceed the car price."
            <<"Please enter again: ";
        cin>>DP;
    }

    cout << "Interest Rate (%): ";
    cin >> IR;

    cout << "Repayment period (in years): ";
    cin >> RP;
    while(RP<=0){
        cout<<"Repayment period must be greater than 0. Please enter again: ";
        cin>>RP;
    }

    calcMonthlyInstallment(price,DP,IR,RP);
}

void calcMonthlyInstallment(double price, double DP, double IR, double RP) {

    double loanAmount = price - DP;
    double totalInterest = loanAmount * (IR / 100) * RP;
    double monthlyInstallment = (loanAmount + totalInterest) / (RP * 12);

    cout<<"MONTHLY INSTALLMENT (MYR): "<<fixed<<setprecision(2)<<monthlyInstallment<<endl;
}
