#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include "OperationFile.h"
#include "Linked.h"
#include "Online.h"

using namespace std;

string lokasi = "/home/sulaiman/ngoding/c++_C/Struktur/Project/pembayaran.xml";

void input(){
	string tanggal,jenis,harga,info,waktu,metode;
	Linked LinkedList1;
	Online online;
	cout<<"Masukan jenis trasaksi : ";
	getline(cin,jenis);
	cout<<"Masukan Harga barang : ";
	getline(cin,harga);
	cout<<"Masukan tanggal trasaksi : ";
	getline(cin,tanggal);
	cout<<"Masukan Waktu trasaksi : ";
	getline(cin,waktu);
	cout<<"Masukan Info trasaksi : ";
	getline(cin,info);
	cout<<"Masukan Metode trasaksi : ";
	getline(cin,metode);
	online.SaveToXML(jenis, harga, tanggal, waktu, info,metode);
	LinkedList1 = online.XMLToLinkedList();
}

int read(){
	string line;
	map<string,string> file;
	ifstream data(lokasi);
	while(getline(data,line)){
		string token;
		istringstream tokens(line);
		while(tokens>>token){
			int open = token.find("<trasaksi>");
			int close = token.find("</trasaksi>");
			if(open == int){
				file[token.substr(0,open) ]= token.substr(open+10,close-(open+10));
			}
		}
		transaksi 1(file["jenis>"],file["tanggal"],file["harga"],file["info"],file["waktu"],file["metode"]);
	}
	file.clear();
}
int main(){
	input();
}

