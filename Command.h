#pragma once
#include "String.h"
#include <fstream>
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
	void saveAs(const String& filename);
	void help() const;
	void exit();
};

