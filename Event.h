#pragma once
#include "Seat.h"
#include "String.h"
#include "Row.h"
#include "Vector.h"

class Event {
	String name;
	Date date;
	Vector<Row> rows;
	size_t hallNum;
public:
	Event() : hallNum(0) {}
	Event(const String& _name, size_t rowNumbers, size_t colNumbers, const Date& _date, size_t _hallNum) : name(_name), date(_date), hallNum(_hallNum) {
		for (size_t i = 0; i < rowNumbers; i++)
		{
			Row newRow(i, colNumbers);
			rows.PushBack(newRow);
		}
	}
	String getName() const {
		return name;
	}
	size_t getColNumber() const {
		return rows[0].getSize();
	}
	size_t getAllSeats() const {
		return rows.getSize() * getColNumber();
	}
	size_t getBookedSeats() const {
		size_t counter = 0;
		size_t size = rows.getSize();
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < rows[i].getSize(); j++)
			{
				if (rows[i][j].isBooked())
					counter++;
			}
		}
	}
	size_t getSeatNum(size_t number) {
		size_t size = rows.getSize();
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < rows[i].getSize(); j++)
			{
				if (rows[i][j].getTicketNum()==number)
				{
					return j;
				}
			}
		}
		return -1;
	}
	size_t getFreeSeats() const {
		return getAllSeats() - getBookedSeats();
	}
	Date getDate() const {
		return date;
	}
	bool isValid(size_t rowNumber, size_t seatNumber) const {
		return 0 <= rowNumber && rowNumber < rows.getSize() && 0 <= seatNumber && seatNumber < getColNumber();
	}
	bool isBooked(size_t rowNumber, size_t seatNumber) const {
		return rows[rowNumber][seatNumber].isBooked();
	}
	void bookSeat(size_t rowNumber, size_t seatNumber, const String& note) {
		if (!isBooked(rowNumber, seatNumber)) {
			rows[rowNumber][seatNumber].book();
			rows[rowNumber][seatNumber].setNote(note);
		}
	}
	void unBookSeat(size_t rowNumber, size_t seatNumber) {
		if (isBooked(rowNumber, seatNumber)) {
			rows[rowNumber][seatNumber].unbook();
			rows[rowNumber][seatNumber].setNote("");
		}
	}
	void buyTicket(size_t rowNumber, size_t seatNumber, const Date& date) {
		if (!isBooked(rowNumber, seatNumber))
			rows[rowNumber][seatNumber].buy(date);
	}
	size_t getBookedButNotBoughtSeats() const {
		size_t counter = 0;
		size_t size = rows.getSize();
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < rows[i].getSize(); j++)
			{
				if (rows[i][j].isBooked() && !rows[i][j].isBought())
					counter++;
			}
		}
		return counter;
	}
};
