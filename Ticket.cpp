#include "Ticket.h"

Event* Ticket::findEvent(const String& name, const Date& date) {
	size_t size = events.getSize();
	for (size_t i = 0; i < size; ++i) {
		if (events[i].getName() == name && events[i].getDate() == date) {
			return &(events[i]);
		}
	}
	return nullptr;
}


void Ticket::addEvent() {
	std::cout << "You are adding an event to the database\n";
	Date date;
	size_t hallNum;
	String eventName;
	do
	{
		std::cout << "Enter a correct date: ";
		std::cin >> date;
	} while (!date.isDateCorrect(date.getDays(), date.getMonths(), date.getYears()));
	std::cout << "Enter a hall number: ";
	std::cin >> hallNum;
	std::cin.ignore();
	std::cout << "Enter an event name: ";
	std::cin >> eventName;

	if (halls[hallNum].isBooked(date))
	{
		std::cout << "Hall is booked\n";
	}
	else
	{
		size_t rows, cols;
		std::cout << "Enter rows: ";
		std::cin >> rows;
		std::cout << "Enter seats per row: ";
		std::cin >> cols;
		Event newEvent(eventName, rows, cols, date, hallNum);
		events.PushBack(newEvent);
		halls[hallNum].book(date);
	}
}

void Ticket::freeSeats() {
	Date date;
	size_t hallNum;
	String eventName;
	do
	{
		std::cout << "Enter a correct date: ";
		std::cin >> date;
	} while (!date.isDateCorrect(date.getDays(), date.getMonths(), date.getYears()));
	std::cout << "Enter an event name: ";
	std::cin.ignore();
	std::cin >> eventName;
	Event* foundEvent = findEvent(eventName, date);
	if (foundEvent != nullptr)
		std::cout << foundEvent->getFreeSeats() << "\n";
	else std::cout << "Event not found\n";
}

void Ticket::book() {
	Date date;
	size_t rowNum, seatNum;
	String eventName, note;
	do
	{
		std::cout << "Enter a correct date: ";
		std::cin >> date;
	} while (!date.isDateCorrect(date.getDays(), date.getMonths(), date.getYears()));
	std::cout << "Enter a row, then a seat number : ";
	std::cin >> rowNum >> seatNum;
	std::cout << "Enter an event name: ";
	std::cin.ignore();
	std::cin >> eventName;
	std::cout << "Enter a note: ";
	std::cin.ignore();
	std::cin >> note;
	Event* foundEvent = findEvent(eventName, date);
	if (!(foundEvent == nullptr))
	{
		if (foundEvent->isValid(rowNum, seatNum) && !foundEvent->isBooked(rowNum, seatNum))
			foundEvent->bookSeat(rowNum, seatNum, note);
		else std::cout << "Seat not available\n";
	}
	else std::cout << "Event not found\n";
}

void Ticket::unbook() {
	Date date;
	size_t rowNum, seatNum;
	String eventName, note;
	do
	{
		std::cout << "Enter a correct date: ";
		std::cin >> date;
	} while (!date.isDateCorrect(date.getDays(), date.getMonths(), date.getYears()));
	std::cout << "Enter a row, then a seat number : ";
	std::cin >> rowNum >> seatNum;
	std::cout << "Enter an event name: ";
	std::cin.ignore();
	std::cin >> eventName;
	Event* foundEvent = findEvent(eventName, date);
	if (foundEvent != nullptr)
	{
		if (foundEvent->isValid(rowNum, seatNum) && foundEvent->isBooked(rowNum, seatNum))
			foundEvent->unBookSeat(rowNum, seatNum);
		else std::cout << "Seat not available\n";
	}
	else std::cout << "Event not found\n";
}

void Ticket::buy() {
	Date date;
	size_t rowNum, seatNum;
	String eventName;
	do
	{
		std::cout << "Enter a correct date: ";
		std::cin >> date;
	} while (!date.isDateCorrect(date.getDays(), date.getMonths(), date.getYears()));
	std::cout << "Enter a row, then a seat number : ";
	std::cin >> rowNum >> seatNum;
	std::cout << "Enter an event name: ";
	std::cin.ignore();
	std::cin >> eventName;
	Event* foundEvent = findEvent(eventName, date);
	if (foundEvent != nullptr)
	{
		if (foundEvent->isValid(rowNum, seatNum) && foundEvent->isBooked(rowNum, seatNum))
			foundEvent->buyTicket(rowNum, seatNum, date);
		else std::cout << "Seat not available\n";
	}
	else std::cout << "Event not found\n";
}

