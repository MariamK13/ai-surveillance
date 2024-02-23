#include <iostream>

class Shape{
public:
	virtual double area () = 0;
	virtual ~Shape () {}
};

class Circle: public Shape {
private:
	double r;

public:
	Circle (double newR) : r(newR) {} 
	double area () {
		return 3.14 * r * r;
	}
};

class Rectangle: public Shape {
private:
	double a;
	double b;

public:
	Rectangle (double width, double length) : a (width), b (length) {}
	double area () {
		return a * b;
	}
};

int main()
{
	Circle c (4);
	Rectangle r (4, 8);

	std::cout << "The area of the circle is: " << c.area () << std::endl;
	std::cout << "The area of the rectangle is: " << r.area () << std::endl;
}
