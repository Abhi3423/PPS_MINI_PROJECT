#include <stdio.h>
#include<string.h>

struct marks
{
   int chem;
   int gen_aptitude;
   int maths;
   int pps;
   int lang;
   float per;
};
struct student
{
   char firstName[50];
   int roll;
   struct marks m;
};

int main()
{
   int student;

   printf("Enter the no. of students:");
   scanf("%d", &student);
   struct student s[student];
   int i, j,sum;
  
   printf("Enter information of students:\n");

   // storing information
   for (i = 0; i < student; ++i)
   {
      s[i].roll = i + 1;
      printf("\nFor roll number %d,\n", s[i].roll);
      printf("Enter first name: ");
      scanf("%s", s[i].firstName);
      printf("Enter chemistry marks: ");
      scanf("%d", &s[i].m.chem);
      printf("Enter General Aptitude marks: ");
      scanf("%d", &s[i].m.gen_aptitude);
      printf("Enter Maths marks: ");
      scanf("%d", &s[i].m.maths);
      printf("Enter PPS marks: ");
      scanf("%d", &s[i].m.pps);
      printf("Enter Language marks: ");
      scanf("%d", &s[i].m.lang);
      sum = s[i].m.chem + s[i].m.gen_aptitude + s[i].m.maths  + s[i].m.pps + s[i].m.lang;
      s[i].m.per = (sum/5);
   }
   printf("Displaying Information:\n\n");

   // displaying information
   for (i = 0; i < student; ++i)
   {
      printf("\nRoll number: %d\n", s[i].roll);
      printf("First name: ");
      puts(s[i].firstName);
      printf("Chemistry: %d", s[i].m.chem);
      printf("\n");
      printf("General Aptitude: %d", s[i].m.gen_aptitude);
      printf("\n");
      printf("Maths: %d", s[i].m.maths);
      printf("\n");
      printf("PPS: %d", s[i].m.pps);
      printf("\n");
      printf("Language: %d", s[i].m.lang);
      printf("\n");
      printf("Percentage: %.3f", s[i].m.per);
      printf("\n");
   }

   // writing information to file
   char *filename = "data.txt";

   // open the file for writing
   FILE *fp = fopen(filename, "w");

   if (fp == NULL)
   {
      printf("Error opening the file %s", filename);
      return -1;
   }

   // write to the text file
   for (int i = 0; i < student; i++)
      fprintf(fp, "\nRoll number: %d\n First Name: %s\n Chemistry: %d\n General aptitude: %d\n Maths: %d\n PPS: %d\n Language: %d\n Percentage: %.3f\n", s[i].roll, s[i].firstName, s[i].m.chem,s[i].m.gen_aptitude,s[i].m.maths,s[i].m.pps,s[i].m.lang,s[i].m.per);

   // close the file
   fclose(fp);

   // sorting the students based on their Percentage
   struct student temp;

   for (int i = 0; i < student; i++)
   {
      for (j = 0; j < student; j++)
      {
         if (s[i].m.per > s[j].m.per)
         {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
         }
      }
   }

   printf("\n\n   SORTED DATA   \n\n");

   // displaying information
   for (i = 0; i < student; ++i)
   {
     
      printf("\nRoll number: %d\n", s[i].roll);
      printf("First name: ");
      puts(s[i].firstName);
      printf("Chemistry: %d", s[i].m.chem);
      printf("\n");
      printf("General Aptitude: %d", s[i].m.gen_aptitude);
      printf("\n");
      printf("Maths: %d", s[i].m.maths);
      printf("\n");
      printf("PPS: %d", s[i].m.pps);
      printf("\n");
      printf("Language: %d", s[i].m.lang);
      printf("\n");
      printf("Percentage: %.3f", s[i].m.per);
      printf("\n");
   }

   // writing sorted information to file
   char *filename1 = "sort_data.txt";

   // open the file for writing
   FILE *fp1 = fopen(filename1, "w");

   if (fp1 == NULL)
   {
      printf("Error opening the file %s", filename1);
      return -1;
   }

   // write to the text file
   for (int i = 0; i < student; i++)
      fprintf(fp, "\nRoll number: %d\n First Name: %s\n Chemistry: %d\n General aptitude: %d\n Maths: %d\n PPS: %d\n Language: %d\n Percentage: %.3f\n", s[i].roll, s[i].firstName, s[i].m.chem,s[i].m.gen_aptitude,s[i].m.maths,s[i].m.pps,s[i].m.lang,s[i].m.per);

   // close the file
   fclose(fp1);

   return 0;
}