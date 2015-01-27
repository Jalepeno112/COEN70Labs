/*
 * Alberto Diaz and Giovanni Brigs
 * 3/11/14
 * Lab10
 */


#include <stack>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <algorithm>
#include "cell.h"
using namespace std;

stack<int> DFS_Generate(Cell graph[], int width);
bool wallsIntact(Cell graph[], int index);
void printGraphEmpty(Cell graph[], int size);
void printGraphNumber(Cell graph[], int size);
void printShortestPath(stack<int>, Cell graph[], int width);
bool sortList(int i, int j) {return (i< j);}

int main() {
    int r;
    cout << "Enter width and height for square maze (1 value): " <<endl;
    cin >> r;
    int totalSize = r*r;
    srand(time(NULL));
    Cell *graph = new Cell[totalSize];
    for (int i = 0; i < totalSize; i++) {
        graph[i].setIndex(i);
    }
    stack <int> CellStack = DFS_Generate(graph, r);
    printGraphEmpty(graph,r);
    cout <<endl;
    printGraphNumber(graph,r);
    cout <<endl;
    printShortestPath(CellStack, graph, r);
    return 0;
}

stack<int> DFS_Generate(Cell graph[], int width) {
    //stack will be the shortest path
    stack<int> CellStack;
    int size = width*width;
    Cell* currentCell = &graph[0];
    
    int VisitedCells = 1;
    
    int visitOrder = 0;

    while (VisitedCells < size) {
        int adjacent[4];
        int adjacentCounter = 0;
        
	//check up
        if(currentCell->getIndex() - width >= 0) {
            if(wallsIntact(graph, currentCell->getIndex()-width)) {
                adjacent[adjacentCounter] = currentCell->getIndex()-width;
                adjacentCounter++;
            }
        }
        
	//check left
        if(currentCell->getIndex()%width != 0) {
            if(wallsIntact(graph, currentCell->getIndex()-1)) {
                adjacent[adjacentCounter] = currentCell->getIndex()-1;
                adjacentCounter++;
            }
        }
        
	//check right
        if(currentCell->getIndex()%width != width-1) {
            if(wallsIntact(graph, currentCell->getIndex()+1)) {
                adjacent[adjacentCounter] = currentCell->getIndex()+1;
                adjacentCounter++;
            }
        }

        //check down
        if(currentCell->getIndex()+width < width*width) {
            if(wallsIntact(graph, currentCell->getIndex()+width)) {
                adjacent[adjacentCounter] = currentCell->getIndex()+width;
                adjacentCounter++;
            }
        }
        
        //if there is a neighbor with all walls intact
        if(adjacentCounter > 0) {
            
        //get cell to break wall
        int random = rand() % adjacentCounter;
        int neighborIndex = adjacent[random];
        
	//if it is the left neighbor, point the left neighbors right to curent, and current left to neighbor
        if(neighborIndex == currentCell->getIndex() - 1) {
                graph[neighborIndex].setRight(&graph[currentCell->getIndex()]);
                graph[currentCell->getIndex()].setLeft(&graph[neighborIndex]);
        }
           
	//if it is right
        else if(neighborIndex == currentCell->getIndex() + 1) {
        	graph[neighborIndex].setLeft(&graph[currentCell->getIndex()]);
                graph[currentCell->getIndex()].setRight(&graph[neighborIndex]);
        }
        //if it is up
        else if(neighborIndex == currentCell->getIndex() - width) {
        	graph[neighborIndex].setDown(&graph[currentCell->getIndex()]);
                graph[currentCell->getIndex()].setUp(&graph[neighborIndex]);
        }
        //if it is down
        else {
        	graph[neighborIndex].setUp(&graph[currentCell->getIndex()]);
                graph[currentCell->getIndex()].setDown(&graph[neighborIndex]);
        }
            
        if(currentCell->getVisited() == -1) {
		graph[currentCell->getIndex()].setVisited(visitOrder%10);
		visitOrder++;
	}
        CellStack.push(currentCell->getIndex());
    
        currentCell = &graph[neighborIndex];
        VisitedCells++;
            
        }//end if walls intact
        
        else {
            currentCell = &graph[CellStack.top()];
            CellStack.pop();
        }
    }//end while
    return CellStack;
}//end generate

bool wallsIntact(Cell graph[], int index) {
    int walls = 0;
    if(graph[index].getUp() == NULL)
        walls++;
    if(graph[index].getDown() == NULL)
        walls++;
    if(graph[index].getLeft() == NULL)
        walls++;
    if(graph[index].getRight() == NULL)
        walls++;
    
    if(walls == 4)
        return true;
    else
        return false;
}

void printGraphEmpty(Cell graph[], int width) {
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            //check up
            Cell currentCell = graph[(i*width)+j];
            if(currentCell.getUp() == NULL)
                cout <<"+-";
            else
                cout << "+ ";
        }
        cout << "+\n";
        for( int j = 0; j < width; j++){
            Cell currentCell = graph[(i*width)+j];
            if(currentCell.getLeft() == NULL)
                cout <<"| ";
            else
                cout << "  ";
        }
        cout << "|\n";
    }//end for i
    for (int i = 0; i < width-1; i++) {
        cout << "+-";
    }
	//print bottom of exit square
    cout<<"+ +\n";
}//end print graph

void printGraphNumber(Cell graph[], int width) {
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            //check up
            Cell currentCell = graph[(i*width)+j];
            if(currentCell.getUp() == NULL)
                cout <<"+-";
            else
                cout << "+ ";
        }
        cout << "+\n";
        for( int j = 0; j < width; j++){
            Cell currentCell = graph[(i*width)+j];
            if(currentCell.getLeft() == NULL)
                cout <<"|";
            else
                cout << " ";
            if(currentCell.getVisited() != -1)
                cout <<currentCell.getVisited();
            else {
                cout<<" ";
            }
        }
        cout << "|\n";
    }//end for i
    for (int i = 0; i < width-1; i++) {
        cout << "+-";
    }
    cout<<"+ +\n";
}

void printShortestPath(stack<int>CellStack, Cell graph[], int width) {
    list<int> sorted;
    //reverse the stack because of the way we do print
    int size = CellStack.size();
    
	for (int k = 0; k < size; k++) {
        	sorted.push_front(CellStack.top());
		cout << sorted.front() << " ";
        	CellStack.pop();
    	}
	cout << endl;
    for (list<int>::iterator it = sorted.end(); it != sorted.begin(); it--) {
        cout << *it << " ";
	if (*it == width*width-1) {
            break;
        }
        else {
            sorted.pop_back();
        }
    }
	cout <<endl;
    //sort the list
    sorted.sort();
    
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            //check up
            Cell currentCell = graph[(i*width)+j];
            if(currentCell.getUp() == NULL)
                cout <<"+-";
            else
                cout << "+ ";
        }
        cout << "+\n";
        for(int j = 0; j < width; j++){
            Cell currentCell = graph[(i*width)+j];
            if(currentCell.getLeft() == NULL)
                cout <<"|";
            else
                cout << " ";
            if(currentCell.getIndex() == sorted.front()) {
                cout <<"#";
                sorted.pop_front();
                //if it hits the last spot, stop cause its already found the exit
            }
            else {
                cout<<" ";
            }//end else
            
        }
        cout << "|\n";
    }//end for i
    for (int i = 0; i < width-1; i++) {
        cout << "+-";
    }
    cout<<"+ +\n";
}
