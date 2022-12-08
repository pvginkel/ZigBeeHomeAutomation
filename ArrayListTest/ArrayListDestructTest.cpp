#include "pch.h"
#include "CppUnitTest.h"

#include "src/ArrayList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Destructable {
public:
	static int constructs;
	static int destructs;
	static int overwrites;
	static int live;

	static void reset() {
		constructs = 0;
		destructs = 0;
		overwrites = 0;
		live = 0;
	}

	Destructable() {
		constructs++;
		live++;
	}

	Destructable(const Destructable& other) {
		constructs++;
		live++;
	}

	Destructable(Destructable&&) = delete;

	~Destructable() {
		destructs++;
		live--;
	}

	Destructable& operator=(const Destructable&) {
		overwrites++;
		return *this;
	}
	Destructable& operator=(Destructable&&) noexcept {
		overwrites++;
		return *this;
	}
};

int Destructable::constructs = 0;
int Destructable::destructs = 0;
int Destructable::overwrites = 0;
int Destructable::live = 0;

TEST_CLASS(ArrayListDestructTest) {
public:
	TEST_METHOD_INITIALIZE(initialize) {
		Destructable::reset();
	}

	void assert(int constructs, int destructs, int overwrites, int live) {
		assertConstructs(constructs);
		assertDestructs(destructs);
		assertOverwrites(overwrites);
		assertLive(live);
	}

	void assertConstructs(int constructs) {
		Assert::AreEqual(constructs, Destructable::constructs, L"Unexpected constructs");
	}

	void assertDestructs(int destructs) {
		Assert::AreEqual(destructs, Destructable::destructs, L"Unexpected destructs");
	}

	void assertOverwrites(int overwrites) {
		Assert::AreEqual(overwrites, Destructable::overwrites, L"Unexpected overwrites");
	}

	void assertLive(int live) {
		Assert::AreEqual(live, Destructable::live, L"Unexpected live");
	}

	TEST_METHOD(simpleDestructable) {
		{
			Destructable destructable;

			assert(1, 0, 0, 1);
		}

		assert(1, 1, 0, 0);
	}

	TEST_METHOD(addWillCopy) {
		{
			ArrayList<Destructable> list;

			list.add(Destructable());

			assertConstructs(2);
		}
	}

	TEST_METHOD(listWillDelete) {
		{
			ArrayList<Destructable> list;

			list.add(Destructable());
		}

		assert(2, 2, 0, 0);
		assertLive(0);
	}

	TEST_METHOD(removeWillDelete) {
		{
			ArrayList<Destructable> list;

			list.add(Destructable());

			assert(2, 1, 0, 1);

			list.removeAt(0);

			assert(2, 2, 0, 0);
		}
	}

	TEST_METHOD(assignDestructs) {
		{
			ArrayList<Destructable> list;

			list.add(Destructable());

			// Constructed and destructed the temporary, and constructed the array element.
			assert(2, 1, 0, 1);

			list[0] = Destructable();

			// Constructed and destructed the temporary, and one overwrite.
			assert(3, 2, 1, 1);
		}

		// Destructed the element still in the list.
		assert(3, 3, 1, 0);
	}
};
