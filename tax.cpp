#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class Owner
{
    private:
    string name,address,phone,email,area,pin;
    int door_no,num,khata;
    vector<int> khata_list;

    public:

    void add_owner()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Address of the owner "<<endl;
        cout<<"door number: ";
        cin>>door_no;
        cout<<"area: ";
        cin>>area;
        cout<<"Pin code: ";
        cin>>pin;

        cout<<"Number of properties owner owns: ";
        cin>>num;
        for(int i=0;i<num;i++)
        {
            cout<<"Enter the ID of "<< i+1<<"property: ";
            cin>>khata;
            khata_list.push_back(khata);
        }
    }

    vector<int> display_own(int i)
    {
        cout<<"Name: "<<name<<endl;
        cout<<"--Address--"<<endl;
        cout<<"Door number: "<<door_no<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Pin code: "<<pin<<endl;

        cout<<"----Properties----"<<endl;

        return khata_list;
    }
};



class Tax{
    public:
    float amt;
    int khath_id;
};

vector<Tax> tax_list;




class property
{
    private:
    int khata_id,phy_dim[2],no_floors,tax,loc_index,eco_index,usage;
    float size;


    
    public:
    void add_property()
    {
        cout<<"Enter khata_id: ";
        cin>>khata_id;
        cout<<"Enter length of the property: ";
        cin>>phy_dim[0];
        cout<<"Enter breadth of the property: ";
        cin>>phy_dim[1];
        cout<<"Enter number of floors: ";
        cin>>no_floors;
        if(no_floors<=5)
        {
            cout<<"Enter locality index: ";
            cin>>loc_index;
        }
        else{

            cout<<"Enter economical index: ";
            cin>>eco_index;
        }
        cout<<"Enter usage (self=0)(rent=1): ";
        cin>>usage;
    }
    void cal_tax()
    {

        size=phy_dim[0]*phy_dim[1];
        if(no_floors==0)
        {
            tax=size;
        }
        if(no_floors==1)
        {
            if(usage==0)
            {
                tax=1.5*size;
            }
            if(usage==1)
            {
                tax=1.75*size;
            }
        }
        if(no_floors==2|| no_floors==3)
        {
            if(usage==0)
            {
                tax=2*size;
            }
            if(usage==1)
            {
                tax=2.25*size;
            }
        }

        if(no_floors==4|| no_floors==5)
        {
            tax=3.5*loc_index;
        }
        if(no_floors>5 && no_floors<=25)
        {
            tax=eco_index*size;
        }

        cout<<"Tax = "<<tax<<endl;
    }

    void pay_tax(int id)
    {

        Tax t;
        t.khath_id=id;
        t.amt=tax;
        tax_list.push_back(t);
        cout<<"The tax for year is: "<<tax<<endl;

    }

    

    int get_khata_id()
    {
        return khata_id;
    }

    float get_area()
    {
        return size;
    }

    int get_floors()
    {
        return no_floors;
    }


};

static float tax_col=0;

void print_tax_col()
    {
        for(auto it:tax_list){
            tax_col+=it.amt;
        }
        cout<<"Tax amt = "<<tax_col<<endl;
    }



int main()
{
    property p[50];
    Owner o[50];
    int i=0,j=0,id;
    int ch,op;
    do
    {
        cout<<"1.Add property"<<endl<<"2.Add owner"<<endl<<"3.Calculate Tax"<<endl<<"4.Pay tax"<<endl<<"5.Print tax collected"<<endl
        <<"6.Display owners"<<endl<<"7.display properties "<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:p[i].add_property();
                    i++;
                    break;

            case 2:o[j].add_owner();
                    j++;
                    break;

            case 3:cout<<"Enter the khata ID: ";
                    cin>>id;
                    for(int t=0;t<i;t++)
                    {
                        if(p[t].get_khata_id()==id)
                        {
                            p[t].cal_tax();
                            break;
                        }
                    }
                    break;

            case 4:cout<<"Enter the khata id: ";
                    cin>>id;
                    for(int t=0;t<i;t++)
                    {
                        if(p[t].get_khata_id()==id)
                        {
                            p[t].pay_tax(id);
                            break;
                        }
                    }
                    break;

            case 5:print_tax_col();
                    break;

            case 6:for(int t=0;t<j;t++)
                {
                    vector<int> vect=o[t].display_own(i);
                    for(auto m=vect.begin();m!=vect.end();++m)
                    {
                        for(int k=0;k<i;k++)
                        {
                            if(p[k].get_khata_id()==*m)
                            {
                                cout<<"Khata id: "<<p[k].get_khata_id()<<endl;
                                cout<<"Area: "<<p[k].get_area()<<endl;
                                cout<<"Floor: "<<p[k].get_floors()<<endl;
                                cout<<"---------------------------"<<endl;
                            }
                        }
                    }

                }   
                break;

            case 7:for(int t=0;t<i;t++)
            {
                cout<<"---Property "<<t+1<<"---"<<endl;
                cout<<"Khata ID: "<<p[t].get_khata_id()<<endl;
                cout<<"Area: "<<p[t].get_area()<<endl;
                cout<<"Floor: "<<p[t].get_floors()<<endl;
                cout<<"----------------------------"<<endl;
            }
            break;


        }

        cout<<"Do you want to do any other operation? (yes=1)(no=0)... ";
        cin>>op;

        if(op==0)
        {
            cout<<"Thank you for your time....";
        }

    } while (op==1);
    
}