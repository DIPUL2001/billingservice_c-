			                  //Project-Billing Services
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class cust
{char name[40]; char mob[10]; char add[60];
public:
void input()
{cout<<"Enter full name:";
gets(name); 
cout<<"Enter mobile no.:"; 
gets(mob);
 cout<<"Enter address:";
gets(add);}
void output()
{cout<<"Name:"<<name<<"\tMobile No:"<<mob<<"\tAddress:"<<add;}
char * f1()
{return name;}
char * f2()
{return mob;}
};

void menu()
{cout<<"*BEVERAGES:       \n ";
cout<<"1.CoHub Coffee 99  ";         //*menu for order
cout<<"2.Choco Shake 75  \n ";
cout<<"3.Vanilla Shake 80 ";
cout<<"4.Sprite(1L) 85  \n";
cout<<"*BURGERS \n";
cout<<"5.Cheese burger 89";
cout<<"6.Hamburger 109 \n";
cout<<"7.Chic'n cheese 149";
cout<<"8.Vegburger 60 \n";
cout<<"*ROLLS \n";
cout<<"9.Egg Roll 40";
cout<<"10.Chicken Roll 40 \n";
cout<<"11.veg Roll 30";
cout<<"12.soya roll 45 \n";
cout<<"*PAN PIZZA \n";
cout<<"13. Onion Pizza 60";
cout<<"14.Hot Pepperoni 95 \n";
cout<<"15.Veggie Supreme 85";
cout<<"16.Margherita 75";
}

void add()
{cust c; ofstream f;
f.open("cust.dat",ios::binary|ios::app);
cout<<"Please enter your details\n";
c.input();
f.write((char *)&c,sizeof(c));
f.close();
}

void find()
{cust c; ifstream f; char x[10]; int a=0,b;
f.open("cust.dat",ios::binary);
cout<<"Enter Your Registered Moblie Number ";
gets(x);
while(!f.eof())
{f.read((char *)&c,sizeof(c));
 if(strcmp(x,c.f2())==0)
  a=1;}
 if(a==1)
   c.output();
 else
  cout<<"Enter registered mobile no.";
f.close();
}

class order
{char name[20]; int quan,price,p;
  public: void place()
 {int x;
  cout<<"\nEnter code of item"; cin>>x;
  if(x==1)
   {strcpy(name,"CoHub Coffee");
     price=99;
    cout<<"Enter quantity"; 
    cin>>quan; 
    p=price*quan;
    }
    else 
  if(x==2)
   {strcpy(name,"Choco Shake");  
    price=75;
    cout<<"Enter quantity"; 
     cin>>quan;  
      p=price*quan;
      }
     else 
    if(x==3)
   {strcpy(name,"Vanilla Shake"); 
    price=80;
    cout<<"Enter quantity"; 
    cin>>quan; 
     p=price*quan;
     }
    else 
   if(x==4)
   {strcpy(name,"Sprite (1L)");
    price=85;
    cout<<"Enter quantity";
    cin>>quan; 
    p=price*quan;
    }
     else 
  if(x==5)
   {strcpy(name,"Cheeseburger"); 
    price=89;
    cout<<"Enter quantity"; 
    cin>>quan;  
    p=price*quan;
    }
    else 
   if(x==6)
   {strcpy(name,"Hamburger"); 
    price=109;
    cout<<"Enter quantity"; 
     cin>>quan; 
     p=price*quan;
     }
  else 
if(x==7)
   {strcpy(name,"Chic'n Cheese");
    price=149;
    cout<<"Enter quantity";
    cin>>quan; 
    p=price*quan;
     }
  else
 if(x==8)
   {strcpy(name,"Vegburger"); 
    price=60;
    cout<<"Enter quantity"; 
    cin>>quan;
     p=price*quan;
      }
  else 
if(x==9)
   {strcpy(name,"Egg Roll");
   price=40;
    cout<<"Enter quantity";
 cin>>quan;
 p=price*quan;
  }
  else 
if(x==10)
   {strcpy(name,"Chicken Roll");
   price=50;
    cout<<"Enter quantity"; 
cin>>quan;
 p=price*quan;
}
  else 
if(x==11)
   {strcpy(name,"Veg Roll"); 
price=30;
    cout<<"Enter quantity"; 
cin>>quan;
 p=price*quan;
  }
  else 
if(x==12)
   {strcpy(name,"Soya Roll"); 
price=45;
    cout<<"Enter quantity";
 cin>>quan;
 p=price*quan;
  }
  else 
if(x==13)
   {strcpy(name,"Onion Pizza");
  price=60;
    cout<<"Enter quantity"; 
cin>>quan; 
p=price*quan;
}
  else 
if(x==14)
   {strcpy(name,"Hot Pepperoni");
 price=95;
    cout<<"Enter quantity";
 cin>>quan; 
p=price*quan;
}
  else 
if(x==15)
   {strcpy(name,"Veggie Supreme");
 price=85;
    cout<<"Enter quantity"; 
cin>>quan;
 p=price*quan;
}
  else 
if(x==16)
   {strcpy(name,"Margherita"); 
price=75;
    cout<<"Enter quantity"; 
cin>>quan;
 p=price*quan;
}
  else
 cout<<"\nEnter a valid code";
   }
 int f1()
  {return p;}
void output()
{cout<<"\n"<<name<<"\t"<<price<<"\t"<<quan<<"\t"<<p<<endl;}
 char * f2()
 {return name;}
};

