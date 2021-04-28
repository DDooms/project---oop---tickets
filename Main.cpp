#include "Date.h"
#include "Vector.h"

int main() {
	Date d1(25, 4, 2021);
	Vector<Date> v1;
	Vector<Date> v2;
	v1.PushBack(d1);
	v1 = v2;
	std::cout << v1;

	return 0;
}