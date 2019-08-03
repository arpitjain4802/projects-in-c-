
//-----------------------------------------------------------------
//   HEADER FILES
//--------------------------------------------------------------

#include<fstream.h>
#include<stdlib.h>
#include<process.h>              // used for exit
#include<string.h>
#include<dos.h>                  // used for delay and date
#include<conio.h>
#include<stdio.h>               // used for gets

void main();
float amount=0;

//--------------------------------------------------------------
//   CLASS DEFINE
//--------------------------------------------------------------

class shop
{
	int qty;
	char itemname[20];
	float price;

	public:

	int month;
	int year;
	int date;
	int qty1;
	long billno;
	int temp;
	float total;
	float final;

	void getdata()                       //function to take data
	{
		cout<<"enter item name";
		gets(itemname);
		cout<<"enter quantity";
		cin>>qty;
		cout<<"enter price";
		cin>>price;
	}  
	float call(float amount)              //function to show amount
	{
		cout<<"\nitemname="<<itemname;
		cout<<"\tquantity purchased="<<qty1;
		cout<<"\nprice="<<price;
		total=price*qty1;
		cout<<"\ttotal="<<total;
		amount=amount+total;
		return amount;
	}
	void copy(shop s)             //function to update quantity
	{
		strcpy(itemname,s.itemname);
		price=s.price;
		qty=qty-s.qty1;
	}
	char * returnname()
	{
		return itemname;
	}
	char returnprice()
	{
		return price;
	}
	int retmonth()
	{
		return month;
	}
	int retyear()
	{
		return year;
	}
	void show()                     // function to display data
	{
		cout<<"\nitem name is "<<itemname;
		cout<<"\t quantity available is "<<qty;
		cout<<"\t price is "<<price;
	}
	int check()                     // function to check quantity
	{
		if(qty1<=qty)
			return 1;
		else
			return 0;
	}

	void display()          // function to display data for menu
	{
		cout<<"\titem name: "<<itemname;
		cout<<"\tprice is "<<price;
	}
	void go()       	       //function to show bills
	{       delay(1500);
		cout<<"\nbill no. "<<billno;
		cout<<"\ndate "<<date<<month<<year;
		cout<<"\namount "<<final;
	}
	int print(int p)                    //function to print bill
	{
		if(p==1)
		{
			cout<<"\nBILL NO: "<<billno;
			cout<<"\t\tdate: "<<date<<month<<year;
		}
		cout<<"\nitem name: "<<itemname;
		cout<<"\tquantity: "<<qty1;
		cout<<"\tprice: "<<price;
		cout<<"\ttotal price: "<<(price*qty1);
		p++;
		return p;
	}
	void calcbillno()
	{
		randomize;
		billno=random(10000);
	}
	void datecalc()
	{
	   struct date d;

	  getdate(&d);
	   year=d.da_year;
	   date=d.da_day;
	   month=d.da_mon;
	}

	int retqty()
	{
		return qty1;
	}


	void calcqty( int m )
	{
		qty1+=m;
		temp=1;
	}

};

//-----------------------------------------------------------------
//   FUNCTIONS PROTOTYPES
//-----------------------------------------------------------------

void ffloor();
void sfloor();
void tfloor();
void watch();
void shoe();
void pantaloons();
void apple();
void samsung();
void electronics();
void dominos();
void pizza_hut();
void mcd();

