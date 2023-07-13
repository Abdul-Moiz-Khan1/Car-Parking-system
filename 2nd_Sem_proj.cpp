#include <iostream>
#include "skylinee.h";
#include <fstream>
using namespace std;

struct data
{
 string f_name,l_name,cnicc,car_numm,timee;
 int hourr,slott,billl;
};

data final[100];

class car_slots 
{
protected:
    int slot[20],slot_num;
public:
    void assign_slots(int chk)
        {
        if(chk == 0)
                {
                for(int i=0; i<20;i++)
                    {
                    slot[i] = i+1;
                    }
                }
        }
    void show_slots()
        {
        cout<<"\n";
            for(int i = 0;i<20;i++)
                {
                cout<<slot[i]<<"\t";
                    if((i+1)%5 == 0 && i!=0) cout<<"\n"<<endl;
                }
        }
    void select_slot()
        {
         cout<<"\nPlease Enter Slot Number : "<<endl;
         again:
         cin>>slot_num;
             
             if(slot_num < 1 || slot_num > 20)  
                {
                 cout<<"Please Enter Valid Slot Number :"<<endl;
                 goto again;
                }   
         slot[slot_num - 1] = 0;     
               
        }
    void show_selcect()
        {
            for(int i=0; i<20;i++)
                {
                slot[i] = i+1;
                }
        slot[slot_num] = 0;
            for(int i = 0;i<20;i++)
                {
                cout<<"Available Slots : \n"<<endl;
                cout<<slot[i]<<"\t";
                if((i+1)%5 == 0 && i!=0) cout<<endl;
                }
        }
};

class info : public car_slots
{
protected:
    string first_name,last_name,cnic , car_num;
    string in_time;
    int  hours; 
public:
    void set_info()
        {
         cout<<"\n\nPlease Enter your First Name : "<<endl;
         cin>>first_name;

         cout<<"\n\nPlease Enter your Last Name : "<<endl;
         cin>>last_name; 
    
         cout<<"\nPlease Enter your CNIC : "<<endl;
         cin>>cnic;
     
         cout<<"\nPlease Enter your Entry Time(12:00AM--11:59PM) : "<<endl;
         cin>>in_time;
 
         cout<<"\nPlease Enter your Hours to stay : "<<endl;
         cin>>hours;

         cout<<"\nPlease Enter your Car Number  : "<<endl;
         cin>>car_num;
        }
    void get_info()
        {
         cout<<"First Name : "<< first_name <<endl;
         cout<<"Last Name : "<< last_name <<endl;
         cout<<"CNIC : "<< cnic <<endl;
         cout<<"Entry Time : "<< in_time <<endl;
         cout<<"No of Hours : "<< hours <<endl;
         cout<<"Car Number : "<< car_num <<endl;
         cout<<"Slot Number : "<< slot_num <<endl;
        }
    void show()
        {
         system("cls");
         cout<<"\t\t Your Bill \n"<<endl;
         get_info();
         cout<<"Total Bill : "<< hours*50 <<endl;
         cout<<"\n\n********************************************************"<<endl;
         cout<<"\tThanks for using Skyline Services"<<endl;
         cout<<"********************************************************\n\n"<<endl;
        }
    void fin(int i)
        {
        final[i].f_name = first_name;
        final[i].l_name = last_name;
        final[i].cnicc = cnic;
        final[i].timee = in_time;
        final[i].billl = hours*50;
        final[i].hourr = hours;
        final[i].car_numm = car_num;
        final[i].slott = slot_num;
        }

};

int main()
{
 ofstream output("Enteries.csv" , ios::app | ios::ate);
 int re = 0,i=0;
 system("Color 02");

  do 
    {
    skyline();
    info p1;
    p1.set_info();
    p1.assign_slots(re);  

    p1.show_slots();
    p1.select_slot();
    p1.show();
    p1.fin(i);

    i++;
    cout<<"Press 1 if you want to Enter another Entry \n\t\tOR\nPress 0 to see all entries:"<<endl;
    cin>>re;
    }while(re == 1);

system("cls");    

for(int j=0 ; j<i ;j++)
    {
     system("Color 05");

     cout<<"\n\n\t\tENTRY NO."<<j+1<<"\n\n"<<endl;
     cout<<"\t"<<"First Name :\t"<<final[j].f_name<<endl;
     cout<<"\t"<<"Last Name :\t"<<final[j].l_name<<endl;
     cout<<"\t"<<"Cnic :\t"<<final[j].cnicc<<endl;
     cout<<"\t"<<"Hours :\t"<<final[j].hourr<<endl;
     cout<<"\t"<<"Car Number :\t"<<final[j].car_numm<<endl;
     cout<<"\t"<<"Slot Number :\t"<<final[j].slott<<endl;
     cout<<"\t"<<"Entry Time :\t"<<final[j].timee<<endl;
     cout<<"\t"<<"Bill :\t"<<final[j].billl<<"Rs"<<endl;
     output<<final[j].f_name<<","<<final[j].l_name<<","<<final[j].cnicc<<","<<final[j].car_numm<<","<<final[j].timee<<","<<final[j].hourr<<","<<final[j].slott<<","<<final[j].billl<<endl;
    }
cout<<"\n*****************************************************"<<endl;
cout<<"\n\t\tTHANKS FOR USING SKYLINE\n"<<endl;
cout<<"*****************************************************\n"<<endl;
} 