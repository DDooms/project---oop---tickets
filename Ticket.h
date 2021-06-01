#pragma once
#include <iostream>
#include "Hall.h"
#include "Event.h"
#include "InputHandler.h"

class Ticket {
	Vector<Hall> halls;
	Vector<Event> events;

	Event* findEvent(const String& name, const Date& date);
public:
	void addEvent();
	void freeSeats();
	void book();
	void unbook();
	void buy();
	void bookings();
	void check();
	void report();
};