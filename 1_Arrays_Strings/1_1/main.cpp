#include <iostream>


bool isUniqueChars(std::string str)
{
	if(str.length() > 128) return false;
	
	bool charFlag[128] = {0};
	
	for(int i=0; i< str.length() ; i++)
	{
		if(charFlag[str[i]] == true) return false;
		
		charFlag[str[i]] = true;
	}
	
	return true;
}

//Assumption this will only have 32 bits which can be mapped. 
//Hence asusming string to comprize of lowercase a-z chars only!
//Note - This method does not use additional array. Instead use additional integer. 
bool isUniqueCharsUsingBitMapping(std::string str)
{
	//32-bi integet that will use each it as a flag;
	int myBitMap = 0;
	
	for(int i=0; i<str.length(); i++)
	{
		int bitAtIndex = str[i] - 'a'; //Using const here.
		
		//Check if bit is already set to true.
		if( myBitMap & (1<<bitAtIndex) ) return false;
		
		myBitMap = myBitMap | (1 << bitAtIndex);
		
	}
	
	return true;
	
}

int main()
{
	std::cout << "Hello World" << std::endl;
	std::string str = "abcdedg";
	
	std::cout << "Are all chars unique: " << isUniqueChars(str) << std::endl;
	
	std::cout << "Are all chars unique: " << isUniqueCharsUsingBitMapping(str) << std::endl;
	
	return 0;
}

//Notes: Time Complexity is O(n). 