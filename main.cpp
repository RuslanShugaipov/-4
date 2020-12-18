#include "Heap.h"
#include <iostream>

using namespace std;

void main()
{
	BinaryHeap binheap;
	int input_number, quantity;
	cout << "Enter amout of elements for the binary heap: ";
	cin >> quantity;
	cout << "Enter the elements for the binary heap: ";
	for (int i = 0; i < quantity; i++)
	{
		cin >> input_number;
		binheap.insert(input_number);
	}
	cout << endl;
	binheap.out();
	cout << endl;

	Iterator* heap_dft_iterator = binheap.create_dft_iterator();
	while (heap_dft_iterator->has_next(&binheap))
		cout << heap_dft_iterator->next(&binheap) << ' ';

	cout << "\n\n";

	Iterator* heap_bft_iterator = binheap.create_bft_iterator();
	while (heap_bft_iterator->has_next(&binheap))
		cout << heap_bft_iterator->next(&binheap) << ' ';
}
