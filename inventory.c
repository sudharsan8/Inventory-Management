/* MAIN INVENTORY MANAGEMENT PAGE*/
#include "project.h"

void bill_print()
        {

    clearscr;
    struct bill b;
  float  gross_total=0;

printf("\n\nSN.\tProduct name\t\tQuantity\tRate\t\tTotal");

printf("\n----------------------------------------------------------------------");

        FILE *bill;
        bill=fopen("C:\\C project\\inventory management system\\datafiles\\bill.txt","rb");
        while(fread(&b,sizeof(b),1,bill))
        {

    printf("\n%d\t%s\t\t\t%d\t\t%.2f\t\t%.1f",b.sn,b.n,b.quantity,b.r,b.t);

    gross_total+=b.t;
    }
    fclose(bill);

    printf("\n\nTOTAL AMOUNT = RS.%.2f",gross_total);

    printf("\n\npress any key to continue to main menu");
            getch();
            inventory();



}

void inv_bill()
{
    struct bill b;
    int a=1,q;
    float total;
    FILE *fptr;
    FILE *bill;
    char tmp[50];
    char x[4]= {0};
    in inv;
    clearscr;


     char ch[]="\xDB\xDB\xDB\xDB\xDB CUSTOMER  BILL \xDB\xDB\xDB\xDB\xDB\n\n\n";
     int i=strlen(ch),k=20,option,j;

        for(j=0;j<i;j++)
        {
        gotoxy(k,5);
        printf("%c",ch[j]);
        Sleep(90);
        k+=2;}
        Sleep(500);


    printf("\n\nenter \"end\" to finish");



    fptr=fopen("C:\\C project\\inventory management system\\datafiles\\inventory.txt","rb+");
    bill=fopen("C:\\C project\\inventory management system\\datafiles\\bill.txt","wb");

     while(1)
     {

         printf("\n\nEnter item code   :"); getstr(x,50,stdin);
         if(strcmp(x,"end")==0)
            {
                    fclose(fptr);
                    fclose(bill);
            bill_print();
            }

        printf("Enter Quantity    :");getstr(tmp,50,stdin);q=strtol(tmp,NULL,10);
        rewind(fptr);
        while(fread(&inv,sizeof(inv),1,fptr))
      {

          if((strcmp(inv.product_code,x)==0))
          {
                total=(inv.rate)*q;
                b.sn=a;b.r=inv.rate;b.quantity=q;b.t=total;

                strcpy(b.n,inv.product_name);

                fwrite(&b,sizeof(b),1,bill);
                int size=sizeof(inv);
                inv.quantity=inv.quantity-q;
                a++;
              fseek(fptr,-size,SEEK_CUR);/* this function helps to move the cursor backward or forward from current
                                            position in the fie */
              fwrite(&inv,sizeof(inv),1,fptr);
              break;
            }
            else
            printf("No match found");
      }

      }
      fclose(fptr);
      fclose(bill);


}


void add_inv()
{
    FILE *fptr;
    char tmp[50];
    in inv;
    clearscr;

     char ch[]="\xDB\xDB\xDB\xDB\xDB ADDING RECORDS \xDB\xDB\xDB\xDB\xDB\n\n\n";
     int i=strlen(ch),k=20,option,j;

        for(j=0;j<i;j++)
        {
        gotoxy(k,5);
        printf("%c",ch[j]);
        //Sleep(90);
        k+=2;}
        Sleep(500);

          printf("\n\n\n\nEnter new record(Y/N)?");
         while(toupper(getche())=='Y')
          {
               fptr=fopen("C:\\C project\\inventory management system\\datafiles\\inventory.txt","ab");
               //append file mode puts cursor at end of file
               //fseek(fptr,0,SEEK_END);


                    printf("\n\nCode                : "); getstr(inv.product_code,50,stdin);
                    printf("Product Name        : "); getstr(inv.product_name,50,stdin);
                    printf("Quantity            : "); getstr(tmp,50,stdin);  inv.quantity = strtol(tmp, NULL,10);
                    printf("Rate                : "); getstr(tmp,50,stdin); inv.rate=strtof(tmp,NULL);


    fwrite(&inv,sizeof(inv),1,fptr);
	fclose(fptr);
	  printf("\nEnter new record(Y/N)?");
} inventory();
}

