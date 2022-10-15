#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

double getMean(vector<int> values);
double getSlope(vector<int> Xvalues, vector<int> Yvalues, double Xmean, double Ymean);
double getIntercept(double slope, double Xmean, double Ymean);
double getLinearRegression(double slope, double intercept, double x);

int main() {
	vector<int> Xvalues;
	vector<int> Yvalues;
	ifstream infile("points.txt");
	int value, total = 0;
	while(infile >> value){
		total++;
		if(total % 2 == 1){
			Xvalues.push_back(value);
		} else {
			Yvalues.push_back(value);
		}
	}

	double Xmean = getMean(Xvalues), Ymean = getMean(Yvalues);
	double slope = getSlope(Xvalues, Yvalues, Xmean, Ymean);
	double intercept = getIntercept(slope, Xmean, Ymean);
	cout << "X Mean: " << Xmean << endl;
	cout << "Y Mean: " << Ymean << endl;
	cout << "Slope: "   << slope << endl;
	cout << "Intercept: "  << intercept << endl;
	double x;
	while(true){
		cout << "Enter a value of x: ";
		cin >> x;
		double regression = getLinearRegression(slope, intercept, x);
		cout << "Expected value of Y: " << regression << endl;
	}
	return 0;
}

double getMean(vector<int> values){
	int total = 0;
	double mean;
	for(auto iter = values.begin(); iter != values.end(); ++iter){
		total += *iter;
	}
	mean = (double)total / values.size();
	return mean;
}

double getSlope(vector<int> Xvalues, vector<int> Yvalues, double Xmean, double Ymean){
	double slope;
	double numerator = 0.0;
	double denominator = 0.0;
	double Xdifference, Ydifference;
	for(int i = 0; i < Xvalues.size(); i++){
		Xdifference = (Xvalues[i] - Xmean);
		Ydifference = (Yvalues[i] - Ymean);
		numerator += (Xdifference * Ydifference);
		denominator += (Xdifference * Xdifference);
	}
	denominator *= denominator;
	slope = numerator / denominator;
	return slope;
}

double getIntercept(double slope, double Xmean, double Ymean){
	return (Ymean - (slope * Xmean));
}

double getLinearRegression(double slope, double intercept, double x) {
	return (intercept + slope * x);
}
