#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}; 

struct Node *Init()
{
	struct Node *current,*prev;
    struct Node *head = NULL;
	current = (struct Node *)malloc(sizeof(struct Node));
	scanf("%d",&current->data);
	
	while (current->data != -1)
	{
		if (current->data % 2 == 0)
		{
			current = (struct Node *)malloc(sizeof(struct Node));
			scanf("%d",&current->data);
			continue;
		}
		if (head == NULL)
		{
			head = current;
		}
		else
		{
			prev->next = current;
		}
		prev = current;
		prev->next = NULL;
		
		current = (struct Node *)malloc(sizeof(struct Node));
		scanf("%d",&current->data);
	}
	return head;
}

void Print(struct Node *head)
{
	bool first = true;
	bool empty = true;
	struct Node *current = head;
	while (current != NULL)
	{
		first?printf("%d",current->data):printf(" %d",current->data);
		first  = false;
		empty = false;
		current = current->next;
	}
	if (!empty)
	{
		printf("\n");
	}
} 

void Free(struct Node *head)
{
	struct Node *current,*tmp;
	current = head;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

int main()
{
	struct Node *head = NULL;
	head = Init();
	Print(head);
	Free(head);
	return 0;
}
