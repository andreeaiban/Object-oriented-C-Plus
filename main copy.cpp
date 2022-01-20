#include <iostream>
using namespace std;
void print(int current[],int& index){
  cout << current[0] << current[1] << current[2] << endl;
   index=2;
}
void count( int begin[], int end[] )
{
    int index, current[3] = { begin[0], begin[1], begin[2] };
    print(current, index);

    while(true){
    while(true){
    if ( current[index] < end[index] - 1 ) {
            current[index]++;
            //print(current, index); doesn't workkkkkkkk only gets half the inputs
            break;       
        }
        else if ( index > 0 ) {
            current[index] = begin[index];
            index--;
            continue;;
        }
        else return;   
        }
        print(current, index);
    } 
}

int main( )
{
    int begin[3] = { 0, 0, 0 };
    int end[3] = { 2, 4, 3 };

    count(begin, end);

    return 0;
}
