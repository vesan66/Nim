#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "template_Cycle.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{

	class TestObject {
	public:
		TestObject(const string& name) : name{ name } {};
		string GetName() const { return this->name; };
		void SetName(const string& name) { this->name = name; };
		~TestObject() {};
	private:
		string name;
	};


	TEST_CLASS(UnitTestsObject) {
	public:

		TEST_METHOD(TestCreateInstance) {
			// Arrange
			Cycle<TestObject*>* pCut = nullptr;

			// Act
			pCut = new Cycle<TestObject*>;

			// Assert
			Assert::IsNotNull(pCut);

			// Teardown
			delete pCut;
		}

		TEST_METHOD(AddOneItem) {
			// Arrange
			Cycle<TestObject*>* pCut = nullptr;
			pCut = new Cycle<TestObject*>;
			TestObject* pInput = new TestObject("Eins");
			TestObject* pExpected = pInput;

			// Act
			pCut->AddItem(pInput);

			// Assert
			TestObject* pActual = pCut->at(0);
			Assert::IsTrue((pActual->GetName() == "Eins"), L"Not the same Object.");
			Assert::IsTrue((pExpected == pActual), L"Not the same Object.");

			// Teardown
			delete pCut;
		}

		//TEST_METHOD(CycleNo_Items) {
		//	// Arrange
		//	Cycle<TestObject>* pCut = nullptr;
		//	pCut = new Cycle<TestObject>;

		//	// Act
		//	try {
		//		TestObject actual = pCut->GetNextItem();
		//		Assert::Fail();
		//	}
		//	catch (const std::exception&) {
		//		Assert::IsTrue(true);
		//	}
		//  // Teardown
		//  delete pCut;
		//}


		TEST_METHOD(CycleTwoItems_2) {
			// Arrange
			Cycle<TestObject*>* pCut = nullptr;
			pCut = new Cycle<TestObject*>;

			TestObject* pInput_1 = new TestObject("Eins");
			TestObject* pInput_2 = new TestObject("Zwo");
			TestObject* pExpected = pInput_1;

			pCut->AddItem(pInput_1);
			pCut->AddItem(pInput_2);
			pCut->GetNextItem();
			pCut->GetNextItem();

			// Act
			TestObject* pActual = pCut->GetNextItem();

			// Assert
			Assert::IsTrue((pExpected == pActual), L"Not the same Object.");

			// Teardown
			delete pCut;
		}

		TEST_METHOD(ForEach) {
			// Arrange
			Cycle<TestObject*>* pCut = nullptr;
			pCut = new Cycle<TestObject*>;
			TestObject* pInput_1 = new TestObject("Eins");
			TestObject* pInput_2 = new TestObject("Zwo");
			TestObject* pExpected = pInput_1;
			pCut->AddItem(pInput_1);
			pCut->AddItem(pInput_2);
			string actual{};
			string expected = pInput_1->GetName() + pInput_2->GetName();

			// Act
			for (auto item = pCut->begin(); item != pCut->end(); item++) {
				actual += (*item)->GetName();
			}

			// Assert
			Assert::AreEqual(actual, expected, L"For Each not correct.");

			// Teardown
			delete pCut;
		}

		TEST_METHOD(TestWriteToObject) {
			// Arrange
			Cycle<TestObject*>* pCut = nullptr;
			pCut = new Cycle<TestObject*>;
			TestObject* pInput_1 = new TestObject("Eins");
			pCut->AddItem(pInput_1);
			TestObject* pReceivedObject = pCut->GetNextItem();

			// Act
			pReceivedObject->SetName("Hallo");

			// Assert
			auto c = pReceivedObject->GetName();
			auto exp1 = string("Hallo");
			Assert::AreEqual(c, exp1, L"Not matching.");
			auto exp2 = pInput_1->GetName();
			Assert::AreEqual(c, exp2, L"Not matching.");

			// Teardown
			delete pCut;
		}
	};
}