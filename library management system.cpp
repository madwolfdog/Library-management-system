
//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>


//***************************************************************
//                   STRUCTURE USED IN PROJECT
//****************************************************************

struct library
{
   char book_name[40];
   char book_type[20];
   char author_name[20];
   char publ_name[20];
   float price;
    int book_no;
};


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class A
{
   public:
   void read();
   void write();
   void input(library &a);
   void search_str();
   void search_no();
};

class B:public A
{
   public:
   void insert();
   void modify();
   void display(library &a);
   void display1(library c[],int n);
   void Delete();
   void sort_str();
   void sort_no();
};
//class ends here

   int n;



//***************************************************************
//      FUNCTION TO DISPLAY ALL RECORDS
//****************************************************************

void B::display1(library c[],int n)
{
   for(int i=0;i<n;i++)
      {
       cout<<"\nBOOK NO: "<<c[i].book_no<<endl;
       cout<<"BOOK NAME: "<<c[i].book_name<<endl;
       cout<<"AUTHOR NAME: "<<c[i].author_name<<endl;
       cout<<"PUBLISHER: "<<c[i].publ_name<<endl;
       cout<<"BOOK TYPE: "<<c[i].book_type<<endl;
       cout<<"PRICE: "<<c[i].price<<endl;
        }
}


//***************************************************************
//      FUNCTION TO READ FROM FILE
//****************************************************************
void A::read()
{
   cleardevice();
   gotoxy(1,5);
   fstream f;
   f.open("library1.dat",ios::in|ios::binary);
   library a2;B b1;
   while(f.read((char*)&a2,sizeof(a2)))
           {
             b1.display(a2);
             }
   f.close();
}


//***************************************************************
//      FUNCTION TO WRITE INTO FILE
//****************************************************************

void A::write()
{
   cleardevice();
   gotoxy(1,5);
   fstream f1;
   f1.open("library1.dat",ios::out|ios::binary);
   library a3;B b2;
   cout<<"ENTER THE NO OF BOOKS:";
   cin>>n;
   for(int i=0;i<n;i++)
     {
      b2.input(a3);
      f1.write((char*)&a3,sizeof(a3));
      }
   f1.close();
}



//***************************************************************
//      ENTRY / EDIT MENU FUNCTIONS
//****************************************************************

void A::input(library &a)
{
   cout<<"\nENTER BOOK NO: ";
   cin>>a.book_no;
   cout<<"ENTER BOOK NAME: ";
   gets(a.book_name);
   cout<<"ENTER AUTHOR NAME: ";
   gets(a.author_name);
   cout<<"ENTER PUBLISHER NAME: ";
   gets(a.publ_name);
   cout<<"ENTER BOOK TYPE: ";
   gets(a.book_type);
   cout<<"ENTER PRICE: ";
   cin>>a.price;
   }

void A::search_str()
{
   cleardevice();
   gotoxy(1,5);
   char ch[40];
   cout<<"ENTER THE BOOK TO BE SEARCHED:";
   gets(ch);
   int flag=1;
   B b1;
   library a4;
   fstream f;
   f.open("library1.dat",ios::in|ios::binary);    
   while(f.read((char*)&a4,sizeof(a4)))
        {
         if(strcmpi(a4.book_name,ch)==0)
           {
            flag=0;
            cout<<"SEARCH SUCCESSFUL\n";
            b1.display(a4);
            break;
            }
         }
   if(flag==1)
     {
      cout<<"SEARCH UNSUCCESSFUL\n";
      cout<<"ENTER THE DETAILS CORRECTLY NEXT TIME";
      }
   f.close();
}

void A::search_no()
{
   cleardevice();
   gotoxy(1,5);
   int num;
   cout<<"ENTER THE BOOK NO TO BE SEARCHED:";
   cin>>num;
   int flag=1;
   fstream f;
   f.open("library1.dat",ios::in|ios::binary);
   library a2;
   B b2;
   while(f.read((char*)&a2,sizeof(a2)))
      {
       if(a2.book_no==num)
         {
          flag=0;
          cout<<"SEARCH SUCCESSFUL\n";
          b2.display(a2);
          break;
          }
        }
   if(flag==1)
     {
      cout<<"SEARCH UNSUCCESSFUL";
      cout<<"ENTER THE DETAILS CORRECTLY NEXT TIME";
      }
   f.close();
}

