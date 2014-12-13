//Back-Up addword function
void Concordance::addWord(string aword,int linenumber)
{
int i=0;

	if (entries.size() == 0) 
	{
		int count;
		count = 1;
		Entry e(aword, count, linenumber);
		entries.push_back(e);
	}
	if (entries[i].getword() == aword)
	{
		entries[i].increaseCount();
		entries[i].addline(linenumber);
		i++;
	}	
	else
	{
		int count;
		count = 1;
		Entry e(aword, count, linenumber);
		entries.push_back(e);
	}	
		
}

//Back-Up Entry.h
#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <string>
#include <vector>

class Entry
{
	private:
		//Member Variables
		std::string word;
		int count;
		std::vector<int> linevector;
	
	public:
		Entry(); 
		//Default Constructor
		
		Entry(std::string w, int c, int l); 
		//Overload Constructor
		
		void increaseCount(); 
		//Count Increment
		
		void addLine(int line); 
		//Adds Line
		
		std::string getWord(); 
		//word accessor
	
};

#endif

//Back-Up Entry.cpp

//entry.cpp

#include "entry.h"
#include <iostream>
#include <vector>
using namespace std;

Entry::Entry()
{
	count = 0;
}
Entry::Entry(string w, int c, int l) 
{
	word = w;
	vector<int> linevector;
	linevector.push_back(l);
	count = c;
}

void Entry::increaseCount()
{
	count++;
}

void Entry::addLine(int line)
{
	linevector.push_back(line);
}
string Entry::getWord() 
{
	return word;
}

//Back-Up concordance.h

#ifndef CONCORDANCE_H
#define CONCORDANCE_H

#include "entry.h"
#include <iostream>
#include <string>
#include <vector>
class Concordance
{
	private:
		//Member Variables
		Entry newEntry;
		
		int search(std::string w);
		//searches for word
	
	public:
		Concordance();
		//Default Constructor
		
		Entry getEntry();
		//Entry Accessor
		
		void addWord(std::string aword, int linenumber);
		//Adds Word
		
		void sort(Concordance aconcordance);
		//Sorts Concordance
		
		int size();
		//Returns Number of Entries
		
		friend std::ostream& operator<< (std::ostream &out, Concordance &entries);
		//cout operator overload
	
};

#endif


//Back-Up concordance.cpp

//concordance.cpp

#include "concordance.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Concordance::Concordance()
{
	Entry newEntry("foo", 1, 1);
	vector<Entry> concordance;
	concordance.push_back(newEntry);
}
/*void Concordance::addWord(string aword,int ln)
{
int count = 1;
int linenumber = ln;
Entry e(aword, count, linenumber);
concordance.pushback(e);
}*/
void Concordance::sort(Concordance aconcordance)
{

}
Entry getEntry()
{
	return newEntry;
}
/*int Concordance::size()
{
	size = concordance.size();
	return size;
} */
std::ostream& operator<<(std::ostream& out, Concordance m)
{
	//unsigned int size = m.size();
	
	//for (int b=0; b < m.size(); b++)
	//{
	out << m.getEntry() << endl;
	return out;
	//}
}

//Back-Up concordmain.cpp

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "concordance.h"
#include "entry.h"

using namespace std;

int main(int argc, char* argv[])
{
	Concordance myconcordance;

	ifstream infile("words.txt");
	infile.open(argv[1]);

	int linenumber = 0;
	string aline;
	while (getline(infile, aline))
	{
		istringstream theline(aline);
		linenumber++;

		string aword;
		while (theline>>aword)
		{
			myconcordance.addWord(aword, linenumber);
		}
	}

	//myconcordance.sort();
	cout<<myconcordance;

	return 0;
}