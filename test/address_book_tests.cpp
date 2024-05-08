#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "address_book.hpp"

TEST_CASE("entries can be added and removed") {
	address_book ab;
	CHECK_FALSE(ab.has_entry("Jane Doe"));
	ab.add_entry("Jane Doe");
	CHECK(ab.has_entry("Jane Doe"));
	ab.remove_entry("Jane Doe");
	CHECK_FALSE(ab.has_entry("Jane Doe"));
}

TEST_CASE("attempting to add an entry with a name violating these restrictions throws an exception'") {
	address_book ab;
	CHECK_THROWS_WITH(ab.add_entry("mynameismorethan100characterslong_mynameismorethan100characterslong_mynameismorethan100characterslong"), "Name too long");
}

TEST_CASE("get_entries returns a list of all entries, sorted alphabetically'") {
	address_book ab;
	ab.add_entry("B");
	ab.add_entry("A");
	CHECK(ab.get_entries()[0] == "A");
}

TEST_CASE("get_entries names returned by the address book have the first letter of each word capitalized'") {
	address_book ab;
	ab.add_entry("bbbb");
	CHECK(ab.get_entries()[0] == "Bbbb");
}