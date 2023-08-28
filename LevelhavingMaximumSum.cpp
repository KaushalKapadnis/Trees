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

int LevelHavingMaxSum(PNODE Head)
{
	int iLevel = 0;
	int iMaxSum = 0;
	int iSum = 0;
	int iMaxLevel = 0;
	
	queue<PNODE> Q;
	
	if(Head == NULL)
	{
		return iMaxLevel;
	}
	else
	{
		Q.push(Head);
		Q.push(NULL);
		
		iMaxSum = Head -> data; 
		
		while(!Q.empty())
		{
			Head = Q.front();
			Q.pop();
			
			if(Head == NULL)
			{
				if(!Q.empty())
					Q.push(NULL);
				
				iLevel++;
				
				if(iMaxSum <= iSum)
				{
					iMaxLevel = iLevel;
				}
				
				iSum = 0;
			}
			else
			{
				iSum += (Head -> data);
				
				if(Head -> left)
					Q.push(Head -> left);
				
				if(Head -> right)
					Q.push(Head -> right);
			}
		}
	}
	
	return iMaxLevel;
}

void LevelOrderTraversal(PNODE Head)
{
	queue<PNODE> Q;
	
	if(Head == NULL)
	{
		cout<<"No Elements"<<endl;
		return;
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
				Q.push(NULL);
			
			cout<<endl;
		}
		else
		{
			cout<<Head -> data<<" ";
		
			if(Head -> left != NULL)
			{
				Q.push(Head -> left);
			}
			
			if(Head -> right != NULL)
			{
				Q.push(Head -> right);
			}
		}
	}
}

int main()
{
	PNODE First = NULL;
	
	Insert(&First,418);
    Insert(&First,21);
	Insert(&First,31);
	Insert(&First,11);
    Insert(&First,71);
	Insert(&First,61);
	Insert(&First,81);
	
	cout<<"Level Order Traversal"<<endl;
	LevelOrderTraversal(First);
	
	int iRet = LevelHavingMaxSum(First);
	cout<<"Level With Max Sum is : "<<iRet<<endl;
	
	return 0;
}

