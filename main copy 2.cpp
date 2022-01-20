#include <iostream>
#include <cmath>
using namespace std;

int main(){

//Declare & Initializing
 int q[8];  
 int solution = 1;
 int c = 0;

 //Start at pos 0 of the 1D array of queens
   q[0] = 0;

 //Move through the col of the chess board
  upCol:
     c++;
     //Check if passed out of bound
     if(c==8)
     goto printboard;
    //Restart col, go to the 1st pos
    q[c]=-1;

  //Move through the row of the chess board
rightRow:
  q[c]++;
  //Check if passed out of bound
  if(q[c]==8)
  goto backtrack;

// Placing a queen based on pos & going through the chess board for # in which a queen may be placed 
for(int i=0; i<c; i++)
    if(q[i]==q[c] || (c-i)==abs(q[c]-q[i]))
      goto rightRow;

goto upCol;

backtrack:
 c--; //go back a column
  if(c==-1) //Check 1st if out of bounds of the chess
    return 0; //terminate the program

  goto rightRow; //move right row

//Print the solution of the 8 Queens w/ Board & The number of the Solution
printboard:

//prints out number of the solution
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

  //Since a solution was printed we keep track of it and update the number of solutions with this:
  solution++;

  //find another solution
  goto backtrack;

}