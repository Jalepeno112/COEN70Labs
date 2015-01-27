//COEN 70 LAB 1 PART 4 TUESDAY
//Created by Amy Truong and Giovanni Briggs on 06JAN14

#include <iostream>
using namespace std;

int main()
{
	struct object {
    	string* s;
	};
	object A, B;
	A.s = new string;
	B.s = new string;
	*A.s = "Hello World"; // A has "Hello World"

	/* Setting B = A makes the B string pointer always pointing to the A string pointer, 
		not the string *A.s is pointing to.
		By specifically setting the *B.s to equal *A.s, 
		the *B.s points to the string *A.s is pointing to, not *A.s itself. */

	*B.s = *A.s; // B has "Hello World" 			
	*A.s = "Goodbye"; // A has "Goodbye"
	cout << *A.s << endl;
	cout << *B.s << endl;
}