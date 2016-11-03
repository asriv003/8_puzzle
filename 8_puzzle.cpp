#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Node
{
private:
	int h_n;
	int g_n;
public:
	int state[9];
	int f_n;
	Node()
	{
		for (int i = 0; i < 9; i++)
			state[i] = 0;

		h_n = 0;
		g_n = 0;
		f_n = g_n + h_n;
	}
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
	int get_h()
	{
		return h_n;
	}
	int get_g()
	{
		return g_n;
	}
	void set_state(int newState[])
	{
		for(int i = 0;i < 9; i++)
				state[i] = newState[i];
	}
	void set_h(int h)
	{
		h_n = h;
	}
	void set_g(int g)
	{
		g_n = g;
	}
	void print_state()
	{
		for(int i = 0; i < 9; i++)
		{
			cout<<state[i]<<" ";
			if( (i)% 3 == 2)
				cout<<endl;
		}
	}
	bool is_equal_state (int *test)
	{
		bool check = true;
		for(int i = 0; i < 9; i++)
			if(state[i] != test[i])
				check = false;
		return check;
	}

};

class puzzle
{
private:
	Node current_node;
	int goal[9];
	vector<Node> visited_nodes;
public:
	puzzle()
	{
		for(int i = 0; i < 8; i++)
			goal[i] = i+1; 

		goal[8] = 0;
	}
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
	bool is_goal_state()
	{
		bool check = true;
		for(int i = 0; i < 9; i++)
			if(goal[i] != current_node.state[i])
				check = false;
		return check;
	}
	void insert_visited_node(Node vn)
	{
		visited_nodes.push_back(vn);
	}
	void print_visited_node_size()
	{
		cout<< "visited nodes size: "<<visited_nodes.size()<<endl;
	}
	int is_visited(Node n)
	{
		vector<Node>::iterator it;
		int* a = n.get_state();
		for (it = visited_nodes.begin(); 
			it != visited_nodes.end(); ++it)
		{
			bool check = true;
			for(int i = 0; i < 9; i++)
			{
				if(it->state[i] != a[i])
				{
					check = false;
					break;
				}
			}
			if(check)
				return true;
		}
		return false;
	}
};

int general_index(int node[9], int value)
{
	for(int i = 0; i < 9; i++)
		if(node[i] == value)
			return i;
}

void swap_value(int *a,int *b)
{
	*a = *a + *b;
	*b = *a - *b;												//swaps the nodes
	*a = *a - *b;
}

//move blank left function
bool move_blank_left(Node &n)
{
	int blank = general_index(n.get_state(),0);
	if(blank%3 != 0)
	{
		swap_value(&n.state[blank], &n.state[blank-1]);
		return true;
	}
	return false;
}

//move blank right function
bool move_blank_right(Node &n)
{
int blank = general_index(n.get_state(),0);
	if(blank%3 != 2)
	{
		swap_value(&n.state[blank], &n.state[blank+1]);
		return true;
	}
	return false;
}

//move blank up funtion
bool move_blank_up(Node &n)
{
	int blank = general_index(n.get_state(),0);
	if(blank >= 3)
	{
		swap_value(&n.state[blank], &n.state[blank-3]);
		return true;
	}
	return false;
}

//move blank down function
bool move_blank_down(Node &n)
{
	int blank = general_index(n.get_state(),0);
	if(blank < 6)
	{
		swap_value(&n.state[blank], &n.state[blank+3]);
		return true;
	}
	return false;
}

priority_queue<Node, vector<Node>,greater<vector<Node>::value_type> > queued_nodes;
//Overload the > operator.
bool operator> (const  Node &node1, const Node &node2)
{
	return node1.f_n < node2.f_n;	
}
bool operator< (const  Node &node1, const Node &node2)
{
	return node1.f_n > node2.f_n;	
}
queue<Node>expanded_nodes;
int all_visited_nodes, max_queue_length;

void update_max_queue_length()
{
	if(queued_nodes.size() > max_queue_length)
		max_queue_length = queued_nodes.size();
}


//uniform cost search algorithm
void * uniform_cost_search()
{
	while(!expanded_nodes.empty())
	{
		queued_nodes.push(expanded_nodes.front());
		expanded_nodes.pop();
		update_max_queue_length();
	}
}

//misplaced tile heuristic algorithm
int misplace_tile(int *a)
{
	int h = 0;
	for(int i = 0; i < 9; i++)
		if(a[i] != 0 && a[i] != i+1)
		{
			cout<<a[i] << ":"<<i<<endl;
			h++;
		}

	cout<<"h: "<<h<<endl;
	int t;
	cin>>t;
	return h;
}

