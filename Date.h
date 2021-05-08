#pragma once
#include <iostream>
class Date
{
	size_t day, month, year;

	size_t daysInMonth(size_t month, size_t year);
	bool compareDates(Date& date1, Date& date2);
	bool isDateCorrect(size_t day, size_t month, size_t year);
	bool isLeapYear(size_t year);
public:
	Date();
	Date(size_t days, size_t months, size_t years);
	Date& operator=(const Date& other);
	friend std::ostream& operator<<(std::ostream& out, const Date& current);
	friend std::istream& operator>>(std::istream& in, Date& current);
	bool operator==(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>=(const Date& other) const;

	size_t getDays() const;
	size_t getMonths() const;
	size_t getYears() const;

	void setDays(size_t days);
	void setMonths(size_t months);
	void setYears(size_t years);

	void print() const;
};

