#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_6/Lab_12_6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab126
{
	TEST_CLASS(UnitTestLab126)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL, * last = NULL;
			enqueue(first, last, 1);
			enqueue(first, last, 2);
			enqueue(first, last, 3);
			enqueue(first, last, 4);
			enqueue(first, last, 5);
			Assert::AreEqual(min(first), 1);
			Assert::AreEqual(max(first), 5);
			Assert::AreEqual(avg(first), 3.0, 0.00001);
		}
	};
}
