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

int findNoOfFullNodesInBinaryTree(PNODE Head)
{
	int iFullNodesNo = 0;
	queue<PNODE> Q;
	
	if(Head == NULL)
	{
		return iFullNodesNo;
	}
	else
	{
		Q.push(Head);
		
		while(!Q.empty())
		{
			Head = Q.front();
			Q.pop();
			
			if(Head -> left != NULL && Head -> right != NULL)
			{
				iFullNodesNo++;
			}
			
			if(Head -> left)
			{
				Q.push(Head -> left);
			}
			if(Head -> right)
			{
				Q.push(Head -> right);
			}			
		}
	}
	
	return iFullNodesNo;
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
	
	int iRet = findNoOfFullNodesInBinaryTree(First);
	cout<<"No of Full Nodes In Binary Tree: "<<iRet<<endl;
	
	return 0;
}