/****8. Develop a menu driven Program in C for the following operations on Doubly Linked
 List(DLL)of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
 a. Create a DLL of N Employees Data by using end insertion.
 b. Display the status of DLL and count the number of nodes in it
 c. Perform Insertion and Deletion at End of DLL
 d. Perform Insertion and Deletion at Front of DLL
 e. Demonstrate how this DLL can be used as Double Ended Queue.
 f. Exit****/


 #include<stdio.h>
 #include<stdlib.h>
 typedef struct node
 {
 char ssn[10],name[20],dept[10],desig[10],phno[10];
 int sal;
 struct node *llink;
 struct node *rlink;
 }NODE;
 NODE*start=NULL;
 void create();
 void display();
 void insert_front();
 void del_front();
 void insert_end();
 void del_end();
 void enqueue();
 void dqueue();
 void main_menu();
 void main()
 {
 main_menu();
 }
 void main_menu()
 {
 int ch;
 while(1)
 {
 printf("\n DOUBLY LINKED LIST IMPLEMENTATION\n");
 printf("\n 1. CREATE LIST\n");
 printf("\n 2. DISPLAY LIST\n");
 printf("\n 3. INPUT RESTRICTED QUEUE\n");
printf("\n 4. OUTPUT RESTRICTED QUEUE\n");
 printf("\n 5.EXIT\n");
 printf("\n ENTER YOUR CHOICE\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: create(); break;
 case 2: display();break;
 case 3: enqueue(); break;
 case 4: dqueue(); break;
 case 5: exit(0);
 default: printf("\n INVALID CHOICE\n");
 }
 }
 }
 void create()
 {
 int i,n;
 printf("\n enter the number of nodes\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 insert_end();
 }
 void display()
 {
 NODE*curptr=NULL;
 int count=0;
 if(start==NULL)
 printf("\n LIST EMPTY\n");
 else
 {
 curptr=start;
 printf("\n The contents are\n");
 printf("\n SSN\t\tNAME\t\tDEPT\t\tDESIG\t\tSALARY\t\tPHONE\n");
 while(curptr!=NULL)
 {
 printf("\n %s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%s\n",curptr->ssn, curptr->name, curptr->dept, curptr->desig, curptr->sal, curptr->phno);
 count++;
 curptr=curptr->rlink;
 }
 }
 printf("\n TOTAL NUMBER OF NODES IS %d",count);
 }
void enqueue()
 {
 int ch;
 while(1)
 {
 printf("\n INPUT DEQUE\n");
 printf("\n 1. Insert from front\n");
 printf("\n 2. Delete from front\n");
 printf("\n 3. Delete from rear\n");
 printf("\n 4. display\n");
 printf("\n 5. exit \n");
 printf("\n enter your choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: insert_front();
 break;
 case 2: del_front();
 break;
 case 3: del_end();
 break;
 case 4: display();
 break;
 case 5: main_menu();
 break;
 default: printf("\n wrong choice\n");
 }
 }
 }
 void dqueue()
 {
 int ch;
 while(1)
 {
 printf("\n OUTPUT DEQUE\n");
 printf("\n 1. Insert from front\n");
 printf("\n 2. Insert from rear \n");
 printf("\n 3. Delete from rear\n");
 printf("\n 4. display\n");
 printf("\n 5. exit \n");
 printf("\n enter your choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: insert_front();
 break;
case 2: insert_end();
 break;
 case 3: del_end();
 break;
 case 4: display();
 break;
 case 5: main_menu();
 break;
 default: printf("\n wrong choice\n");
 }
 }
 }
 void insert_end()
 {
 NODE*newnode,*curptr=NULL;
 newnode=(NODE*)malloc(sizeof(NODE));
 printf("\nenter the ssn\n");
 scanf("%s",newnode->ssn);
 printf("\n enter name department and designation\n");
 scanf("%s%s%s",newnode->name,newnode->dept,newnode->desig);
 printf("\n enter salary\n");
 scanf("%d",&newnode->sal);
 printf("\n enter phone number\n");
 scanf("%s",newnode->phno);
 if(start==NULL)
 {
 newnode->rlink=NULL;
 newnode->llink=NULL;
 start=newnode;
 }
 else
 {
 curptr=start;
 while(curptr->rlink!=NULL)
 {
 curptr=curptr->rlink;
 }
 newnode->llink=curptr;
 newnode->rlink=NULL;
 curptr->rlink=newnode;
 }
 }
 void del_end()
 {
 NODE*curptr=NULL;
 if(start==NULL)
printf("\n LIST EMPTY\n");
 else if(start->rlink==NULL)
 {
 free(start);
 start=NULL;
 }
 else
 {
 curptr=start;
 while(curptr->rlink!=NULL)
 curptr=curptr->rlink;
 curptr->llink->rlink=NULL;
 free(curptr);
 }
 }
 void del_front()
 {
 NODE*curptr=NULL;
 if(start==NULL)
 printf("\n LIST EMPTY\n");
 else if(start->rlink==NULL)
 {
 free(start);
 start=NULL;
 }
 else
 {
 curptr=start;
 start=start->rlink;
 start->llink=NULL;
 free(curptr);
 }
 }
 void insert_front()
 {
 NODE*newnode,*curptr=NULL;
 newnode=(NODE*)malloc(sizeof(NODE));
 printf("\nenter the ssn\n");
 scanf("%s",newnode->ssn);
 printf("\n enter name department and designation\n");
 scanf("%s%s%s",newnode->name,newnode->dept,newnode->desig);
 printf("\n enter salary\n");
 scanf("%d",&newnode->sal);
 printf("\n enter phone number\n");
 scanf("%s",newnode->phno);
 if(start==NULL)
{
 newnode->rlink=NULL;
 newnode->llink=NULL;
 start=newnode;
 }
 else
 {
 newnode->rlink=start;
 start->llink=newnode;
 start=newnode;
 }
 }