void create(int x)              // CREATE FILE
{
	clrscr();
	int ch;
	cout<<"\nenter 1 to create a new file";
	cout<<"\nenter 2 to add in previous file";
	cin>>ch;
	if(ch==1)
	{
		ofstream fout;
		if(x==1)
			fout.open("watch.dat",ios::binary);
		else if(x==2)
			fout.open("shoe.dat",ios::binary);
		else if(x==3)
			fout.open("pantaloons.dat",ios::binary);
		else if(x==4)
			fout.open("apple.dat",ios::binary);
		else if(x==5)
			fout.open("samsung.dat",ios::binary);
		else if(x==6)
			fout.open("electronics.dat",ios::binary);
		else if(x==7)
			fout.open("dominos.dat",ios::binary);
		else if(x==8)
			fout.open("pizza.dat",ios::binary);
		else if(x==9)
			fout.open("mcd.dat",ios::binary);

		char choice='y';
		shop s1;
		while(choice=='y')
		{
			cout<<"ENTER DATA\n";
			s1.getdata();
			fout.write((char*)&s1,sizeof(s1));
			cout<<"do you want to write more(y/n) ";
			cin>>choice;
		}
		fout.close();
	}
	else if(ch==2)
	{
		ofstream fout;
		if(x==1)
			fout.open("watch.dat",ios::binary|ios::app);
		else if(x==2)
			fout.open("shoe.dat",ios::binary|ios::app);
		else if(x==3)
			fout.open("pantaloons.dat",ios::binary|ios::app);
		else if(x==4)
			fout.open("apple.dat",ios::binary|ios::app);
		else if(x==5)
			fout.open("samsung.dat",ios::binary|ios::app);
		else if(x==6)
			fout.open("electronics.dat",ios::binary|ios::app);
		else if(x==7)
			fout.open("dominos.dat",ios::binary|ios::app);
		else if(x==8)
			fout.open("pizza.dat",ios::binary|ios::app);
		else if(x==9)
			fout.open("mcd.dat",ios::binary|ios::app);

		char choice='y';
		shop s1;
		while(choice=='y')
		{
			cout<<"ENTER DATA\n";
			s1.getdata();
			fout.write((char*)&s1,sizeof(s1));
			cout<<"do you want to write more(y/n) ";
			cin>>choice;
		}
		fout.close();
	 }
}
void read(int x)        	// READ FILE
{
	clrscr();
	ifstream fin;
		if(x==1)
			fin.open("watch.dat",ios::binary);
		else if(x==2)
			fin.open("shoe.dat",ios::binary);
		else if(x==3)
			fin.open("pantaloons.dat",ios::binary);
		else if(x==4)
			fin.open("apple.dat",ios::binary);
		else if(x==5)
			fin.open("samsung.dat",ios::binary);
		else if(x==6)
			fin.open("electronics.dat",ios::binary);
		else if(x==7)
			fin.open("dominos.dat",ios::binary);
		else if(x==8)
			fin.open("pizza.dat",ios::binary);
		else if(x==9)
			fin.open("mcd.dat",ios::binary);

	shop s1;
	while(fin.read((char*)&s1,sizeof(s1)))
	{
		s1.show();
	}
	fin.close();
}
void searchname(int x)              // FUNCTION TO SEARCH RECORD
{
	clrscr();
	ifstream fin;
		if(x==1)
			fin.open("watch.dat",ios::binary);
		else if(x==2)
			fin.open("shoe.dat",ios::binary);
		else if(x==3)
			fin.open("pantaloons.dat",ios::binary);
		else if(x==4)
			fin.open("apple.dat",ios::binary);
		else if(x==5)
			fin.open("samsung.dat",ios::binary);
		else if(x==6)
			fin.open("electronics.dat",ios::binary);
		else if(x==7)
			fin.open("dominos.dat",ios::binary);
		else if(x==8)
			fin.open("pizza.dat",ios::binary);
		else if(x==9)
			fin.open("mcd.dat",ios::binary);

	shop s1;
	char name1[20];
	cout<<"enter item name whose details you want to search for ";
	gets(name1);
	while(fin.read((char*)&s1,sizeof(s1)))
	{
	       if(strcmpi(s1.returnname(),name1)==0)
	       s1.show();
	}
	fin.close();
}
void Delete(int x)	     // FUNCTION TO DELETE RECORD
{
	clrscr();
	ofstream fout;
	ifstream fin;
	fout.open("temp2.dat",ios::binary);
		if(x==1)
			fin.open("watch.dat",ios::binary);
		else if(x==2)
			fin.open("shoe.dat",ios::binary);
		else if(x==3)
			fin.open("pantaloons.dat",ios::binary);
		else if(x==4)
			fin.open("apple.dat",ios::binary);
		else if(x==5)
			fin.open("samsung.dat",ios::binary);
		else if(x==6)
			fin.open("electronics.dat",ios::binary);
		else if(x==7)
			fin.open("dominos.dat",ios::binary);
		else if(x==8)
			fin.open("pizza.dat",ios::binary);
		else if(x==9)
			fin.open("mcd.dat",ios::binary);

	int flag=0;
	char r[20];
	shop s1;
	cout<<"enter item name whose record you want to delete";
	gets(r);
	while(fin.read((char *)&s1,sizeof(s1)))
	{
		if(strcmp(s1.returnname(),r)!=0)
		{
			fout.write((char *)&s1,sizeof(s1));
		}
		else
			flag=1;
	}
	if(flag==0)
	cout<<"item not found";
	fin.close();
	fout.close();
		if(x==1)
		{
			remove("watch.dat");
			rename("temp2.dat","watch.dat");
		}
		else if(x==2)
		{
			remove("shoe.dat");
			rename("temp2.dat","shoe.dat");
		}
		else if(x==3)
		{
			remove("pantaloons.dat");
			rename("temp2.dat","pantaloons.dat");
		}
		else if(x==4)
		{
			remove("apple.dat");
			rename("temp2.dat","apple.dat");
		}
		else if(x==5)
		{
			remove("samsung.dat");
			rename("temp2.dat","samsung.dat");
		}
		else if(x==6)
		{
			remove("electronics.dat");
			rename("temp2.dat","electonics.dat");
		}
		else if(x==7)
		{
			remove("dominos.dat");
			rename("temp2.dat","dominos.dat");
		}
		else if(x==8)
		{
			remove("pizza.dat");
			rename("temp2.dat","pizza.dat");
		}
		else if(x==9)
		{
			remove("mcd.dat");
			rename("temp2.dat","mcd.dat");
		}
}
void bill()               // FUNCTION TO DISPLAY BILLS
{
	clrscr();
	ifstream fin;
	fin.open("temp.dat",ios::binary);
	shop s1;
	int m;
	int y;
	cout<<"enter month ";
	cin>>m;
	cout<<"enter year ";
	cin>>y;
	while(fin.read((char*)&s1,sizeof(s1)))
	{
	       if(s1.retmonth()==m && s1.retyear()==y)
	       s1.go();
	}
	fin.close();
}
void modify(int x)                  // FUNCTION TO MODIFY RECORDS
{
	clrscr();
	fstream f;
		if(x==1)
		    f.open("watch.dat",ios::binary|ios::out|ios::in);
		else if(x==2)
			f.open("shoe.dat",ios::binary|ios::out|ios::in);
		else if(x==3)
		    f.open("pantaloons.dat",ios::binary|ios::out|ios::in);
		else if(x==4)
			f.open("apple.dat",ios::binary|ios::out|ios::in);
		else if(x==5)
			f.open("samsung.dat",ios::binary|ios::out|ios::in);
		else if(x==6)
		   f.open("electronics.dat",ios::binary|ios::out|ios::in);
		else if(x==7)
			f.open("dominos.dat",ios::binary|ios::out|ios::in);
		else if(x==8)
			f.open("pizza.dat",ios::binary|ios::out|ios::in);
		else if(x==9)
			f.open("mcd.dat",ios::binary|ios::out|ios::in);

	shop s1;
	int pos,flag=0;
	char r[20];
	cout<<"\nenter item name whose details you want to change";
	gets(r);
	while(!f.eof())
	{
		pos=f.tellg();
		f.read((char*)&s1,sizeof(s1));
		if(strcmp(s1.returnname(),r)==0)
		{
			s1.getdata();
			f.seekg(pos);
			flag=1;
			f.write((char *)&s1,sizeof(s1));
			break;
		}
	}
	if(flag==0)
	cout<<"item not found";
	f.close();
}

