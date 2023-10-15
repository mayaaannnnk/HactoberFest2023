#include <stdio.h>
#define max 5
int isfull(int front, int rear)
{
    if(rear==(max-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(int front,int rear)
{
    if(front>rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int enqueue(int queue[], int front, int rear)
{
    int x;
    x=isfull(front,rear);
    if(x)
    {
        printf("queue is full\n");
        return rear;
    }
    int a;
    printf("Enter the element: ");
    scanf("%d",&a);
    queue[++rear]=a;
    return rear;
}
int dequeue(int queue[], int front, int rear)
{
    int x;
    x=isempty(front,rear);
    if(x)
    {
        printf("queue is empty\n");
        return -1;
    }
    front++;
    return front;
}
void display(int queue[],int front,int rear)
{
    if(isempty(front,rear))
    {
        printf("queue is empty\n");
    }
    for(;front<=rear;front++)
    {
        printf("%d ",queue[front]);
    }
}
void frontv(int queue[],int front,int rear)
{
    if(isempty(front,rear))
    {
        printf("queue is empty\n");
    }
    printf("element at top: %d\n",queue[front]);
}
void rearv(int queue[],int front,int rear)
{
    if(isempty(front,rear))
    {
        printf("queue is empty\n");
    }
    printf("element at rear: %d\n",queue[rear]);
}
int main()
{
    int queue[max],front=-1,rear=-1,ch; char k;
    do
    {
        printf("1. enqueue\n2.dequeue\n3.display\n4.front\n5.rear\n6.isfull\n7.isempty\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :{
                        rear=enqueue(queue,front,rear);
                        if(rear!=-1  && front==-1);
                        {
                            front=0;
                        }
                        break;
                    }
            case 2 :{
                        front=dequeue(queue,front,rear);
                        break;
                    }
            case 3 :{
                        display(queue,front,rear);
                        break;
                    }
            case 4 :{
                        frontv(queue,front,rear);
                        
                        break;
                    }
            case 5 :{
                        rearv(queue,front,rear);
                        
                        break;
                    }   
            case 6 :{
                        int x;
                        x=isfull(front,rear);
                        if(x)
    {
        printf("queue is full\n");
    }
    else
    {
        printf("queue is not full\n");
    }
                        
                        break;
                    }   
            case 7 :{int x;
                        x=isempty(front,rear);
                        if(x)
                        {
                            printf("queue is empty\n");
                        }
                        else
                        {
                        printf("queue is not empty\n");
                        }
                        }
                        break;
                    }
        printf("Do you want to continue?");
        scanf(" %c",&k);
    }while(k=='y');
    return 0;
}