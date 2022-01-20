#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
  //declaring and initializing
  int q[8];
  int c = 0;
  int numOfSol = 1;

  //first pos is 0
  q[0] = 0;

nextCol:
  //move to next column
  c++;

  //check to see if it passed last column
  if(c==8)
    goto print;

  q[c] = -1;

nextRow:
  q[c]++; //move up a row

  //check to see if it passed last row
  if(q[c]==8)
    goto backtrack;

  for(int i=0; i<c; i++)
    if(q[i]==q[c] || (c-i)==abs(q[c]-q[i]))
      goto nextRow;


  goto nextCol;

backtrack:
  c--; //go back a column
  if(c==-1) //end if out of bounds
    return 0;
  goto nextRow;

print:
  //prints out number of the solution
  cout << "Solution #" << numOfSol << ": " << endl;

  for(int i=0; i<8; i++)
  {
    for(int j=0; j<8; j++)
    {
      if(q[i]==j) //places queen
        cout << "1";
      else //no queen is placed
        cout << "0";
    }
    cout << endl;
  }

  //increment solutions by one
  numOfSol++;

  goto backtrack;
}