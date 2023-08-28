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

int FindMaxWithoutRecursion(PNODE Head)  //Using Level Order Travel
{
	int iMax = 0;
	
	queue<PNODE> Q;
	
	if(Head == NULL)
	{
		return iMax;
	}
	
	Q.push(Head);
	
	while(!Q.empty())
	{
		Head = Q.front();
		
		Q.pop();
		
		if(iMax < Head -> data)
		{
			iMax = Head -> data;
		}
		
		if(Head -> left != NULL)
		{
			Q.push(Head -> left);
		}
		
		if(Head -> right != NULL)
		{
			Q.push(Head -> right);
		}
	}
	
	return iMax;
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
	
	cout<<endl<<"Find Maximum Without Recursion(Level Order Traversal)"<<endl;
	int iRet = FindMaxWithoutRecursion(First);
	cout<<"Maximum is : "<<iRet<<endl;

	return 0;
}