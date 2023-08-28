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

bool findElementWithoutRecursion(PNODE Head, int data)
{
	bool bRet = false;
	queue<PNODE> Q;
	
	if(Head == NULL)
	{
		return false;
	}
	
	Q.push(Head);
	
	while(!Q.empty())
	{
		Head = Q.front();
		Q.pop();
		
		if(Head -> data == data)
		{
			bRet = true;
			break;
		}
		if(Head -> left != NULL)
			Q.push(Head -> left);
		
		if(Head -> right != NULL)
			Q.push(Head -> right);
	}
	
	return bRet;
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
	
	bool bRet = findElementWithoutRecursion(First, 91);
	if(bRet == true)
	{
		cout<<"Element Found"<<endl;
	}
	else
	{
		cout<<"Element Not Found"<<endl;
	}
	
	
	return 0;
}