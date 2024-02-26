#include <iostream>

void drawHorizontalLine(int length, char ch);
void drawVerticalLine(int height, char ch);
void drawSquare(int size , char ch);
void drawRectangle(int height, int length, char ch);

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



}