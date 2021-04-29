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
};