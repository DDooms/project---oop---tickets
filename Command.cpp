#include "Command.h"
#include "Ticket.h"

Command::Command() : isOpened(false), isSaved(false), isChanged(false), FileName("") {}

void Command::open()
{
	//note: this function does 4 things at the same time: open, save, saveAs, close
	if (isOpened)
	{
		std::cout << "Already opened\n";
		return;
	}
	else
	{
		String filename;
		std::cout << "Enter a path with a filename. Note: The filename should end with .txt!\n";
		std::cin >> filename;
		size_t size = filename.getSize();
		while (((filename[0] != 'C' && filename[0] != 'D') || filename[1] != ':' || filename[2] != '\\') && (filename[size - 4] != '.' || filename[size - 3] != 't' || filename[size - 2] != 'x' || filename[size - 1] != 't'))
		{
			std::cout << "It should be entered with the correct format disk like C or D and the filename should end with '.txt'\n";
			std::cout << "For example: C:\\Windows\\User\\file.txt\n";
			filename = "";
			std::cin >> filename;
			size = filename.getSize();
		}
		std::ofstream fileOf;
		fileOf.open(filename.getString());
		if (fileOf.fail())
		{
			std::cout << "File did not open...\n";
			return;
		}
		Event event;
		event.saveEvent(fileOf);
		fileOf.close();
		
		std::ifstream fileIf;
		fileIf.open(filename.getString());
		fileIf >> std::noskipws;
		char n;
		while (fileIf >> n)
		{
			
			std::cout << n;
		}

		FileName = filename;
		isOpened = true;
	}
}

void Command::close()
{
	if (!isOpened)
	{
		std::cout << "Open a file first...\n";
		return;
	}

	isOpened = false;

	std::cout << "Successfully closed " << FileName.getString() << std::endl;
	std::cout << std::endl;
}

void Command::save()
{
	if (!isOpened)
	{
		std::cout << "Open a file first...\n";
		return;
	}
	if (!isChanged)
	{
		std::cout << "No changes have been made!\n";
		return;
	}
	std::ofstream file(this->FileName.getString());
	Event event;
	event.saveEvent(file);
	std::cout << "Saved!\n";
	isChanged = false;
}

void Command::saveAs()
{
	if (!isOpened)
	{
		std::cout << "Open a file first...\n";
		return;
	}
}

void Command::help() const
{
	std::cout << "Available commands: " << std::endl;
	std::cout << "open                                 opens a file(this function does 4 things at the same time: open, save, saveAs, close)" << std::endl;
	std::cout << "close                                closes opened file" << std::endl;
	std::cout << "help                                 opens help menu" << std::endl;
	std::cout << "save                                 saves opened file" << std::endl;
	std::cout << "saveas                               saves other file" << std::endl;
	std::cout << "addevent                             adds an event" << std::endl;
	std::cout << "freeseats                            gives you info for the quantity of free seats in the hall" << std::endl;
	std::cout << "book                                 books an event" << std::endl;
	std::cout << "unbook                               unbooks an event" << std::endl;
	std::cout << "buy                                  buys a ticket" << std::endl;
	std::cout << "bookings                             gives you report of all the bookings" << std::endl;
	std::cout << "check                                checks if you have a valid seat with a ticket" << std::endl;
	std::cout << "report                               gives you a report for the bookings for a date interval" << std::endl;
}

void Command::run()
{
	std::cout << "Type 'help' for the commands\n";
	Ticket ticket;
	std::cout << "Please enter all dates in the format: YYYY-MM-DD" << std::endl;
	String command;
	while (true) {
		std::cout << "Enter a command: ";
		std::cin >> command;
		command.tolower();

		if (command == "addevent") {
			ticket.addEvent();
			std::cin.ignore();
		}
		else if (command == "freeseats") {
			ticket.freeSeats();
		}
		else if (command == "book") {
			ticket.book();
		}
		else if (command == "unbook") {
			ticket.unbook();
		}
		else if (command == "buy") {
			ticket.buy();
		}
		else if (command == "bookings") {
			ticket.bookings();
			std::cin.ignore();
		}
		else if (command == "check") {
			ticket.check();
		}
		else if (command == "report") {
			ticket.report();
		}
		else if (command == "open") {
			this->open();
		}
		else if (command == "save") {
			this->save();
		}
		else if (command == "saveas") {
			this->saveAs();
		}
		else if (command == "help") {
			this->help();
		}
		else if (command == "close") {
			this->close();
		}
		else if (command == "exit") {
			std::cout << "Exiting the program...\n";
			return;
		}
		command = "";
	}
}


