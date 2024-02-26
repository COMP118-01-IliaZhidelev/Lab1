#include <iostream>
#include <cassert>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

void drawHorizontalLine(const int length, const char ch);
void drawVerticalLine(const int height, const char ch);
void drawSquare(const int size , const char ch);
void drawRectangle(const int height, const int length, const char ch);

/*
* Example: #####
*/
void drawHorizontalLine(const int length, const char ch)
{
	assert(length > 0);
	std::cout << "I am drawHorizontalLine\n";
	std::string line(length, ch);
	std::cout << line << std::endl;
}
/*
* Example:
	#
	#
	#
	#
	#
*/
void drawVerticalLine(const int height, const char ch)
{
	assert(height> 0);
	std::cout << "I am drawVerticalLine\n";
	for (int i = 0; i < height; i++)
	{
		std::cout << ch << "\n";
	}
}
/*
* Example: #    #
*/
void drawLineEmpty(const int length,const char ch)
{
	std::stringstream ss;
	std::cout << ch;
	std::string whiteSpaces(length, ' ');
	ss << whiteSpaces;
	std::cout << ss.str();
	std::cout << ch;
	std::cout << std::endl;
}
/*
* Example: 
	######
	#    #
	#    #
	#    #
	#    #
	######
*/
void drawSquare(const int size,const  char ch)
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
/*
* Example:
	######
	#    #
	#    #
	######
*/
void drawRectangle(const int height,const  int length,const  char ch)
{
	assert(height> 0 && length > 0);
	std::cout << "I am drawRectangle\n";
	//first line
	std::string topLine(length, ch);
	std::cout << topLine << std::endl;

	for (int i = 0; i < height  -2 ; i++)
	{
		drawLineEmpty(length - 2, ch);
	}

	std::string bottomLine(length, ch);
	std::cout << bottomLine << std::endl;
}
/*
* returns int in range [downLimit, upLimit]
*/
int randomIntRange(const int downLimit, const int upLimit)
{
	
	int randomValue = downLimit + rand() % (upLimit - downLimit + 1);
	return randomValue;
}
/*
* returns random int 
*/
int randomInt(const int limit)
{
	
	int randomValue = rand() % limit;
	return randomValue;
}
/*
* draws random shapes
*/
void drawShapes(const int numShapes)
{
	const int MAX_SHAPES_AMOUNT = 10;
	std::stringstream ss;
	ss << "Cannot draw more than " << MAX_SHAPES_AMOUNT;
	assert(MAX_SHAPES_AMOUNT >= numShapes && ss.str().c_str());
	srand(time(NULL));
	for (int i = 0; i < numShapes; i++)
	{
		const int MAX_LENGTH = 6 - 1;
		auto shapeType = randomInt(4);
		char character = randomIntRange(33,126);
		// certainly not the best "robust" way to do it
		if (shapeType == 0)
		{
			auto length = randomInt(MAX_LENGTH);
			while (length == 0)
			{
				length = randomInt(MAX_LENGTH);
			}
			drawHorizontalLine(length, character);
		}
		else if (shapeType == 1)
		{
			auto height= randomInt(MAX_LENGTH);
			while (height == 0)
			{
				height = randomInt(MAX_LENGTH);
			}
			drawVerticalLine(height, character);
		}
		else if (shapeType == 2)
		{
			auto size = randomInt(MAX_LENGTH);
			while (size  <  2)
			{
				size = randomInt(MAX_LENGTH);
			}

			drawSquare(size, character);
		}
		else if (shapeType == 3)
		{
			auto width = randomInt(MAX_LENGTH);
			auto height = randomInt(MAX_LENGTH);
			while (width < 2 || height  < 2)
			{
				width = randomInt(MAX_LENGTH);
				height = randomInt(MAX_LENGTH);
			}
			drawRectangle(height,width, character);
		}
		else
		{
			assert(false && "Unknown type");
		}
	}


}
/*
* asks user for int input
*/
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
	std::cout << "5) Draw randoms\n";
	std::cout << "6) Quit\n";

	auto isRunning = true;
	while (isRunning)
	{
		int option = 0;
		std::cout << "Enter your Option:"; std::cin >> option;
		std::cout << std::endl;
		if (option == 1)
		{
			int length = getInt("Length:");
			drawHorizontalLine(length, '*');
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
		else if (option == 4)
		{
			int width = getInt("Width:");
			int length = getInt("Length:");
			drawRectangle(length, width, '*');
		}
		else if (option == 5)
		{
			int shapeAmount = getInt("Shapes amount:");
			drawShapes(shapeAmount);
		}
		else if (option == 6)
		{
			isRunning = false;
		}
		else
		{
			std::cout <<"could not parse input\n";
		}
	}
	



}