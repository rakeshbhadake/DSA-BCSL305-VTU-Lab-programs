/**** 12. Given a File of N employee records with a set K of Keys (4-digit) which uniquely
 determine the records in file F. Assume that file F is maintained in memory by a Hash
 Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of
 locations in HT. Let the keys in K and addresses in L are Integers. Develop a Program in
 Cthat uses Hash function H: K →L as H(K)=K mod m (remainder method), and
 implement hashing technique to map a given key K to the address space L. Resolve the
 collision (if any) using linear probing.****/


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
