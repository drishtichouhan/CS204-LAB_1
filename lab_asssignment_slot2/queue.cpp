#include<bits/stdc++.h>
using namespace std;
class node
{
      public:
             class node *next;
             int data;
};

class Queue : public node
{
            node *head;
            int front,rare;
	public:
           Queue()
           	{
            	front=-1;
             	rare=-1;
             }
           void push(int x)
           	{
            	if (rare < 0 )
             		{
               			head =new node;
                  		head->next=NULL;
                    	head->data=x;
                     	rare ++;
                     }
             else
                    {
                    	node *temp,*temp1;
                     	temp=head;
                      	if(rare >= 4)
                          {
                          	cout <<"queue over flow";
                           	return;
                           }
                        rare++;
                        while(temp->next != NULL)
                        	temp=temp->next;
                        temp1=new node;
                        temp->next=temp1;
                        temp1->next=NULL;
                        temp1->data=x;
                    }  }

           void display()
           	{
              node *temp;
              temp=head;
              if (rare < 0)
                {
                    cout <<" queue under flow";
                    return;
                 }
              while(temp != NULL)
               {
               	   cout <<temp->data<< " ";
                   temp=temp->next;
                }
             }
             void pop()
              {
              	node *temp;
               	temp=head;
                if( rare < 0)
                  {
                  	cout <<"queue under flow";
                   	return;
                   }
                if(front == rare)
                  {
                  	front = rare =-1;
                   	head=NULL;
                    return;
                   }
                front++;
                head=head->next;
                }
};
int main()
{
	Queue s1;
	int ch;
	while(1)
      {
		cout <<"\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n enter ru choice:";
		cin >> ch;
		switch(ch)
		{
            case 1:
                 	cout <<"\n enter a element";
                  	cin >> ch;
                   	s1.push(ch); break;

            case 2: s1.pop();break;
            case 3: s1.display();break;
        	case 4: exit(0);
		  }
       }
return (0);
}