void * a_star_misplaced_tile_heuristic()
{
	int h;
	while(!expanded_nodes.empty())
	{
		Node n = expanded_nodes.front();
		h = misplace_tile(n.get_state());
		n.set_h(h);
		queued_nodes.push(n);
		expanded_nodes.pop();
		update_max_queue_length();
	}
}
//manhattan distance heuristic algorihtm i.e h'(n)
int manhattan_distance(int *a)
{
	int h = 0;
	int index, r, c;
	for(int i = 0; i < 8; i++)
	{
		index = general_index(a, i+1);
		r = abs((i/3) - (index/3));						//Quotient of index and matrix size gives you the row
		c = abs((i%3) - (index%3));						//Remainder gives column
		h = h + r + c;
	}
	index = general_index(a, 0);											//same for the blank tile alone
	r = abs((8/3) - (index/3));					
	c = abs((8%3) - (index%3));
	h = h + r + c;
	return h;
}

void * a_star_manhattan_distance_heuristic()
{
	int h;
	while(!expanded_nodes.empty())
	{
		Node n = expanded_nodes.front();
		h = misplace_tile(n.get_state());
		n.set_h(h);
		queued_nodes.push(n);
		expanded_nodes.pop();
		update_max_queue_length();
	}
}

void expand(Node data,puzzle project)
{
	int * current_state = data.get_state();
	int current_g = data.get_g();
	Node left_node, right_node,up_node, down_node;

	left_node.set_state(current_state);
	right_node.set_state(current_state);
	up_node.set_state(current_state);
	down_node.set_state(current_state);

	if( move_blank_left(left_node))
	{
		if(!project.is_visited(left_node) )
		{
			left_node.set_g(current_g + 1);
			expanded_nodes.push(left_node);
			all_visited_nodes++;
		}
	}
	if(move_blank_right(right_node))
	{
		if(!project.is_visited(right_node) )
		{
			right_node.set_g(current_g + 1);
			expanded_nodes.push(right_node);
			all_visited_nodes++;
		}
	}
	if(move_blank_up(up_node))
	{
		if(!project.is_visited(up_node))
		{
			up_node.set_g(current_g + 1);
			expanded_nodes.push(up_node);
			all_visited_nodes++;
		}
	}
	if(move_blank_down(down_node))
	{
		if(!project.is_visited(down_node))
		{
			down_node.set_g(current_g + 1);
			expanded_nodes.push(down_node);
			all_visited_nodes++;
		}
	}
}

//general-search
Node general_search(Node problem, void *queuing_function())
{
	//The priorities will be assigned in the Descending Order of priority
	
	queued_nodes.push(problem);
	update_max_queue_length();
	Node curr_node;
	puzzle element;

	while (1)
	{
		if(queued_nodes.empty())
		{
			cout<<"Queue is empty...returning..!!"<<endl;
			return curr_node;
		}
		curr_node = queued_nodes.top();
		element.set_current_node(curr_node);
		queued_nodes.pop();
		cout<<"The best state to expand with a g(n) = "<<curr_node.get_g()<<" and h(n) = "<<curr_node.get_h()<<" is...."<<endl;
		element.print_current_node();
		if(element.is_goal_state())
		{
			cout<<"Goal State Found!!"<<endl;
			cout<<"To solve this problem, the search algorithm expanded a total of "<<all_visited_nodes<<" nodes."<<endl;
			cout<<"The maximum number of nodes in the queue at any time was "<<max_queue_length<<"."<<endl;
			cout<<"The depth of the goal node was "<<curr_node.get_g()<<endl;
			return curr_node;
		}
		cout<<"Expanding nodes..."<<endl;
		expand(curr_node,element);
		queuing_function();
	}
}

int main(int argc, char const *argv[])
{
	int puzzle_choice, algo_choice;
	int start_state[9] = {0,1,3,4,2,5,7,8,6};	//default state
	
	cout<<"Welcome to Abhishek's 8-puzzle solver."<<endl;
	
	cout<<"Type '1' to use a default puzzle, or"<<endl<<"Type '2' to enter your own puzzle."<<endl;
	cin>>puzzle_choice;

	if(puzzle_choice == 1)
	{
		//generate intial state
		cout<<"using default puzzle"<<endl;

	} 
	else if(puzzle_choice == 2)
	{
		cout<<"Enter your puzzle, use a zero to represent the blank"<<endl;
		//puzzle input
		for(int i = 0; i < 9; i++)
		{
			if( (i+1)%3 == 1 )
				cout<<"Enter row: "<<((i+1)/3)+1<<" use space or tabs between numbers"<<endl;
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