#include <iostream>
#include <string>
#include <cstdlib>
#ifndef BOGVALIDATOR_H
#define BOGVALIDATOR_H
#include "BogSolver.h"
using namespace std;

struct wordNode{
	wordNode();
	string word;
	bool   status;
	wordNode* next;

};


class BogValidator
{
public:
BogValidator();
// constructor
~BogValidator();
// destructor
bool readDict();
// read in a dictionary
bool readBoard();
// read in a board
bool isValid(string s);
// validates one word
void checkWords();
// validates cin


private:

Dictionary dict;

BogSolver solver;
//linked list of provided answers
wordNode* inputlist; 

void print();

bool previousCorrect(string s);

};


#endif
