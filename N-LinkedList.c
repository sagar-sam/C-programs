#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char data_type[20];
    char name[20];
    struct node *next;
    int id;
};
struct node *head=NULL;
struct node **start;
void print(int i)
{
    struct node *temp;
    if(i==-1)
        temp=head;
    else
        temp=start[i];
    printf("data type   ->   name\n");
    while(temp!=NULL)
    {
        printf("%s   ->   %s\n",temp->data_type,temp->name);
        temp=temp->next;
    }
}
int main()
{
    int a,count=0;
    char ch='y';
    struct node *temp,*temp1;
    while(ch!='n')
    {
        if(ch=='y')
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("enter the data type: ");
            scanf(" %s",temp->data_type);
            printf("enter the name of %s: ",temp->data_type);
            scanf(" %s",temp->name);
            temp->next=NULL;
            if(head==NULL)
                head=temp;
            else
            {
                temp1=head;
                while(temp1->next!=NULL)
                    temp1=temp1->next;
                temp1->next=temp;
            }
        }
        printf("want to enter another node(y/n): ");
        scanf(" %c",&ch);
    }
    print(-1);
    temp=head;
    temp->id=0;
    count=1;
    temp=temp->next;
    while(temp!=NULL)
    {
        a=1;
        temp1=head;
        while(temp1!=temp)
        {
            if(strcmp(temp1->data_type,temp->data_type)==0)
                {
                    temp->id=temp1->id;
                    a=0;
                    break;
                }
            temp1=temp1->next;
        }
        if(a!=0){
            temp->id=count;
            count++;
        }
        temp=temp->next;
    }
    start=(struct node**)malloc(count*sizeof(struct node*));
    for(a=0;a<count;a++)
    {
        start[a]=NULL;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->id==a)
            {
                struct node *new_node=(struct node*)malloc(sizeof(struct node));
                strcpy(new_node->data_type,temp->data_type);
                strcpy(new_node->name,temp->name);
                new_node->next=NULL;
                new_node->id=temp->id;
                if(start[a]==NULL)
                    start[a]=new_node;
                else
                {
                    temp1=start[a];
                    while(temp1->next!=NULL)
                        temp1=temp1->next;
                    temp1->next=new_node;
                }
            }
            temp=temp->next;
        }
    }
    printf("you have entered %d data types\n",count);
    for(a=0;a<count;a++)
        printf("enter %d for %s list\n",a+1,start[a]->data_type);
    printf("Enter 0 to exit\n");
    scanf("%d",&a);
    while(a!=0)
    {
	print(a-1);
        for(a=0;a<count;a++)
            printf("enter %d for %s list\n",a+1,start[a]->data_type);
	printf("Enter 0 to exit\n");
	scanf("%d",&a);
    }
    return 0;
}
