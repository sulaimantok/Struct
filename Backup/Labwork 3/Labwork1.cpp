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

struct Mahasiswa{
	string nama;
	string nrp;
	Mahasiswa* next = NULL;
} *head, *tail;

void initiate();
int isEmpty();
void addLast(string nama, string nrp);
void getXMLData(string filename);
int CountMahasiswa(string filename);
void PrintList();

int main(){
	initiate();
	OperationFile op;

	getXMLData("dea3.xml");
	PrintList();
	system("PAUSE");
}

void initiate() {
	head = tail = NULL;
}

int isEmpty() {
	return (head == NULL) ? 1 : 0;
}

void addLast(string Nama, string Nrp) {
	Mahasiswa *baru;
	baru = new Mahasiswa;
	baru->nama = Nama;
	baru->nrp = Nrp;

	if (isEmpty() == 1)
		head = tail = baru;
	else{
		tail->next = baru;
		tail = baru;
	}
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
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
