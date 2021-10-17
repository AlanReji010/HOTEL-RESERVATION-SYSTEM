#include<iostream>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

//****************************
//      CLASS USED IN PROJECT
//****************************

class hotel
{
int room_no;
char name[20];
char address[50];
char phone[10];
  public:
void header()
{
  cout<<"\n\t\t\t  HOTEL MANAGEMENT PROJECT";
  cout<<"\n\t\t\t*~*~*~*~*~*~*~*
}
int check(int);
    void login();
    void main_menu();
    void disp_admin();
    void add();
    void display();
    void rooms();
    void edit();
    void modify(int);
    void delete_rec(int);
};

//****************************
//     function declaration
//****************************

void hotel::main_menu()
  {
long ctr=0; 
char choice;
while(1)
{
system("cls");
header();
cout<<"\n   MAIN MENU";
cout<<"\n  ***********";
cout<<"\n\n  1.Book a room";
cout<<"\n  2.login as administrator";
cout<<"\n  3.Exit";
cout<<"\n\n\n  Enter your choice :";
cin>>choice;
switch(choice)
{
case '1':add();
break;
case '2':disp_admin();
break;
case '3':exit(0);                    
break;
default:
 
cout<<"\n\n\n\tWrong choice!!!\n";
for(ctr=0;;)
{  
ctr++;
if(ctr==10000000) break;
} 
}
}
}
//****************************
//   function to validate login
//****************************
void hotel::login()  
  {
  system("cls");
  header();
  cin.ignore();
  char user[20],pass[20];
  cout<<"\n  Enter username :";
  gets(user);
  cout<<"\n  Enter your password :";
  gets(pass);
  if(!(strcmp(user,"a")==0&&
  {
cout<<"\n\n\n\t INVALID LOGIN!! TRY AGAIN..\n";
    login();
  } 
  cout<<"\n\n  Login successful...\n\n\n  ";
  system("pause");
  }   
   
//**************************** 
//   function to display admin menu
//****************************
      
void hotel::disp_admin()
  { 
login();
int choice;
while(choice!=5)
  {
system("cls");
header();
cout<<"\n   MAIN MENU[admin]";
cout<<"\n  ***********";
cout<<"\n\n  1.Book a room";
cout<<"\n  2.Customer record";
cout<<"\n  3.Rooms alloted";
cout<<"\n  4.Edit record";
cout<<"\n  5.Exit";
cout<<"\n\n\n  Enter your choice :";
cin>>choice;
switch(choice)
  {
case 1:add();
      break;
case 2:display();
      break;
case 3:rooms();
      break;
case 4:edit();
      break;
case 5:                       
      break;
default:
     {
  cout<<"\n\n\n\tWrong choice!!!\n";
  system("pause");
     }              
  }
  }
  }
//*************************
//   function to add rooms
//*************************
void hotel::add()
  {
system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);
cout<<"\n\t Enter Customer Details";
cout<<"\n\t*******************
cout<<"\n\nRoom no:";
cin>>r;
flag=check(r);
if(flag)
cout<<"\nSorry...Room is already booked\n";
else
{
room_no=r;
cin.ignore();
cout<<"\nName:";
gets(name);
cout<<"\nAddress:";
gets(address);
cout<<"\nPhone no:";
gets(phone);
fout.write((char*)this,sizeof(
cout<<"\nRoom is booked!!!\n";
}
    system("pause");
    fout.close();
  }
//**************************** 
//   function to display specific customer details
//****************************
void hotel::display()
  {
system("cls");
header();
ifstream fin("Record.dat",ios::in);
int r,flag;
cout<<"\n Enter room no:";
cin>>r;
while( fin.read((char*)this,sizeof(
{
   if(room_no==r)
   {
   system("cls");
   cout<<"\n  Customer details";
   cout<<"\n *~*~*~*~*~*~*~*~*~*";
   cout<<"\n\n Room no:"<<room_no;
   cout<<"\n Name:"<<name;
   cout<<"\n Address:"<<address;
   cout<<"\n Phone no:"<<phone;
   cout<<"\n";
   flag=1;
   break;
   }
   else flag=0;
}
   if(flag==0)
   cout<<"\n** SORRY...Room no. not found or vacant!! **\n";
   cout<<"\n\n\n\n";
   system("pause");
   fin.close();
  }
//****************************
//   function to display allotted rooms and customer details
//****************************
void hotel::rooms()
  {         
system("cls");
header();
ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t List of rooms alloted";
cout<<"\n\t\t\t***************
cout<<"\n\n\n\tROOM NO.\tNAME\t\tADDRESS\t\tPHONE NO.\n";
while(fin.read((char*)this,
   {    
   cout<<"\n\n\t"<<room_no<<"\t\
   }
  cout<<"\n\n";
  system("pause");
  fin.close();
  }
//**************************** 
//   function to edit coustomer records
//****************************
void hotel::edit()
  {   
system("cls");
header();
int choice,r;
cout<<"\n Edit menu";
cout<<"\n***********";
cout<<"\n\n 1.Modify customer record";
cout<<"\n\n 2.Delete customer record";
cout<<"\n\n Enter your choice :";
cin>>choice;
system("cls");
   
   switch(choice)
   {
   case 1:  cout<<"\n Enter room no:";
cin>>r;
modify(r);
break;
       case 2:  cout<<"\n Enter room no:";
cin>>r;
    delete_rec(r);
                break;
       default:               
cout<<"\n\n ** WRONG CHOICE!! **";
cout<<"\n\n";
system("pause"); 
   
   }
  }
int hotel::check(int r)
  {    
int flag=0;
ifstream fin("Record.dat",ios::in);
while(fin.read((char*)this,
   {
   if(room_no==r)
   {
  flag=1;
  break;
   }
   }
   fin.close();
   return(flag);
  }
//****************************
//   function to modify customer details
//****************************
void hotel::modify(int r)
  {
header();
long pos,flag=0;
fstream file("Record.dat",ios::in|ios:
while(file.read((char*)this,
   {
   pos=file.tellg();    
   if(room_no==r)
   {
   cout<<"\n  Enter new details";
   cout<<"\n ********************";
   cin.ignore();
   cout<<"\n\n Name :";
   gets(name);
   cout<<"\n Address :";
   gets(address);
   cout<<"\n Phone no :";
   gets(phone);
   file.seekg(pos);
   file.write((char*)this,
   cout<<"\n  RECORD IS MODIFIED.. \n\n\n";
   system("pause");
   flag=1;
   break;
   }
   else flag=0;
   }
if(flag==0)
cout<<"\n ** SORRY...ROOM NO. NOT FOUND OR VACANT!! ** \n\n\n";
file.close();
system("pause");
   }
//**************************** 
//   function to delete specific records
//****************************
void hotel::delete_rec(int r)
  {
  header();
  int flag=0;
  char ch;
  ifstream fin("Record.dat",ios::in);
  ofstream fout("temp.dat",ios::out);
  while(  fin.read((char*)this,sizeof(
   {
if(room_no==r)
  {
cout<<"\nName:"<<name;
cout<<"\nAddress:"<<address;
cout<<"\nPhone no.:"<<phone;
cout<<"\n\nDo you want to delete this record(y/n):";
cin>>ch;
   if(ch=='y') 
   { 
fout.write((char*)this,sizeof(
flag=1; 
cout<<"\n\tRECORD IS DELETED..\n";     
    system("pause");
   } 
   
  }
else
fout.write((char*)this,sizeof(
   }
  fin.close();
  fout.close();
  if(flag==0)
{
  cout<<"\nSorry room no. not found or vacant!! \n";
  system("pause");
    }
  else
{
remove("Record.dat");
}
  }
  
//****************************
//    main function of program
//****************************

int main()
  {
hotel h;
system("cls");
cout<<"\n\t\t\t  HOTEL MANAGEMENT PROJECT";
cout<<"\n\t\t\t*~*~*~*~*~*~*~*
cout<<"\n\n\n\n\t\t\t\tMade by : ";
cout<<"GROUP B\n\n";
cout<<"\t\t\t\tMembers : * Milan Joseph Sebastian\n\t\t\t\t\t  * Alan Reji\n\t\t\t\t\t  * Ignatius Ealias Roy"<<endl;
cout<<"\n\n\n\n\n\n\n\t\t\t\t"
system("pause");
h.main_menu();
return 0;
  }
  
//****************************
//     END OF PROJECT                
//****************************
