#include<iostream>
#include <stdlib.h>
#include <string >
using namespace std;
struct node
{
   string name , number,address,e_mail;
   node *next;
};
node *head = NULL , *newnode , *temp;
int len = 0 ;
void C_node ()
{
    newnode = new node;
    cout<<"Enter Name ";
    cin>>newnode->name;
    cout<<"Enter number ";
    cin>>newnode->number;
    cout<<"Enter Address ";
    cin>>newnode->address;
    cout<<"Enter e-mail ";
    cin>>newnode->e_mail;
    
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next= newnode;
        temp = newnode;
    }
}
void display ()
{
    if(head == NULL)
    {
        cout<<"Contact list is Empty "<<endl;
    }
    else
    {
        node *trav = head ;
        while (trav != NULL)
        {
            cout<<"\n\t\tFull Name "<<trav->name<<endl;
            cout<<"\t\tPhone Number "<<trav->number<<endl;
             cout<<"\t\t\tAddress "<<trav->number<<endl;
             cout<<"\t\t\t\tE-mail "<<trav->e_mail<<endl;
            
            trav= trav->next;
            len++;
        }
        cout<<"Here is your all contact in the list = "<<len<<endl;
    }
}
void search_contact ()
{
    node *search_node = head;
    string srch;
    int count = 1;
    cout<<"provide contact name to search ";
    cin>>srch;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\n Contact List is Empty "<<endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if(srch == search_node->name || srch == search_node->number || srch==search_node->address||srch==search_node->e_mail)
            {
                cout<<"\n\t\tFull name: "<<search_node->name<<endl;
                cout<<"\t\tPhone number: "<<search_node->number<<endl;
                cout<<"\t\t\tAddress : "<<search_node->address<<endl;
                cout<<"\t\t\tE-mail : "<<search_node->e_mail<<endl;
                found =true;
                break;
            }
            search_node = search_node->next;
            count++;
        }
    }
    if(found == true)
    {

        cout<<"\t\tIndex of the Contact = "<<count<<endl;
    }
    else
    {
        cout<<"This contact is not availabe in this list "<<endl;
    }
}
void at_given () ///deletion function
{
    int pos ;
    node *next_node;
    temp = head;
    cout<<"Enter the position from where you want to delete contact "<<endl;
    cin>>pos;
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else if (pos > len)
    {
        cout<<"Invalid Position "<<endl;
    }
    else if(pos == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        cout<<"Contact has been deleted "<<endl;
    }
    else
    {
        for (int i = 1 ; i<pos ; i++)
        {
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"Contact has been deleted "<<endl;
    }
}
void clear_all ()
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        temp = head ;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout<<"\n\t\tALL contact list has been deleted "<<endl;
    }
}
void menu ()
{
	cout<<"***************** welcome to contact management*****************" <<endl;
    cout<<"Enter 1 To add a contact   "<<endl;
    cout<<"Enter 2 To display all contact "<<endl;
    cout<<"Enter 3 To search a contact   "<<endl;
    cout<<"Enter 4 To delete a contact from the list  "<<endl;
    cout<<"Enter 5 To clear All record from the list "<<endl;
}
int main ()
{
    int op;
    while (true )
    {
        menu();
        cin>>op;
        switch (op)
        {
        case 1:
            C_node();
            break;
        case 2:
            len = 0;
            display();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            at_given();
            break;
        case 5:
            clear_all();
            break;
        default:
            cout<<"Invalid Option "<<endl;
        }
    }
}
