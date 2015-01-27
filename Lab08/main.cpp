#include "tree.h"


int main()
{
	Tree express;
    
	string input;
    
	cout << "Please enter a postfix expression" << endl;
	getline(cin, input);
    
	express.build(input);
    
	cout << "Result: " << express.evaluate() << endl;
    
	cout << "Preorder: ";
	express.print_preorder();
	cout << endl;
    
	cout << "Postorder: ";
	express.print_postorder();
	cout << endl;
    
	cout << "Inorder: ";
	express.print_inorder();
	cout << endl;
}