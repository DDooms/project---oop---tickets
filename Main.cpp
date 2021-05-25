#include "Ticket.h"
#include "Command.h"

int main() {
	//da si suzdam glaven class za faylove
	Command command;
	command.open();
	Ticket ticket;
	ticket.run();
	command.save();

	


	/*Ticket ticket;
	ticket.addEvent();*/
	/*ticket.book(1, 1, date, name, note);
	ticket.bookings();*/
	return 0;
}