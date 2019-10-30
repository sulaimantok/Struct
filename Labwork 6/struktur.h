#include "stdio.h"
#include "string.h"
#include "iostream"

#define max 10
struct Stack
{
	int count;
	int data[max];
};

struct  Queue
{
	int count;
	int head;
	int tail;
	int data[max];
};

class Stack{
private:
	Stack* S;
public:
	~Stack();
	void Initialize(Stack* S);
	int IsFull(Stack* S);
	int IsEmpty(Stack* S);
	void Push(int x,Stack* S);
	void Pop(Stack* S);
}
class Queue{
private:
	Queue* Q,head,tail,count;
public:
	~Queue();
	void Initialize(Queue* Q);
	int IsFull(Queue* Q);
	int IsEmpty(Queue* Q);
	void Enqueue(int a,Queue* Q);
	void Dequeue(int a,Queue* Q);
}