void B::insert()
{
   cleardevice();
   gotoxy(1,5);
   library t;
   library a2;
   int a;
   fstream f("library1.dat",ios::in|ios::binary);
   fstream f1("library2.dat",ios::out|ios::binary);
   cout<<"ENTER THE BOOK DETAILS TO BE INSERTED:\n";
   cout<<"ENTER BOOK NO: ";
   cin>>t.book_no;
   cout<<"ENTER BOOK NAME: ";
   gets(t.book_name);
   cout<<"ENTER AUTHOR NAME: ";
   gets(t.author_name);
   cout<<"ENTER PUBLISHER NAME: ";
   gets(t.publ_name);
   cout<<"ENTER BOOK TYPE: ";
   gets(t.book_type);
   cout<<"ENTER PRICE: ";
   cin>>t.price;
   cout<<"ENTER THE BOOK NO BEFORE WHICH THE DATA TO BE INSERTED: ";
   cin>>a;
   for(int i=0;i<n;i++)
        {
         f.read((char*)&a2,sizeof(a2));
         if(a2.book_no!=a)
            f1.write((char*)&a2,sizeof(a2));
         else
           {
            f1.write((char*)&t,sizeof(t));
            f1.write((char*)&a2,sizeof(a2));
            }
          }
   f.close();
   f1.close();
   n++;
   remove("library1.dat");
   rename("library2.dat","library1.dat");
   cout<<"DATA INSERTED";
 }

void B::modify()
{
   cleardevice();
   gotoxy(1,5);
   fstream f3;
   f3.open("library1.dat",ios::in|ios::out|ios::binary);
   library a5;
   char bname[40];
   char btype[20];
   char aname[20];
   char pname[20];
   float bprice;
   int bno;
   int pos;
   cout<<"ENTER THE BOOK NO OF DATA TO BE MODIFIED: ";
   cin>>bno;
   cout<<"ENTER THE MODIFIED BOOK NAME: ";
   gets(bname);
   cout<<"ENTER THE MODIFIED BOOK TYPE: ";
   gets(btype);
   cout<<"ENTER THE MODIFIED AUTHOR NAME: ";
   gets(aname);
   cout<<"ENTER THE MODIFIED PUBLISHER NAME: ";
   gets(pname);
   cout<<"ENTER THE MODIFIED BOOK PRICE: ";
   cin>>bprice;
   while(f3.read((char*)&a5,sizeof(a5)))
        {
         if(a5.book_no==bno)
           {
            pos=f3.tellg()-sizeof(a5);
            strcpy(a5.book_name,bname);
            strcpy(a5.book_type,btype);
            strcpy(a5.author_name,aname);
            strcpy(a5.publ_name,pname);
            a5.price=bprice;
            f3.seekp(pos,ios::beg);
            f3.write((char*)&a5,sizeof(a5));
            }
          }
   f3.close();
   cout<<"DATA MODIFIED";
}

void B::display(library &a)
{
   cout<<"\nBOOK NO: "<<a.book_no<<endl;
   cout<<"BOOK NAME: "<<a.book_name<<endl;
   cout<<"AUTHOR NAME: "<<a.author_name<<endl;
   cout<<"PUBLISHER: "<<a.publ_name<<endl;
   cout<<"BOOK TYPE: "<<a.book_type<<endl;
   cout<<"PRICE: "<<a.price<<endl;
}


