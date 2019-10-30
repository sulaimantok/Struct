#pragma once
#include <string>
#include <vector>
using namespace std;

struct linkedlist {
	string jenis;
	string metode;
	string tanggal;
	string waktu;
	string harga;
	linkedlist *next;
};
class LinkedList {
private:
	linkedlist *head, *tail, *linkedlist1;
public:
	LinkedList();
	~LinkedList();
	void AddFirst(string a,string b,string c,string d,string e);
	void AddLast(string a, string b, string c, string d, string e);
	void DeleteFirst();
	void DeleteLast();
	void InsertAtIndex(int index, string a, string b, string c, string d, string e);
	void DeleteAtIndex(int index, string a, string b, string c, string d, string e);
	int isEmpty();
	void displayList();
	
};