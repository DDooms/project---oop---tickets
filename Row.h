#pragma once
#include "Vector.h"
#include "Seat.h"

class Row {
	size_t rowNumber;
	Vector<Seat> seats;
public:
	Row();
	Row(size_t _rowNumber, size_t numberOfSeats);
	size_t getSize() const;
	Seat& operator[](size_t index) const;
	friend std::ostream& operator<<(std::ostream& out, const Row& current);
	friend std::istream& operator>>(std::istream& in, Row& current);
};
