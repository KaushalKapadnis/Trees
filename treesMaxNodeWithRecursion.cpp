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

int findMax(PNODE temp)
{
	int iRoot = 0, iLeft = 0, iRight = 0, iMax = 0;
	
	if(temp)
	{
		iRoot = temp -> data;
		
		iLeft = findMax(temp -> left);
		iRight = findMax(temp -> right);
		
		if(iLeft < iRight)
		{
			iMax = iRight;
		}
		else
		{
			iMax = iLeft;
		}
		
		if(iMax < iRoot)
		{
			iMax = iRoot;
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
	
	cout<<endl<<endl<<"Find Maximum With Recursion";
	int iRet = findMax(First);
	cout<<endl<<"Maximum is : "<<iRet<<endl;

	return 0;
}