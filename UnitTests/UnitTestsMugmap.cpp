#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "Mugmap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTestsMugmap) {
public:

	TEST_METHOD(TestCreateInstance) {
		// Arrange
		Mugmap* pCut = nullptr;

		// Act
		pCut = new Mugmap();

		// Assert
		Assert::IsNotNull(pCut);

		// Teardown
		delete pCut;
	}

	TEST_METHOD(AddItem) {
		// Arrange
		Mugmap* pCut = nullptr;
		pCut = new Mugmap();

		// Act
		pCut->AddItem(1, 3);

		// Assert
		Mug* pItem = pCut->GetItemByMugNumber(1);

		Assert::IsNotNull(pItem);
		string key = pItem->Key();
		Assert::AreEqual(key, string("k_001"));
		
		// Teardown
		delete pCut;
	}

	TEST_METHOD(CheckRef) {
		// Arrange
		Mugmap* pCut = nullptr;
		pCut = new Mugmap();

		// Act
		pCut->AddItem(1, 3);
		Mug* pItem_1 = pCut->GetItemByMugNumber(1);
		pItem_1->PullAPearl(2);

		// Assert
		Mug* pItem_2 = pCut->GetItemByMugNumber(1);

		Assert::IsNotNull(pItem_2);
		Assert::AreEqual(pItem_2->ElectedPearl(), 2);

		// Teardown
		delete pCut;
	}


	TEST_METHOD(Chaintest) {
		// Arrange
		Mugmap* pCut = nullptr;
		pCut = new Mugmap();
		pCut->AddItem(99, 3);
		pCut->AddItem(2, 3);
		pCut->AddItem(3, 3);
		pCut->AddItemToChain(pCut->GetItemByMugNumber(99));
		pCut->AddItemToChain(pCut->GetItemByMugNumber(3));
		pCut->AddItemToChain(pCut->GetItemByMugNumber(2));
		Mug* pItem_2 = pCut->LastMug();
		Mug* pItem_3 = pItem_2->Previous();
		
		// Act
		Mug* pItem_99 = pItem_3->Previous();

		// Assert
		Assert::IsNotNull(pItem_99);
		Assert::AreEqual(pItem_99->Key(), string("k_099"));

		// Teardown
		delete pCut;
	}

	TEST_METHOD(ChainCleanup) {
		// Arrange
		Mugmap* pCut = nullptr;
		pCut = new Mugmap();
		pCut->AddItem(99, 3);
		pCut->AddItem(2, 3);
		pCut->AddItem(3, 3);
		pCut->AddItemToChain(pCut->GetItemByMugNumber(99));
		pCut->AddItemToChain(pCut->GetItemByMugNumber(3));
		pCut->AddItemToChain(pCut->GetItemByMugNumber(2));

		// Act
		pCut->CleanupChain();

		// Assert
		Assert::IsNull(pCut->LastMug());		

		// Teardown
		delete pCut;
	}

	TEST_METHOD(SetupMugMap) {
		// Arrange
		Mugmap* pCut = nullptr;
		pCut = new Mugmap();

		// Act
		pCut->SetupMugMap(4, 3);

		// Assert
		Assert::AreEqual(pCut->GetMugs()->size(), (size_t)4);

		// Teardown
		delete pCut;
	}
	};
}