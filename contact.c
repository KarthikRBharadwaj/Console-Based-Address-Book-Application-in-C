/*
Name : Karthik R Bharadwaj
Date : 09-10-2024
Description : To develop an AddressBook which is used to create,display,edit,delete and list the contacts*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include<ctype.h>

int validate_name(AddressBook *addressBook,char *name)
{
    //STEP1: Fetch one by one character till null character
    for(int i=0;name[i] != '\0';i++)
    {
        if(!(isalpha(name[i])) && name[i]!=' ')
        {
            return 1;
            //STEP2: Check the character is alphabet ot not
            //Yes->Move to next character,N0->stop the process
        }
    }
   return 0; 
}
int validate_phoneno(AddressBook *addressBook,char *phoneno)
{
    int length = strlen(phoneno);
    if (length != 10) //Number should be equal to 10
    {
        printf("Invalid phone number: Phone number must be exactly 10 digits long.\n");
        return 0;
    }
    for (int i = 0; i < length; i++) 
    {
        if (phoneno[i] < '0' || phoneno[i] > '9') {//only numbers should be read
            printf("Invalid phone number: Phone number must contain only digits.\n");
            return 0;
        }
    }
    //STEP4:Validate the mobile number -> Digit & 10 Digits
    //True -> goto STEP5,False -> print error,goto STEP3
    
    /*If the phone number is not found in the dummyContacts,
     the function then checks the AddressBook, which contains the contacts added dynamically by the user.*/
     for(int i = 0; i < addressBook->contactCount; i++) 
     {
        if (strcmp(addressBook->contacts[i].phone, phoneno) == 0)//if the number is there try another number
         {
            printf("Phone number already exists in the Address Book \n");
            return 0; 
         }
     }
    return 1; 
}
//STEP6: validate the email_Id -> @gmail.com & unique
//True -> goto STEP7,False -> print error,goto STEP5
int validate_email(AddressBook *addressBook,char *emailid)
{
    if(!strstr(emailid,"@gmail.com"))//the mail should be ended with @gmail.com always
    {
        printf("Invalid Email adress,Please try again.");
        return 0;
    }
    for(int i=0;i<addressBook->contactCount;i++)//if exist other mail should be entered
    {
        if(strcmp(addressBook->contacts[i].email,emailid) == 0)
        {
        printf("Email Id already exists in Address Book\n");
        return 0;
        }
    }
    return 1;
}
    //1 -> Name
    //read name
    //search the entered name is present in the database or not
    //present -> print the details of the contact  ,no-> print error message, goto step1
void name2_display1(AddressBook *addressBook,int *flag)
{ 
    char name2[50];
    printf("Enter the name : ");
    scanf(" %[^\n]",name2);
    for(int i=0;i<addressBook->contactCount;i++)
    {

        if(strcasestr(addressBook->contacts[i].name,name2) != NULL)//if contacts found display the details
        {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            *flag = 1;
        }
    }
    if(*flag == 0)
    printf("Contacts Details not found. Please try again.\n");//if not found print error message
}
    //2 Mobile no
    //read the mobile no
    //search the entered number is present in the database or not
    //present -> print the details of the contact  ,no-> print error message, goto step1
void phoneno2_display2(AddressBook *addressBook,int *flag)
{ 
    char phoneno1[50];
    printf("Enter the phone number : ");
    scanf(" %[^\n]",phoneno1);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcasestr(addressBook->contacts[i].phone,phoneno1) != NULL)//if contacts found display the details
        {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            *flag = 1;
        }
    }
    if(*flag == 0)
    printf("Contacts Details not found. Please try again.\n");//if not found print error message
}
    //3 emailid
    //search the entered email id is present in the database or not
    //present -> print the details of the contact  ,no-> print error message, goto step1
