#include<stdio.h>
int main(){
   return 0;}

    void selectMode(){
    int mode;
    printf("\t\t\t\t\tStudent Record System\n");
    printf("To select the mode enter:\n");
    printf(" 1 -> for admin mode \n 2 -> for user mode \n 3 -> for exit");
    scanf("%d",&mode);
    if(mode==1)
      adminMode();
    else if(mode==2)
      userMode();
      
    else if(mode==3)
      exit();
    else{
      printf("wrong choise,there is no such mode ,try again");
    selectMode();}
    }
    void adminMode(){
        int count=2;
        int adminPass;
        printf("please enter the password : ");
        scanf("%d",&adminPass);
        if(adminPass==1234){
          printf("\t\t\t\t\t\t\t welcome to admin mode");
          adminPrevilage();
        }
        else {
        while(count--){
            printf("wrong password , you have %d tries",count);
            adminMode();
        }
        printf("you ran out of trise");
        selectMode();

    }}

   
   void fileManegement (){
    FILE *pnt;
    pnt=fopen("file.txt","rw");
    fputs("manar mohamed first try",pnt);
    char arr[1000];
    fgets(arr,100,pnt);

    printf("%s",arr);}
    void adminPrevilage(){
        int adminChoise;
        printf("enter appropriat number to perform the wanted task:\n");
        printf("1: Add student record \n2: Remove student record\n3: View student record\n4: View all records\n5: Edit admin password\n6: Edit student grade");
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
    void addRecord()
        {
            typedef struct {
                char *name ;
                int age;
                char *id;
                char *gender;
                int  pass;
            } record;
           

            
            
        
        
    }

    
