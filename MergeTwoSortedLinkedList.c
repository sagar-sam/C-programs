#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    struct node *next;
};

struct node *start[2];
struct node *head=NULL;
void print()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->id);
        temp=temp->next;
    }
}
void merge()
{
    struct node *temp=start[0];
    struct node *temp1=start[1];
    if(temp->id<temp1->id)
    {
        head=start[0];
        temp=temp->next;
    }
    else
    {
        head=start[1];
        temp1=temp1->next;
    }
    struct node *temp2=head;
    while(temp!=NULL && temp1!=NULL)
    {
        if(temp->id<temp1->id)
        {
            temp2->next=temp;
            temp=temp->next;
            temp2=temp2->next;
        }
        else
        {
            temp2->next=temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    if(temp==NULL)
        temp2->next=temp1;
    else
        temp2->next=temp;
    print();
    printf("\n");
}
int main()
{
    int i;
    char ch;
    for(i=0;i<2;i++)
    {
	printf("List %d\n",i+1);
        do
        {
            struct node *temp=(struct node*)malloc(sizeof(struct node));
            temp->next=NULL;
            printf("Enter id: ");
            scanf("%d",&temp->id);
            if(start[i]==NULL)
                start[i]=temp;
            else
            {
                struct node *temp1=start[i];
                while(temp1->next!=NULL)
                    temp1=temp1->next;
                temp1->next=temp;
            }
            printf("want to enter another node(y/n): ");
            scanf(" %c",&ch);
        }while(ch!='n');
    }
    merge();
    return 0;
}
