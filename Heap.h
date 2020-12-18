#pragma once
#include "List.h"


class BinaryHeap
{
	int MaxSize = 10;
	int* root;
	int HeapSize;
	void check(int, int);
	void top(int);
	void bottom(int);
public:
	BinaryHeap();
	~BinaryHeap();
	bool contains(int);
	void insert(int);
	void remove(int);
	void out();

	Iterator* create_dft_iterator();
	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int);
		int next(BinaryHeap*) override;
		bool has_next(BinaryHeap*) override;
	private:
		int index;
		LinkedList stk;
	};

	Iterator* create_bft_iterator();
	class bft_iterator :public Iterator
	{
	public:
		bft_iterator(int);
		int next(BinaryHeap*) override;
		bool has_next(BinaryHeap*) override;
	private:
		int index;
	};
};