#include "Date.h"
#include "Vector.h"
#include "Seat.h"
#include "Event.h"

int main() {
	Date date(25, 04, 2021);
	Seat seat;
	seat.buy(date);
	Event event;
	event.getBookedSeats();


	return 0;
}