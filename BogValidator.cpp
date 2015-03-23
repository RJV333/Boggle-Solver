#include <iostream>
#include <string>
#include <cstdlib>
#include "BogValidator.h"

using namespace std;
//Constructor
BogValidator::BogValidator(){

	inputlist = NULL;
}

//Destructor
//Clean up behind yourself
BogValidator::~BogValidator(){

	while(inputlist!=NULL){
		wordNode*i = inputlist;
		inputlist=inputlist->next;
		delete i;
	}
}
//wordNode Constructor
//Sets empty word, false status, and NULL pointer
wordNode::wordNode(){
	word = "";
	status = false;
	next=NULL;

}
//readDict()
//PRECONDITION: User has list of words to provide solver
//POSTCONDITION: solver has read those contents up til '.'
bool BogValidator::readDict(){

     return solver.readDict();

}
//readBoard()
//PRECONDITION: User has Board for solver formatted to assignment
//POSTCONDITION: solver has read board of specificed dimensions
bool BogValidator::readBoard(){

      return solver.readBoard();

}
//checkWords()
//PRECONDITION: Dictionary and Board have been read
//POSTCONDITION: The user input 'answers' have been evaluated
//		and printed back out.
void BogValidator::checkWords(){
    solver.solve(); 
 //   solver.listWords();

     string y;
     cin>>y;
     inputlist = new wordNode;
     inputlist->word = y;
     wordNode* i = inputlist;

     cin >> y;
       while (!cin.eof( )){
         
	 i->next = new wordNode;
         i = i->next;
	 i->word = y; 	
	cin >> y;
	}
	i = inputlist;
	while(i !=NULL ){
	i->status = isValid( i->word );
	i = i->next;
	 }
	print();
}
//isValid
//PRECONDITION: Function is reading in user answer. solver has solved Board
//POSTCONDITION: bool is returned denoting OK or NO for each user word
bool BogValidator::isValid(string s){
     bool result = false;
     int wordlength = s.length();
     string compare;
     int i,j,m;
     BogWordList* answerlist = solver.getWords(wordlength);  
     int numberwords = answerlist->numWords;
     for (i=0; i<numberwords; i++){
	compare="";
	m = wordlength;
	for (j=0;j<m;j++){
	     compare += answerlist->words[i].letts[j].c;
             if(answerlist->words[i].letts[j].c=='Q'){
		compare+='U';
                m--;
		}
	    }
	if ((compare == s )&&(!previousCorrect(s))){ 
	    result = true;
	    return result;
	}	
	}	
	return result;
}
//print
//PRECONDITION: Board has been solved and compared to user answers.
//		each answer is OK or NO
//POSTCONDITION:  Results are coutted in proper format
void BogValidator::print(){

	wordNode* i = inputlist;
	int y=0;
	while(i!=NULL){
	   i = i->next;
	   y++;
	  }
	i = inputlist;

	while(i!=NULL){
	      if(i->status == true )
		cout<<"OK ";
	      else
		cout<<"NO ";

	      cout<<i->word<<endl;

	      i = i->next;
	}
}
//previousCorrect
//PRECONDITION: Answer has been found in Boggle Board. Was it a prev answer?
//POSTCONDITION: Bool returned whether it is a previous answer
bool BogValidator::previousCorrect(string s){
	bool result=false;

	wordNode*i=inputlist;

	while(i!=NULL){
		if (i->word==s){
			if (i->status==true){
			 result=true;
			}
		}
		i=i->next;
	}

	return result;

}
