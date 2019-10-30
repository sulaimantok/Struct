#pragma once
#include <string>
#include <vector>
using namespace std;

struct linkedlist {
	string jenis;
	string harga;
	string tanggal;
	string waktu;
	string info;
	string metode;
	linkedlist *next;
};
class LinkedList {
private:
	linkedlist *head, *tail, *linkedlist1;
public:
	LinkedList();
	~LinkedList();
	void AddFirst(string a,string b,string c,string d,string e,string f);
	void AddLast(string a, string b, string c, string d, string e,string f);
	void DeleteFirst();
	void DeleteLast();
	void InsertAtIndex(int index, string a, string b, string c, string d, string e,string f);
	void DeleteAtIndex(int index, string a, string b, string c, string d, string e,string f);
	int isEmpty();
	void show();
	
};