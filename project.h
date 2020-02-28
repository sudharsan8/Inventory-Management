#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<windows.h>

/* predirectives*/
#define clearscr system ("cls")

struct inventory
{
    char product_code[4];
   char product_name[20];
   int quantity;
   float rate;
};

 struct bill
    {
        int sn;
        char n[20];
        int quantity;
        float r;
        float t;
    };
struct employee
    {
        char name[20];
        int age;
        char address[20];
        char contactno[10];

        int salary;
    };

typedef struct inventory in;
    /* The typedef facility allows the programmer to use type names in abbreviated form
                                Now instead of writing struct inventory we can simply write inv */

/*FUNCTION PROTOTYPES*/
void animated_title(void);
void title(void);
void subtitle(void);
void date(void);
void inventory(void);
void employee(void);
int password(void);
void add_employee(void);
void list_employee(void);


/* for not using fflush */
char* getstr (char* string, int size, FILE* file_ptr);
// modification of fgets() - it is used for all input tasks to avoid use of scanf() gets()
