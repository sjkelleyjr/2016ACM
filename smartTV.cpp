#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct coordinate
{
	int x;
	int y;
	
	void setValues(int a, int b)
	{
		x = a;
		y = b;
	}
};

int difference(char prevChar, char currChar, std::vector<coordinate> table)
{
	int xClicks = abs(table.at(prevChar-33).x - table.at(currChar-33).x);
	int yClicks = abs(table.at(prevChar-33).y - table.at(currChar-33).y);
	
	//std::cout << "totalclicks: " << xClicks + yClicks + 1 << std::endl;
	
	return xClicks + yClicks + 1;
}

int main()
{
	int xSize;
	int ySize;
	char input;
	
	//Setup the x and y values
	std::cin >> xSize;
	std::cin >> ySize;
	
	std::vector<coordinate> values(93);
	
	char firstCin;
	
	//Setup all the values for the remote controller
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			std::cin >> input;
			
			if (x == 0 && y == 0)
			{
				firstCin = input;
			}
			
			values.at(input - 33).setValues(x,y);
		}
	}
	
	string title;
	int titleCount;
	std::cin >> titleCount;
	cin.ignore();
	
	//std::cout << "titlecount: " << titleCount << std::endl;
	
	int buttonClicks;
	char prevChar = firstCin;
	
	//Get the button clicks from each title
	for (int i = 0; i < titleCount; i++)
	{
		buttonClicks = 0;
		prevChar = firstCin;
		getline(std::cin, title, '\n');

		for (int j = 0; j < (int)title.length(); j++)
		{
			buttonClicks += difference(prevChar, title[j], values);
			prevChar = title[j];
		}
		std::cout << buttonClicks;
		if (i != titleCount-1)
		{
			std::cout << std::endl;
		}
		
	}
}
