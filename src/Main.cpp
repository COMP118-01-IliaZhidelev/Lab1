#include <iostream>
#include <cassert>
#include <sstream>

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
	assert(height> 0);
	std::cout << "I am drawVerticalLine\n";
	for (int i = 0; i < height; i++)
	{
		std::cout << ch << "\n";
	}
}
// example: *             *
void drawLineEmpty(int length,char ch)
{
	std::stringstream ss;
	std::cout << ch;
	std::string whiteSpaces(length, ' ');
	ss << whiteSpaces;
	std::cout << ss.str();
	std::cout << ch;
	std::cout << std::endl;
}
void drawSquare(int size, char ch)
{
	assert(size> 0);
	std::cout << "I am drawSquare\n";

	//first line
	std::string topLine(size, ch);
	std::cout << topLine << std::endl;
	
	for (int i = 0; i < size-2; i++)
	{
		drawLineEmpty(size - 2, ch);
	}

	// last line

	std::string bottomLine(size, ch);
	std::cout << bottomLine << std::endl;



}
void drawRectangle(int height, int length, char ch)
{
	std::cout << "I am drawRectangle\n";
}


int getInt(const char* userPrompt)
{
	int number= 0;
	std::cout << userPrompt;
	std::cin >> number;
	return number;
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
		int length  = getInt("Length:");
		drawHorizontalLine(length,'*');
	}
	else if (option == 2)
	{
		int height = getInt("Height:");
		drawVerticalLine(height, '*');
	}
	else if (option == 3)
	{
		int size = getInt("Size:");
		drawSquare(size, '*');
	}
	else
	{
		assert(false && "could not parse input");
	}



}