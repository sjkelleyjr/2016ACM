#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

	int roll;
	unsigned int rollSize;
	
	std::cin >> rollSize;
	
	for (unsigned int i = 0; i < rollSize; i++)
	{
		std::cin >> roll;
		
		if (roll == 1)
		{
			std::cout << "CRITICAL MISS" << std::endl;
		}
		else if (roll == 20)
		{
			std::cout << "CRITICAL HIT" << std::endl;
		}
		else
		{
			std::cout << roll << std::endl;
		}
	}

}
