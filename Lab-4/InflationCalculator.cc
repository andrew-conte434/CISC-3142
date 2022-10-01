#include <iostream>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;
int main(){

	double inflationRate, price, years;
	cout << "Enter an inflation rate: ";
	cin >> inflationRate;
	inflationRate = inflationRate / (double)100;
	cout << "Enter a starting price: ";
	cin >> price;
	cout << "How many years do you wish to calculate? ";
	cin >> years;

	for(int i = 0; i < years; i++){
		price = price + (price * inflationRate);
	}

	cout << "Estimated price after " << years << " years: "
		<< fixed << setprecision(2) << price << endl;
}
