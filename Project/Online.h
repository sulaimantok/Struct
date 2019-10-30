#pragma once
#include "OperationFile.h"
#include "Linked.h"
using namespace std;

class Online{
public:
	pembayaran();
	~pembayaran();
	LinkedList XMLToLinkedList();
	void SaveToXML(string jenis, string harga, string tanggal, string waktu, string info,string metode);
	string FileLocation = "/home/sulaiman/ngoding/c++_C/Struktur/Project/pembayaran.xml";
};