  #include<iostream>
  using namespace std;
  /*
  syntax for initialization list in constructor:
  constructor(argument-list) : initilization-section{
          assignment+other code;
  }

  class Test{
  int a;
  int b;
  public:
  Test(int i, int j) : a(i), b(j){constructor-body}
  };
  */
 
  class Test{
  int a;
  int b;
  public:
  Test(int i, int j) : a(i), b(j){cout<<"constructor-body executed";}
  };
  int main(){
    Test t(4,6);
  }