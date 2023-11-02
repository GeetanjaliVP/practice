#include<bits/stdc++.h>

using namespace std;

typedef int(*r_ptr)(int,int);
r_ptr p;

struct data
{
    int num;
    string name;
};

template<typename t>
void add(t a,t b)
{
    cout<<"Sum: "<<a+b<<endl;
}

template<typename m>
void sub(m a,m b)
{
    cout<<"Subtraction: "<<a-b<<endl;
}

template<typename n>
void mult(n a,n b)
{
    cout<<"Multiplication: "<<a*b<<endl;
}

void show()
{
    cout<<"Hello"<<endl;
}

int fun1(int a, int b)
{
    //cout<<"add of fun1="<<&fun1<<endl;
    //cout<<"Function 1"<<endl;

    return a+b;
}

void fun2()
{
    cout<<"Function 2"<<endl;
}

r_ptr return_fun()
{
    return fun1;
}

void wrapper(void (*fun)())
{
    fun();
}

void compare(int a,int b,int *max,int *min)
{
    if(a>b)
    {
        *max=a;
        *min=b;
    }
    else
    {
        *max=b;
        *min=a;
    }
}

int main()
{

    //pointer to function

    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;

    cout<<typeid(a).name()<<endl;

    void (*ptr_arr[])(int,int)={add,sub,mult};
    void (*ptr)()=show;

    (*ptr)();
    int ch;
    
    cout<<"1.addition    2.Subtraction      3.Multiplication"<<endl;
    cin>>ch;
     
    if(ch>3)
    {
        return 0;
    }

    (*ptr_arr[ch-1])(5,2);

    //returning function address

    p=return_fun();
    //cout<<"Address of function: "<<&p<<endl;
    cout<<"final_value="<<p(10,20)<<endl;

    //wrapper function
    wrapper(fun2);

    //pointer to structure
    struct data s;
    struct data* s_ptr=&s;

    cout<<s_ptr<<endl;
    s.num=5;
    s.name="Geeta";
    cout<<(*s_ptr).num<<endl;
    cout<<(*s_ptr).name<<endl;
    

    //returning multiple values from function
    int great,small,x,y;
    cout<<"Enter two values: ";
    cin>>x>>y;

    compare(x,y,&great,&small);
    cout<<"greater: "<<great<<endl;
    cout<<"Smaller: "<<small<<endl;

    return 0;
}