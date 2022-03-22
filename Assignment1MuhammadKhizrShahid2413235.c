//MuhammadKhizrShahid
//2413235

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

//a structure for node which will contain all the following things
struct Node {

    char name[25];
    int idnumber;
    int posts;
    int following;
    int followers;
    int day;
    int month;
    int year;
    int time_hour;
    int time_minute;
    struct Node *next;

};


//structure which will contain 2 node structures made above and a variable called size
struct listrecord {

      struct Node *head;
      struct Node *tail;
      int size;

};




//helping/auxiliary function to search the name
int search(struct listrecord* list1,char* name) {

    struct Node* temp; //declaration of a pointer

    //for loop which will traverse the list and check if the name user wants to find matches any of the names existing in list
    for (temp = list1->head; temp != NULL;temp = temp->next) {
        if (strcmp(temp->name,name) == 0) {
            return 0;
        }
    }
    return 1;
}







struct listrecord* initialiseMyAccount(char* name) {

//declaration of list variable
struct listrecord* following;

//declaration and initialization of variables
int i,count=0;


//declaration of the name array variables and other character variables
char temp[25],ch,space;


//declaration of structure variable
struct Node* temp_ptr;


    //file stream
    FILE *infile;

    //opens the file for reading purposes
    infile = fopen(name, "r");


    //counts the number of lines in the file until the end of the file
    while ( (ch= fgetc(infile)) != EOF ) {

        if (ch == '\n') {
            count=count+1;
        }

    }

    //closes the file
    fclose(infile);

    //allocates memory for the list
    following = (struct listrecord *) malloc(sizeof(struct listrecord));

    //allocates the memory for structure
    following->head = (struct Node *) malloc(sizeof(struct Node));
    following->head->next=NULL;
    following->size=0;

    //file stream
    FILE *infile3;

    //opens the file for reading purposes
    infile3 = fopen(name, "r");

    //gives the head of the list to the temporary structure
    temp_ptr= following->head;

    //for loop which will read every line of the file step by step until the end of the file and data will be given to the list then and then returns a list at the end of the function
    for (i=0; i<count; i++) {

         space = 'a';
         fscanf(infile3, "%d;", &temp_ptr->idnumber);
         fscanf(infile3, "%[^;];", &temp_ptr->name);
         fscanf(infile3, "%d;", &temp_ptr->posts);
         fscanf(infile3, "%d;", &temp_ptr->following);
         fscanf(infile3, "%d;", &temp_ptr->followers);
         fscanf(infile3, "%d/", &temp_ptr->day);
         fscanf(infile3, "%d/", &temp_ptr->month);
         fscanf(infile3, "%d/", &temp_ptr->year);
         fscanf(infile3, "%c",&space);
         fscanf(infile3, "%d:", &temp_ptr->time_hour);
         fscanf(infile3, "%d;", &temp_ptr->time_minute);

         following->tail = temp_ptr;
         following->size++;

             if (i<count-1) {
                 temp_ptr->next = (struct Node*)malloc(sizeof(struct Node));
                 temp_ptr = temp_ptr->next;
                 temp_ptr->next = NULL;
             }
    }


return following;
}


void addAccount(struct listrecord* list1 ,char* name, int posts,int followers,int following) {

//structure for time
time_t ti = time(NULL);
struct tm t = *localtime(&ti);


    //auxiliary search function checks and tells that if the account does not already exists then loop is entered and account is entered to the list
    if (search(list1,name) == 1) {


        //allocates memory for node structure which hold all the posts,followers,following etc data for new entry
        list1->tail->next = (struct Node*)malloc(sizeof(struct Node));

            list1->tail->next->idnumber = list1->tail->idnumber + 1; //assigns a unique id number to the new entry simply by adding +1 to the last available id
            list1->tail = list1->tail->next;
            strcpy(list1->tail->name,name);
            list1->tail->posts = posts;
            list1->tail->followers = followers;
            list1->tail->following = following;;
            list1->tail->day = t.tm_mday;
            list1->tail->month = t.tm_mon;
            list1->tail->year = t.tm_year;
            list1->tail->time_hour = t.tm_hour;
            list1->tail->time_minute = t.tm_min;
            list1->tail->next = NULL;

            //informs the user that account has been added
            printf("\nThe account has been added to list!!\n");
            printf("\n");

            return;

    }

    //if the account already exists in the files and list then the user is informed that account already exists
    printf("The account already exists!!! \n");
    printf("\n");

}


void printMyAccount(struct listrecord* lst) {

//declaration of a structure pointer
struct Node* temp;

//head of the list is given to this pointer
temp = lst->head;

    //traverses the entire linked list and prints every entry available in that linked list with their respective data
    for (temp = lst->head; temp != NULL;temp = temp->next) {


        printf("Account ID: %d\n",temp->idnumber);
        printf("Account name: %s\n",temp->name);
        printf("Number of posts: %d\n",temp->posts);
        printf("Number of followers: %d\n",temp->followers);
        printf("Number of following: %d\n",temp->following);
        printf("Date: ");
        printf("%d",temp->day);
        printf("%c", '/');
        printf("%d",temp->month);
        printf("%c", '/');
        printf("%d\n",temp->year);
        printf("Time: ");
        printf("%d",temp->time_hour);
        printf("%c",':');
        printf("%d\n",temp->time_minute);
        printf("\n");



    }
}


