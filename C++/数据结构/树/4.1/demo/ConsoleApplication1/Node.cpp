#include "pch.h"
#include "Node.h"
#include <iostream>
using namespace std;


Node::Node()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}

Node *Node::SearchNode(int nodeIndex)
{
	if (this->index == nodeIndex)
	{
		return this;
	}

	Node *temp = NULL;
	if (this->pLChild != NULL)
	{
		if (this->pLChild->index == nodeIndex)
		{
			return this->pLChild;
		}

		else
		{
			temp = this->pLChild->SearchNode(nodeIndex);
			if (temp != NULL)
			{
				return temp;
			}

		}
	}
	

	if (this->pRChild != NULL)
	{
		if (this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
		else
		{
			temp = this->pRChild->SearchNode(nodeIndex);
			return temp;
		}

	}
	return NULL;

}

void Node::DeleteNode()
{
	if (this->pLChild != NULL)
		this->pLChild->DeleteNode();
	if (this->pRChild != NULL)
		this->pRChild->DeleteNode();
	if (this->pParent != NULL)
	{
		if (this->pParent->pLChild == this)
		{
			this->pParent->pLChild = NULL;
		}
			
		if (this->pParent->pRChild == this)
		{
			this->pParent->pRChild = NULL;
		}		
	}
	delete this;
}

void Node::PreorderTraverse()
{
	cout << this->index << "  " << this->data << endl;

	if (this->pLChild != NULL)
		this->pLChild->PreorderTraverse();

	if (this->pRChild != NULL)
		this->pRChild->PreorderTraverse();
}

void Node::InorderTraverse()
{
	
	if (this->pLChild != NULL)
		this->pLChild->InorderTraverse();

	cout << this->index << "  " << this->data << endl;

	if (this->pRChild != NULL)
		this->pRChild->InorderTraverse();
}

void Node::PosorderTraverse()
{
	if (this->pLChild != NULL)
		this->pLChild->PosorderTraverse();
	
	if (this->pRChild != NULL)
		this->pRChild->PosorderTraverse();

	cout << this->index << "  " << this->data << endl;

}