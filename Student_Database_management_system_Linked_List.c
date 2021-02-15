#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


struct student{
char fn[100];
char ln[100];
char roll[10],add[30],d[15],ph[10];
struct student *next;
};
struct student *first=NULL,*last=NULL,*k,*t;


void create(int n)
{
int i;
system("cls");
first=(struct student*)malloc(sizeof(struct student));
printf("\nEnter the first name of the student:");
scanf("%s",first->fn);
printf("\nEnter the last name of the student:");
scanf("%s",first->ln);
printf("\nEnter the roll number of the student:");
scanf("%s",first->roll);
 printf("\nEnter the Ph No. of Student : ");
  scanf("%s",first->ph);
  printf("\nEnter the Address of Student : ");
  scanf("%s",first->add);
  printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) : ");
  scanf("%s",first->d);
first->next=NULL;
last=first;
for(i=0;i<=n-2;++i) {
system("cls");
k=(struct student*)malloc(sizeof(struct student));
printf("\nEnter the first name of the student:");
scanf("%s",k->fn);
printf("\nEnter the last name of the student:");
scanf("%s",k->ln);
printf("\nEnter the roll number of the student:");
scanf("%s",k->roll);
printf("\nEnter the Ph No. of Student : ");
  scanf("%s",k->ph);
  printf("\nEnter the Address of Student : ");
  scanf("%s",k->add);
  printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) : ");
  scanf("%s",k->d);
k->next=NULL;
last->next=k;
last=k;
}
}


void display()
{
struct student *t;
system("cls");
t=first;
while(t!=NULL)
{
printf("\nThe roll number of the student:%s",t->roll);
printf("\nFirst name of the student:%s",t->fn);
printf("\nEnter the Last Name of Student :%s",t->ln);
printf("\nEnter the Ph No. of Student :%s",t->ph);
printf("\nEnter the Address of Student :%s",t->add);
printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) :%s\n",t->d);
t=t->next;
}
}


void insertafter()
{
char r[10];
int flag=0;
system("cls");
printf("\nEnter the roll number u wanna insert after that:");
scanf("%s",r);
t=first;
while(t!=NULL)
{
if(strcmpi(r,t->roll)==0)
{
k=(struct student*)malloc(sizeof(struct student));
printf("\nEnter the first name of the student:");
scanf("%s",k->fn);
printf("\nEnter the last name of the student:");
scanf("%s",k->ln);
printf("\nEnter the roll number of the student:");
scanf("%s",k->roll);
printf("\nEnter the Ph No. of Student : ");
  scanf("%s",k->ph);
  printf("\nEnter the Address of Student : ");
  scanf("%s",k->add);
  printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) : ");
  scanf("%s",k->d);
k->next=t->next;
t->next=k;
flag=1;
break;
}
t=t->next;
}
if(flag==0)
printf("\nThe element not found!!!");
}


void del()
{
struct student *back,*t,*k;
char r[10];
int flag=0;
system("cls");
printf("\nEnter the roll number u wanna delete:");
scanf("%s",r);
if(strcmpi(r,first->roll)==0)
{
first=first->next;
flag=1;
}
else
{
back=first;
k=first->next;
while(k!=NULL)
{
if(strcmpi(r,k->roll)==0)
{
back->next=k->next;
flag=1;
break;
}
}
}
if(flag==0)
printf("\nThe element not found!!!");
}


void search()
{
char r[10];
int flag=0;
system("cls");
printf("\nEnter the roll number u wanna search:");
scanf("%s",r);
t=first;
while(t!=NULL)
{
if(strcmpi(r,t->roll)==0)
{
printf("\nThe roll number found in the list!!!\n first name of Student is %s",t->fn);
printf("\n the Last Name of Student is %s",t->ln);
printf("\n the Ph No. of Student is %s",t->ph);
printf("\n the Address of Student is %s",t->add);
printf("\nEnter the D.O.B. of Student is %s\n",t->d);
flag=1;
break;
}t=t->next;
}
if(flag==0)
printf("\nThe roll number not in database!!");
}

void main()
{
int n,ch;
system("cls");
while(1)
{
system("cls");
printf("\n-------------------------STUDENT DATABASE MANAGEMENT----------------------------\n");
printf("\n                               PROJECT BY AJAY                         \n");
printf("\n**************************************MENU**************************************\n");
printf("\nEnter 1 for creating database");
printf("\nEnter 2 for displaying database");
printf("\nEnter 3 for inserting an record after another");
printf("\nEnter 4 for deleting a record");
printf("\nEnter 5 for searching a record");
printf("\nEnter 6 for exit!\n");
printf("\n--------------------------------------------------------------------------------\n");
scanf("%d",&ch);
if (ch==6)
   break;
switch(ch)
{
case 1:printf("\nEnter the maximum size of the database:");
       scanf("%d",&n);
       create(n);
       break;
case 2:display();
       break;
case 3:insertafter();
       break;
case 4:del();
       break;
case 5:search();
       break;
default:printf("\nYou have entered a wrong choice!!!");
}
getch();
}
getch();
}
