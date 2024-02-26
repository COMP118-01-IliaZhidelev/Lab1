#include <iostream>
#include <cassert>
#include <string>

void drawHorizontalLine(int length, char ch);
void drawVerticalLine(int height, char ch);
void drawSquare(int size , char ch);
void drawRectangle(int height, int length, char ch);


void drawHorizontalLine(int length, char ch)
{
	assert(length > 0);
	std::cout << "I am drawHorizontalLine\n";
	std::string line(length, ch);
	std::cout << line << std::endl;
}
void drawVerticalLine(int height, char ch)
{
	std::cout << "I am drawVerticalLine\n";
}
void drawSquare(int size, char ch)
{
	std::cout << "I am drawSquare\n";
}
void drawRectangle(int height, int length, char ch)
{
	std::cout << "I am drawRectangle\n";
}

int main()
{
	std::cout << "Hello, traveller!\n";

	std::cout << "1) Draw a horizontal line\n";
	std::cout << "2) Draw a vertical line\n";
	std::cout << "3) Draw a square\n";
	std::cout << "4) Draw a rectangle\n";
	std::cout << "5) Quit\n";

	int option = 0;
	std::cout << "Enter your Option:"; std::cin >> option;
	std::cout << std::endl;
	if (option == 1)
	{
		int length = 0;
		std::cout << "Length:";
		std::cin >> length;

		drawHorizontalLine(length,'*');
	}
	else
	{
		assert(false);
	}



}