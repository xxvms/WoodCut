// WoodCut.cpp : Defines the entry point for the console application.
//
/*
	multiple inheritance with English distance


*/

#include "stdafx.h"
#include <iostream>
#include <string>

class Type				// type of lumber wood
{
private: 
	std::string dimension;
	std::string grade;
public:
	Type() : dimension("N/A"), grade("N/A") // no argument constructor
	{}
	Type(std::string dimension_, std::string grade_) : dimension(dimension_), grade(grade_) // 2 argument constructor
	{}
	void getType()							// get type from user
	{
		std::cout << "\nEnter nominal dimensions (2x4, etc.): ";
		std::cin >> dimension;
		std::cout << "\nEnter grade: ";
		std::cin >> grade;
	}
	void showType() const					// show type
	{
		std::cout << "\nDimension: " << dimension;
		std::cout << "\nGrade: " << grade;
	}
};

class Distance							// English distance Class
{
private:
	int feet;
	double inches;
public:
	Distance() : feet(0), inches(0.0) // no argument constructor
	{}
	Distance(int feet_, double inches_) : feet(feet_), inches(inches_) // 2 arguments constructor
	{}
	void getDistance()				// get distance from user
	{
		std::cout << "\nEnter feet: ";
		std::cin >> feet;
		std::cout << "\nEnter inches: ";
		std::cin >> inches;
	}
	void schowDistance() const		// display distance
	{
		std::cout << feet << "\'- " << inches << "\"";
	}
};

class Lumber : public Type, public Distance
{
private:
	int quantity;				// number of pieces of wood
	double price;				// price of each piece
public:
	Lumber() : Type(), Distance(), quantity(0), price(0.0) // constructor NO arguments
	{}
	// 6 argument constructor
	Lumber(std::string dimention_, std::string grade_,	// arguments for Type
		int feet_, double inches_,						// arguments for Distance 
		int quantity_, double price_) :					// arguments for Lumber (this class data)
		Type(dimention_, grade_),						// call Type constructor
		Distance(feet_, inches_),						// call Distance constructor
		quantity(quantity_), price(price_)				// initilalize data for Lumber class
	{}

	void getLumber()
	{
		Type::getType();
		Distance::getDistance();
		std::cout << "Enter quantity: ";
		std::cin >> quantity;
		std::cout << "Enter price per piece: ";
		std::cin >> price;
	}

	void showLumber() const
	{
		Type::showType();
		std::cout << "\nLenght: ";
		Distance::schowDistance();
		std::cout << "\nPrice for " << quantity << " pieces: $" << price * quantity;
	}
};

int main()
{
	Lumber siding;					// creating object type Lumber through constructor no arguments

	std::cout << "\nSiding data:\n";
	siding.getLumber();				// get siding from user

	Lumber studs("2x4", "const", 8, 0.0, 200, 4.45); // constructor with 6 arguments

	// display data for Lumber class
	std::cout << "\nSiding";
	siding.showLumber();
	std::cout << "\nStuds";
	studs.showLumber();

	std::cout << std::endl;

	system("pause");
    return 0;
}

