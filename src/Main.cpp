/** \file Main.cpp
* \brief It draws shapes such as rectangles,
	horizontal or vertical lines, squares on terminal.
* \details User is prompted to choose shape, its parametrs, symbol of drawing.
* \author Ilia Zhidelev
* \version 0.1
* \date 04.03.2024
* \copyright GNU Public License.
*/
#include <iostream>
#include <cassert>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <sstream>







/**
* draws a horizontal line with a specified character
\verbatim
 Example: #####
\endverbatim
* @param length: how long line is 
* @param ch: a specified character
*/
void drawHorizontalLine(const int length, const char ch);
/**
* draws a horizontal line with a specified character
\verbatim
 Example:
	#
	#
	#
	#
	#
\endverbatim
* @param length: how long line is
* @param ch: a specified character
*/
void drawVerticalLine(const int height, const char ch);


/**
* draws a square with a specified character
\verbatim
 Example:
	####
	#  #
	#  #
	####
\endverbatim
* @param size: width and height of a square 
* @param ch: a specified character
*/
void drawSquare(const int size , const char ch);
/**
* draws a square with a specified character
\verbatim
 Example:
	#########
	#		#
	#		#
	#########
\endverbatim
* @param height: how tall a rectangle is 
* @param length: how wide a rectangle is 
* @param ch: a specified character
*/
void drawRectangle(const int height, const int length, const char ch);


void drawHorizontalLine(const int length, const char ch)
{
	assert(length > 0);
	std::cout << "I am drawHorizontalLine\n";
	std::string line(length, ch);
	std::cout << line << std::endl;
}

void drawVerticalLine(const int height, const char ch)
{
	assert(height> 0);
	std::cout << "I am drawVerticalLine\n";
	for (int i = 0; i < height; i++)
	{
		std::cout << ch << "\n";
	}
}

/**
* draws an empty line with a specified character
\verbatim
 Example: #    #
\endverbatim
* @param length: how long a line is 
* @param ch: a specified character
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
/**
* returns int in range [downLimit, upLimit]
* @param downLimit: start of range included
* @param upLimit: end of range included
* @return returns a random int in specified range
*/
int randomIntRange(const int downLimit, const int upLimit)
{
	int randomValue = downLimit + rand() % (upLimit - downLimit + 1);
	return randomValue;
}
int randomInt(const int limit)
{
	
	int randomValue = rand() % limit;
	return randomValue;
}




/**
* draws random shapers with random parameters, uses draw functions to draw shapes
* @param numShapes: amount of shapes to draw
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
/**
* draws random shapers with random parameters, uses draw functions to draw shapes.
* it doesn't validate input
* @param userPrompt: a prompt hint for a user
* @return an integer user is prompted
*/
int getInt(const char* userPrompt)
{
	int number= 0;
	std::cout << userPrompt;
	std::cin >> number;
	return number;
}


/**
* Fills array shapeTy with values 1 - 3, to indicate which shape type to print
* Fills array shapeLen with values 1 - 20, the length of the shape
* Fills array shapeCh with values from the printable ASCII table, i.e. 33 - 126
* @param shapeTy: a type of shape
* @param shapeLen: length of shape to be drawn
* @param shapeCh: character that will be drawn
* @param arrSuze: the length of parameters
*/
void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		shapeTy[i] = randomIntRange(1,3);
		shapeLen[i] = randomIntRange(1, 20);
		shapeCh[i] = randomIntRange(33, 126);
	}
}


/**
* 
* Loops and prints all the shapes that are specified in the arrays	
* initializeArrays must be called prior to this function
* @param shapeTy: a type of shape
* @param shapeLen: length of shape to be drawn
* @param shapeCh: character that will be drawn
* @param arrSuze: the length of parameters
*/

void drawArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		auto option = shapeTy[i];
		auto ch = shapeCh[i];
		if (option == 1)
		{
			int length = shapeLen[i];
			drawHorizontalLine(length, ch);
		}
		else if (option == 2)
		{
			int height = shapeLen[i];
			drawVerticalLine(height, ch);
		}
		else if (option == 3)
		{
			int size = shapeLen[i];
			drawSquare(size, ch);
		}

	}
}


// entry point
int main()
{

	const int MAX_ARRAY = 10;
	int shapeTy[MAX_ARRAY];
	int shapeLen[MAX_ARRAY];
	char shapeCh[MAX_ARRAY];
	initializeArrays(shapeTy,shapeLen,shapeCh,MAX_ARRAY);

	std::cout << "Hello, traveller!\n";
	std::cout << "1) Draw a horizontal line\n";
	std::cout << "2) Draw a vertical line\n";
	std::cout << "3) Draw a square\n";
	std::cout << "4) Draw a rectangle\n";
	std::cout << "5) Draw randoms\n";
	std::cout << "6) Draw 10 random shapes with random character\n";
	std::cout << "7) Quit\n";

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
			drawArrays( shapeTy,shapeLen, shapeCh, MAX_ARRAY);
		}
		else if (option == 7)
		{
			isRunning = false;
		}
		else
		{
			std::cout <<"could not parse input\n";
		}
	}
	



}