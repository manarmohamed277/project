#include <stdio.h>
#include<string.h>
#include <malloc.h>
#include "user.h"
#include "struct.h"
FILE *pf ;
record student;
char ID[20];
FILE *file;
void userprivilege()
{
    printf("enter appropriat number to perform the wanted task:\n");
    printf("1: View your record \n2: Edit your password\n3: Edit your name\n");

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
    else
    {
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
    }
}

void editpass(char id[]) {
    char *password = (char *)malloc(50 * sizeof(char));
    FILE *tempfile = fopen("temp.txt", "a");
    file = fopen("recfile.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter your old password:");
    scanf("%s",password);
    while (fscanf(pf, " %s %s %d %s %s %d", student.name, student.id, &student.age, student.gender, student.pass,&student.grade) != EOF) {
        if (strcmp(student.pass, password) == 0) {
            printf("Enter your new Password:");
            char *newpass = (char *)malloc(50 * sizeof(char));
            scanf("%s",newpass);
            removepass(id);
            fprintf(tempfile,"%s %s %d %s %s %d\n",student.name,student.id,student.age,student.gender,newpass,student.grade);
            printf("your password has changed succefully");
            free(newpass);
            break;

        } else {
            printf("Wrong password...\nPlease try again ");
            free(password);
            editpass(id);
        }
    }
}
void editname(char id[]) {


    FILE *tempfile = fopen("temp.txt", "a");
    file = fopen("recfile.txt", "r");
    record student;

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, " %s %s %d %s %s %d", student.name, student.id, &student.age, student.gender, student.pass,&student.grade) != EOF) {
        if (strcmp(id , student.id)==0) {
            printf("Enter the new name you want : ");
            char *newname=(char*)malloc(30*sizeof(char));
            scanf("%s",newname);
            removename(id);
            fprintf(pf, "%s %s %d %s %s %d\n", student.name, student.id, student.age, student.gender, student.pass, student.grade);
            printf("\nyour name is changed sucssefully");
            free(newname);
            break;
        }
    }
}
void removename(char id[]) {
    FILE *originalFile = fopen("recfile.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (originalFile == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }
    int recordRemoved = 0;
    while (fscanf(pf, " %s %s %d %s %s %d", student.name, student.id, &student.age, student.gender, student.pass,&student.grade) != EOF)  {
        if (strcmp(student.id ,id)!=0) {
            fprintf(pf, "%s %s %d %s %s %d\n", student.name, student.id, student.age, student.gender, student.pass, student.grade);// Write record to temp file if ID doesn't match
        } else {
            recordRemoved = 1;
        }
    }

    fclose(originalFile);
    fclose(tempFile);

    if (!recordRemoved) {
        printf("Name Record with ID %s not found.\n", id);
        remove("tempfile"); // Remove temporary file
        return;
    }

    // Replace original file with temp file
    remove("recfile.txt");
    rename("temp.txt","recfile.txt");
    printf("Name with ID %s removed successfully.\n", id);
}

void removepass(char id[]) {
    FILE *originalFile = fopen("recfile.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (originalFile == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }
    int recordRemoved = 0;
    while (fscanf(pf, " %s %s %d %s %s %d", student.name, student.id, &student.age, student.gender, student.pass,&student.grade) != EOF) {
        if (strcmp(student.id , id)!=0) {
            fprintf(tempFile,"%s %s %d %s %s %d\n",student.name,student.id,student.age,student.gender,student.pass,student.grade); // Write record to temp file if ID doesn't match
        } else {
            recordRemoved = 1;
        }
    }

    fclose(originalFile);
    fclose(tempFile);

    if (!recordRemoved) {
        printf("Password Record with ID %s not found.\n", id);
        remove("temp.txt"); // Remove temporary file
        return;
    }

    // Replace original file with temp file
    remove("file.txt");
    rename("temp.txt", "file.txt");

    printf("Password with ID %s removed successfully.\n", id);
}

