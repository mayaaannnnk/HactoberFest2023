#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertatbegin(struct node **head,int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Data not allocated");
        return;
    }
    temp->data=val;    
    if(*head==NULL)
    {
        *head=temp;
        temp->next=NULL;
        return;
    }   
    temp->next=*head; 
    *head=temp;
}
void insertatend(struct node **head,int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Data not allocated");
        return;
    }
    temp->data=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
        return;
    }

    struct node *itr=*head;
    while(itr->next!=NULL)
    {
        itr=itr->next;
    }
    itr->next=temp;
    temp->next=NULL;
}
void insertafterk(struct node **head,int val,int k)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Data not allocated");
        return;
    }
    temp->data=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
        return;
    }
    struct node *itr=*head;
    while(itr!=NULL && itr->data!=k)
    {
        itr=itr->next;
    }
    temp->next=itr->next;
    itr->next=temp;
}
void insertbeforek(struct node **head,int val,int k)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Data not allocated");
        return;
    }
    temp->data=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
        return;
    }
    if((*head)->data==k)
    {
        temp->next=*head;
        *head=temp;
        return;
    }
    struct node *itr=*head;
    while(itr->next!=NULL && itr->next->data!=k)
    {
        itr=itr->next;
    }
    if(itr->next==NULL)
    {
        printf("Element not found");
        return;
    }
    temp->next=itr->next;
    itr->next=temp;
}
void deleteatbegin(struct node **head)
{
    if(!(*head))
    {
        return;
    }
    struct node *temp=*head;
    *head=(*head)->next;
    free(temp);
}
void deleteatend(struct node **head)
{
    struct node *itr=*head,*temp;
    if(*head==NULL)
    {
        return;
    }
    if((*head)->next==NULL)
    {
        temp=*head;
        *head=NULL;
        free(temp);
    }
        while(itr->next->next!=NULL)
        {
            itr=itr->next;
        }
        temp=itr->next;
        itr->next=NULL;
        free(temp);
}
void deletek(struct node **head,int k)
{
    struct node *itr=*head,*temp=NULL;
    if(!(*head))
    {
        return;
    }
    if(itr->data==k)
    {
        *head=(*head)->next;
        free(itr);
        return;
    }
    while(itr->next!=NULL && itr->next->data!=k)
    {
        itr=itr->next;
    }
    if(itr->next)
    {
        temp=itr->next;
        itr->next=temp->next;
        free(temp);
    }
}
void display(struct node **head)
{
    if(!(*head))
    {
        printf("list is empty");
        return;
    }
    struct node *itr=*head;
    do
    {        
        printf("%d ",itr->data);
        itr=itr->next;
    } while (itr!=NULL);
    return;
}
int main()
{
    struct node *head=NULL;
    int a,val,k;
    char c;
    do
    {
        printf("1. insert at beginning\n2. insert at end\n3. insert after k\n4. insert before k\n5. delete from beginning\n6. delete from end\n7. delete a node of value k\n8. display\nEnter your choice: ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            {
                printf("Enter the value to insert: ");
                scanf("%d",&val);
                insertatbegin(&head,val);
                break;
            }
            case 2:
            {
                printf("Enter the value to insert: ");
                scanf("%d",&val);
                insertatend(&head,val);
                break;
            }
            case 3:
            {
                printf("Enter the value to insert: ");
                scanf("%d",&val);
                printf("Enter the value after to insert: ");
                scanf("%d",&k);
                insertafterk(&head,val,k);
                break;
            }
            case 4:
            {
                printf("Enter the value to insert: ");
                scanf("%d",&val);
                printf("Enter the value before to insert: ");
                scanf("%d",&k);
                insertbeforek(&head,val,k);
                break;
            }
            case 5:
            {
                deleteatbegin(&head);
                break;
            }
            case 6:
            {
                deleteatend(&head);
                break;
            }
            case 7:
            {
                printf("Enter the value to delete: ");
                scanf("%d",&k);
                deletek(&head,k);
                break;
            }
            case 8:
            {
                display(&head);
                printf("\n");                
                break;
            }
            default:
            {
                printf("invalid choice!!\n");
            }
        }
        printf("Do you want to continue?(y/n)\n");
        scanf(" %c",&c);
    } while (c=='y');
    return 0;
}