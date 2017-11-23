#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
	char id[10];
	char firstname[30];
	char lastname[30];
	char phone[20];
	char email[40];
	char pass[30];
	char confirmpass[30];
	char role[20];
};

//struct Create Variable
struct data userInfo[100] = {{"0000001","Dechapon","Tongmak","0920011706","d@b.com","12345678","12345678","Admin"}
                            ,{"6088211","Iamlord","Haha","0123456789","dechapon@t.com","asdfghjk","asdfghjk","Student"}
                            ,{"0000002","Benz","Slayer","0812345678","b@s.com","87654321","87654321","Admin"}
                            };
struct data userInput;
struct data temp;



//Global Variable
int countUser = 3;
int mailLength = 0;
int passLength = 0;
int confirmpassLength = 0;
int i,j,k;
int countAt;
int cond = 0;
int checkUser = 0;
int MenuChoice;
int choice;
int checkCond;
int userNow;


void logout(){
    system("cls");
    printf("[Logout Page]\n");
    printf("Good Bye\n\n");

    printf("Press Any key to back to Main Menu");
    getch();
    MainMenu();
}

void admin(){
    system("cls");
    printf("Now you are logged in as a Admin in the system.\n");
    printf("You can start using the following functions.\n");
    printf("[1] Edit My Contact Information\n");
    printf("[2] Show all Contacts\n");
    printf("[3] Search for a Contact\n");
    printf("[4] Delete User’s Contact\n");
    printf("[0] Logout\n");
    printf("Please enter the choice : ");
    scanf("%d",&MenuChoice);
        if(MenuChoice == 1){
            adminEditUser();
        }
        else if(MenuChoice == 2){
            showallContact();
        }
        else if(MenuChoice == 3){
            searchaContact();
        }
        else if(MenuChoice == 4){
            deleteContact();
        }
        else if(MenuChoice == 0){
            logout();
        }
}

void student(){
    system("cls");
    printf("Now you are logged in as a Student in the system.\n");
    printf("You can start using the following functions.\n");
    printf("[1] Edit My Contact Information\n");
    printf("[2] Show all Contacts\n");
    printf("[3] Search for a Contact\n");
    printf("[0] Logout\n");
    printf("Please enter the choice : ");
    scanf("%d",&MenuChoice);
        if(MenuChoice == 1){
            editUser();
        }
        else if(MenuChoice == 2){
            showallContact();
        }
        else if(MenuChoice == 3){
            searchaContact();
        }
        else if(MenuChoice == 0){
            logout();
        }
}

void deleteContact(){
    printf("[ADMIN] ID : %s\n",userInput.id);
    printf("\nPlease enter the ID for deleting : ");
    scanf("%s",userInput.id);

    for(i = 0 ; i < countUser ;i++){
        if(strcmp(userInput.id, userInfo[i].id)==0){
            checkUser = i;
        }
    }

    for(i = checkUser ; i < countUser ; i++){
        userInfo[i] = userInfo[i+1];
    }
      countUser = countUser - 1;

      printf("\n Delete Success!!\n");
      printf("Press Any key to back to menu");
      getch();
      admin();


}

void searchaContact(){
    system("cls");
    printf("Contacts Information\n");
    printf("Please input First Name for searching : ");
    scanf("%s",userInput.firstname);

    for(i = 0 ; i < countUser ;i++){
        if(strstr(userInfo[i].firstname,userInput.firstname)){
            printf("%s\t%s\n",userInfo[i].firstname,userInfo[i].lastname);
        }
    }
    printf("\n Press Any Key to Back to Menu");
    getch();
    if(strcmp(userInfo[userNow].role,"Admin") == 0){
        admin();
    }
    else{
        student();
    }


}

void showallContact(){
    system("cls");

    printf("--------------------------------------------------------------------------------------------\n");
    printf("%-15s  %-20s %-20s %-15s %-15 %-20s\n","ID","FirstName","LastName","Role","Phone Number","Email");
    printf("--------------------------------------------------------------------------------------------\n\n");

    //Show all Admin First
    for(i = 0; i < countUser ; i++){
            if(strcmp(userInfo[i].role,"Admin")==0){
                printf("%-15s  %-20s %-20s %-15s %-15 %-20s\n"
                ,userInfo[i].id,userInfo[i].firstname,userInfo[i].lastname,userInfo[i].role,userInfo[i].phone,userInfo[i].email);
                }
        }
     //Show all students
      for(i = 0; i < countUser ; i++){
            if(strcmp(userInfo[i].role,"Student")==0){
                printf("%-15s  %-20s %-20s %-15s %-15 %-20s\n"
                ,userInfo[i].id,userInfo[i].firstname,userInfo[i].lastname,userInfo[i].role,userInfo[i].phone,userInfo[i].email);
                }
        }


     printf("\n\n Press Any key to back to Manu");
     getch();

     if(strcmp(userInfo[userNow].role,"Admin") == 0){
        admin();
     }
     else{
        student();
        }

    }

