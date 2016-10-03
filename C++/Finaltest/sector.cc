#include <iostream>
#define pi 3.1416

class Circle{

public:
    Circle(double r) : radius(r)
    {}
    double getArea() const{
    	return pi*radius*radius;
    }


private:
    double radius;

};

class Sector: public Circle{

public:
	Sector(double r, double a);
	double getArea() const{
		return Circle::getArea() * angle/360;
	}
private:
	double angle;
};

Sector::Sector(double r, double a): Circle(r), angle(a)
{}


int main(){
	Circle circle(5);
	Sector sector(5,50);
	double area1 = circle.getArea();
	double area = sector.getArea();
	std::cout << "Area of the circle is " << area1 << std::endl;
	std::cout << area << std::endl;
}
