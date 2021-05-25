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
		return rand() % 10000;
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
			Vector<int> ticketNumCheck;
			//proverka za razlichni nomera
			ticketNumCheck.PushBack(50000);
			book();
			size_t size = ticketNumCheck.getSize();
			ticketNum = (rowNumber * 100 + seatNumber) * 10000 + random();
			for (size_t i = 0; i < size; i++)
			{
				if (ticketNumCheck[i] == ticketNum)
				{
					ticketNum = (rowNumber * 100 + seatNumber) * 10000 + random();
					continue;
				}
			}
			ticketNumCheck.PushBack(ticketNum);
			buyingDate = date;
			std::cout << ticketNum;
		}
	}
	size_t getTicketNum() const {
		return ticketNum;
	}
	bool isBoughtInDateInterval(const Date& dateFrom, const Date& dateTo) const {
		return buyingDate >= dateFrom && buyingDate <= dateTo;
	}
	friend std::ostream& operator<<(std::ostream& out, const Seat& current) {
		out << current.rowNumber;
		out << current.seatNumber;
		out << current.booked;
		out << current.note;
		out << current.ticketNum;
		out << current.buyingDate;
		return out;
	}
};