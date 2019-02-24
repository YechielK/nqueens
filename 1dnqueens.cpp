/*
This is the program solves the the eight queens problem, but really solves the n queens problem.

The n queens problem is to find all possible solutions for putting n queens on an n x n chessboard
so they cannot harm each other. Basically, if you have an 8 x 8 chessboard, a solution would be to
find a way to put 8 queens on the board without them being able to kill each other. There are various 
mathematical mathods to solve this problem, but the most trivial to understand is the "Brute force" 
algorithm.

The algorithm starts by placing a queen on the first available spot in the first available column.
It then checks to make sure this is valid, as in is it directly in the path of any other queens.
If not, the algorithm moves on to the next column and places a queen on the first available spot 
and checks to see if the placement is valid. If the placement is not valid, the algorithm places the 
queen in the next available spot. 

If the queens has reached the last available spot in the column, the the program "backtracks". The 
algorithm moves to the previous column and moves the queen in that one to the next available spot.
It then will continue to try placing the queens in the original column. If the queen that the 
algorithm is trying to backtrack is also in the last spot in the column, then it will backtrack that
queens also. Using this method, there will eventually be a queen in every column, or n queens in 
n columns. Once the algortihm has reached this stage, it will print the solution and backtrack, so
further solutions can be reached.

 


*/
#include<iostream>
using namespace std;
bool check(int b[], int p){ //The check function. It only checks for values behind the placed column, as there may be values past it that will be overwritten.
	for (int i = 1; i <= p; i++){
		if (b[p] == b[p-i] || b[p] == b[p-i] + i || b[p] == b[p-i] - i) //Will return false if any of the three conditions are satisfied.
		//First checks if there is a queens in the same row, second checks if there is a queen in the lower diagonal, third checks upper diagonal
		{return false;}
	}	return true;
}

void print(int b[],int p,int x,int c){ //Prints solution.
	cout<<"Solution Number "<<c + 1<<endl;
	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
		if (b[i] == j)
		{cout<<1;}
		else 
		{cout<<0;}
		cout<<" ";
		}cout<<endl;
	}

}
int main(){
	int size; // The size of the board that will be used
	cout<<"Enter size of board: ";
	cin>>size;
	int column =0; //The column in which we are trying to place queens
	int counter = 0; //The amount of solutions we have found so far
	int board[size] = {0}; //The size of the board
	while (column >= 0){ 
		column++; //The algorithm starts of placing queens in the second column, the first queens in the first column doesnt need checking
		if(column == size){ //If we are trying to place a queen in n+1 columns, that means a solution to n queens has been found
			print(board, column, size, counter); //print function
			column--; //If a solution has been found, backtrack to find more solutions
			counter++; //Increases the amount of solutions found
		}
		else 
		{board[column] = -1;} //This sets the spot of the column were in to -1. When the while loop starts, it'll move up to 0
		while(column >= 0){ //This loop goes as long the value of the column being backtracked is greater then 0. If it backtracks past that, it means all solutions have been found
			board[column]++; //Increase to next spot in the column
			if(board[column] == size){ //If a queen is placed in the n+1 spot, we must backtrack, so we move queen in previous column 
				column--;
			}
			else{ 
				if( check(board, column)) //If the check function to see if the queen placement was valid returns true, end loop.
				{break;}
			}
		}	
	} 
	return 0;
}
