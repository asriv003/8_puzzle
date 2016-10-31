#include "8_puzzle.h"

using namespace std;

int puzzle[3][3];

//check valid move

bool is_valid_move()
{

}

//move blank left function
void move_blank_left()
{

}

//move blank right function
void move_blank_right()
{

}

//move blank up funtion
void move_blank_up()
{

}

//move blank down function
void move_blank_down()
{

}

//uniform cost search algorithm
void * uniform_cost_search()
{

}

//misplaced tile heuristic algorithm
int misplace_tile()
{

}

void * misplaced_tile_heuristic()
{

}
//manhattan distance heuristic algorihtm i.e h'(n)
int manhattan_distance()
{

}

void * manhattan_distance_heuristic()
{

}

//queuing function

//general-search
void general_search(problem puzzle, void *queuing_function())
{

}

//generate random intial stage

//generate goal state

//output funtion
void output(int total_nodes, int max_nodes, int depth)
{
	cout<<"To solve this problem the search algorithm expanded a total of "<< total_nodes << " nodes."<<endl;
	cout<<"The maximum number of nodes in the queue at any one time was "<< max_nodes <<endl;
	cout<<"The depth of the goal node was "<< depth <<endl;
}

//print algorithm choices
void print_algo_choices()
{
		cout<<"Enter your choice of algorithm"<<endl;
		cout<<"1. Uniform Cost Search"<<endl;
		cout<<"2. A* with the Misplaced Tile heuristic."<<endl;
		cout<<"3. A* with the Manhattan distance heuristic."<<endl;
}

int main(int argc, char const *argv[])
{
	int puzzle_choice, algo_choice;
	
	cout<<"Welcome to Abhishek's 8-puzzle solver."<<endl;
	
	cout<<"Type '1' to use a default puzzle, or"<<endl;
	cout<< "Type '2' to enter your own puzzle."<<endl;
	cin>>puzzle_choice;

	if(puzzle_choice == 1)
	{
		//generate random intial state

		//Algorithm Choice Input
		print_algo_choices();
		cin>>algo_choice;
		//general-search
		//output function
	} 
	else if(puzzle_choice == 2)
	{
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

		//Algorithm Choice Input
		print_algo_choices();
		cin>>algo_choice;

		//general-search
		//output function
	}
	else
	{
		cout<<"Wrong!!(In trump's Voice)"<<endl;
	}

	return 0;
}