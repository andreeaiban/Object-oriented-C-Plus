#include <iostream>
using namespace std;


string add(string a, string b){
  string result,empty;
  if (a.length() > b.length()) 
        swap(a, b); 
  string str = ""; 
 
  int n1 = a.length(), n2 = b.length(); 
  int diff = n2 - n1; 

  int carry = 0; 

  for (int i=n1-1; i>=0; i--) 
    { 
        int sum = ((a[i]-'0') + 
                   (b[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((a[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
  
    empty=""; 
   for(int i=str.size()-1;i>=0;i--) 
    empty+=str[i]; 
    str=empty;
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