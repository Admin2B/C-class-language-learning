class Array
{
public:
	Array(int len);
	~Array();
	void setLen(int len);
	int getLen();
	void printInfo();
private:
	int len;
};