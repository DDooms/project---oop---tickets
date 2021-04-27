#include "Date.h"
#include "Vector.h"

int main() {
	Date d1(25, 4, 2022);
	std::cout << std::endl;
	d1.print();
	Vector<Date> v1;
	Vector<Date> v2;
	v1 = v2;
	v1.PushBack(d1);
	std::cout << v1;
	v1.print();

	return 0;
}