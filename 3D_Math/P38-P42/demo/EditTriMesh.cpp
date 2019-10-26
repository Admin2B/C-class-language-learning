#include "pch.h"
#include"EditTriMesh.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>

using namespace std;
void EditTriMesh::Vertex::setDefaults()
{
	memset(this, 0, sizeof(this));
}

void EditTriMesh::Tri::setDefaults()
{
	memset(this, 0, sizeof(this));
}

EditTriMesh::EditTriMesh()
{
	empty();
}

EditTriMesh::~EditTriMesh()
{
	construct();
}

void EditTriMesh::construct()
{
	vAlloc = 0;
	vCount = 0;
	vList = NULL;
	tAlloc = 0;
	tCount = 0;
	tList = NULL;
}

void EditTriMesh::empty()
{
	if (vList != NULL)
	{
		::free(vList);
		vList = NULL;
	}
	vAlloc = 0;
	vCount = 0;

	if (tList != NULL)
	{
		::free(tList);
		tList = NULL;
	}
	tAlloc = 0;
	tCount = 0;

}

int EditTriMesh::addTri()
{
	int r = tCount;
	if (tCount >= tAlloc)
	{
		setTriCount(tCount+1);
	}
	else
	{
		++tCount;
		tList[r].setDefaults();
	}
	return r;
}


int EditTriMesh::addTri(const Tri &t)
{
	int r = tCount;
	if (tCount >= tAlloc)
	{
		setTriCount(tCount + 1);
	}
	else
	{
		++tCount;
	}
	tList[r] = t;
	return r;
}

void EditTriMesh::setTriCount(int tc)
{
	assert(tc >= 0);
	assert(tCount <= tAlloc);
	if (tc > tCount)
	{
		if (tc > tAlloc)
		{
			tAlloc = tc * 4 / 3+10;
			tList = (Tri*)::realloc(tList, tAlloc * sizeof(*tList));
			if (tList == NULL)
			{
				cout << "Out of Memory" << endl;
				return;
			}
		}
		while (tCount < tc)
		{
			tList[tCount].setDefaults();
			++tCount;
		}
	}
	else
	{
		tCount = tc;
	}
}

int EditTriMesh::addVertex()
{
	int r = vCount;
	if (vCount >= vAlloc)
	{
		setVertexCount(vCount + 1);
	}
	else
	{
		++vCount;
		vList[r].setDefaults();
	}
	return r;
}




int EditTriMesh::addVertex(const Vertex &v)
{
	int r = vCount;
	if (vCount >= vAlloc)
	{
		setVertexCount(vCount + 1);
	}
	else
	{
		++vCount;
	}
	vList[r] = v;
	return r;
}

void EditTriMesh::setVertexCount(int vc)
{
	assert(vc >= 0);
	assert(vCount <= vAlloc);
	if (vc > vCount)
	{
		if (vc > vAlloc)
		{
			vAlloc = vc * 4 / 3 + 10;
			vList = (Vertex*)::realloc(vList, vAlloc * sizeof(*vList));
			if (vList == NULL)
			{
				cout << "Out of Memory" << endl;
				return;
			}
		}
		while (vCount < vc)
		{
			vList[vCount].setDefaults();
			++vCount;
		}
	}
	else
	{
		vCount = vc;
	}
}

EditTriMesh::Vertex &EditTriMesh::vertex(int vertexIndex)
{
	assert(vertexIndex >= 0);
	assert(vertexIndex < vCount);
	return vList[vertexIndex];
}

const EditTriMesh::Vertex &EditTriMesh::vertex(int vertexIndex) const
{
	assert(vertexIndex >= 0);
	assert(vertexIndex < vCount);
	return vList[vertexIndex];
}



void EditTriMesh::computeOneTriNormal(Tri &t)
{
	const Vector3 &v1 = vertex(t.v[0].index).p;
	const Vector3 &v2 = vertex(t.v[1].index).p;
	const Vector3 &v3 = vertex(t.v[2].index).p;
	Vector3 e1 = v3 - v2;
	Vector3 e2 = v1 - v3;

	t.normal=crossProduct(e1, e2);
	t.normal.normalize();
}


EditTriMesh::Tri &EditTriMesh::tri(int triIndex)
{
	assert(triIndex >= 0);
	assert(triIndex < tCount);
	return tList[triIndex];
}

const EditTriMesh::Tri &EditTriMesh::tri(int triIndex)const
{
	assert(triIndex >= 0);
	assert(triIndex < tCount);
	return tList[triIndex];
}


void EditTriMesh::computeOneTriNormal(int triIndex)
{
	computeOneTriNormal(tri(triIndex));
}

void  EditTriMesh::computeTriNormals()
{
	for (int i = 0; i < triCount(); ++i)
	{
		computeOneTriNormal(tri(i));
	}
}

void EditTriMesh::computeVertexNormals()
{
	int i;
	computeTriNormals();
	for (i = 0; i < vertexCount(); ++i)
	{
		vertex(i).normal.zero();
	}

	for (i = 0; i < triCount(); ++i)
	{
		const Tri *t = &tri(i);
		for (int j = 0; j < 3; ++j)
		{
			vertex(t->v[j].index).normal += t->normal;
		}
	}

	for (i = 0; i < vertexCount(); ++i)
	{
		vertex(i).normal.normalize();
	}

}

void EditTriMesh::detachAllFaces()
{
	if (triCount() < 1)
	{
		return;
	}
	int newVertexCount = triCount() * 3;
	Vertex *newVertexList = (Vertex*)::malloc(newVertexCount * sizeof(Vertex));
	if (newVertexList == NULL)
	{
		cout << "Out of Memory" << endl;
		return;
	}
	for (int i = 0; i < triCount(); ++i)
	{
		Tri *t = &tri(i);
		for (int j = 0; j < 3; ++j)
		{
			int sIndex = t->v[j].index;
			int dIndex = i * 3 + j;
			Vertex *dPtr = &newVertexList[dIndex];
			*dPtr = vertex(sIndex);
			dPtr->u = t->v[i].u;
			dPtr->v = t->v[i].v;
			dPtr->normal = t->normal;
			t->v[i].index = dIndex;
		}
	}

	::free(vList);
	vList = newVertexList;
	vCount = newVertexCount;
	vAlloc = newVertexCount;
}