void owner(int x)	      // ACCESSIBLE TO THE OWNER
{
	clrscr();
	char pw[20],a;
	cout<<"Enter your password : ";
	for(int i=0;i<20;i++)
	{
		pw[i]=getch();

		if( int(pw[i])==8 )
		{
			clrscr();
			cout<<"Enter your password : ";
			for(int j=1; j<i ; j++ )
				cout<<'*';
			if(i>=1)
				i-=2;
		}
		else if(int(pw[i])!=13)
		{
			cout<<'*';
		}
		else
		{
			pw[i]='\0';
			break;
		}
	}
	if(x==1)
	{
		if(!strcmp(pw,"timezone"))
		{
			clrscr();
			cout<<"\n\t\t\tWELCOME TO TIME ZONE";
			int ch;
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to first floor\n";
				cin>>ch;
				if(ch==1)
				create(1);
				else if(ch==2)
				read(1);
				else if(ch==3)
				searchname(1);
				else if(ch==4)
				Delete(1);
				else if(ch==5)
				modify(1);
				else if(ch==6)
				bill();
				else if(ch==7)
				watch();
				else if(ch==8)
				ffloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				ffloor();
		}
	}
	else if(x==2)
	{
		if(!strcmp(pw,"foot"))
		{
			clrscr();
			int ch;
			cout<<"\n\t\t\tWELCOME TO FOOT PRINTS";
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to first floor\n";
				cin>>ch;
				if(ch==1)
				create(2);
				else if(ch==2)
				read(2);
				else if(ch==3)
				searchname(2);
				else if(ch==4)
				Delete(2);
				else if(ch==5)
				modify(2);
				else if(ch==6)
				bill();
				else if(ch==7)
				shoe();
				else if(ch==8)
				ffloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				ffloor();
		}
	}
	else if(x==3)
	{
		if(!strcmp(pw,"pantaloons"))
		{
			clrscr();
			int ch;
			cout<<"\n\t\t\tWELCOME TO PANTALOONS";
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to first floor\n";
				cin>>ch;
				if(ch==1)
				create(3);
				else if(ch==2)
				read(3);
				else if(ch==3)
				searchname(3);
				else if(ch==4)
				Delete(3);
				else if(ch==5)
				modify(3);
				else if(ch==6)
				bill();
				else if(ch==7)
				pantaloons();
				else if(ch==8)
				ffloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				ffloor();
		}
	}
	else if(x==4)
	{
		if(!strcmp(pw,"apple"))
		{
			clrscr();
			int ch;
			cout<<"\n\t\t\tWELCOME TO iSTORE";
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to second floor\n";
				cin>>ch;
				if(ch==1)
				create(4);
				else if(ch==2)
				read(4);
				else if(ch==3)
				searchname(4);
				else if(ch==4)
				Delete(4);
				else if(ch==5)
				modify(4);
				else if(ch==6)
				bill();
				else if(ch==7)
				apple();
				else if(ch==8)
				sfloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				sfloor();
		}
	}
	else if(x==5)
	{
		if(!strcmp(pw,"samsung"))
		{
			clrscr();
			int ch;
			cout<<"\n\t\t\tWELCOME TO SAMSUNG";
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to second floor\n";
				cin>>ch;
				if(ch==1)
				create(5);
				else if(ch==2)
				read(5);
				else if(ch==3)
				searchname(5);
				else if(ch==4)
				Delete(5);
				else if(ch==5)
				modify(5);
				else if(ch==6)
				bill();
				else if(ch==7)
				samsung();
				else if(ch==8)
				sfloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				sfloor();
		}
	}
	else if(x==6)
	{
		if(!strcmp(pw,"techmart"))
		{
			clrscr();
			int ch;
			cout<<"\n\t\t\tWELCOME TO TECH MART";
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to second floor\n";
				cin>>ch;
				if(ch==1)
				create(6);
				else if(ch==2)
				read(6);
				else if(ch==3)
				searchname(6);
				else if(ch==4)
				Delete(6);
				else if(ch==5)
				modify(6);
				else if(ch==6)
				bill();
				else if(ch==7)
				electronics();
				else if(ch==8)
				sfloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				sfloor();
		}
	}
	else if(x==7)
	{
		if(!strcmp(pw,"dominos"))
		{
			clrscr();
			int ch;
			cout<<"\n\t\t\tWELCOME TO DOMINOS";
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to third floor\n";
				cin>>ch;
				if(ch==1)
				create(7);
				else if(ch==2)
				read(7);
				else if(ch==3)
				searchname(7);
				else if(ch==4)
				Delete(7);
				else if(ch==5)
				modify(7);
				else if(ch==6)
				bill();
				else if(ch==7)
				dominos();
				else if(ch==8)
				tfloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				tfloor();
		}
	}
	else if(x==8)
	{
		if(!strcmp(pw,"pizza"))
		{
			clrscr();
			int ch;
			cout<<"\n\t\t\tWELCOME TO PIZZA HUT";
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to third floor\n";
				cin>>ch;
				if(ch==1)
				create(8);
				else if(ch==2)
				read(8);
				else if(ch==3)
				searchname(8);
				else if(ch==4)
				Delete(8);
				else if(ch==5)
				modify(8);
				else if(ch==6)
				bill();
				else if(ch==7)
				pizza_hut();
				else if(ch==8)
				tfloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				tfloor();
		}
	}
	else if(x==9)
	{
		if(!strcmp(pw,"mcdonalds"))
		{
			clrscr();
			int ch;
			cout<<"\n\t\t\tWELCOME TO McDONALDS";
			char choice;
			do
			{
				cout<<"\nenter 1 to create file";
				cout<<"\nenter 2 to read file";
				cout<<"\nenter 3 to search the record";
				cout<<"\nenter 4 to delete record";
				cout<<"\nenter 5 to modify the file";
				cout<<"\nenter 6 to search bills in month";
				cout<<"\nenter 7 to go back";
				cout<<"\nenter 8 to third floor\n";
				cin>>ch;
				if(ch==1)
				create(9);
				else if(ch==2)
				read(9);
				else if(ch==3)
				searchname(9);
				else if(ch==4)
				Delete(9);
				else if(ch==5)
				modify(9);
				else if(ch==6)
				bill();
				else if(ch==7)
				mcd();
				else if(ch==8)
				tfloor();
				cout<<"\n do you want to continue(y/n)";
				cin>>choice;
				clrscr();
			}while(choice=='y');
		}
		else
		{
			cout<<"\nwrong password";
			cout<<"\ndo you want to try again (press y)";
			cin>>a;
			if(a=='y' || a=='Y')
				owner(x);
			else
				tfloor();
		}
	}
	else
		main();
}
void edit(shop s,int x)         // FUNCTION TO CHANGE QUANTITY IN DATA FILE
{
	fstream f;
		if(x==1)
			f.open("watch.dat",ios::binary|ios::out|ios::in);
		else if(x==2)
			f.open("shoe.dat",ios::binary|ios::out|ios::in);
		else if(x==3)
		    f.open("pantaloons.dat",ios::binary|ios::out|ios::in);
		else if(x==4)
		     f.open("apple.dat",ios::binary|ios::out|ios::in);
		else if(x==5)
		    f.open("samsung.dat",ios::binary|ios::out|ios::in);
		else if(x==6)
		   f.open("electronics.dat",ios::binary|ios::out|ios::in);
		else if(x==7)
			f.open("dominos.dat",ios::binary|ios::out|ios::in);
		else if(x==8)
		    f.open("pizza.dat",ios::binary|ios::out|ios::in);
		else if(x==9)
			f.open("mcd.dat",ios::binary|ios::out|ios::in);
	shop s1;
	int pos,flag=0;
	while(!f.eof())
	{
		pos=f.tellg();
		f.read((char*)&s1,sizeof(s1));
		if(strcmp(s1.returnname(),s.returnname())==0)
		{
			s1.copy(s);
			f.seekg(pos);
			flag=1;
			f.write((char *)&s1,sizeof(s1));
			break;
		}
	}
	if(flag==0)
	cout<<"item not found";
	f.close();
}

