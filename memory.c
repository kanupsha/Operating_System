#include<stdio.h>


extern int M;
extern int MAR;
extern int MBR;
int Mem[255];

void mem_init(M)
{
  int i;
  
  for (i=0; i<M; i++)
    Mem[i]=0;
}
int mem_read()
{
  MBR=Mem[MAR];
}

void mem_write()
{
  Mem[MAR]=MBR;
}


