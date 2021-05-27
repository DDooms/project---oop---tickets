#include "Ticket.h"
#include "Command.h"
#include "Test.h"

int main() {
	runtests();
	std::ifstream file("text.txt");
	Event event;
	event.loadEvent(file);
	std::cout << event.getDate() << "\n";
	std::cout << event.getAllSeats();
	return 0;
}