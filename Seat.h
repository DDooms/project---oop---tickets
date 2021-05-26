#pragma once
#include "Date.h"
#include "Vector.h"
#include "String.h"
#include <cstdlib>
#include <ctime>

class Seat {
	size_t rowNumber;
	size_t seatNumber;
	bool booked;
	String note;
	size_t ticketNum;
	Date buyingDate;

	size_t random() const;

public:
	Seat();
	Seat(size_t _rowNumber, size_t _seatNumber);
	String getNote() const;
	void setNote(const String& _note);
	bool isBooked() const;
	void book();
	void unbook();
	bool isBought() const;
	void buy(const Date& date);
	size_t getTicketNum() const;
	bool isBoughtInDateInterval(const Date& dateFrom, const Date& dateTo) const;
	friend std::ostream& operator<<(std::ostream& out, const Seat& current);
	friend std::istream& operator>>(std::istream& in, Seat& current);
};