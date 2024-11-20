#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

//Creating a contact structure
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

//Creating array of contacts structure
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

//Function declaration for creating contact
void createContact(AddressBook *addressBook);

//Function declaration for searching the contact
void searchContact(AddressBook *addressBook);

//Function declaration for editing the contacts
void editContact(AddressBook *addressBook);

//Function declaration for Deleting the contacts
void deleteContact(AddressBook *addressBook);


//Function declaration for list all the contacts
void listContacts(AddressBook *addressBook);

//Function declaration for initialize the contacts to the structure
void loadContactsFromFile(AddressBook *addressBook);

void sorting_contacts(AddressBook *AddressBook);

//void saveContactsToFile(AddressBook *AddressBook);
void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook) ;
#endif
