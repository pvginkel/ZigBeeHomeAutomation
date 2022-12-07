#include "pch.h"
#include "CppUnitTest.h"

#include "src/ArrayList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(ArrayListTest) {
public:
	TEST_METHOD(Instantiate) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(2, (int)list.capacity());
	}

	TEST_METHOD(InstantiateWithCapacity) {
		ArrayList<int> list(4);

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
	}

	TEST_METHOD(SimpleAdd) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);

		Assert::AreEqual(1, (int)list.size());
		Assert::AreEqual(42, list[0]);
	}

	TEST_METHOD(AddMultiple) {
		ArrayList<int> list(4);

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		Assert::AreEqual(4, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
		Assert::AreEqual(45, list[3]);
	}

	TEST_METHOD(AddWithResize) {
		ArrayList<int> list(2);

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(2, (int)list.capacity());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		Assert::AreEqual(4, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
		Assert::AreEqual(45, list[3]);
	}

	TEST_METHOD(InsertStart) {
		ArrayList<int> list(2);

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(2, (int)list.capacity());

		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.insert(0, 42);

		Assert::IsTrue(result);
		Assert::AreEqual(4, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
		Assert::AreEqual(45, list[3]);
	}

	TEST_METHOD(InsertMiddle) {
		ArrayList<int> list(2);

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(2, (int)list.capacity());

		list.add(42);
		list.add(44);
		list.add(45);

		bool result = list.insert(1, 43);

		Assert::IsTrue(result);
		Assert::AreEqual(4, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
		Assert::AreEqual(45, list[3]);
	}

	TEST_METHOD(InsertEnd) {
		ArrayList<int> list(2);

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(2, (int)list.capacity());

		list.add(42);
		list.add(43);
		list.add(44);

		bool result = list.insert(3, 45);

		Assert::IsTrue(result);
		Assert::AreEqual(4, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
		Assert::AreEqual(45, list[3]);
	}

	TEST_METHOD(RemoveAtStart) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.removeAt(0);

		Assert::IsTrue(result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(43, list[0]);
		Assert::AreEqual(44, list[1]);
		Assert::AreEqual(45, list[2]);
	}

	TEST_METHOD(RemoveAtMiddle) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.removeAt(1);

		Assert::IsTrue(result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(44, list[1]);
		Assert::AreEqual(45, list[2]);
	}

	TEST_METHOD(RemoveAtEnd) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.removeAt(3);

		Assert::IsTrue(result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
	}

	TEST_METHOD(RemoveBeyondEnd) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.removeAt(99);

		Assert::IsFalse(result);
		Assert::AreEqual(4, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
		Assert::AreEqual(45, list[3]);
	}

	TEST_METHOD(RemoveStart) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		auto result = list.remove(0);

		Assert::AreEqual(42, result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(43, list[0]);
		Assert::AreEqual(44, list[1]);
		Assert::AreEqual(45, list[2]);
	}

	TEST_METHOD(RemoveMiddle) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		auto result = list.remove(1);

		Assert::AreEqual(43, result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(44, list[1]);
		Assert::AreEqual(45, list[2]);
	}

	TEST_METHOD(RemoveEnd) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		auto result = list.remove(3);

		Assert::AreEqual(45, result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
	}

	TEST_METHOD(Iterate) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		auto index = 0;

		for (auto v : list) {
			switch (index++) {
				case 0: Assert::AreEqual(42, v); break;
				case 1: Assert::AreEqual(43, v); break;
				case 2: Assert::AreEqual(44, v); break;
				case 3: Assert::AreEqual(45, v); break;
				default: Assert::Fail();
			}
		}

		Assert::AreEqual(4, index);
	}

	TEST_METHOD(IterateEmpty) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		auto index = 0;

		for (auto v : list) {
			switch (index++) {
			default: Assert::Fail();
			}
		}

		Assert::AreEqual(0, index);
	}

	TEST_METHOD(Replace) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		list[1] = 59;
		list[2]++;

		Assert::AreEqual(4, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(59, list[1]);
		Assert::AreEqual(45, list[2]);
		Assert::AreEqual(45, list[3]);
	}

	TEST_METHOD(Clear) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		list.clear();

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
	}
};
