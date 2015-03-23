#include <iostream>
#include <string>
#include <cstdlib>
#include "BogSolver.h"

using namespace std;
//BogLett Constructor
//PRECONDITION:User is creting a new BogLett
//
//POSTCONDITION:BogLett initialized with 'a' char
//		and 0 ints
BogLett::BogLett(){
	c ='a';
	row=0;
	col=0;
}
//BogWord Constructor
//PRECONDITION:User is creating a new BogWord
//
//POSTCONDITION:BogWord initialized with '1' int for numLett
//		and space for 50 letters	
BogWord::BogWord(){
	capacity = origLetterRange;
	numLetts=1;
	letts= new BogLett[capacity];

}
//BogSolver Constructor
//PRECONDITION:User is making a new instance of BogSolver class
//
//POSTCONDITION:The private members, testWord and wordsFound are initialized
//		with abundant space for letters and words
BogSolver::BogSolver(){
	testWord.capacity = origLetterRange;
	testWord.numLetts = 1;
	testWord.letts = new BogLett[testWord.capacity];
	for(int i=0;i<testWord.capacity;i++){
		testWord.letts[i].c='a';
		testWord.letts[i].row=0;
		testWord.letts[i].col=0;
	}
	wordsFound.capacity = origWordRange;
	wordsFound.numWords = 0;
	wordsFound.words= new BogWord[ wordsFound.capacity ];

}
//Destructor
//Clean up behind yourself
BogSolver::~BogSolver(){

	for(int  i=0; i <boardRows; i++){
	   delete[]BoggleBoard[i];
	}
	   delete[]BoggleBoard;

	BogWord* y;
	y = wordsFound.words;
	delete []y;


}

//addWord
//PRECONDITION: A new word has been in the BoggleBoard for insertion
//		 Also established the word is not already in the BogWordList
//POSTCONDITION: If over 2 characters, the word has been deep copied
//		 and   inserted in the private	member, wordsFound.
void BogSolver::addWord  (BogWord word){
	if(word.numLetts<3)
		return;
	BogWord copy;
	copy.numLetts = word.numLetts;
	
	for(int i=0;i<copy.numLetts;i++){
		copy.letts[i].c = word.letts[i].c ;
		copy.letts[i].row = word.letts[i].row;
		copy.letts[i].col = word.letts[i].col;	      
	     }

	wordsFound.words [ wordsFound.numWords ] = copy;
	wordsFound.numWords++;

	return;
}
//getWords
//POSTCONDITION: Returns a pointer to a BogWordList of all the words found
//
BogWordList* BogSolver::getWords(){

	BogWordList* newList = new BogWordList;
	newList->words = new BogWord[ wordsFound.numWords ];
	newList->numWords=0;
	for(int i=0;i<wordsFound.numWords;i++){
		newList->words[i] = copyWord ( wordsFound.words[i] );
		newList->numWords++;
		}

	return newList;

}
//getWords(int len)
//POSTCONDITION: Returns a pointer of a BogWordList of all the words found
//		of length 'len'
BogWordList* BogSolver::getWords(int len){

	int num=0;
	int i;
	for(i=0; i<wordsFound.numWords; i++){
		if (wordsFound.words[i].numLetts == len)
			num++;
	}
	BogWordList* newList = new BogWordList;
	newList->words = new BogWord[num];

	newList->numWords=0;
	int y=0;
	for(i=0; i<wordsFound.numWords;i++){
		if (wordsFound.words[i].numLetts == len){
			newList->words[y] = copyWord ( wordsFound.words[i] );	
			newList->numWords++;
			y++;
			}
	}

	return newList;
}
//copyWord
//PRECONDITION: Hard copy of a word is required
//POSTCONDITION: BogWord is returned with identical values
//		but different addresses
BogWord      BogSolver::copyWord(BogWord tocopy){

	BogWord result;
	result.numLetts = tocopy.numLetts;
	for (int i=0;i<result.numLetts;i++){
	    result.letts[i].c = tocopy.letts[i].c;
	    result.letts[i].row = tocopy.letts[i].row;
	    result.letts[i].col = tocopy.letts[i].col;
	}
	
	return result;
}


