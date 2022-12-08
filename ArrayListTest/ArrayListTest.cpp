#include "pch.h"
#include "CppUnitTest.h"

#include "src/ArrayList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(ArrayListTest) {
public:
	TEST_METHOD(instantiate) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(2, (int)list.capacity());
	}

	TEST_METHOD(instantiateWithCapacity) {
		ArrayList<int> list(4);

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
	}

	TEST_METHOD(simpleAdd) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);

		Assert::AreEqual(1, (int)list.size());
		Assert::AreEqual(42, list[0]);
	}

	TEST_METHOD(addMultiple) {
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

	TEST_METHOD(addWithResize) {
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

	TEST_METHOD(insertStart) {
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

	TEST_METHOD(insertMiddle) {
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

	TEST_METHOD(insertEnd) {
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

	TEST_METHOD(removeAtStart) {
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

	TEST_METHOD(removeAtMiddle) {
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

	TEST_METHOD(removeAtEnd) {
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

	TEST_METHOD(removeStart) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.remove(42);

		Assert::IsTrue(result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(43, list[0]);
		Assert::AreEqual(44, list[1]);
		Assert::AreEqual(45, list[2]);
	}

	TEST_METHOD(removeMiddle) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.remove(43);

		Assert::IsTrue(result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(44, list[1]);
		Assert::AreEqual(45, list[2]);
	}

	TEST_METHOD(removeEnd) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.remove(45);

		Assert::IsTrue(result);
		Assert::AreEqual(3, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
	}

	TEST_METHOD(removeNonExisting) {
		ArrayList<int> list;

		Assert::AreEqual(0, (int)list.size());

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		bool result = list.remove(49);

		Assert::IsFalse(result);
		Assert::AreEqual(4, (int)list.size());
		Assert::AreEqual(42, list[0]);
		Assert::AreEqual(43, list[1]);
		Assert::AreEqual(44, list[2]);
		Assert::AreEqual(45, list[3]);
	}

	TEST_METHOD(iterate) {
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

	TEST_METHOD(iterateEmpty) {
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

	TEST_METHOD(replace) {
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

	TEST_METHOD(clear) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		list.clear();

		Assert::AreEqual(0, (int)list.size());
		Assert::AreEqual(4, (int)list.capacity());
	}

	TEST_METHOD(indexExisting) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		Assert::AreEqual(1, list.indexOf(43));
	}

	TEST_METHOD(indexWithDuplicatesExisting) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(43);
		list.add(45);

		Assert::AreEqual(1, list.indexOf(43));
	}

	TEST_METHOD(indexNonExisting) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		Assert::AreEqual(-1, list.indexOf(49));
	}

	TEST_METHOD(lastIndexExisting) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		Assert::AreEqual(1, list.lastIndexOf(43));
	}

	TEST_METHOD(lastIndexWithDuplicatesExisting) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(43);
		list.add(45);

		Assert::AreEqual(2, list.lastIndexOf(43));
	}

	TEST_METHOD(lastIndexNonExisting) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		Assert::AreEqual(-1, list.lastIndexOf(49));
	}

	TEST_METHOD(containsExisting) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		Assert::IsTrue(list.contains(43));
	}

	TEST_METHOD(containsNonExisting) {
		ArrayList<int> list;

		list.add(42);
		list.add(43);
		list.add(44);
		list.add(45);

		Assert::IsFalse(list.contains(49));
	}
};
