#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	
}NODE, *PNODE, **PPNODE;

void InsertTreewithLevelOrder(PPNODE Head,int data)
{
	queue<PNODE> Q;
	PNODE newn = new(NODE);
	PNODE temp = *Head;
	
	newn -> left = NULL;
	newn -> right = NULL;
	newn -> data = data;
	
	if((*Head) == NULL)
	{
		*Head = newn;
	}
	else
	{
		Q.push(temp);
		
		while(!Q.empty())
		{
			temp = Q.front();
			Q.pop();
			
			if(temp -> left)
			{	
				Q.push(temp -> left);
			}
			else
			{
				temp -> left = newn;
				break;
			}

			if(temp -> right == NULL)
			{
				temp -> right = newn;
				break;
			}
			else
			{
				Q.push(temp -> right);
			}
		}
	}
}

int treeSize(PNODE Head)
{
	int iCount = 0;
	
	queue<PNODE> Q;
	
	if(Head == NULL)
	{
		return iCount;
	}
	
	Q.push(Head);
	
	while(!Q.empty())
	{
		Head = Q.front();
		
		Q.pop();
		
		iCount++;
		
		if(Head -> left != NULL)
		{
			Q.push(Head -> left);
		}
		
		if(Head -> right != NULL)
		{
			Q.push(Head -> right);
		}
	}
	
	return iCount;
	
}

int main()
{
	PNODE First = NULL;
	
	InsertTreewithLevelOrder(&First,1);
    InsertTreewithLevelOrder(&First,2);
	InsertTreewithLevelOrder(&First,3);
	InsertTreewithLevelOrder(&First,4);
    InsertTreewithLevelOrder(&First,5);
	InsertTreewithLevelOrder(&First,6);
	InsertTreewithLevelOrder(&First,7);
	
	int iRet = treeSize(First);
	cout<<"Size of Tree is With Level Order Traversal "<<iRet<<endl;
	
	return 0;
}