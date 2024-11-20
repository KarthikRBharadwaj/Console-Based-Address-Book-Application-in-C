#include <stdio.h>
#include<string.h>
#include "file.h"
//To save the contacts to file
void saveContactsToFile(AddressBook *addressBook) 
{
    // Sort contacts alphabetically before saving
    sorting_contacts(addressBook);
    
    FILE *fp; // File pointer
    fp = fopen("contacts.csv", "w"); // Save to CSV file
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    // Loop through each contact and write to file in CSV format
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        // Write the contacts in CSV format: name,phone,email
        fprintf(fp, "%s,%s,%s\n", 
                addressBook->contacts[i].name, 
                addressBook->contacts[i].phone, 
                addressBook->contacts[i].email);
    }

    fclose(fp); // Close the file after saving
    printf("Contacts saved successfully to file.\n");
}
//To load the contents to the file
void loadContactsFromFile(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    
    FILE *fp = fopen("contacts.csv", "r"); // Open file for reading
    if (fp == NULL) 
    {
        printf("No contacts found, or file could not be opened.\n");
        return;
    }
    
    // Loop to read the contacts from the file in CSV format
    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n", 
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3) 
    {
        addressBook->contactCount++;
    }

    fclose(fp); // Close the file after reading
    //printf("Contacts loaded successfully from file.\n");
}

