#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *end=NULL;
void print()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int count=0;
    char ch='y';
    while(ch!='n')
    {
        count++;
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->next=NULL;
        printf("enter the data: ");
        scanf("%d",&temp->data);
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            struct node *temp1=head;
            while(temp1->next!=NULL)
                temp1=temp1->next;
            temp1->next=temp;
        }
        printf("want to enter an another node(y/n): ");
        scanf(" %c",&ch);
    }
    end=head;
    while(end->next!=NULL)
        end=end->next;
    printf("initial linked list is: ");
    print();
    int i;
    struct node *prev=NULL;
    struct node *temp=head;
    for(i=0;i<count;i++)
    {
        if((temp->data)%2==0)
        {
            if(i==0)
            {
                head=temp->next;
                end->next=temp;
                end=temp;
            }
            else
            {
                prev->next=temp->next;
                end->next=temp;
                end=temp;
            }
        }
        if(i==0)
            prev=head;
        else
            if(temp->data%2!=0)
                prev=prev->next;
        struct node *temp1=temp->next;
        if(temp->data%2==0)
            temp->next=NULL;
        temp=temp1;
    }
    printf("\n");
    printf("Final Linked List is: ");
    print();
    printf("\n");
    return 0;
}
