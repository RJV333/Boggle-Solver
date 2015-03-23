#include <iostream>
#include <string>
#include <cstdlib>
#include "BogScorer.h"

int main(){
BogScorer sc;

sc.readIn();
sc.score();
sc.tally();
sc.print();
return 0;

}
