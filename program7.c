/****7
 7. Develop a menu driven Program in C for the following operations on Singly Linked List
 (SLL) of Student Data with the fields: USN, Name, Programme, Sem, PhNo.
 a. Create a SLL of N Students Data by using front insertion.
 b. Display the status of SLL and count the number of nodes in it
 c. Perform Insertion / Deletion at End of SLL
 d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
 e. Exit***/


#include<stdio.h>
 #include<stdlib.h>
 typedef struct node
 {
 char usn[20],name[20],branch[10],phno[10];
 int sem;
 struct node *link;
 }NODE;
 NODE*start= NULL;
 void main_menu();
 void create_list();
 void insert_front();
 void display();
 void insert_end();
 void del_front();
 void del_end();
 void stack();
 void main()
 {
 main_menu();
 }
 void main_menu()
 {
 int ch;
 while(1)
 {
 printf("\n SINGLY LINKED LIST IMLEMENTATION\n");
 printf("\n 1. CREATE LIST\n");
 printf("\n 2. INSERTION AND DELETION FROM FRONT(STACK)\n");
 printf("\n 3. INSERT END\n");
 printf("\n 4. DELETE END\n");
 printf("\n 5. DISPLAY\n");
 printf("\n 6. EXIT\n");
 printf("\n ENTER YOUR CHOICE\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: create_list();
break;
 case 2: stack();
 break;
 case 3: insert_end();
 break;
 case 4: del_end();
 break;
 case 5: display();
 break;
 case 6: exit(0);
 default: printf("\n INVALID CHOICE\n");
 }
 }
 }
 void create_list()
 {
 NODE*newnode=NULL; int n,i;
 printf("enter the number of nodes\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 insert_front();
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
 printf("\n USN\tNAME\tBRANCH\tSEM\tPHONENUMBER\n");
 while(curptr!=NULL)
 {
 printf("%s\t%s\t%s\t%d\t%s\n",curptr->usn,curptr->name,curptr->branch,curptr->sem,curptr->phno);
 curptr=curptr->link;
 count++;
 }
 }
 printf("\n NUMBER OF NODES= %d",count);
 }
 void stack()
 {
 int ch;
 while(1)
 {
 printf("\n STACK IMPLEMENTATION\n");
printf("\n 1.insert front\n");
 printf("\n 2. delete front\n");
 printf("\n 3. display\n");
 printf("\n 4. exit from stack menu\n");
 printf("\n enter your choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: insert_front();
 break;
 case 2: del_front();
 break;
 case 3: display();
 break;
 case 4: main_menu();
 break;
 default: printf("\n invalid choice\n");
 }
 }
 }
 void insert_front()
 {
 NODE*newnode=NULL;
 newnode=(NODE*)malloc(sizeof(NODE));
 printf("enter USN\n");
 scanf("%s",newnode->usn);
 printf("enter name and branch\n");
 scanf("%s%s",newnode->name,newnode->branch);
 printf("enter semester\n");
 scanf("%d",&newnode->sem);
 printf("enter phone number\n");
 scanf("%s",newnode->phno);
 newnode->link=start;
 start=newnode;
 }
 void del_front()
 {
 NODE*curptr=NULL;
 if(start==NULL)
 printf("\n LIST EMPTY\n");
 else
 {
 curptr=start;
 start=start->link;
 printf("the deleted information is \n");
 printf("\n USN\tNAME\tBRANCH\tSEM\tPHONENUMBER\n");
printf("%s\t%s\t%s\t%d\t%s\n",curptr->usn,curptr->name,curptr->branch,curptr->sem,curptr->phno);
 free(curptr);
 }
 }
 void insert_end()
 {
 NODE*curptr,*newnode=NULL;
 newnode=(NODE*)malloc(sizeof(NODE));
 printf("enter USN\n");
 scanf("%s",newnode->usn);
 printf("enter name and branch\n");
 scanf("%s%s",newnode->name,newnode->branch);
 printf("enter semester\n");
 scanf("%d",&newnode->sem);
 printf("enter phone number\n");
 scanf("%s",newnode->phno);
 if(start==NULL)
 {
 newnode->link=start;
 start=newnode;
 }
 else
 {
 curptr=start;
 while(curptr->link !=NULL)
 curptr=curptr->link;
 newnode->link=NULL;
 curptr->link=newnode;
 }
 }
 void del_end()
 {
 NODE*curptr=NULL,*nextcur=NULL;
 if(start==NULL)
 printf("\n LIST EMPTY\n");
 else if(start->link==NULL)
 {
 printf("the deleted information is \n");
 printf("\n USN\tNAME\tBRANCH\tSEM\tPHONENUMBER\n");
 printf("%s\t%s\t%s\t%d\t%s\n",start->usn,start->name,start->branch,start->sem,start->phno);
 free(start);
 start=NULL;
 }
 else
 {
curptr=start;
 nextcur=curptr;
 while(curptr->link!=NULL)
 {
 nextcur=curptr;
 curptr=curptr->link;
 }
 nextcur->link=NULL;
 printf("the deleted information is \n");
 printf("\n USN\tNAME\tBRANCH\tSEM\tPHONENUMBER\n");
 printf("%s\t%s\t%s\t%d\t%s\n",curptr->usn,curptr->name,curptr->branch,curptr->sem,curptr->phno);
 free(curptr);
 }
 }
