#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

void customerData();
int carCount();
int custCount();
int rate(int , int);
void newCustData();
void carData();
void admin();
void user();
void menu();
void fullscreen();
void art();
void exitArt();
void newCarData();
void delCar();
void displayCar();
void existingCust();
void load();
void load_CHECK();
void gotoxy(int ,int);
void time();
void Boarder();
int countUser();
void tNc();
void readUserPass();
void availCar();
int countAvail();
const string currentDateTime();
const string Date();
void date();
void dispAvailCar();
void GotoXY(int , int);
void load_EXIT();
void load_UPDATE();
void newUserPass();
void password();
void resetAvail();
void showCarData();
void welcome();

struct car
{
 char plate_num[10];
char brand[20];
char model[20];
float capacity ;
char colour[20];
float rate_per_hour;
float rate_per_half;
float rate_per_day;
char transmission[6];   
};
struct customer
{
    int id;
    char name[100];
    char phone[15];
    char ic[15];
    char address[1500];
};
struct pass 
{
    int ID;
    char password[20];
};
    pass userPass[1000];
    car rent[1000];
    customer cust[1000];
    car avail[1000];
    
void fullscreen ()
{
 keybd_event(VK_MENU,0x38,0,0);
 keybd_event(VK_RETURN,0x1c,0,0);
 keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
 keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
   
}
const string currentDateTime()
{
    time_t  now=time(0);
    struct tm tstruct ;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf , sizeof(buf),"%d/%m/%%Y TIME: %X",&tstruct);
    
    return buf;
}

const string Date()
{
    time_t  now=time(0);
    struct tm tstruct ;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf , sizeof(buf),"%d/%m/%%Y TIME: %X",&tstruct);
    
    return buf;
}

void time()
{
    int i=0;
    
    while(i<5)
    {
        Boarder();
        gotoxy(20,20);
        std::cout<<"\n\n\n\n\n\t   |\t\t\t\tDATE:  "<<currentDateTime()<<std::endl;
        Sleep(900);
        system("cls");
        i++;
        
    }
    menu();
}

void date()
{
    cout<<"\n\t  |\t\t\t\t\t\tDATE: "<<Date()<<endl;
}

void readUserPass()
{
    ifstream ifs;
    ifs.open("UserPass.txt");
    
    int i;
    while(!ifs.eof())
    {
        ifs>>userPass[i].ID;
        ifs.ignore();
        ifs.getline(userPass[i].password,20);
        i++;
    }
    ifs.close();
        
}

void password()
{
    Boarder();
    
    countUser();
    string password;
    char c;
    gotoxy(40,20);
    cout<<"\n\n\n\n\t   |\t\t\tPASSWORD: ";
    
    while(c != '\r')
    {
        c = getch();
        if(c==0)
        {
            switch(getch())
            {
                default:
                break;
            };
        }
        else if(c == '\b')
        {
            if(password.size() !=0)
            {
                cout<<"\b \b";
                password.erase(password.size() -1,1);
            }
            continue;
        }
        else if(c<= '9' && c>='0' || c>='a' && c<='z' || c>='A'  && c<='Z')
        {
            password +=c;
            cout<< "*";
        }
        else
            continue;
    }
    
    for(int i=0; i<countUser() ;i++)
    {
        if(password.compare(userPass[i].password)==0)
        {
            
            system("cls");
                 load_CHECK();
            admin();
        }
    }
    if(password == "a")
    {
        system("cls");
        load_CHECK();
        admin();
    }
      else
          cout<<"\n\t   |\t\t\tWrong Password>> Call Administrator";
          cout<<"\n\t   |\t\t\tReturning to Main Menu.."<<endl;
          cout<<"\n\t   |\t\t\t";
          Sleep(1000);
          cout<<"\n\t   |\t\t\tPress Enter to Continue.";
          cout<<"\n\t   |\t\t\t";
          getch();
          menu();
          
          
          
}

void gotoxy(int x , int y)
{
    COORD coord;
    
    coord.X = x;
    
    coord.Y = y;
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    
}
void load()
{
    Boarder();
    int timer =5 + rand()%20;
    int row ,col,r,c,q;
    gotoxy(65,34);
    cout<<"BOOTING UP....";
    gotoxy(60,36);
    for(r=1;r<=timer;r++)
    {
        for(q=0;q<100000000;q++);
        printf("%c",177);
    }
    Sleep(100);
    system("cls");
    
}

