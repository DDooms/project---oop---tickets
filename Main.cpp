#include "Command.h"
#include "Test.h"

int main() {
	runtests();
	/*String name = "EventName";
	Date date(2021, 10, 25);
	Event event(name, 10, 10, date, 1);
	std::ofstream fileOf;
	fileOf.open("file.txt");
	fileOf << event;
	fileOf.close();
	std::ifstream fileIf;
	fileIf.open("file.txt");
	fileIf >> std::noskipws;
	char n;
	while (fileIf >> n)
	{
		std::cout << n;
	}*/
	Command command;
	command.run();
	return 0;
}