void removed(shop s2)               // FUNCTION TO DELETE MULTIPLE ENTERIES
{
	ofstream fout;
	ifstream fin;
	fout.open("temp1.dat",ios::binary);
	fin.open("bill.dat",ios::binary);
	int flag=0;
	fin.seekg(0);
	shop s1;
	while(fin.read((char *)&s1,sizeof(s1)))
	{
		if(strcmp(s1.returnname(),s2.returnname())!=0 || s1.temp==1)
		{
			fout.write((char *)&s1,sizeof(s1));
		}
		else
			flag=1;
	}
	if(flag==0)
	cout<<"item not found";
	fin.close();
	fout.close();
	remove("bill.dat");
	rename("temp1.dat","bill.dat");
}
void tobill(int amt)               // FUNCTION TO WRITE ENTERIES IN BILL FILE
{
	fstream f;
	f.open("bill.dat",ios::binary|ios::out|ios::in);
	ofstream fout;
	fout.open("temp.dat",ios::binary|ios::app);
	shop s1,s2;
	int pos;
	while(!f.eof())
	{
		pos=f.tellg();
		f.read((char*)&s1,sizeof(s1));
		s1.final=amt;
		f.seekg(pos);
		f.write((char *)&s1,sizeof(s1));
	}
	f.close();
	f.open("bill.dat",ios::binary|ios::out|ios::in);
	f.read((char*)&s1,sizeof(s1));
	s2.billno=s1.billno;
	s2.date=s1.date;
	s2.month=s1.month;
	s2.year=s1.year;
	s2.final=s1.final;
	fout.write((char*)&s1,sizeof(s1));
	f.close();
}
void read1()             	  // FUNCTION TO DISPLAY BILL
{
	ifstream fin;
	fin.open("bill.dat",ios::binary);
	shop s1;
	int p=1;
	while(fin.read((char*)&s1,sizeof(s1)))
	{
		p=s1.print(p);
	}
	fin.close();
}
void customer(int x)                    	  // CUSTOMER
{
	clrscr();
	ifstream fin;
	ofstream fout;
		if(x==1)
			fin.open("watch.dat",ios::binary);
		else if(x==2)
			fin.open("shoe.dat",ios::binary);
		else if(x==3)
			fin.open("pantaloons.dat",ios::binary);
		else if(x==4)
			fin.open("apple.dat",ios::binary);
		else if(x==5)
			fin.open("samsung.dat",ios::binary);
		else if(x==6)
			fin.open("electronics.dat",ios::binary);
		else if(x==7)
			fin.open("dominos.dat",ios::binary);
		else if(x==8)
			fin.open("pizza.dat",ios::binary);
		else if(x==9)
			fin.open("mcd.dat",ios::binary);

	shop s1,s2;
	amount=0;
	fout.open("bill.dat",ios::binary);
	int i=1,ch,j=1,qty1,counter=1;
	char ch1='y';
	while(ch1=='y')
	{
		cout<<"SELECT THINGS YOU WANT TO BUY"<<endl;
		while(fin.read((char*)&s1,sizeof(s1)))
		{
			cout<<"\npress "<<i++<<" for ";
			s1.display();
		}
		cout<<endl;
		cin>>ch;
		fin.close();
		if(x==1)
			fin.open("watch.dat",ios::binary);
		else if(x==2)
			fin.open("shoe.dat",ios::binary);
		else if(x==3)
			fin.open("pantaloons.dat",ios::binary);
		else if(x==4)
			fin.open("apple.dat",ios::binary);
		else if(x==5)
			fin.open("samsung.dat",ios::binary);
		else if(x==6)
			fin.open("electronics.dat",ios::binary);
		else if(x==7)
			fin.open("dominos.dat",ios::binary);
		else if(x==8)
			fin.open("pizza.dat",ios::binary);
		else if(x==9)
			fin.open("mcd.dat",ios::binary);

		while(fin.read((char*)&s1,sizeof(s1)))
		{
			if(ch==j)
			{
				cout<<"\nenter quantity you want to purchase ";
				cin>>s1.qty1;
				if(s1.check()==1)
				{
					edit(s1,x);
					amount=s1.call(amount);
				}
				else
				{
					cout<<"\nstock not available";
					break;
				}
				s1.datecalc();
				if(counter==1)
				{
					s1.calcbillno();
				}
				s1.temp=0;
				fout.write((char *)&s1,sizeof(s1));
			}
			j++;
		}
		cout<<"\ndo you want to purchase more (press y) ";
		cin>>ch1;
		clrscr();
		fin.close();
		if(x==1)
			fin.open("watch.dat",ios::binary);
		else if(x==2)
			fin.open("shoe.dat",ios::binary);
		else if(x==3)
			fin.open("pantaloons.dat",ios::binary);
		else if(x==4)
			fin.open("apple.dat",ios::binary);
		else if(x==5)
			fin.open("samsung.dat",ios::binary);
		else if(x==6)
			fin.open("electronics.dat",ios::binary);
		else if(x==7)
			fin.open("dominos.dat",ios::binary);
		else if(x==8)
			fin.open("pizza.dat",ios::binary);
		else if(x==9)
			fin.open("mcd.dat",ios::binary);

		i=1;
		j=1;
		counter++;
	}
	fout.close();
	fin.close();

	fstream f;
	f.open("bill.dat",ios::binary|ios::in|ios::out);
	int no=0;
	int pos;
	while(f.read((char*)&s1,sizeof(s1)))
	{
		pos=f.tellg()-sizeof(s1);
		no++;
		while(f.read((char*)&s2,sizeof(s2)))
		{
			if(strcmp(s1.returnname(),s2.returnname())==0)
			{
				s1.calcqty( s2.retqty() );
				f.seekg(pos);
				f.write((char*)&s1,sizeof(s1));
				f.close();
				removed(s2);
				f.open("bill.dat",ios::binary|ios::in|ios::out);

				f.seekg(pos+sizeof(s1));
			}

		}
		f.close();
		f.open("bill.dat",ios::binary|ios::in|ios::out);
		for(int l=1;l<=no;l++)
			f.read((char*)&s1,sizeof(s1));
	}


	read1();
	cout<<"\ntotal amount="<<amount;
	tobill(amount);
}

