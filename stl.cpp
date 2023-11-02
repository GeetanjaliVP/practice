#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void show(stack<int> st)
{
    while(!st.empty())
    {
        cout<<" "<<st.top();
        st.pop();
    }
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    show(st);



}