#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>


using namespace std;

//This constant integer tracks the number of indices of Node pointers
//within each Node of the Trie.  One for each letter of the alphabet
const int range = 26;

//Each Node in the Trie is surprisingly simple. It contains a bool
//denoting if its location denotes a word and an array of pointers
//to other Nodes corresponding to the 26 letters of the alphabet
struct Node{
	Node();
	bool isWord;
	Node* alpha[range];
};

class Dictionary{

	public:
		//Constructor
		Dictionary();
		//Is a given string a prefix of a word in the Dionctary?
		bool isPrefix(string s);
		//Is a given string a word in the Dciontary?
		bool isWord(string s);
		//Inserts string in Dictionary Trie
		bool insert(string s);

	private:
		//cleans up strings
		string	cleanup(string s);
		//root of the Trie
		Node* root;


};


