#pragma once
#include "Seat.h"
#include "String.h"
#include "Row.h"
#include "Vector.h"

class Event {
	String name;
	Date date;
	Vector<Row> rows;
	size_t hallIndex;
};
