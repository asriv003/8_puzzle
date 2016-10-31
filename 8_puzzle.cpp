#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

puzzle[3][3];
goal[3][3];

//move blank left function
//move blank right function
//move blank up funtion
//move blank right function

//uniform cost search algorithm i.e g(n)
//misplaced time heuristic algorithm i.e h(n)
//manhattan distance heuristic algorihtm i.e h'(n)

//queuing function

//general-search

//generate random intial stage

//generate goal state

//output funtion
void output(int total_nodes, int max_nodes, int depth)
{
	cout<<"To solve this problem the search algorithm expanded a total of "<< total_nodes << " nodes."<<endl;
	cout<<"The maximum number of nodes in the queue at any one time was "<< max_nodes <<endl;
	cout<<"The depth of the goal node was "<< depth <<endl;
}

int main(int argc, char const *argv[])
{
	int puzzle_choice;
	
	cout<<"Welcome to Abhishek's 8-puzzle solver."<<endl;
	
	cout<<"Type “1” to use a default puzzle, or “2” to enter your own puzzle."<<endl;
	cin>>puzzle_choice;

	if(puzzle_choice == 1)
	{
		//generate random intial state
		//general-search
		//output function
	} else{
		cout<<"Enter your puzzle, use a zero to represent the blank"<<endl;
		//puzzle input
		for(int i = 0; i < 3; i++)
		{
			cout<<"Enter row: "<<i+1<<"use space or tabs between numbers"<<endl;
			for(int j = 0; j < 3; j++)
			{
				cin>>puzzle[i][j];
			}
		}

		//general-search
		//output function
	}

	return 0;
}