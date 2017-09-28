#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINESZ 1024

int main ( int argc, char *argv[] )
{
    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else 
    {
        struct user {
	    int id;
	    char name[64];
	};     
	char buff[LINESZ];
	char usrnm[64];
	// We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );
        
	/* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
            int count = 0;
	    int num;
	    int i;
	    char c;
            
	    printf("What is your name: ");
	    scanf("%64s", usrnm);
	    printf("\nWhat is the magic number, %s: ", usrnm);
	    scanf("%d", &num); 
 	    // count the number of lines of the file
	    for (c = fgetc(file); c != EOF; c = fgetc(file))
                if (c == '\n')
            	  count = count + 1; 
	
	    // create local array of users
	    struct user users[count];
	    rewind(file);

	    // for each line in file, populate that line in user array
	    for (i = 0; i < count; i++)
	    {
                while (fgets (buff, LINESZ, file)) 
	        {
		    sscanf(buff, "%s%d", users[i].name, &users[i].id);
		    if (strcmp(usrnm, users[i].name) == 0)
	   	    {	
	                if (num == users[i].id) printf("\nYou nailed it\n");
		        else if (num > users[i].id) printf("\nToo High\n");
		        else printf("\nTOO LOW\n");
	                goto end;  
	  	    }
	        }
		if (i == (count -1))
		    printf("\nuser not found\n");
	    }
	}
	    end:
	      fclose(file);
	    
        }
    
}
