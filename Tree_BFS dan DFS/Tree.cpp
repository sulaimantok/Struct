#include <stdio.h>
#include <iostream>

using namespace std;

struct tree
{
	char info;
	tree *Left;
	tree *Right;
};

void insert(tree *pohon, char input){
	tree *P,*Q,*leaf;

	leaf = new tree;
	leaf->info = input;
	leaf->Right = leaf->Left = NULL;

	while((input != pohon->info) && ( Q!=NULL)){
		P = Q;
		if(input < P->info)
			Q = P->Left;
		else
			Q = P-> Right;
	}

	if(input == P->info)
		printf("Huruf yang anda masukan sudah ada\n");
	else
	if(input< P->info)
		P->Left=leaf;
	else
		P->Right=leaf;
}

void preorder(tree *ph){
	if(ph != NULL){
		printf("%c ",ph->info );
		preorder(ph->Left);
		preorder(ph->Right);
	}
}

void inorder(tree *ph){
	if (php != NULL){
		inorder(ph->Left);
		printf("%c ", ph->info);
		inorder(ph->Right);
	}
}

void postorder(tree *ph){
	if(ph != NULL){
		postorder(ph->Left);
		postorder(ph->Right);
		printf("%c ",ph->info );
	}
}


int main(){
	int j=0;char input,jawab[2];
	tree *br;
	while(1){
		printf("Ketikkan huruf :");scanf("%c",&input);
		fflush(stdin);
		if (j==0) {
			br = new tree;
			br->info = input;
			br-> kiri = br-> kanan = NULL;
		}
		else{
			sisip(br,input);
		}
		printf("Ada data lagi(y/t):"); scanf("%s",&jawab);
		fflush(stdin);
		if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0)){
		j++;continue;
		}
		else if ((strcmp(jawab,"T")==0)||(strcmp(jawab,"t")==0))
		break;
	}
	preorder(br); printf("\n");
	inorder(br); printf("\n");
	postorder(br);

}