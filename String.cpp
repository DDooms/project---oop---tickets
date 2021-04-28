#include "String.h"

void String::copy(const String& other) {
	size = other.size;
	capacity = other.capacity;
	string = new char[size + 1];
	strcpy_s(string, size + 1, other.string);
}
void String::copyTwo(const char* other)
{
	capacity = strlen(other) + 1;
	string = new char[capacity];
	strcpy_s(string, capacity, other);
	size = strlen(other);
}
String::String(const char* other) {
	copyTwo(other);
}
void String::erase()
{
	delete[] string;
}

void String::resize()
{
	capacity *= 2;
	char* newCap = new char[capacity];
	for (size_t i = 0; i < size; i++)
		newCap[i] = string[i];
	delete[] string;
	string = newCap;
}

String::String()
{
	size = 0;
	capacity = 10;
	string = new char[capacity];
	string[0] = '\0';
};
String& String::operator=(const String& other) {
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
String::String(const String& other) {
	copy(other);
}
String::~String() {
	erase();
}

const char* String::getString() const
{
	return string;
}

size_t String::getSize() const
{
	return size;
}

size_t String::getCapacity() const
{
	return capacity;
}

void String::setString(const char* _string)
{
	delete[] string;
	string = new char[strlen(_string) + 1];
	strcpy_s(string, strlen(_string) + 1, _string);
}

void String::setSize(size_t _size)
{
	size = _size;
}

void String::setCapacity(size_t _capacity)
{
	capacity = _capacity;
}
void String::print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << string[i];
	}
	std::cout << "\n";
}
char String::operator[](size_t index) {
	if (index >= size - 1)
	{
		std::cout << "Index too big!" << std::endl;
		return 0;
	}
	return string[index];
}
bool String::operator==(const String& _string)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (string[i] != _string.string[i])
		{
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, const String& current)
{
	for (size_t i = 0; i < current.size; i++)
	{
		out << current.string[i];
	}
	return out;
}
