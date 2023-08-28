#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE, *PNODE, **PPNODE;

void InsertTreewithLevelOrder(PPNODE Head, int data)
{
	PNODE temp = *Head;
	PNODE newn = new(NODE);
	
	newn -> data = data;
	newn -> left = NULL;
	newn -> right = NULL;
	
	queue<PNODE> Q;
	
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
			
			if(temp -> left != NULL)
			{
				Q.push(temp -> left);
			}
			else
			{
				temp -> left = newn;
				break;
			}
			
			if(temp -> right != NULL)
			{
				Q.push(temp -> right);
			}
			else
			{
				temp  -> right = newn;
				break;
			}
		}
	}
}

void Delete(PNODE Head, int data)
{
	queue<PNODE> Q;
	PNODE prev = NULL;
	PNODE temp = NULL;
	
	if(Head == NULL)
	{
		return;
	}
	else
	{
		while(1)
		{
			Head
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
	InsertTreewithLevelOrder(&First,8);	
	InsertTreewithLevelOrder(&First,9);	
	InsertTreewithLevelOrder(&First,10);	
	InsertTreewithLevelOrder(&First,11);	
	InsertTreewithLevelOrder(&First,12);	
	InsertTreewithLevelOrder(&First,13);	
	InsertTreewithLevelOrder(&First,14);	
	InsertTreewithLevelOrder(&First,15);	
	//InsertTreewithLevelOrder(&First  ,16);
	
	int iRet = treeSize(First);
	cout<<"Size : "<<iRet<<endl;
	
	Delete(First,16);
	
	cout<<"Here";
	iRet = treeSize(First);
	cout<<"Size : "<<iRet<<endl;
	
	return 0;
}