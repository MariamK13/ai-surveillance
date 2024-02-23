#include <iostream>
#include <stdexcept>

class Shape {
public:
	virtual double area () const = 0;
	virtual void exceptionHandling() const = 0;
	virtual ~Shape () {};
};

class Circle: public Shape {
private:
	double m_radius;

public:
	Circle(double r) : m_radius(r) {}
	double area() const override {
		exceptionHandling();
		return m_radius * m_radius * 3.14;
	}
	void exceptionHandling() const override {
		if (m_radius <= 0) {
			throw std::invalid_argument("Invalid argument");
		}
	}
};

class Rectangle: public Shape {
private:
	double m_length;
	double m_width;

public:
	Rectangle (double length, double width) : m_length(length), m_width(width) {}
	
	double area() const override {
		exceptionHandling();
		return m_length * m_width;
	}
	void exceptionHandling() const override {
		if (m_length <= 0 || m_width <= 0) {
		throw std::invalid_argument("Invalid argument");
		}
	}
};

int main()
{
	try {
		Circle c(6);
		Rectangle r(9, -1);
		std::cout << "Circle area: " << c.area() << std::endl;
		std::cout << "Rectangle area: " << r.area() << std::endl;
	} catch (const std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