void searchAccount(struct listrecord* list1,char * name) {

//declaration of a structure pointer
struct Node* temp;

    //traverses the whole linked list and if the user entered name matches the existing name in the list then it breaks and prints out the entire data of that entered user
    for (temp = list1->head; temp != NULL; temp = temp->next) {

        if (strcmp(temp->name, name) == 0) {
            break;
        }

    }

    if (temp != NULL) {

        printf("Account ID: %d\n",temp->idnumber);
        printf("Account name: %s\n",temp->name);
        printf("Number of posts: %d\n",temp->posts);
        printf("Number of followers: %d\n",temp->followers);
        printf("Number of following: %d\n",temp->following);
        printf("Date: ");
        printf("%d",temp->day);
        printf("%c", '/');
        printf("%d",temp->month);
        printf("%c", '/');
        printf("%d\n",temp->year);
        printf("Time: ");
        printf("%d",temp->time_hour);
        printf("%c",':');
        printf("%d\n",temp->time_minute);
        printf("\n");
        printf("---------------------");
        printf("\n\n");;

    }

    else {

        //if the user entered name does not match the existing names in the list then error message is displayed
        printf("There is no account with this name in the list!!!\n");
    }

}



void deleteAccount(struct listrecord* lst,int id) {

//declaration of structure pointer
struct Node* temp2;
struct Node* temp1;

//assigns the head of the list to temporary pointers
temp1 = lst->head;
temp2 = lst->head;


    //traverses the whole linked list to find the id entered by user, in the list and if found then deleted
    for (; temp2 != NULL;temp2 = temp2->next) {

        //if the id which user wants to delete is available in list then this is entered
        if (temp2->idnumber == id) {

            //transferring of pointer done if the head of the list is being dealt with
            if (temp2 == lst->head) {
                lst->head = temp2->next;
                temp2->next = NULL;
                free(temp2);
            }

            //transferring of pointer done for other nodes except head
            else {
                temp1->next = temp2->next;
                temp2->next = NULL;
                free(temp2);
            }

            //informs the user of successfully deleting the id
            printf("Account with ID %d has been deleted successfully. \n",id);

            return;

        }

        temp1 = temp2;
    }

    //if the id which user wants to delete is not available in the list  then this is entered
    printf("Account with ID %d does not exist.\n\n",id);


}



void OverwriteMyAccount(char * name ,struct listrecord* lst) {

    //file stream
    FILE* infile;

    //opens the file for writing purposes or in our case, overwriting purpose
    infile= fopen(name,"w");

    //declaration of structure pointer
    struct Node* temp;

    //head of the list is assigned to this temporary pointer
    temp = lst->head;


    //writes all the changes made to the list back on the file after delete,add operations are applied on the list, each and every modified entry is written back
    for (temp = lst->head; temp != NULL; temp = temp->next) {

        fprintf(infile,"%d", temp->idnumber);
        fprintf(infile, "%c", ';');
        fprintf(infile,"%s", temp->name);
        fprintf(infile, "%c", ';');
        fprintf(infile,"%d", temp->posts);
        fprintf(infile, "%c", ';');
        fprintf(infile,"%d", temp->followers);
        fprintf(infile, "%c", ';');
        fprintf(infile,"%d", temp->following);
        fprintf(infile, "%c", ';');
        fprintf(infile,"%d", temp->day);
        fprintf(infile, "%c", '/');
        fprintf(infile,"%d", temp->month);
        fprintf(infile, "%c", '/');
        fprintf(infile,"%d", temp->year);
        fprintf(infile, "%c", ' ');
        fprintf(infile,"%d", temp->time_hour);
        fprintf(infile, "%c", ':');
        fprintf(infile,"%d", temp->time_minute);
        fprintf(infile,"%c",'\n');
    }

    //closes the file
    fclose(infile);

}






