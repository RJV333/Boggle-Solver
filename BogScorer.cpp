#include <iostream>
#include <string>
#include <cstdlib>
#include "BogScorer.h"

using namespace std;


//BogScorer()
//PRECONDITION:User is constructing an instance of BogScorer
//POSTCONDITION: linked list set NULL, other private values '0'
BogScorer::BogScorer(){

	answerList=NULL;
	numvalidWords=0;
	totalPoints=0;
}
//answerNode()
//PRECONDITION: Initialized an answerNode
//POSTCONDITION: empty strings, 0 score, nullpointer
answerNode::answerNode(){

	word="";
	status="";
	
	score=0;
	next=NULL;

}
//readIn
//PRECONDITION: User has result chart to read in
//POSTCONDITION: Private linked list, answerList, is populated with
//		the words and their validity, still not scored or tallied
void BogScorer::readIn(){

     string status, word;
     cin>>status;
     cin>>word;
     answerList = new answerNode;
     answerList->status = status;
     answerList->word = word;
     answerNode* i = answerList;

     cin >> status;
       while (!cin.eof( )){
         cin>>word;
	 i->next = new answerNode;
         i = i->next;
	 i->word = word; 	
	 i->status = status;
	 cin >> status;
	}

	return;
}
//score
//PRECONDITION: chart has been read in and populated into answerList linkedList
//POSTCONDITION: All valid words have been assigned a point value based on 
//		their length
void BogScorer::score(){
	answerNode* i= answerList;
	int s;
	while(i!=NULL){
	   s = (i->word).length();	
		if( i->status != "NO"){
	 	   if((s==3)||(s==4)){
	 	   i->score = 1;
			}
		   if(s==5){
		   i->score = 2;
			}
		   if(s==6){
		   i->score = 3;
		        }
		   if(s==7){
		   i->score = 5;
			}
		   if(s>=8){
		   i->score = 11;
			}
		}
		   i = i->next;
		}
	return;
}
//tally
//PRECONDITION: chart has been read in, words have been scored
//POSTCONDITION: the number of valid words and total points have been
//		recorded in their respective private data members
void BogScorer::tally(){

	answerNode* i = answerList;

	while(i!=NULL){
		if(i->status=="OK"){
			numvalidWords++;
			totalPoints = totalPoints + i->score;
		}
		i = i->next;
	}


}
//print
//PRECONDITION: Tally has reviewed number of valid words and their score
//POSTCONDITION: Scorer prints individual word score, word chart, total valid
//		words, and total points
void BogScorer::print(){

	answerNode* i= answerList;

	while(i!=NULL){
	cout<<i->score<<" "<<i->status<<" "<<i->word<<endl;
	i=i->next;
	}

	cout<<numvalidWords<<" words "<<totalPoints<<" points";

}

