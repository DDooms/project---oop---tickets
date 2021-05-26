#include "Command.h"
#include "Ticket.h"

Command::Command() : isOpened(false), isSaved(false), isChanged(false), FileName("") {}

void Command::open()
{
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
		std::ofstream file;
		file.open(filename.getString());
		if (file.fail())
		{
			std::cout << "File did not open...\n";
			return;
		}
		FileName = filename;
		isOpened = true;
	}
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
	Ticket ticket;
	//ticket.addEvent(file);
	std::cout << "Saved!\n";
	isChanged = false;
}