int main () {

//declaration of list variable pointer
struct listrecord* following;
struct listrecord* followers;

//declaration and initialization of file variables
char file1[100] = "following.txt";
char file2[100] = "followers.txt";

//initialisemyaccount function is called by passing the files into the function and the lists it returns after initializing respective lists is given to the list pointer
following = initialiseMyAccount(file1);
followers = initialiseMyAccount(file2);

//declaration of the add,delete,search,print and exit option variables
int option,printoption,followoption,searchoption,deleteoption;

//declaration of the posts,id,follower,following variables
int posts,numoffollowers,numoffollowing,deleteid;

//declaration of the name array variables
char nameofacc[50];
char nameofsearch[50];

//informs the user of successful loading of files in to the system and now user can do whatever he wants with the lists in these files
printf("The following.txt file has been loaded successfully\n");
printf("The followers.txt file has been loaded successfully\n");

printf("\n\n");


//main do while loop which will keep the program running and allow the user to add or search or print or delete the account from the list/files until the user decides to exit the program
do{

    //menu for user to select the option
    printf("-----MENU-----\n");
    printf("1) Add a new account\n");
    printf("2) Print my account info\n");
    printf("3) Search account\n");
    printf("4) Delete account\n");
    printf("5) Exit \n");

    printf("\n");

    //asks the user to input the desired option according to what he wants to do and how he wants to manipulate with the lists
    printf("Enter your option: ");
    scanf("%d",&option);



    if (option == 1) { //if the user wants to add an account

        do { //a smaller inner do while loop which will keep on asking the user to enter a correct option until the user enters a correct option
            //i.e either 1 for following account or 2 for followers account

            printf("(1) Add a following account\n");
            printf("(2) Add a followers account\n");

            printf("Enter your option: \n");
            scanf("%d",&followoption);

        }while(followoption!= 1 && followoption !=2);

                if (followoption == 1) {

                    //asks the user to enter the name,number of posts,number of followers and number of following for a following account
                    printf("Enter name of the account:\n");
                    scanf("%s",&nameofacc);
                    printf("Enter number of posts:\n");
                    scanf("%d",&posts);
                    printf("Enter number of followers:\n");
                    scanf("%d",&numoffollowers);
                    printf("Enter number of following:\n");
                    scanf("%d",&numoffollowing);


                    //function call to add an account by taking the required inputs
                    addAccount(following,nameofacc,posts,numoffollowers,numoffollowing);

                }

                else if (followoption == 2) {

                    //asks the user to enter the name,number of posts,number of followers and number of following for a followers account
                    printf("Enter name of the account:\n");
                    scanf("%s",&nameofacc);
                    printf("Enter number of posts:\n");
                    scanf("%d",&posts);
                    printf("Enter number of followers:\n");
                    scanf("%d",&numoffollowers);
                    printf("Enter number of following:\n");
                    scanf("%d",&numoffollowing);


                    //function call to add an account by taking the required inputs
                    addAccount(followers,nameofacc,posts,numoffollowers,numoffollowing);

                }


    }



     else if (option == 2 ) { //if the user wants to print the list


        do{ //a smaller inner do while loop which will keep on asking the user to enter a correct option until the user enters a correct option
            //i.e either 1 for following account or 2 for followers account

            printf("(1) Print following list\n");
            printf("(2) Print followers list\n");

            printf("Enter your option: \n");
            scanf("%d",&printoption);

        }while(printoption!= 1 && printoption !=2);

                if (printoption == 1) {

                    printf("-----My following list-----\n");

                    //function call to print the following account
                    printMyAccount(following);

                }

                else if (printoption == 2) {

                    printf("-----My followers list-----\n");

                    //function call to print the followers account
                    printMyAccount(followers);

                }

    }

    else if (option == 3) { //if the user wants to search the list

        do{ //a smaller inner do while loop which will keep on asking the user to enter a correct option until the user enters a correct option
            //i.e either 1 for following account or 2 for followers account

            printf("(1) Search following list\n");
            printf("(2) Search followers list\n");

            printf("Enter your option: \n");
            scanf("%d",&searchoption);

        }while(searchoption!= 1 && searchoption !=2);

        //asks the user to enter the name he wants to search
        printf("Enter name of search: \n");
        scanf("%s", &nameofsearch);


                if (searchoption == 1) {

                    printf("\n");
                    //function call to search an account in the following list by sending the list and the name he wants to search
                    searchAccount(following, nameofsearch);

                }

                else if (searchoption == 2) {

                    printf("\n");
                    //function call to search an account in the followers list by sending the list and the name he wants to search
                    searchAccount(followers, nameofsearch);

                }

    }


    else if (option == 4) { //if the user wants to delete an account

        do{ //a smaller inner do while loop which will keep on asking the user to enter a correct option until the user enters a correct option
            //i.e either 1 for following account or 2 for followers accoun

            printf("(1) Delete account from following list\n");
            printf("(2) Delete account from followers list\n");

            printf("Enter your option: ");
            scanf("%d",&deleteoption);

        }while(deleteoption!= 1 && deleteoption !=2);

        //asks the user to enter the account id of the account he wants to delete
        printf("Enter account ID: \n");
        scanf("%d",&deleteid);

                if (deleteoption == 1) {

                    //function call to delete the account from following list by sending the list and the id
                    deleteAccount(following, deleteid);

                }

                else if (deleteoption == 2) {

                    //function call to delete the account from followers list by sending the list and the id
                    deleteAccount(followers, deleteid);

                }

    }

}while(option != 5); //do while loop ends the moment user enter 5 as option


//function call to overwrite all the add,delete changes user has made to the following and followers list whenever user decides to exit
OverwriteMyAccount(file2,followers);
OverwriteMyAccount(file1,following);

printf("Goodbye!!\n\n");

//informs the user that the changes he made to files has been updated on the files
printf("The following.txt has been updated successfully\n");
printf("The follower.txt has been updated successfully\n");


return 0;
}
