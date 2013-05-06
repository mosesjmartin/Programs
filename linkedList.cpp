/* Implementation of Linked List */

#include<iostream>
using namespace std;
class node
{
	private:
		int data;
		class node *next;
	public:
		node(int a=0,class node *p=0)
		{
			data=a;
			next=p;
		}
		void ath(int e);
		void ate(int e);
		void atl(int e);
		void dfh();
		void dfe();
		void dfl();
		void display();
}*head;
void node::ath(int e)
{
	if(head==0)
		head=new node(e);
	else
	{
		class node *temp=new node(e);
		temp->next=head;
		head=temp;
	}
}
void node::ate(int e)
{
	if(head==0)
		head=new node(e);
	else
	{
		class node *temp=new node(e);
		class node *t;
		for(t=head;t->next!=NULL;t=t->next);
		t->next=temp;
	}
}
void node::atl(int e)
{
	int l;
	cout<<"Enter the location: ";
	cin>>l;
	if(head==0)
		head=new node(e);
	else
	{
		class node *temp=head,*t=new node(e),*temp1;
		for(int i=1;i<l;i++)
		{
			temp1=temp;
			temp=temp->next;
		}
		t->next=temp;
		temp1->next=t;
	}
}
void node::dfh()
{
	if(head==NULL)
		cout<<"List is EMPTY!!!";
	else if(head->next==NULL)
	{
		delete head;
		head=0;
		cout<<"\nValue deleted...";
	}
	else
	{
		class node *temp=head;
		head=temp->next;
		delete temp;
		cout<<"\nValue deleted...";
	}
}
void node::dfe()
{
	if(head==NULL)
		cout<<"List is EMPTY!!!";
	else if(head->next==NULL)
	{
		delete head;
		head=0;
		cout<<"\nValue deleted...";
	}
	else
	{
		class node *temp=head;
		class node *t;
		for(;temp->next!=NULL;temp=temp->next)
			t=temp;
		delete temp;
		t->next=0;
		cout<<"\nValue deleted...";
	}
}
void node::dfl()
{
	int l;
	cout<<"Enter the location: ";
	cin>>l;
	if(head==NULL)
		cout<<"List is EMPTY!!!";
	else if(head->next==0)
	{
		delete head;
		head=0;
		cout<<"\nValue deleted...";
	}
	else
	{
		class node *temp=head,*t;
		for(int i=1;i<l;i++)
		{
			t=temp;
			temp=temp->next;
		}
		t->next=temp->next;
		delete temp;		
		cout<<"\nValue deleted...";
	}
}
void node::display()
{
	if(head==NULL)
		cout<<"List is EMPTY!!!";
	else
	{
		class node *temp=head;
		cout<<"\nThe values in the list: ";
		for(;temp->next!=NULL;temp=temp->next)
			cout<<temp->data<<" ";
		cout<<temp->data;
	}
}
int main()
{
	int c,a;
	do
	{
		cout<<"\n\n\t\tMENU";
		cout<<"\n1.Add To Head";
		cout<<"\n2.Add To End";
		cout<<"\n3.Add To Location";
		cout<<"\n4.Delete from Head";
		cout<<"\n5.Delete From End";
		cout<<"\n6.Delete From Location";
		cout<<"\n7.Display";
		cout<<"\n8.Exit";
		cout<<"\nEnter your choice: ";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<"\nEnter the value to add: ";
				cin>>a;
				head->ath(a);
				cout<<"Value added...";
				break;
			case 2:
				cout<<"\nEnter the value to add: ";
				cin>>a;
				head->ate(a);
				cout<<"Value added...";
				break;
			case 3:
				cout<<"\nEnter the value to add: ";
				cin>>a;
				head->atl(a);
				cout<<"Value added...";
				break;
			case 4:
				head->dfh();
				break;
			case 5:
				head->dfe();
				break;
			case 6:
				head->dfl();
				break;
			case 7:
				head->display();
				break;
			case 8:
				break;
			default:
				cout<<"\nINVALID Choice...";
		}
	}while(c!=8);
	cout<<"\n";
	return 0;
}
