#include <iostream>
#include <string>
#include <cstdlib>
#include "dictionary.h"

using namespace std;
//Constructor
//Initializes the state of the class Dictionary
//The Node pointer and trie head, root, is set to new Node
//This Node pointed at by root is designated as not a word.
//The array of Node pointers within the root Node are set to NULL
Dictionary::Dictionary(){

	root = new Node;

	root->isWord = false;

	for (int i=0; i< range; i++){
		root->alpha[i] = NULL;
	}
}
//Node Constructor
//Initializes the pointers of 'alpha' to NULL
Node::Node()
{
	isWord = false;
	for (int i = 0; i < range; i++) {
		alpha[i] = NULL;
	}
}

//isPrefix
//Checks to see if a given string is a prefix within the Dictionary Trie
//The input string is cleaned up.  Then checks to see if the Trie is empty
//for handling cases of the empty string.  Because an empty string can only
//not be a prefix within an empty trie, a false bool is returned if both the
//input string and the trie are empty.  A while loop then checks the presence
//of the input string.  
bool Dictionary::isPrefix(string s){
	s = cleanup(s);	
	Node* iter = root;
	int i = 0;
	bool result=false;
	bool emptyset=true;
	int length = s.length();
	for(int k=0;k<range;k++){
		if (iter->alpha[k] !=NULL) 
			emptyset = false;
		}
	if ((length==0) && (emptyset==true) && (iter->isWord!=true)){
		//cout<<result<<endl;
		return result;}		

	while (i < length ){
		if (iter->alpha[ s.at(i) - 'a'] == NULL){
			//cout<<result<<endl;
			return result;}		
		iter = iter->alpha [ s.at(i) - 'a'];
		i++;
	}
	result = true;
	//cout<<result<<endl;
	return result;
}
//isWord
//Checks to see if an input string exists as a word in the Dictionary
//The input string is first cleaned up.  An iterator starting from the root
//works through an available path in the Trie, if available.  If the pointer
//makes it through the spelling of the word in the trie, this Node is then 
//checked as a word with the isWord bool of the Node
bool Dictionary::isWord(string s){


	s = cleanup(s);


	Node* iter = root;
	int i = 0;
	bool result=false;
	int length = s.length();

	while (i < length){

		if (iter->alpha[ s.at(i) - 'a'] == NULL){
//			cout<<result;
			return result;
		}		
	
		iter = iter->alpha [ s.at(i) - 'a'];
		i++;
	}
		
		result = iter->isWord;

	return result;
}
//insert
//Inserts words in the dictionary. Returns true bool if inserted.
//Climbs down in Trie by each individual letter of the string
//creating new Nodes along the away as needed.  The isWord bool
//of the final Node is set to true. Once this is done, the result
//is set true as well and returned.
bool Dictionary::insert(string s){

	s = cleanup(s);

	Node* iter = root;
	int i = 0;
	bool result = false;
	int length = s.length();
	while (i < length){
		if (iter->alpha[ s.at(i) - 'a']==NULL){
			iter->alpha[ s.at(i) - 'a'] = new Node;
		}
		iter = iter->alpha [ s.at(i) - 'a'];
		i++;
	}

	iter->isWord = true;

	if (iter->isWord)
		result = true;
	//cout<<result<<endl;
	return result;
}
//cleanup
//Cleans up text from input for all other functions
//First all uppercase characters are made lowercase
//Afterwards, only the alphabetical characters are copied
//from one string into another which is returned
string Dictionary::cleanup(string word){
	string newWord= "";
	int length = word.length();
	 for (int n=0 ; n< length ; n++){
  	    word[n] = tolower( word[n] );
 	}

	 for (int n=0 ; n< length ; n++){
		if ((word[n] >= 'a') && (word[n] <= 'z')){
			newWord +=word[n];
		}
		}

	return newWord;

}



