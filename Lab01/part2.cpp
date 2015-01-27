//COEN 70 LAB 1 PART 2 TUESDAY
//Created by Amy Truong and Giovanni Briggs on 06JAN14
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	/*declare variable count to hold the count of alphabetical characters
		declare variable i to use for interation through the string */
	int count = 0, i; 
	string input; //create an empty string to hold the user's input string
    
	getline(cin, input); //ask for the user to input string and save entire string (including spaces) to input

    
    /*traverse to the end of the string
		if the character is not a space and is an alphabetical letter, increase count*/
    for (i=0; i<input.length(); i++)
    {

        if (isalnum(input[i]))
            ++count;
    }
    
    //print the input string and the number of alphabetical characters it has
	cout << '"' << input << '"' << " has " << count;
    cout << " alphanumeric characters."<< endl;
    
}