//merge alternate nodes of two linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node **start;

void print(struct node *x)
{
    struct node *temp=x;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}

void merge()
{
    int flag=0;
    struct node *temp=start[0]->next;
    struct node *temp1=start[1];
    head=start[0];
    struct node *temp2=head;
    while(temp!=NULL&&temp1!=NULL)
    {
        if(flag==0)
        {
            temp2->next=temp1;
            temp2=temp2->next;
            temp1=temp1->next;
            flag=1;
        }
        else if(flag==1)
        {
            temp2->next=temp;
            temp2=temp2->next;
            temp=temp->next;
            flag=0;
        }
    }
    if(temp==NULL)
        temp2->next=temp1;
    else if(temp1==NULL)
        temp2->next=temp;
    print(head);
}
int main()
{
    struct node *temp,*temp1;
    start=(struct node**)malloc(2*sizeof(struct node*));
    int i;
    char ch;
    for(i=0;i<2;i++)
    {
        //printf("h");
        start[i]=NULL;
        printf("for %d list\n",i+1);
        do
        {
            temp=(struct node*)malloc(sizeof(struct node));

            printf("Enter the data: ");
            scanf(" %d",&temp->data);
            temp->next=NULL;
            if(start[i]==NULL)
                start[i]=temp;
            else
            {
                temp1=start[i];
                while(temp1->next!=NULL)
                    temp1=temp1->next;
                temp1->next=temp;
            }
            printf("want to enter another node(y/n)");
            scanf(" %c",&ch);
        }
        while(ch!='n');
    }
    //print();
    merge();
    return 0;
}
