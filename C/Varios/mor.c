
#include <ctype.h>
#define D 'a'-1
#define TRUE 1
#define FALSE 0
#include <stdio.h>

void encrypt();
void decrypt();

void main()
{
  int n;
  printf("Please enter a text to encrypt\n");
  encrypt();
  printf("\nPlease enter a text to decrypt\n");
  decrypt();
}

void encrypt()
{
  int c;
  while((c=getchar())!='\n')
  {
    if(isalpha(c))
    {
      c=tolower(c);
      c-=D;
      if(c<10)
	printf("0%d", c);
      else
	printf("%d", c);
    }
  }
}

void decrypt()
{
  int n;
  int number;
  int two_dig=FALSE;
  while((n=getchar())!='\n')
  {
    if(two_dig==FALSE)
    {
      n-=48;
      number=(n*10);
      two_dig=TRUE;
    }
    else
    {
      n-=48;
      number+=n;
      number+=96;
      two_dig=FALSE;
      printf("%c", number);
    }
  }
}
