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

TEST_CASE("After assignment objects are still independent")
{
    Person firstPerson{"Iordan",21};
	AddressBookEntry originalEntry{firstPerson,"IordanFace"};
	AddressBookEntry copyEntry{originalEntry};
    
    Person secondPerson{"Kavi",23};
    originalEntry.setPerson(secondPerson);
    originalEntry.setImageName("KaviFace");
    
    copyEntry = originalEntry;

    CHECK(originalEntry.getImageName() == copyEntry.getImageName());
    CHECK(originalEntry.getPerson().age() == copyEntry.getPerson().age());
    CHECK(originalEntry.getImageName() == copyEntry.getImageName());
    
    originalEntry.setPerson(firstPerson);
    originalEntry.setImageName("IordanFace");
    
    CHECK(originalEntry.getPerson().name() != copyEntry.getPerson().name());
	CHECK(originalEntry.getPerson().age() != copyEntry.getPerson().age());
    CHECK(originalEntry.getImageName() != copyEntry.getImageName());
    
    //This is the case because the image is a pointer, while the other members are not
}