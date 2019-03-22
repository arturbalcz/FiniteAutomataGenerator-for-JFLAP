#pragma once
#include"source.h"

class State
{
public:
	State(int id, string name); 
	State(int id, string name, bool initial, bool final);
	~State() {}
	int id; 
	string name;
	int x; 
	int y; 
	bool initial; 
	bool final; 

	friend ofstream& operator<<(ofstream& stream, State state); 
};
