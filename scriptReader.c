
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

enum {BUFSIZE = 48};
char name[BUFSIZE];
int dec;
FILE *script;
int util;
int deon;

/* same as grader.c lol */
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
   int c;

   putchar('\n');
   putchar('\n');
   while ((c = fgetc(script)) != '&') 
      putchar(c);

   putchar('\n');
   putchar('\n');

   readString();
   
}


/* MUST be dialogue */
void choiceMarker(void)
{
   int c;
   putchar('\n');
   /* if ! (choice a), continue through.
      if @, (choice b) skip until next @, then
      print as normal. */
   if (dec == 1) {
       while ((c = fgetc(script)) != '^')
          c = 0;/* arbitrary action */
       while ((c = fgetc(script)) != '^') 
      putchar(c);
   } else {
       while ((c = fgetc(script)) != '@')
          c = 0;/* arbitrary action */
        while ((c = fgetc(script)) != '@') 
      putchar(c);
   }
   c = fgetc(script);
 /* increments utilitarian score */
         if (c == '$') {
            util++;
         }

         /* increments deontology score */
         if (c == '*') {
            deon++;
         }
   putchar('\n');
   putchar('\n');
   readString();
   
}


void choice(void)
{
   int i = 0;
   int c;
   putchar('\n');
   while ((c = fgetc(script)) != '#') 
      putchar(c);

   putchar('\n');
   
   printf("Please select your choice: A or B?\n");
   readString();
   
   while (i == 0){
      if (strcmp(name, "a") != 0 && strcmp(name, "b") != 0) {
         if (strcmp(name, "A") != 0 && strcmp(name, "B") != 0){
            printf("Please input a valid option.\n");
            readString();
         } else {
            if (strcmp(name, "A") == 0) {
               dec = 1;
               i = 1;
            }
            if (strcmp(name, "B") == 0) {
               dec = 2;
               i = 1;
            }
         }
      } else {
         if (strcmp(name, "a") == 0) {
            dec = 1;
            i = 1;
         }
         if (strcmp(name, "b") == 0) {
            dec = 2;
            i = 1;
         }
      }
   }
   putchar('\n');
   putchar('\n');
}

   int main(void)
   {
      char *filename = "wizardScript.txt";
      int ch;
      script = fopen(filename, "r");
      dec = 0;
      util = 0;
      deon = 0;

      /* checks if file is valid */
      if (script == NULL)
      {
         printf("Error: could not open file %s", filename);
         return 1;
      }

       printf("Welcome to the wizarding world of wizarding ethics!\n");
       printf("Please remember that you can press ENTER to exceed\n");
       printf("dialogue, and you can press the 'a' or 'b' keys to\n");
       printf("make decisions. Happy Wizarding!\n");
       printf("\n             **PRESS ENTER TO CONTINUE**\n");
       readString();

       
      /* goes through script */
      while ((ch = fgetc(script)) != EOF) {
         /* tracks regular dialogue */
         if (ch == '&') {
            printDialogue();
         }

         /* choice */
         if (ch == '#') {
            choice();
         }

         /* true fork in path (cannot have choice ) */
         if (ch == '%') {
            choiceMarker();
         }
      }
   
      fclose(script);
      return 0;
   }

