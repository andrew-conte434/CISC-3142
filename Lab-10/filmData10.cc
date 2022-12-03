#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <functional>
#include <numeric>
#include <algorithm>
#include "../Lab-8/Film.h"

using namespace std;

bool uniqueYear(const Film& current, const Film& next){
    return current.YEAR == next.YEAR;
}

int main() {

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
                    break;
				case 9:
					film.IMAGE = word;
					films.push_back(film);
					break;
			}
			
			count++;

		}
	}

    int totalLength = accumulate(films.begin(), films.end(), 0, 
                    [](int a, const Film& curr) {return a + curr.LENGTH;});
    output << "Total length of all films: " << totalLength << endl; 

    output << endl;

    sort(films.begin(), 
         films.end(), 
         [](const Film& curr, const Film& next){return curr.POPULARITY > next.POPULARITY;});
    output << "Top 10 most popular films: " << endl;
    for(int i = 0; i < 10; i++){
        output << films[i].TITLE << " " << films[i].POPULARITY <<endl;
    }

    output << endl;

    auto it = find_if(films.begin(), 
                                    films.end(), 
                                    [](const Film& current){return current.ACTOR == "Connery, Sean";});
    Film connery;
    if(it != films.end()){
        connery = *it;
    } else {
        cout << "no connery" << endl;
    }
    output << "First film to feature Sean Connery: " << connery.TITLE << endl << endl;

    vector<Film> comedy, action;
    for(const auto& film : films) {
        if(film.GENRE == "Comedy"){
            comedy.push_back(film);
        } else if (film.GENRE == "Action"){
            action.push_back(film);
        }
    }
    sort(comedy.begin(), 
        comedy.end(), 
        [](const Film& curr, const Film& next){return curr.YEAR > next.YEAR;});
    sort(action.begin(), 
        action.end(), 
        [](const Film& curr, const Film& next){return curr.YEAR > next.YEAR;});

    unique(comedy.begin(), comedy.end(), uniqueYear);
    unique(action.begin(), action.end(), uniqueYear);
    
    bool equalYears = equal(comedy.begin(), comedy.end(), action.begin(),
                    [](const Film& comedy, const Film& action){return comedy.YEAR == action.YEAR;});
    
    if(equalYears){
        output << "Comedy and Action movies were released in the same years." << endl;
    } else {
        output << "Comedy and Action movies were not released in the same years." << endl;
    }

}