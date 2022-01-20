#include <iostream>
#include <cmath>
using namespace std;
/*.  STABLE MARRIAGE
bool ok(int q[], int c) {
   static int mp[3][3] = { {0,2,1},  // 0  Men's preferences
                           {0,2,1},  // 1
                           {1,2,0}}; // 2
   static int wp[3][3] = { {2,1,0},  // 0  Women's preferences
                           {0,1,2},  // 1
                           {2,0,1}}; // 2

   // Check for conflicts between man#c's marriage and previous marriages.
   for (int i = 0; i < c; ++i) {                                    // For each previous man#i, if
      if (q[i] == q[c]                                              // man#i and man#c are married to the same woman OR
         || mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]  // man#i and man#c's wife like each more than their own spouse OR
         || mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) // man#c and man#i's wife like each more than their own spouse,
         return false;                                              // return false.
   }
   return true;
}
void print(int q[]) {
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}
int main() {
   int q[3] = {};
   int c = 0;
   while (c >= 0) {
      if (c == 2) {
         print(q);
         --c;
      }
      else
         q[++c] = -1;
      while (c >= 0) {
         ++q[c];
         if (q[c] == 3) 
            --c;
         else if (ok(q, c))
            break;
      }
   }
   return 0;
}
*/
//FANCY QUEENS:
// Returns true if the queen in column c is ok
bool validSpot(int q[], int c) {
// Checks a queen based on pos & going through the chess board for # in which a queen may be placed 
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i) //checks pos of other queens & checks if its a valid spot
         return false;
   return true;
}
void printBoard(int q[]){
  static int solution = 0;
   solution++;
   cout << "Solution Number: " << solution <<endl;
   cout<< "Display: " << endl;

   typedef char box[5][7];   // box is now a data type: a 5x7 2D array of characters
    box bb, wb, *board[8][8]; // bb and wb are boxes (5x7 arrays).  board is an 8x8 array of pointers to boxes.
    

                             // You don't have to clean up the board after printing, because it's not static,
                             // so it'll be reinitialized the next time you call the funtion.

    // Fill in bb (black box) and wb (white box).  They each represent a square of the chessboard.
   // You only need to create one of each, since the chessboard can contain many pointers to the same box.
   char a= 'x';

   for (int i=0; i<5; i++)
      for (int j=0; j<7; j++) {
         bb[i][j] = ' ';
         wb[i][j] = 'o';
      }
      //white queen
       static box wq = { {' '  ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' },
                     {' ' ,a,' ' ,a,' '  ,a,' ' },
                     {' ' ,a,a,a,a,a,' '  },
                     {' ' ,a,a,a,a,a,' '  },
                     {' ' ,' ' ,' ' ,' ' ,' '  ,' '  ,' '  } };
      //black queen
       static box bq = {{ 'o','o','o','o','o','o','o'},
                     {a,' ',a,' ',a,' ',a},
                     {a,' ',' ',' ',' ',' ',a},
                     {a,' ',' ',' ',' ',' ' ,a},
                     {'o','o','o','o','o','o','o'} };

     // Fill board with pointers to bb and wb in alternate positions.
    // Fill board with pointers to bb and wb in alternate positions.
     for(int i=0; i<8; i++)
      for(int j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;
    // Set up the current solution on the chessboard by placing pointers to bq and wq in the appropriate squares.
    // Place black queens on white squares and white queens on black squares, so that you will be able to see them when printing.
     for(int i=0; i<8; i++)
        if((i+q[i])%2 == 0)
         board[q[i]][i] = &bq;
      else
         board[q[i]][i] = &wq;

    // Print upper border
     for (int i=0; i<7*8; i++)
       cout << '_';
       cout << "\n";

       // Print the board
   for (int i=0; i<8; i++)          // for each board row
      for (int k=0; k<5; k++) {     // for each box row
         cout << char(179);
         for (int j=0; j<8; j++)    // for each board column
            for (int l=0; l<7; l++) // for each box column
               // board[i][j] is the box pointer in the ith row, jth column of the board.
               // *board[i][j] is the box being pointed to.
               // (*board[i][j])[k][l] is the kth row, lth column of the box.
               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      }

   // Print lower border
   cout << " ";
   for (int i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}
int main(){
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