#include"transition.h"

Transition::Transition(int from, int to, char read)
{
	this->from = from; 
	this->to = to; 
	this->read = read; 
}

ofstream & operator<<(ofstream & stream, Transition trans)
{
	stream << "<transition>&#13;" << endl;
	stream << "<from>" << trans.from << "</from>&#13;" << endl;
	stream << "<to>" << trans.to << "</to>&#13;" << endl;
	stream << "<read>" << trans.read << "</read>&#13;" << endl;
	stream << "</transition>&#13;" << endl;
	return stream;
}
