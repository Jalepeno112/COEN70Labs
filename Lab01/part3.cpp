//COEN 70 LAB 1 PART 3 TUESDAY
//Created by Amy Truong and Giovanni Briggs on 06JAN14

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc <1)
	{
		cout << "No file name given. Try again." << endl;
		return 1;
	}

	ifstream in_stream;
	ofstream out_stream;
    
    //declare an empty string next to store each word read from the input file
	string next;

	/* declare variable i for interation*/
	int i, alpha_count = 0;			

	in_stream.open(argv[1]); //open input file
	assert(in_stream);						//check for failure in opening the input file

	//traverse to the end of the input file
	while(in_stream >> next)
	{
		/*first check if the length of the word is at least 10 characters
		 and if it has exactly 10 characters, check if the last character is an alphabetical character*/
		if (next.length() >= 10)
		{
			/*second, check if there are at least 10 alphabetical characters
				even if there the string length is 10, the last character might be a symbol or number*/
			for(i=0; i<next.length(); i++)
			{
				if (isalpha(next[i]))
					alpha_count++;
			}
			/* if the string has at least 10 characters that are alphabetical,
				traverse through the word 
			 	capitalize and print any alphabetical character
			 	ignore symbols or numbers */
			if (alpha_count >= 10)
			{
				for(i=0; i<next.length(); i++)
				{
					if(isalpha(next[i]))
						putchar(toupper(next[i]));
				}
			}
			//print space to space the words apart
			cout << " ";
		}
		alpha_count = 0; //reset the count of alphabetical characters
        
	}

    
	in_stream.close();		  //close input file
}