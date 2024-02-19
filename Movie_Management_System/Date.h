#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Date {
public:
	// Static variable
	static string format;  // Either "US", "Euro", or "Asian"

	// Constructor
	Date(unsigned int = 0, unsigned int = 0, unsigned int = 0);  // Constructor with initial values of "month", "day" and "year"

	// Overloading the operator "<="
	bool operator<=(const Date&) const;

	// Overloading the operator "=="
	bool operator==(const Date&) const;

	// Overloading the operator "<"
	bool operator < (const Date&) const;

	// Overloading the operator ">"
	bool operator > (const Date&) const;

	// method for checking whether date's are valid or not
	bool isValid() const;

	// method for parse the string to unsigned int format to load the date data
	bool parse_from_string(const string&);

	// Getters
	unsigned int get_year() const;  // Returns the year of the date.
	unsigned int get_month() const;  // Returns the month of the date.
	unsigned int get_day_of_month() const;  // Returns the day-of-month of the date.


	// Setters
	void set_year(unsigned int);  // Updates the year of the date.
	void set_month(unsigned int);  // Updates the month of the date.
	void set_day_of_month(unsigned int);  // Updates the day-of-month of the date.

	// Class-member function
	void print_date(ostream&) const;  // Prints the date to an output stream.

private:
	// Data fields
	unsigned int year;  // Stores the year of the date.
	unsigned int month;  // Stores the month of the date.
	unsigned int day_of_month;  // Stores the day-of-month of the date.
};


// Static variable
string Date::format = "US";

// Constructor

// Constructor with initial values of "year", "month", and "day_of_month"
Date::Date(unsigned int year, unsigned int month, unsigned int day_of_month) :
	year(year), month(month), day_of_month(day_of_month) {}

// Getters

/** Returns the year of the date.
	@return: year of the date
*/
unsigned int Date::get_year() const { return year; }

/** Returns the month of the date.
	@return: month of the date
*/
unsigned int Date::get_month() const { return month; }

/** Returns the day-of-month of the date.
	@return: day-of-month of the date
*/
unsigned int Date::get_day_of_month() const { return day_of_month; }

// Setters

/** Updates the value of the year of the date.
	@param new_year: updated value of the year of the date
*/
void Date::set_year(unsigned int new_year) { year = new_year; }

/** Updates the value of the month of the date.
	@param new_month: updated value of the month of the date
*/
void Date::set_month(unsigned int new_month) { month = new_month; }

/** Updates the value of the day-of-month of the date.
	@param new_day_of_month: updated value of the day-of-month of the date
*/
void Date::set_day_of_month(unsigned int new_day_of_month) { day_of_month = new_day_of_month; }

// Class-member function

/** Prints the date to an output stream.
	@param out: output stream to show the date
*/
void Date::print_date(ostream& out) const {
	if (format == "US") { out << month << '/' << day_of_month << '/' << year << endl; }
	if (format == "Euro") { out << day_of_month << '/' << month << '/' << year << endl; }
	if (format == "Asian") { out << year << '-' << month << '-' << day_of_month << endl; }
}

bool Date::operator<=(const Date& other) const {
	// Implement the logic to compare dates
	// For example, you can compare years, months, and days one by one
	// or convert them to a comparable numerical value.
	// Return true if this date is less than or equal to the other date.
	if (this->month <= other.month && this->year <= other.year && this->day_of_month <= other.day_of_month) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator < (const Date& other) const {

	if (this->month < other.month && this->year < other.year && this->day_of_month < other.day_of_month) {
		return true;
	}

	return false;

}


bool Date::operator > (const Date& other) const {

	if (this->month > other.month && this->year > other.year && this->day_of_month > other.day_of_month) {
		return true;
	}

	return false;
}


bool Date::operator==(const Date& other) const {

	if (other.day_of_month == day_of_month && month == other.month && year == other.year) {
		return true;
	}
	return false;
}


bool Date::isValid() const {

	if (year < 1900 || year > 2100) {
		return false;
	}

	if (month < 1 || month > 12) {
		return false;
	}

	if (day_of_month < 1 || day_of_month > 31) {
		return false;
	}

	return true;
}


bool Date::parse_from_string(const string& date_string) {

	istringstream read_string(date_string);
	unsigned int month, day, year;

	string month_string = date_string.substr(0, 2);
	month = stoi(month_string);

	string day_string = date_string.substr(3, 5);
	day = stoi(day_string);

	string year_string = date_string.substr(6, 10);
	year = stoi(year_string);

	set_month(month);
	set_day_of_month(day);
	set_year(year);
	return true;

}


#endif