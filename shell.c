#include<stdio.h>
#include<stdlib.h>
extern int PC;
extern int IR0;
extern int IR1;
extern int  AC;
extern int MAR;
extern int MBR;
extern int Base;
extern int M;
extern int Mem[];
extern int base;

void shell_init()
{

}


void shell_print_registers()
{
  printf("\n=============================================\n");
    printf("\n      Register Dump\n");
    printf("\n=============================================\n");
                
  printf("\nPC:%d",PC);
  printf("\nIR0:%d",IR0);
  printf("\nIR1:%d",IR1);
  printf("\nAC:%d",AC);
  printf("\nMAR:%d",MAR);
  printf("\nMBR:%d",MBR);
  printf("\nBase:%d\n",Base);
}

void shell_print_memory()
{
  printf("\n=============================================\n");
    printf("\n      Memory Dump\n");
    printf("\n=============================================\n");

  printf("\n");
  int i;
  for (i=0; i<M; i++)
    {
      printf("%d ,",Mem[base + i] );   
      
    }
  printf("\n");
}

void shell_command (int cmd)
{

  int j;
  switch(cmd)
    {
    case 1:
      printf("Initialize the shell module");
      break;
    case 2:
      printf("\nDumping the values of registers\n");
      shell_print_registers();
      break;
      
    case 3:
      printf("\nDumping the values of memory\n");
      shell_print_memory();
      break;
    case 4:
      exit(0);
      break;

    }

}
