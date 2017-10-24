#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("No State Sharing between object and its copy")
{
	Date originalDate{22,Month::December,2003};
	Date copyDate{originalDate};
	
	CHECK(originalDate == copyDate);
	
	originalDate.increaseDay();
	
	CHECK(originalDate.day() == 23);
	CHECK(copyDate.day() == 22);
	
	CHECK(originalDate.month() == copyDate.month());
	CHECK(originalDate.year() == copyDate.year());
	
	CHECK_FALSE(originalDate == copyDate);
}
