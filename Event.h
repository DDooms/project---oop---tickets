#pragma once
#include "String.h"
#include "Row.h"
#include "Vector.h"

class Event {
	String name;
	Date date;
	Vector<Row> rows;
	size_t hallNum;
public:
	Event();
	Event(const String& _name, size_t rowNumbers, size_t colNumbers, const Date& _date, size_t _hallNum);
	String getName() const;
	size_t getHallNum() const;
	size_t getColNumber() const;
	size_t getAllSeats() const;
	size_t getBookedSeats() const;
	size_t getSeatNum(size_t number);
	size_t getFreeSeats() const;
	Date getDate() const;
	bool isValid(size_t rowNumber, size_t seatNumber) const;
	bool isBooked(size_t rowNumber, size_t seatNumber) const;
	void bookSeat(size_t rowNumber, size_t seatNumber, const String& note);
	void unBookSeat(size_t rowNumber, size_t seatNumber);
	void buyTicket(size_t rowNumber, size_t seatNumber, const Date& date);
	size_t getBookedButNotBoughtSeats() const;
	size_t getBoughtSeatsOnDateInterval(const Date& dateFrom, const Date& dateTo) const;
	friend std::ostream& operator<<(std::ostream& out, const Event& current);
	friend std::istream& operator>>(std::istream& in, Event& current);
};
