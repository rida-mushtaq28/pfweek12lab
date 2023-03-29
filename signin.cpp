#include <iostream>
#include<fstream>
using namespace std;

//Prototypes of Functions
int takeChoice();
bool isvalidUserName(string name);
bool signIn(string name,string password);
void signUpArray(string name,string password);
void storeInFile(string name,string password);
void readDataFromData();

void viewUsers();
int userCount=0;

//Arrays
string n_ame[100];
string p_assword[100];

 
 main()
 {
    readDataFromData();
    int option=4;
    bool decision;
    string name;
    string password;
    while(option!=0)
      {
        option=takeChoice();
         if(option==1)
          {
            cout << "Enter Name:"<<endl;
            cin >> name;
            cout << "Enter Passsword"<< endl;
            cin >> password;
            decision=isvalidUserName(name);
            if(decision==true)
             {
                signUpArray(name,password);
                storeInFile(name,password);
                cout <<"Signed up successfully!!"<<endl;
             }
             else
             {
                cout << "UserName Already Exist!!"<<endl;

             }
        
          }
          else if(option==2)
          {
            cout << "Enter Name:"<<endl;
            cin >> name;
            cout << "Enter Passsword"<< endl;
            cin >> password;
            decision=signIn(name,password);
            if(decision==true)
             {
                cout << "LOgin SuccesFully"<<endl;
             }
             else
             {
                cout<<"Invalid Credential"<<endl;
             }
          }  

          else if(option==3)
          { 
            viewUsers();
          }  
      }

 }
int takeChoice()
 {
    int option;
    cout << "0. Exit"     <<endl;
    cout << "1. SignUp"<<endl;
    cout << "2. SignIn"<<endl;
    cout << "3. ViewUsers"<<endl;
    cout << "Enter the OPtion:"<<endl;
    cin>>option;
    return option;
 }

void signUpArray(string name,string password)
  {
    n_ame[userCount]=name;
    p_assword[userCount]=password;
    userCount++;
  }
  
void storeInFile(string name,string password)
  {
    fstream file;
    file.open("user.txt",ios::app);
    file<<name<<endl;
    file<<password<<endl;
    file.close();
  } 

void viewUsers()
  {
     cout << "UserName" << "\t\t" << "Passwords" << endl<< endl;
    for(int x=0;x<userCount;x++)
     {
        cout << n_ame[x] << "\t\t" <<  p_assword[x] << endl;
  
     }
  } 

bool signIn(string name,string password)
 {
    bool flag=false;
    for (int x=0 ;x < userCount;x++)
     {
        if(n_ame[x]==name && p_assword[x]==password)
         {
            flag=true;
            break;
         }
     }
          return flag;
 }

 bool isvalidUserName(string name)
  {
    bool flag=true;
    for (int x=0 ;x < userCount;x++)
     {
        if(n_ame[x]==name)
         {
            flag=false;
            break;
         }
     }
          return flag;
  }

 void readDataFromData()
  {
    string name;
    string password;
    fstream file;
    file.open("user.txt",ios::in);
    while(getline(file,name) && getline(file,password))
     {
        n_ame[userCount]=name;
        p_assword[userCount]=password;
        userCount++;
     }
     file.close();
  }
    
    

