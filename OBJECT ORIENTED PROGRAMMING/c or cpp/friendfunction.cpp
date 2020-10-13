// Friend function working code

#include <iostream>

using namespace std;

class N;

class M{
    int num;
    public:
    M(){
      cout<<"Enter value (M)";
      cin>>num;
    };
    void displaydata();
    ~M(){

    }
    friend void comp(M x, N y);
};

class N{
    int num;
    friend void comp(M x, N y);
    public:
    N(){
      cout<<"Enter value (N)";
      cin>>num;
    };
    void displaydata();
    ~N(){

    }
    //friend void comp(M x, N y);
};
 void comp(M x, N y){
   if (x.num>y.num){
     cout<<"\n Greater number is : "<<x.num;
   }
   else if (x.num==y.num){
    cout<<"\n Both numbers are equle ";
   }
   else{
     cout<<"\n Greater number is : "<<y.num;
   }
 }

int main(){
  M m;
  N n;
  comp(m,n);
}