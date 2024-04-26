#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "admin.h"
#include "struct.h"

    void adminPrevilage(){
        printf("\t\t\t\t-----adminPrevilage-----\n");
        int adminChoise;
        printf("enter appropriat number to perform the wanted task:\n");
        printf("1: Add student record \n2: Remove student record\n3: View student record\n4: View all records\n5: Edit admin password\n6: Edit student grade\n");
        scanf("%d",&adminChoise);
        if(adminChoise==1)
          addRecord();
        else if(adminChoise==2)
          removeRecord();
        else if(adminChoise==3)
          viewRecord();
        else if(adminChoise==4)
          viewAllRecords();
        else if(adminChoise==5)
          editAdminPassword();
        else if(adminChoise==6)
          editStudentGrade();
          else{
            printf("wrong choise,try again");
            adminPrevilage();
          }
    }
    void addRecord() {

        printf("enter how many records do you want to add:\n");
        int n;
        record *pnt;
        scanf("%d", &n);
        pnt = (record *) malloc(n * sizeof(record)); //allocate memo to records
        if (pnt == NULL) {
            printf("memory allocation failed");
            return;
        }
        for (int i = 0; i < n; i++) {
            printf("for student %d :\n", 1 + i);
            printf("enter name: ");
            scanf("%s", pnt[i].name);
            printf("enter id: ");
            scanf("%s", pnt[i].id);
            printf("enter age: ");
            scanf("%d", &pnt[i].age);
            printf("enter gender: ");
            scanf("%s", pnt[i].gender);
            printf("enter passowrd: ");
            scanf("%s", pnt[i].pass);
            printf("enter grade: ");
            scanf("%d",&pnt[i].grade);
            }
        FILE *fpnt;
        fpnt = fopen("recFile.txt", "a"); // Use append mode
        if (fpnt == NULL) {
            printf("Error opening the file.\n");
            return;
        }
        for (int i = 0; i < n; i++) {
                fprintf(fpnt,"%s %s %d %s %s %d\n ", //writing in the file
                        pnt[i].name, pnt[i].id, pnt[i].age, pnt[i].gender, pnt[i].pass,pnt[i].grade);
                //for me
                printf("Name: %s\nID: %s\nAge: %d\nGender: %s\nPassword: %s\n",
                       pnt[i].name, pnt[i].id, pnt[i].age, pnt[i].gender, pnt[i].pass,pnt[i].grade);
            }

            fflush(fpnt);
            fclose(fpnt); // Close the file

            printf("Record saved :)\n");

        adminPrevilage();
    }

int removeRecord(){
     char id[50];
    printf("enter id of student to remove his record: ");
    // take id to remove
    scanf("%s",id);
        //temp file to take place of the original
        FILE *tempnt = fopen("tempFile.txt", "w");
        if (tempnt == NULL) {
            printf("Error creating the temporary file.\n");
            return -1;}
            FILE *fp;

            fp = fopen("recFile.txt", "r");
            if (fp == NULL) {
                printf("Error opening file");
                fclose(tempnt);
                return -1;
            }
            record tempArr;
            int i = 0;
            // writing all records in the temp file except the one we want to remove
            fseek(fp, 0L, SEEK_SET);
            while (fscanf(fp, "%s %s %d %s %s %d", tempArr.name, tempArr.id, &tempArr.age, tempArr.gender,
                          tempArr.pass, &tempArr.grade) != EOF) {
                // making exception for the wanted record
                if (strcmp(id, tempArr.id) != 0) {
                    fprintf(tempnt, "%s %s %d %s %s %d\n ",
                            tempArr.name, tempArr.id, tempArr.age, tempArr.gender, tempArr.pass, tempArr.grade);
                }
                else{ i=1;
                }

            }  fclose(tempnt);
               fclose(fp);

              // if the id is wrong remove the temp file
                if (i == 0) {
                    printf(" Record not found.\n");
                    remove("tempFile.txt");
                    removeRecord();
                }
                //removing the original and rename the temo after the original
                else {
                remove("recFile.txt");
                rename("tempFile.txt", "recFile.txt");
                printf("record removed successfully.\n");

            }
                adminPrevilage();
        }
void viewAllRecords() {
   /* char s1[1000];
    FILE *read;
    read = fopen("recFile.txt", "r");
    if (read == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    while (fgets(s1, sizeof(s1), read)) {
        printf("%s", s1);
    }*/
    FILE *fp;
    record student;
    fp = fopen("recFile.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file");
    }
    while (fscanf(fp, "%49s %9s %d %9s %19s %d", student.name, student.id, &student.age, student.gender, student.pass,& student.grade) != EOF) {
            printf("Name: %s\nID: %s\nAge: %d\nGender: %s\nPassword: %s\nGrade: %d\n",
                   student.name, student.id, student.age, student.gender, student.pass, student.grade);
            printf("--------------------------------------------------\n");

        }

    fclose(fp);
    adminPrevilage();
}

void viewRecord() {
     char id[50];
     //taking id of the wanted recored
    printf("enter student id : ");
    scanf("%s", id);
    FILE *fp;
    record student;
    fp = fopen("recFile.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file");
    }
    int i = 0;
    // searching for the wanted recored
      while (fscanf(fp, "%49s %9s %d %9s %19s %d", student.name, student.id, &student.age, student.gender, student.pass, &student.grade) != EOF) {
        if (strcmp(id, student.id) == 0) {
            //print the wanted recored
            printf("Name: %s\nID: %s\nAge: %d\nGender: %s\nPassword: %s\nGrade: %d\n",
                   student.name, student.id, student.age, student.gender, student.pass, student.grade);
            break;
        }
        i=1;}
        if (feof(fp)) {
            printf("Student with  not found.\n");
        } else if (ferror(fp)) {
            printf("Error reading file");
        }

        fclose(fp);
        adminPrevilage();
    }

void  editAdminPassword(){
        char pass[50];
        int count =3;
    char adminPass[50]="1234";
        printf("\nplease enter the old password : ");
        scanf("%s",pass);
        if(strcmp(pass,adminPass)==0){
            printf("enter the new password : ");
            scanf("%s",adminPass);
            adminPrevilage();
        }
        else {
            printf("wrong password \n");
            editAdminPassword();
        }
  adminPrevilage();
    }

void editStudentGrade(){
        char id[50];
        int nGrad;
        //taking id of the wanted recored
    printf("enter id of student to change his grade " );
    scanf("%s",id);
    printf("enter the new grade : ");
    scanf("%d",&nGrad);
    FILE *fp;
    record student;
    fp = fopen("recFile.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file");}
    //searching for the wanted recored
    while (fscanf(fp, " %s %s %d %s %s %d", student.name, student.id, &student.age, student.gender, student.pass,&student.grade) != EOF) {
        if (strcmp(id, student.id) == 0) {
            //changing the grade
            student.grade=nGrad;
            fseek(fp, -sizeof( record), SEEK_CUR); // move back to overwrite the record
            fprintf(fp, "%s %s %d %s %s %d\n", student.name, student.id, student.age, student.gender, student.pass, student.grade);
            break;
        }
        }
    if (feof(fp)) {
        printf("Student with  not found.\n");
    } else if (ferror(fp)) {
        printf("Error reading file");
    }

    fclose(fp);
    printf("done");

}





