#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

using namespace std;

struct Weather {
	string MONTH;
	int TEMP;
};

bool isDigit(string word);
double getAverage(vector<Weather> weatherData, int start, int end);
double getWeightedAverage(vector<Weather> weatherData, int start, int end);

int main() {
	fstream input("weather.csv");
	ofstream output;
	output.open("results.txt");
	vector<Weather> weatherData;

	while (input.good()) {
		string line, word;
		getline(input, line);
		stringstream str(line);
		Weather weather;
		while (getline(str, word, ',')) {
			if (word == "Month" || word == "Temp") { break; }
			if (isDigit(word)) {
				weather.TEMP = stoi(word);
			}
			else {
				weather.MONTH = word;
			}
		}
		if (!weather.MONTH.empty()) {
			weatherData.push_back(weather);
		}
		
	}

	double average = getAverage(weatherData, 0, 9);
	output << "October weather based on average: " << average << endl;
	average = getAverage(weatherData, 6, 9);
	output << "October weather based on moving average: " << average << endl;
	average = getWeightedAverage(weatherData, 6, 9);
	output << "October weather based on weighted moving average: " << average << endl;
	return 0;
}

bool isDigit(string word) {
	regex digits(R"(^^\s*[-+]?((\d+(\.\d+)?)|(\d+\.)|(\.\d+))(e[-+]?\d+)?\s*$)");
	return regex_match(word, digits);
}

double getAverage(vector<Weather> weatherData, int start, int end) {
	double total = 0;
	for (int i = start; i < end; i++) {
		total += weatherData.at(i).TEMP;
	}
	return (total / (end - start));
}

double getWeightedAverage(vector<Weather> weatherData, int start, int end) {
	int weights[3] = { 1, 2, 3 };
	int temperatures[3] = {0, 0, 0};
	for (int i = start; i < end; i++) {
		temperatures[i - start] = weatherData.at(i).TEMP;
	}
	double weightedSum = 0;
	int sumOfWeights = 0;
	for (int i = 0; i < sizeof(weights) / sizeof(int); i++) {
		weightedSum += (temperatures[i] * weights[i]);
		sumOfWeights += weights[i];
	}

	return weightedSum / sumOfWeights;

}