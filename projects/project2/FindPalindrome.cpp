#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string &value)
{
	for (int i = 0; i < value.size(); i++)
	{
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
												  candidateStringVector,
											  vector<string> currentStringVector)
{

	//helper varaible
	std::string holderString;
	
	
	//check to see if we can stop branching 
	if (cutTest1(vectorOfStrings) && cutTest2(candidateStringVector, currentStringVector))
	{

		//base case: candidate string vector is full possible size
		if (candidateStringVector.size() == vectorOfStrings.size())
		{

			holderString = "";

			for (unsigned i = 0; i < candidateStringVector.size(); i ++){
				holderString += candidateStringVector[i];
			}


			if (isPalindrome(holderString))
			{
				vectorOfPalindromes.push_back(candidateStringVector);
			}
		}

		//non base case: candiadate vector has more space to fill, keep recursion going
		else
		{
			for (unsigned i = 0; i < currentStringVector.size(); i++)
			{

				std::vector<std::string> holderCandidate = candidateStringVector;
				std::vector<std::string> holderCurrent = currentStringVector;

				holderCandidate.push_back(holderCurrent[i]);
				holderCurrent.erase(holderCurrent.begin() + i);

				recursiveFindPalindromes(holderCandidate, holderCurrent);
			}
		}
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
}

FindPalindrome::~FindPalindrome()
{
}

int FindPalindrome::number() const
{
	return vectorOfPalindromes.size();
}

void FindPalindrome::clear()
{
	vectorOfStrings.clear();
	vectorOfPalindromes.clear();
}

bool FindPalindrome::cutTest1(const vector<string> &stringVector)
{

	//helper vars
	vector<char> prevChars;
	std::string totalString = "";
	int oddCounter = 0, duplicateCounter = 0;
	char comparingChar;
	bool keepGoing;

	//get vector in continuous string
	for (unsigned i = 0; i < stringVector.size(); i++)
	{
		totalString += stringVector[i];
	}

	convertToLowerCase(totalString);


	//checking for all evens and at most one odd
	for (unsigned i = 0; i < totalString.length(); i++)
	{

		comparingChar = totalString[i];


		//make sure we we havent checking this char before
		keepGoing = true;
		for (unsigned h = 0; h < prevChars.size(); h++)
		{
			if (comparingChar == prevChars[h])
			{
				keepGoing = false;
			}
		}

		//count for duplicates
		duplicateCounter = 0;

		if (keepGoing)
		{
			for (unsigned j = 0; j < totalString.length(); j++)
			{
				if (comparingChar == totalString[j])
				{
					duplicateCounter++;
				}
			}

			if (duplicateCounter % 2 == 1)
			{
				oddCounter++;
			}

			//add char to previous vector so we dont check for it again
			prevChars.push_back(comparingChar);
		}

	}

	//if there is more than one odd, return 0, otherwise, return 1
	if (oddCounter > 1)
	{
		return 0;
	}
	else{
		return 1;
	}

	
}

bool FindPalindrome::cutTest2(const vector<string> &stringVector1,
							  const vector<string> &stringVector2)
{

	//helper strings
	std::string stringHolder1 = "", stringHolder2 = "";

	//turn variables into continuous strings
	for (unsigned i = 0; i < stringVector1.size(); i++)
	{
		stringHolder1 += stringVector1[i];
	}

	for (unsigned i = 0; i < stringVector2.size(); i++)
	{
		stringHolder2 += stringVector2[i];
	}

	convertToLowerCase(stringHolder1);
	convertToLowerCase(stringHolder2);

	//make sure string two is the smaller one
	if (stringHolder1.length() < stringHolder2.length())
	{

		std::string swapper = stringHolder1;
		stringHolder1 = stringHolder2;
		stringHolder2 = swapper;
	}


	//see if all the characters in the smaller (stringHolder2) exist in the larger (stringHolder1)
	bool hasABrother;

	for (unsigned i = 0; i < stringHolder2.length(); i++)
	{

		hasABrother = 0;

		for (unsigned j = 0; j < stringHolder1.length(); j++)
		{
			if (stringHolder2[i] == stringHolder1[j])
			{
				hasABrother = 1;
			}
		}

		if (hasABrother == 0)
		{
			return 0;
		}
	}

	return 1;
}

bool FindPalindrome::add(const string &value)
{
	//get lowercase version
	std::string holderInputValue = value;
	convertToLowerCase(holderInputValue);

	//make sure the input has all letters
	for (unsigned i = 0; i < holderInputValue.length(); i++)
	{
		if (!isalpha(holderInputValue[i]))
		{
			return 0;
		}
	}

	//make sure the input does not currently exist in the instance
	for (unsigned i = 0; i < vectorOfStrings.size(); i++)
	{

		std::string holderVectorValue = vectorOfStrings[i];
		convertToLowerCase(holderVectorValue);

		if (holderVectorValue == holderInputValue)
		{
			return 0;
		}
	}

	//add input to instance
	vectorOfStrings.push_back(value);

	//calculate new set of palindromes
	vectorOfPalindromes.clear();
	vector<std::string> candidateVector;
	recursiveFindPalindromes(candidateVector, vectorOfStrings);

	return 1;
}

bool FindPalindrome::add(const vector<string> &stringVector)
{

	//helper vars
	std::string holderInputValue, holderVectorValue, checkWithinInput;
	int numElement;

	//go through ever wrod in the vector
	for (unsigned i = 0; i < stringVector.size(); i++)
	{

		holderInputValue = stringVector[i];
		convertToLowerCase(holderInputValue);

		//make sure every word in the input appears once
		numElement = 0;
		for (unsigned j = 0; j < stringVector.size(); j++){

			checkWithinInput = stringVector[j];
			convertToLowerCase(checkWithinInput);

			if (checkWithinInput == holderInputValue){
				numElement++;
			}

			if (numElement > 1){
				return 0;
			}

		}

		//make sure each word has only letters
		for (unsigned j = 0; j < holderInputValue.length(); j++)
		{
			if (!isalpha(holderInputValue[j]))
			{
				return 0;
			}
		}

		
		//make sure all words do not currently exist in the instance
		for (unsigned j = 0; j < vectorOfStrings.size(); j++)
		{

			holderVectorValue = vectorOfStrings[j];
			convertToLowerCase(holderVectorValue);

			if (holderVectorValue == holderInputValue)
			{
				return 0;
			}
		}
	}

	//add new vector to instance
	for (unsigned i = 0; i < stringVector.size(); i++)
	{
		vectorOfStrings.push_back(stringVector[i]);
	}

	//find all new plaindromes
	vectorOfPalindromes.clear();
	vector<std::string> candidateVector;
	recursiveFindPalindromes(candidateVector, vectorOfStrings);

	return 1;
}

vector<vector<string>> FindPalindrome::toVector() const
{
	return vectorOfPalindromes;
}
