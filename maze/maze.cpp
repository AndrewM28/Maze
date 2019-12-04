/*************************************************************************
File Name: maze.cpp
Des:  This program inputs a set of mazes from a file, and then attempts to solve them 
	using a brute force method that utilizes a Stack ADT, and then outputs the results
	to a differant file
Author: Andrew Mock

*************************************************************************/


#include <iostream>
#include <fstream>
#include "Stack.h"
#include "vld.h"
using namespace std;


//solveMaze: Checks all available moves from the current cooinate and places them 
//on the stack, and then pops off the next move and repeats until an exit is 
//found or the stack is empty
bool solveMaze(char maze[][80], int startRow, int startColumn) {
	
	Stack moveStack;
	Coordinate currentCoordinate;
	currentCoordinate.Column = startColumn;
	currentCoordinate.Row = startRow;


	//Checks to see if an exit is found
	while (maze[currentCoordinate.Row][currentCoordinate.Column] != 'E') {

		//Checks to see if the north coordinate is a valid move
		if (maze[currentCoordinate.Row - 1][currentCoordinate.Column] >= 0) {

			if (maze[currentCoordinate.Row - 1][currentCoordinate.Column] == '0' ||
				maze[currentCoordinate.Row - 1][currentCoordinate.Column] == 'E') {

				Coordinate northCoordinate = currentCoordinate;
				northCoordinate.Row--;
				if (!moveStack.Push(northCoordinate)) {

					cerr << "C++ memory allocation error ... program exiting" << endl;
					exit(EXIT_FAILURE);
				}
			}
		}

		//Checks to see if the south coordinate is a valid move
		if (maze[currentCoordinate.Row + 1][currentCoordinate.Column] >= 0) {

			if (maze[currentCoordinate.Row + 1][currentCoordinate.Column] == '0' ||
				maze[currentCoordinate.Row + 1][currentCoordinate.Column] == 'E') {

				Coordinate southCoordinate = currentCoordinate;
				southCoordinate.Row++;
				if (!moveStack.Push(southCoordinate)) {

					cerr << "C++ memory allocation error ... program exiting" << endl;
					exit(EXIT_FAILURE);
				}
			}

		}

		//Checks to see if the east coordinate is a valid move
		if (maze[currentCoordinate.Row][currentCoordinate.Column + 1] >= 0) {

			if (maze[currentCoordinate.Row][currentCoordinate.Column + 1] == '0' ||
				maze[currentCoordinate.Row][currentCoordinate.Column + 1] == 'E') {

				Coordinate eastCoordinate = currentCoordinate;
				eastCoordinate.Column++;
				if (!moveStack.Push(eastCoordinate)) {

					cerr << "C++ memory allocation error ... program exiting" << endl;
					exit(EXIT_FAILURE);
				}
			}

		}

		//Checks to see if the west coordinate is a valid move
		if (maze[currentCoordinate.Row][currentCoordinate.Column - 1] >= 0) {

			if (maze[currentCoordinate.Row][currentCoordinate.Column - 1] == '0' ||
				maze[currentCoordinate.Row][currentCoordinate.Column - 1] == 'E') {

				Coordinate westCoordinate = currentCoordinate;
				westCoordinate.Column--;
				if (!moveStack.Push(westCoordinate)) {

					cerr << "C++ memory allocation error ... program exiting" << endl;
					exit(EXIT_FAILURE);
				}
			}

		}

		//Places a "breadcrumb" on the current coodinate to singnify that coordinate has 
		//already been processed
		maze[currentCoordinate.Row][currentCoordinate.Column] = '.';

		//If the stack is empty, then there is no exit
		if (!moveStack.Pop(currentCoordinate)) {
			moveStack.~Stack();
			return false;
		}
	}

	//Exit is found
	moveStack.~Stack();
	return true;
	
}




int main(){

	const int MAXROWS = 80;
	const int MAXCOLUMNS = 80;

	char maze[MAXROWS][MAXCOLUMNS];
	char returnCharacter;
	int row, col, rIndex, cIndex, startRow, startColumn;
	int mazeNum = 0;
	bool results;
	

	ifstream fin("maze.txt");
	ofstream fout("mazeSolutions.txt");
	fout << "Solutions to A-MAZE-ING Stacks Assignment" << endl << "Andrew Mock" << endl << endl;

	fin >> row >> col;



	do
	{
		mazeNum++;
		for (rIndex = 0; rIndex < row; rIndex++) {

			for (cIndex = 0; cIndex < col; cIndex++) {
				fin >> maze[rIndex][cIndex];
			}

		}

		fin >> startRow >> startColumn;

		results = solveMaze(maze, startRow, startColumn);

		fout << "MAZE NUMBER " << mazeNum << endl << endl;

		for (rIndex = 0; rIndex < row; rIndex++)
		{
			for (cIndex = 0; cIndex < col; cIndex++) {
				fout << maze[rIndex][cIndex];
			}
			fout << endl;
		}
		if (results) {
			fout << endl << "There IS a way out!" << endl << endl;
		}
		else {
			fout << endl << "There IS NOT a way out!" << endl << endl;
		}


		fin >> row >> col;
	} while (row != -1 && col != -1);

	

	fout.close();
	fin.close();


}