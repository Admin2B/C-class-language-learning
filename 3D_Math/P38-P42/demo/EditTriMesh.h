#ifndef EDITTRIMESH_H
#define EDITTRIMESH_H

#include  "Vector3.h"


class EditTriMesh
{
public:
	class Vertex
	{
	public:
		Vertex()
		{
			setDefaults();
		}
		void setDefaults();
		Vector3 p;

		float u, v;
		Vector3 normal;

	};
	class Tri
	{
	public:
		Tri()
		{
			setDefaults();
		}
		void setDefaults();
		struct Vert
		{
			int index;
			float u, v;
		};
		Vert v[3];
		Vector3 normal;


	};
	EditTriMesh();
	~EditTriMesh();

	Vertex &vertex(int vertexIndex);
	const Vertex &vertex(int vertexIndex)const;
	Tri &tri(int triIndex);
	const Tri &tri(int triIndex)const;

	int triCount()const
	{
		return tCount;
	}

	int vertexCount() const
	{
		return vCount;
	}

	void empty();
	void setTriCount(int tc);
	void setVertexCount(int vc);
	int addTri();
	int addTri(const Tri &t);

	int addVertex();
	int addVertex(const Vertex &v);

	void detachAllFaces();



	void computeOneTriNormal(Tri &t);
	void computeOneTriNormal(int triIndex);
	void computeTriNormals();
	void computeVertexNormals();


private:
	int vAlloc;
	int vCount;
	Vertex *vList;
	int tAlloc;
	int tCount;
	Tri *tList;
	void construct();
	
};


#endif