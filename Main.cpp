#include "Ticket.h"

int main() {
	Date date(25, 04, 2021);
	String name = "pesho";
	String note = "ppp";
	Date date2(25, 10, 2021);
	String name2 = "sho";
	String note2 = "ppp";


	Ticket ticket;
	ticket.addEvent(1, name, date);
	ticket.addEvent(1, name2, date);
	ticket.book(1, 1, date, name, note);
	//ticket.book(1, 3, date, name, note);
	//ticket.book(1, 4, date, name, note);
	//ticket.book(2, 2, date, name2, note2);
	ticket.report(date, date2, 1);
	//ticket.bookings();



	return 0;
}