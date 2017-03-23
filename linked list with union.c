#include <stdio.h>
#include <stdlib.h>
struct student
{
    char stud_name[20];
    int roll_no;
};
struct teacher
{
    int tchr_id;
    char tchr_name[20];
    char mob_no[10];
};
union data
{
    struct student stud;
    struct teacher tchr;
};
struct node
{
    char ch;
    char id[10];
    union data new_data;
    struct node* next;
};
struct node* head=NULL;
void print()
{
    struct node *temp1=head;
    while(temp1!=NULL)
    {
        if(temp1->ch=='y')
        {
            printf("\nId: %s\n",temp1->id);
            printf("student name: %s\n",temp1->new_data.stud.stud_name);
            printf("student roll number: %d\n",temp1->new_data.stud.roll_no);
        }
        else if(temp1->ch=='n')
        {
            printf("\nId: %s\n",temp1->id);
            printf("teacher name: %s\n",temp1->new_data.tchr.tchr_name);
            printf("teacher Id: %d\n",temp1->new_data.tchr.tchr_id);
            printf("teacher mobile number: %s\n",temp1->new_data.tchr.mob_no);
        }
        temp1=temp1->next;
    }
}
int main()
{
    struct node *temp,*temp1,*swap;
    int n,i,j;
    char id[10];
    printf("enter number of nodes: ");
    scanf(" %d",&n);
    for(i=0;i<n;i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nNode %d: \nenter Id: ",i+1);
        scanf(" %s",temp->id);
        printf("whether student: ");
        scanf(" %c",&temp->ch);
        if(temp->ch=='y')
        {
            printf("enter student name: ");
            scanf(" %s",temp->new_data.stud.stud_name);
            fflush(stdin);
            printf("enter student roll number: ");
            scanf(" %d",&temp->new_data.stud.roll_no);
        }
        else if(temp->ch=='n')
        {
            printf("enter teacher name: ");
            scanf(" %s",temp->new_data.tchr.tchr_name);
            fflush(stdin);
            printf("enter teacher id: ");
            scanf(" %d",&temp->new_data.tchr.tchr_id);
            fflush(stdin);
            printf("enter mobile number: ");
            scanf(" %s",temp->new_data.tchr.mob_no);
        }
        temp->next=NULL;
        if(i==0)
            head=temp;
        else
        {
            temp1=head;
            while(temp1->next!=NULL)
                temp1=temp1->next;
            temp1->next=temp;
        }
    }
    print();
    printf("\nenter Id to search for: ");
    fflush(stdin);
    scanf("%s",id);
    fflush(stdin);
    while(strcmp("0",id)!=0)
    {
        temp=head;
        for(i=0;i<n;i++)
        {
            if(strcmp(temp->id,id)==0)
            {
                if(temp==head)
                {
                    print();
                    break;
                }
                temp1=head;
               for(j=0;j<i-1;j++)
                    temp1=temp1->next;//temp1 points to n-1 node
                swap=head;
                head=temp;
                temp1->next=temp->next;
                temp->next=swap;
                print();
                break;
            }
            temp=temp->next;
        }
        printf("\nenter Id to search for: ");
        fflush(stdin);
        scanf("%s",id);
    }
    return 0;
}
