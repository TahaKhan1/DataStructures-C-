/*--------------- P r o g 7 . c p p ---------------

Starter Code by:   George Cheney
      16.322 Data Structures
      ECE Dept.
      UMASS Lowell
 Finished By: Taha Khan
PURPOSE
Find a path through a maze.

DEMOSTRATES
Stack as Linked List
Backtracking

CHANGES
10-19-2016 gpc - Distribute to 16.322 class.
10-20-2016 gpc - Install naive SolveMaze( ) function.
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

#include "CursorCntl.h"
#include "Maze.h"
#include "Stack.h"
#include "cassert"

/*----- M a z e : : T r a v e r s e (  ) -----

PURPOSE
Maze traversal Program. Try all possible next
positions to reach Goal.Mark all the positions with V,
P if path is found and R if Rejected

RETURN VALUE
true  -- a solution was found.
false -- failed to find a solution.
*/

bool YouCanGetThereFrom(Maze &maze, const Position &curPos)
{
	   bool isOpen = 0;
	   maze.Visit(curPos);

        // If goal position then wait for user input and return
		if (curPos == maze.Goal())
		{
		   cin.get();
		   maze.MarkPathCell(curPos); // Path found
		   return 1;
		}
        // if position east is open
		if (maze.IsOpen(curPos + StepEast)){
		   maze.Visit(curPos + StepEast); // Mark visited
		   if (0 == YouCanGetThereFrom(maze, curPos + StepEast)){
			   maze.Reject(curPos); // Reject path
			   isOpen = 0;
		   }
		   else
		   {    // Path found
			   maze.MarkPathCell(curPos);
			   return 1;
		   }
		}// if position south is open
		if (maze.IsOpen(curPos + StepSouth)){
		   maze.Visit(curPos + StepSouth);// Mark visited
		   if (0 == YouCanGetThereFrom(maze, curPos + StepSouth)){
			   maze.Reject(curPos); // Reject path
		   }
		   else
		   {      // Path found
				 maze.MarkPathCell(curPos);
				 return 1;
		   }
		}// if position west is open
		if (maze.IsOpen(curPos + StepWest)){
		   maze.Visit(curPos + StepWest); // Mark visited
		   if (0 == YouCanGetThereFrom(maze, curPos + StepWest)) {
			   maze.Reject(curPos); // Reject path
		   }
		   else
		   {     // Path found
				 maze.MarkPathCell(curPos);
				 return 1;
		   }
		}// if position north is open
		if (maze.IsOpen(curPos + StepNorth)){
		   maze.Visit(curPos + StepNorth); // Mark visited
		   if (0 == YouCanGetThereFrom(maze, curPos + StepNorth)){
			   maze.Reject(curPos); // Reject path
		   }
		   else{
			   maze.MarkPathCell(curPos);
			   return 1;
		   }
		}
		maze.Reject(curPos);

		return 0;
}

/*--------------- m a i n ( ) ---------------*/

int main(void)
{
	// Screen positions
	const unsigned XResult = 15;
	const unsigned YResult = 5;
	const unsigned XFinish = 0;
	const unsigned YFinish = 20;

	// Position stack remembers visited positions.
	Stack posStack;

	// Construction of  maze.
	Maze maze;
	Position p = maze.Start();

	// Traverse the maze.
	bool success = YouCanGetThereFrom(maze, p);
	// Success or Failure.
	gotoxy(XResult, YResult);
	if (!success)
		cout << "Failed: No path from start to goal exists." << endl;
	else
		{
		cout << "Success: Found a path." << endl;

		cin.get();  // Wait for a key press.

   // Path back to the goal.
		while (!posStack.Empty());
			maze.MarkPathCell(posStack.Pop());
			}

	gotoxy(XFinish, YFinish);

   return 0;
}
