#pragma once
#include "Date.h"
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

	size_t random() {
		srand(time(0));
		return rand() % 100;
	}
public:
	Seat() : rowNumber(0), seatNumber(0), booked(false), note(""),ticketNum(0){}
	Seat(size_t _rowNumber, size_t _seatNumber) : rowNumber(_rowNumber), seatNumber(_seatNumber), booked(false), note(""),ticketNum(0){}
	String getNote() const {
		return note;
	}
	void setNote(const String& _note) {
		note = _note;
	}
	bool isBooked() const {
		return booked;
	}
	void book() {
		booked = true;
	}
	void unbook() {
		booked = false;
	}
	bool isBought() const {
		return ticketNum != 0;
	}
	void buy(const Date& date) {
		if (!isBought())
		{
			book();
			ticketNum = (rowNumber * 100 + seatNumber) * 100 + random();
			buyingDate = date;
			std::cout << ticketNum;
		}
	}
	size_t getTicketNum() const {
		return ticketNum;
	}
};