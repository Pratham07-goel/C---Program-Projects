#include <iostream>
using namespace std;
#include <stdlib.h>

class account
{
	protected:
		float opening_bal_saving,balance_saving;
		float opening_bal_current,balance_current;
		public:
			virtual void withdraw()=0;
			virtual void deposit()=0;
};

class saving_acc:public account
{
	public:
		saving_acc()
		{
			opening_bal_saving=0.0;
		}
		saving_acc(float openbal)
		{
			opening_bal_saving=openbal;
		}
		void withdraw()
		{
			int amount;
			cout<<"Balance amount in your savings A/c is: "<<opening_bal_saving<<endl;
			
			cout<<"Enter the amount to withdraw from your A/c:";
			cin>>amount;
			balance_saving=opening_bal_saving - amount;
			
			cout<<endl<<"The balance amounut in your savings A/c is:"<<balance_saving<<endl;
		}
		void deposit()
		{
			int amount;
			cout<<"Balance amount in your savings A/c is: "<<opening_bal_saving;
			cout<<endl<<"Enter the amount to deposit: ";
			cin>>amount;
			balance_saving=opening_bal_saving + amount;
			
			cout<<"The balance amount in your savings A/c is:"<<balance_saving<<endl;
		}
		};

class current_acc:public account
{
	public:
		current_acc()
		{
			opening_bal_current=0.0;
		}
		current_acc(float openbal)
		{
				opening_bal_current=openbal;
		}
		void withdraw()
		{
			int amount;
			cout<<"Balance amount in your current A/c is: "<<opening_bal_current<<endl;
			
			cout<<"Enter the amount to withdraw:* ";
			cin>>amount;
			balance_current=opening_bal_current - amount;
			
			cout<<endl<<"The balance in your current savings A/c is: Rs."<<balance_current<<endl; 
		}
		
		void deposit()
		{
			int amount;
			cout<<"Balnce amount in your current A/c is: "<<opening_bal_current<<endl;
			
			cout<<"Enter the amount to deposit:* ";
			cin>>amount;
			balance_current=opening_bal_current + amount;
			
			cout<<endl<<"The balance in your current savings A/c is: Rs."<<balance_current<<endl; 
		}
};

int main()
{
	account *acc;
	saving_acc savingobj(200000);
	current_acc currentobj(500000);
	
	int choice ;
	char ans,ch;
	while(choice<=4)
	{
	cout<<"Which Bank A/c do you want to operate"<<endl;
		
		cout<<"1.Saving Account"<<endl;
		cout<<"2.Current Account"<<endl;	
		cout<<"3.Other"<<endl;
		cout<<"4.Quit"<<endl;
		cout<<"Enter the choice:";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				acc=&savingobj;
				cout<<"Press 'd' to deposit the amount ELSE Press 'w' to withdraw the amount ";
				cin>>ch;
				if(ch=='d')
				{
					acc->deposit();
				}
				if(ch=='w')
				{
					acc->withdraw();
				}
				break;
				
				case 2:
					acc=&currentobj;
						cout<<"Press 'd' to deposit the amount ELSE Press 'w' to withdraw the amount ";
				cin>>ch;
				
				if(ch=='d')
				{
					acc->deposit();
				}
				if(ch=='w')
				{
					acc->withdraw();
				}
				break;
				
				case 3:
					cout<<"Other facilities are provided to you; To avail, please contact the branch manager";
					break;
					case 4:
						return 0;
						
						default:
							cout<<"You entered the wrong choice";
							return 0;
		}
	}
		return 0;
	}
