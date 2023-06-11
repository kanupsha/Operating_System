#include<unistd.h>
#include <stdio.h>
#include<stdlib.h>

  int PC;
  int IR0;
  int IR1;
  int  AC;
  int MAR;
  int MBR;
  int Base;
  int opcode;
  int operand;
extern int Mem[];




 void cpu_fetch_instruction() 
  { 
   
       
    // PC = Base;
    MAR=PC;
    mem_read();
    IR0=MBR;
      ++PC;
    MAR=PC;
    mem_read();
    IR1=MBR;
    ++PC;
    // printf("%d ",IR0);
    // printf("%d ",IR1);

    
  }

  void cpu_execute_instruction() 
  {
     opcode = IR0;
     operand = IR1;
     int time;
  

    switch(opcode)
      {
      case 1:
      AC = operand;
      
      break;

      case 2:
      MBR=cpu_mem_address(operand);
      AC = MBR;
      // printf("%d",AC);
      // printf("%s","case2\n");
      
      break;
     
      case 3:
      MBR = cpu_mem_address(operand);
      AC = AC + MBR;
      // printf("%d",AC);
      // printf("%s","case3");

      break; 

      case 4:
      MBR = cpu_mem_address(operand);
      AC = AC * MBR;
      // printf("%s","case4");

      break;
     
      case 5:
      MAR=operand+Base;
      MBR=AC;
      mem_write();
      //  printf("%d",AC);
      // printf("%s","case5");

      break;
     
      case 6:
      if (AC>0){        
        PC=cpu_mem_address(operand);
	//	printf("%s","case6");

        }
      break; 
     
      case 7:
      printf("\nAC:%d",AC);
       printf("\n");

      break;
      
      case 8:
      time=operand;
      sleep(time);
      // printf("%s","case8");

      break;

      case 9:
      shell_command(operand);
      // printf("%s","case9");

      break;
            
      case 0:
	// printf("%s","case0");
	 exit(0);
	 break;
      }
  
  }


int cpu_mem_address(int maddr)
{
  int val;
  MAR =maddr+Base;
  val=Mem[MAR];
  return val;
 
}

void cpu_operation()
{ 
  PC=Base;
   opcode=777; 
  //    printf("%d",Base);
  
  while(opcode!=0)
    {
      cpu_fetch_instruction();
      cpu_execute_instruction();
  }
}
