#pragma once
#include <iostream>
#include "Hall.h"
#include "Event.h"


class Ticket {
	Vector<Hall> halls;
	Vector<Event> events;
public:
	Event* findEvent(const String& name, const Date& date) {
		for (size_t i = 0; i < events.getCap(); ++i) {
			if (events[i].getName() == name && events[i].getDate() == date) {
				return &(events[i]);
			}
		}
		return nullptr;
	}

	void addEvent(size_t hallNum, const String& eventName, const Date& date) {
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
	void freeSeats(const String& name, const Date& date) {
		Event* foundEvent = findEvent(name, date);
		if (foundEvent != nullptr)
			std::cout << foundEvent->getFreeSeats() << "\n";
		else std::cout << "Event not found\n";
	}
	void book(size_t rowNum, size_t seatNum, const Date& date, const String& name, const String& note) {
		Event* foundEvent = findEvent(name, date);
		if (!(foundEvent == nullptr))
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
	void bookings() {
			size_t size = events.getSize();
			for (size_t i = 0; i < size; ++i) {
				std::cout << events[i].getName() << ", " << events[i].getDate() << ": "
					<< events[i].getBookedButNotBoughtSeats() << std::endl;
			}
		/*else {
			string temporary;
			cin >> temporary;

			if (cin.peek() == '\n') {
				if (isDate(temporary)) {
					for (int i = 0; i < events.size(); ++i) {
						if (events[i].get_date() == temporary) {
							cout << events[i].get_event_name() << ": "
								<< events[i].get_booked_seats_which_are_not_bought() << endl;
						}
					}
				}
				else {
					for (int i = 0; i < events.size(); ++i) {
						if (events[i].get_event_name() == temporary) {
							cout << events[i].get_date() << ": "
								<< events[i].get_booked_seats_which_are_not_bought() << endl;
						}
					}
				}
			}
			else {
				Date date(temporary);
				string event_name;
				cin >> event_name;

				Event* found_event = find_event(event_name, date);

				if (found_event != nullptr) {
					cout << found_event->get_booked_seats_which_are_not_bought() << endl;
				}
				else {
					cout << "Event not found" << endl;
				}
			}
		}*/
	}
	void check(size_t serialNum) {
		for (int i = 0; i < events.getCap(); ++i) {
			size_t seatNum = events[i].getSeatNum(serialNum);
			if (seatNum != -1)
				std::cout << "Valid ticket with seat: " << seatNum;
			else std::cout << "Invalid ticket\n";
		}
	}
	void report(const Date& dateFrom, const Date& dateTo, size_t hallNum) {
		for (int i = 0; i < events.getCap(); ++i) {
			if (!events[i].getHallNum() == hallNum) {
				std::cout << events[i].getName() << ", " << events[i].getDate() << ": "
					<< events[i].getBoughtSeatsOnDateInterval(dateFrom, dateTo) << "\n";
			}
		}
	}
};