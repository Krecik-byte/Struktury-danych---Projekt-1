#ifndef LINKEDLIST_H 
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
private:
	int t;
	Node* next;

	friend class linkedlist;
};

class linkedlist
{
private:
	Node* head;
public:
	linkedlist();
	~linkedlist();
	bool isempty();
	void addlast(const int& t);
	void insert(const int& t, const int& numer);
	void addfirst(const int& element);
	void deletefirst();
	void deletelast();
	void deletespecific(const int& numer);
	void displayspecific(const int& numer);
	bool isthere(int element) const;
};

#endif