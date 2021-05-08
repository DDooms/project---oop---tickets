#pragma once
#include <iostream>

template<class T>
class Vector {
	T* vector;
	size_t size;
	size_t capacity;

	void Resize() {
		capacity *= 2;
		T* newDeck = new T[capacity];

		for (size_t i = 0; i < size; i++)
			newDeck[i] = vector[i];

		delete[] vector;
		vector = newDeck;
	}
public:
	Vector() {
		size = 0;
		capacity = 4;
		vector = new T[capacity];
	}
	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& current) {
		for (size_t i = 0; i < current.size; i++)
		{
			out << current.vector[i] << "\n";
		}
		return out;
	}
	void PushBack(const T& value) {
		if (size >= capacity)
			Resize();

		vector[size++] = value;
	}
	size_t getSize() const {
		return size;
	}
	size_t getCap() const {
		return capacity;
	}
	T& operator[](size_t index) const {
		return vector[index];
	}
	void PopBack() {
		if (size > 0)
			size--;
	}
	void copy(const Vector<T>& other) {
		vector = new T[other.capacity];
		size = other.size;
		capacity = other.capacity;
		for (size_t i = 0; i < size; i++)
		{
			vector[i] = other.vector[i];
		}
	}
	Vector<T>& operator=(const Vector<T>& other) {
		if (this != &other)
		{
			delete[] vector;
			this->copy(other);
		}
		return *this;
	}
	bool operator==(const Vector<T>& other) {
		for (size_t i = 0; i < size; i++)
		{
			if (vector[i] == other.vector[i])
				return true;
		}
		return false;
	}
	void print() const {
		for (size_t i = 0; i < size; i++)
		{
			std::cout << vector[i] << "\n";
		}
	}
};

