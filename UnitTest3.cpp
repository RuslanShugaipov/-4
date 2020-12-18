#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\79825\Desktop\modak\аисд3лаба\Heap.h"
#include "C:\Users\79825\Desktop\modak\аисд3лаба\List.h"
#include "C:\Users\79825\Desktop\modak\аисд3лаба\Heap.cpp"
#include "C:\Users\79825\Desktop\modak\аисд3лаба\List.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(BinaryHeapTests)
	{
	public:

		TEST_METHOD(contains_test)
		{
			BinaryHeap test;
			test.insert(1);
			test.insert(2);
			test.insert(3);
			Assert::AreEqual(test.contains(1), true);
			Assert::AreEqual(test.contains(4), false);
		}

		TEST_METHOD(insert_test)
		{
			BinaryHeap test;
			test.insert(1);
			test.insert(2);
			test.insert(3);
			Assert::AreEqual(test.contains(1), true);
			Assert::AreEqual(test.contains(2), true);
			Assert::AreEqual(test.contains(3), true);
		}

		TEST_METHOD(remove_test)
		{
			BinaryHeap test;
			test.insert(5);
			test.insert(4);
			test.insert(3);
			test.insert(2);
			test.insert(1);
			Assert::AreEqual(test.contains(1), true);
			Assert::AreEqual(test.contains(2), true);
			Assert::AreEqual(test.contains(3), true);
			Assert::AreEqual(test.contains(4), true);
			Assert::AreEqual(test.contains(5), true);
			test.remove(3);
			test.remove(4);
			Assert::AreEqual(test.contains(1), true);
			Assert::AreEqual(test.contains(2), true);
			Assert::AreEqual(test.contains(3), false);
			Assert::AreEqual(test.contains(4), false);
			Assert::AreEqual(test.contains(5), true);
			try
			{
				test.remove(10);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "\nThere is no such element\n");
			}
			
		}

		TEST_METHOD(dft_iterator_test)
		{
			BinaryHeap test;
			int array[5] = { 1,2,3,4,5 };
			int check[5] = { 5,4,1,3,2 };
			for (int i = 0; i < 5; i++)
				test.insert(array[i]);
			Iterator* heap_dft_iterator = test.create_dft_iterator();
			for (int i = 0; i < 5; i++)
				Assert::IsTrue(heap_dft_iterator->next(&test) == check[i]);
			
		}

		TEST_METHOD(bft_iterator_test)
		{
			BinaryHeap test;
			int array[5] = { 1,2,3,4,5 };
			int check[5] = { 5,4,2,1,3 };
			for (int i = 0; i < 5; i++)
				test.insert(array[i]);
			Iterator* heap_bft_iterator = test.create_bft_iterator();
			for (int i = 0; i < 5; i++)
				Assert::IsTrue(heap_bft_iterator->next(&test) == check[i]);
		}
	};
}