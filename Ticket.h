#pragma once
#include <iostream>
#include "Hall.h"
#include "Event.h"


class Ticket {
	Vector<Hall> halls;
	Vector<Event> events;
public:
	Event* findEvent(const String& name, const Date& date) {
		size_t size = events.getSize();
		//opravi size vuv for
		for (size_t i = 0; i < events.getCap(); ++i) {
			if (events[i].getName() == name && events[i].getDate() == date) {
				return &(events[i]);
			}
		}
		return nullptr;
	}

	void addEvent() {
		//cheti ot konzolata
		Date date;
		size_t hallNum;
		String eventName;
		std::cin >> date;
		std::cin >> hallNum;
		std::cin.ignore();
		std::cin >> eventName;
		if (halls[hallNum].isBooked(date))
		{
			std::cout << "Hall is booked\n";
		}
		else
		{
			/*size_t rows, cols;
			std::cout << "Enter rows: ";
			std::cin >> rows;
			std::cout << "Enter seats per row: ";
			std::cin >> cols;*/
			size_t rows = halls[hallNum].getRows();
			size_t cols = halls[hallNum].getSeats();
			Event newEvent(eventName, rows, cols, date, hallNum);
			events.PushBack(newEvent);
			halls[hallNum].book(date);
			}
	}
	void freeSeats() {
		Date date;
		size_t hallNum;
		String eventName;
		std::cin >> date;
		std::cin.ignore();
		std::cin >> eventName;
		Event* foundEvent = findEvent(eventName, date);
		if (foundEvent != nullptr)
			std::cout << foundEvent->getFreeSeats() << "\n";
		else std::cout << "Event not found\n";
	}
	void book() {
		Date date;
		size_t rowNum, seatNum;
		String eventName, note;
		std::cin >> date >> rowNum >> seatNum;
		std::cin.ignore();
		std::cin >> eventName >> note;
		Event* foundEvent = findEvent(eventName, date);
		if (!(foundEvent == nullptr))
		{
			if (foundEvent->isValid(rowNum, seatNum) && !foundEvent->isBooked(rowNum, seatNum))
				foundEvent->bookSeat(rowNum, seatNum, note);
			else std::cout << "Seat not available\n";
		}
		else std::cout << "Event not found\n";
	}
	void unbook() {
		Date date;
		size_t rowNum, seatNum;
		String eventName, note;
		std::cin >> date >> rowNum >> seatNum;
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
	void buy() {
		Date date;
		size_t rowNum, seatNum;
		String eventName, note;
		std::cin >> date >> rowNum >> seatNum;
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
	void bookings() {
			size_t size = events.getSize();
			for (size_t i = 0; i < size; ++i) {
				std::cout << events[i].getName() << ", " << events[i].getDate() << ": "
					<< events[i].getBookedButNotBoughtSeats() << std::endl;
			}
	}
	void check() {
		size_t serialNum;
		std::cin >> serialNum;
		size_t size = events.getSize();
		//opravi size vuv for
		for (size_t i = 0; i < events.getCap(); ++i) {
			size_t seatNum = events[i].getSeatNum(serialNum);
			if (seatNum != -1)
				std::cout << "Valid ticket with seat: " << seatNum;
			else std::cout << "Invalid ticket\n";
		}
	}
	void report() {
		Date dateFrom, dateTo;
		size_t hallNum;
		std::cin >> dateFrom >> dateTo >> hallNum;
		size_t size = events.getSize();
		//opravi size vuv for
		for (size_t i = 0; i < events.getCap(); ++i) {
			/*if (events[i] == events[i].getHallNum())
			{*/
				std::cout << events[i].getName() << ", " << events[i].getDate() << ": "
					<< events[i].getBoughtSeatsOnDateInterval(dateFrom, dateTo) << "\n";
			//}	
		}
	}
};