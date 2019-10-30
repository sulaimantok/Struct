#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
}
LinkedList::~LinkedList() {
	
}

void LinkedList::AddFirst(string a, string b, string c, string d, string e) {
	linkedlist1 = new linkedlist;
	linkedlist1->jenis = a;
	linkedlist1->metode = b;
	linkedlist1->tanggal = c;
	linkedlist1->waktu = d;
	linkedlist1->harga = e;
	linkedlist1->next = NULL;
	head = linkedlist1;
	if (isEmpty() == 1) head = tail = linkedlist1;
	else {
		linkedlist1->next = head;
		head = linkedlist1;
	}
}
void LinkedList::AddLast(string a, string b, string c, string d, string e) {
	linkedlist1 = new linkedlist;
	linkedlist1->jenis = a;
	linkedlist1->metode = b;
	linkedlist1->tanggal = c;
	linkedlist1->waktu = d;
	linkedlist1->harga = e;
	linkedlist1->next = NULL;
	if (isEmpty() == 1) head = tail = linkedlist1;
	else {
		tail->next = linkedlist1;
		tail = linkedlist1;
	}
}
void LinkedList::DeleteFirst() {
	linkedlist *temp = head;
	head = head->next;
	delete(temp);
}
void LinkedList::DeleteLast() {
	linkedlist *temp1 = tail, *temp2 = head;
	while (temp2->next != tail) temp2 = temp2->next;
	tail = temp2;
	tail->next = NULL;
	delete(temp1);
}
void LinkedList::InsertAtIndex(int index, string a, string b, string c, string d, string e) {
	linkedlist *temp1 = head, *temp2;
	linkedlist1 = new linkedlist;
	linkedlist1->jenis = a;
	linkedlist1->metode = b;
	linkedlist1->tanggal = c;
	linkedlist1->waktu = d;
	linkedlist1->harga = e;
	linkedlist1->next = NULL;
	if (isEmpty() == 1)
		head = tail = linkedlist1;
	else {
		int count = 1;
		while (count < index) {
			if (temp1->next == NULL) break;
			else {
				temp1 = temp1->next;
				count++;
			}
		}
		temp2 = temp1->next;
		temp1->next = linkedlist1;
		linkedlist1->next = temp2;
	}

}

void LinkedList::DeleteAtIndex(int index, string a, string b, string c, string d, string e) {
	linkedlist *temp1 = head, *temp2, *temp3;
	int count = 1;
	while (count < index - 1) {
		temp1 = temp1->next;
		count++;
	}
	temp2 = temp1->next;
	temp3 = temp2->next;
	delete(temp2);
}

int LinkedList::isEmpty(){
	return (head == NULL) ? 1 : 0;
}
void LinkedList::displayList() {
	
}