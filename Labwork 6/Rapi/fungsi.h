#include "stdio.h"
#include "iostream"

using namespace std;

struct petak {
	string huruf;
	string angka;
	int x;
	int y;

	int kiri = 0;
	int kanan= 0;
	int atas = 0;
	int bawah = 0;

	int status = 1;
}maps[6][6];

struct list {
	petak isi[10];
	int batas = 0;
} forbidden, path, branch;

class fungsi{
public:
	~Stack();
	void inisialisasi();
	void pushToPath(petak input);
	void pushToForbidden(petak input);
	void pushToBranch(petak input);
	petak popPath();
	petak popBranch();

	void enqueue(petak input, list queue);
	petak dequeue(list queue);
	petak top (list input);

	void move(petak input, int direction);
	void back();
	int cekrules(petak input, list forbidden);
	int findInForbidden(petak input);
	int cekBelokan(petak input);
	void printList(list print);

};