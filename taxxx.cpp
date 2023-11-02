#include  <iostream>

#include  <bits/stdc++.h>




using namespace std;



#define MAX_ADD 120

class Owner

{

    private:

    string owner_name;

    char owner_address[MAX_ADD];

    string email;

    vector<int> khata_list;

    

    public:

    Owner(string name,char address[],string mail,vector<int> list){

        owner_name=name;

        strcpy(owner_address,address);

        khata_list=list;

        email = mail;

    }



    string getOwnerName(){

        return owner_name;

    }



    void setOnwerName(string name){

        owner_name=name;

    }



    char* getOwnerAddress(){

        return owner_address;

    }



    void setOnwerAddress(char add[120]){

        strcpy(owner_address,add);

    }



    string getOwnerEmail(){

        return email;

    }



    void setOnwerEmail(string mail){

        email=mail;

    }



    vector<int> getOwnerKhataList(){

        return khata_list;

    }



    void setOnwerName(vector<int> list){

        khata_list=list;

    }




    

};



class Khata

{

    private:

    int khata_id;

    float dim;

    int no_of_stories;

    float tax;

    //0- self

    //1-rental

    int usage;



    

    

    public:

    Khata(int id,float d,int stories,float amt,int use){

        khata_id=id;

        dim=d;

        no_of_stories=stories;

        tax=amt;

        usage=use;



    }




    int getKhataId(){

        return khata_id;

    }



    float getKhataDim(){

        return dim;

    }

    int getKhataStories(){

        return no_of_stories;

    }

    float getKhataAmount(){

        return tax;

    }



    int getKhataUsage(){

        return usage;

    }




    void setKhataId(int id){

         khata_id=id;

    }



    

    void setKhataStories(int n){

         no_of_stories=n;

    }

    void getKhataAmount(float a){

         tax=a;

    }



    void getKhataUsage(int u){

         usage=u;

    }



    



};



class Tax{



    public:



    float amt;



    int khath_id;



};






vector<Owner> owner_list;

vector<Khata> property_list;

vector<Tax> tax_list;



float tax_total_amt=0;

float cur_tax=0;

void display_khata(){



    for(auto it:property_list){

        cout<<it.getKhataId()<<" "<<it.getKhataDim()<<" "<<it.getKhataStories()<<" "<<it.getKhataAmount()<<endl;

    }

}

void add_owner(){



     string name,mail;

     vector<int> list;

     int id;

     char address[MAX_ADD];

     cout<<"ENter name\n";

     cin.ignore();

     getline(cin,name);



     cout<<"Enter address\n";

     cin.getline (address, MAX_ADD);

     cout<<"ENter mail\n";

     getline(cin,mail);



    display_khata();

    while(1)

    {

        cout<<"Enter khata id or press -1 to exit\n";

        cin>>id;

        if(id==-1){

            break;

        }

        list.push_back(id);

    }



     Owner e(name,address,mail,list);

     owner_list.push_back(e);



     cout<<"Owner has been created\n";

}



float get_tax_amount(float dimension,int usage,int floors)

{

   

    

    float tax,index;

    

    if(floors==0)

    {

        tax=(dimension)*1;

        return tax;

    }

    else if(floors==1)

    {

        if(usage==0)

        {

            tax=(dimension)*(floors)*(1.5);

            return tax;

        }

        else

        {

            tax=(dimension)*(floors)*(1.75);

            return tax;

        }

    }

    else if(floors>1 || floors<=3)

    {

        if(usage==0)

        {

            tax=(dimension)*2;

            return tax;

        }

        else

        {

            tax=(dimension)*(2.25);

            return tax;

        }

    }

    else if(floors>3 || floors<=5)

    {

        printf("\nEnter locality Index betweeen 1.0 to 2.0 :\n");

        scanf("%f",&index);

        tax=(dimension)*(index)*(floors)*(3.5);

        return tax;

    }

    else if(floors>5 || floors<=25)

    {

        printf("\nEnter Economic Index betweeen 2.0 to 2.5 :\n");

        scanf("%f",&index);

        tax=(dimension)*(index)*(floors)*(5);

        return tax;

    }



    return 0;

}




void add_property(){



     int no_stories,use;

    float tax,d[2];

    

     cout<<"ENter Physical dimension\n";

     cout<<"ENter Length \n";

     cin>>d[0];

     cout<<"Enter breadth\n";

     cin>>d[1];



     cout<<"Enter no. of stories\n";

     cin>>no_stories;



     cout<<"Enter 0-self 1-rent usage\n";

     cin>>use;



     tax = get_tax_amount(d[0]*d[1],use,no_stories);



    cout<<"Tax amount = "<<tax;




    Khata p(property_list.size()+1,d[0]*d[1],no_stories,tax,use);



    property_list.push_back(p);
    cout<<"Property has been created\n";

}



void calculate_tax(){

    int id;

    cout<<"Enter khata id\n";

    cin>>id;

    for(auto it:property_list){

        if(it.getKhataId()==id){

            cout<<"Tax = "<<it.getKhataAmount();

           

            break;

        }

    }



}

void pay_tax()



    {



        int id;

        cout<<"Enter khata id\n";

        cin>>id;

        for(auto it:property_list){

        if(it.getKhataId()==id){

            cout<<"Tax = "<<it.getKhataAmount();

            Tax t;



        t.khath_id=id;



        t.amt=it.getKhataAmount();



        tax_total_amt+=t.amt;

        tax_list.push_back(t);



            break;

        }

    }
    

}
void print_tax_col()



    {



        



        cout<<"Tax amt = "<<tax_total_amt;



    }



int main() {

    int ch;

    // Write C++ code here

    while(1){

        cout<<"1. Add Property\n";

        cout<<"2. Add owner\n";

        cout<<"3. Calculate tax\n";

        cout<<"4. pay tax\n";

        cout<<"5. Total tax\n";

        cin>>ch;

        switch(ch){

            case 1: add_property();

                    break;

            case 2: add_owner();

                    break;

            case 3:calculate_tax();

                    break;

            case 4:pay_tax();

                    break;

            case 5:print_tax_col();

                    break;

        }

    }



    return 0;

}