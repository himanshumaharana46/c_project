# include<iostream>
# include<conio.h>
using namespace std;
class Bank{
	private:
		int total;
		string id;
		struct person{
		string name,id,address;
		int contact,cash;
		
		}person[100];
		public:
			Bank(){
				total=0;
				
			}
			void choice();
			void perdata();
			void show();
			void update();
			void search();
			void transaction();
			void del();
			
};
int main(){
	system("cls");
	Bank b;
	b.choice();
	return 0;
}
void Bank::choice(){
	system("cls");
	cout<<"..............................................................."<<endl;
	cout<<".                 BANKING MANAGEMENT SYSTEM                   ."<<endl;
	cout<<"..............................................................."<<endl;
	char ch;
	while(1){
		cout<<"press"<<endl;
	cout<<"1. create new account"<<"\t"<<	"2. view customer list"<<endl;
	cout<<"3. update  account"<<"\t"<<"4. check details "<<endl;
	cout<<"5. for transaction"<<" \t"<<"6. remove existing account"<<endl;
	cout<<"7. Exit"<<endl;
	ch=getch();	
	switch(ch){
		case '1':
		Bank::perdata();
		break;
		case '2':
		Bank::show();
		break;
		case '3':
		Bank::update();
		break;
		case'4':
		Bank::search();
		break;
		case'5':
			Bank::transaction();
			break;
			case'6':
		Bank::del();
		break;
		case '7':
			exit(0);
			break;
			default:
				cout<<"...invalid input...."<<endl;
				break;
		
	}
	
	}

	
}void Bank::perdata(){
		system("cls");
		cout<<"....................................................."<<endl;
		cout<<".            	NEW DATA CREATION                   ."<<endl;
		cout<<"....................................................."<<endl;
	cout<<"enter data of person:"<<total+1<<endl;
	cout<<"enter person name:";
	cin>>person[total].name;
	cout<<"id:";
	cin>>person[total].id;
	cout<<"address:";
	cin>>person[total].address;
	cout<<"contact:";
	cin>>person[total].contact;
	cout<<"total cash:";
	cin>>person[total].cash;
	total++;

}

void Bank::show(){
	system("cls");
	cout<<"................................................................"<<endl;
	cout<<".                      SHOW DATA                               ."<<endl;
	cout<<"................................................................"<<endl;
	if(total==0)
	{
		cout<<".....no data is there to show...."<<endl;
	}else{
	
	for(int i=0;i<total;i++){
		cout<<"data of person"<<i+1<<endl;
		cout<<"name:"<<person[i].name<<endl;
		cout<<"id:"<<person[i].id<<endl;
		cout<<"address:"<<person[i].address<<endl;
		cout<<"contact:"<<person[i].contact<<endl;
		cout<<"cash:"<<person[i].cash<<endl;
		
	}

}
}
void Bank::update()
{    system("cls");
      cout<<"..................................................."<<endl;
      cout<<".                  DATA UPDATION                  ."<<endl;
      cout<<"..................................................."<<endl;
if(total==0)
	{
		cout<<".....no data is there to update...."<<endl;
	}else{
	
	cout<<"enter the id of student those data you want to update:"<<endl;
	cin>>id;
	for(int i=0;i<total;i++){
		if(id==person[i].id){
		cout<<"previous data"<<endl;
		cout<<"data of person"<<i+1<<endl;
		cout<<"name:"<<person[i].name<<endl;
		cout<<"id:"<<person[i].id<<endl;
		cout<<"address:"<<person[i].address<<endl;
		cout<<"contact:"<<person[i].contact<<endl;
		cout<<"cash:"<<person[i].cash<<endl;
		cout<<"\nEnter new data"<<endl;
		cout<<"enter person name"<<endl;
    	cin>>person[i].name;
	    cout<<"id:";
    	cin>>person[i].id;
	    cout<<"address:";
    	cin>>person[i].address;
    	cout<<"contact:";
    	cin>>person[i].contact;
    	cout<<"total cash:";
    	cin>>person[i].cash;
    	break;
		}
		if(i==total-1){
			cout<<"no such record found"<<endl;
		}
	}
}
}

