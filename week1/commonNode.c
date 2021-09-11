#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------------------
// The block of code between the two commented borders is where your solution goes.
typedef struct node node;

struct node{
	int data; // The data stored in this node of Linked list.
	int id; // The id of this node, which is used to uniquely determine this node in the array A.
	struct node *next; // Pointer to the next node in the Linked list.
};
node* findCommonList(node *head1, node *head2){
	if( head1==NULL || head2==NULL)//checking if any linked list is empty
		return NULL;

	node *temp1=head1;
	node *temp2=head2;

	int count1=0,count2=0,diff=0;
	//finding the length of the first linked list
	while(temp1)
	{
		count1++;
		temp1=temp1->next;
	}
	//finding the length of the second linked list
	while(temp2)
	{
		count2++;
		temp2=temp2->next;
	}

	temp1=head1;//reassigning temp1 to head1
	temp2=head2;//reassigning temp2 to head2
	/*comparing the lengths of the two linked lists and then placing the temp of the longer linked list (diff) positions ahead of its head so that both the temp
	variables finish traversing the linked lists at the same time */
	if(count1>=count2)
	{
		diff=count1-count2;
		for(int i=0;i<diff;i++)
			temp1=temp1->next;
	}
	else
	{
		diff=count2-count1;
		for(int i=0;i<diff;i++)
			temp2=temp2->next;
	}
	while(temp1->id!=temp2->id)//checking if the id of the temp variables is same while they are traversing through the linked list
	{
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return temp1;
}
//------------------------------------------------------------------------------------------

void printList(node *head){
	node *curr = head;
	int len = 0;
	while(curr!=NULL){
		len++;
		curr = curr->next;
	}
	curr = head;
	printf("%d ",len );
	while(curr!=NULL){
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	struct node **head1 = malloc(sizeof(struct node*));
	struct node **head2 = malloc(sizeof(struct node*));
	char tmp = 'a';
	int val;
	int t;
	scanf("%d\n", &t);
	int *a = malloc(sizeof(int)*t);
	int i = 0;
	do
	{
		scanf("%d%c", &val, &tmp);
		a[i++] = val;
	} while (i < t);
	struct node *curr = *head1;
	struct node *prev = NULL;
	do
	{
		scanf("%d%c", &val, &tmp);
		curr = malloc(sizeof(struct node));
		curr->id = val;
		curr->data = a[val-1];
		if(prev) prev->next = curr;
		else *head1 = curr;
		prev = curr;
		curr = curr->next;
	} while (tmp!='\n');
	curr = *head2;
	prev = NULL;
	do
	{
		scanf("%d%c", &val, &tmp);
		curr = malloc(sizeof(struct node));
		curr->id = val;
		curr->data = a[val-1];
		if(prev) prev->next = curr;
		else *head2 = curr;
		prev = curr;
		curr = curr->next;
	} while (tmp!='\n');
	node* commonNode = findCommonList(*head1, *head2);
	printList(commonNode);
	return 0;
}
