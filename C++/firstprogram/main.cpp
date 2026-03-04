#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector> 
#include <fstream>

using namespace std;


void new_acc()
{
 std::cout<<"Creating a New Account--\n";
 string name;
 string pid;
 string accid= to_string(100000 + std::rand() % (999999-100000 + 1));
 string datee=__DATE__;

 std::cout<<"Enter Name of Account Holder\n";
 cin.ignore();
 getline(std::cin,name);
 std::cout<<"Enter Person ID \n";
 std::cin>>pid;
 accid=pid+accid+to_string(1000 + std::rand() % (9999-1000 + 1));

 std::vector<string> ent={name,pid,accid,datee,to_string(0)};
 std::cout<<accid<<std::endl;
 std::ofstream objcs("bank.csv",std::ios::app);
 if(objcs.is_open())
 {
  for(string cel:ent)
  {
   objcs<<cel<<",";
  }
  objcs<<"\n";
  objcs.close();
  std::cout<<"ACCOUNT SUCCESSFULLY CREATED\n";

 }
 else{std::cout<<"ERROR CREATING ACCOUNT!\n";}
}

void chang()
{
 std::ifstream objrd("bank.csv",std::ios::app);
 std::vector<std::vector<string>> dataread;
 std::vector<string> ech;
 string lin;
 while(getline(objrd,lin))
 {
   string ele;
   for(int j=0;j<=(lin.size()-1);j++)
   {
    if(lin[j]==',')
    {
      ech.push_back(ele);
      ele="";
    }
    else
    {
      ele=ele+lin[j];
    }

   }
   dataread.push_back(ech);
   ech={};

 }

 objrd.close();
 
 string cho;
 std::cout<<"Depositing/Withdrawing Money--\n";
 std::cout<<"Enter Account Id of the account you wish to Deposit or Withdraw from\n";
 string ac;
 cin>>ac;
 std::cout<<"Press 1 to deposit money\nPress 0 to withdraw money\n";
 std::cin>>cho;
 int fincho=stoi(cho);
 int val=0;
 int amt;
 switch(fincho)
       {
         case 0:
            std::cout<<"Enter Amount to Withdraw\n";
            std::cin>>amt;
            val= -1*amt;
            break;
         case 1:
            std::cout<<"Enter Amount to Deposit\n";
            std::cin>>amt;
            val=amt;
            break;
         default:std::cout<<"WRONG INPUT!\n";
                 break;

        }
 for(int i=0;i<=(dataread.size()-1);i++)
 {
   if(dataread[i][2]==ac)
   {
    dataread[i][4]=to_string(stoi(dataread[i][4])+(val));
   }
 }

 std::ofstream objwri("bank.csv");
 for(int i=0;i<=(dataread.size()-1);i++)
 {
   string put=dataread[i][0]+","+dataread[i][1]+","+dataread[i][2]+","+dataread[i][3]+","+dataread[i][4];
   objwri<<put<<"\n";
 }

 objwri.close();
 
}

void tra()
{

}
void dis()
{

}

void dis_all()
{

}

int main()
{
    std::cout<<"HELLO, WELCOME TO SIMPLE BANKING SYSTEM\n";
    std::cout<<"--Made by Abhirup Banik--\n";
    int strstp=1;

    while(strstp==1)
    {
      int choice=-1;
      std::cout<<"Enter your Choice\nPress 1 to Create a New Account\nPress 2 to Deposit/Withdraw Money From an Account\nPress 3 to Transfer Money Between Accounts\nPress 4 to Display Information About an account \nPress 5 to Display All Existing Accounts\n";
      cin>>choice;
      switch(choice)
       {
         case 1:new_acc();
             break;
         case 2:chang();
             break;
         case 3:tra();
             break;
         case 4:dis();
             break;
         case 5:dis_all();
             break;
         default:std::cout<<"WRONG INPUT!\n";

        }

        cout<<"Do you Want to Continue?\n[Press 1 for Yes/Press 0 for No]\n";
        cin>>strstp;
    }
    
    return 0;
}