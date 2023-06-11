#include<stdio.h>
#include<string.h>
extern int Mem[];
extern int M;

void load_prog(char *fname, int base)
{
  int i=0;
  int num;
  FILE *fptr;
  char str[50];
 
   
  strcpy(str,fname);
  //    printf("%s",str);

   fptr = fopen(str,"r");

  if (NULL == fptr) {
    printf("file can't be opened \n");
  }
   
  while (fscanf(fptr,"%d",&num)>0)
    {
      Mem[base+i]=num; 
      printf ("%d ", Mem[base+i]);
      i++;      
    }

  fclose (fptr);  
 

}

void load_finish(FILE *f)
{

  f = fopen("fname", "w");
  fclose(f);

}
