#include "pch.h"
#include "CppUnitTest.h"
#include "../5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t;
			t = A(-2, 2, -0.5);
			Assert::AreEqual(t, -0.075);
		}
	};
}
