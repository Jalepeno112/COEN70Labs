/*
 * Name:    Giovanni Brigs and Steven Sanz
 * Date:    2/25/14
 * Class:   Tues 2:15
 * Lab:     8
 */

#ifndef TREE_H
#define TREE_H
#include <string>
#include <iostream>
using namespace std;

class Tree {
public:
    Tree();
    ~Tree();
    void build(string &);
    int evaluate();
    void print_preorder();
    void print_inorder();
    void print_postorder();
private:
    Tree *left;
    Tree *right;
    int operand;
    char opertr;
};

//construct an empty tree with left and right equal to null
Tree::Tree() {
    left = NULL;
    right = NULL;
    operand = -1;
    opertr = '\0';
}

//destruct the tree
Tree::~Tree() {
    delete left;
    delete right;
    
}

//builds tree with operands as leaves and operators as roots and parents of operands
void Tree::build(string &s) {
    if(s.length() == 0)
        return;
    //get rid of space if it appears
    if (s.at(s.length()-1) == ' ') {
        s = s.substr(0,s.length()-1);
    }
    
    //if it is an operator, reduce the string by one character and then build the left and right trees
    if(s.at(s.length()-1) == '/' || s.at(s.length()-1) == '*' || s.at(s.length()-1) == '+'|| s.at(s.length()-1)=='-') {
        
        opertr = s.at(s.length()-1);
        
        //chop off last arugment
        s = s.substr(0,s.length()-1);
       
        right = new Tree();
        right->build(s);
        
        left = new Tree();
        left->build(s);
    }
    //if it is an operand, make it a leaf and decrease the string by 1 char
    else {
        operand = s.at(s.length()-1) - '0';
        left = NULL;
        right = NULL;
        s = s.substr(0,s.length()-1);
    }
}

//print root, left, right
void Tree::print_preorder() {
    if(left == NULL && right == NULL) {
        cout << operand <<" " ;
        return;
    }//end if operand
    else {
        cout << opertr <<" ";
    }
    left->print_preorder();
    right->print_preorder();
}

//print left, right, root
void Tree::print_postorder() {
    if(left == NULL && right == NULL) {
        cout << operand << " ";
        return;
    }
    else {
        left->print_postorder();
        right->print_postorder();
        cout << opertr <<" ";
    }
}

//print left, root, right
void Tree::print_inorder() {
    
    if(left == NULL && right == NULL) {
        cout << operand <<" ";
        return;
    }
    else {
        left->print_inorder();
        cout << opertr <<" ";
        right->print_inorder();
    }

}

//go until it hits a leave, return the operand, and then return the result of the two operands with the operator (which is the parent of the operands)
int Tree::evaluate() {
   if (left == NULL && right == NULL)
       return operand;
    int l = left->evaluate();
    int r = right->evaluate();
    if (opertr == '+') {
        return l + r;
    }
    else if(opertr == '-') {
        return l -r;
    }
    else if (opertr == '*')
        return l*r;
    else
        return l/r;
}
#endif
