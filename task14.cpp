#include <iostream>

class Shape {
public:
	virtual double area () = 0;
	virtual ~Shape () {}
};

class Circle: public Shape {
private:
	double r;

public:
	Circle (double newR) : r(newR) {}
	double area() {
		return 3.14 * r * r;
	}
};

class Rectangle: public Shape {
private:
	double width;
	double length;

public:
	Rectangle (double w, double l) : width(w), length(l) {}
	double area () {
		return width * length;
	}
};

void printArea (Shape* sh)
{
	std::cout << sh -> area() << std::endl;
}

int main ()
{
	Circle c (8);
	Rectangle r (7, 9);

	std::cout << "Circle area: ";
	printArea (&c);
	std::cout << "Rectangle area: ";
	printArea (&r);
}
