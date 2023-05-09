#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

enum {BUFSIZE = 48};

char grade = 'D';
char name[BUFSIZE];

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
   printf("What is your name?\n");
   readString();
}
void getName(void)
{
   printf("What is your name?\n");
   readString();
}

int main(void)
{
    char *filename = "wizardingScript.txt";
    FILE *fp = fopen(filename, "r");

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
   }
   getName();

   if (strcmp(name, "Andrew Appel") == 0) 
      grade = 'B';

   printf("%c is your grade.\n", grade);
   printf("Thank you, %s.\n", name);

   return 0;
}
