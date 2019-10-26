#ifndef CMAP_H
#define CMAP_H
#include <vector>
#include <iostream>
#include <cstring>
#include "Node.h"
#include "Edge.h"
using namespace std;

class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);
	void resetNode();
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);


	void printMatrix();

	void depthFirstTraverse(int nodeIndex);
	void breadthFirstTraverse(int nodeIndex);

	void primTree(int nodeIndex);

private:
	bool getValueFromMatrix(int row, int col, int &val);
	bool breadthFirstTraverseImpl(vector<int> preVec);
	int getMinEdge(vector <Edge>edgeVec);
private:
	int m_iCapacity;
	int m_iNodeCount;
	Node *m_pNodeArray;
	int *m_pMatrix;

	Edge *m_pEdge;
};






#endif