#include <iostream> 
#include "linkedlist.h"

using namespace std;

linkedlist::linkedlist() : head(NULL) {};

linkedlist::~linkedlist()
{
	Node* current = head;
	while (current != NULL)
	{
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	head = NULL;
}


bool linkedlist::isempty()
{
	return (head == NULL);

}

void linkedlist::addlast(const int &element)
{
	Node* newNode = new Node;
	newNode->t = element;
	newNode->next = NULL;
	if (isempty())
	{
		head = newNode;
	}
	else
	{
		Node* current=head;
		while (current->next!=NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void linkedlist::insert(const int& element, const int& numer)
{
	Node* newNode = new Node;
	newNode->t = element;
	if (numer <= 0 || isempty())
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		Node* current = head;
		int index = 0;
		while (current->next != nullptr && index < numer - 1)
		{
			current = current->next;
			index++;
		}

		newNode->next = current->next;
		current->next = newNode;
	}
}

void linkedlist::addfirst(const int& element)
{
	Node* newNode = new Node;
	newNode->t = element;
	newNode->next = head;  
	head = newNode;        
}

void linkedlist::deletefirst()
{
	if (head==NULL) return;
	Node* temp = head;
	head = head->next;
	delete temp;
}

void linkedlist::deletelast()
{
	if (isempty()) return;

	if (head->next == NULL)
	{
		delete head;
		head = NULL;
		return;
	}

	Node* current = head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		delete current->next;
		current->next = NULL;
}

void linkedlist::deletespecific(const int& numer)
{
	if (numer < 0 || isempty()) return;

	if (numer == 0)
	{
		deletefirst();
		return;
	}

		Node* current = head;
		int index = 0;
		while (current != NULL && current->next != NULL && index < numer - 1)
		{
			current = current->next;
			index++;
		}

		if (current == NULL || current->next == NULL)
		{
			return;
		}

		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
}

bool linkedlist::isthere(int element) const
{
	Node* current = head;
	while (current != NULL)
	{
		if (current->t == element)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

void linkedlist::displayspecific(const int& numer)
{
	if (isempty())
	{
		cout << "Lista jest pusta!" << endl;
		return;
	}
	if (numer<0)
	{
		cout << "Nie istnieje taki element!" << endl;
		return;
	}
		Node* current = head;
		int index = 0;
		while (current != NULL && index < numer)
		{
			current = current->next;
			index++;
		}

		if (current == NULL)
		{
			cout << "Nie istnieje taki element!" << endl;
			return;
		}

		cout << "Element nr " << numer << ": " << current->t << endl;
}






