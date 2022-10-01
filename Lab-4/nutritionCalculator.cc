#include <iostream>
using namespace std;
int main() {
	double const lethalDose = 5.0 / 35.0;
	double const sweetenerContent = 0.001;
	double const gramsInDietSoda = 350.0 * sweetenerContent; 
	int weight, weightInGrams, sodaLimit;

	cout << "Enter your target weight: ";
	cin >> weight;
	weightInGrams = weight * 454;
	while(weight > 0){
		double sweetenerLimit = (double)weightInGrams * lethalDose;
		sodaLimit = sweetenerLimit / gramsInDietSoda;
		cout << "It would take " << sodaLimit << " cans of diet soda to kill you" << endl;
		cout << "Enter a new weight or '0' to quit: ";
		cin >> weight;
		weightInGrams = weight * 454;
	} 
	return 0;
}
