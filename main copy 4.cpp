#include <iostream>
using namespace std;
string add(string a, string b){
  string result,empty,t;
  //larger number will always be b & a will be smallest
  if (a.length() > b.length()) {
        t = a; 
        a = b; 
        b = t; 
  }
  string str = ""; 
  int n1 = a.length(), n2 = b.length(); 
  int diff = n2 - n1; 
  //a has to add the diff amount of 0 to the front of the string
  string zero;
  for(int s=0; s<diff;s++)
  {
    zero=zero+"0";
  }
  a=zero+a;
  int carry; 
  int cur;
  string curr;
  for (int i=n1-1; i>=0; i--) 
    {   carry = 0;
        int sum = ((a[i]-48) +  (b[i]-48) + carry); 
        if(i!=0){
        cur=sum%10;
        carry = sum/10;
        str=str+(char)cur;
        }
        else 
        cur=cur+carry;
        str=str+(char)cur;
    } 
  
   
  /*
    empty=""; 
   for(int i=str.size()-1;i>=0;i--) 
    empty+=str[i]; 
    str=empty;
    */
  return str;

}
int main() {
  bool loop= false;
  string added;

  while(loop!=true){
  string a, b;
  cout<<"Enter a number for A ";
   cin>>a;
   if(a.compare("done")==0){
     break;
   }
   cout<<"Enter a number for B ";
   cin>>b;
   added=add(a,b);
   cout<<"The result it "<<added<<endl;
  }
  return 0;
}