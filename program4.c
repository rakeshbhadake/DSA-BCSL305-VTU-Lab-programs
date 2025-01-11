/**** 4. Develop a Program in C for converting an Infix Expression to Postfix
 Expression.Program should support for both parenthesized and free parenthesized
 expressions with the operators: +,-, *, /, % (Remainder), ^ (Power) and alphanumeric
 operands.****/


#include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<ctype.h>
 char stack[100];
 int top=-1;
 void push(char x)
 {
 stack[++top]=x;
 }
 char pop()
 {
 if(top==-1) return-1;
 return stack[top--];
 }
 int priority(char x)
 {
 if(x=='(')
 return 1;
 if(x=='+'||x=='-')
 return 2;
 if(x=='*'||x=='/'||x=='%')
 return 3;
 if(x=='^'||x=='$')
 return 4;
 return 1;
 }
 void main()
 {
 char expression[100];
 char symbol,a;
 int i=0;
 
 printf("enter infix expression:\n");
 scanf("%s",expression);
 printf("postfix expression is\n");
  for(i=0;i<strlen(expression);i++)
 {
 symbol=expression[i];
 if(isalnum(symbol))
 printf("%c ",symbol);
 else if(symbol=='(')
 push(symbol);
 else if(symbol==')')
 {
 while((a=pop())!='(') printf("%c ",a);
 }
 else
 {
 }
 }
 while(top!=-1)
 {
 while(priority(stack[top])>=priority(symbol))
 {
 printf("%c ",pop());
 }
 push(symbol);
 printf("%c ",pop());
 }
 printf("\n");
 }
