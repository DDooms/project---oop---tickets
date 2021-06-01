#pragma once
#include "String.h"
#include <fstream>
#include "Ticket.h"
class Command
{
	bool isOpened;
	bool isSaved;
	bool isChanged;
	String FileName;
public:
	Command();
	void open();
	void close();
	void save();
	void saveAs();
	void help() const;
	void run();
};

