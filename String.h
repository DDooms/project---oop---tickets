#pragma once
#include <iostream>
#include <cstring>

class String {
	char* string;
	size_t size;
	size_t capacity;
	void copy(const String& other);
	void copyTwo(const char* other);

	void erase();
	void resize();
public:
	String();
	String& operator=(const String& _String);
	friend std::ostream& operator<<(std::ostream& out, const String& current);
	String(const char* other);
	String(const String& _String);
	~String();

	const char* getString() const;
	size_t getSize() const;
	size_t getCapacity() const;
	void setString(const char* _string);
	void setSize(size_t _size);
	void setCapacity(size_t _capacity);
	void print();

	bool operator==(const String& _string);
	char operator[](size_t index);
};