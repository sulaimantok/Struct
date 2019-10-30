// Labwork1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include "OperationFile.h"

using namespace std;

struct Online{
	string jenis;
	string metode;
	string tanggal;
	string waktu;
	string harga;
	Online* next = NULL;
} *head, *tail;

void initiate();
int isEmpty();
void addLast(string jenis, string metode, string tanggal, string waktu, string harga);
void getXMLData(string filename);
int CountTransaksi(string filename);
void PrintList();
void input();
void cari();
void SaveToXML(string jenis, string metode, string tanggal, string waktu, string harga);
int banyak(string filename);
int duitbanyak(string filename);
void menu();

int main(){
	initiate();
	OperationFile op;

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
			getXMLData("Pembayaran.xml");
			PrintList();
			break;
		case 3:
			menu();
			break;
		default:
			cout<<"Masukan pilihan yang benar";
	}
	
}

void initiate() {
	head = tail = NULL;
}

int isEmpty() {
	return (head == NULL) ? 1 : 0;
}

void addLast(string Jenis, string Metode, string Tanggal, string Waktu, string Harga) {
	Online *baru;
	baru = new Online;
	baru->jenis = Jenis;
	baru->metode = Metode;
	baru->tanggal = Tanggal;
	baru->waktu = Waktu;
	baru->harga = Harga;


	if (isEmpty() == 1)
		head = tail = baru;
	else{
		tail->next = baru;
		tail = baru;
	}
}

void getXMLData(string filename) {
	OperationFile op;
	Online output;
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
			string Tanggal = text.substr(open + 9, close - open - 9);

			open = text.find("<waktu>", start);
			close = text.find("</waktu>", pos);
			string Waktu = text.substr(open + 7, close - open - 7);

			open = text.find("<harga>", start);
			close = text.find("</harga>", pos);
			string Harga = text.substr(open + 7, close - open - 7);

			addLast(Jenis, Metode,Tanggal,Waktu,Harga);

			start = close + 1;
			pos = close + 1;	
		}
	}
}

int CountTransaksi(string filename) {
	OperationFile op;
	string text = op.getFile(filename);
	int index = 0;
	int output = 0;
	int start = 0;
	while (true) {
		index = text.find("<transaksi>", start);

		if (index > text.length())
			break;
		else {
			output++;
			start = index + 1;
		}
	}
	return output;
}
int banyak(string filename) {
	OperationFile op;
	string text = op.getFile(filename);
	int index = 0,index2=0,index3=0;
	int payback = 0,pay =0,cashback =0;
	int start = 0,start2=0,start3=0;
	while (true) {
		index = text.find("Pengembalian", start);

		if (index > text.length())
			break;
		else {
			payback++;
			start = index + 1;
		}
	}
	while (true) {
		index2 = text.find("Pembayaran", start2);

		if (index2 > text.length())
			break;
		else {
			pay++;
			start2 = index2 + 1;
		}
	}
	while (true) {
		index3 = text.find("Cashback", start3);

		if (index3 > text.length())
			break;
		else {
			cashback++;
			start3 = index3 + 1;
		}
	}/*
	printf("%d\n",pay);
	printf("%d\n",payback);
	printf("%d\n",cashback);*/
	if (payback>pay && payback>cashback){
		printf("Pengembalian paling sering dilakukan\n");
	}else if(pay>payback && pay>cashback){
		printf("Pembayaran paling sering dilakukan\n");
	}else{
		printf("Cashback paling sering dilakukan\n");
	}
	
}

void PrintList() {
	system("clear");
	Online *it = head;

	while(it!=NULL) {
		cout << it->jenis << endl;
		cout << it->metode << endl;
		cout << it->tanggal << endl;
		cout << it->waktu << endl;
		cout << it->harga << endl << endl;

		it = it->next;
	} 
}

void input() {
	system("clear");
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
	//SaveToXML(jenis, metode, tanggal, waktu, harga);	
}

void cari(){
	system("clear");
	printf("Jumlah transaksi\n");
	int data = CountTransaksi("Pembayaran.xml");
	printf("%d\n",data );
}
void menu(){
	system("clear");
	int i=0;
	cout<<"Apa yang mau kamu cari ?\n";
	cout<<"1. Jenis yang paling Sering Digunakan\n";
	cout<<"2. Jenis paling banyak duit\n";
	cout<<"3. dll \n";
	cout<<"Masukan Pilihan anda(1/2/3): ";
	cin>>i;
	switch(i){
		case 1:
			banyak("Pembayaran.xml");
			break;
		case 2:
			duitbanyak("Pembayaran.xml");
			break;
		case 3:
			//banyak("Pembayaran.xml");
			break;
		default:
			cout<<"Masukan pilihan yang benar";
	}
}

int duitbanyak(string filename){
	OperationFile op;
	string text = op.getFile(filename);

	printf("Duit\n");
}

/*
void SaveToXML(string jenis, string metode, string tanggal, string waktu, string harga) {
	initiate();
	OperationFile file("Pembayaran.xml");
	string isiFile = file.getFile();
	size_t location=isiFile.find("</Online>");
	string input = "\n\t<transaksi>\n\t\t<jenis>" + jenis + "</jenis>\n\t\t<metode>" + metode + "</metode>\n\t\t<tanggal>" + tanggal + "</tanggal>\n\t\t<waktu>" + waktu + "</waktu>\n\t\t<harga>" + harga + "</harga>\n\t</transaksi>";
	if(location!=string::npos) isiFile.insert(location - 1, input);
	else cout << "</Online> tidak Ditemukan\n";
	file.OverwriteToFile(isiFile);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
*/
