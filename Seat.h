#pragma once
#include "Date.h"
#include "String.h"

class Seat {
	size_t rowNumber;
	size_t seatNumber;
	bool booked;
	String note;
	Date buyingDate;
public:
	Seat() : rowNumber(0), seatNumber(0), booked(false), note(""){}
	Seat(size_t _rowNumber, size_t _seatNumber) : rowNumber(_rowNumber), seatNumber(_seatNumber), booked(false), note(""){}
	String getNote() const {
		return note;
	}
	void setNote(const String& _note) {
		note = _note;
	}

	bool is_booked() const {
		return booked;
	}
	void book() {
		booked = true;
	}
	void unbook() {
		booked = false;
	}
};