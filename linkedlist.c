#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void print(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int n,i,x;
    struct node* head;
    head=NULL;
    struct node *temp,*temp1;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    head=temp;
    for(i=1;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&temp->data);
        temp->next=NULL;
        temp1=head;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        temp1->next=temp;
    }
    print(head);
    return 0;
}
