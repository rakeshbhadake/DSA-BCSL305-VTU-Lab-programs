#include<stdio.h>
 char str[50], pat[20], rep[20], ans[50];
 int c=0, m=0, i=0, j=0, k, flag=0;
 void stringmatch()
 {
    while(str[c] !='\0')
    {
        if(str[m] == pat[i])
        {
            i++;
            m++;
                if(pat[i] == '\0')
                {
                    flag = 1;
                    for(k=0; rep[k]!='\0'; k++, j++)
                        {
                            ans[j] = rep[k];
                         }
                    c=m;
                    i=0;
                }
        }
         else
        {
            ans[j]= str[c];
            j++;
            c++;
            m=c;
            i=0;
         }

    }
 ans[j]='\0';
 }
 
 void main()
 {
 printf("\nEnter the main string:\t");
 gets(str);
 printf("\nEnter the pat string:\t");
 gets(pat);
 printf("\nEnter the replace string:\t");
 gets(rep);
 stringmatch();
 if(flag == 1)
 printf("\nResultant string is :\t%s\n", ans);
 else
 printf("\nPattern string is not found");
 }