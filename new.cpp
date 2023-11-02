#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class car
{
    private:
        string car_comp_name,car_model,year_of_purchase,last_ser_data[10],insu_expiry,odo_read,insu_pre_amount;
        int no_of_owners,car_regi_no,insu_no,insu_type,chassis_no,eng_no;

        static int it;

        map<string,string> last_service_data[50];

    public:
        car()
        {
            car_comp_name=" ";
            car_model=" ";
            year_of_purchase=" ";
            insu_expiry=" ";
            odo_read=" ";
            insu_pre_amount=" ";
            no_of_owners=0;
            car_regi_no=0;
            insu_no=0;
            insu_type=0;
            chassis_no=0;
            eng_no=0;
        }

        void add_car()
        {
            cout<<"Enter car campany: ";
            cin>>car_comp_name;
            cout<<"Enter car model: ";
            cin>>car_model;
            cout<<"Enter year of purchase: ";
            cin>>year_of_purchase;
            cout<<"Enter number of owners: ";
            cin>>no_of_owners;
            cout<<"Enter car registration number: ";
            cin>>car_regi_no;
            cout<<"Enter odometer reading: ";
            cin>>odo_read;
            cout<<"Enter insurance number: ";
            cin>>insu_no;
            cout<<"Enter insurance expiry date: ";
            cin>>insu_expiry;
            cin.ignore();
            cout<<"Enter insurance type (1,2,3): ";
            cin>>insu_type;
            cout<<"Enter premium insurance amount paid: ";
            cin>>insu_pre_amount;
            cout<<"Enter chassis number: ";
            cin>>chassis_no;
            cout<<"Enter engine number: ";
            cin>>eng_no;
        }


        // getters

        void get_car_comp()
        {
            return car_comp_name;
        }
        string get_car_model()
        {
            return car_model;
        }
        string get_year_of_purchase()
        {
            return year_of_purchase;
        }
        string get_insu_expiry()
        {
            return insu_expiry;
        }
        int get_no_of_owners()
        {
            return no_of_owners;
        }
        int get_car_regi_number()
        {
            return car_regi_no;
        }

        string get_odo_read()
        {
            return odo_read;
        }
        int get_insu_no()
        {
            return insu_no;
        }
        int get_insu_type()
        {
            return insu_type;
        }
        string get_insu_pre()
        {
            return insu_pre_amount;
        }
        int get_chassis_no()
        {
            return chassis_no;
        }
        int get_eng_no()
        {
            return eng_no;
        }

        void display()
        {
            cout<<"Car company name: "<<get_car_comp();
            cout<<"Car Model: "<<get_car_model()<<endl;
            cout<<"Year of Purchase: "<<get_year_of_purchase()<<endl;
            cout<<"Number of Owners: "<<get_no_of_owners()<<endl;
            cout<<"Car registration number: "<<get_car_regi_number()<<endl;
            cout<<"Odometer reading: "<<get_odo_read()<<endl;
            cout<<"Insurance number: "<<get_insu_no()<<endl;
            cout<<"Insurance expiry date: "<<get_insu_expiry()<<endl;
            cout<<"Insurance type: "<<get_insu_type()<<endl;
            cout<<"Insurance premium amount paid: "<<get_insu_pre()<<endl;
            cout<<"Chassis number: "<<get_chassis_no()<<endl;
            cout<<"Engine number: "<<get_eng_no()<<endl;
            cout<<endl;
        }

        void insurance(string amount,int insu_num,int insu_ty,string e_date)
        {
            int year,month,day;
            int year1,month1,day1;

            year=stoi(e_date.substr(6,4));
            month=stoi(e_date.substr(3,2));
            day=stoi(e_date.substr(0,2));

            year1=stoi(insu_expiry.substr(6,4));
            month1=stoi(insu_expiry.substr(3,2));
            day1=stoi(insu_expiry.substr(0,2));

            if(year<year1)
            {
                cout<<"The date is expired....";
            }
            if(year>year1)
            {
                insu_pre_amount=amount;
                insu_no=insu_num;
                insu_type=insu_ty;
                insu_expiry=e_date;
            }
            if(year==year1)
            {
                if(month<month1)
                {
                    cout<<"The date is expired....";
                }
                if(month>month1)
                {
                    insu_pre_amount=amount;
                    insu_no=insu_num;
                    insu_type=insu_ty;
                    insu_expiry=e_date;
                }
                if(month==month1)
                {
                    if(day<day1)
                    {
                        cout<<"The date is expired....";
                    }
                    if(day>day1)
                    {
                        insu_pre_amount=amount;
                        insu_no=insu_num;
                        insu_type=insu_ty;
                        insu_expiry=e_date;
                    }
                    if(day==day1)
                    {
                        insu_pre_amount=amount;
                        insu_no=insu_num;
                        insu_type=insu_ty;
                        insu_expiry=e_date;
                    }
                }
            }
        }

        void set_service(string odo,string issue,string date,string bill)
        {
            last_service_data[it].insert(pair<string,string>("odo",odo));
            last_service_data[it].insert(pair<string,string>("Issues",issue));
            last_service_data[it].insert(pair<string,string>("Date",date));
            last_service_data[it].insert(pair<string,string>("Amount",bill));
            it++;
        }

        void print_last_ser_data()
        {
            map<string,string> :: iterator itr;

            cout<<"-------services--------";
            for(int m=0;m<it;m++)
            {
                cout<<endl;
                for(itr=last_service_data[m].begin(); itr!=last_service_data[m].end();++itr)
                {
                    cout<<" "<<itr->first<<": "<<itr->second<<endl;

                }
            }
        }


};

