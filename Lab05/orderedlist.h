/*
 * Name:    Giovanni Briggs and Kevin Cai
 * Date:    2/4/14
 * Class:   COEN 70L Tuesday 2:15pm
 * Lab:     5
 */
#ifndef _orderedlist_h
#define _orderedlist_h

#include <iostream>

using namespace std;
class List {
public:
	List();
	~List();
	List(const List&);
	const List& operator=(const List&);
	friend ostream& operator<<(ostream&, const List&);
	void insert(const int&);
    void replace(const int&, const int&);
	class node {
	public:
		node(int, node*);
		int data;
		node* next;
	};
protected:
	node * list;
	int size;
	node* cursor;
};
//node constructor
List::node::node(int i, node* n) {
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
void List::insert(const int & i ){
    cursor=list;
    //get to end of list
    while(cursor->next != NULL){
        cursor=cursor->next;
    }
    //insert
    cursor->next = new node (i, NULL);
    size++;
}

//replace at index with data
void List::replace (const int &index, const int& data) {
    cursor = list;
    for(int i = 0; i < index; i++) {
        if(cursor == NULL) {
            cout << "Index does not exist!"<<endl;
            break;
        }
        cursor = cursor->next;
    }//end for
    /*after going through the loop, cursor will point to the index(th) node*/
    cursor->data = data;
}//end replace

/*ORDERED LIST INHERITS FROM LIST*/
class OrderedList : public List {
public:
    OrderedList();
    ~OrderedList();
    void replace(const int&, const int &);
    void insert(const int&);
};//end class
//constructor inherited from List
OrderedList::OrderedList():List() {}

OrderedList::~OrderedList(){
    cursor = list->next;
	while(cursor != NULL) {
		delete list;
		list = cursor;
		cursor = list->next;
	}
}

//deletes the node at index and inserts data
void OrderedList::replace(const int& index, const int& data) {
    cursor = list;
    node * prev;
    prev = cursor;
    for (int i = 0; i < index; i++) {
        if(cursor == NULL) {
            cout <<"index does not exist!"<<endl;
            return;
        }
        prev = cursor;
        cursor = cursor->next;
    }//end for
    //assign pointers to keep list together
    prev->next = cursor->next;
    //delete the current index
    delete cursor;
    //use insert to insert the new data in order
    insert(data);
}//end replace

//insert and keep list in order
void OrderedList::insert(const int& data) {
    cursor = list->next;
    node *prev = list;
    /*if list is empty*/
    if(cursor == NULL) {
        list->next = new node (data, NULL);
        return;
    }
    /*traverse list looking for spot to insert data in order*/
    while(cursor!=NULL) {
        if(data < cursor->data){
            break;
        }
        prev = cursor;
        cursor = cursor->next;
    }//end while
    prev->next = new node(data, cursor);
    size++;
}//end insert
#endif