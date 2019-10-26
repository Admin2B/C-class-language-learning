#ifndef TREE_H
#define TREE_H

#include "Node.h"
class Tree
{
public:
	Tree();
	~Tree();
	Node *SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex,int direction,Node *pNode);
	bool DeleteNode(int nodeIndex,Node *pNode);
	void PreorderTraverse();     //Root-Left-Right   0526897
	void InorderTraverse();      //Left-Root-Right   2560987
	void PosorderTraverse();     //Left-Right-Root   2659780

/*
       0
	5     8
  2   6 9   7

*/
private:
	Node *m_pRoot;



};





#endif