#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
//#include "OperationFile.h"
#include "LinkedList.h"
#include "Online.h"
#include "OperationFile2.h"
#include "pch.h"


using namespace std;
void save(string a,string b,string c,string d,string e){
	LinkedList LinkedList1;
	Online transaksi;
	transaksi.SaveToXML(a, b, b, d, e);
	LinkedList1 = transaksi.XMLToLinkedList();
}

void input() {
	string jenis, metode, tanggal, waktu, harga;
	cout << "Masukkan jenis: ";
	getline(cin, jenis);
	cout << "Masukkan Metode: ";
	getline(cin, metode);
	cout << "Masukkan tanggal: ";
	getline(cin, tanggal);
	cout << "Masukkan waktu : ";
	getline(cin, waktu);
	cout << "Masukkan harga: ";
	getline(cin, harga);
	save(jenis, metode, tanggal, waktu, harga);
	
}

void getXMLData(string filename) {
	OperationFile op;
	LinkedList LinkedList1;
	string text = op.getFile(filename);

	int open = 0;
	int pos = 0;
	int close = 0;
	int start = 0;
	int index = 0;

	while (true) {
		index = text.find("<transaksi>", start);
		if (index > text.length())
			break;
		else {
			open = text.find("<jenis>", start);
			close = text.find("</jenis>", pos);
			string Jenis = text.substr(open + 7, close - open - 7);

			open = text.find("<metode>", start);
			close = text.find("</metode>", pos);
			string Metode = text.substr(open + 8, close - open - 8);

			open = text.find("<tanggal>", start);
			close = text.find("</tanggal>", pos);
			string Metode = text.substr(open + 9, close - open - 9);

			open = text.find("<waktu>", start);
			close = text.find("</waktu>", pos);
			string Metode = text.substr(open + 7, close - open - 7);

			open = text.find("<harga>", start);
			close = text.find("</harga>", pos);
			string Metode = text.substr(open + 7, close - open - 7);

			addLast(Jenis, Metode);

			start = close + 1;
			pos = close + 1;	
		}
	}
}

int CountMahasiswa(string filename) {
	OperationFile op;
	string text = op.getFile(filename);
	int index = 0;
	int output = 0;
	int start = 0;
	while (true) {
		index = text.find("<mahasiswa>", start);

		if (index > text.length())
			break;
		else {
			output++;
			start = index + 1;
		}
	}
	return output;
}

void PrintList() {
	LinkedList *it = head;

	while(it!=NULL) {
		cout << it->nama << endl;
		cout << it->nrp << endl << endl;

		it = it->next;
	} 
}

void tampil(){
	initiate();
	OperationFile op;

	getXMLData("Pembayaran.xml");
	PrintList();
}

void cari(){
	printf("Cari\n");
}
int main(){
	int i=0;
	cout<<"========================================================\n";
	cout<<"\t\t\tTuku bae\n";
	cout<<"========================================================\n";
	cout<<"1. Input data\n";
	cout<<"2. Tampilkan data\n";
	cout<<"3. Cari data \n";
	cout<<"Masukan Pilihan anda(1/2/3): ";
	cin>>i;
	switch(i){
		case 1:
			input();
			break;
		case 2:
			tampil();
			break;
		case 3:
			cari();
			break;
		default:
			cout<<"Masukan pilihan yang benar";
	}
}


