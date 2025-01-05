/*************************************************************
                   UMP FOC STUDENT DATABASE
                        Beta Version
            Last Update : All Requirement Fullfill
**************************************************************/



#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>


//=================================\\
//                                 \\
//      Structure Declaration      \\
//                                 \\
//=================================\\

struct BirthInfo{

    int day, month, year;
    char birthplace[30];

};

//------------------------

struct ContactInfo{

    char email[30], facebook[30], phoneNum[12];

};

//------------------------

struct AddressInfo{

    char PermanentAddress[100], CurrentAddress[100];

};

//------------------------

struct FinancialInfo{

    int income;
    char scholarship[5];

};

//------------------------

struct OtherInfo{

    char religion[15], race[15], nationality[15], maritalStatus[15];

};

//------------------------

struct Student
{
	char name[50],MatricID[10], gender[6], course[40], IC[14];
	struct BirthInfo birth;
	struct ContactInfo contact;
	struct AddressInfo address;
	struct FinancialInfo financial;
	struct OtherInfo other;
	struct Student *ptrnext;
};

//------------------------

//--------pointer that can point to a node-----------

struct Student *headptr, *newptr, *currentptr, *previousptr, *delNode;


//---------------------------------------------------------------------------------------------------------


//=================================\\
//                                 \\
//       Function Declaration      \\
//                                 \\
//=================================\\

//------display Menu Function------
void Menu();
void SubMenu_B();
void SubMenu_C();

//------------Function-------------
void CreateNewData();
void EnterData();
void displayData();
void searchData();
void data();
void updateData();
void delete_data();
void sortingData();
void SwapData(struct Student *A, struct Student *B);
void deleteData();
void dataTable();


//---------------------------------------------------------------------------------------------------------


//=================================\\
//                                 \\
//          Main Function          \\
//                                 \\
//=================================\\


int main(){

    //Main Variable
    char MainMenu, Sub_B, Sub_C;
    //int StudCounter = 0;
    //readPreEnterData();
    //Main Menu Loop
    bool MainOption = false, SubB_Option = false, SubC_Option = false;
    while(MainOption == false){

        system("cls");
        Menu();//display Main Menu
        scanf(" %[^\n]s", &MainMenu);

        switch(toupper(MainMenu)){

        //Create New Data Option
        case'A':
            system("cls");
            CreateNewData();
            printf("\n\n----> Insert Data Success");
            printf("\n\n  Press Any Key to Continue.");
            getch();
            break;

        //Manage Existing Data Option
        case'B':
            while(SubB_Option == false){
                system("cls");
                SubMenu_B();//display B option
                scanf(" %[^\n]s", &Sub_B);

                switch(toupper(Sub_B)){

                case'A':
                    updateData();
                    break;
                case'B':
                    deleteData();
                    break;
                case'C':
                    SubB_Option = true;
                    break;
                default:
                    printf("\n---->Invalid Option, Please Enter Right Option !");
                    printf("\n\n  Press Any Key to Continue.");
                    getch();
                }
            }
            SubB_Option = false;//reset value
            break;

        //Display Data Option
        case'C':
            while(SubC_Option == false){
                system("cls");
                SubMenu_C();//display C option
                scanf(" %[^\n]s", &Sub_C);

                switch(toupper(Sub_C)){

                case'A':
                    system("cls");
                    displayData();
                    break;
                case'B':
                    searchData();
                    break;
                case'C':
                    SubC_Option = true;
                    break;
                default:
                    printf("\n---->Invalid Option, Please Enter Right Option !");
                    printf("\n\n  Press Any Key to Continue.");
					getch();
                }
            }
            SubC_Option = false;//reset value
            break;

        //Exit System Option
        case'D':
            MainOption = true;//change value to exit loop
            printf("\n\n  Thank you for using this program");
            int smile=1;
            printf("\n  Have a nice day %c\n\n\n", smile);
            break;

        //Invalid Option
        default:
            printf("\n---->Invalid Option, Please Enter Right Option !\n");
            printf("\n\n  Press Any Key to Continue.");
			getch();
        }
    }


    return 0;
}


