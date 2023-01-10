#include<stdio.h>
#include<stdlib.h>
//making structure for node
struct node{
	int info;
	struct node *prev;
	struct  node *next;
	
};
struct node *head=NULL;
struct node *ptr=NULL;
struct node *newnode=NULL;
//function for insertion 
int Insert_Beginning()
{
	 int data;
     newnode=(struct node*)malloc(sizeof(struct node));
	 printf("\nenter the data you want to enter\n ");
	 scanf("%d",&data);
	 newnode->info=data;
	 newnode->prev=NULL;
	 newnode->next=NULL;
	 if(head==NULL)
	 {
	 	head=newnode;
	 	return 0;
	 
     }	
     else{
     	newnode->next=head;
     	head->prev=newnode;
     	head=newnode;
     	return 0;
	 }
	 
}
int Insert_End()
{
	int data;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data\n");
	scanf("%d",&data);
	newnode->info=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(head=NULL)
	{
		head=newnode;
	}
	else{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->prev=ptr;
	}
}
int Insert_Specified()
{
	int data,i,pos;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data you\n");
	scanf("%d",&data);
	newnode->prev=NULL;
	newnode->next=NULL;
	printf("\nenter the position where you want to input the data \n");
	scanf("%d",&pos);
	ptr=head;
	for(i-0;i<=pos-1;i++)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("position not forund");
		}
		
	}
	newnode->next=ptr->next;
	newnode->prev=ptr;
	ptr->next->prev=newnode;
	
}
//deletion function
int Deletion_Beginning()
{
	if(head==NULL)
	{
		printf("\nthe list is empty\n");
		exit(0);
	}
	ptr=head;
	head=head->next;
	head->next=NULL;
	free(ptr);
}
int Deletion_End()
{
	if(head==NULL)
	{
		printf("\nthe list is empty\n");
		exit(0);
	}
	else if(head->next=NULL)
	{
		ptr=head;
		head=NULL;
		printf("\nthe deleted item is%d",ptr->info);
		free(ptr);
	}
	else
	{
		ptr=head;
		while(ptr->next=NULL)
		{
			ptr=ptr->next;
		}
		ptr->prev->next=NULL;
		printf("\nthe deleted item is %d",ptr->info);
		free(ptr);
	}
}
int Deletion_Specified()
{
	int pos,i;
	printf("\nenter the position to be deleted\n");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("\nthe list is empty\n");
		exit(0);
	}
	else if(pos==0)
	{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		printf("the deleted item is %d",ptr->info);
		free(ptr);
	}
	else
	{
		ptr=head;
		for(i=0;i<=pos-1;i++)
		{
			ptr=ptr->next;
			if(ptr->next=NULL)
			{
				printf("position not found");
			}
		}
	}
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
	free(ptr);
}
Display()
{
	return 0;
}

int main()
{
	int choice;
	printf("1.insert at beginning\n2.insert at end\n3.insert at specified\n4.deletion at beginning\n5.deletion at end\n6.deletion at specified\n7.display\n8.exit");
	
	while(1)
	{
		printf("\nenter your choice\n");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Insert_Beginning();
				break;
				case 2:
					Insert_End();
					break;
					case 3:
						Insert_Specified();
						break;
						case 4:
							Deletion_Beginning();
							break;
							case 5:
								Deletion_End();
								break;
								case 6:
									Deletion_Specified();
									break;
									case 7:
										Display();
										break;
										case 8:
											exit(0);
											default:
												printf("\nchoice is incorrect enter another choice\n");
												break;
		}
	}
}

