#pragma once
#include "OperationFile.h"
#include "LinkedList.h"
using namespace std;

class Online{
public:
	Online();
	~Online();
	LinkedList XMLToLinkedList();
	void SaveToXML(string jenis, string metode, string tanggal, string waktu, string harga);
	string FileLocation = "Pembayaran.xml";
};