void Ticket::bookings() {
	size_t number;
	size_t size = events.getSize();
	if (size == 0)
	{
		std::cout << "No events booked\n";
		return;
	}
	Date tempDate;
	String tempName;
	std::cout << "If you want to see all bookings, type 1. If you want to see a show by its name, type 3 and enter the name\n"
		<< "If you want to see a show by the date, type 2, then enter the date\n";
	std::cout << "If you want to enter a name and a date, type 4, then enter\n";
	std::cin >> number;
	if (number == 1)
	{
		for (size_t i = 0; i < size; ++i) {
			std::cout << events[i].getName() << ", " << events[i].getDate() << ": "
				<< events[i].getBookedButNotBoughtSeats() << std::endl;
		}
	}
	else if (number == 2)
	{
		std::cout << "Enter a date: ";
		std::cin >> tempDate;
		for (size_t i = 0; i < size; ++i) {
			if (events[i].getDate() == tempDate)
				std::cout << events[i].getDate() << ": " << events[i].getBookedButNotBoughtSeats() << std::endl;
		}
	}
	else if (number == 3)
	{
		std::cout << "Enter a name: ";
		std::cin.ignore();
		std::cin >> tempName;
		for (size_t i = 0; i < size; ++i) {
			if (events[i].getName() == tempName)
				std::cout << events[i].getName() << ": " << events[i].getBookedButNotBoughtSeats() << std::endl;
		}
	}
	else if (number == 4)
	{
		std::cout << "Enter a date: ";
		std::cin >> tempDate;
		std::cin.ignore();
		std::cout << "Enter a name: ";
		std::cin >> tempName;

		Event* foundEvent = findEvent(tempName, tempDate);
		if (!(foundEvent == nullptr))
			std::cout << foundEvent->getBookedButNotBoughtSeats() << std::endl;
		else std::cout << "Event not found\n";
	}
	else std::cout << "Wrong input...\n"; return;
}

void Ticket::check() {
	size_t serialNum;
	std::cout << "Enter a serial number for the ticket: ";
	std::cin >> serialNum;
	size_t size = events.getSize();
	for (size_t i = 0; i < size; ++i) {
		size_t seatNum = events[i].getSeatNum(serialNum);
		if (seatNum != -1)
			std::cout << "Valid ticket with seat: " << seatNum;
		else std::cout << "Invalid ticket\n";
	}
}

void Ticket::report() {
	Date dateFrom, dateTo;
	size_t hallNum;
	bool weHaveHallNum = false;
	std::cout << "Please enter a timespan from date to date you want to check wether there are bookings or not.\n"
		<< "Note: If you want to check exact hall, after entering the second date, press space, then enter\n";
	do
	{
		std::cout << "Enter a date, from which you want to check. Note: the date must be correct:\n";
		std::cin >> dateFrom >> dateTo;
	} while (!dateFrom.isDateCorrect(dateFrom.getDays(), dateFrom.getMonths(), dateFrom.getYears()));
	do
	{
		std::cout << "Enter a date, to which you want to check. Note: the date must be correct:\n";
		std::cin >> dateTo;
	} while (!dateTo.isDateCorrect(dateTo.getDays(), dateTo.getMonths(), dateTo.getYears()));
	if (std::cin.peek() != '\n')
	{
		std::cout << "You want to check exact hall. Please enter a number: ";
		std::cin >> hallNum;
		weHaveHallNum = true;
	}
	size_t size = events.getSize();
	for (size_t i = 0; i < size; ++i) {
		if (!weHaveHallNum || events[i].getHallNum() == hallNum)
		{
			std::cout << events[i].getName() << ", " << events[i].getDate() << ": "
				<< events[i].getBoughtSeatsOnDateInterval(dateFrom, dateTo) << "\n";
		}
	}
}