int car::it=0;

class ServiceStation
{
    private:
        int current_car_list[50];
        static int j,k;
        string odo_meter,issue,bill,date;

    public:
        void add_car_to_service(int num)
        {
            current_car_list[j]=num;
            cout<<"Enetr odometer reading: ";
            cin>>odo_meter;
            cout<<"Enter issue: ";
            cin>>issue;
        } 

        void service_car(int number)
        {   
            cout<<"Enter bill: ";
            cin>>bill;
            cout<<"Enter date: ";
            cin>>date;

            for(k=0;k<j;k++)
            {
                if(current_car_list[k]==number)
                    break;
            }

            if(k<j)
            {
                j=j-1;
                for(int l=k;l<j;l++)
                {
                    current_car_list[l]=current_car_list[l+1];
                }
            }
            
        }  

        void get_odo()
        {
            return odo_meter;
        }
        void get_issue()
        {
            return issue;
        }
        void get_date()
        {
            return date;
        }
        void get_bill()
        {
            return bill;
        }

};

int ServiceStation:: j=0;

int main()
{
    car c[20];
    ServiceStation s;
    int ch,i=0,t,num;
    string e_date,amount,bill,odo,date,issue;
    int insu_num,insu_ty;



    do
    {
        cout<<"1.add car"<<endl<<"2.display"<<endl<<"3.Insurance"<<endl<<"4. add car to service"<<endl<<"5.pick up car from the service"<<endl
        <<"6.show last service data: "<<endl<<"7.show cars at service"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1: c[i].add_car();
                    i++;
                    break;

            case 2: for(t=0;t<i;t++)
            {
                c[t].display();
            }
            break;

            case 3:cout<<"Enter registration number: ";
                    cin>>num;
                    cout<<"Enter premium amount: ";
                    cin>>amount;
                    cout<<"Enter insurance number: ";
                    cin>>insu_num;
                    cout<<"Enter insurance type; ";
                    cin>>insu_ty;
                    cout<<"Enter expiry date: ";
                    cin>>e_date;
                    for(t=0;t<i;t++)
                    {
                        if(c[t].get_car_regi_number()==num)
                        {
                            c[t].insurance(amount,insu_num,insu_ty,e_date);
                        }
                    }
                    break;

            case 4: cout<<"Enter car registration number: ";
                    cin>>num;
                    for(t=0;t<i;t++)
                    {
                        if(c[t].get_car_reg_number()==num)
                        {
                            s.add_car_to_service(num);
                        }
                    }
                    break;

            case 5:cout<<"Enter car registration number: ";
                    cin>>num;
                    for(t=0;t<i;t++)
                    {
                        if(c[t].get_car_reg_number()==num)
                        {
                            s.service_car(num);
                        }
                    }
                    odo=s.get_odo();
                    issue=s.get_issue();
                    date=s.get_date();
                    bill=s.get_bill();
                    c[t].set_service(odo,issue,date,bill);




        }

    } while (1);
    
}