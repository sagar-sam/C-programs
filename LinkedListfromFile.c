#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};
struct node *head;

void print()
{
    printf("the current elements in the list are\n");
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->number);
        temp=temp->next;
    }
    printf("\n");
}
void create_linked_list()
{
    char ch;
    do
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->next=NULL;
        printf("Enter the number: ");
        scanf("%d",&temp->number);
        if(head==NULL)
            head=temp;
        else
        {
            struct node *temp1=head;
            while(temp1->next!=NULL)
                temp1=temp1->next;
            temp1->next=temp;
        }

        printf("want to enter an another node(y/n): ");
        scanf(" %c",&ch);
    }while(ch!='n');
    print();
}
void insert(int pos,int number)
{
    int i;
    struct node *temp=head;
    struct node *temp1=(struct node*)malloc(sizeof(struct node));
    temp1->next=NULL;
    temp1->number=number;
    for(i=0;i<pos-2;i++)
        temp=temp->next;
    temp1->next=temp->next;
    temp->next=temp1;
    print();
}

void delete_node(int pos)
{
    int i;
    struct node *temp=head;
    for(i=0;i<pos-2;i++)
        temp=temp->next;
    temp->next=temp->next->next;
    print();

}



int main()
{
    create_linked_list();
    FILE *fp;
    int number,pos;
    char ch;
    fp=fopen("input.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%c ",&ch);
        if(ch=='i')
        {
            fscanf(fp,"%d %d\n",&pos,&number);
            insert(pos,number);

        }
        else if(ch=='d')
        {
            fscanf(fp,"%d",&pos);
            delete_node(pos);
        }

    }
    return 0;
}
