//Nesting of Member function

#include<iostream>
#include<string>
using namespace std;

class binary{
    private:  //if not mentioned,cosidered as private
    string s;
    void chk_bin(void);   //private function can't be called in main body, but in another function 
    public: 
          void read(void);
          void ones_complement(void);
          void display(void);
};

void binary :: read(void){
    cout<<"Enter a binary number"<<endl;
    cin>>s;
}

void binary :: chk_bin (void){
    for(int i=0; i<s.length(); i++){
        if(s.at(i)!='0' && s.at(i)!='1'){
            cout<<"Incorrect binary format"<<endl;
            exit(0);
        }
    }
}

void binary :: ones_complement(void){
    chk_bin();
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='0'){
            s.at(i)='1';
        }else{
            s.at(i)='0';
        }
    }
}

void binary :: display(void){
    cout<<"Displaying your binary number"<<endl;
    for(int i = 0;i<s.length();i++){
        cout<<s.at(i);
    }
    cout<<endl;
}

int main(){
     binary b;
     b.read();
     //b.chk_bin();
     b.display();
     b.ones_complement();
     b.display();

     return 0;
}