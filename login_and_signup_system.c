/*
define funtion key
struct of user_pass
Funtion () of Welcome
log in and sigin menu massage
sigin funvtion ()
login funtion()
Massage of menu
Massage of wrong key
*/
/*
Make a file of .bin
*/

//! Before Run Install This Extension in vscode "aaron-bond.better-comments"

//! login and signup aksing username and userpassword "backspace" is not working

//#include
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//? windows library used for gotoxy function
#include <windows.h>
//?dirent is used for creata dir usinf mydir
#include <dirent.h>

//? unistd library is used for usleep function for animination loading
#include <unistd.h>

//function
void welcome_intro();
void signup();
void login();
void gotoxy(int, int);

//struct
struct information_of_username_password
{
    char username[10], userpassword[10];
} information;

int main()
{
    //Declare
    int choice;

    //main
    welcome_intro();

    system("cls");
    {

        gotoxy(50, 20);
        printf("Loading:\n");
        usleep(9000);

        gotoxy(25, 21);
        for (int i = 0; i < 50; i++)
        {
            printf("-");

            usleep(7000);
        }
    }
    system("cls");
menu:
    // gotoxy(25, 15);

    //login and signup massage
    printf("\n\tPress 1 To signup \n");
    printf("\tPress 2 To login \n");
    printf("\tPress ESC TO exit ");
    choice = getch();

    switch (choice)
    {
    case (49):
        system("cls");

        signup();

        goto menu;

        break;

    case (50):
        system("cls");

        login();
        // printf("Out of login function ");

        goto menu;

        break;

    case (27):
        exit(0);
        break;

    default:
        printf("\n\n\tyou enter worng choice \n");
        printf("\n\tEnter any key to return menu ");
        getch();
        system("cls");
        goto menu;
        break;
    }

    getch();
    return 0;
}

void welcome_intro()
{

    gotoxy(30, 15);
    printf("***************\t Welcome \t***************");
    {
        for (int i = 0; i < 100; i++)
        {
            usleep(1000);
        }
    }

    // getch();
}

void signup()
{
    int i, flag = 0, choice;

    //?dD:\My Project\c\Employee1\Password
    //goto

    {
        gotoxy(40, 15);
        printf("Loading signup Zone\n");
        usleep(9000);
        gotoxy(20, 16);
        for (int i = 0; i < 50; i++)
        {
            printf("-");
            // delay(100000);
            usleep(7000);
        }
        system("cls");
    }

not_done:

    printf("Enter username : ");
    for (i = 0; i < 20; i++)
    {
        information.username[i] = getch();
        printf("%c", information.username[i]);

        if (information.username[i] == 8)
        {
            i--;
            information.username[i] = getch();
            printf("%c", information.username[i]);
        }

        if (information.username[i] == 13)
        {
            break;
        }
    }
    information.username[i] = '\0';

    printf("\n");

    printf("Enter password : ");
    for (i = 0; i < 20; i++)
    {
        // information.userpassword[i] = getch();
        // printf("*");
        information.userpassword[i] = getch();
        printf("*");

        if (information.userpassword[i] == 8)
        {
            i--;
            information.userpassword[i] = getch();
            printf("*");
        }

        if (information.userpassword[i] == 13)
        {
            flag = 1;
            break;
        }
    }
    information.userpassword[i] = '\0';
    printf("\n");

    //FILE
    FILE *user_pass;

    if (user_pass == NULL)
    {
        printf("Did not have enough storage");
    }

    mkdir("password");

    user_pass = fopen("password\\info.bin", "w+");

    fprintf(user_pass, "Username: %s\n", information.username);
    fprintf(user_pass, "Userpassword: %s", information.userpassword);

    fflush(user_pass);

    fclose(user_pass);

    if (flag == 1)
    {
        printf("Ragister succefull\n");
        getch();
    }
    else
    {
        goto not_done;
    }
    system("cls");
}

void login()
{

    int i, j, result_of_username, result_of_password, choice;
    char taker[20], newtaker[15], newtaker2[15];

    {
        gotoxy(40, 15);
        printf("Loading Login Zone\n");
        usleep(9000);
        gotoxy(25, 16);
        for (int i = 0; i < 50; i++)
        {
            printf("-");
            // delay(100000);
            usleep(7000);
        }
        system("cls");
    }

reset:

    printf("Enter username : ");
    for (i = 0; i < 20; i++)
    {
        information.username[i] = getch();
        printf("%c", information.username[i]);

        if (information.username[i] == 8)
        {
            i--;
            information.username[i] = getch();
            printf("%c", information.username[i]);
        }

        if (information.username[i] == 13)
        {
            break;
        }
    }
    information.username[i] = '\0';

    printf("\n");

    printf("Enter password : ");
    for (i = 0; i < 20; i++)
    {
        information.userpassword[i] = getch();
        printf("*");

        if (information.userpassword[i] == 8)
        {
            i--;
            information.userpassword[i] = getch();
            printf("*");
        }

        if (information.userpassword[i] == 13)
        {
            break;
        }
    }
    information.userpassword[i] = '\0';

    //FILE
    FILE *user_pass = NULL;

    user_pass = fopen("password\\info.bin", "r+");

    for (i = 0; i <= 40; i++)
    {
        if (fscanf(user_pass, "%s", &taker) != EOF)
        {
            if (i == 1)
            {
                for (j = 0; j < strlen(taker); j++)
                {
                    newtaker[j] = taker[j];
                }
                newtaker[j] = '\0';
            }
            else if (i == 3)
            {
                for (j = 0; j < strlen(taker); j++)
                {
                    newtaker2[j] = taker[j];
                }
                newtaker2[j] = '\0';
            }
        }
        else
        {
            break;
        }
    }

    result_of_username = strcmp(newtaker, information.username);
    result_of_password = strcmp(newtaker2, information.userpassword);

    fflush(user_pass);

    fclose(user_pass);

    printf("\n");
    if (result_of_username == 0 && result_of_password == 0)
    {
        printf("login succefull \n\n");
        printf("Wecome %s \n\n", newtaker);

        //history of login using pre-define Mecros
        mkdir("History");
        user_pass = fopen("History\\history.bin", "ab+");
        fprintf(user_pass, "Date is %s\n", __DATE__);
        fprintf(user_pass, "Time is %s\n\n", __TIME__);
        fflush(user_pass);
        fclose(user_pass);
    s1:
        printf("Press ESE to Logout\n");
        printf("Press 1 to See Login History\n");
        choice = getch();
        switch (choice)
        {
        case (27):
            information.username[0] = '\0';
            information.userpassword[0] = '\0';
            break;

        case (49):
            system("cls");
            //Open history.bin from History Folder
            user_pass = fopen("History\\history.bin", "r+");
            {
                char ht;

                while ((ht = fgetc(user_pass)) != EOF)
                {
                    printf("%c", ht);
                }
            }

            fclose(user_pass);
            getch();
            system("cls");
            goto s1;
            break;

        default:
            goto s1;
            system("cls");
            break;
        }
    }
    else
    {
        printf("sorry try Again");
        usleep(10000);
    r1:
        system("cls");
        printf("Press Enter Want to Try again \n");
        printf("Press ESC to goto Memu \n");
        choice = getch();

        switch (choice)
        {

        case (13):
            system("cls");
            goto reset;
            break;

        case (27):
            system("cls");
            break;

        default:

            printf("\n\n\tyou enter worng choice \n");
            printf("\n\tEnter any key to return menu ");
            getch();
            system("cls");
            goto r1;
        }
    }
    system("cls");
    getch();
}

void gotoxy(int x, int y)
{
    {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
}