int bill()
{int total=0;
 ifstream f;
 order p;
 f.open("Order.dat",ios::binary);
 while(f.read((char*)&p,sizeof(p)))
 {total+=p.f1();
  p.output();}
 f.close();
 return total;
}

void added()
{order o;
 ofstream f;
 f.open("Order.dat",ios::binary|ios::app);
 o.place();
 f.write((char *)&o,sizeof(o));
 f.close();
}

void remove()
{ifstream f1;
 ofstream f2; 
order o; 
char x[20]; 
int fo=0;
 f1.open("Order.dat",ios::binary);
 f2.open("temp.dat",ios::binary);
 cout<<"\nEnter name of item to be removed";
 gets(x);
  while(!f1.eof())
  {f1.read((char*)&o,sizeof(o));
    if(strcmpi(o.f2(),x)!=0)
      f2.write((char*)&o,sizeof(o));
     else fo=1;}
  if(fo==0)
   cout<<"Item not found";
   f1.close();
   f2.close();
   remove("Order.dat");
   rename("temp.dat","Order.dat");
 }
void main()
{char a,c,y; cust s; int b,t; order o; ofstream f;
clrscr();
cout<<"\t\t\t\tWELCOME TO COHUB";          
cout<<"\n are here for the first time??(y/n)\n";
cin>>a;
if(a=='Y'|| a=='y')
    add();
 else
  if(a=='N' || a=='n')
   find();
 else
 cout<<"Please enter a valid choice\n";
if(a=='y'||a=='Y'||a=='n'||a=='N')
do{
{cout<<"\nWHAT DO YOU WISH TO DO??\n";
cout<<"\n1.Place your order\n";
cout<<"\n2.View your bill\n";
cout<<"\n3.Modify your order\n";
cout<<"4.Exit";
  cin>>b;
 if(b==1)
  {menu();
    f.open("Order.dat",ios::binary);
   do{o.place();
    f.write((char*)&o,sizeof(o));
    cout<<"\nDo you want to add anything else"; cin>>c;
   }while(c=='y'||c=='Y');
    f.close();
   }
 if(b==2)
 {t=bill();
  cout<<"\nGST is 9% of basic";
  cout<<"\nBasic = "<<t;
  cout<<"\nTotal = "<<(0.09*t)+t;}
 if(b==3)
 {cout<<"\n1.Add item\n2.Remove item";
   int n;
   cin>>n;
   switch(n)
   {case 1:added(); break;
    case 2:remove(); break;
    default:cout<<"\nEnter valid choice";
    }
   }
cout<<"\nDo you want to continue??(y/n)"; 
cin>>y;
}
}while(y!='n');
getch();
}