void display_inv()
{
    FILE *fptr;
    char tmp[50];
    in inv;
    clearscr;

     char ch[]="\xDB\xDB\xDB\xDB\xDB ALL INVENTORY PRODUCTS \xDB\xDB\xDB\xDB\xDB\n\n\n";
     int i=strlen(ch),k=20,option,j;

        for(j=0;j<i;j++)
        {
        gotoxy(k,5);
        printf("%c",ch[j]);
        Sleep(90);
        k+=2;}
        Sleep(500);

            fptr=fopen("C:\\C project\\inventory management system\\datafiles\\inventory.txt","rb");
            fseek(fptr,0,SEEK_SET);//sets cursor to initial point of file
            printf("\n\n\nCode\tPRODUCT NAME\t\tQUANTITY\t\tRATE\n");
            printf("----------------------------------------------------------------\n");
            while(fread(&inv,sizeof(inv),1,fptr)==1)
            {

                printf("%s\t%s\t\t\t%d\t\t\t%.2f\n",inv.product_code,inv.product_name,inv.quantity,inv.rate);
            }
            printf("\n\npress any key to continue to main menu");
            getch();
            inventory();

}

void search_inv()
{
    int datafound=0;
    FILE *fptr;
    char tmp[50];
    in inv;
    clearscr;


     char ch[]="\xDB\xDB\xDB\xDB\xDB Search Inventory Product \xDB\xDB\xDB\xDB\xDB\n\n\n";
     int i=strlen(ch),k=20,option,j;

        for(j=0;j<i;j++)
        {
        gotoxy(k,5);
        printf("%c",ch[j]);
        Sleep(90);
        k+=2;}
        Sleep(500);



            fptr=fopen("C:\\C project\\inventory management system\\datafiles\\inventory.txt","rb");
            printf("\n\nWhat is the name of product you want to search\n");
            getstr(tmp,50,stdin);
            fseek(fptr,0,SEEK_SET);
            while(fread(&inv,sizeof(inv),1,fptr)==1)
            {
                if(strcmp(inv.product_name,tmp)==0)
                {

                    datafound=1;
                       printf("\nCode\tPRODUCT NAME\t\tQUANTITY\t\tRATE\n");
                       printf("--------------------------------------------------------------\n");
                       printf("%s\t%s\t\t\t%d\t\t\t%.2f",inv.product_code,inv.product_name,inv.quantity,inv.rate);
                }
                if(datafound=0)
                {
                    printf("\nNO product found");
                    printf("\ncheck if you have entered name correctly!!");
                    }}
        printf("\n\n\npress any key to continue to main menu");
        getch();
        inventory();

}

void modify_inv()
{
    FILE *fptr;
    char tmp[50];
    in inv;
    int datafound=0;
    clearscr;

    char ch[]="\xDB\xDB\xDB\xDB\xDB Modify Inventory Product \xDB\xDB\xDB\xDB\xDB\n\n\n";
     int i=strlen(ch),k=20,option,j;

        for(j=0;j<i;j++)
        {
        gotoxy(k,5);
        printf("%c",ch[j]);
        Sleep(90);
        k+=2;}
        Sleep(500);

            fptr=fopen("C:\\C project\\inventory management system\\datafiles\\inventory.txt","rb+");
            //rewind(fptr);
            printf("\n\nWhat is the name of product you want to modify:\n");
            getstr(tmp,50,stdin);

            while(fread(&inv,sizeof(inv),1,fptr)==1)
            {
                if(strcmp(inv.product_name,tmp)==0)
                {
                    datafound=1;
                    printf("\nThe product you want to modify is: \n");
                    printf("\nCode\tPRODUCT NAME\t\tQUANTITY\t\tRATE\n");
                    printf("---------------------------------------------------------------\n");
                    printf("%s\t%s\t\t\t%d\t\t\t%.2f",inv.product_code,inv.product_name,inv.quantity,inv.rate);

                     printf("\n\nDo you want to edit this record?(y/n):");
                    if(toupper(getche())=='Y')
                    {
                    printf("\n\nCode                : "); getstr(inv.product_code,50,stdin);
                    printf("Product Name        : "); getstr(inv.product_name,50,stdin);
                    printf("Quantity            : "); getstr(tmp,50,stdin);  inv.quantity = strtol(tmp, NULL,10);
                    printf("Rate                : "); getstr(tmp,50,stdin); inv.rate=strtof(tmp,NULL);

                    fseek(fptr,-sizeof(inv),SEEK_CUR); //moving back the cursor position
                    fwrite(&inv,sizeof(inv),1,fptr);

                        printf("\n--- product edited---\n");
                        break;


                }}
            }
            if(datafound==0)
            {
                 printf("\nNO product found");
                printf("\ncheck if you have entered name correctly!!");
            }
        printf("\n\n\npress any key to continue to main menu");
        getch();
        fclose(fptr);
        inventory();

}

