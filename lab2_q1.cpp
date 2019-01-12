#include<iostream>
using namespace std;

class node{
	public:
	//Data
	int data;
	//pointer to next Node
	node *next;
	//Constructor that makes ptr to null
	node()
	{
		next = NULL;
	}
};
class linkedlist{
	//Head+circles inside linked with each other
	public:
	//head
	node *head,*tail;
	//constructor
	linkedlist(){
		head = NULL;
		tail = NULL;
	}
	//Circles inside linked with each other
	//Rules how circles are linked
	
	//insert ( This inserts at the end )
	void insert(int value);
	//delete
	void del();
	
	//display
	void display();

	//insertat function
	void insertat(int pos, int value);

	//deleteat function
	void deleteat(int pos);
	
};

void linkedlist::insert(int value)
{
	node *temp = new node;
	temp->data = value; 		
	// If first Node is added
	if ( head == NULL )
	{	
		head = temp;
	}
	else{ 
	tail->next = temp;
	}
	tail = temp;
}

void linkedlist::del()
{
	node *temp=tail,*ptr = head;
	while (ptr->next !=tail)
	{
		ptr = ptr->next;
	}
	tail = ptr;
	tail->next = NULL;
	delete temp;	
}

void linkedlist::display()
{
	node *ptr = head;
	while (ptr != NULL)
	{
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<endl;
}

void linkedlist::insertat(int pos, int value)
{
	int i=1;node *current = head;
	while(i<pos-1)
	{
		current = current->next;
		i++;
	}
	node *temp=new node;
	temp->data=value;
	temp->next=current->next;
	current->next=temp;
}

void linkedlist::deleteat(int pos)
{
	node *ptr=head,*del;int i=1;
	while(i<pos-1)
	{	
		ptr=ptr->next;
		i++;	
	}
	del=ptr->next;
	ptr->next=del->next;
	delete del;	
}


int main()
{	
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.display();
	l1.del();
	l1.display();
	l1.insertat(3,10);
	l1.display();
	l1.deleteat(3);
	l1.display();
	return 0;
}
