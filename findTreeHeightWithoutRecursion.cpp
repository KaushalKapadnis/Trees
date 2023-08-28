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

int FindHeightTree(PNODE Head)
{
	int iHeight = 0;
	queue<PNODE> Q;
	
	if(Head == NULL)
	{
		return iHeight;
	}
	
	Q.push(Head);
	Q.push(NULL);
	
	while(!Q.empty())
	{
		Head = Q.front();
		Q.pop();
		
		if(Head == NULL)
		{
			if(!Q.empty())
			{
				Q.push(NULL);
			}
			
			iHeight++;
		}
		else
		{
			if(Head -> left != NULL)
			{
				Q.push(Head -> left);
			}
			
			if(Head -> right!= NULL)
			{
				Q.push(Head -> right);
			}
		}
	}
	
	return iHeight;
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
	InsertTreewithLevelOrder(&First,16);
	
	int iRet = FindHeightTree(First);
	cout<<"Height of tree is : "<<iRet<<endl;
	
	return 0;
}