#include<iostream>
#include <math.h>
using namespace std;
int main(){
	int value;
	cout << "Please enter a number" << endl;
	cin >> value;
	int temp = value;
	int numDigits = 0;
	while(temp > 0){
		temp /= 10;
		numDigits++;
	}
	temp = value;
	int sum = 0, digit;
	for(int i = 0; i < numDigits; i++){
		digit = temp % 10;
		sum += digit;
		temp /= 10;
		cout << digit << " " << sum << endl; 
	}
	cout << "You entered: " << value << endl;
	cout << "The sum of the numbers digits is: " << sum << endl;	
}
