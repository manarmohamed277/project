#include<stdio.h>
#include<stdlib.h>

#include <string.h>
 void selectMode();
  void adminMode();
  void userMode();
void addRecord();
 void adminPrevilage();
void  viewAllRecords();
int viewRecord();
int main(){
   selectMode();
   return 0;}

    void selectMode(){
    int mode;
    printf("\t\t\t\t\tStudent Record System\n");
    printf("To select  mode enter:\n");
    printf(" 1 -> for admin mode \n 2 -> for user mode \n 3 -> for exit\n");
    scanf("%d",&mode);
    if(mode==1)
     adminMode();
   /* else if(mode==2)
      userMode();*/

   // else if(mode==3)
     // exit();
    else{
      printf("wrong choise,there is no such mode ,try again");
    selectMode();}
    }
    void adminMode(){
        int count=3;
        int adminPass;
        while(count--){
        printf("\nplease enter the password : ");
        scanf("%d",&adminPass);
        if(adminPass==1234){
          printf("\t\t\t\t\t welcome to admin mode\n");
          adminPrevilage();
        }
        else {
            printf("wrong  ,  have %d tries\n",count);

           // adminMode();
        }}
        printf("you ran out of trise\n");
        selectMode();

    }


  /* void fileManegement (){
    FILE *pnt;
    pnt=fopen("file.txt","rw");
    fputs("manar mohamed first try",pnt);
    char arr[1000];
    fgets(arr,100,pnt);

    printf("%s",arr);}*/

    void adminPrevilage(){
        printf("\t\t\t\tadminPrevilage\n");
        int adminChoise;
        printf("enter appropriat number to perform the wanted task:\n");
        printf("1: Add student record \n2: Remove student record\n3: View student record\n4: View all records\n5: Edit admin password\n6: Edit student grade\n");
        scanf("%d",&adminChoise);
        if(adminChoise==1)
          addRecord();
      /*  else if(adminChoise==2)
          removeRecord();*/
        else if(adminChoise==3)
          viewRecord();
        else if(adminChoise==4){
          viewAllRecords();}
       /* else if(adminChoise==5)
          editAdminPassword();
        else if(adminChoise==6)
          editStudentGrade();*/
          else{
            printf("wrong choise,try again");
            adminPrevilage();
          }
    }
typedef struct {
    char name[100];
    int age;
    char id[100];
    char pass[100];
    char gender[100];

} record;
    void addRecord() {

        printf("enter how many records do you want to add:\n");
        int n;
        record *pnt;
        scanf("%d", &n);
        pnt = (record *) malloc(n * sizeof(record));
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

            FILE *fpnt;
            fpnt = fopen("recFile.txt", "a"); // Use append mode
            if (fpnt == NULL) {
                printf("Error opening the file.\n");
                return;
            }

            for (int i = 0; i < n; i++) {
                fprintf(fpnt,"%s %s %d %s %s\n ",
                        pnt[i].name, pnt[i].id, pnt[i].age, pnt[i].gender, pnt[i].pass);

                printf("Name: %s\nID: %s\nAge: %d\nGender: %s\nPassword: %s\n",
                       pnt[i].name, pnt[i].id, pnt[i].age, pnt[i].gender, pnt[i].pass);
            }

            fflush(fpnt);
            fclose(fpnt); // Close the file

            printf("Record saved :)\n");
        }
        adminPrevilage();
    }

void removeRecord(){
    char name[100]; char id[50];
    printf("enter id of student to remove his record: ");
    scanf("%s",id);
    FILE *fpIn = fopen("recFile.txt", "r");
    if (fpIn == NULL) {
        printf("Error opening the file.\n");
        return;}
        FILE *fpOut = fopen("tempFile.txt", "w");
        if (fpOut == NULL) {
            printf("Error creating the temporary file.\n");

            fclose(fpIn);
            return;}
    }
void viewAllRecords() {
    char s1[1000];
    FILE *read;
    read = fopen("recFile.txt", "r");
    if (read == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    while (fgets(s1, sizeof(s1), read)) {
        printf("%s", s1);
    }

    fclose(read);
}

int viewRecord() {
     char id[100];
    printf("enter student id : ");
    scanf("%s", id);
    FILE *fp;
    record student;
    fp = fopen("recFile.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file");
        return -1;
    }
    int i = 0;
    //fseek(fp, 0L, SEEK_SET);
    // Search for the student with the target ID
  //  int d=    fread(&student, sizeof (record), 1, fp);
//printf("d= %d",d);
      while (fscanf(fp, "%49s %9s %d %9s %19s", student.name, student.id, &student.age, student.gender, student.pass) != EOF) {
        if (strcmp(id, student.id) == 0) {
            printf("Name: %s\nID: %s\nAge: %d\nGender: %s\nPassword: %s\n",
                   student.name, student.id, student.age, student.gender, student.pass);
            break;  // Exit the loop after finding the student


        }
        i=1;}
        if (feof(fp)) {
            printf("Student with  not found.\n");
        } else if (ferror(fp)) {
            printf("Error reading file");
        }

        fclose(fp);
        printf("done");
        return 0;
    }


