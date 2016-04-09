#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	//Offset of 98 => 
	
	
	std::vector<int> firstString;
	std::vector<int> secondString;
	
	for (int i = 0; i < 26; i++)
	{
		firstString.push_back(0);
		secondString.push_back(0);
	}
	
	std::string lineOne; // = "i was lord voldemort";
	std::string lineTwo; //= "tom marvolo riddle";
	
	getline(cin, lineOne, '\n');
	getline(cin, lineTwo, '\n');

	
	
	for (int i = 0; i < (int)lineOne.length(); i++)
	{
		if (lineOne[i] - 98 < 0 || lineOne[i] - 98 > 25)
		{
			//nothing
		}
		else
		{
			//std::cout << lineOne[i] - 98 << std::endl;
			firstString.at(lineOne[i] - 98) += 1;
		}
	}
	
	std::cout << std::endl;
	
	for (int i = 0; i < (int)lineTwo.length(); i++)
	{
		if (lineTwo[i] - 98 < 0 || lineTwo[i] - 98 > 25)
		{
			//nothing
		}
		else
		{
			//std::cout << lineTwo[i] - 98 << std::endl;
			secondString.at(lineTwo[i] - 98) += 1;
		}
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (firstString.at(i) == secondString.at(i))
		{
			//GOOD
		}
		else
		{
			std::cout << "NO" << std::endl;
			return 0;
		}
	}
	
	std::cout << "YES" << std::endl;
} 