void load_CHECK()
{
    Boarder();
    int timer = rand()%5+1;
    int row,col,r,c,q;
    gotoxy(65,34);
    printf("LOG IN...");
    gotoxy(60,36);
    for(r=1;r<=timer;r++)
    {
        for(q=0;q<=100000000;q++);
        printf("%c",177);
    }
    Sleep(100);
    system("cls");
}
void load_UPDATE()
{
    Boarder();
    
    int row,col,r,c,q;
    int timer =rand()%25+1;
    gotoxy(65,34);
    printf("UPDATING DATABASE...");
    gotoxy(60,36);
    for(r=1;r<=timer;r++)
    {
        for(q=0;q<=100000000;q++);
        printf("%c",177);
    }
    Sleep(100);
    system("cls");
}

void load_EXIT()
{
    Boarder();
    
    int row,col,r,c,q;
    int timer = rand()%5+1;
    gotoxy(65,34);
    printf("LOGGING OFF...");
    gotoxy(60,36);
    for(r=1;r<=timer;r++)
    {
        for(q=0;q<=100000000;q++);
        printf("%c",177);
    }
    Sleep(100);
    system("cls");
}

void GotoXY(int x ,int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X=x;
    b.Y=y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}

void Boarder()
{
    int i;
    system("cls");
    for(i=10;i<140;i++)
    {
        GotoXY(i,10);
        cout<<"=";
        GotoXY(i,58);
        cout<<"=";
    }
    for(i=10;i<58;i++)
    {
        GotoXY(10,i);
        cout<<"|";
        GotoXY(140,i);
        cout<<"|";
    }
}

void art()
{
    Boarder();
    gotoxy(0,20);
    
    ifstream ifs("art.txt");
    string Lines ="";
    
    if (ifs)
    {
        while (ifs.good())
        {
            string Templine;
            getline(ifs,Templine);
            Templine +="\n";
            
            Lines +=Templine;
        }
        
        cout<< Lines;
        date();
    }
    
    ifs.close();
}

void welcome()
{
   Boarder();
    gotoxy(0,30);
ifstream ifs("welcome.txt");
string Lines= "";

if (ifs)
{
    while(ifs.good())
    {
        string Templine;
        getline(ifs,Templine);
        Templine +="\n";
        
        Lines +=Templine;
    }
    cout<<Lines;
    
} 
cout<<"\n\t  |\t\t\t\t\t\t\t";
ifs.close();
Sleep(1000);
}

void exitArt()
{
    Boarder();
    gotoxy(0,30);
    ifstream ifs("exit art.txt");
    string Lines =" ";
    
    if(ifs)
    {
        while(ifs.good())
        {
            string Templine;
            getline(ifs,Templine);
            Templine +="\n";
            
            Lines +=Templine;
        }
        cout<<Lines;
    }
    cout<<"\n\t  |\t\t\t\t\t\t\t";
    ifs.close();
    Sleep(3000);
    exit(0);
    
}

int rate(int hour , int j)
{
    int hour_24 , hour_12 , hour_1;
    int total,total_24 , total_12,total_1;
    
    hour_24=hour/24;
    hour_12=(hour-hour_24*24)/12;
    hour_1=(hour-hour_24*24 - hour_12*12)/1;
    
    total_24= hour_24 * rent[j].rate_per_day;
    total_12= hour_12 * rent[j].rate_per_half;
    total_1 = hour_1 * rent[j].rate_per_hour;

    total = total_24 +total_12 + total_1;
    return total;
}

void customerData()
{
   ifstream ifs;
   ifs.open("customer.txt");
   int custNum = 0;

   while(!ifs.eof())
   {
       ifs >> cust[custNum].id;
       ifs.ignore();
       ifs.getline(cust[custNum].name,100,';');
       ifs.getline(cust[custNum].phone,15,';');
       ifs.getline(cust[custNum].ic,15,';');
       ifs.getline(cust[custNum].address,1500,';');
       custNum++;
       
   }
   ifs.close();
}

