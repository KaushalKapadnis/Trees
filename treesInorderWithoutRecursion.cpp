#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE Head,int data)
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
		if(temp -> data > data)
		{
			if(temp -> left == NULL)
			{
				temp -> left = newn;
				return;
			}
			temp = temp -> left;
			Insert(&temp, data);
		}
		else if(temp -> data < data)
		{
			if(temp -> right == NULL)
			{
				temp -> right = newn;
				return;
			}
			temp = temp -> right;
			Insert(&temp,data);
		}
		else if(temp -> data == data)
		{
			delete(newn);
			cout<<"Data already present"<<endl;
		}
	}
}

void Inorder(PNODE Head)
{
	if(Head != NULL)
	{
		Inorder(Head -> left);
		cout<<(Head -> data)<<" ";
		Inorder(Head -> right);
	}
}

void InorderNonRecursion(PNODE Head)
{
	stack<PNODE> S;
	
	while(1)
	{
		while(Head)
		{
			S.push(Head);
			Head = Head -> left;
		}
		
		if(S.empty())
		{
			break;
		}
		
		Head = S.top();
		cout<<Head -> data<<" ";
		S.pop();
		
		Head = Head -> right;
	}
}

int main()
{
	PNODE First = NULL;
	
	Insert(&First,51);
    Insert(&First,21);
	Insert(&First,31);
	Insert(&First,11);
    Insert(&First,71);
	Insert(&First,61);
	Insert(&First,81);

	cout<<"Inorder Rcursion"<<endl;
    Inorder(First);
	cout<<endl<<endl<<"Inorder Non Recursive"<<endl;
	InorderNonRecursion(First);
	
	return 0;
}