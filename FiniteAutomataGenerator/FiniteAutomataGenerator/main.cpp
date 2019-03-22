#include"source.h"
#include"state.h"
#include"transition.h"

void save(vector<State> &StateVec, vector<Transition> &TranVec)
{
	string filename; 
	cout << "type name of output file[default: automata.jff]: "; 
	(getline(cin, filename));
	(getline(cin, filename)); 
	if (filename=="\0")
	{
		filename = "automata.jff";
	}

	ofstream out; 
	out.open(filename, ios::out); 
	out << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?><!--Created with JFLAP 7.1.--><structure>&#13;" << endl; 
	out << "<type>fa</type>&#13;" << endl; 
	out << "<automaton>&#13;" << endl; 
	out << "<!--The list of states.-->&#13;" << endl; 

	for (auto e : StateVec)
	{
		out << e; 
	}

	out << "<!--The list of transitions.-->&#13;" << endl; 

	for (auto e : TranVec)
	{
		out << e;
	}

	out << "</automaton>&#13;" << endl;
	out << "</structure>"; 

	out.close(); 
}

int main()
{
	srand(time(NULL)); 

	int n, fs; 

	// n - number of states 
	//fs - number of final states

	cout << "n = "; 
	cin >> n;
	cout << endl;

	cout << "fs = ";
	cin >> fs;
	cout << endl; 

	vector<char> alphabet; 
	cout << "(\"*\" is final char) alphabet = "; 

	char ch; 
	while (cin>>ch)
	{
		if (ch == '*') break;
		alphabet.push_back(ch); 
	}
	cout << endl; 

	vector<Transition>TranVec; 
	vector<State> StateVec; 

	char ni = '0'; 

	for (int i = 0; i < n; i++)
	{
		string nm = "q";
		//nm += ni;
		//ni++;
		State st = State(i, nm); 
		StateVec.push_back(st); 
	}


	//initial state choosing 
	int ra = rand() % n, za = fs; 
	StateVec[ra].initial = 1; 

	//final states choosing 
	for (int i = 0; i < fs; i++)
	{
		ra = rand() % za; 
		StateVec[ra].final = 1; 
		swap(StateVec[ra], StateVec[StateVec.size() - 1 - i]); 
		za--; 
	}

	//transitions drawing 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ra = rand() % 2; 
			if (ra==1)
			{
				for (int k = 0; k < alphabet.size(); k++)
				{
					ra = rand() % 2;
					if (ra == 1)
					{
						Transition tra(i, j, alphabet[k]);
						TranVec.push_back(tra);
					}
				}
			}
		}
	}

	save(StateVec, TranVec); 

	return 0; 
}