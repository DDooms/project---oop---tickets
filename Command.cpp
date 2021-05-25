#include "Command.h"

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
		std::cout << "Enter a filename. Note: it should end with .txt!\n";
		std::cin >> filename;
		size_t size = filename.getSize();
		while (filename[size - 4] != '.' || filename[size - 3] != 't' || filename[size - 2] != 'x' || filename[size - 1] != 't')
		{
			std::cout << "File name must end with .txt !\nEnter the filename again: ";
			filename = "";
			std::cin >> filename;
			size = filename.getSize();
		}
		/*if (filename[size - 4] != '.' || filename[size - 3] != 't' || filename[size - 2] != 'x' || filename[size - 1] != 't')
		{
			std::cout << "File name must end with .txt !\nEnter the filename again: ";
			return;
		}*/
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
		std::cout << "File not opened\n";
		return;
	}
	std::ofstream file(FileName.getString());
}


