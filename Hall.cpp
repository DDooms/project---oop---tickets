#include "Hall.h"

Hall::Hall() : rows(0), seatsPerRow(0), bookedDates(Vector<Date>()) {};

Hall::Hall(size_t _rows, size_t _seatsPerRow) : rows(_rows), seatsPerRow(_seatsPerRow), bookedDates(Vector<Date>()) {};

void Hall::book(const Date& date) {
	bookedDates.PushBack(date);
}

size_t Hall::getRows() const {
	return rows;
}

size_t Hall::getSeats() const {
	return seatsPerRow;
}

bool Hall::isBooked(const Date& date) const {
	size_t size = bookedDates.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (bookedDates[i] == date)
			return true;
	}
	return false;
}

bool Hall::isFree(const Date& date) const {
	return !isBooked(date);
}

std::ostream& operator<<(std::ostream& out, const Hall& current) {
	size_t size = current.bookedDates.getSize();
	out << size << "\n";
	out << current.rows << "\n";
	out << current.seatsPerRow << "\n";
	for (size_t i = 0; i < size; i++)
	{
		out << current.bookedDates[i] << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Hall& current) {
	size_t size = current.bookedDates.getSize();
	in >> size;
	in >> current.rows;
	in >> current.seatsPerRow;
	for (size_t i = 0; i < size; i++)
	{
		in >> current.bookedDates[i];
	}
	return in;
}