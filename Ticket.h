#pragma once
#include <iostream>
#include "String.h"
#include "Vector.h"
#include "Hall.h"
#include "Event.h"
#include "Date.h"

class Ticket {
	Vector<Hall> halls;
	Vector<Event> events;

	Event* findEvent(const String& name, const Date& date) {
		for (int i = 0; i < events.getSize(); ++i) {
			if (events[i].getName() == name && events[i].getDate() == date) {
				return &(events[i]);
			}
		}
		return nullptr;
	}

	void addEvent(size_t hallNum, const String& eventName, const Date& date) {
		//if (halls[hallNum].isBooked(date))
		//{
		//	std::cout << "Hall is booked\n";
		//}
		//else
		//{
			size_t rowNumbers = halls[hallNum].getRows();
			size_t colNumbers = halls[hallNum].getSeats();
			Event newEvent(eventName, rowNumbers, colNumbers, date, hallNum);
			events.PushBack(newEvent);
			halls[hallNum].book(date);
		//}
	}
	void freeSeats(const String& name, const Date& date) {
		Event* foundEvent = findEvent(name, date);
		if (foundEvent != nullptr)
			std::cout << foundEvent->getFreeSeats() << "\n";
		else std::cout << "Event not found\n";
	}
	void book(size_t rowNum, size_t seatNum, const Date& date, const String& name, const String& note) {
		Event* foundEvent = findEvent(name, date);
		if (foundEvent != nullptr)
		{
			if (foundEvent->isValid(rowNum, seatNum) && !foundEvent->isBooked(rowNum, seatNum))
				foundEvent->bookSeat(rowNum, seatNum, note);
			else std::cout << "Seat not available\n";
		}
		else std::cout << "Event not found\n";
	}
	void unbook(size_t rowNum, size_t seatNum, const Date& date, const String& name) {
		Event* foundEvent = findEvent(name, date);
		if (foundEvent != nullptr)
		{
			if (foundEvent->isValid(rowNum, seatNum) && foundEvent->isBooked(rowNum, seatNum))
				foundEvent->unBookSeat(rowNum, seatNum);
			else std::cout << "Seat not available\n";
		}
		else std::cout << "Event not found\n";
	}
	void buy(size_t rowNum, size_t seatNum, const Date& date, const String& name) {
		Event* foundEvent = findEvent(name, date);
		if (foundEvent != nullptr)
		{
			if (foundEvent->isValid(rowNum, seatNum) && foundEvent->isBooked(rowNum, seatNum))
				foundEvent->buyTicket(rowNum, seatNum, date);
			else std::cout << "Seat not available\n";
		}
		else std::cout << "Event not found\n";
	}
};