void B::Delete()
{
   cleardevice();
   gotoxy(1,5);
   fstream f2,f3;
   f2.open("library1.dat",ios::in|ios::out|ios::binary);
   f3.open("library2.dat",ios::out|ios::binary);
   library a4;
   int bno;
   cout<<"ENTER THE BOOK NO TO BE DELETED: ";
   cin>>bno;
   while(f2.read((char*)&a4,sizeof(a4)))
        {
         if(a4.book_no!=bno)
           { 
            f3.write((char*)&a4,sizeof(a4));
            }
         }
   f2.close();
   f3.close();
   remove("library1.dat");
   rename("library2.dat","library1.dat");
   cout<<"DATA DELETED";
}

void B::sort_str()
{
   cleardevice();
   gotoxy(1,5);
   fstream f("library1.dat",ios::in|ios::binary);
   library t;
   library c[10];
   B b5;
   int n=0;
   while(f.read((char*)&c[n],sizeof(c[n])))
       {
        n++;
        }
   for(int i=0;i<n;i++)
   for(int j=0;j<n-i-1;j++)
   if(strcmpi(c[j].book_name,c[j+1].book_name)>0)
     {
      t=c[j];
      c[j]=c[j+1];
      c[j+1]=t;
     }
   b5.display1(c,n);
   cout<<"DATA IS SORTED";
}

void B::sort_no()
{
   cleardevice();
   gotoxy(1,5);
   fstream f("library1.dat",ios::in|ios::binary);
   library t,a[10];
   B b4;
   int n=0;
   while(f.read((char*)&a[n],sizeof(a[n])))
        {
         n++;
         }
   for(int i=0;i<n;i++)
   for(int j=0;j<n-i-1;j++)
   if(a[j].book_no>a[j+1].book_no)
     {
      t=a[j];
      a[j]=a[j+1];
      a[j+1]=t;
      }
   b4.display1(a,n);
   cout<<"DATA IS SORTED";
}


//***************************************************************
//      THE MAIN FUNCTION OF PROGRAM
//****************************************************************

void main()
{

//***************************************************************
//      INTRODUCTION
//****************************************************************

   clrscr();

   int gdriver=DETECT,gmode;
   initgraph(&gdriver, &gmode,"c://turboc3//bgi");

   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 9);

   outtextxy(10,10,"CS PROJECT");
   outtextxy(10,100,"**************");

   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);

   outtextxy(150,250,"CREATED BY");
   outtextxy(0,300,"ARVINDH,JITHIN AND KEERTHIVASAN");
   getch();


//***************************************************************
//      TO DISPLAY MENU
//****************************************************************

   int x;
   B a1;
   char cont;
   do
      {
       cleardevice();
       gotoxy(1,5);
       cout<<"\tMENU\n";
       cout<<"\t****\n\n";
       cout<<"1.INPUT DATA\n";
       cout<<"2.DISPLAY DATA\n";
       cout<<"3.INSERT DATA\n";
       cout<<"4.MODIFY DATA\n";
       cout<<"5.DELETE DATA\n";
       cout<<"6.SORT DATA ACCORDING TO BOOK NAME\n";
       cout<<"7.SORT DATA ACCORDING TO BOOK NO\n";
       cout<<"8.SEARCH DATA ACCORDING TO BOOK NAME\n";
       cout<<"9.SEARCH DATA ACCORDING TO BOOK NO\n";
       cout<<"10.EXIT\n";

       cout<<"\nENTER YOUR CHOICE(1-10):";
       cin>>x;
       switch(x)
             {
	case 1:a1.write();
				 break;
	case 2:a1.read();
				 break;
	case 3:a1.insert();
				 break;
	case 4:a1.modify();
				 break;
	case 5:a1.Delete();
				 break;
	case 6:a1.sort_str();
				 break;
	case 7:a1.sort_no();
				 break;
	case 8:a1.search_str();
				 break;
	case 9:a1.search_no();
				 break;
	case 10:exit(0);
	default:cout<<"\t\tWRONG CHOICE !!!!\n";
	};
     cout<<"\nDO YOU WANT TO CONTINUE(y/n):";
     cin>>cont;
     }while(cont=='y');
   getch();
}
//***************************************************************
//                      END OF PROJECT
//***************************************************************
