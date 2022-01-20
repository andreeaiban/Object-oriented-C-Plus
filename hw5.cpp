#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool validSpot(int q[], int c) {
// Checks a queen based on pos & going through the chess board for # in which a queen may be placed 
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i) //checks pos of other queens & checks if its a valid spot
         return false;
   return true;
}
//Print the solution of the 8 Queens w/ Board & The number of the Solution
void printBoard(int q[]) {
   static int solution = 0;
   solution++;
   cout << "Solution Number: " << solution <<endl;
   cout<< "Display: " << endl;

  for(int i=1; i<=8; i++)
  {
    for(int j=1; j<=8; j++)
    {
      if(q[i]==j) //places queen
        cout << "1";
      else //no queen is placed
        cout << "0";
    }
    cout << endl;
  }
}

int main() {

  //Declare & Initializing
   int q[8] = {};   
   int c = 0;      
 
  while (c >= 0) { 
  // End the loop if you backtrack from the first column
      if (c == 7) {         // If you are in the last column, print and backtrack
         printBoard(q);
         --c;
      }
      else                  // Otherwise, move to one before the first row of the next column
         q[++c] = -1;

      while (c >= 0) {
         ++q[c];            // Move to the next row
         if (q[c] == 8)     // If you have passed the end of the column 
            --c;            //Backtrack
         else if (validSpot(q, c)) // If the location spot, is valid, break go back to the beginning
            break;
      }
   }
   return 0;
}