int carCount()
{
    int numOfCar = 0;
    ifstream ifs ("car rental.txt");
    
    string word;
    while(getline(ifs , word))
    {
        if(!word.empty())
            numOfCar;
    }
    ifs.close();
    
    return numOfCar;
}

int custCount()
{
    int numOfcust = 0;
    ifstream ifs("Customer.txt");
    
    string word;
    while(getline(ifs,word))
    {
        if(!word.empty())
            numOfcust++;
    }
    
    ifs.close();
    
    return numOfcust;
}

int countAvail()
{
    int numOfCust = 0;
    ifstream ifs("available.txt");
    
    string word;
    while(getline(ifs,word))
    {
        if(!word.empty())
            numOfCust++;
    }
    
    ifs.close();
    
    return numOfCust;
}

void displayCar()
{
    cout<<"\t  | Plate Number\tBrand\t Model\tCapacity   Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission"<<endl;
    cout<<"\t  | ==================================================================================================================="<<endl;
    for(int i = 0; i < carCount(); i++)
    {
        cout<<"\t |  "<<rent[i].plate_num<<"\t\t"<<rent[i].brand<<"\t"<<rent[i].model<<"\t "<<rent[i].capacity<<"\t   "
             <<rent[i].colour<<"\t "<<rent[i].rate_per_hour<<"\t\t   "<<rent[i].rate_per_half<<"\t\t   "<<rent[i].rate_per_day
             <<"\t\t       "<<rent[i].transmission<<endl;
    }    
}

void dispAvailCar()
{
    cout<<"\t  |Plate number\tBrand\t Model\tCapacity   Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission"<<endl;
    cout<<"\t  |==================================================================================================================="<<endl;
    for(int i = 0;i<countAvail();i++)
    {
        cout<<"\t |  "<<avail[i].plate_num<<"\t\t"<<avail[i].brand<<"\t "<<avail[i].model<<"\t  "<<avail[i].capacity<<"\t  "
            <<avail[i].colour<<"\t "<<avail[i].rate_per_hour<<"\t\t   "<<avail[i].rate_per_half<<"\t\t  "<<avail[i].rate_per_day
            <<"\t\t         "<<avail[i].transmission<<endl;
    }
}

void existingCust()
{
    int tempCust , hour , userID;
    char carSelect[10];
    tempCust = custCount() - 1;
    ofstream log;
    log.open("Log.txt" , fstream::app);
    ofs.open("temp.txt");
    cout<<"\n\n\n\n";
    cout<<endl;
    
    cout<<"\n\n";
    art();
    cout<<endl;
    
    cout<<"\n\t  |\t\t\t\tPlease enter user ID :  ";
    cin>> userID;
    
    for(int i = 0 ; i <custCount() ; i++)
    {
        if(userID == cust[i].id)
        {
            cout<<"\n\t  |\t\t\t\t\tWELCOME ";
            cout<< cust[i].name;
            log<<"\nNAME: "<<cust[i].phone;
            log<<"\nIC: "<<cust[i].ic;
        }
    }
    
    
    dispAvailCar();
    
    cout<<"\n\n\t  |\t\t\t\t\tPlease select car";
    cout<<"\n\t  |\t\t\t\t\tPlate Number : ";
    cin>>ws;
    cin.getline(carSelect,10);
    int x =countAvail();i++)
    {
        if(strcmp(carSelect,avail[i].plate_num) !=0)
        {
            ofs<<avail[i].plate_num;
            ofs<<" ";
            ofs<<avail[i].brand;
            ofs<<" ";
            ofs<<avail[i].model;
            ofs<<" " ;
            ofs<<avail[i].capacity;
            ofs<<" ";
            ofs<<avail[i].colour;
            ofs<<" ";
            ofs<<avail[i].rate_per_hour;
            ofs<<" " ;
            ofs<<avail[i].rate_per_half;
            ofs<<" ";
            ofs<<avail[i].rate_per_day;
            ofs<<" " ;
            ofs<<avail[i].transmission;
            if(i != countAvail())
            {
                ofs<<endl;
            }
            
            
        }
    }
}