void watch()                        	    // TIME ZONE
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO TIME ZONE";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-FIRST FLOOR\n";
		cout<<"4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(1);
		else if(ch==2)
		customer(1);
		else if(ch==3)
		ffloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}
void shoe()                             	// FOOT PRINTS
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO FOOT PRINTS";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-FIRST FLOOR";
		cout<<"\n4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(2);
		else if(ch==2)
		customer(2);
		else if(ch==3)
		ffloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}
void pantaloons()                             // PANTALOONS
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO PANTALOONS";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-FIRST FLOOR\n";
		cout<<"4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(3);
		else if(ch==2)
		customer(3);
		else if(ch==3)
		ffloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}
void apple()                                         // iSTORE
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO iSTORE";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-SECOND FLOOR\n";
		cout<<"4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(4);
		else if(ch==2)
		customer(4);
		else if(ch==3)
		sfloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}
void samsung()                                         // SAMSUNG
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO SAMSUNG";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-SECOND FLOOR\n";
		cout<<"4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(5);
		else if(ch==2)
		customer(5);
		else if(ch==3)
		sfloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}
void electronics()                                   //TECH MART
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO TECH MART";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-SECOND FLOOR\n";
		cout<<"4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(6);
		else if(ch==2)
		customer(6);
		else if(ch==3)
		sfloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}
