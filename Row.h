#pragma once
#include "Vector.h"
#include "Seat.h"

class Row {
	size_t rowNumber;
	Vector<Seat> seats;
public:
	Row() : rowNumber(0){}
	Row(size_t _rowNumber, size_t numberOfSeats) : rowNumber(_rowNumber) {
		for (size_t i = 0; i < numberOfSeats; i++)
		{
			Seat seat(_rowNumber, i);
			seats.PushBack(seat);
		}
	}
	size_t getSize() const {
		return seats.getSize();
	}
};
