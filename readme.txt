A concise guide to the methodology of my programs

./bbsolver

Firstly, this program incorporates the dictionary class, and the assignments 
formal structs, BogWord, BogLett, and BogWordList, in the BogWordList.h file.

The main file works in the following way.
1- Creating an instance of the BogSolver class
2- reading the dictionary in this BogSolver
3- reading in the board
4- SOLVE- THE HEART OF THE PROGRAM
   Within the BogSolver class are the following private members
a- The BoggleBOard
b and c- Ints marking the number of rows and columns, boardRows, boardCol
d, e, and f- num_neighbors, valid__coord, and neighborsarray are used to 
	    an array of coordinate neighbors for a given location for recursion
g, h- testWord and wordsFound are private members used to test individual words
      and then store them when they discovered as previously undiscovered words

    With this in mind, solve then performs the function testlocation for every
individual point on the BoggleBoard. At each one of these points test location 
utilizes the recursive function, neighborRec, on all valid neighbors around
this point. Essentially, as the programs builds up function calls on the stack 
so too is testWord augmented when a function call of neighborRec is stack on
its previous invocation, and decremented when it leaves that specific call.
neighborRec knows that it should only continue this recursive process if
testWord at that given point is a prefix within the dictionary.  If it is,
testWord is tested as a word within the dictionary.  And another neighbor
array is called for a further instance of recursion.
5- The found words of wordsFound are then printed in Hescott Boggle Format

./bbchecker

This program incorporates all the previous classes required in BogSolver 
AS WELL AS the BogSolver class itself

The main file works in the following way
1- Creating an instance of the BogValidator class
2- reading in the dictionary with the use of its private BogSolver member
3- reading in the board with the use its private BogSolve (solver)
4- CHECKWORDS- THE HEART OF THE PROGRAM
  a) The private data member inputlist takes in all the answers provided
	by the user and assembles them in a linked list
	Each Node has the word, and a 'status' bool denoting the legitimacy
	of the answer
  b) an iterator then passes through this list checking the validity of
     each answer, returning a bool that is placed in the Node's 'status'
  c) the private function, print, then iterates through this list printing
     an OK for Nodes with a true status, NO for those with a false status
     as well as the string content of each word.

./bbscorer

The simplest program of all, this requires no external classes to its own
which is called BogScorer

The main file works in the following way
1-  readin() The chart of words and their validity is read in and stored in a 
   linked list, which is the private data member, answerlist
   answerlist is composed of answerNodes. answerNodes contain two strins
   for their word and their status, and int for its point value, and a
   pointer to a subsequent node.
2-  score() Then iterates through this answerList, assigning points to each
   Node based on the status of each Node and the length of its word
3- tally() Then iterates through this answerList once more, tallying up the
   total number of valid words and total points, storing them in two private
   data members, numvalidWords, and totalPoints.
4- Print() Then iterates through the list once more, printing each answerNode's
   points, status, and word in that order, listing beneath it the total number of
   valid words and the total number of points
