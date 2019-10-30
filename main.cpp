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

struct mahasiswa {
	vector <string> nama;
	vector <string > nrp;
};

int main(){
	mahasiswa mhs1;
	string nama,nrp;
	string lokasi = "/home/sulaiman/ngoding/c++_C/Struktur/mahasiswa.xml";
	string tag = "mahasiswa";
	OperationFile file1;
	
	mhs1.nama = file1.getData(lokasi,tag);
	file1.printXMLToScreen(lokasi,tag);
	/*
	cout<<"Masukan Nama : ";
	cin>>nama;
	cout<<"Masukan NRP : ";
	cin >>nrp;
	file1.WriteToFile(lokasi,"<mahasiswa>\n	<nama>\n		"+nama+"\n	</nama>\n	<nrp>\n		"+nrp+"\n	</nrp>\n</mahasiswa>");
	file1.printToScreen(lokasi);
	*/
	file1.getFile(lokasi);
	file1.getData("mhs",tag);
}
