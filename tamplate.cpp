#include<bits/stdc++.h>

using namespace std;

template<class T,int size>

class array1
{
    public:

    T arr[size];

    void insert()
    {
        for(int i=0;i<size;i++)
        {
            arr[i]=i;
        }
    }
    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }

};


int main()
{
    array1<int,5> a;
    a.insert();
    a.display();
    return 0;
}
