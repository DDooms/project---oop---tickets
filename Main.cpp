#include "Ticket.h"

int main() {
	//da si suzdam glaven class za faylove
	Date date(25, 04, 2021);
	String name = "pesho";
	String note = "ppp";
	Date date2(25, 10, 2021);
	String name2 = "sho";
	String note2 = "ppp";
	Ticket ticket;
	ticket.addEvent();
	ticket.bookings();


	/*Ticket ticket;
	ticket.addEvent();*/
	/*ticket.book(1, 1, date, name, note);
	ticket.bookings();*/
	return 0;
}