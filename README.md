# 2048-Solver-Simulator
1) Purpose of this Project’
	- Practice and Learn the use of stacks
2) Instructions
	- Create a C++ program to find the shortest path to solve the given matrix
3) Specifics:
	- This is not 2048 it simulates it in a sense
	- A matrix is considered solved if there is only one number left in the matrix that isn’t 0 or 2048
	- 2048 acts like a wall it cannot move or be merged
	- 0 represents an empty space
	- 1 represents a shift up, 2 represents a shift right, 3 represents a shift down, and 4 represents a shift left
	- You are not allowed to merge a number more than once if it has already been merged in that shift
4) Input and Output Example:
	- **This program takes as STDIN:**
		- Dimensions of the matrix(in the first line)
		- The matrix the user is working with
	- **This program returns:**
		- The shortest path taken to solve the matrix or 0 if the matrix was not solved or can't be shifted any further
		
	- INPUT:
		- 4
		- 2 0 0 0
		- 0 0 0 0
		- 0 0 0 0
		- 0 0 0 0
	-  OUTPUT:
		- 0
