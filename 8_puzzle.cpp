#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

class Node
{
private:
	int state[9];
	int h_n;
	int g_n;
public:
	int f_n;
	Node(){}
	Node( int nNewState[], int nH, int nG )
	{
		for (int i = 0; i < 9; i++)
			state[i] = nNewState[i];

		h_n = nH;
		g_n = nG;
		f_n = g_n + h_n;
	}
	int *get_state()
	{
		return state;
	}
	void set_state(int newState[])
	{
		for(int i = 0;i < 9; i++)
				state[i] = newState[i];
	}
	void print_state()
	{
		for(int i = 0; i < 9; i++)
		{
			cout<<state[i]<<" ";
			if( (i+1)% 3 == 2)
				cout<<endl;
		}
	}
};

class puzzle
{
private:
	Node current_node;
	Node goal_node;
	int goal[9];
	queue<Node> visited_nodes;
public:
	puzzle(){}
	~puzzle(){}
	void print_current_node()
	{
		current_node.print_state();
	}
	Node get_current_node()
	{
		return current_node;
	}
	void set_current_node(Node n)
	{
		current_node = n;
	}
	void generate_goal_state()
	{
		for(int i = 0; i < 8; i++)
			goal[i] = i+1; 

		goal[8] = 0;
		goal_node.set_state(goal);
	}
	bool is_goal(Node n)
	{
		bool check = true;
		int* a = n.get_state();
		for(int i = 0; i < 9; i++)
			if(goal[i] != a[i])
				check = false;
		return check;
	}
};


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

//Overload the > operator.
bool operator> (const  Node &node1, const Node &node2)
{
	return node1.f_n < node2.f_n;	
}


// Add container elements.
/*pqStudent2.push( Student( "Mark", 38 ) );
pqStudent2.push( Student( "Marc", 25 ) );
*/

//general-search
void general_search(Node problem, void *queuing_function())
{
	//The priorities will be assigned in the Descending Order of priority
	priority_queue<Node, vector<Node>,greater<vector<Node>::value_type> > nodes;
	nodes.push(problem);
	puzzle element;
	while (1)
	{
		if(nodes.empty())
		{
			cout<<"Is empty";
			return;
		} 
        element.set_current_node(nodes.top());
        nodes.pop();
        //if problem.goal state() succeed then return node
        //node = queuing function()
	}

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

int main(int argc, char const *argv[])
{
	int puzzle_choice, algo_choice;
	int start_state[9] = {1,2,3,4,0,6,7,5,8};
	
	cout<<"Welcome to Abhishek's 8-puzzle solver."<<endl;
	
	cout<<"Type '1' to use a default puzzle, or"<<endl<<"Type '2' to enter your own puzzle."<<endl;
	cin>>puzzle_choice;

	if(puzzle_choice == 1)
	{
		//generate intial state

	} 
	else if(puzzle_choice == 2)
	{
		cout<<"Enter your puzzle, use a zero to represent the blank"<<endl;
		//puzzle input
		for(int i = 0; i < 9; i++)
		{
			if( (i+1)%3 == 2 )
				cout<<"Enter row: "<<((i+1)/3)+1<<"use space or tabs between numbers"<<endl;
			cin>>start_state[i];
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
	cout<<"Enter your choice of algorithm"<<endl<<"1. Uniform Cost Search"<<endl<<"2. A* with the Misplaced Tile heuristic."
	<<endl<<"3. A* with the Manhattan distance heuristic."<<endl;
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