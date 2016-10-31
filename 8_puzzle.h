#include <iostream>
#include <cstdio>
#include <cstdlib>

class problem
{

private:
	int puzzle[3][3];
	int goal[3][3];
public:
	problem();
	~problem();
	void print_node();
	int current_node();
};