void delete_inv()
{
     FILE *fptr;
     FILE *temp;
    char tmp[50];
    int datafound=0;
    in inv;
    clearscr;


    char ch[]="\xDB\xDB\xDB\xDB\xDB Delete Inventory Product \xDB\xDB\xDB\xDB\xDB\n\n\n";
     int i=strlen(ch),k=20,option,j;

        for(j=0;j<i;j++)
        {
        gotoxy(k,5);
        printf("%c",ch[j]);
        Sleep(90);
        k+=2;}
        Sleep(500);

            fptr=fopen("C:\\C project\\inventory management system\\datafiles\\inventory.txt","rb");
            printf("\n\nWhat is the name of product you want to Delete:\n");
            getstr(tmp,50,stdin);//passing to our input function
            /* here we have opened two files: "inventory.txt" and temp.txt"
    To Remove a Product we first search for it's existence in file and if the product name is found we write all other
    products and their details in "temp.txt" and delete the file "inventory.txt" and at the same time renaming
            "temp.txt" to "inventory.txt" */

           while(fread(&inv,sizeof(inv),1,fptr)==1)
            {
                if(strcmp(inv.product_name,tmp)==0)
                {
                     datafound=1;
                    printf("\nThe product you want to delete is: \n");
                    printf("\nCode\tPRODUCT NAME\t\tQUANTITY\t\tRATE\n");
                    printf("-------------------------------------------------------------\n");
                    printf("%s\t%s\t\t\t%d\t\t\t%.2f",inv.product_code,inv.product_name,inv.quantity,inv.rate);
                }}

                     if(datafound==0)
            {

                 printf("\nNO product found");
                printf("\ncheck if you have entered name correctly!!");
            }


            printf("\n\nDo you really want to delete this record?(y/n):");

                    if(toupper(getche())=='Y')
                    {
                    temp=fopen("C:\\C project\\inventory management system\\datafiles\\temp.txt","wb");
                    rewind(fptr);

                    while(fread(&inv,sizeof(inv),1,fptr)==1)
                    {
                    if(strcmp(inv.product_name,tmp)!=0)
                    {
                    fwrite(&inv,sizeof(inv),1,temp);
                    }
                    }

                    fclose(fptr);
                    fclose(temp);

                    remove("C:\\C project\\inventory management system\\datafiles\\inventory.txt");
                    rename("C:\\C project\\inventory management system\\datafiles\\temp.txt","C:\\C project\\inventory management system\\datafiles\\inventory.txt");
                    printf("\n--- product deleted---\n");

                    }
        printf("\n\n\npress any key to continue to main menu");
        getch();
        inventory();

}

void exit_inv()
{
    printf("Want to close ??(y/n):");
    if(toupper(getche())=='Y')
    {
        clearscr;
        gotoxy(20,5);

         int r;
		printf("EXITING");
		for(r=1;r<=20;r++){
    Sleep(50);
    printf("\xB0");}
    exit(1);

    }
    else
    inventory();
}

void inventory(void)
{
    char tmp[50];
      clearscr;
        subtitle();
    int option;

    printf("%s",
			"\n"
			"\n   INVENTORY MAIN MENU    \n"
			"------------------------------------\n"
			"   1.  CUSTOMER'S BILL    \n"
			"   2.  ADD inventory product \n"
			"   3.  LIST all inventory products \n"
			"   4.  SEARCH a product \n"
			"   5.  MODIFY inventory record\n"
			"   6.  DELETE inventory record \n"
			"   7.  ADD or LIST employee record\n"
			"   8.  Exit \n"
			"\n"
			"Enter your choice:\t ");
			getstr(tmp,50,stdin);
			option=strtol(tmp,NULL,10);
			printf("\n");


        switch(option)
        {
        case 1:inv_bill();break;;
        case 2:add_inv(); break;
        case 3:display_inv(); break;
        case 4:search_inv(); break;
        case 5:modify_inv();break;
        case 6:delete_inv();break;
        case 7:employee();break;
        case 8: exit_inv();break;

        default: inventory();

           }

}



