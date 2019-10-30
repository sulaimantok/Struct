#include <stdio.h>
#include <string>

struct petak
{
	int row;
	int col;
	int R[6][6];
};

void opsi(int o){
	/* 1 bawah
	2 kiri atas
	3 kanan bawah
	4 kiri bawah
	*/
	switch (o){
		case 1:
			row = row+1;
			break;
		case 2:
			col = col-1;
		case 3:
			col = col+1;
			row = 
		case 4:
			row = row+1;
			col = col-1;
	}

}

void init(){
	petak *S;
	S->col = 0;
	S->row = 0;
}

void isFull(Stack* col, Stack* row){
	petak *S;
	return (S->col == 6 && S->row == 6 )? 1:0;
}

void isEmpty(){
	petak *S;
	return (S->col == 0 && S->row == 6)? 1:0;
}

void push(int i){
	petak *S;
	if (isFull() == 1)
		cout<< "Penuh"<<endl;
	else{
		if(S->col== 5){
			++S;S->row;
			S->col=0;
		}
		S->R[S->col][S->row] = i;
		++S->col;
	}
}

void pop(){
	petak *S;
	if(isEmpty()== 1 ){
		cout<<"Kosong"<<endl;
	}else{
		if(S->col == -1){
			-- S->row;
			S->col = 5;
		}
		S->R[S->row][S->col];
		--S;S->row;
	}
}

int main(){
	int mypos[];

}