void Bank::search()
{    system("cls");
     cout<<"........................................................."<<endl;
     cout<<".                     SEARCH DATA                       ."<<endl;
     cout<<"........................................................."<<endl;
if(total==0)
	{
		cout<<".....no data is there to search...."<<endl;
	}else
	{
	
	cout<<"enter the id of student those data you want to search:"<<endl;
	cin>>id;
	for(int i=0;i<total;i++){
		if(id==person[i].id){
				
		cout<<"name:"<<person[i].name<<endl;
		cout<<"id:"<<person[i].id<<endl;
		cout<<"address:"<<person[i].address<<endl;
		cout<<"contact:"<<person[i].contact<<endl;
		cout<<"cash:"<<person[i].cash<<endl;
		break;
		}
      if(i==total-1){
      	cout<<"no such record found"<<endl;
	  }
	}
}
}
void Bank::transaction(){
system("cls");
   cout<<".............................................................."<<endl;
   cout<<".                   MONEY TRANSACTION                        ."<<endl;
   cout<<".............................................................."<<endl;
    if(total==0)
	{
		cout<<".....no data is there for transaction...."<<endl;
	}

	else{
		char ch;
	int cash;
cout<<"enter the id of student those data you want for transaction:"<<endl;	
cin>>id;
for(int i=0;i<total;i++){
	if(id==person[i].id){
		cout<<"name:"<<person[i].name<<endl;
		cout<<"address:"<<person[i].address<<endl;
		cout<<"contact:"<<person[i].contact<<endl;
		cout<<"\n Existing cash "<<person[i].cash<<endl;
		cout<<"press 1 to deposit"<<endl;
		cout<<"press 2 to withdraw"<<endl;
		ch=getch();
		switch(ch){
			case '1':
				cout<<"how much cash you want to deposit"<<endl;
				cin>>cash;
				person[i].cash+=cash;
				cout<<"your account balance is:"<<person[i].cash<<endl;
				break;
				case '2':
					back:
					cout<<"how much cash you want to withdraw"<<endl;
					cin>>cash;
					if(cash>person[i].cash){
						cout<<"your withdrawl limit exceeds your balance:"<<person[i].cash<<endl;
						
						goto back;
					}
					person[i].cash-=cash;
					cout<<"your remaining balance is:"<<person[i].cash<<endl;
					cout<<"thank you!!"<<" "<<"visit again"<<endl;
					break;
					default:
						cout<<"invalid input"<<endl;
						break;
					
		}
		break;
	}
	
	if(i==total-1){
		cout<<"no such record found"<<endl;
		break;
	}
}
}
}
 
 void Bank::del()
{ system("cls");
 cout<<"......................................................................."<<endl;
 cout<<".                           DELETE RECORD                             ."<<endl;
 cout<<"......................................................................."<<endl;
if(total==0)
	{
		cout<<".....no data is there to delete...."<<endl;
	}
	
	else{
	int i,j;
	char ch;
	cout<<"press 1 to remove specific record"<<endl;
	cout<<"press 2 to remove the whole record"<<endl;
	ch=getch();
	switch(ch){
		case'1':
			cout<<"enter id of student those data you want to remove"<<endl;
			cin>>id;
			for(i=0;i<total;i++){
				if(id==person[i].id){
					for(j=i;j<total;j++){
					
					person[j].name=person[j+1].name;
					person[j].id=person[j+1].id;
					person[j].address=person[j+1].address;
					person[j].contact=person[j+1].contact;
					person[j].cash=person[j+1].cash;
					total--;
					break;
				}
				    	
				}
				if(i==total-1){
					cout<<"no such record found"<<endl;
				}
			}break;
			case'2':
				total=0;
				cout<<"all record is deleted"<<endl;
				break;
				default:
					cout<<"invalid input"<<endl;
					break;
	}
	
}
}