void emaildid2_display3(AddressBook *addressBook,int *flag)
{ 
    char emailid1[20];
    printf("Enter the Email Id : ");
    scanf(" %[^\n]",emailid1);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcasestr(addressBook->contacts[i].email,emailid1) != NULL)//if contacts found print the display
        {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            *flag = 1;
        }
    }
    if(*flag == 0)
    printf("Contacts Details not found. Please try again.\n");//if not found print error message
}
//If edit is wrt name
void edit_name(AddressBook *addressBook)
{
    char newname[50];
    char oldname[50];
    printf("Enter the Old name :");
    scanf(" %[^\n]",oldname);
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
    if (strcasecmp(addressBook->contacts[i].name, oldname) == 0)//if old name found go for editing
    {
        printf("Enter the new Name : ");
        scanf(" %[^\n]",newname); 
        if(validate_name(addressBook,newname)==0)//validate its in proper order
        {
        strcpy(addressBook->contacts[i].name, newname);//Replace newname with old name
        printf("Name updated from %s to %s successfully.\n",oldname,newname);
        return;
        }
        else
        {
            printf("Please enter the name in correct format");
        }
    }
    }
}
//If edit is wrt to phone number
void edit_phoneno(AddressBook *addressBook)
{
    char newphone[50];
    char oldphone[50];

    printf("Enter the Old Phone Number: ");
    scanf(" %[^\n]", oldphone);

    // Search for the old phone number in the contacts
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcasecmp(addressBook->contacts[i].phone, oldphone) == 0) 
        {
            printf("Enter the New Phone Number: ");
            scanf(" %[^\n]", newphone); 

            // Validate the new phone number for uniqueness and proper format
            if (validate_phoneno(addressBook, newphone)) 
            {
                strcpy(addressBook->contacts[i].phone, newphone);
                printf("Phone number updated from %s to %s successfully.\n", oldphone, newphone);
                return;
            }
            else 
            {
                printf("Phone number not updated. New phone number is invalid or already exists.\n");
            }
        }
    }
}


//if edit is wrt email id
void edit_emailid(AddressBook *addressBook)
{
    char newemail[50];
    char oldemail[50];

    printf("Enter the Old Email Id: ");
    scanf(" %[^\n]", oldemail);

    // Search for the old email in the contacts
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcasecmp(addressBook->contacts[i].email, oldemail) == 0) 
        {
            printf("Enter the New Email Id: ");
            scanf(" %[^\n]", newemail); 

            // Validate the new email for format and uniqueness
            if (validate_email(addressBook, newemail)) 
            {
                strcpy(addressBook->contacts[i].email, newemail);
                printf("Email ID updated from %s to %s successfully.\n", oldemail, newemail);
                return;
            }
            else 
            {
                printf("Email ID not updated. New email is invalid or already exists.\n");
            }
        }
    }
}


