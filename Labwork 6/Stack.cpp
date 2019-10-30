#include "struktur.h"

Stack::~Stack(){

}

void Stack::Initialize(Stack* S){
	S->count =0;
}

int Stack::IsFull(Stack* S){
	return (S->count == max)? 1:0;
}

int Stack::IsEmpty(Stack* S){
	return (S->count == 0)? 1:0;
}

void Stack::Push(int x,Stack* S){
	if(IsFull()==1)
		cout<<"Maaf Stack penuh"<<endl;
	else{
		S->data[S->count];
		++ S->count;
	}
}

void Stack::Pop(Stack* S){
	if(IsEmpty()==1)
		cout<<"Maaf Stack kosong"<<endl;
	else{
		-- S->count;
		return (S->data[S->count]);
	}
}