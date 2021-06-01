#include "Seat.h"

Seat::Seat() : rowNumber(0), seatNumber(0), booked(false), note(""), ticketNum(0) {}

Seat::Seat(size_t _rowNumber, size_t _seatNumber) : rowNumber(_rowNumber), seatNumber(_seatNumber), booked(false), note(""),ticketNum(0){}

String Seat::getNote() const
{
	return note;
}

void Seat::setNote(const String& _note)
{
	note = _note;
}

bool Seat::isBooked() const {
	return booked;
}

void Seat::book() {
	booked = true;
}

void Seat::unbook() {
	booked = false;
}

bool Seat::isBought() const {
	return ticketNum != 0;
}

void Seat::buy(const Date& date) {
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

size_t Seat::getTicketNum() const {
	return ticketNum;
}

bool Seat::isBoughtInDateInterval(const Date& dateFrom, const Date& dateTo) const {
	return buyingDate >= dateFrom && buyingDate <= dateTo;
}

size_t Seat::random() const
{
	srand(time(0));
	return rand() % 10000;
}

std::ostream& operator<<(std::ostream& out, const Seat& current)
{
	out << current.rowNumber << ": Row number\n";
	out << current.seatNumber << ": Seat number\n";
	out << current.booked << ": Check if its booked\n";
	out << current.note << ": Note\n";
	out << current.ticketNum << ": Ticket number\n";
	out << current.buyingDate << ": Buying date\n";
	return out;
}

std::istream& operator>>(std::istream& in, Seat& current)
{
	in >> current.rowNumber;
	in >> current.seatNumber;
	in >> current.booked;
	in >> current.note;
	in >> current.ticketNum;
	in >> current.buyingDate;
	return in;
}
