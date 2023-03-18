// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	elementNameBag = new Bag<std::string>;
	parseStack = new Stack<std::string>;
	successParse, successTokenize, elementsBagged = 0;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	clear();
	delete elementNameBag;
	delete parseStack;
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{

	clear();
	//helpung varaibles
	bool  onlySpace = 0,  Markup = 0;
	std::string helperString, tagVerify = "";
	std::string forbiddenTagChars = "!#$%&\'\"()*+,/;<=>?@[\\]^'{|}~.";
	std::string forbiddenToBegin = "1234567890.,-";
	StringTokenType helperToken;
	char readingChar;
	successTokenize = 0;
	
	
	
	//check if the input is only spaces, end lines, and tabs
	for (int a = 0; a < inputString.length(); a++){

		readingChar = inputString[a];
		if ((readingChar != '\n') && (readingChar != ' ') && (readingChar != '\t')){
			onlySpace = 1;
			break;
		}
	}




	//if input is only spaces or is an empty string, then return false
	if ((!onlySpace) || (inputString == "")){
		return false;
	}

    int i = 0;
	//loop through entire input string
	while (i < inputString.length()){
		
		
		readingChar = inputString[i];
		
		//start of markup
		if (readingChar == '<'){
			

			//get next char
			i++;
			readingChar = inputString[i];

			//read through markup
			while(readingChar != '>'){

				//return zero if there are nested chevrons
				if (readingChar == '<'){
					tokenizedInputVector.clear();
					return successTokenize;
				}
				//if valid, add to helper
				else{
					helperString.push_back(readingChar);
					i++;
					readingChar = inputString[i];
					
				}

			}


			//determine the type of tag, and erase extra elements
			//end tag
			if (helperString[0] == '/'){

				helperToken = END_TAG;
				helperString.erase(helperString.begin());	
			}

			//empty tage
			else if (helperString[helperString.length() - 1] == '/'){

				helperToken = EMPTY_TAG;
				helperString.erase(helperString.begin() + helperString.length() - 1);	
			}

			//possible declaration
			else if ((helperString[0] == '?') || (helperString[helperString.length() - 1] == '?')){
				
				//declarration
				if ((helperString[0] == '?') && (helperString[helperString.length() - 1] == '?')){
					helperToken = DECLARATION;
					helperString.erase(helperString.begin());
					helperString.erase(helperString.begin() + helperString.length() - 1);
				}
				else{
					tokenizedInputVector.clear();
					return successTokenize;
				}
			}

			//possible unecessary spaces, in that case return 0
			else if ((helperString[0] == ' ') || (helperString[helperString.length() - 1] == ' ')){
				tokenizedInputVector.clear();
				return successTokenize;	
			}

			//if nothing else, it must be start tag
			else{
				helperToken = START_TAG;
			}

			

			//get the possible tag
			for (int j = 0; j < helperString.length(); j++){

				readingChar = helperString[j];
					
				if ((readingChar != ' ')){
					tagVerify.push_back(readingChar);
				}
				else{
					break;
				}

			}

			

			//return 0 if initial conditions fail
			if (tagVerify == ""){
				tokenizedInputVector.clear();
				return successTokenize;
			}
			
			for (int j = 0; j < forbiddenToBegin.length(); j++){

				if (tagVerify[0] == forbiddenToBegin[j]){
					tokenizedInputVector.clear();
					return successTokenize;
				}
			}

			//return 0 if there are forbidden characters
			for (int j = 0; j < tagVerify.length(); j++){

				if (tagVerify[j] == '"'){
					tokenizedInputVector.clear();
					return successTokenize;
				}

				for (int h = 0; h < forbiddenTagChars.length(); h++){
						if (tagVerify[j] == forbiddenTagChars[h]){
						tokenizedInputVector.clear();
						return successTokenize;
					}
				}
			}


			//add to vector
			if (helperToken != DECLARATION){
				tokenizedInputVector.push_back(TokenStruct{helperToken, tagVerify});
			}
			else{
				tokenizedInputVector.push_back(TokenStruct{helperToken, helperString});
			}

			//increase i and reset helpders
			i++;
			helperString = "";
			tagVerify = "";

		}

		else if ((readingChar == ' ') || (readingChar == '\n') || (readingChar == '\t')){
			
			//if reading char is space, skip
			i++;
		}

		//if there is an unwarrented closed chevron, return false
		else if (readingChar == '>'){
			tokenizedInputVector.clear();
			return successTokenize;
		}

		//content
		else{

			//add the beggining contnet
			helperString.push_back(readingChar);
			i++;
			readingChar = inputString[i];

			//read through content
			while(readingChar != '<'){

				//add contnet
				helperString.push_back(readingChar);
				
				i++;
				readingChar = inputString[i];

			}


			helperToken = CONTENT;

			//add to vector
			tokenizedInputVector.push_back(TokenStruct{helperToken, helperString});

			//increase i and reset helpders
			helperString = "";

		}
	}


	successTokenize = 1;
	return successTokenize;

}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	//helper var
	TokenStruct tokenHelper;
	successParse = 0;
	std::string rootHolder, endRootHolder;
	
	
	//loop through token vector
	for (int i = 0; i < tokenizedInputVector.size() ; i++){

		tokenHelper = tokenizedInputVector[i];

		//if a start tag, add to stack
		if (tokenHelper.tokenType = START_TAG){

			parseStack->push(tokenHelper.tokenString);

		}

		//if end tag, look for corresponding start tag in stack, if not there, then return false
		else if (tokenHelper.tokenType = END_TAG){

			if(parseStack->isEmpty()){
				return successParse;
			}

			else if (parseStack->peek() == tokenHelper.tokenString){
				parseStack->pop();
			}
			else{
				return successParse;
			}
		}

	}

	
	for (int i = 0; i < tokenizedInputVector.size(); i++){

		if (tokenizedInputVector[i].tokenType == START_TAG){
			elementNameBag->add(tokenizedInputVector[i].tokenString);
		}

	}



	successParse = 1;
	return successParse;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear();
	parseStack->clear();
	tokenizedInputVector.clear();
	successParse, successTokenize, elementsBagged = 0;
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	
	bool continueOn = successTokenize && successParse;
	
	//throw exception if input has not been tokenized or parsed 
	if (!continueOn){
		throw(
			std::logic_error(
				"input string has not been successfully tokenized or parsed"
			)
		);
		
		return continueOn;
	}



	return elementNameBag->getFrequencyOf(inputString) > 0;

}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	bool continueOn = successTokenize && successParse;
	
	//throw exception if input has not been tokenized or parsed 
	if (!continueOn){
		throw(
			std::logic_error(
				"input string has not been successfully tokenized or parsed"
			)
		);
		
		return continueOn;
	}

			

	return elementNameBag->getFrequencyOf(inputString);
}