void adminEditUser(){
    system("cls");
    printf("[Edit User’s Contact]\n");
    printf("\n[ADMIN] ID: %s\n",userInfo[userNow].id);
    printf("Please enter the id for editing : ");
    scanf("%s",userInput.id);

    for(i = 0;i< countUser ; i++){
        if(strcmp(userInfo[i].id,userInput.id) == 0){
            checkUser = i;
        }
    }

    //Edit of Check User
    printf("\n[STUDENT] ID: %s\n",userInfo[checkUser].id);


    //Find Id


    printf("[Edit My Contact Information]\n");
    printf("[STUDENT] ID: %s\n\n",userInfo[checkUser].id);

    printf("[1] First Name : %s\n",userInfo[checkUser].firstname);
    printf("[2] Last Name : %s\n",userInfo[checkUser].lastname);
    printf("[3] Phone Number : %s\n",userInfo[checkUser].phone);
    printf("[4] Email : %s\n",userInfo[checkUser].email);
    printf("[5] Password : %s\n",userInfo[checkUser].pass);
    printf("[6] Back to Menu\n");
    printf("Please enter the choice to edit : ");
    scanf("%d",&MenuChoice);

    if(MenuChoice == 1){
        printf("[Re-Input] First Name : ");
        scanf("%s",userInfo[checkUser].firstname);
        printf("Change first name to %s Success!!",userInfo[checkUser].firstname);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 2){
        printf("[Re-Input] Last Name : ");
        scanf("%s",userInfo[checkUser].lastname);
        printf("Change last name to %s Success!!",userInfo[checkUser].lastname);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 3){
        printf("[Re-Input] Phone Number : ");
        scanf("%s",userInfo[checkUser].phone);
        printf("Change phone to %s Success!!",userInfo[checkUser].phone);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 4){
        printf("[Re-Input] Email : ");
        scanf("%s",userInfo[checkUser].email);
        printf("Change Email to %s Success!!",userInfo[checkUser].firstname);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 5){
        printf("[Re-Input] Password : ");
        scanf("%s",userInfo[checkUser].pass);
        printf("Change Password to %s Success!!",userInfo[checkUser].pass);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 6){
        admin();
    }
}

void editUser(){
    system("cls");
    printf("[Edit My Contact Information]\n");
    printf("[STUDENT] ID: %s\n\n",userInfo[userNow].id);

    printf("[1] First Name : %s\n",userInfo[userNow].firstname);
    printf("[2] Last Name : %s\n",userInfo[userNow].lastname);
    printf("[3] Phone Number : %s\n",userInfo[userNow].phone);
    printf("[4] Email : %s\n",userInfo[userNow].email);
    printf("[5] Password : %s\n",userInfo[userNow].pass);
    printf("[6] Back to Menu\n");
    printf("Please enter the choice to edit : ");
    scanf("%d",&MenuChoice);

    if(MenuChoice == 1){
        printf("[Re-Input] First Name : ");
        scanf("%s",userInfo[userNow].firstname);
        printf("Change first name to %s Success!!",userInfo[userNow].firstname);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 2){
        printf("[Re-Input] Last Name : ");
        scanf("%s",userInfo[userNow].lastname);
        printf("Change last name to %s Success!!",userInfo[userNow].lastname);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 3){
        printf("[Re-Input] Phone Number : ");
        scanf("%s",userInfo[userNow].phone);
        printf("Change phone to %s Success!!",userInfo[userNow].phone);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 4){
        printf("[Re-Input] Email : ");
        scanf("%s",userInfo[userNow].email);
        printf("Change Email to %s Success!!",userInfo[userNow].firstname);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 5){
        printf("[Re-Input] Password : ");
        scanf("%s",userInfo[userNow].pass);
        printf("Change Password to %s Success!!",userInfo[userNow].pass);
        printf("\n Press Any Key to Continue");
        getch();
        editUser();
    }
    else if(MenuChoice == 6){
        student();
    }



}

