/*
 * Name:    Giovanni Briggs and Reed Conway
 * Date:    1/28/14
 * Class:   COEN 70L Tuesday 2:15pm
 * Lab:     04
 */
#include "list.h"
#include <stdlib.h>

using namespace std;
double parse(string s);
int main() {
    int counter = 0;
    while (counter < 10) {
        /*get user input*/
        cout <<"Enter postfix argument: " <<endl;
        string input;
        getline(cin, input);
        /*parse the string and get an answer*/
        double answer = parse(input);
        cout << "Answer: " << answer <<endl;
        counter++;
    }
    return 0;
}

double parse(string s) {
    /*create empty stack*/
    List stack;
    /*
     * While the string is not empty
     * go through the string
     * find doubles and push to stack
     * find operator
     * pop off stack
     * do operation
     * push back on stack
     */
    while (!s.empty()) {
        /*get position of first space*/
        int firstSpace = s.find(' ');
        string sub;
        
        /*if it equals -1, then there are no more spaces, but still 1 term*/
        if(firstSpace == -1) {
            sub = s;
            //make s empty
            s="";
        }
        else {
            /*take the characters from 0 to the first space and put them in a substring*/
            sub = s.substr(0,firstSpace);
            /*get rid of everything before first space*/
            s = s.substr(firstSpace+1);
        }//end else
        
        /*check if operator*/
        if(sub == "+"|| sub=="-"||sub=="*"||sub=="/") {
            double argument1, argument2, argument3;
            argument2 = stack.pop();
            argument1 = stack.pop();
            if(sub=="+") {
                argument3 = argument1 + argument2;
            }
            else if(sub=="-") {
                argument3 = argument1 - argument2;
            }
            else if(sub == "*") {
                argument3 = argument1 * argument2;
            }
            else if(sub == "/") {
                argument3 = argument1/argument2;
            }
            stack.insert(argument3);
        }
        /*if its not an operator, assume its a double*/
        else {
            double d = atof(sub.c_str());
            stack.insert(d);
        }
    }//end while
    
    /*the only node on the stack is the answer*/
    double answer = stack.pop();
    return answer;
    
}//end parse