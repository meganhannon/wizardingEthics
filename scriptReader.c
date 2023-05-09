
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>


FILE *fp;


void printDialogue(void)
{
   char c;
   while ((c = fgetc(fp)) != '\0') 
      putc(c);

   putc('\n');
   
}

void choice(void)
{
    char c;
   while ((c = fgetc(fp)) != '\0') 
      putc(c);

   putc('\n');
   
   printf("Please select your choice: A or B?\n");
   readString();
}

int main(void)
{
    char *filename = "wizardingScript.txt";
    *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }
   
   char ch;
   while ((ch = fgetc(fp)) != EOF) {
        if (ch = '&') {
           printDialogue();
        }
        if (ch = '#') {
           choice();
        }
   }
   
   fclose(fp);
   return 0;
}
