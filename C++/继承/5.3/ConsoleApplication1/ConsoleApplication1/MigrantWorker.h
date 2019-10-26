#include"Worker.h"
#include"Farmer.h"
#include<string>



class MigrantWorker:public Worker,public Farmer
{
public:
	MigrantWorker(string name,string code);
	~MigrantWorker();
};