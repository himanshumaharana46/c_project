# include<iostream>
# include<conio.h>
using namespace std;
class node{
	public:
		int roll;
		string name,dept,course,section;
		node* next;
		node(string n,int r,string c,string d,string s)
		{
			name=n;
			roll=r;
			course=c;
			dept=d;
			section=s;
		}
};
class student{
	node* head=NULL;
	public:
		void InsertData(string n,int r,string c,string d,string s)
		{
			system("cls");
            node* new_node= new node(n,r,c,d,s);
            node* temp=head;
			new_node->name=n;
			new_node->roll=r;
			new_node->course=c;
			new_node->dept=d;
			new_node->section=s;
			new_node->next=NULL;
			if(head==NULL)
			{
				head=new_node;
				new_node->next=NULL;
				return;
			}
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}temp->next=new_node;
            
		}
		void search(int r1)
		{
			system("cls");
			if(head==NULL)
			{
				cout<<"..........NO RECORD IS AVAILABLE............"<<endl;
				return;
			}
			else
			{
				cout<<"ENTER ROLL OF THE STUDENT YOU WANT TO SEARCH:";
				cin>>r1;
				node* temp=head;
				while(temp!=NULL)
				{
					if(temp->roll==r1)
					{
						cout<<"THE DATA OF THE STUDENT IS AS FOLLOWS:"<<endl;
						cout<<"name:"<<temp->name<<endl;
						cout<<"roll:"<<temp->roll<<endl;
			    		cout<<"course:"<<temp->course<<endl;
			    		cout<<"dept:"<<temp->dept<<endl;
						cout<<"section:"<<temp->section<<endl;
						return;
					}
					temp=temp->next;
				}if(temp==NULL)
				{
					cout<<"............NO SUCH RECORD OF THE STUDENT IS FOUND..........."<<endl;
				}
				
			}
		}
		void update(int r1,string n,int r,string c,string d,string s)
		{
			system("cls");
			if(head==NULL)
			{
				cout<<"............NO DATA IS THERE FOR UPDATION.........."<<endl;
				return;
			}
            cout<<"ENTER ROLL OF THE STUDENT YOU WANT TO UPDATE:";
			cin>>r1;
			node* temp=head;
			while(temp!=NULL)
			{
				if(temp->roll==r1)
			{
				cout<<"......the previous data of the student is as follows......."<<endl;
				cout<<"name:"<<temp->name<<endl;
				cout<<"roll:"<<temp->roll<<endl;
			    cout<<"course:"<<temp->course<<endl;
			    cout<<"dept:"<<temp->dept<<endl;
				cout<<"section:"<<temp->section<<endl;
				cout<<endl;
				cout<<"enter new data of the student:"<<endl;
				cout<<"name:";
				cin>>n;
				temp->name=n;
				cout<<"roll:";
				cin>>r;
				temp->roll=r;
				cout<<"course:";
				cin>>c;
				temp->course=c;
				cout<<"dept:";
				cin>>d;
				temp->dept=d;
				cout<<"section:";
				cin>>s;
				temp->section=s;
				return;
			}temp=temp->next;
			if(temp==NULL)
			{
				cout<<"...........NO SUCH RECORD OF THE STUDENT IS FOUND.........."<<endl;
				return;
			}
			}
		}
		int del(int r1)
		{ 
		    system("cls");
		    if(head==NULL)
		    {
		    	cout<<"NO RECORD IS THERE TO BE DELETED"<<endl;
		    	return 0;
			}
		    cout<<"press 1 to delete a specific record"<<"\t"<<"press 2 to delete whole record"<<endl;
		    int choice;
		    cout<<"enter your choice:";
		    cin>>choice;
		    if(choice==1)
		    {
		    	cout<<"enter roll of the student you want to delete:";
		    	cin>>r1;
		    	node* temp=head;
			node* temp1=NULL;
			if (temp!=NULL && temp->roll==r1)
			{
				head = temp->next;
				delete (temp);
				cout<<".............THE SPECIFIED RECORD HAS BEEN DELETED........."<<endl;
				return 0;
			}
			while(temp!=NULL && temp->roll!=r1)
			{
				temp1=temp;
				temp=temp->next;
			}
				if(temp==NULL)
				{
					cout<<"...............NO SUCH RECORD OF THE STUDENT IS FOUND TO BE DELETED................"<<endl;
					return -1;
					temp1->next=temp->next;
					delete temp;
					cout<<"....................RECORD DELETED SUCCESSFULLLY..................."<<endl;
					return 0;
				}
			}
			else if(choice==2)
			{
			    node* temp=head;
			    head=NULL;
				delete(temp);
				cout<<"ALL RECORDS HAVE BEEN DELETED"<<endl;	
			}
		   else
		   {
		   	cout<<"..................INVALID CHOICE..................."<<endl;
		   }
		}
		void show()
		{
			if(head==NULL)
			{
				cout<<"...............NO DATA IS THERE TO BE SHOWN.............."<<endl;
			}
			node* temp=head;
			while(temp!=NULL){
				cout<<"name:"<<temp->name<<endl;
				cout<<"roll:"<<temp->roll<<endl;
			    cout<<"course:"<<temp->course<<endl;
			    cout<<"dept:"<<temp->dept<<endl;
				cout<<"section:"<<temp->section<<endl;
				cout<<endl;
				temp=temp->next;
			}
		}
};
int main()
{
	system("cls");
	cout<<"...................................STUDENTS' DATABASE MANAGEMENT SYSTEM............................"<<endl;
	student* obj= new student();
	char ch,ch1;
	int r,r1;
	string n,c,d,s;
	while(1)
	{
		cout<<"press"<<endl;
		cout<<"1. create new record of the student"<<"\t"<<"2. show existing record"<<"\t"<<"3. search record"<<endl;
		cout<<"4. update record"<<"\t"<<"5. delete record"<<"\t"<<"6. exit"<<endl;
		ch=getch();
		switch(ch)
		
		{
			case '1':
				cout<<".....................NEW DATA CREATION..............."<<endl;
					cout<<"enter name:";
				   	cin>>n;
				  	cout<<"roll:";
					cin>>r;
					cout<<"course:";
					cin>>c;
					cout<<"department:";
					cin>>d;
					cout<<"section:";
					cin>>s;
					obj->InsertData(n,r,c,d,s);
					break;
			case '2':
				cout<<"....................DATA SHOW...................."<<endl;
				obj->show();
				break;
			case '3':
				cout<<"................SEARCH DATA...................."<<endl;

				obj->search(r1);
				break;
			case '4':
				cout<<"...................DATA UPDATION.................."<<endl;
				obj->update(r1,n,r,c,d,s);
				break;
			case '5':
				cout<<".......................RECORD DELETION................"<<endl;
				obj->del(r1);
				break;
			case '6':
				exit(0);
				break;
			default:
				cout<<"......................INVALID INPUT..................."<<endl;
				break;
		}
	}return 0;
} 
