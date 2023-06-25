#include<iostream>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
struct Node
{
	
	long long int card_no;  
	int pin;  
	
	string name;           
	int cash; 
	
	Node *next;
	Node *prev;
};
class ATM
{
	Node *head;
	string x;
	long long int y;  
	int z;              
	int c;
	public:
		ATM()
		{
			head=NULL;
			x="";
			y=0;
			z=0;
			c=0;
		}
    	
    	void CreateACC()
	    {
	    	if(head==NULL)
	    	{
    	    	Node *newer= new Node;
	    	    cout<<"  Enter Name ";
		        cin>>x;
		        newer->name=x;

    		    cout<<"  Enter Card No: ";
	    	    cin>>y;
		        newer->card_no=y;
		        
		        cout<<"  Enter Pin: ";
	    	    cin>>z;
		        newer->pin=z;
		        
		        newer->cash=0;
	
		        newer->next=NULL;
		        newer->prev==NULL;
		        head=newer;
		        
		        cout<<"Account Created"<<endl;
		    }
		    else
		    {
			
		        Node *newer= new Node;
	    	    cout<<"  Enter Name: ";
		        cin>>x;
		        newer->name=x;

    		    cout<<"  Enter Card No: ";
	    	    cin>>y;
		        newer->card_no=y;
		        
		        cout<<"  Enter Pin: ";
	    	    cin>>z;
		        newer->pin=z;
		        
		        newer->cash=0;
		        
		        newer->next=NULL;
		        
		    	Node *temp=head;
		    	while(temp->next!=NULL)
		    	{
		    		temp=temp->next;
		    	}
		    	temp->next=newer;
		    	newer->prev=temp;
		    	cout<<"Account Created"<<endl;
			}
		}
		
		
		
    
    	int LOGIN_TO_ACCOUNT()
    	{
    		    
    		
    		    Node *temp=head;
	    		cout<<"  Enter Card No: ";
	    		cin>>y;
	    		
	    		cout<<"  Enter Your PIN: ";
	    		cin>>z;
		    	while(temp!=NULL)
		    	{

		        	if(temp->card_no==y && temp->pin==z)
		        	{
		        		
	                    
		        		cout<<"***********"<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		user_menu();
		        		
		        		
		        		
		        	}
		        	temp=temp->next;
	        	}
	        	cout<<"  You Enter Wrong CardNo or Pin"<<endl;
	        	
	        
	    }
	    
	    void Widthdraw()         	    
	    {
	    	    Node *temp=head;
	    	    
	    		while(temp!=NULL)
		    	{

		        	if(temp->card_no==y && temp->pin==z)
		        	{
		        		
		        		cout<<"Enter The Ammount: ";
		        		cin>>c;
		        		if(temp->cash>=c)
						{
						temp->cash=temp->cash-c;
		        		cout<<"Amount successfully Widthdraw"<<endl;
						}
						else
						{
							cout<<"You Dont Have Enough Balance To Widthdraw"<<endl;
							cout<<"***********"<<endl;
						}
		        		
		        		break;
					}
					temp=temp->next;
	    	    }
	    }                   		
		void Deposit()
        {
        	
        	
        	Node *temp=head;
	    		while(temp!=NULL)
		    	{

		        	if(temp->card_no==y && temp->pin==z)
		        	{
		        		
		        		cout<<"Enter The Ammount: ";
		        		cin>>c;
		        		temp->cash=temp->cash+c;
		        		cout<<"Amount successfully Added"<<endl;
		        		break;
					}
					temp=temp->next;
	    	    }
    		
	    	
	    }
	    void Balance_Enquiry()
        {
        	Node *temp=head;
	    		while(temp!=NULL)
		    	{

		        	if(temp->card_no==y && temp->pin==z)
		        	{
		        		
		        		cout<<"Your Balance is: "<<temp->cash<<endl;
		        		break;
					}
					temp=temp->next;
	    	    }
	    	
	    }
		

	
    	
    	void user_menu()
    	{
    		            cout<<"  USER MENU"<<endl;
    		            cout<<"  1. Deposit Money"<<endl;
		        		cout<<"  2. Widthdraw Money"<<endl;
		        		cout<<"  3. Check Balance"<<endl;
		        		cout<<"  4. Main Menu"<<endl;
		        		cout<<"***********"<<endl;
		        		int command;
		        		cout<<"  Enter the Command: ";
		        		cin>>command;
		        		
		    try
	    	{
	    		if(command>=1&&command<=4)
	    		{
		        		if (command==1)
		        		{
		        			Deposit();
		        			user_menu();
		        			
						}
						else if (command==2)
		        		{
		        			Widthdraw();
		        			user_menu();
		        			
						}
						else if (command==3)
		        		{
		        			Balance_Enquiry();
		        			user_menu();
		        			
						}
						else if (command==4)
		        		{
		        			main_menu();
		        			
						}
					}
				else
				{
					throw(command);
				}
			}
			catch(int command)
			{
				cout<<"  You Enter wrong Command... Run the Code Again"<<endl;
				main_menu();
			}	
    		
		}
		void main_menu()
    	{
	    	cout<<"***********"<<endl;
	    	cout<<"  MAIN MENU"<<endl;
	    	cout<<"  1. Create Account"<<endl;
	    	cout<<"  2. Login to Account"<<endl;
	    	cout<<"  3. Exit"<<endl;
	    	cout<<"***********"<<endl;
		
	    	int Scommand;
	    	cout<<"  Enter the Command: ";
	    	cin>>Scommand;
	    	try
	    	{
	    		if(Scommand>=1&&Scommand<=6)
	    		{
	    			if(Scommand==1)
	            	{
	            		CreateACC();
	    	        	main_menu();
	            	}
	            	else if(Scommand==2)
		        	{
		        		
		        	    LOGIN_TO_ACCOUNT();
		        		main_menu();
			        }
	            	
	            	else if(Scommand==3)
	            	{
	            		cout<<"   Thanks For Choosing HBL ATM"<<endl;
	            		cout<<"***********"<<endl;
	            		exit(0);	
		        	}
				}
				else
				{
					throw(Scommand);
				}
			}
			catch(int Scommand)
			{
				cout<<"  You Enter wrong Command... Run the Code Again"<<endl;
				main_menu();
			}	
	    }
    	
};

int main()
{   
    system("color A0");
    ATM cb;
    

	
    cout<<"***********"<<endl;
	cout<<"  WELCOME TO THE HBL ATM BANKING      "<<endl;
	cout<<"***********"<<endl;
	cb.main_menu();
	return 0;
}