void createContact(AddressBook* addressBook)
{
    char name1[50];
    int i;
    //STEP1:Read a name from user
    printf("Enter the name : ");
    scanf(" %[^\n]",name1);
    //STEP2:Validate the name -> Alphabets
    while(validate_name(addressBook,name1)==1)
    {
        printf("INFO: Name validation not done, Please enter valid name...\n");
        printf("Enter the name : ");
        scanf(" %[^\n]",name1);
        //True -> goto STEP3,False -> print error,goto STEP1
    }
    //Step3:Read a mobile number from user
    char phoneno[20];
    printf("Enter the mobile number : ");
    scanf(" %[^\n]",phoneno);
    while(validate_phoneno(addressBook,phoneno)==0)
    {
        printf("INFO: Mobile number validation not done, Please enter valid mobile number...\n");
        printf("Enter the mobile number : ");
        scanf(" %[^\n]",phoneno);   
    }
    //STEP5:Read a email id from user
    char emailid[50];
    printf("Enter the Email Id : ");
    scanf(" %[^\n]",emailid);
    while(validate_email(addressBook,emailid)==0)
    {
        
        printf("INFO: Email validation not done, Please enter valid email...\n");
        printf("Enter the Enter the Email Id : ");
        scanf(" %[^\n]",emailid);
    }
    //STEP7:store into structure[contact_count]
    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }
    strcpy(addressBook->contacts[addressBook->contactCount].name, name1);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phoneno);
    strcpy(addressBook->contacts[addressBook->contactCount].email, emailid);
    addressBook->contactCount++;
    printf("Contact created...");
}
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    //step1: print the menu based on what searching
    //step2: choose the menu
    int choice,flag=0;
    printf("Search the conacts by\n");
    printf("1.Name \n");
    printf("2.Mobile number\n");
    printf("3.Email Id\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:name2_display1(addressBook,&flag);
    break;
    case 2:phoneno2_display2(addressBook,&flag);
    break;
    case 3:emaildid2_display3(addressBook,&flag);
    break;
    default:printf("Invalid choice....");
    }
}
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice,flag=0;
    while(1)
    {
    printf("Search the contacts by\n");
    printf("1. Name\n");
    printf("2. Mobile Number\n");
    printf("3. Email Id\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:name2_display1(addressBook,&flag);
        break;
        case 2:phoneno2_display2(addressBook,&flag);
        break;
        case 3:emaildid2_display3(addressBook,&flag);
        break;
        default:printf("Invalid choice....");
        continue;
    }
    if(flag != 0)
    break;
    }
    //Please select on what are you going to edit
    //1. name
    //2. mobile no
    //3. email
    int choice1;
        printf("\nWhat would you like to edit?\n");
        printf("1. Name\n");
        printf("2. Mobile Number\n");
        printf("3. Email\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);
    switch(choice1)
    {
        case 1:edit_name(addressBook);
        break;
        case 2:edit_phoneno(addressBook);
        break;
        case 3:edit_emailid(addressBook);
        break;
        default:printf("Invalid choice Thank You...");
    }
}
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int choice,flag=0;
    while(1)
    {
    printf("Search the contacts by\n");
    printf("1. Name\n");
    printf("2. Mobile Number\n");
    printf("3. Email Id\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:name2_display1(addressBook,&flag);
        break;
        case 2:phoneno2_display2(addressBook,&flag);
        break;
        case 3:emaildid2_display3(addressBook,&flag);
        break;
        default:printf("Invalid choice....");
        continue;
    }
    if(flag != 0)
    break;
    }
    int choice1,x=-1,i;
    char del[50];
    printf("Delete the contats by\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.Email Id\n");
    printf("Enter your choice : ");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:printf("Enter the Name : ");
        scanf(" %[^\n]",del);
        for(i=0;i<addressBook->contactCount;i++)
        {
            if(strcasecmp(addressBook->contacts[i].name,del)==0)//compare to check if name is present or not
            {
                x=i;//if found return its addrress
                break;
            }
        }
            break;
            case 2:printf("Enter the Phone Number : ");
            scanf(" %[^\n]",del);
            for(i=0;i<addressBook->contactCount;i++)
            {
            if(strcasecmp(addressBook->contacts[i].phone,del)==0)//compare to check if phone number is present or not
            {
                x=i;//if found return its address
                break;
            }
            }
            break;
            case 3:printf("Enter the Email Id : ");
            scanf(" %[^\n]",del);
            for(i=0;i<addressBook->contactCount;i++)
            {
            if(strcasecmp(addressBook->contacts[i].email,del)==0)//compare to check if emaid id is present or not
            {
                x=i;//if found return its address
                break;
            }
            }
            break;
            default :printf("Inavlid choice...");
            return;
        }
        if (x != -1) {
        // Shift the contacts up one position to remove the contact
        for (int i = x; i < addressBook->contactCount - 1; i++) 
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        // Decrement contact count
        addressBook->contactCount--;
        printf("Contact deleted successfully.\n");
         } 
        else
        {
            printf("Contact not found.\n");
        }
}
void sorting_contacts(AddressBook *addressBook)//to arranmge in alphabetical order
{
    for (int i = 0; i < addressBook->contactCount - 1; i++) 
    {
        for (int j = 0; j < addressBook->contactCount - i - 1; j++) 
        {
            if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) 
            {
                // Swap the contacts if they are in the wrong order
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
}
void listContacts(AddressBook *addressBook) 
{
    printf("Number of contacts: %d\n", addressBook->contactCount);  // Check contact count

    // Check if the sorting is happening correctly
    sorting_contacts(addressBook);
    
    // Debug output before the loop
    printf("Listing contacts...\n");
    
    // Print each contact in a simplified way for debugging
    for(int i = 0; i < addressBook->contactCount; i++) 
    {
        printf("Contact %d: Name: %s, Phone: %s, Email: %s\n", 
               i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}

