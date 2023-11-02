#include<bits/stdc++.h>
#include<csignal>
#include <unistd.h>

using namespace std;

void signal_handler(int signal_num)
{
    cout<<"The interrupt signal is "<<signal_num<<endl;
    exit(signal_num);
}

int main()
{
    signal(SIGTERM,signal_handler);

    while(true)
    {
        cout<<"Hello world...."<<endl;
        sleep(1);
        raise(SIGTERM);
    }
    return 0;
}