void dominos()                                      // DOMINO'S
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO DOMINO'S";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-THIRD FLOOR\n";
		cout<<"4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(7);
		else if(ch==2)
		customer(7);
		else if(ch==3)
		tfloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}
void pizza_hut()                                    // PIZZA HUT
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO PIZZA HUT";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-THIRD FLOOR\n";
		cout<<"4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(8);
		else if(ch==2)
		customer(8);
		else if(ch==3)
		tfloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}
void mcd()                                             // McDONALDS
{
	clrscr();
	cout<<"\n\t\t\tWELCOME TO McDONALDS";
	char choice;
	shop s1;
	int ch;
	do
	{
		cout<<"\n1-OWNER\n";
		cout<<"2-CUSTOMER";
		cout<<"\n3-THIRD FLOOR\n";
		cout<<"4-EXIT";
		cin>>ch;
		if(ch==1)
		owner(9);
		else if(ch==2)
		customer(9);
		else if(ch==3)
		tfloor();
		else if(ch==4)
		exit(0);

		cout<<"\npress y to restart";
		cin>>choice;
	}while(choice=='y');
}

void ffloor()                                         // FIRST FLOOR
{
	clrscr();
	char choice='y';
	int ch;
	cout<<"\t\t\tWELCOME TO THE FIRST FLOOR";
	while(choice=='y' || choice=='Y')
	{
		cout<<"\n1-TIME ZONE"<<endl;
		cout<<"2-FOOT PRINTS"<<endl;
		cout<<"3-PANTALOONS"<<endl<<endl;
		cout<<"4-SECOND FLOOR"<<endl;
		cout<<"5-THIRD FLOOR"<<endl;
		cout<<"6-EXIT"<<endl;
		cin>>ch;
		if(ch==1)
			watch();
		else if(ch==2)
			shoe();
		else if(ch==3)
			pantaloons();
		else if(ch==6)
			exit(0);
		else if(ch==4)
			sfloor();
		else if(ch==5)
			tfloor();
		else
			cout<<"\nWrong choice";
		cout<<"\nDo you want to go in other store on same floor(press y)";
		cin>>choice;
	}
}
void sfloor()                                        // SECOND FLOOR
{
	clrscr();
	char choice='y';
	int ch;
	cout<<"\t\t\tWELCOME TO THE SECOND FLOOR";
	while(choice=='y' || choice=='Y')
	{
		cout<<"\n1-iSTORE"<<endl;
		cout<<"2-SAMSUNG"<<endl;
		cout<<"3-TECH MART"<<endl<<endl;
		cout<<"4-FIRST FLOOR"<<endl;
		cout<<"5-THIRD FLOOR"<<endl;
		cout<<"6-EXIT"<<endl;
		cin>>ch;
		if(ch==1)
			apple();
		else if(ch==2)
			samsung();
		else if(ch==3)
			electronics();
		else if(ch==6)
			exit(0);
		else if(ch==4)
			ffloor();
		else if(ch==5)
			tfloor();
		else
			cout<<"\nWrong choice";
		cout<<"\nDo you want to go in other store on same floor(press y)";
		cin>>choice;
	}
}
void tfloor()                                         // THIRD FLOOR
{
	clrscr();
	char choice='y';
	int ch;
	cout<<"\t\t\tWELCOME TO THE THIRD FLOOR";
	while(choice=='y' || choice=='Y')
	{
		cout<<"\n1-DOMINOS"<<endl;
		cout<<"2-PIZZA HUT"<<endl;
		cout<<"3-McDONALDS"<<endl<<endl;
		cout<<"4-FIRST FLOOR"<<endl;
		cout<<"5-SECOND FLOOR"<<endl;
		cout<<"6-EXIT"<<endl;
		cin>>ch;
		if(ch==1)
			dominos();
		else if(ch==2)
			pizza_hut();
		else if(ch==3)
			mcd();
		else if(ch==6)
			exit(0);
		else if(ch==4)
			ffloor();
		else if(ch==5)
			sfloor();
		else
			cout<<"\nWrong choice";
		cout<<"\nDo you want to go in other store on same floor(press y)";
		cin>>choice;
	}
}

void main()                                          // MAIN FUNCTION
{
	clrscr();
	char choice='y';
	int ch;
	cout<<"\t\t\tWELCOME TO THE EMPORIO SUPERMARKET";
	delay(1500);
	while(choice=='y' || choice=='Y')
	{
		cout<<"\n1-FIRST FLOOR"<<endl;
		cout<<"2-SECOND FLOOR"<<endl;
		cout<<"3-THIRD FLOOR"<<endl;
		cout<<"4-EXIT"<<endl;
		cin>>ch;
		if(ch==1)
			ffloor();
		else if(ch==2)
			sfloor();
		else if(ch==3)
			tfloor();
		else if(ch==4)
			exit(0);
		else
			cout<<"\nWrong choice";

		cout<<"\nDo you want to go to any other floor (press y)";
		cin>>choice;
	}
	delay(2500);
	cout<<"\n\t\t\tTHANKS FOR YOUR VISIT\n";
getch();
}
