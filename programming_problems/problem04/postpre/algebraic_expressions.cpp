#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {


  //only convert if the postfix is valid
  if (isPost(postfix)){

    //variables for later use
    int postLength = postfix.size();
    char ch = postfix[postLength - 1];


    //if the last character is not an operator, simply attach it to the begining of the prefix
    if (!isoperator(ch)){
      prefix = ch + prefix;
    }

    //if the last character is an operator
    else{

      //find the separating point between the inner expressions
      int beginPost = endPost(postfix, postLength - 2);

      //get the inner expressions
      std::string holderFirst, holderSecond = "";

      for(unsigned i = beginPost; i < postLength - 1; i++){
        holderFirst += postfix[i];
      }

      for(unsigned i = 0; i < beginPost; i++){
        holderSecond += postfix[i];
      }

      
      //fidn the prefix versions of the inner expression recursively
      std::string prefix1, prefix2;

      convert(holderFirst, prefix1);
      convert(holderSecond, prefix2);


      //assemble the prefix expression
      prefix = ch + prefix2 + prefix1 + prefix;

      

    }

  }


  
}
