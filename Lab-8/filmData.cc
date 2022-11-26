#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include "Film.h"

using namespace std;

double getAverageLength(vector<Film> films);
int getAwardCount(vector<Film> films);

int main(){
	fstream input("film.csv.txt");
	ofstream output;
	output.open("results.txt");
	vector<Film> films;
	map<int, vector<Film>> decades;
	map<string, vector<Film>> genres;

	while(input.good()){
		string line, word;
		getline(input, line);
		stringstream str(line);
		int count = 0;
		Film film;
		while(getline(str, word, ';')){
			if(word == "Year" || word == "INT"){break;}
			
			switch(count){
				case 0:
					film.YEAR = stoi(word);
					break;
				case 1:
					if(!word.empty()){
						film.LENGTH = stoi(word);
					} else {
						film.LENGTH = 0;
					}
					break;
				case 2:
					film.TITLE = word;
					break;
				case 3:
					film.GENRE = word;
					break;
				case 4:
					film.ACTOR = word;
					break;
				case 5:
					film.ACTRESS = word;
					break;
				case 6: 
					film.DIRECTOR = word;
					break;
				case 7:
					if(!word.empty()){
						film.POPULARITY = stoi(word);
					} else {
						film.POPULARITY = 0;
					}
					break;
				case 8:
					if(word == "Yes"){
						film.AWARDS = true;
					} else {
						film.AWARDS = false;
					}
				case 9:
					film.IMAGE = word;
					films.push_back(film);
					break;
			}
			
			count++;

		}
	}

	//Iterate through films vector and add each film to decades map
	for (const auto& film : films) {
		decades[(film.YEAR / 10) * 10].push_back(film); //Rounds film's year to nearest ten
		genres[(film.GENRE)].push_back(film);
	}

	output << "Average length of all films: " << getAverageLength(films) << " minutes" << endl;

	double average;
	int awards;
	output << "Average length by decade: " << endl;
	for (auto it = decades.begin(); it != decades.end(); ++it) {
		average = getAverageLength((*it).second);
		output << (*it).first << "s: " << average << " minutes" << endl;
	}
	output << endl << "Awarded films by genre: " << endl;
	for (auto it = genres.begin(); it != genres.end(); ++it) {
		awards = getAwardCount((*it).second);
		if (!(*it).first.empty()) {
			output << (*it).first << ": " << awards << " " << endl;
		}
	}

	output.close();
	return 0;
}

double getAverageLength(vector<Film> films) {
	int total = 0;
	int count = 0;
	for (Film film : films) {
		if (film.LENGTH > 0) {
			total += film.LENGTH;
			count++;
		}	
	}
	double average = total / count;
	return average;
}

int getAwardCount(vector<Film> films) {
	int total = 0;
	for (const auto& film : films) {
		if (film.AWARDS) {
			total++;
		}
	}
	return total;
}
