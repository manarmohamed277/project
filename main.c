#include<stdio.h>
#include<stdlib.h>

#include <string.h>
 void selectMode();
  void adminMode();
  void userMode();
void addRecord();
 void adminPrevilage();
void  viewAllRecords();
void viewRecord();
int removeRecord();
void editAdminPassword();
void editStudentGrade();
char adminPass[50]="1234";
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
        char pass[50];
        while(count--){
        printf("\nplease enter the password : ");
        scanf("%s",pass);
        if(strcmp(pass,adminPass)==0){
          printf("\t\t\t\t\t welcome to admin mode\n");
          adminPrevilage();
        }
        else {
            printf("wrong password\n");
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
typedef struct {
    char name[100];
    int age;
    char id[100];
    char pass[100];
    char gender[100];
    int grade;
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
                fprintf(fpnt,"%s %s %d %s %s %d\n ",
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
    scanf("%s",id);

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
            fseek(fp, 0L, SEEK_SET);
            while (fscanf(fp, "%s %s %d %s %s %d", tempArr.name, tempArr.id, &tempArr.age, tempArr.gender,
                          tempArr.pass, &tempArr.grade) != EOF) {
                if (strcmp(id, tempArr.id) != 0) {
                    fprintf(tempnt, "%s %s %d %s %s %d\n ",
                            tempArr.name, tempArr.id, tempArr.age, tempArr.gender, tempArr.pass, tempArr.grade);
                }
                else{ i=1;
                }

            }  fclose(tempnt);
               fclose(fp);


                if (i == 0) {
                    printf(" Record not found.\n");
                    remove("tempFile.txt");
                    removeRecord();
                }
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
    while (fscanf(fp, "%49s %9s %d %9s %19s %d", student.name, student.id, &student.age, student.gender, student.pass, student.grade) != EOF) {
            printf("Name: %s\nID: %s\nAge: %d\nGender: %s\nPassword: %s\nGrade: %d\n",
                   student.name, student.id, student.age, student.gender, student.pass, student.grade);
            printf("--------------------------------------------------");

        }

    fclose(fp);
    adminPrevilage();
}

void viewRecord() {
     char id[50];
    printf("enter student id : ");
    scanf("%s", id);
    FILE *fp;
    record student;
    fp = fopen("recFile.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file");
    }
    int i = 0;
      while (fscanf(fp, "%49s %9s %d %9s %19s %d", student.name, student.id, &student.age, student.gender, student.pass, &student.grade) != EOF) {
        if (strcmp(id, student.id) == 0) {
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
    printf("enter id of student to change his grade " );
    scanf("%s",id);
    printf("enter the new grade : ");
    scanf("%d",&nGrad);
    FILE *fp;
    record student;
    fp = fopen("recFile.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file");}
    while (fscanf(fp, " %s %s %d %s %s %d", student.name, student.id, &student.age, student.gender, student.pass,student.grade) != EOF) {
        if (strcmp(id, student.id) == 0) {
            student.grade=nGrad;
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

