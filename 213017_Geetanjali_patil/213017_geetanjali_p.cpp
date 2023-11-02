#include<bits/stdc++.h>
#include<map>
#include<math.h>

using namespace std;

class employee
{
    public:
        string name,gender,base_location,department,employee_type,band,bank_acc_no,street,area,city,pin;
        int pf_number,door_no,employee_id;
        /// @brief 
        float ctc;
        int id;
        

        static int counter;
        static int i;

        map<string,map<string,float>> salary_slip;

    
        void employee_add()
        {
            cin.ignore();
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter gender: ";
            cin>>gender;
            cout<<"Enter door number: ";
            cin>>door_no;
            cout<<"Enter street: ";                                                                                
            cin>>street;
            cin.ignore();
            cout<<"Enter area: ";
            cin>>area;
            cout<<"Enter city: ";
            cin>>city;
            cout<<"Enter pin: ";
            cin>>pin;
            cout<<"Enter base location: ";
            cin>>base_location;
            cout<<"Enter department: ";
            cin>>department;
            cout<<"Enter employee type: ";
            cin>>employee_type;
            cout<<"Enter band: ";
            cin>>band;
            cout<<"Enter PF number: ";
            cin>>pf_number;
            cout<<"Enter bank account number: ";
            cin>>bank_acc_no;
            cout<<"Enter CTC in lakhs: ";
            cin>>ctc;
            employee_id=id;


        }

        void show()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Gender: "<<gender<<endl;
            cout<<"address: "<<" "<<endl;;
            cout<<door_no<<" ";
            cout<<street<<" ";
            cout<<city<<" ";
            cout<<pin<<" ";
            cout<<"Location: "<<base_location<<endl;
            cout<<"Employee id: "<<employee_id<<endl;
            cout<<"Department" <<department<<" "<<endl;
            cout<<"employee type" <<employee_type<<" "<<endl;
            cout<<"band"<<band<<" "<<endl;
            cout<<"Pf number"<<pf_number<<" "<<endl;
            cout<<"bank Account number: "<<bank_acc_no<<" "<<endl;
            cout<<"CTC in lakhs: "<<ctc<<endl;
        }


};

int employee::counter=0;
int employee::i=0;

class employer:public employee
{
    private:

    string company_name;
    string locations[4];                             // {"Bangalore","Pune","Chennai","Kolkata"};
    string bands[7];                                  // {"GT","E1","E2","E3","L1","L2","L3"};
    string departments[4];                            //{"SEC","SatComm","Devices","RAN"};

    string month,mess_bill,transfer_date;

    map<int,employee> employee_info;
    

    public:

        employee e[20];

        employer()
        {
            cout<<"Enter the name of the company: ";
            cin>>company_name;
            cout<<"Enter the 4 locations of the company: ";
            for(int j=0;j<4;j++)
            {
                cin>>locations[i];
            }
            cout<<"Enter the 7 bands: ";
            for(int j=0;j<7;j++)
            {
                cin>>bands[i];
            }
            cout<<"Enter 4 departments: ";
            for(int j=0;j<4;j++)
            {
                cin>>departments[i];
            }
        }

        void add_user()
        {
            // employee e[i];    
            // e[i].employee_add();
            // id++;

            // // employee_info[id]=e[i];
            // // id++;

            e[i].employee_add();
	        cout<<"in  start add user"<<endl;
            id=counter;
	        employee_info.insert(pair<int,employee>(id,e[i]));
	        i++;
	        counter++;
	        cout<<"emp_id:"<<id<<endl;
	        cout<<"in end of add user"<<endl;
            
        }


