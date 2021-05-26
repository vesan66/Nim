#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "Mug.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTestsMug) {
public:

	TEST_METHOD(TestCreateInstance) {
		// Arrange
		Mug* pCut = nullptr;

		// Act
		pCut = new Mug(0,3);

		// Assert
		Assert::IsNotNull(pCut);

		// Teardown
		delete pCut;
	}


	TEST_METHOD(MixIt) {
		// Arrange
		Mug* pCut = nullptr;
		pCut = new Mug(0, 3);
		int actual = 0;
		int tries = 100;
		int a = 0; int b = 0; int c = 0;
		int passes = 0;
		// Act
		do {
			int actual = pCut->ElectAPearl(3);
			if (actual == 0) { a++; }
			if (actual == 1) { b++; }
			if (actual == 2) { c++; }

			tries--;
			passes++;
			if (tries < 1) {
				break;
			}

		} while ((actual >= 0) && (actual <= (2)));

		// Assert
		int sum = (a + b + c);
		Assert::AreEqual(sum, passes);

		// Teardown
		delete pCut;
	}


	TEST_METHOD(PullARandomPearl_1) {
		// Arrange
		Mug* pCut = nullptr;
		pCut = new Mug(0, 3);

		// Act
		bool actual = pCut->PullARandomPearl();

		// Assert
		Assert::IsTrue(actual);
		Assert::IsTrue((pCut->ElectedPearl() != 0));

		int number = pCut->ElectedPearl();
		Assert::IsTrue((pCut->PearlIsInMug(number) == false));
		
		// Teardown
		delete pCut;
	}


	TEST_METHOD(PullPearl_1) {
		// Arrange
		Mug* pCut = nullptr;
		pCut = new Mug(0, 3);

		int pearl = 1;

		// Act
		bool actual = pCut->PullAPearl(pearl);

		// Assert
		Assert::IsTrue(actual);
		Assert::IsTrue((pCut->ElectedPearl() != 0));

		int number = pCut->ElectedPearl();
		Assert::IsTrue((pCut->PearlIsInMug(number) == false));

		Assert::AreEqual(number, pearl);

		// Teardown
		delete pCut;
	}

	TEST_METHOD(PullPearl_0) {
		// Arrange
		Mug* pCut = nullptr;
		pCut = new Mug(0, 3);

		int pearl = 0;

		// Act
		bool actual = pCut->PullAPearl(pearl);

		// Assert
		Assert::IsFalse(actual);

		// Teardown
		delete pCut;
	}


	TEST_METHOD(PullPearl_4) {
		// Arrange
		Mug* pCut = nullptr;
		pCut = new Mug(0, 3);

		int pearl = 4;

		// Act
		bool actual = pCut->PullAPearl(pearl);

		// Assert
		Assert::IsFalse(actual);

		// Teardown
		delete pCut;
	}

	TEST_METHOD(PullPearl_3) {
		// Arrange
		Mug* pCut = nullptr;
		pCut = new Mug(0, 3);

		int pearl = 3;
		pCut->PullAPearl(pearl);

		// Act
		// The number three is allready away...
		bool actual = pCut->PullAPearl(pearl);

		// Assert
		Assert::IsFalse(actual);

		// Teardown
		delete pCut;
	}

	TEST_METHOD(PushPearlBackToMug) {
		// Arrange
		Mug* pCut = nullptr;
		pCut = new Mug(0, 3);

		int pearl = 3;
		pCut->PullAPearl(pearl);

		// Act		
		bool actual = pCut->PushPearlBackToMug();

		// Assert
		Assert::IsTrue(pCut->ElectedPearl() == 0);

		// Teardown
		delete pCut;
	}

	};
}
