#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[15];
    struct node *next;
};
struct node *head1=NULL,*head2=NULL;
void reverse(struct node *p)
{
    if(p->next==NULL)
    {
        head2=p;
        return;
    }
    reverse(p->next);
    struct node *q=p->next;
    q->next=p;
    p->next=NULL;
}
void print()
{
    printf("string in reverse oredr is:");
    struct node *temp=head2;
    while(temp!=NULL){
        printf(" %s ",temp->name);
        temp=temp->next;
    }
}
int main()
{
    struct node *temp1,*temp;
    char ch;
    do
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->next=NULL;
        printf("enter the name: ");
        scanf(" %s",temp->name);
        if(head1==NULL)
            head1=temp;
        else
        {
            temp1=head1;
            while(temp1->next!=NULL)
                temp1=temp1->next;
            temp1->next=temp;
        }
        printf("want to enter another node(y/n): ");
        scanf(" %c",&ch);
    }while(ch!='n');
    reverse(head1);
    print();
    printf("\n");
    return 0;
}
