#pragma once
#include"state.h"

class Transition
{
public:
	Transition(int from, int to, char read); 
	~Transition() {}

	int from; 
	int to; 
	char read;

	friend ofstream& operator<<(ofstream& stream, Transition trans);
};
