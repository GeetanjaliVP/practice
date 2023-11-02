#include<iostream>

using namespace std;

class customer
{

};

class mall
{

};


int main()
{
  int section;
  cout<<".....Welcome to Shopping mall...."<<endl;
  cout<<"-------sections----------"<<endl;
  cout<<"1.Men"<<endl<<"2.Women"<<endl<<"3.Kids"<<endl;
  cout<<"Which section you want to go?   ";
  cin>>section;
  cout<<endl;
  switch(section)
  {
    case 1: cout<<"....Welocome to Men's section...."<<endl;
            break;
    
    case 2: cout<<"....Welcome to Women's section...."<<endl;
            break;

    case 3: cout<<"....Welcome to Kid's section...."<<endl;
            break;

    default: cout<<"Invalid choice.."<<endl;
  }



}