/*
 * CS1050
 * Fall 2024
 * Prelab 13
 * by Jim Ries
 */
#include <stdio.h>

// Symbolic Constants
#define FILENAME "DnDMonsterScores.csv"

// Main
int main(void)
{
    FILE * fp;
    char name[256];

    fp = fopen(FILENAME,"r");
    if (NULL!=fp)
    {
        // Throw away the blank line
        fgets(name,255,fp);

        // Read the header line and print it
        fgets(name,255,fp);
        name[255]='\0';
        printf("Header line was: %s\n",name);

        // Variables for each field in the csv file
        int ac,hp,str,dex,con,intel,wis,cha;

        // Note that my code just reads the first data line in the csv.  You will
        // want to read all of the lines, right?

        // fscanf() returns the number of fields it successfully read.  We asked for 9, so
        // if we didn't get 9, then something must be wrong.  Notice also that the first field
        // is "anything but a comma" because the names might have spaces in them.  Notice also
        // that I am reusing the name variable.
        if (9==fscanf(fp," %[^,],%d,%d,%d,%d,%d,%d,%d,%d,",name,&ac,&hp,&str,&dex,&con,&intel,&wis,&cha))
        {
            printf("\"%s\" : AC=%d,HP=%d\n",name,ac,hp);
        }
    }

    // Make your mama proud and clean up after yourself!
    fclose(fp);
}
