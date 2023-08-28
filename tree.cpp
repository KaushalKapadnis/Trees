////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  BINARY TREE	
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>

using namespace std;


typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE Head, int data)
{
	PNODE temp = *Head;
	PNODE newn = new(NODE);
	
	newn -> data = data;
	newn -> left = NULL;
	newn -> right = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(1)
		{
			if(data < temp -> data)
			{
				if(temp -> left == NULL)
				{
					temp -> left = newn;
					break;
				}
				temp = temp -> left;
			}
			else if(data > temp -> data)
			{
				if(temp -> right == NULL)
				{
					temp -> right = newn;
					break;
				}
				temp = temp -> right;
			}
			else if(data == temp -> data)
			{
				delete(newn);
				cout<<"Duplicate Entry"<<endl;
				break;
			}
		}
	}
}

void Inorder(PNODE Head)
{
	if(Head != NULL)
	{
		Inorder(Head -> left);
		cout<<Head -> data<<endl;
		Inorder(Head -> right);
	}
}

void preorder(PNODE Head)
{
	if(Head != NULL)
	{
		cout<<Head -> data<<endl;
		Inorder(Head -> left);
		Inorder(Head -> right);
	}
}

void postorder(PNODE Head)
{
	if(Head != NULL)
	{
		Inorder(Head -> left);
		Inorder(Head -> right);
		cout<<Head -> data<<endl;
	}
	
	cout<<"NULL  ";
}

int main()
{
	cout<<"Here"<<endl;
	
	PNODE Head = NULL;
	
	Insert(&Head,7);
	Insert(&Head,5);
	Insert(&Head,6);
	Insert(&Head,4);

	Inorder(Head);
	
	Delete(&Head,4);
	
	cout<<"Here2"<<endl;

	Inorder(Head);
	
	return 0;
}