//isPrefix
//PRECONDITION:Test if the current testWord is a Prefix within the Dictionary
//
//POSTCONDITION:A Bool is returned if the testword is in the Dictionary or not
//
bool BogSolver::isPrefix (BogWord word){
	
	bool pfx=false;

	string s="";

	for(int i=0;i< word.numLetts; i++){
		s+=word.letts[i].c;		
	}
	s = Qmod(s);
	pfx = dict.isPrefix(s);
	return pfx;
}
//isWord
//PRECONDITION:testWord has been deemed a prefix, is it a Word as well?
//	      
//POSTCONDITION:A Bool is returned if the the word is in the dictionary 
//		
bool BogSolver::isWord(BogWord word){

	bool pfx=false;

	string s="";

	for(int i=0;i< word.numLetts; i++){
		s+=word.letts[i].c;		
	}
	string y= Qmod(s);
	pfx = dict.isWord(y);

	return pfx;
}
//listWords	
//POSTCONDITION: Prints words without Hescott Boggle Format
//
void   BogSolver::listWords(){
	int i, j, k;
	for(i =0; i<wordsFound.numWords;i++){
		k=wordsFound.words[i].numLetts;
		for(j=0; j< k; j++){	
			if( wordsFound.words[i].letts[j].c == 'Q'){
			cout<<"QU";
			k--;
			}
			else
			cout<<wordsFound.words[i].letts[j].c;
			}
			cout<<endl;
		}
	}
//listWords( int len)
//POSTCONDITION: Prints words without HescottBoggle Format
//
void   BogSolver::listWords(int len){
	int i, j, k;
	for(i =0; i<wordsFound.numWords;i++){
	    k=wordsFound.words[i].numLetts;
	    if(wordsFound.words[i].numLetts == len){
		for(j=0; j< k; j++){			
			if( wordsFound.words[i].letts[j].c == 'Q'){
			cout<<"QU";
			k--;
			}
			else		
			cout<<wordsFound.words[i].letts[j].c;
			}
			cout<<endl;
			}
		}
	}
//neighborsarray
//PRECONDITION: The number of neighbors has been established for location(i,j)
//
//POSTCONDITION:A pointer to an array in dynamic memory is returned with 
//		all the neighbors for point i,j
BogLett* BogSolver::neighborsarray(int n, int i, int j){
	BogLett*   neighbors = new BogLett[n];
	int g=0;

		if(valid_coord(i-1, j-1)){
		neighbors[g] = BoggleBoard[i-1][j-1];
		g++;	}	if(valid_coord(i-1, j)){
				neighbors[g] = BoggleBoard[i-1][j];
				g++;	}
		if(valid_coord(i-1, j+1)){
		neighbors[g] = BoggleBoard[i-1][j+1];
		g++;	}	if(valid_coord(i, j-1)){
				neighbors[g] = BoggleBoard[i][j-1];
			 	g++;	}
		if(valid_coord(i, j+1)){
		neighbors[g] = BoggleBoard[i][j+1];
		g++;	}       if(valid_coord(i+1, j-1)){
			        neighbors[g] = BoggleBoard[i+1][j-1];
			         g++;	}
		if(valid_coord(i+1, j)){
		neighbors[g] = BoggleBoard[i+1][j];
		g++;	}	if(valid_coord(i+1, j+1)){
			 	neighbors[g] = BoggleBoard[i+1][j+1];}
	
	 return neighbors;	
}
//neighborRec
//PRECONDITION:testlocation has invoked this recursive function with one of its
//		original neighbors
//POSTCONDITION:The function has recursed through all appropiate neighbors
//		not already in the testWord and its number of letters 
//		is decremented
void BogSolver::neighborRec(BogLett letter){	
	if(testWord.numLetts==testWord.capacity)
	expandtestWord();
	testWord.letts[ testWord.numLetts ] = letter;
	testWord.numLetts++;
	int i = letter.row;
	int j = letter.col;

	if(isPrefix(testWord)){
		if(isWord(testWord)){
			if(!priorWord(testWord)){
			    if(wordsFound.numWords==wordsFound.capacity){
				expandwordsFound();
				}			
				addWord(testWord);
				}			
			}
		int n = num_neighbors(i, j);
		BogLett* nbrs;
		nbrs = neighborsarray(n, i, j);
		for(int g=0; g<n; g++){
			if(notinWord(nbrs[g])){
				neighborRec( nbrs[g] );
				}
			}
	}
	testWord.numLetts--;
}
//notinWord
//PRECONDITION:neighborRec is trying to see if any neighbors are currently
//		in the testWord
//POSTCONDITION:bool is returned whether the given location is in testWord
//
bool BogSolver::notinWord(BogLett letter){

	bool test = true;
	
	for(int i=0; i< testWord.numLetts ;i++){
		if ((testWord.letts[i].c==letter.c)&&
			(testWord.letts[i].row==letter.row)&&
				(testWord.letts[i].col==letter.col))
			test=false;
		}
	return test;

}
//numWords
//POSTCONDITION: returns an int of the number of words found in BoggleBoard
//
int BogSolver::numWords(){

	return wordsFound.numWords;
}
//numWords(int len)
//POSTCONDITION:returns an int of the number of words found in BoggleBoard
//		of length len
int BogSolver::numWords(int len){
	int y=0;

	for(int i=0;i<wordsFound.numWords;i++){
		if (wordsFound.words[i].numLetts == len)
			y++;
	}


	return y;
}
//num_neighbors
//PRECONDITION:Need to establish number of neighbors around location
//		in order to create neighbor array
//POSTCONDITION: Integer is returned of the number of valid coordinates
//		surrounding a location
int  BogSolver::num_neighbors(int i, int j){


   int rows[8]= {i-1,i-1,i-1,i,i,i+1,i+1,i+1};
   int cols[8]= {j-1,j,j+1,j-1,j+1,j-1,j,j+1};
   int y= 0;

	for(int x=0; x<8 ;x++){
	  if(valid_coord( rows[x], cols[x] ) )
		y++;
	}

	return y;

}
//printWords
//PRECONDITION:BoggleBoard has been solved and results are to be printed in HBF
//
//POSTCONDITION:Contents of wordFound have been coutted in HBF
//
void   BogSolver::printWords(){
	int i, j, k;
	for(i =0; i<wordsFound.numWords;i++){
		cout<<"< ";
		k = wordsFound.words[i].numLetts;
		for(j=0; j< k; j++){
			if(wordsFound.words[i].letts[j].c!='Q')			
				cout<<wordsFound.words[i].letts[j].c<<" ";
			if(wordsFound.words[i].letts[j].c=='Q'){
				cout<<"QU"<<" ";
				k--;
			}
			cout<<wordsFound.words[i].letts[j].row<<" ";
			cout<<wordsFound.words[i].letts[j].col<<" ";
			
			}
			cout<<">"<<endl;
			}
	cout<<"< >"<<endl;

	}
