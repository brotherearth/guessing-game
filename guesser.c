#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
  char *buffer;
  size_t bufsize = 32;
  size_t characters;
  int num = (rand() * rand() % rand());



  buffer = (char *)malloc(bufsize * sizeof(char));
  if( buffer == NULL)
  {
    perror("Unable to allocate buffer");
    exit(1);
  }

  printf("Ask me something, but be warned: I'm not smart\n");
  characters = getline(&buffer,&bufsize,stdin);


  if (strcmp(buffer, "What is your name?\n") == 0)
    printf("Bob\n"); 
  else
  {
  	printf("???");
    exit(0);	
  }

  getline(&buffer,&bufsize,stdin);

  if (strcmp(buffer, "What is the magic number, Bob?\n") == 0)
  	printf("%d\n", num);
  else
  {
  	printf("???");
    exit(0);	
  }    
  getline(&buffer,&bufsize,stdin);
  exit(0);
} 
