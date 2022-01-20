#include <iostream>
#include <cmath>
using namespace std;

void backtrack(int& c){ 
--c;
if (c < 0)
//b/c if its out of bound the program will crash so exit 
exit (0);
}
// Returns true if the number written in square c is ok.
bool ok(int q[], int c) {
  //this is the helper method

   int adj[8][4]={{-1, -1, -1, -1},
                  {0, -1, -1, -1},
                  {1, -1, -1, -1},
                  {0, 1, 2, -1},
                  {1, 2, 3, -1},
                  {0, 3, 4, -1},
                  {3, 4, 5, -1},
                  {2, 4, 6, -1}};


   for (int i = 0; i < c; i++) 
   // If the number in square c has already been used, return false. So, that we can move c value to a different spot in the 8 squares.
      if (q[i] == q[c])
         return false;
    //checks to see if the neighbors of c the left side are adj
   for (int i = 0; adj[c][i] != -1; i++) 
   // For each neighbor of square c check diagonal for adjs return falses if there are adj #'s to c on its diagonal parts
      if (abs(q[c] - q[adj[c][i]]) == 1) 
         return false;
  //only return true if the value of c is not adj to its neighbours or already used in that location for a different solution
   return true;
}
void printCross(int cross[],int&s) { 

    //print the solution # and add to determine which solution # it is
    cout << "Solution #" << ++s << "\n";
    //first line of # (2 BOXES)
    cout << "   " << cross[0] << "  " << cross[1] << endl;
    //second line of # (4 BOXES)
    cout << cross[2] << "  " << cross[3] << "  " << cross[4] << "  " << cross[5] << endl;
    //third line of # (2 BOXES)
    cout << "   " << cross[6] << "  " << cross[7] <<endl;
}
void solve(int q[], int num) {
  //keep track of the solutions
 
}

int main() {
   int q[8], num = 0;
   q[num] = 1;
   int static s=0;
    while (true){ //backtrack will end loop once solution is found
    while (num >= 0){ //
        num++;
        if (num == 8){ // if all solutions were found print
            printCross(q,s);
            backtrack(num);
        } 
        else {
            q[num] = 0;
        }
        while ( num >= 0){
            ++q[num];
            if (q[num] > 8){ //if no solutions were found in a row
                backtrack(num);
                continue;
            }
            else {
                if (ok(q, num)) { //if number is ok break and go to next
                    break;
                }
            }
        }
    }
}
   return 0;
}