//printWords(int len)
//PRECONDITION: BoggleBoard has been solved and those results of a given length
//		are to be printed in HBF
//POSTCONDITION:Those contents of the appropriate length have been coutted in HBF
//
void   BogSolver::printWords(int len){
	int i, j, k;
	for(i =0; i<wordsFound.numWords;i++){
	    if(wordsFound.words[i].numLetts==len){
		cout<<"< ";
		k = wordsFound.words[i].numLetts;
		for(j=0; j< k; j++){			
			if(wordsFound.words[i].letts[j].c!='Q')			
				cout<<wordsFound.words[i].letts[j].c<<" ";
			if(wordsFound.words[i].letts[j].c=='Q'){
				cout<<"QU"<<" ";
				k--;
			}
			cout<<wordsFound.words[i].letts[j].row<<" ";
			cout<<wordsFound.words[i].letts[j].col<<" ";
			
			}
			cout<<">"<<endl;
			}
		}
	cout<<"< >"<<endl;

	}
//priorWord
//PRECONDITION:Need to see if a word has already been found so it isn't
//		reinserted in the BogWordList
//POSTCONDITION:A bool is returned as to wheither a word already exists
//		in wordsFound
bool BogSolver::priorWord(BogWord word){
	int i,k;
	string comp="";
	for(i=0;i<word.numLetts;i++){
		comp+=word.letts[i].c;
	}
	string alreadyfound="";
	
	bool result=false;
	
	for(i=0;i<wordsFound.numWords;i++){		
		for(k=0;k<wordsFound.words[i].numLetts;k++){
			alreadyfound+=wordsFound.words[i].letts[k].c;
		}
		if (comp==alreadyfound){
			result = true;
			return result;
		}
		alreadyfound="";
}
	return result;
}
//readDict
//PRECONDITION:User is cinning a list of words terminated by sentinel '.'
//
//POSTCONDITION:A true bool is returned when the process is completed
//
bool BogSolver::readDict(){

   string word;
   bool read = false;
   int h;	
   cin >> word;
   while (word!="."){ 
	 h = word.length();
	 for (int n=0 ; n< h ; n++){
 	     word[n] = toupper( word[n] );
 	}
        dict.insert(word);
	cin >> word;
 }
  read=true;

  return read;
}
//readBoard
//PRECONDITION:Dictionary has been read in. Board is formated by two ints
//		and a series of strings
//POSTCONDITION: A true bool is returned when the process is completed
//
bool BogSolver::readBoard(){

	int row, col;
	cin>>row>>col;
	boardRows = row;
	boardCol = col;
    	BoggleBoard = new BogLett*[row];
	bool read = false;
	
	int i=0;
	int j;
	string line;
	while(i<row){		
            	BoggleBoard[i] = new BogLett[col];
		cin>>line;
		for(j=0;j<col;j++){
		   line[j] = toupper(line[j]);
		   BoggleBoard[i][j].c = line[j];
	           BoggleBoard[i][j].row  = i;			           
		   BoggleBoard[i][j].col = j;
 		}
      		i++;
      }
       read=true;
       return read;	
}
//solve
//PRECONDITION:Board and Dictionary have been read in
//
//POSTCONDITION:A bool is returned denoting that the Board has been solved
//
bool BogSolver::solve(){
	bool solved = false;
	for(int i=0; i<boardRows; i++){
		for(int j=0; j<boardCol; j++){
		testlocation(i, j);
			}
		}
	listQadjust();
	solved=true;
	return solved;     

}
//testlocation
//PRECONDITION: Solving has begun. This function will work from each individual
//		location on the board to work out solutions from there
//POSTCONDITION:
//
void BogSolver::testlocation(int i, int j){
	
	testWord.letts[ testWord.numLetts -1 ].c = BoggleBoard[i][j].c;	
	testWord.letts[ testWord.numLetts -1 ].row = i;
	testWord.letts[ testWord.numLetts -1 ].col = j;

	int n = num_neighbors(i, j);
	BogLett* nbrs;
	nbrs = neighborsarray(n, i, j);	

	for(int g=0; g<n; g++){
		neighborRec( nbrs[g] );
	}



}
//valid_coord
//PRECONDITION: Need to see if a given coordinates are within Board's confines
//
//POSTCONDITION:Bool is returned denoting whether location is in fact on Board
//
bool BogSolver::valid_coord(int i, int j){
	bool val = true;
	if(  (i<0) || (i>= boardRows) || (j<0) || (j>=boardCol) )
	     val = false;

	return val;
}
//Qmod
//PRECONDITION: Need to see if a string needs adjustment to immitate 'Qu' tile
//POSTCONDITION:If the string contains a Q, it is now modified to have QU in 
//		that location
string BogSolver::Qmod(string s){

	string result="";
	int j = s.length();
	for(int i=0;i<j;i++){
		if(s.at(i)!='Q')
			result+=s.at(i);
		else if(s.at(i)=='Q'){
			result+='Q';
			result+='U';
		}
	}
	
	return result;
}
//listQadjust
//PRECONDITION: Solve has been performed
//POSTCONDITION: The numLetts in any word with a Q/QU has been modded
void BogSolver::listQadjust(){

	int i,j,k;

	for(i=0;i<wordsFound.numWords;i++){
		k = wordsFound.words[i].numLetts;
		for(j=0 ; j<k ; j++){
			if(wordsFound.words[i].letts[j].c=='Q'){
				wordsFound.words[i].numLetts++;
					}
				}
		}
}
//expandwordsFound()
//PRECONDITION: wordsFound has equal capacity and numWords
//POSTCONDITION: wordsFound has twice as much capacity
void BogSolver::expandwordsFound(){

	BogWordList newList;
	newList.numWords = wordsFound.numWords;
	newList.capacity = (wordsFound.capacity*2);

	newList.words = new BogWord[newList.capacity];

	for(int i=0; i<wordsFound.numWords;i++){
		newList.words[i] = copyWord(wordsFound.words[i]);
	}
	BogWord* y;
	y = wordsFound.words;
	delete []y;

	wordsFound = newList;
}
//expandtestWord()
//PRECONDITION: testWord has equal capacity and numWords
//POSTCONDITION: testWord has twice as much capacity
void BogSolver::expandtestWord(){

        BogWord newWord;
	newWord.numLetts = testWord.numLetts;
	newWord.capacity = (testWord.capacity*2);
	
	newWord.letts = new BogLett[newWord.capacity];
	int j=newWord.numLetts;
	for(int i=0;i<j;i++){
	    newWord.letts[i].c=testWord.letts[i].c;
	    newWord.letts[i].row=testWord.letts[i].row;
	    newWord.letts[i].col=testWord.letts[i].col;
	   }
	for(j=newWord.numLetts; j<newWord.capacity; j++){
	    newWord.letts[j].c='a';
	    newWord.letts[j].row=0;
	    newWord.letts[j].col=0;
	}
	BogLett* y;
	y = testWord.letts;
	delete[]y;
	testWord = newWord;	

}




