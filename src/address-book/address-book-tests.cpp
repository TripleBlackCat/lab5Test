#include <stdio.h>
#include "address-book.h"
#include "person.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Copy shares no state with original")
{
	Person firstPerson{"Iordan",21};
	AddressBookEntry originalEntry{firstPerson,"IordanFace"};
	AddressBookEntry copyEntry{originalEntry};

    CHECK(originalEntry.getImageName() == copyEntry.getImageName());
    
    Person secondPerson{"Kavi",23};
    originalEntry.setPerson(secondPerson);
    originalEntry.setImageName("KaviFace");
        
	CHECK(originalEntry.getPerson().name() != copyEntry.getPerson().name());
	CHECK(originalEntry.getPerson().age() != copyEntry.getPerson().age());
    CHECK(originalEntry.getImageName() != copyEntry.getImageName());
}
