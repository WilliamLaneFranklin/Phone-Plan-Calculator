#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


//function prototypes
void welcomeMessage();
void planTypes();
char getInput();
double calculatePlanAmount(char userPlan);
double getUserGB();
double calculateOverage(char userPlan, double userGB);
void outputTotals(double planAmount, double userGB);
void endingMessage();


//constants
const double SMALL = 35.00;
const double MEDIUM = 50.00;
const double LARGE = 70.00;
const double UNLIMITED = 75.00; 


int main(){
	welcomeMessage();
	planTypes();

	char userPlan;
	userPlan = getInput();

	cout << fixed << showpoint << setprecision(2);

	double planAmount = 0.00;
	planAmount = calculatePlanAmount(userPlan);

	double userGB = 0.00;
	userGB = getUserGB();

	double overageAmount = 0.00;
	overageAmount = calculateOverage(userPlan, userGB);

	outputTotals(planAmount, overageAmount);
	endingMessage();
	return 0;
}


void welcomeMessage(){
	cout << "***** Welcome to Mint Mobile! *****" << endl;
	cout << '\n' << "Let's calculate your monthly bill!" << '\n' << endl;
}


void planTypes(){
	cout << "S: 2GB $35/mo*" << endl;
	cout << "M: 4GB $50/mo*" << endl;
	cout << "L: 8GB $70/mo*" << endl;
	cout << "U: Unlimited $75/mo" << endl;
	cout << '\n' << "*Overage charges $15 per GB" << endl;
}


char getInput(){
	cout << '\n' << "Which plan are you on? (S/M/L/U): ";
	char userPlan;
	cin >> userPlan;
	userPlan = toupper(userPlan);
	while (userPlan != 'S' && userPlan != 'M' && userPlan != 'L' && userPlan != 'U'){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid plan!" << endl;
		cout << '\n' << "Which plan are you on? (S/M/L/U): ";
		cin >> userPlan;
		userPlan = toupper(userPlan);
	}
	return userPlan;
}


double calculatePlanAmount(char userPlan){
	double planAmount = 0.00;
	switch (userPlan){
		case 'S':
		planAmount = SMALL;
		break;

		case 'M':
		planAmount = MEDIUM;
		break;

		case 'L':
		planAmount = LARGE;
		break;

		case 'U':
		planAmount = UNLIMITED;
		break;

		}
	return planAmount;
}


double getUserGB(){
	cout << '\n' << "How many GB did you use last month? ";
	double userGB = 0.00;
	cin >> userGB;
	while (!cin || userGB < 0.00){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid number of GB" << endl;
		cin >> userGB;
	}
	userGB = ceil(userGB);
	return userGB;
}


double calculateOverage(char userPlan, double userGB){
	double overageAmount = 0.00;
	if (userPlan == 'S' && userGB > 2){
		overageAmount = (userGB - 2) * 15.00;
	}
	else if (userPlan == 'M' && userGB > 4){
		overageAmount = (userGB - 4) * 15.00;
	}
	else if (userPlan == 'L' && userGB > 8){
		overageAmount = (userGB - 8) * 15.00;
	}
	return overageAmount;
}


void outputTotals(double planAmount, double overageAmount){
	cout << '\n' << "Plan charges: $" << planAmount << endl;
	if (overageAmount > 0){
		cout << "Overage charges: $" << overageAmount << endl;
	}
	cout << "Total cost: $" << planAmount + overageAmount << endl;
	if (planAmount + overageAmount > 75.00){
		cout << '\n' << "Upgrade to Unlimited and save $" << (planAmount + overageAmount) - UNLIMITED << "!!!" << endl;
	}
}


void endingMessage(){
	cout << '\n' << "Thank you for choosing Mint Mobile." << endl;
	cout << "Goodbye!" << endl;
}