        void modify_user()
        {
            int emp_id,ch;
            cout<<"Enter employee id: ";
            cin>>emp_id;

            for(int t=0;t<i;t++)
            {
                if(e[t].employee_id==emp_id)
                {
                    cout<<"1.Name   2.address   3.location   4.department   5.employee type   6.band    7.bank account number   8.CTC "<<endl;
                    cout<<"Enter your choice: ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:cout<<"enter name: ";
                               cin>>e[t].name;
                               break;

                        case 2:cout<<"Enter door number: ";
                               cin>>e[t].door_no;
                               cout<<"enter street: ";
                               cin>>e[t].street;
                               cout<<"enter area: ";
                               cin>>e[t].area;
                               cout<<"enter city: ";
                               cin>>e[t].city;
                               cout<<"Enter pin: ";
                               cin>>e[t].pin;
                               break;

                        case 3:cout<<"Enter base location: ";
                                cin>>e[t].base_location;
                                break;

                        case 4:cout<<"enter department: ";
                                cin>>e[t].department;
                                break;

                        case 5:cout<<"enter employee type: ";
                                cin>>e[t].employee_type;
                                break;

                        case 6:cout<<"Enter band: ";
                                cin>>e[t].band;
                                break;

                        case 7:cout<<"Enter bank account number: ";
                                cin>>e[t].bank_acc_no;
                                break;

                        case 8:cout<<"Enter CTC: ";
                                cin>>e[t].ctc;
                                break;
                    }
                }
            }

        }

        int search(int employee_num)
        {
            for(int t=0;t<i;t++)
            {
                if(e[t].employee_id==employee_num)
                {
                    return t;
                }
                else
                    return -1;
            }
            
        }

        void print_emp_details(int t)
        {
            
            e[t].show();
        }

        void remove(int val)
        {
            e[val].employee_id=-1;
        }

        void pay_slip()
        {
            int em_id;

            float basic_salary,variable_pay,provident_fund,other_allowence,income_tax,gross_pay,net_pay,net_pay1;

            cout<<"Enter the month of the pay: ";
            cin>>month;
            cout<<"Enter the employee id: ";
            cin>>em_id;
            cout<<"Enter the mess bill: ";
            cin>>mess_bill;
            cout<<"Enter the transfer date: ";
            cin>>transfer_date;


            for(int t=0;t<i;t++)
            {
                //cout<<e[t].employee_id<<"--------------";
                if(e[t].employee_id==em_id)
                {
                    int salary=e[t].ctc*100000;
            

                    basic_salary=(salary*60)/100;
                    variable_pay=(salary*30)/100;
                    provident_fund=(salary*5)/100;
                    other_allowence=(salary*5)/100;
                    if(salary<5)
                    {
                        income_tax=0;
                    }
                    else if(salary>500000 && salary<1000000)
                    {
                         income_tax=(salary*5)/100;
                    }
                    else if(salary>1010000 && salary<1500000)
                    {
                        income_tax=(salary*10)/100;
                    }
                    else if(salary>1510000 && salary<2000000)
                        {
                            income_tax=(salary*15)/100;
                    }
                    else if(salary>2000000)
                    {
                        income_tax=(salary*20)/100;
                    }

                     gross_pay=basic_salary+variable_pay+provident_fund+other_allowence;
                     net_pay1=gross_pay - income_tax;
    



                    cout<<"Basic salary: "<<basic_salary<<endl;
                    cout<<"Variable Pay: "<<variable_pay<<endl;
                    cout<<"Provident fund: "<<provident_fund<<endl;
                    cout<<"Other allowence: "<<other_allowence<<endl;
                    cout<<"Income tax: "<<income_tax<<endl;
                    cout<<"Net Pay: "<<net_pay1<<endl;
                    cout<<"Gross pay: "<<gross_pay<<endl;



                }
            }


            
            
        }

    
        


};



int main()
{

    employer er;
    int ch,t,i=0;
    int employee_num;
    

    do
    {
        cout<<"1.add employee"<<endl<<"2.modify"<<endl<<"3.remove"<<endl<<"4.Search"<<endl<<"5.show"<<endl<<"6.pay slip"<<endl<<"7.exit    ";
        cin>>ch;

        switch(ch)
        {
            case 1:er.add_user();
                    i++;
                    break;

            case 2:er.modify_user();
                    break;

            case 3:cout<<"Enter Employee ID: ";
                    cin>>employee_num;
                    if(er.search(employee_num)!=-1)
                    {
                        int val=er.search(employee_num);
                        er.remove(val);
                    }
                    else{
                        cout<<"Employee does not exist...";
                    }



                    break;

            case 4:cout<<"Enter Employee ID: ";
                    cin>>employee_num;
                    if(er.search(employee_num)!=-1)
                    {
                        int val=er.search(employee_num);
                        er.print_emp_details(val);
                    }
                    else{
                        cout<<"Employee does not exist...";
                    }

                    break;

            case 5:for(int j=0;j<i;j++)
            {
                er.print_emp_details(j);
            }
                    break;


            case 6: er.pay_slip();
                    break;

            case 7: exit(0);


        }
    
    }while(1);


    return 0;
}




// std::map< std::string, std::map<std::string,float> > database;

//     //let's first put the data in three vectors
//     std::vector<std::string> names = { "James", "Jane", "Janet", "John" };
//     std::vector<float> heights = { 1.7, 1.8, 1.5, 1.4 };
//     std::vector<float> weights = { 75.4, 76.5, 56.8, 52.0 };

//     //now put all of the data into the database
//     for (int i=0; i<names.size(); ++i)
//     {
//         std::map<std::string,float> data;

//         data["height"] = heights[i];
//         data["weight"] = weights[i];

//         database[names[i]] = data;
//     }

//     //now print out the entire database
//     for ( auto item : database )
//     {
//         //print out the name
//         std::cout << item.first << " : ";

//         //now print out all of the data about the person
//         for ( auto data : item.second )
//         {
//             std::cout << data.first << "=" << data.second << " ";
//         }

//         std::cout << std::endl;
//     }