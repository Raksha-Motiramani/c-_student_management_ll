#include <iostream>
#include <conio.h>
using namespace std;

class node
{
  public:
    int roll_no;
    string name;
    float marks,percentage;
    node *next;
};

class linked_list
{
  public:
     node *head=NULL;
     void Insert()
     {
         int r;
         string n;
         float m;
         cout<<"\n\n ENTER ROLL NO. :";
         cin>>r;
         cout<<"\n\n ENTER NAME :";
         cin>>n;
         cout<<"\n\n ENTER MARKS :";
         cin>>m;
         node *new_node = new node;
         new_node -> roll_no = r; 
         new_node -> name = n;
         new_node -> marks = m;
         new_node -> percentage = m/100*100 ;
         new_node -> next = NULL;
         if(head == NULL)
         {
            head = new_node;
         }
         else
         {
            node *ptr = head;
            while (ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new_node;
        }
        cout<<"\n\n\n NEW NODE INSERTED SUCCESSFULLY...";
     }

     void Search()
     {
         if(head == NULL)
         {
             cout<<"\n\n Linked list is empty...";
         }
         else
         {   
             int r , found=0;
             cout<<"\n\n ENTER ROLL NO. FOR SEARCH :";
             cin>>r;
             node *ptr = head;
             while (ptr != NULL)
             {
                if(r == ptr -> roll_no)
                {
                    cout<<"\n\n ROLL NO. : "<<ptr -> roll_no;
                    cout<<"\n\n NAME : "<<ptr -> name;
                    cout<<"\n\n MARKS : "<<ptr -> marks;
                    cout<<"\n\n PER % : "<<ptr -> percentage;
                    found++;
                }
                ptr = ptr -> next;
             }
             if(found == 0)
             {
                 cout<<"\n\n\n CANT FIND ROLL NO. "<<r<<" NOT IN RECORD...SORRY!!";
             }
         }
     }

     void Count()
     {
         if(head == NULL)
         {
             cout<<"\n\n Linked list is Empty...";
         }
         else 
         {
             int c=0;
             node *ptr = head;
             while (ptr != NULL)
             {
                 c++;
                 ptr = ptr -> next;
             }
             cout<<"\n\n Total no of nodes : "<<c;
         }
     }

    void Update()
     {
         if(head == NULL)
         {
             cout<<"\n\n Linked list is empty...";
         }
         else
         {   
             int r , found=0;
             //float m;
            // string n;
             cout<<"\n\n ENTER ROLL NO. FOR UPDATION :";
             cin>>r;
             node *ptr = head;
             while (ptr != NULL)
             {
                if(r == ptr -> roll_no)
                {
                    cout<<"\n\n ENTER  NEW ROLL NO. :";
                    cin>>ptr->roll_no;
                    cout<<"\n\n ENTER NAME :";
                    cin>>ptr->name;
                    cout<<"\n\n ENTER MARKS :";
                    cin>>ptr->marks;
                    float x;
                    x=ptr->marks;
                    ptr->percentage= x/100*100;
                    cout<<"\n\n\n RECORD UPDATED SUCCESSFULLY!!!";
                    found++;
                }
                ptr = ptr -> next;
             }
             if(found == 0)
             {
                 cout<<"\n\n\n CANT FIND ROLL NO. "<<r<<" NOT IN RECORD...SORRY!!";
             }
         }
     } 

     void Delete()
     {
         if(head == NULL)
         {
             cout<<"\n\n Linked list is empty...";
         }
         else
         {   
             int r , found=0;
             cout<<"\n\n ENTER ROLL NO. FOR Deletion :";
             cin>>r;
             if(r==head->roll_no)
             {
                 node *ptr = head;
                 head = head -> next;
                 cout<<"\n\n Record deleted successfully...";
                 found++;
                 delete ptr;
             }
             else
             {
                 node *pre = head;
                 node *ptr = head -> next;
                 while (ptr!=NULL)
                 {
                     if(r = ptr -> roll_no)
                     {
                         pre -> next = ptr -> next;
                         cout<<"\n\n Record deleted successfully...";
                         found++;
                         delete ptr;
                         break;
                     }
                     pre = ptr;
                     ptr= ptr-> next;
                 }
            }
            if(found==0)
            {
                cout<<"\n\n Delete roll no "<<r<<"cant find...";
            }
         }
     } 

     void Show()
     {
         if(head == NULL)
         {
             cout<<"\n\n Linked list is empty...";
         }
         else
         {  
             node *ptr = head;
             while (ptr != NULL)
             {
               
                cout<<"\n\n ROLL NO. : "<<ptr -> roll_no;
                cout<<"\n\n NAME : "<<ptr -> name;
                cout<<"\n\n MARKS : "<<ptr -> marks;
                cout<<"\n\n PER % : "<<ptr -> percentage;
                ptr = ptr -> next;
             }
         }
     }
};

main()
{
   linked_list obj;
   p:
   system("cls");
   int choice;
   cout<<"\n\n 1) INSERT RECORD";
   cout<<"\n\n 2) SEARCH RECORD";
   cout<<"\n\n 3) COUNT NODES";
   cout<<"\n\n 4) UPDATE RECORD";
   cout<<"\n\n 5) DELETE RECORD";
   cout<<"\n\n 6) SHOW ALL RECORD";
   cout<<"\n\n 7) EXIT";
   cout<<"\n\n\n YOUR CHOICE : ";
   cin>>choice;
   switch(choice)
   {
       case 1:
            system("cls");
            obj.Insert();
            break;
       case 2:
            system("cls");
            obj.Search();
            break;
       case 3:
            system("cls");
            obj.Count();
            break;
       case 4:
            system("cls");
            obj.Update();
            break;
       case 5:
            system("cls");
            obj.Delete();
            break;
       case 6:
            system("cls");
            obj.Show();
            break;
       case 7:
            exit(0);
       default:
            cout<<"/n/n/n INVALID CHOICE...pls try again";
   }
   getch();
   goto p;
}