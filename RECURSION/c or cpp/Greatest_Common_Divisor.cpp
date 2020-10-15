/* This is a program that gives you the Greatest Common Divisor or Highest Common Factor of two integers using recursion */
// Sphoortikadapa

#include <iostream>

using namespace std;


int hcf(int x, int y){
    if(x==0){
        return x;
    }
    
    if(y==0){
        return y;
    }
    
    if(x==y){
        return x;
    }
    
    if(x>y){
        return hcf(x-y, y);
    }
    
    if(y>x){
        return hcf(x, y-x);
    }
    
}

int main(){
    int x,y;
    cout<<"Enter the integers whose HCF you want to calculate\n";
    cin>>x>>y;
    cout<<hcf(x,y);
   
   return 0; 
    
}


