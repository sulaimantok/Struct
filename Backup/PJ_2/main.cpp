#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "OperationFile.h"
#include "LinkedList.h"
#include "Online.h"
#include "OperationFile2.h"


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
	Mahasiswa output;
	string text = op.getFile(filename);

	int open = 0;
	int pos = 0;
	int close = 0;
	int start = 0;
	int index = 0;

	while (true) {
		index = text.find("<mahasiswa>", start);
		if (index > text.length())
			break;
		else {
			open = text.find("<nama>", start);
			close = text.find("</nama>", pos);
			string Nama = text.substr(open + 6, close - open - 6);

			open = text.find("<nrp>", start);
			close = text.find("</nrp>", pos);
			string Nrp = text.substr(open + 5, close - open - 5);

			addLast(Nama, Nrp);

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
	Mahasiswa *it = head;

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


