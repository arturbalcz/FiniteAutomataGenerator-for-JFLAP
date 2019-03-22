#include "state.h"

State::State(int id, string name)
{
	this->id = id; 
	this->name = name; 
	x = 0; 
	y = 0; 
	initial = 0; 
	final = 0; 
}

State::State(int id, string name, bool initial, bool final)
{
	this->id = id;
	this->name = name;
	x = 0;
	y = 0;
	this->initial = initial; 
	this->final = final; 
}

ofstream & operator<<(ofstream & stream, State state)
{
	stream << "<state id=\"" << state.id << "\" name=\"" << state.name << "\">&#13;" << endl; 
	stream << "<x>" << state.x << ".0</x>&#13;" << endl; 
	stream << "<y>" << state.y << ".0</y>&#13;" << endl;
	if (state.final == 1)
	{
		stream << "<final/>&#13;" << endl; 
	}

	if (state.initial == 1)
	{
		stream << "<initial/>&#13;" << endl;
	}

	stream << "</state>&#13;" << endl; 
	return stream;
}
