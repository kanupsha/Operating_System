#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern int PC;
extern int IR0;
extern int IR1;
extern int  AC;
extern int MAR;
extern int MBR;
extern int Base;
//extern int M;
extern int Mem[];
//extern int base;

int PCi=0;
int MARi=0;
int MBRi=0;
int IR0i=0;
int IR1i=0;
int ACi=0;
int basei=0;
int PIDi=0;
int M;
char filename[50];
int base;
int PID;

void process_init_PCB();
void process_set_registers();
void boot_system(int);

int main()

{ 
  int input;
  int K;
  
  FILE* fptr;
  // code for reading using shell script execute
  /*
  FILE *fp;
  gets(fp);
  char c[50];

  //  strcpy(c,fp);
 
  c = fgetc(fp);
  while (c != EOF)
    {
      printf ("%s", c);
      c = fgetc(fp);
    }
  */
 
  // printf("%s",c);
  
  fptr = fopen("config.sys", "r");
 
  fscanf(fptr,"%d",&M); 
  while (!feof (fptr))
    {  
     
      fscanf (fptr, "%d", &M);      
    }

 
  //  printf("%d",M);
  boot_system(M);
 
  
  printf("Input Program File and Base> ");
  scanf("%s%d",&filename,&Base);
  load_prog(&filename,Base);
  
  //   process_init_PCB();
  // process_set_registers();
  
  cpu_operation();

  /* Will use later projects as vlaues of memory and registers are printed in cpu.c itself    
  printf("\nPlease select command code:\n 1.Initialize shell module \n 2.Values of all the registers \n 3.Values of Memory \n 4.Exit\n ");
  scanf("Enter choice: %d",&input);
  shell_command(input);
  */
 
  //  fclose(fp);  /* close the file */ 
  fclose(fptr);  /* close the file */ 

  return(0);
 }
void boot_system(int K)

{
  mem_init(K);

}

void process_init_PCB()
{

  PCi=0;
  MARi=0;
  MBRi=0;
  IR0i=0;
  IR1i=0;
  ACi=0;
  //  basei=0;
  PIDi=0;

}
void process_set_registers()
{

  PC= PCi;
  MAR=MARi;
  MBR=MBRi;
  IR0=IR0i;
  IR1=IR1i;
  AC=ACi;
  // Base=base;
  PID=PIDi;

}
