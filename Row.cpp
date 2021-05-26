#include "Row.h"

Row::Row() : rowNumber(0) {}

Row::Row(size_t _rowNumber, size_t numberOfSeats) : rowNumber(_rowNumber) {
	for (size_t i = 0; i < numberOfSeats; i++)
	{
		Seat seat(_rowNumber, i);
		seats.PushBack(seat);
	}
}

size_t Row::getSize() const {
	return seats.getSize();
}

Seat& Row::operator[](size_t index) const {
	return seats[index];
}

std::ostream& operator<<(std::ostream& out, const Row& current) {
	size_t size = current.seats.getSize();
	out << size << "\n";
	out << current.rowNumber;
	for (size_t i = 0; i < size; i++)
	{
		out << current.seats[i] << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Row& current) {
	size_t size = current.seats.getSize();
	in >> size;
	in >> current.rowNumber;
	for (size_t i = 0; i < size; i++)
	{
		in >> current.seats[i];
	}
	return in;
}