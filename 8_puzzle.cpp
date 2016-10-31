#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

class puzzle
{

private:
	int state[3][3];
	int goal[3][3];
public:
	puzzle(int *initial)
	{

	}
	~puzzle();
	void print_node();
	int get_current_node();
	void generate_goal_state()
	{
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				goal[i][j] = 3*i+j+1;

		goal[2][2] = 0;
	}
};

class Node
{
private:
	int state[3][3];
	int h;
	int g;
public:
	int priority;
	Node( int nNewState[][3], int nH, int nG )
	{
		for(int i = 0;i < 3; i++)
			for(int j = 0; j < 3; j++)
				state[i][j] = nNewState[i][j];
		h = nH;
		g = nG;
		priority = h + g;
	}
};

//Overload the > operator.
bool operator> (const  Node &node1, const Node &node2)
{
	return node1.priority < node2.priority;	
}


//The priorities will be assigned in the Descending Order of priority
priority_queue<Node, vector<Node>,greater<vector<Node>::value_type> > pqNodes;

// Add container elements.
/*pqStudent2.push( Student( "Mark", 38 ) );
pqStudent2.push( Student( "Marc", 25 ) );
*/
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

void * a_star_misplaced_tile_heuristic()
{

}
//manhattan distance heuristic algorihtm i.e h'(n)
int manhattan_distance()
{

}

void * a_star_manhattan_distance_heuristic()
{

}

//general-search
void general_search(Node problem, void *queuing_function())
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
		
}

int main(int argc, char const *argv[])
{
	int puzzle_choice, algo_choice, start_state[3][3];;
	
	cout<<"Welcome to Abhishek's 8-puzzle solver."<<endl;
	
	cout<<"Type '1' to use a default puzzle, or"<<endl;
	cout<< "Type '2' to enter your own puzzle."<<endl;
	cin>>puzzle_choice;

	if(puzzle_choice == 1)
	{
		//generate intial state

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
				cin>>start_state[i][j];
			}
		}
	}
	else
	{
		cout<<"Wrong!!(In trump's Voice)"<<endl;
		return 0;
	}

	//Intialization	
	Node problem(start_state,0,0);
	//Algorithm Choice Input
	cout<<"Enter your choice of algorithm"<<endl<<"1. Uniform Cost Search"<<endl<<"2. A* with the Misplaced Tile heuristic."<<endl<<"3. A* with the Manhattan distance heuristic."<<endl;
	cin>>algo_choice;
	//general-search
	if(algo_choice == 1)
	{
		cout<<"Using Uniform Cost Search"<<endl;
		general_search(problem, uniform_cost_search);
	}
	else if(algo_choice == 2)
	{
		cout<<"Using A* with misplaced tile heuristic"<<endl;
		general_search(problem,a_star_misplaced_tile_heuristic);
	}
	else if(algo_choice == 3)
	{
		cout<<"Using A* with manhattan distance heuristic"<<endl;
		general_search(problem,a_star_manhattan_distance_heuristic);
	}
	else
	{
		cout<<"Wrong!!(In trump's Voice)"<<endl;
		return 0;
	}
	//output function
	return 0;
}