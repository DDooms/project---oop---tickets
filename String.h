#pragma once
#include <iostream>
#include <cstring>

class String {
	char* string;
	size_t size;
	size_t capacity;
	void copy(const String& other);
	void erase();
	void resize();
public:
	String();
	String& operator=(const String& _String);
	String& operator=(const char*);
	friend std::ostream& operator<<(std::ostream& out, const String& current);
	friend std::istream& operator>>(std::istream& in, String& current);
	String(const char* other);
	String(const String& _String);
	~String();

	const char* getString() const;
	size_t getSize() const;
	size_t getCapacity() const;
	void print();
	void removeLast();

	String operator+(String&);
	String& operator+=(const char);
	bool operator==(const String& _string) const;
	bool operator==(const char*) const;
	const char operator[](size_t index) const;
};