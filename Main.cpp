#include "Date.h"
#include "Vector.h"
#include "Seat.h"

int main() {
	Date date(25, 04, 2021);
	Seat seat;
	seat.buy(date);


	return 0;
}