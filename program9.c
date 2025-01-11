#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int coef,flag;
    int xexp,yexp,zexp;
    struct node *link;
};
typedef struct node* NODE;
NODE create()
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("insufficient memory");
        exit(0);
    }
    return p;
}
NODE attach(int coef,int xexp,int yexp,int zexp,NODE head)
{
    NODE temp,cur;
    temp=create();
    temp->coef=coef;
    temp->xexp=xexp;
    temp->yexp=yexp;
    temp->zexp=zexp;
    temp->flag=0;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return head;
}
NODE read_poly(NODE head)
{
    int coef,xexp,yexp,zexp;
    int i,n;
    printf("enter the no of term of polynomial:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("%dth term:\n ",i);
        printf("enter coef,xexp,yexp,zexp:\n");
        scanf("%d%d%d%d",&coef,&xexp,&yexp,&zexp);
        head=attach(coef,xexp,yexp,zexp,head);
    }
    return head;
}
void display(NODE head)
{
    NODE temp;
    if(head->link==head)
    {
        printf("display not possible\n");
        return;
    }
    temp=head->link;
    while(temp!=head)
    {
        printf("%dx^%dy^%dz^%d",temp->coef,temp->xexp,temp->yexp,temp->zexp);
        temp=temp->link;
        if(temp!=head)
        printf("+");
    }
    
}
void evaluate(NODE head)
{
    int x,y,z,val=0;
    NODE poly;
    printf("enter x,y and z values");
    scanf("%d%d%d",&x,&y,&z);
    poly=head->link;
    while(poly!=head)
    {
        val=val+(poly->coef)*pow(x,poly->xexp)*pow(y,poly->yexp)*pow(z,poly->zexp);
        poly=poly->link;
    }
    printf("evaluated ressult is :%d",val);

}
NODE polyadd(NODE h1,NODE h2,NODE h3)
{
    NODE p1,p2;
    int x1,y1,z1,coef1;
    int x2,y2,z2,coef2,coefres=0;
    p1=h1->link;
    while(p1!=h1)
    {
        int consider=0;
        coef1=p1->coef;
        x1=p1->xexp;
        y1=p1->yexp;
        z1=p1->zexp;
        p2=h2->link;
        while(p2!=h2)
        {
            coef2=p2->coef;
            x2=p2->xexp;
            y2=p2->yexp;
            z2=p2->zexp;
            if(x1==x2&&y1==y2&&z1==z2)
            {
                consider=1;
                p2->flag=1;
                coefres=coef1+coef2;
                if(coefres!=0)
                h3=attach(coefres,x1,y1,z1,h3);

            }
            p2=p2->link;
        }
        if(consider==0)
        h3=attach(coef1,x1,y1,z1,h3);
        p1=p1->link;
    }
    p2=h2->link;
    while(p2!=h2)
    {
        if(p2->flag==0)
        h3=attach(p2->coef,p2->xexp,p2->yexp,p2->zexp,h3);
        p2=p2->link;
    }
    return h3;
}
void main()
{
    NODE head,h1,h2,h3;
    head=create();
    h1=create();
    h2=create();
    h3=create();
    int ch;
    head->link=head;
    h1->link=h1;
    h2->link=h2;
    h3->link=h3;
    while(1)
    {
        printf("\n1.evaluation\n2.addition\n3.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("polynomial evaluation\n");
                   head=read_poly(head);
                   display(head);
                   evaluate(head);
                   break;
            case 2:printf("poly addition\n");
                   printf("enter poly 1:\n");
                   h1=read_poly(h1);
                   display(h1);
                   printf("enter poly2:\n");
                   h2=read_poly(h2);
                   display(h2);
                   h3=polyadd(h1,h2,h3);
                   printf("the polyaddition result:\n");
                   display(h3);
                   break;
            case 3:exit(0);
            default:printf("invalid choice");
        }
    }

}