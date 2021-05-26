#include "String.h"

void String::copy(const String& other) {
	size = other.size;
	capacity = other.capacity;
	string = new char[size + 1];
	strcpy_s(string, size + 1, other.string);
}

String::String(const char* other) {
	capacity = strlen(other) + 1;
	string = new char[capacity];
	strcpy_s(string, capacity, other);
	size = strlen(other);
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
String& String::operator=(const char* other)
{
	erase();
	capacity = strlen(other) + 1;
	string = new char[capacity];
	size = strlen(other);
	strcpy_s(string, capacity, other);
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

void String::print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << string[i];
	}
	std::cout << "\n";
}
const char String::operator[](size_t index) const{
	return string[index];
}
void String::tolower()
{
	for (int i = 0; i < size; i++) {
		if (string[i] >= 'A' && string[i] <= 'Z')
			string[i] = string[i] + ('a' - 'A');
	}
}
bool String::operator==(const String& _string) const
{
	return !strcmp(string, _string.string);
}
bool String::operator==(const char* _string) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (_string[i] != string[i])
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
String String::operator+(String& other)
{
	String temp;
	temp.copy(*this);
	for (size_t i = 0; i < other.size; ++i)
	{
		temp += other[i];
	}
	return temp;
}
String& String::operator+=(const char _element)
{
	if (this->size + 1 >= this->capacity)
	{
		this->resize();
	}
	string[size] = _element;
	size++;
	string[size] = '\0';
	return *this;
}

void String::removeLast()
{
	if (this->size >= 1)
	{
		this->size--;
		char* newString = new char[capacity];
		for (size_t i = 0; i < size; ++i)
		{
			newString[i] = string[i];
		}
		delete[] string;
		string = newString;
		string[size] = '\0';
	}
}

std::istream& operator>>(std::istream& in, String& _string)
{
	char element = ' ';
	while (element != '\n')
	{
		element = in.get();
		if (element != '\n')
			_string += element;
	}
	return in;
}
