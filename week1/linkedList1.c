#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;//to store the value
    struct node *next;//to store the address of the next node
};


struct node *insert(struct node *head)
{
    int k,v;
    scanf("%d %d",&k,&v);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));//creating a new node
    newnode->data=v;
  
    if(head==NULL)//for creating the first node 
    {
        
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
    struct node *temp=head;
    if(k==0)//edge case when position to insert node is 0
    {
        head=newnode;
        newnode->next=temp;
    }
    else
    {
        for(int i=0;i<k-1;i++)
        {
            temp=temp->next;
        }
        
        newnode->next=temp->next;
        temp->next=newnode;
        }
    }
    return head;
}

struct node *delete(struct node *head)
{
    int k;
    scanf("%d",&k);
    struct node *temp=head;
    if(head==NULL)
        return head;
    else
    {
        if(k==0)//edge case when position to delete node is 0
        {
            head=temp->next;
            free(temp);
        }
            
        else
        {
            for(int i=0;i<k-1;i++)
            {
                temp=temp->next;
            }
            
            struct node *tofree=temp->next;//storing the address of the node to be deleted
            temp->next=temp->next->next;
            free(tofree);
        }

            return head;
    }
}

struct node *update(struct node *head)
{
    int k,v;
    scanf("%d %d",&k,&v);
    struct node *temp=head;
    for(int i=0;i<k;i++)
    {
        temp=temp->next;
    }
    temp->data=v;
    
    return head;
}

void max(struct node *head)
{
    int max=head->data;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data>max)
            max=temp->data;
        temp=temp->next;
    }
    printf("%d\n",max);

}

int main()
{
    struct node *head=NULL;
    int size;
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        int query; 
        scanf("%d",&query);
        if(query==1)
        {
            head=insert(head);

        }
        else if(query==2)
        {
            head=delete(head);
        }
        else if(query==3)
            head=update(head);

        else if(query==4)
            max(head);
    }
    return 0;

}

