#ifndef PERSON
#define PERSON
#include <string>
#include <sstream>

using namespace std;

class Person {

public:
	Person(string firstIn, string lastIn, int monthIn, int dayIn, int yearIn, char genderIn):
	first(firstIn), last(lastIn), month(monthIn), day(dayIn), year(yearIn), gender(genderIn) {};

	string getFullName() {
		return first + " " + last;
	};

	string getDOB() {
		stringstream ss;
		ss << month << "/" << day << "/" << year << " ";
		
		return ss.str();
	}

	char getGender() {
		return gender;
	}

	friend ostream& operator<<(ostream& os, Person& p) {
		os << p.getFullName() << ", Gender: " << p.gender << ", Born: " << p.getDOB() << endl;
		return os;
	}

	
private:
	string first, last;
	int month, day, year;
	char gender;
};

#endif
