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

bool checkStructurallyIdentical(PNODE Head, PNODE Head1)
{
	if(Head == NULL && Head1 == NULL)
	{
		return true;
	}
	
	if((Head == NULL || Head1 == NULL))
	{
		return false;
	}
	
	return(checkStructurallyIdentical(Head -> left, Head1 -> left) && checkStructurallyIdentical(Head -> right, Head1 -> right));
} 

int main()
{
	PNODE First = NULL;
	PNODE First1 = NULL;
	
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
	
	InsertTreewithLevelOrder(&First1,1);
    InsertTreewithLevelOrder(&First1,2);
	InsertTreewithLevelOrder(&First1,3);
	InsertTreewithLevelOrder(&First1,4);
    InsertTreewithLevelOrder(&First1,5);
	InsertTreewithLevelOrder(&First1,6);
	InsertTreewithLevelOrder(&First1,7);	
	InsertTreewithLevelOrder(&First1,8);	
	InsertTreewithLevelOrder(&First1,9);	
	InsertTreewithLevelOrder(&First1,10);	
	InsertTreewithLevelOrder(&First1,11);	
	InsertTreewithLevelOrder(&First1,12);	
	InsertTreewithLevelOrder(&First1,13);	
	InsertTreewithLevelOrder(&First1,14);	
	InsertTreewithLevelOrder(&First1,15);	
	InsertTreewithLevelOrder(&First1,16);
	
	bool bRet = checkStructurallyIdentical(First, First1);
	
	if(bRet == false)
	{
		cout<<"Structurally Not Identical"<<endl;
	}
	else
	{
		cout<<"Structurally Identical"<<endl;
	}
	
	return 0;
}