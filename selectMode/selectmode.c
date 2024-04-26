#include <stdio.h>
#include <string.h>
#include "..\admin\admin.h"
#include "..\user\user.h"
#include "selectmode.h"
#include "..\struct.h"

void selectmode(){
int mode;
printf("\t\t\t\t\t------------Student Record System------------\n");
printf("To select  mode enter:\n");
printf(" 1 -> for admin mode \n 2 -> for user mode \n 3 -> for exit\n");
scanf("%d",&mode);
if(mode==1)
adminMode();
else if(mode==2)
usermode();

// else if(mode==3)
// exit();
else{
printf("wrong choise,there is no such mode ,try again");
selectmode();} //return to select mood
}

void adminMode(){
    char adminPass[50]="1234";
    int count=3;
    char pass[50];
    while(count--){
        printf("\nplease enter the password : ");
        scanf("%s",pass);
        if(strcmp(pass,adminPass)==0){
            printf("\t\t\t\t\t----- welcome to admin mode-----\n");
            adminPrevilage();
        }
        else {
            printf("wrong password\n");
        }}
    printf("you ran out of trise\n");
    selectmode(); //if pass is wrong return to select mood

}
extern char ID[50];
void  usermode() {
    record student;
    FILE *fpnt;
    fpnt = fopen("recFile.txt", "r");
    if (fpnt == NULL) {
        printf("ERROR, FILE NOT OPENED\n");
    }
    char spass[50];
    printf("Enter your ID:-  ");
    scanf("%s", ID);
    printf("enter password: ");
    scanf("%s",spass);
    while (fscanf(fpnt, "%s %s %d %s %s %d", student.name, student.id, &student.age, student.gender, student.pass,&student.grade) != EOF) {

        if (strcmp(ID, student.id) == 0) {
            printf("eqrg");
            if (strcmp(spass, student.pass) == 0) {
                printf("\t\t\t\t Welcome to usermode \n");
                userprivilege();
                break;
            } //eawgt
            else {
                printf("id or password is wrong, try again\n");
                usermode();
            }
        }
    }
        }

