#include <iostream>
#include <string>
#include <cstdlib>
#ifndef BOGSOLVER_H
#define BOGSOLVER_H
#include "BogWordList.h"
#include "dictionary.h"

using namespace std;

	const int origLetterRange = 45;
	const int origWordRange = 500;


class BogSolver
{
	public:
		BogSolver();
		~BogSolver();
		bool readDict();
		bool readBoard();
		bool solve();			//search board ofr words in dic
		int numWords();			//returns number of words found
		int numWords(int len);		//number of words of length len
		BogWordList* getWords();	//returns all words found
		BogWordList* getWords(int len); //returns words of length len
		void printWords();		//print all words in HBF
		void printWords(int len);	//print len-length words in HBF
		void listWords();		//print just the text, no coords
		void listWords(int len);	//just the text, no coords
	private:
		Dictionary dict;		//must use a Dictionary
		//other private methods or data may appear here
		BogLett**  BoggleBoard;
		int        boardRows;
		int	   boardCol;

		int	   num_neighbors(int i, int j);
		bool	   valid_coord(int i, int j);
		BogLett*   neighborsarray(int n, int i, int j);

		void	   testlocation(int i, int j);
		void       neighborRec(BogLett p);

		BogWord	   testWord;

		bool	   isPrefix (BogWord word);		
		bool	   isWord   (BogWord word);	
		void       addWord  (BogWord word); 

		BogWordList    wordsFound;
		
		bool       priorWord(BogWord word);
		bool	   notinWord(BogLett l);

		string	   Qmod(string s);
		void	   listQadjust();
		
		BogWord    copyWord( BogWord tocopy);
		void	   expandwordsFound();
		void	   expandtestWord();

};



#endif
