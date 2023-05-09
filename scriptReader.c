
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

enum {BUFSIZE = 48};
char name[BUFSIZE];
int dec;
FILE *fp;

void readString(void)
{
   char buf[BUFSIZE];
   int i = 0; 
   int c;

   for (;;)
   {
      c = fgetc(stdin);
      if ((c == EOF) || (c == '\n')) 
         break;
      buf[i] = c;
      i++;
   }
   buf[i] = '\0';

   for (i = 0; i < BUFSIZE; i++) 
      name[i] = buf[i];
}


void printDialogue(void)
{
   char c;
   while ((c = fgetc(fp)) != '\0') 
      putchar(c);

   putchar('\n');
   printf("Press any key to continue.\n");
   readString();
   
}

void choice(void)
{
   int i = 0;
   char c;
   while ((c = fgetc(fp)) != '\0') 
      putchar(c);

   putchar('\n');
   
   printf("Please select your choice: A or B?\n");
   readString();
   
   while (i == 0){
      if (strcmp(name, "a") != 0 && strcmp(name, "b") != 0) {
         if (strcmp(name, "A") != 0 && strcmp(name, "B") != 0){
            printf("Please input a valid option.\n");
         } else {
            if (strcmp(name, "A") == 0) {
               dec = 1;
               int i = 1;
            }
            if (strcmp(name, "B") == 0) {
               dec = 2;
               int i = 1;
            }
         }
      } else {
         if (strcmp(name, "a") == 0) {
            dec = 1;
            int i = 1;
         }
         if (strcmp(name, "b") == 0) {
            dec = 2;
            int i = 1;
         }
      }
   }

      int main(void)
      {
         char *filename = "wizardScript.txt";
         char ch;
         fp = fopen(filename, "r");
         dec = 0;
         
         if (fp == NULL)
         {
            printf("Error: could not open file %s", filename);
            return 1;
         }
   
       
         while ((ch = fgetc(fp)) != EOF) {
            if (ch = '&') {
               printDialogue();
            }
            if (ch = '#') {
               choice();
            }
         }
   
         fclose(fp);
      }
}
