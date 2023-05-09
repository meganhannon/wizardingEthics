
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>


FILE *fp;

enum {BUFSIZE = 48};
char name[BUFSIZE];
int choice;
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
      putc(c);

   putc('\n');
   
}

void choice(void)
{
    int i = 0;
    char c;
   while ((c = fgetc(fp)) != '\0') 
      putc(c);

   putc('\n');
   
   printf("Please select your choice: A or B?\n");
   readString();
   
   while (i == 0){
   if (strcmp(name, "a") != 0 && strcmp(name, "b") != 0) {
       if (strcmp(name, "A") != 0 && strcmp(name, "B") != 0){
          printf("Please input a valid option.\n");
       } else {
      if ((strcmp(name, "A") == 0) {
          choice = 1;
          int i = 1;
      }
      if ((strcmp(name, "B") == 0) {
          choice = 2;
          int i = 1;
      }
   }
          }
}
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
