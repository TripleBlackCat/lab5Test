// address_book.cpp
// Implementation of the AddressBookEntry class
#include "address-book.h"
#include <memory>
#include <algorithm>
using std::make_unique;

// AddressBookEntry Constructor
AddressBookEntry::AddressBookEntry(	const Person& person,
								   const string& image_filename)
								   :_person(person)
{
	// dynamically allocate memory for the image
	if (image_filename != "") {
		// ignore (for now) what will happen if there is a memory allocation failure
        _image_ptr = make_unique<Image>(image_filename);
	}
}

string AddressBookEntry::getImageName() const
{
	if (_image_ptr != nullptr)
		return _image_ptr->name();
	else return "No image!";
}

void AddressBookEntry::setImageName(string newname)
{
	if (_image_ptr != nullptr) _image_ptr->name(newname);
}

AddressBookEntry::AddressBookEntry(const AddressBookEntry& rhs) :
    _person{rhs.getPerson()}
{ 
    if (rhs._image_ptr != nullptr) _image_ptr = make_unique<Image>(*rhs._image_ptr);
}

AddressBookEntry& AddressBookEntry::operator=(const AddressBookEntry& rhs)
{
    AddressBookEntry temp(rhs);
    swap(temp);
    return *this;
}

void AddressBookEntry::swap(AddressBookEntry& newObject)
{
    std::swap(newObject._person,_person);
    std::swap(newObject._image_ptr,_image_ptr);
}

//This assignment is not an atomic operation because the object Person gets assigned, in which the object itself
//may not have atomic assignment, which may result in only some of its fields being assigned and others not, but
//still passing through. This affects the atomic assignment of the AddressBookEntry, making it not atomic. The
//correct error checks are also not implemented.