#include "Event.h"

Event::Event() : hallNum(0) {}

Event::Event(const String& _name, size_t rowNumbers, size_t colNumbers, const Date& _date, size_t _hallNum) : name(_name), date(_date), hallNum(_hallNum) {
	for (size_t i = 0; i < rowNumbers; i++)
	{
		Row newRow(i, colNumbers);
		rows.PushBack(newRow);
	}
}

String Event::getName() const {
	return name;
}

size_t Event::getHallNum() const {
	return hallNum;
}

size_t Event::getColNumber() const {
	return rows[0].getSize();
}

size_t Event::getAllSeats() const {
	return rows.getSize() * getColNumber();
}

size_t Event::getBookedSeats() const {
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
	return 0;
}

size_t Event::getSeatNum(size_t number) {
	size_t size = rows.getSize();
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < rows[i].getSize(); j++)
		{
			if (rows[i][j].getTicketNum() == number)
			{
				return j;
			}
		}
	}
	return -1;
}

size_t Event::getFreeSeats() const {
	return getAllSeats() - getBookedSeats();
}

Date Event::getDate() const {
	return date;
}

bool Event::isValid(size_t rowNumber, size_t seatNumber) const {
	return rowNumber > 0 && rowNumber < rows.getSize() && seatNumber > 0 && seatNumber < getColNumber();
}

bool Event::isBooked(size_t rowNumber, size_t seatNumber) const {
	return rows[rowNumber][seatNumber].isBooked();
}

void Event::bookSeat(size_t rowNumber, size_t seatNumber, const String& note) {
	if (!isBooked(rowNumber, seatNumber)) {
		rows[rowNumber][seatNumber].book();
		rows[rowNumber][seatNumber].setNote(note);
	}
}

void Event::unBookSeat(size_t rowNumber, size_t seatNumber) {
	if (isBooked(rowNumber, seatNumber)) {
		rows[rowNumber][seatNumber].unbook();
		rows[rowNumber][seatNumber].setNote("");
	}
}

void Event::buyTicket(size_t rowNumber, size_t seatNumber, const Date& date) {
	if (!isBooked(rowNumber, seatNumber))
		rows[rowNumber][seatNumber].buy(date);
}

size_t Event::getBookedButNotBoughtSeats() const {
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

size_t Event::getBoughtSeatsOnDateInterval(const Date& dateFrom, const Date& dateTo) const {
	int counter = 0;
	for (size_t i = 0; i < rows.getSize(); ++i) {
		for (size_t j = 0; j < rows[i].getSize(); ++j) {
			if (rows[i][j].isBoughtInDateInterval(dateFrom, dateTo)) {
				++counter;
			}
		}
	}
	return counter;
}

void Event::saveEvent(std::ostream& file)
{							   
	file << name << ": Default name\n";
	file << date << ": Default date\n";
	file << rows << ": Default hall\n";
	file << hallNum << ": Default hall number\n";						   											   
}

void Event::loadEvent(std::istream& file)
{
	file >> name;
	if (name == "\n")
	{
		file >> name;
	}
	file >> date;
	file >> rows;
	file >> hallNum;
}
														   
std::ostream& operator<<(std::ostream& out, const Event& current) {
	size_t size = current.rows.getSize();
	out << size << "\n";
	out << current.name << "\n";
	out << current.date << "\n";
	for (size_t i = 0; i < size; i++)
	{
		out << current.rows[i] << "\n";
	}
	out << current.hallNum << "\n";
	return out;
}
std::istream& operator>>(std::istream& in, Event& current) {
	size_t size = current.rows.getSize();
	in >> size;
	in >> current.name;
	in >> current.date;
	for (size_t i = 0; i < size; i++)
	{
		in >> current.rows[i];
	}
	in >> current.hallNum;
	return in;
}