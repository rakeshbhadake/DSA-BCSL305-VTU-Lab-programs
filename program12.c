#include<stdio.h>
#include<stdlib.h>

int m,n,key[20],count=0;
int *ht,index;
void insert(int key)
{
    if(count==m){
        printf("the hash table is full\n");

    }
    else{
        index=key%m;
        if(ht[index]!=-1)
        {
            printf("the collision detected\n");
            while(ht[index]!=-1)
            {
                index=(index+1)%m;

            }
        }
        ht[index]=key;
        count++;

    }
}
void display()
{
    int i;
    printf("the hash table is \n");
    for(i=1;i<=m;i++)
    {
        printf("T[%d]-->%d\n",i,ht[i]);


    }

}
void main()
{
    int i;
    printf("enter the number of employee key to store in the hash table:\n");
    scanf("%d",&n);
    printf("enter the hash table size\n");
    scanf("%d",&m);
    ht=(int*)malloc(m*sizeof(int));
    for(i=1;i<=m;i++)
    ht[i]=-1;
    printf("enter the keys for %d employees\n",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&key[i]);
        insert(key[i]);
    }
    display();


}