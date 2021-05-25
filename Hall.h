#pragma once
#include "Date.h"
#include "Vector.h"

class Hall {
	size_t rows;
	size_t seatsPerRow;
	Vector<Date> bookedDates;
public:
	Hall() : rows(0), seatsPerRow(0), bookedDates(Vector<Date>()) {};
	Hall(size_t _rows, size_t _seatsPerRow) : rows(_rows), seatsPerRow(_seatsPerRow), bookedDates(Vector<Date>()) {};

	void book(const Date& date) {
		bookedDates.PushBack(date);
	}
	size_t getRows() const {
		return rows;
	}
	size_t getSeats() const {
		return seatsPerRow;
	}
	bool isBooked(const Date& date) const {
		size_t size = bookedDates.getSize();
		for (size_t i = 0; i < size; i++)
		{
			if (bookedDates[i] == date)
				return true;
		}
		return false;
	}
	bool isFree(const Date& date) const {
		return !isBooked(date);
	}
	friend std::ostream& operator<<(std::ostream& out, const Hall& current) {
		out << current.rows;
		out << current.seatsPerRow;
		size_t size = current.bookedDates.getSize();
		for (size_t i = 0; i < size; i++)
		{
			out << current.bookedDates[i] << "\n";
		}
		return out;
	}
};

