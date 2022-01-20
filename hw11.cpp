#include <iostream>
using namespace std;

class Rat {
    private:
        int n;
        int d;

    public:
        Rat() {
            n = 0;
            d = 1;
        }
        Rat(int i, int j) {
            n = i;
            d = j;
        }
        Rat(int i) {
            n = i;
            d = 1;
        }
        int getN() {  
          return n;    }
        int getD() {  
          return d;     }

        void setN(int i) {
           n = i; }
        void setD(int i) {
           d = i; }    
        Rat operator+(Rat r) {
            Rat t;
            t.n = n * r.d + d * r.n;
            t.d = d * r.d;
            return t;
        }
        Rat operator- (Rat r) {
            Rat t;
            t.n = n * r.d - d * r.n;
            t.d = d * r.d;
            return t;
        }
        Rat operator* (Rat r) {
            Rat t;
            t.n = n * r.n;
            t.d = d * r.d;
           
            return t;

        } 
        Rat operator/ (Rat r) {
            Rat t;
            t.n = n * r.d;
            t.d = d * r.n;
            return t;
            
        }
        int gcd(int n, int d) {
            return d == 0 ? n : gcd(d, n%d);
        }
 
        int reduce(){
            int lowTerms = gcd(n,d);
            n=n/lowTerms;
            d=d/lowTerms;
            if(d<0){
                n=-n;
                d=-d;
            }
        }
      friend ostream& operator<<(ostream& os, Rat r);
      friend istream& operator>>(istream& is, Rat& r);
}; 

ostream& operator<<(ostream& os, Rat r) {
    r.reduce();
    int c=0;
    while(abs(r.n)>=abs(r.d)){
        c++;
        r.n-=r.d;
    }
    if(r.n==0) os << c;
    else if (c==0) os <<r.n<<"/"<<r.d;
    else os << c<< " "<< r.n<<"/"<<r.d << " ";
    return os;
}

int main() {
    
   Rat r1(7, 6);
   Rat r2(2, 7);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   
   return 0;
}