#include <stdio.h>
#include<string.h>
#include <malloc.h>
#include "user.h"
#include "..\struct.h"
#include "..\selectMode\selectmode.h"
#define num_students 100
FILE *pf ;
record student;
char ID[20];
FILE *file;
void userprivilege()
{
    printf("enter appropriat number to perform the wanted task:\n");
    printf("1: View your record \n2: Edit your password\n3: Edit your name\n4: exit user mode\n");

    int userchoise;
    scanf("%d",&userchoise);
    if(userchoise==1)
    {
        viewrecord(ID);
    }
    else if(userchoise==2)
    {
        editpass(ID);
    }
    else if(userchoise==3)
    {
        editname(ID);
    }
    else if (userchoise==4)
    {
       selectmode();
    }
    else{
        printf("wrong choise,try again");
        userprivilege();
    }

}

void viewrecord(char id[]) {
    file = fopen("recfile.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    int recordFound = 0;
    while( fscanf(file, "%s %s %d %s %s %d", student.name, student.id, &student.age, student.gender, student.pass,&student.grade) != EOF) {
        if (strcmp(student.id , id)==0) {
            printf("Name: %s\nID: %s\nAge: %d\nGender: %s\nPassword: %s\nGrade: %d\n",
                   student.name, student.id, student.age, student.gender, student.pass, student.grade);
            printf("--------------------------------------------------\n");
            recordFound = 1;
            break;
        }
    }
    fclose(file);

    if (!recordFound) {
        printf("Record with ID %s not found.\n", id);
        viewrecord(id);}
    userprivilege();
}

int editpass(char id[20]) {

    record arr[num_students];
    char *newpassword = (char *)malloc(50 * sizeof(char));

    printf("Enter your new password:");
    scanf("%s",newpassword);

    FILE *pnt = fopen("recFile.txt", "r");
    if (pnt == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    int counter =0;


    while  ( fscanf(pnt, "%49s %9s %d %9s %19s %d", arr[counter].name, arr[counter].id, &arr[counter].age, arr[counter].gender, arr[counter].pass,& arr[counter].grade) != EOF) {
        counter++;
    }
    fclose(pnt);
    int found =0;
    for (int i = 0; i < counter; ++i) {
        if(strcmp(arr[i].id,id)==0)
        {
            strcpy(arr[i].pass,newpassword);
            found=1;
        }
    }
    pnt = fopen("recFile.txt", "w");
    if (pnt == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < counter; ++i) {
        fprintf(pnt, "%s %s %d %s %s %d\n", arr[i].name, arr[i].id, arr[i].age, arr[i].gender, arr[i].pass, arr[i].grade);

    }
    fclose(pnt);
    if(found){
        printf("Password is changed succefully\n");
    }else{
        printf("Student with id %s not found.\n ",ID);
    }

}

void editname(char id[]) {
    record arr[num_students];
    char newname[20];
    printf("Enter the new name you want: ");
    scanf("%s", newname);
    FILE *pnt = fopen("recFile.txt", "r");
    if (pnt == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    int counter=0;
    while (fscanf(pnt, "%49s %9s %d %9s %19s %d", arr[counter].name, arr[counter].id, &arr[counter].age, arr[counter].gender, arr[counter].pass,&arr[counter].grade)!=EOF)
    {
        counter++;
    }
    fclose(pnt);

    int found = 0;
    for (int i = 0; i < counter; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            strcpy(arr[i].name, newname);
            found = 1;
        }
    }

    pnt = fopen("recFile.txt", "w");
    if (pnt == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < counter; ++i) {
        fprintf(pnt, "%s %s %d %s %s %d\n", arr[i].name, arr[i].id, arr[i].age, arr[i].gender, arr[i].pass, arr[i].grade);
    }

    fclose(pnt);

    if (found) {
        printf("Name is changed successfully.\n");
    } else {
        printf("Student with ID %s not found.\n", id);
    }
    userprivilege();
}
