/*
 * Name:    Giovanni Briggs and Reed Conway
 * Date:    1/28/14
 * Class:   COEN 70L Tuesday 2:15pm
 * Lab:     04
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;
class List {
public:
	List();
	~List();
	List(const List&);
	const List& operator=(const List&);
	friend ostream& operator<<(ostream&, const List&);
    /*insert to front*/
	void insert(const double&);
    /*pop the first element*/
    double pop();
	class node {
	public:
		node(double, node*);
		double data;
		node* next;
	};
private:
	node * list;
	int size;
	node* cursor;
};
//node constructor
List::node::node(double i, node* n) {
	data = i;
	next = n;
}
//default constructor
List::List() {
	list = new node(0,NULL);
	size = 0;
	cursor = list;
}
//destructor
List::~List() {
	cursor = list->next;
	while(cursor != NULL) {
		delete list;
		list = cursor;
		cursor = list->next;
	}
}
//copy constructor
List::List(const List& l) {
    node* cursTemp;
	cursTemp = l.list->next;
	list = new node(0,NULL);
    cursor = list;
	size = 0;
	while(cursTemp != NULL) {
		cursor->next = new node(cursTemp->data, NULL);
		cursor=cursor->next;
        cursTemp=cursTemp->next;
	}
    size = l.size;
}

//assignment operator
const List& List::operator= (const List& l) {
	list = l.list;
	size = l.size;
	return l;
}
//print operator
ostream& operator <<(ostream & out, const List& l) {
	List print;
    print.cursor = l.list->next;
    while(print.cursor != NULL) {
		out << print.cursor->data << ", ";
		print.cursor = print.cursor->next;
	}
	out <<endl;
	return out;
}

//insert at end of list
void List::insert(const double & i ){
    /*start at the node right after list*/
    cursor = list->next;
    //insert after the dummy node, but before cursor
    list->next = new node (i, cursor);
    size++;
}
double List::pop() {
    if (list->next == NULL) {
        cout << "List is empty!"<<endl;
        return 0;
    }
    cursor = list->next;
    double d = cursor->data;
    list->next = cursor->next;
    delete cursor;
    return d;
}
#endif
