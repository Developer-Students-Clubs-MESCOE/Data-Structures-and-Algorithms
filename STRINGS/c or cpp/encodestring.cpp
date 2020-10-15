/*This program converts a normal string into a encode string*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
string decode = "abcdefhijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string code = "ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihfedcba";	
string input;
string output="";
cout<<"Enter a String:"<<endl;
cin>>input;
int l = input.length();
for(int i=0;i<l;i++)
{	
int in = decode.find(input[i]);	
output += code.substr(in,1);
}
cout<<output<<endl;
return 0;
}
