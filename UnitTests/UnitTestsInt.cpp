#include "pch.h"
#include "CppUnitTest.h"
#include "template_Cycle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTestsInt)
	{
	public:
		
		TEST_METHOD(TestCreateInstance)
		{
			// Arrange
			Cycle<int>* pCut = nullptr;

			// Act
			pCut = new Cycle<int>;

			// Assert
			Assert::IsNotNull(pCut);

			// Teardown
			delete pCut;
		}

		TEST_METHOD(AddOneItem) {
			// Arrange
			Cycle<int>* pCut = nullptr;
			pCut = new Cycle<int>;
			int input = 12;
			int expected = input;

			// Act
			pCut->AddItem(input);

			// Assert
			int actual = pCut->at(0);
			int size = pCut->size();
			Assert::AreEqual(expected, actual);
			Assert::AreEqual(1, size);

			// Teardown
			delete pCut;
		}

		TEST_METHOD(CycleOneItem_1) {
			// Arrange
			Cycle<int>* pCut = nullptr;
			pCut = new Cycle<int>;
			int input_1 = 12;
			pCut->AddItem(input_1);

			// Act
			int actual = pCut->GetNextItem();

			// Assert
			Assert::AreEqual(12, actual);	

			// Teardown
			delete pCut;
		}

		TEST_METHOD(CycleOneItem_2) {
			// Arrange
			Cycle<int>* pCut = nullptr;
			pCut = new Cycle<int>;
			int input_1 = 12;
			pCut->AddItem(input_1);
			pCut->GetNextItem();

			// Act
			int actual = pCut->GetNextItem();

			// Assert
			Assert::AreEqual(12, actual);

			// Teardown
			delete pCut;
		}

		TEST_METHOD(CycleTwoItems_1) {
			// Arrange
			Cycle<int>* pCut = nullptr;
			pCut = new Cycle<int>;
			int input_1 = 12;
			int input_2 = 13;
			pCut->AddItem(input_1);
			pCut->AddItem(input_2);
			pCut->GetNextItem();

			// Act
			int actual = pCut->GetNextItem();

			// Assert
			Assert::AreEqual(13, actual);

			// Teardown
			delete pCut;
		}

		TEST_METHOD(CycleTwoItems_2) {
			// Arrange
			Cycle<int>* pCut = nullptr;
			pCut = new Cycle<int>;
			int input_1 = 12;
			int input_2 = 13;
			pCut->AddItem(input_1);
			pCut->AddItem(input_2);
			pCut->GetNextItem();
			pCut->GetNextItem();

			// Act
			int actual = pCut->GetNextItem();

			// Assert
			Assert::AreEqual(12, actual);

			// Teardown
			delete pCut;
		}

		TEST_METHOD(SetPosition) {
			// Arrange
			Cycle<int>* pCut = nullptr;
			pCut = new Cycle<int>;
			int input_1 = 12;
			int input_2 = 13;
			int input_3 = 14;
			pCut->AddItem(input_1); // pos 0
			pCut->AddItem(input_2); // pos 1
			pCut->AddItem(input_3); // pos 2

			// Act
			pCut->SetPosForNextItem(2);

			// Assert
			int actual = pCut->GetNextItem();

			Assert::AreEqual(actual, 14);

			// Teardown
			delete pCut;
		}

		TEST_METHOD(MixIt) {
			// Arrange
			Cycle<int>* pCut = nullptr;
			pCut = new Cycle<int>;

			int sum = 0;
			for (int i = 0; i < 10; i++) {
				pCut->AddItem(i);
				sum += i * i;
			}

			// Act
			pCut->MixItB();

			// Assert
			int differentsumm = 0;
			for (int i = 0; i < 10; i++) {
				int item = pCut->at(i);
				differentsumm += i * item;
			}
			
			Assert::AreNotEqual(differentsumm, sum);

			// Teardown
			delete pCut;
		}

	};
}
