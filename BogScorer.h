#include <iostream>
#include <string>
#include <cstdlib>
#ifndef BOGSCORER_H
#define BOGSCORER_H

using namespace std;

struct answerNode{
	answerNode();
	string  word;
	string    status;
	int     score;
	answerNode* next;

};

class BogScorer{

	public:
		//constructor
		BogScorer();
		//reads in result chart
		void readIn();
		//scores entries
		void score();
		//tallies valid words and total points
		void tally();
		//prints
		void print();




	private:
		//list of entries
		answerNode* answerList;
		//amount of valid answer
		int         numvalidWords;
		//total points accumulated
		int	    totalPoints;
	

};



#endif
