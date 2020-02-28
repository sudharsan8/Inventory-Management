/* ADD EMPLOYEE DETAILS */
#include "project.h"
void add_employee()
{
    clearscr;
    struct employee emp;
    char tmp[50];
    FILE *f;


     printf("\nEnter new record(Y/N)?");
         while(toupper(getche())=='Y')
          {
    f=fopen("C:\\C project\\inventory management system\\datafiles\\employee.txt","rb+");
    if(f==NULL)
    {
    f=fopen("C:\\C project\\inventory management system\\datafiles\\employee.txt","wb+");
        if(f=NULL)
        {
        printf("FILE CAN'T BE CREATED");
        }}
        //fclose(f);
        //f=fopen("C:\\C project\\inventory management system\\datafiles\\employee.txt","ab");

    printf("\n.................ENTER THE DETAILS OF THE EMPLOYEES...........\n\n");

printf("\nEnter employee name               :");getstr(emp.name,50,stdin);
printf("\nEnter age                         :");getstr(tmp,50,stdin);emp.age=strtol(tmp,NULL,10);
printf("\nEnter address of the employee     :");getstr(emp.address,50,stdin);
printf("\nEnter contact no the employee     :");getstr(emp.contactno,50,stdin);


printf("\nEnter salary of the employee      :");getstr(tmp,50,stdin);emp.salary=strtoll(tmp,NULL,10);

 fseek(f,0,SEEK_END);

 fwrite(&emp,sizeof(emp),1,f);
 fclose(f);

  printf("\n\nDo you want to add another:(Y/N)?");
          }
          employee();
}

void list_employee()
{
   FILE *f;
    char tmp[50];
    struct employee emp;
    clearscr;
    printf(":::::EMPLOYEE RECORDS:::::\n\n");

            f=fopen("C:\\C project\\inventory management system\\datafiles\\employee.txt","rb");
            fseek(f,0,SEEK_SET);
            printf("\nEmployee name\t\tAge\t\tAddress\t\t\t\tContact no\t\tSalary\n");
            printf("----------------------------------------------------------------------------------------------------\n");
            while(fread(&emp,sizeof(emp),1,f)==1)
            {

                printf("%s\t\t%d\t\t%s\t\t\t%s\t\t%d\n",emp.name,emp.age,emp.address,emp.contactno,emp.salary);
            }
            fclose(f);
            printf("\n\npress any key to continue to employee menu");
            getch();
            employee();
}

void employee()
{
clearscr;
char tmp[50];
 char ch[]=".....ADD OR LIST EMPLOYEES.....\n\n ";
     int i=strlen(ch),k=20,option,j;

        for(j=0;j<i;j++)
        {
        gotoxy(k,5);
        printf("%c",ch[j]);
        Sleep(90);
        k+=2;}
        Sleep(500);

       printf("%s",
			"\n\n\n"
			"   1.  ADD Employee of your inventory \n"
			"   2.  SEE your employees Record \n"
			"   3.  RETURN to main menu \n"
			"\nEnter your choice:\t ");
			getstr(tmp,50,stdin);
			option=strtol(tmp,NULL,10);
			printf("\n");

			switch(option)
			{
			    case 1:add_employee();break;
			    case 2:list_employee();break;
			    case 3:inventory();break;
			}


}


