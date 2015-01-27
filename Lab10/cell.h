/*
 * Alberto Diaz and Giovanni Brigs
 * 3/11/14
 * Lab10
 */
#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std;

class Cell {
public:
    Cell();
    
    /*Accssors*/
    Cell* getUp();
    Cell* getDown();
    Cell* getLeft();
    Cell* getRight();
    int getIndex();
    int getVisited();
    /*Mutators*/
    void setUp(Cell*);
    void setDown(Cell*);
    void setLeft(Cell*);
    void setRight(Cell*);
    void setIndex(int i);
    void setVisited(int v);
private:
    Cell* up;
    Cell* down;
    Cell* left;
    Cell* right;
    int visited;
    int index;
};

Cell::Cell()
{
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    index = 0;
    visited = -1;
}

/*ACESSORS*/
Cell* Cell::getUp()
{
    return up;
}

Cell* Cell::getDown()
{
    return down;
}

Cell* Cell::getLeft()
{
    return left;
}
Cell* Cell::getRight() {
    return right;
}
int Cell::getIndex() {
    return index;
}
int Cell::getVisited() {
    return visited;
}

/*MUTATORS*/
void Cell::setUp(Cell* c) {
    up = c;
}
void Cell::setDown(Cell* c) {
    down = c;
}
void Cell::setLeft(Cell* c) {
    left = c;
}
void Cell::setRight(Cell* c) {
    right = c;
}
void Cell::setIndex(int i) {
    index = i;
}
void Cell::setVisited(int v) {
    visited = v;
}
#endif