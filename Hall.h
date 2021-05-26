#pragma once
#include "Date.h"
#include "Vector.h"

class Hall {
	size_t rows;
	size_t seatsPerRow;
	Vector<Date> bookedDates;
public:
	Hall();
	Hall(size_t _rows, size_t _seatsPerRow);

	void book(const Date& date);
	size_t getRows() const;
	size_t getSeats() const;
	bool isBooked(const Date& date) const;
	bool isFree(const Date& date) const;
	friend std::ostream& operator<<(std::ostream& out, const Hall& current);
	friend std::istream& operator>>(std::istream& in, Hall& current);
};

