#include "Heap.h"
#include <iostream>

using namespace std;

BinaryHeap::BinaryHeap()
{
	HeapSize = 0;
	root = new int[MaxSize];
}

BinaryHeap::~BinaryHeap()
{
	delete[] root;
}

bool BinaryHeap::contains(int key)
{
	for (int i = 0; i < HeapSize; i++)
	{
		if (key == root[i])
			return true;
	}
	return false;
}

void BinaryHeap::top(int i)
{
	int parent = (i - 1) / 2;
	if (i > 0 && root[parent] < root[i])
	{
		int temp = root[i];
		root[i] = root[parent];
		root[parent] = temp;
		top(parent);
	}
}

void BinaryHeap::bottom(int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int greater;
	if (right<HeapSize && root[right]>root[left])
		greater = right;
	else
		greater = left;
	if (greater<HeapSize && root[greater]>root[i])
	{
		int temp = root[i];
		root[i] = root[greater];
		root[greater] = temp;
		bottom(greater);
	}
}

void BinaryHeap::check(int key, int i)
{
	int parent = (i - 1) / 2;
	if (key >= root[parent])
		top(i);
	else
		bottom(i);
}

void BinaryHeap::insert(int key)
{
	if (HeapSize == MaxSize)
	{
		int* transit = new int[MaxSize + 10];
		for (int i = 0; i < HeapSize; i++)
			transit[i] = root[i];
		delete root;
		root = transit;
		MaxSize += 10;
	}
	root[HeapSize] = key;
	HeapSize++;
	check(key, HeapSize - 1);
}

void BinaryHeap::remove(int key)
{
	if (this->HeapSize == 0)
		throw "Heap is empty";
	int i = 0;
	while (root[i] != key)
		i++;
	if (i == HeapSize)
	{
		printf("\nThere is not such element\n");
		return;
	}
	root[i] = root[HeapSize - 1];
	HeapSize--;
	check(key, i);
}

void BinaryHeap::out()
{
	int i = 0; 
	int k = 1; 
	while (i < HeapSize)
	{
		while ((i < k) && (i < HeapSize))
		{
			cout << root[i] << ' ';
			i++;
		}
		cout << endl;
		k = k * 2 + 1;
	}
}

Iterator* BinaryHeap::create_dft_iterator()
{

	return new dft_iterator(0);
}

BinaryHeap::dft_iterator::dft_iterator(int index = 0)
{
	this->index = index;
}

bool BinaryHeap::dft_iterator::has_next(BinaryHeap* binheap)
{
	if (index == 0 && binheap->HeapSize != 0)
		return true;
	if (binheap->HeapSize == 0)
		return false;
	if (index == 0)
		return true;
	if (!stk.isEmpty() && index != 0)
		return false;
	else
		return true;
}

int BinaryHeap::dft_iterator::next(BinaryHeap* binheap)
{
	if (!has_next(binheap))
		throw "The last element in the heap";
	int var = binheap->root[index];
	int left = index * 2 + 1, right = index * 2 + 2;
	if (index == 0)
		stk.push_back(0);
	if (right < binheap->HeapSize)
	{
		stk.push_back(right);
		index = left;
	}
	else if (left < binheap->HeapSize)
		index = left;
	else
	{
		if (stk.at(stk.get_size() - 1) == 0)
			stk.pop_back();
		else
		{
			index = stk.at(stk.get_size() - 1);
			stk.pop_back();
		}
		if (binheap->HeapSize == 1)
			index = -1;
	}
	return var;
}

Iterator* BinaryHeap::create_bft_iterator()
{

	return new bft_iterator(0);
}

BinaryHeap::bft_iterator::bft_iterator(int index = 0)
{
	this->index = 0;
}

bool BinaryHeap::bft_iterator::has_next(BinaryHeap* binheap)
{
	return index != binheap->HeapSize;
}

int BinaryHeap::bft_iterator::next(BinaryHeap* binheap)
{
	if (!has_next(binheap))
		throw "The last element in the heap";
	this->index++;
	return binheap->root[index - 1];
}