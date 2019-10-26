#ifndef MYQUEUE_H
#define MYQUEUE_H



#include "Customer.h"
class MyQueue
{
public:
	MyQueue(int queueCapacity);
	virtual ~MyQueue();
	void ClearQueue();
	bool QueueEmpty() const;
	int QueueLength() const;
	bool QueueFull() const;
	bool EnQueue(Customer element);
	bool DeQueue(Customer &element);
	void QueueTraverse();
private:
	Customer *m_pQueue;
	int m_iQueueLen;
	int m_iQueueCapacity;
	int m_iHead;
	int m_iTail;

};


#endif