#include <iostream>
#include <iostream>
#include <cmath>
using namespace std;
typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b) {
// area += height * width, 
// where width = 0.0001, height = f(x) <= here choose the midpoint f(x+0.0001/2) is more accurate
double m = 0, area = .0001;
    for(double x = a + area/2; x < b; x += area)
//loop x from a to b, each time x increments by the width of the rectangle  
     m += f(x) * area;
    return m;//return area;
}
//since you can't do power in c++ you use these functions for x^of something 
double line(double x) {
   return x;
}
double square(double x) {  
   return x*x;
}
double cube(double x) { 
   return x*x*x;
}
int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;   // output: 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // output: 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // output: 156
  return 0;
}