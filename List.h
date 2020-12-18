#pragma once
#pragma once

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void push_back(int newEl);
	void push_front(int newEl);
	void pop_back();
	void pop_front();
	void insert(int newEl, size_t index);
	int at(size_t index) const;
	void remove(size_t index);
	size_t get_size();
	void print_to_console();
	void clear();
	void set(size_t index, int newData);
	bool isEmpty();
	size_t find_first(LinkedList *list);
	bool isPrinted();

private:
	class Node
	{
		public:
			Node(int data, Node* next = nullptr, Node* prev =nullptr)
			{
				this->data = data;
				this->next = next;
				this->prev = prev;
			}
			int data;
			Node* next;
			Node* prev;
	};
	
	Node* head;
	Node* tail;
	size_t size;
};

class BinaryHeap;

class Iterator
{
public:
	virtual int next(BinaryHeap*) = 0;
	virtual bool has_next(BinaryHeap*) = 0;
};