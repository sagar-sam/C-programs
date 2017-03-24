#include <stdio.h>
#include <stdlib.h>
//the implementation of stack on linked list can not be done on the end of linked list as bcz it can not be accessed on the unit time bt it is a dependent on
//the number of inputs
//so the implementation of stack will be done on head node on the linked list
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void push(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=x;
    temp->next=head;
    head=temp;
}
void pop()//deleting the element at the top
{
    if(head==NULL)
    {
        printf("no element exists");
        return;
    }
    struct node *temp=head;
    head=head->next;
    free(temp);
}
void print()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("   %d   ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    char ch;
    do
    {
        printf("Enter 'i' for a push and 'd' for a pop and n to exit: ");
        scanf(" %c",&ch);
        if(ch=='i')
        {
            printf("insert the data");
            int n;
            scanf("%d",&n);
            push(n);
        }
        else if(ch=='d')
            pop();
	printf("The current Stack is: \n");
        print();
	printf("\n");
    }while(ch!='n');
    return 0;
}
