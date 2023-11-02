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
            no_of_owners=0;
            car_regi_no=0;
            odo_read=" ";
            insu_no=0;
            insu_expiry=" ";
            insu_type=0;
            insu_pre_amount=" ";
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

        //----getters--------

        string get_car_company()
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

        //-------setters--------------------------

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
        

        void show(int num)
        {
            cout<<"----- Details of car - "<<num+1<<" -------"<<endl;
            cout<<"Company name: "<<get_car_company()<<endl;
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
            int year,month,day,year1,month1,day1;
            year=stoi(e_date.substr(6,4));
            month=stoi(e_date.substr(3,2));
            day=stoi(e_date.substr(0,2));

            year1=stoi(insu_expiry.substr(6,4));
            month1=stoi(insu_expiry.substr(3,2));
            day1=stoi(insu_expiry.substr(0,2));

            if(year<year1)
            {
                cout<<"The date is expired.....";
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
                    cout<<"The date is expired.....";
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
                        cout<<"The date is expired.....";
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


};

int car::it=0;

class ServiceStation
{
    private:

    string name,address,issue,date,odo_meter,bill;
    int current_car_list[50],k;
    static int j;

    public:

        void add_car_to_service(int num)
        {
            current_car_list[j]=num;
            j++;
            cout<<"Enter odometer reading: ";
            cin>>odo_meter;
            cout<<"Enter the issue: ";
            cin>>issue;

        }


        void service_car(int t,int number)
        {
            
            cout<<"Enter the bill: ";
            cin>>bill;
            cout<<"Enter the date: ";
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

        string get_odo()
        {
            return odo_meter;
        }
        string get_issue()
        {
            return issue;
        }

        string get_date()
        {
            return date;
        }
        string get_bill()
        {
            return bill;
        }

        void show_cars()
        {
            for(int i=0;i<j;i++)
            {
                cout<<current_car_list[i]<<"  ";
            }
            cout<<endl;
            if(j==0)
            {
                cout<<"---There are no cars in the service station----";
                cout<<endl;
            }
        }

};
int ServiceStation::j=0;

int main()
{
    car c[20];
    ServiceStation s;
    int i=0,t,val;
    int ch,op,num,insu_num,insu_ty,number;
    string e_date,amount,odo,issue,date,bill;

    map<int,car> car_objects;

    do
    {
        cout<<"1.Create Car "<<endl<<"2.Print All Car Details"<<endl<<"3.Update Insurance"<<endl<<"4.Drop car to service"
              <<endl<<"5.Pick up car from service"<<endl<<"6.Show cars at service station"<<endl<<"7.Show last service data"<<endl;

        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:c[i].add_car();  
                    car_objects.insert(pair<int,car>(c[i].get_car_regi_number(),c[i]));
                    i++;
                    break;

            case 2:for(t=0;t<i;t++)
                    {
                        c[t].show(t);
                    }
                    break;
            case 3:cout<<"Enter the car registraion number: ";
                    cin>>num;
                    cout<<"Enter insurance premium amount paid: ";
                    cin>>amount;
                    cout<<"Enter insurance number: ";
                    cin>>insu_num;
                    cout<<"Enter insurance type (1,2,3) : ";
                    cin>>insu_ty;
                    cout<<"Enter expiry date: ";
                    cin>>e_date;

                    for(t=0;t<=i;t++)
                    {
                        if(c[t].get_car_regi_number()==num)
                        {
                            c[t].insurance(amount,insu_num,insu_ty,e_date);
                            break;
                        }
                    }
                    break;

            case 4: cout<<"Enter the car registration number: ";
                    cin>>num;
                    for(t=0;t<=i;t++)
                    {
                        if(c[t].get_car_regi_number()==num)
                        {
                            s.add_car_to_service(num);
                            break;
                        }
                    }
                    break;

            case 5:cout<<"Enter the car registration number: ";
                    cin>>number;
                    for(t=0;t<i;t++)
                    {
                        if(c[t].get_car_regi_number()==number)
                        {
                            s.service_car(t,number);
                            
                            break;
                        }
                    }
                    odo=s.get_odo();
                    issue=s.get_issue();
                    date=s.get_date();
                    bill=s.get_bill();

                    c[t].set_service(odo,issue,date,bill);
                    break;

            case 6:s.show_cars();
                    break;

            case 7:cout<<"Enter car registration number: ";
                    cin>>num;
                    for(t=0;t<i;t++)
                    {
                        if(c[t].get_car_regi_number()==num)
                        {
                            c[t].print_last_ser_data();
                            break;
                        }
                    }
                    break;   

        }

        cout<<"Do you want to do any other operation? (yes-1)(no-0)....";
        cin>>op;

        if(op==0)
        {
            cout<<"------Thank you visit again------";
        }
    } while (op==1);
}