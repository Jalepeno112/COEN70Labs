//COEN 70 LAB 1 PART 1 TUESDAY
//Created by Amy Truong and Giovanni Briggs on 06JAN14

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    
	string divider("+---+---+---+"); //declare a string for the repeated divder between each row
	string x_player("| X |");		//declare a string for the player using the X symbol
	string o_player("| O |");		//declare a string for the player using the O symbol


    //print the first divider
	cout << divider << '\n'										
		/*print the first X symbol followed by a set width of 4 of three spaces 
		and the '|' symbol to create an empty box, do this twice */
    	 << x_player << setw(4) << "|" << setw(4) << "|" << '\n' 
    	 //print another divider to seperate the next row
    	 << divider << '\n'						
    	 /* print the edge of the box, a set with of 8 to include three spaces for an empty box 
    	 and 5 spaces for the X symbol, followed by another set width of 4 to create another empty box 
    	 closed off with an edge, the '|' symbol*/
    	 << "|" << setw(8) << x_player << setw(4)<< "|" << '\n'
    	 //print another divider to seperate the next row
    	 << divider << '\n'		
    	 /* print the edge, followed by a set width of 4 to create an empty box, 
    	 	include another set width of 8 to create another empty box of 3 spaces 
    	 	and including 5 spaces for the O symbol*/				
    	 << "|" << setw(4) << "|" << setw(8) << o_player << '\n'
    	 //print the last divider to close the tic tac toe box
    	 << divider << endl;					
    
	return 0;
}