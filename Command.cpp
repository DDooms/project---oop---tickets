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
		const char* filen = filename.getString();
		if ((filename[0] != 'C' && filename[0] != 'D') || filename[1] != ':' || filename[2] != '\\')
		{
			std::cout << "Please use the format DISK:\\PATH\\...\\filename.txt\n";
			return;
		}
		if (filename[size - 4] != '.' || filename[size - 3] != 't' || filename[size - 2] != 'x' || filename[size - 1] != 't')
		{
			std::cout << "File name must end with .txt !\n";
			return;
		}
		std::fstream file(filen);
		if (file.fail())
		{
			std::cout << "File did not open...\n";
		}
		FileName = filename;
		isOpened = true;
	}
}

