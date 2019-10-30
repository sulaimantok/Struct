#include "struktur.h"


Queue::~Queue(){

}
void Queue::Initialize(Queue* Q){
	Q->count = 0;
	Q->head = 0;
	Q->tail = 0;
}

void Queue::IsFull(Queue* Q){
	return (Q->count == max)? 1:0;
}

void Queue::IsEmpty(Queue* Q){
	return (Q->count == 0)? 1:0;
}

void Queue::Enqueue(int a,Queue* Q){
	if(IsFull() == 1)
		cout<< "Maaf queue penuh"<<endl;
	else{
		Q->data[Q->tail]=x;
		Q->tail = (Q->tail+1)%max;
		++ Q->count;
	}
}

void Queue::Dequeue(int a,Queue* Q){
	int temp = 0;
	if(IsEmpty() == 1)
		cout<<"Maaf queue kosong"<<endl;
	else{
		temp = Q->data[data->head]
		Q->head = (Q->head+1)%max;
		-- Q->count;
		return (temp);
	}
}