#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  bool hasUpper = false;
  bool hasLower = false;

  for(unsigned char ch : pass)
  {
	  if(std::isupper(ch))
	  {
		  hasUpper = true;
	  }
	  else if(std::islower(ch))
	  {
		  hasLower = true;
	  }

	  if(hasUpper && hasLower)
	  {
		  return true;
	  }
  }

  return false;
}