void registration(){
    system("cls");
    printf("\t __________________________________________________________________________________________________\n");
    printf("\t **************************************************************************************************\n");
    printf("\t \t \t \t \t  \t Registration\n");
    printf("\t **************************************************************************************************\n\n");
    printf("\t                           == Please Enter Following Information ==                                \n\n");

    printf("\t \t \t ID : ");
    scanf("%s",userInfo[countUser].id);
        while(strlen(userInfo[countUser].id) != 7){
            printf("\t \t \t [ERROR] You can use only 7 digits for ID \n");
            printf("\t \t \t [Re-type] ID : ");
            scanf("%s",userInfo[countUser].id);
        }
   printf("\t \t \t First Name : ");
    scanf("%s",userInfo[countUser].firstname);

    printf("\t \t \t Last Name : ");
    scanf("%s",userInfo[countUser].lastname);

    printf("\t \t \t Phone Number : ");
    scanf("%s",userInfo[countUser].phone);
        while(strlen(userInfo[countUser].phone) != 10){
            printf("\t \t \t [ERROR] You must use only 10 digit numbers for phone number\n");
            printf("\t \t \t [Re-type] Phone Number: ");
            scanf("%s",userInfo[countUser].phone);
        }

    countAt = 0;
    printf("\t \t \t Email : ");
    scanf("%s",userInfo[countUser].email);
        mailLength = strlen(userInfo[countUser].email);
        for(i = 0 ; i < mailLength ; i++){
            if(userInfo[countUser].email[i] == '@'){
                    countAt = countAt + 1;
                }
        }
        while(countAt != 1){
                        printf("\t \t \t [ERROR] You must contain character @ in email and must have only 1 @ sign\n");
                        printf("\t \t \t [Re-type] Email: ");
                        scanf("%s",userInfo[countUser].email);
                            mailLength = strlen(userInfo[countUser].email);
                            countAt = 0;
                                for(i = 0 ; i < mailLength ; i++){
                                    if(userInfo[countUser].email[i] == '@'){
                                countAt = countAt + 1;
                            }
                        }
                    }

    printf("\t \t \t Password : ");
    scanf("%s",userInfo[countUser].pass);
        passLength = strlen(userInfo[countUser].pass);
        while(passLength < 8){
            printf("\t \t \t [ERROR] You must use at least 8 characters for password\n");
            printf("\t \t \t [Re-type] Password : ");
            scanf("%s",userInfo[countUser].pass);
        }


    printf("\t \t \t Confirm Password : ");
    scanf("%s",userInfo[countUser].confirmpass);
        confirmpassLength = strlen(userInfo[countUser].confirmpass);
        //Check password regis
           while(strcmp(userInfo[countUser].pass,userInfo[countUser].confirmpass) != 0){
                    printf("\t \t \t [ERROR] These passwords don’t match\n");
                    printf("\t \t \t [Re-type] Confirm Password : ");
                    scanf("%s",userInfo[countUser].confirmpass);
                    }

    //Store Role
    cond = 0;
    for(i = 0; i < 2 ; i++){
        if(userInfo[countUser].id[i] == '0'){
            cond = cond + 1;
        }
    }

    if(cond == 2){
        strcpy(userInfo[countUser].role , "Admin");
    }
    else{
        strcpy(userInfo[countUser].role , "Student");
    }

    countUser = countUser + 1;

    system("cls");
    printf("\t **************************************************************************************************\n");
    printf("\t \t \t \t \t Congratulation!! %s\n\n",userInfo[countUser-1].firstname);
    printf("\t \t \t Now you can login to the ICT Contact Management System and start \n");
    printf("\t \t \t to search for ICT faculty staffs’ and friends’ information.\n\n");

    printf("\t \t \t [ 1 ] back to Main Menu\n");
    printf("\t \t \t [ 2 ] login\n\n\n");
    printf("\t \t \t \t Enter a Choice Number : ");
    scanf("%d",&MenuChoice);
    if(MenuChoice == 1){
            MainMenu();
        }
        else if(MenuChoice == 2){
            login();
        }
}

void login(){
    system("cls");
    printf("Please enter your ID : ");
    scanf("%s",&userInput.id);
    printf("Please enter your password : ");
    scanf("%s",&userInput.pass);

    //Check which user and which pass
    for(i = 0 ; i < countUser ; i++){
            if(strcmp(userInput.id,userInfo[i].id) == 0){
                userNow = i;
            }
        }

    //Check password
    if(strcmp(userInput.pass,userInfo[userNow].pass) != 0){
        do{
            printf("[ERROR] Wrong ID or Password!!!\n");
            printf("[Re-type] Please enter your ID : ");
            scanf("%s",&userInput.id);
            printf("[Re-type] Please enter your password : ");
            scanf("%s",&userInput.pass);
        }while(strcmp(userInput.pass,userInfo[userNow].pass) != 0);
    }

    if(strcmp(userInfo[userNow].role,"Admin") == 0){
        admin();
    }
    else{
        student();
    }
}

void MainMenu(){
    system("cls");
    printf("\t __________________________________________________________________________________________________\n");
    printf("\t **************************************************************************************************\n");
    printf("\t \t \t \t \t  ICT Contact Management Systems\n");
    printf("\t **************************************************************************************************\n");
    printf("\t *                                                                                                *\n");
    printf("\t *                                          == Main Menu ==                                       *\n");
    printf("\t *                                                                                                *\n");
    printf("\t *                                     [1] User Registration                                      *\n");
    printf("\t *                                                                                                *\n");
    printf("\t *                                     [2] Login                                                  *\n");
    printf("\t *                                                                                                *\n");
    printf("\t *                                     [0] Exit                                                   *\n");
    printf("\t *                                                                                                *\n");
    printf("\t                                   Enter a Choice Number : ");
    scanf("%d",&MenuChoice);
        if(MenuChoice == 1){
            registration();
        }
        else if(MenuChoice == 2){
            login();
        }
        else if(MenuChoice == 3){
                searchaContact();
        }
}



int main(){
    MainMenu();
}
