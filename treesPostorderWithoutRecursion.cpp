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

void Postorder(PNODE Head)
{
	if(Head != NULL)
	{
		Postorder(Head -> left);
		Postorder(Head -> right);
		cout<<(Head -> data)<<" ";
	}
}

void PostorderNonRecursion(PNODE Head)
{
	stack<PNODE> S;
	PNODE prev = NULL;
	
	do
	{
		while(Head)
		{
			S.push(Head);
			Head = Head -> left;
		}
		
		while(Head == NULL && !S.empty())
		{
			Head = S.top();
			
			if(Head -> right == NULL || Head -> right == prev)
			{
				cout<<Head -> data<<" ";
				S.pop();
				prev = Head;
				Head = NULL;
			}
			else
			{
				Head = Head -> right;
			}
		}
		
	}while(!S.empty());
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

	cout<<"Postorder Rcursion"<<endl;
	Postorder(First);	
	cout<<endl<<endl<<"Postorder Non Recursive"<<endl;
	PostorderNonRecursion(First);

	return 0;
}