//---------------------------------------------------------------------------------------------------------


//=================================\\
//                                 \\
//       Function Definition       \\
//                                 \\
//=================================\\


void Menu(){

    printf("\n--------------------------------------------------------------------\n");
	printf("\tUMP Faculty Of Computing Students Database Management");
    printf("\n--------------------------------------------------------------------\n");
    printf("\n   A\t-\tAdd New Student\n");
    printf("\n   B\t-\tManage Existing Data\n");
    printf("\n   C\t-\tDisplay Data\n");
    printf("\n   D\t-\tExit System");
    printf("\n\nEnter Option : ");

}


//---------------------------------------------------------------------------------------------------------


void SubMenu_B(){

    printf("\n     Manage Existing Data");
    printf("\n    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
    printf("\n    A  -  Update Existing Data");
    printf("\n    B  -  Delete Data");
    printf("\n    C  -  Back To Main Menu");
    printf("\n\n      Enter Option : ");

}


//---------------------------------------------------------------------------------------------------------


void SubMenu_C(){

    printf("\n      Display Data");
    printf("\n     ¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
    printf("\n    A  -  Display All Data");
    printf("\n    B  -  Search Data");
    printf("\n    C  -  Back To Main Menu");
    printf("\n\n      Enter Option : ");

}


//---------------------------------------------------------------------------------------------------------


void CreateNewData(){

    newptr=(struct Student *)malloc(sizeof (struct Student));

    EnterData();

    if (headptr==NULL){
        headptr=newptr;
        newptr->ptrnext=NULL;
    }
    else{
        newptr->ptrnext=headptr;
        headptr=newptr;
    }
}


//---------------------------------------------------------------------------------------------------------


void EnterData(){

    int ChooseCourse, address;

    printf("\n\tPersonal  Information\n======================================");
    printf("\n\n Enter a name (Format: String) : ");
    scanf(" %[^\n]s",&newptr->name);

	printf("\n---------------------------------------\n");
    printf("\n\t<< Course >>\n");
    printf("\n   1.   Computer Systems & Networking");
    printf("\n   2.   Software Engineering");
    printf("\n   3.   Graphics & Multimedia Technology\n");

    do{

        printf("\n Choose course (Format: 1/2/3): ");
        scanf(" %d",&ChooseCourse);

        if(ChooseCourse == 1){
            strcpy(newptr->course,"Computer Systems & Networking");
        }
        else if(ChooseCourse == 2){
            strcpy(newptr->course,"Software Engineering");
        }
        else if(ChooseCourse == 3){
            strcpy(newptr->course,"Graphics & Multimedia Technology");
        }
        else{
            printf("\n----> Invalid Option, Please Enter right Option\n");
        }

    }while(ChooseCourse >= 4);

    printf("\n---------------------------------------\n");
	printf("\n Enter a Matric ID (Example: CA21060) : ");
    scanf(" %[^\n]s",&newptr->MatricID);

    printf("\n---------------------------------------\n");
    printf("\n Enter IC No.\n (Example: 020111101831): ");
    scanf(" %[^\n]s",&newptr->IC);

    system("cls");
	printf("\n\tAddress  Information");
	printf("\n======================================\n");
    printf(" \n Enter Permanent Address (Format: String) :\n\n ");
    scanf(" %[^\n]s",&newptr->address.PermanentAddress);

    printf("\n---------------------------------------\n");

	do
	{
    	printf("\n Does the current address same as permanent address?\n (Format: 1 = YES/ 2 = NO): ");
    	scanf(" %d",&address);

		if(address == 1)
		{
     	    strcpy(newptr->address.CurrentAddress, newptr->address.PermanentAddress);
    	}
    	else if(address == 2)
		{
    	    printf("\n Enter Current Address (Format: String): \n\n ");
    	    scanf(" %[^\n]s",&newptr->address.CurrentAddress);
    	}
    	else
    	{
    		printf("\n --->Invalid Option, Please enter the correct Option\n");
		}

	}while(address >= 3);

    system("cls");
    printf("\n\tBirth Information");
    printf("\n======================================\n");
    printf("\n Enter Birth Day\n (Example: 28)\t\t: ");
    scanf(" %d",&newptr->birth.day);
    printf("\n Enter Birth Month\n (Example: 07)\t\t: ");
    scanf(" %d",&newptr->birth.month);
    printf("\n Enter Birth Year\n (Example: 2002)\t: ");
    scanf(" %d",&newptr->birth.year);
    printf("\n Enter Birth Place\n (Example: Selangor)\t: ");
    scanf(" %[^\n]s",&newptr->birth.birthplace);
    printf("\n Enter a Gender\n (Format: Male/Female)\t: ");
    scanf(" %[^\n]s",&newptr->gender);

    system("cls");
    printf("\n\tContact Information");
    printf("\n======================================\n");
    printf("\n Enter Phone No.\n (Example: 0147203059)\t\t  : ");
    scanf(" %[^\n]s",&newptr->contact.phoneNum);
    printf("\n Enter Email\n (Example: nazhanhaziq@gmail.com) : ");
    scanf(" %[^\n]s",&newptr->contact.email);
    printf("\n Enter Facebook\n (Example: Nazhan Haziq)\t  : ");
    scanf(" %[^\n]s",&newptr->contact.facebook);

    system("cls");
    printf("\n\tFinancial Information");
    printf("\n======================================\n");
    printf("\n Enter Income\n (Format: Float -> Example: 4500.50)\t: ");
    scanf(" %f",&newptr->financial.income);
    printf("\n Enter Scholarship Status\n (Format: YES/NO)\t\t\t: ");
    scanf(" %[^\n]s",&newptr->financial.scholarship);

    system("cls");
    printf("\n\tOther Information");
    printf("\n======================================\n");
    printf("\n Enter Nationality\n (Format: String -> Example: Malaysia)\t: ");
    scanf(" %[^\n]s",&newptr->other.nationality);
    printf("\n Enter Race\n (Format: String -> Example: Malay)\t: ");
    scanf(" %[^\n]s",&newptr->other.race);
    printf("\n Enter Religion\n (Format: String -> Example: Islam)\t: ");
    scanf(" %[^\n]s",&newptr->other.religion);
    printf("\n Enter Marital\n (Format: Married/Single)\t\t: ");
    scanf(" %[^\n]s",&newptr->other.maritalStatus);

}


//---------------------------------------------------------------------------------------------------------


void displayData(){

    int DataOption, count;
    char DisplayMenuOption;
    bool SubDisplayOption = false;

    if(headptr == NULL){
        system("cls");
        printf("---->Empty list");
        printf("\n\n  Press Any Key to Continue.");
        getch();
        return;
    }

    while(SubDisplayOption == false){

        //display information table
        system("cls");
        currentptr=headptr;
        dataTable();
        printf("\n\n\n            << OPTION >>");
        printf("\n __________________________________ ");
        printf("\n|   A. Sort the data               |");
        printf("\n|   B. Get Detail About Student    |");
        printf("\n|   C. Back                        |");
        printf("\n|__________________________________|");
        printf("\n\n\tChoose Option : ");
        scanf(" %[^\n]s",&DisplayMenuOption);


        switch(toupper(DisplayMenuOption)){

            case 'A':
                sortingData();
                break;

            case 'B':
                printf("\n\nChoose Number Based on Table Above\n (Press 0 to back): ");
                scanf("%d", &DataOption);

                if(DataOption != 0){
                    count = 0;
                    currentptr=headptr;
                    while(currentptr != NULL){

                        if(count == DataOption-1){

                            system("cls");
                            data();
                            printf("\n\n\n  Press Any Key to Continue . . . ");
							getch();
                        }
                        count++;
                        currentptr=currentptr->ptrnext;
                    }
                }
                break;

            case 'C':
                SubDisplayOption = true;
                break;

            default:
                printf("\n----> Invalid Option, Please Enter Right Option !\n");
                printf("\n\n  Press Any Key to Continue.");
				getch();
        }
    }
}


//---------------------------------------------------------------------------------------------------------


void searchData(){

    char IDnum[15];

    printf("\n Enter Student ID: ");
    scanf(" %[^\n]s",&IDnum);

    currentptr=headptr;
    while(currentptr != NULL){

        if(strcmp(IDnum, currentptr->MatricID) == 0){
            system("cls");
            data();
            printf("\n\n\n  Press Any Key to Continue . . . ");
			getch();
            return;
        }
        currentptr=currentptr->ptrnext;
    }

    printf("\n ---->No Record Found");
    printf("\n\n  Press Any Key to Continue.");
    getch();
}


//---------------------------------------------------------------------------------------------------------


void data(){

    printf("\n\n+------------------------+");
	printf("\n|  Personal Information  |");
	printf("\n+------------------------+");
    printf("\n Student ID        : %s",currentptr->MatricID);
    printf("\n Name              : %s",currentptr->name);
    printf("\n Course            : %s",currentptr->course);
    printf("\n IC No             : %s",currentptr->IC);

    printf("\n\n+------------------------+");
	printf("\n|   Address Information  |");
	printf("\n+------------------------+");
    printf("\n Permanent Address : %s",currentptr->address.PermanentAddress);
    printf("\n Current Address   : %s",currentptr->address.CurrentAddress);

    printf("\n\n+------------------------+");
	printf("\n|    Birth Information   |");
	printf("\n+------------------------+");
    printf("\n Birthday          : %d/%d/%d",currentptr->birth.day, currentptr->birth.month, currentptr->birth.year);
    printf("\n Birth Place       : %s", currentptr->birth.birthplace);
    printf("\n Gender            : %s", currentptr->gender);

    printf("\n\n+------------------------+");
	printf("\n|   Contact Information  |");
	printf("\n+------------------------+");
    printf("\n Phone No.         : +6%s", currentptr->contact.phoneNum);
    printf("\n Email             : %s", currentptr->contact.email);
    printf("\n Facebook          : %s", currentptr->contact.facebook);

    printf("\n\n+------------------------+");
	printf("\n|  Financial Information |");
	printf("\n+------------------------+");
    printf("\n Income            : RM %.2f", currentptr->financial.income);
    printf("\n Scholarship       : %s", currentptr->financial.scholarship);

    printf("\n\n+------------------------+");
	printf("\n|    Other Information   |");
	printf("\n+------------------------+");
    printf("\n Nationality       : %s", currentptr->other.nationality);
    printf("\n Race              : %s", currentptr->other.race);
    printf("\n Religion          : %s", currentptr->other.religion);
    printf("\n Marital Status    : %s", currentptr->other.maritalStatus);

}


//---------------------------------------------------------------------------------------------------------


void updateData(){

    int Update, UpdatePart, counter, ChooseCourse;
    int address;
    bool UpdateOption = false;

    system("cls");
    currentptr=headptr;
    dataTable();

    printf("\nChoose Number to Update (Press 0 to back): ");
    scanf("%d", &Update);

    if(Update == 0){
        return;
    }

    int count = 1;
    currentptr=headptr;
    while(currentptr != NULL){
        if(count == Update){

            UpdateOption = false;
            do{
                system("cls");

                printf("\n===============================================");
				printf("\n  Update Information for Student Name:  ");
				printf("\n << %s >>", currentptr->name);
				printf("\n===============================================\n");

                printf("\n        Information");
                printf("\n       ¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
                printf("\n   1.  Personal Information");
                printf("\n   2.  Address Information");
                printf("\n   3.  Birth Information");
                printf("\n   4.  Contact Information");
                printf("\n   5.  Financial Information");
                printf("\n   6.  Other Information (Nationality, Race , Religion & etc)");
                printf("\n   7.  Back");
                printf("\n\n  Choose Which part to update: ");
                scanf(" %d", &UpdatePart);

                switch(UpdatePart){

                    case 1:// Update Personal Info

                        system("cls");
                        printf("\n+------------------------+");
                        printf("\n|  Personal Information  |");
                        printf("\n+------------------------+");
                        printf("\n Enter a name (Format: String) : ");
                        scanf(" %[^\n]s",&currentptr->name);

                        printf("\n\n\t<< Course >>\n");
                        printf("\n   1.   Computer Systems & Networking");
    					printf("\n   2.   Software Engineering");
    					printf("\n   3.   Graphics & Multimedia Technology\n");

                        do{

                            printf("\n Choose course (Format: 1/2/3): ");
                            scanf(" %d",&ChooseCourse);

                            if(ChooseCourse == 1){
                                strcpy(currentptr->course,"Computer Systems & Networking");
                            }
                            else if(ChooseCourse == 2){
                                strcpy(currentptr->course,"Software Engineering");
                            }
                            else if(ChooseCourse == 3){
                                strcpy(currentptr->course,"Graphics & Multimedia Technology");
                            }
                            else{
                                printf("\n----> Invalid Option, Please Enter right Option\n");
                            }

                        }while(ChooseCourse >= 4);

                        printf("\n Enter a Matric ID (Format: String): ");
                        scanf(" %[^\n]s",&currentptr->MatricID);
                        printf("\n Enter IC No. (Example: 020111101831): ");
                        scanf(" %[^\n]s",&currentptr->IC);
                        printf("\n\n----> Update Success");
                        printf("\n\n  Press Any Key to Continue.");
                        getch();
                        break;

                    case 2: //Update Address Info

                        system("cls");
                        printf("\n+------------------------+");
                        printf("\n|   Address Information  |");
                        printf("\n+------------------------+");
                        printf("\n Enter Permanent Address (Format: String):\n\n ");
                        scanf(" %[^\n]s",&currentptr->address.PermanentAddress);

                        printf("\n\n-------------------------------------------\n");

						do
						{
							printf("\n Does the current address same as permanent address?\n (Format: 1 = YES/ 2 = NO): ");
    						scanf(" %d",&address);

                        	if(address == 1)
							{
                        	    strcpy(currentptr->address.CurrentAddress, currentptr->address.PermanentAddress);
                        	}
                        	else if(address == 2)
							{
                        	    printf(" Enter Current Address (Format: String): ");
                        	    scanf(" %[^\n]s",&currentptr->address.CurrentAddress);
                        	}
                        	else
                        	{
                        		printf("\n --->Invalid Option, Please enter the correct Option\n");
							}

                    	}while(address >= 3);

                        printf("\n\n----> Update Success");
                        printf("\n\n  Press Any Key to Continue.");
                        getch();
                        break;

                    case 3:// Update Birth Info

                        system("cls");
                        printf("\n+------------------------+");
                        printf("\n|    Birth Information   |");
                        printf("\n+------------------------+");
                        printf("\n Enter Birth Day\n (Example: 28)\t\t: ");
                        scanf(" %d",&currentptr->birth.day);
                        printf(" Enter Birth Month\n (Example: 07)\t\t: ");
                        scanf(" %d",&currentptr->birth.month);
                        printf(" Enter Birth Year\n  (Example: 2002)\t: ");
                        scanf(" %d",&currentptr->birth.year);
                        printf(" Enter Birth Place\n (Example: Selangor)\t: ");
                        scanf(" %[^\n]s",&currentptr->birth.birthplace);
                        printf(" Enter a Gender\n (Format: Male/Female)\t: ");
                        scanf(" %[^\n]s",&currentptr->gender);
                        printf("\n\n----> Update Success");
                        printf("\n\n  Press Any Key to Continue.");
                        getch();
                        break;

                    case 4:// Update Contact Info

                        system("cls");
                        printf("\n+------------------------+");
                        printf("\n|   Contact Information  |");
                        printf("\n+------------------------+");
                        printf("\n Enter Phone No.\n (Example: 0147203059)\t\t  : ");
                        scanf(" %[^\n]s",&currentptr->contact.phoneNum);
                        printf("\n Enter Email\n (Example: nazhanhaziq@gmail.com) : ");
                        scanf(" %[^\n]s",&currentptr->contact.email);
                        printf("\n Enter Facebook\n (Example: Nazhan Haziq)\t  : ");
                        scanf(" %[^\n]s",&currentptr->contact.facebook);
                        printf("\n\n----> Update Success");
                        printf("\n\n  Press Any Key to Continue.");
                        getch();
                        break;

                    case 5:// Update Financial Info

                        system("cls");
						printf("\n+------------------------+");
						printf("\n|  Financial Information |");
						printf("\n+------------------------+");
                        printf("\n Enter Income\n (Format: Float -> Example: 4500.50)\t: ");
                        scanf(" %f",&currentptr->financial.income);
                        printf("\n Enter Scholarship Status\n (Format: YES/NO)\t\t\t: ");
                        scanf(" %[^\n]s",&currentptr->financial.scholarship);
                        printf("\n----> Update Success");
                        printf("\n\n  Press Any Key to Continue.");
                        getch();
                        break;

                    case 6:// Update Other Info

                        system("cls");
						printf("\n+------------------------+");
						printf("\n|    Other Information   |");
						printf("\n+------------------------+");
                        printf("\n Enter Nationality\n (Format: String -> Example: Malaysia)\t: ");
                        scanf(" %[^\n]s",&currentptr->other.nationality);
                        printf("\n Enter Race\n (Format: String -> Example: Malay)\t: ");
                        scanf(" %[^\n]s",&currentptr->other.race);
                        printf("\n Enter Religion\n (Format: String -> Example: Islam)\t: ");
                        scanf(" %[^\n]s",&currentptr->other.religion);
                        printf("\n Enter Marital\n (Format: Married/Single)\t\t: ");
                        scanf(" %[^\n]s",&currentptr->other.maritalStatus);
                        printf("\n----> Update Success");
                        printf("\n\n  Press Any Key to Continue.");
                        getch();
                        break;

                    case 7:
                        UpdateOption = true;
                        break;

                    default:
                        printf("\n----> Invalid Option, Please Enter Right Option !\n");
                        printf("\n\n  Press Any Key to Continue.");
						getch();

                }
            }while(UpdateOption == false);

        }
        count++;
        currentptr=currentptr->ptrnext;
    }
}


//---------------------------------------------------------------------------------------------------------


void deleteData()
{
    int count, DeleteNumber;
    char DeleteOption;

    if(headptr==NULL){

        system("cls");
        printf("\n\n ----> The list is empty. There is no student that has been added yet.\n");
        printf("\n\n  Press Any Key to Continue . . . ");
        getch();
    }
    else{

        if(headptr==NULL){

            system("cls");
            printf("\n\n ----> The list is empty. There is no student that has been added yet.\n");
            printf("\n\n  Press Any Key to Continue . . . ");
            getch();
            return;
        }

        bool DeleteSubMenu = false;
        do{

            system("cls");
            currentptr=headptr;
            dataTable();
            printf("\n\n\n             Delete Option");
            printf("\n ______________________________________");
            printf("\n|   A. Delete Latest Inserted Data     |");
            printf("\n|   B. Choose Number To Delete         |");
            printf("\n|   C. Back                            |");
            printf("\n|______________________________________|");
            printf("\n\n\tEnter Option: ");
            scanf(" %[^\n]s", &DeleteOption);

            switch(toupper(DeleteOption)){

            case 'A':

                delNode = headptr;
                headptr = delNode->ptrnext;
                free(delNode);
                printf("\n---->Delete Success");
                printf("\n\n  Press Any Key to Continue.");
                getch();
                break;

            case 'B':

                printf("\n Insert Number (Press 0 to back) : ");
                scanf(" %d", &DeleteNumber);

                if(DeleteNumber == 0){
                    DeleteSubMenu = true;
                }
                else{
                    count = 1;
                    currentptr=headptr;
                    while(currentptr->ptrnext != NULL){

                        if(count == DeleteNumber){
                            break;
                        }

                        else{
                            previousptr=currentptr;
                            currentptr=currentptr->ptrnext;
                            count++;
                        }
                    }

                    if(count == DeleteNumber){ //Delete After found location

                        if(currentptr==headptr){
                            headptr=currentptr->ptrnext;
                            free(currentptr);
                            printf("\n\n---->Delete Success");
                    		printf("\n\n  Press Any Key to Continue.");
                    		getch();
                        }
                        else{
                            previousptr->ptrnext=currentptr->ptrnext;
                            free(currentptr);
                            printf("\n\n---->Delete Success");
                    		printf("\n\n  Press Any Key to Continue.");
                    		getch();
                        }
                    }
                    else{//Not found location
                        printf("\n----> Invalid Number");
                        printf("\n\n  Press Any Key to Continue.");
                        getch();
                    }

                }
                break;

            case 'C':
                return;
                break;

            default:
                printf("\n---->Invalid Option, Please Enter Right Option !");
                printf("\n\n  Press Any Key to Continue.");
                getch();

            }


        }while(DeleteSubMenu == true);

    }
}


//---------------------------------------------------------------------------------------------------------


void sortingData(){

    struct Student *temp1, *temp2;

    int SortOption;

    if(headptr == NULL){
        return;
    }
    else{

        printf("\n       << Sort Data by >>");
        printf("\n ______________________________");
        printf("\n|     1. Matric ID             |");
        printf("\n|     2. Name                  |");
        printf("\n|     3. Gender                |");
        printf("\n|______________________________|");
        printf("\n\n\tEnter Choice : ");
        scanf(" %d", &SortOption);

        switch(SortOption){

        case 1:
            temp1 = headptr;
            temp2 = temp1->ptrnext;

            while(temp2 != NULL){

                if(strcmp(temp1->MatricID, temp2->MatricID) > 0){

                        SwapData(temp1,temp2);

                }
                temp1 = temp2;
                temp2 = temp1->ptrnext;

            }
            break;

        case 2:

            temp1 = headptr;
            temp2 = temp1->ptrnext;

            while(temp2 != NULL){

                if(strcmp(temp1->name, temp2->name) > 0){

                        SwapData(temp1,temp2);

                }
                temp1 = temp2;
                temp2 = temp1->ptrnext;

            }
            break;

        case 3:
            temp1 = headptr;
            temp2 = temp1->ptrnext;

            while(temp2 != NULL){

                if(strcmp(temp1->gender, temp2->gender) > 0){

                        SwapData(temp1,temp2);

                }
                temp1 = temp2;
                temp2 = temp1->ptrnext;

            }
            break;

        default:
            printf("\n----> Invalid Option, Please Enter Right Option !\n");
            printf("\n\n  Press Any Key to Continue.");
            getch();

        }
    }
}


//---------------------------------------------------------------------------------------------------------


void SwapData(struct Student *A, struct Student *B){

    char tempChar[100];
    int tempInt;
    float tempFloat;

    //swap id
    strcpy(tempChar,A->MatricID);
    strcpy(A->MatricID,B->MatricID);
    strcpy(B->MatricID,tempChar);

    //swap name
    strcpy(tempChar,A->name);
    strcpy(A->name,B->name);
    strcpy(B->name,tempChar);

    //swap course
    strcpy(tempChar,A->course);
    strcpy(A->course,B->course);
    strcpy(B->course,tempChar);

    //swap IC
    strcpy(tempChar,A->IC);
    strcpy(A->IC,B->IC);
    strcpy(B->IC,tempChar);

    //swap permanent address
    strcpy(tempChar,A->address.PermanentAddress);
    strcpy(A->address.PermanentAddress,B->address.PermanentAddress);
    strcpy(B->address.PermanentAddress,tempChar);

    //swap current address
    strcpy(tempChar,A->address.CurrentAddress);
    strcpy(A->address.CurrentAddress,B->address.CurrentAddress);
    strcpy(B->address.CurrentAddress,tempChar);

    //swap birth day
    tempInt = A->birth.day;
    A->birth.day = B->birth.day;
    B->birth.day = tempInt;

    //swap birth month
    tempInt = A->birth.month;
    A->birth.month = B->birth.month;
    B->birth.month = tempInt;

    //swap birth year
    tempInt = A->birth.year;
    A->birth.year = B->birth.year;
    B->birth.year = tempInt;

    //swap birth place
    strcpy(tempChar,A->birth.birthplace);
    strcpy(A->birth.birthplace,B->birth.birthplace);
    strcpy(B->birth.birthplace,tempChar);

    //swap gender
    strcpy(tempChar,A->gender);
    strcpy(A->gender,B->gender);
    strcpy(B->gender,tempChar);

    //swap phone num
    strcpy(tempChar,A->contact.phoneNum);
    strcpy(A->contact.phoneNum,B->contact.phoneNum);
    strcpy(B->contact.phoneNum,tempChar);

    //swap email
    strcpy(tempChar,A->contact.email);
    strcpy(A->contact.email,B->contact.email);
    strcpy(B->contact.email,tempChar);

    //swap facebook
    strcpy(tempChar,A->contact.facebook);
    strcpy(A->contact.facebook,B->contact.facebook);
    strcpy(B->contact.facebook,tempChar);

    //swap income
    tempFloat = A->financial.income;
    A->financial.income = B->financial.income;
    B->financial.income = tempFloat;

    //swap scholarship
    strcpy(tempChar,A->financial.scholarship);
    strcpy(A->financial.scholarship,B->financial.scholarship);
    strcpy(B->financial.scholarship,tempChar);

    //swap nationality
    strcpy(tempChar,A->other.nationality);
    strcpy(A->other.nationality,B->other.nationality);
    strcpy(B->other.nationality,tempChar);

    //swap race
    strcpy(tempChar,A->other.race);
    strcpy(A->other.race,B->other.race);
    strcpy(B->other.race,tempChar);

    //swap religion
    strcpy(tempChar,A->other.religion);
    strcpy(A->other.religion,B->other.religion);
    strcpy(B->other.religion,tempChar);

    //swap marital status
    strcpy(tempChar,A->other.maritalStatus);
    strcpy(A->other.maritalStatus,B->other.maritalStatus);
    strcpy(B->other.maritalStatus,tempChar);

}


//---------------------------------------------------------------------------------------------------------


void dataTable(){

    printf("\n\n\t\t\t\tStudent Record\n");
    printf("-------------------------------------------------------------------------------------------------");
    printf("\n| NO. \t| NAME \t\t\t\t\t\t\t| MATRIC ID \t| GENDER \t|");
    printf("\n-------------------------------------------------------------------------------------------------\n");
    int counter = 1;
    do{
        printf("| %d   \t| %-50s \t| %-10s \t| %-8s \t|\n", counter, currentptr->name, currentptr->MatricID, currentptr->gender);
        currentptr=currentptr->ptrnext;
        counter++;

    }while(currentptr !=NULL);
    printf("-------------------------------------------------------------------------------------------------");
    printf("\n\n  Press Any Key to Continue . . . \n");
	getch();

}



//---------------------------------------------------------------------------------------------------------

/****************************************  END OF PROGRAM  ***********************************************/