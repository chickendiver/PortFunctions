#include <conio.h>
#include <stdio.h>
#include <windows.h>
 
typedef short (_stdcall * inpfuncPtr ) ( short portaddr );
typedef void ( _stdcall * oupfuncPtr ) ( short portaddr, short datum );
 
main()
{
  HINSTANCE hLib;
  inpfuncPtr inp32;
  oupfuncPtr oup32;
 
  short InValue; //Value
  int OutAddress = 0x378; //Port Address
  int i;
  short j;
 
  // Load the library
  hLib = LoadLibrary( "inpout32.dll" );
 
  if ( hLib == NULL ) //If Load Fails
  {
    printf( "LoadLibrary Failed.\n" );
    return -1;
  }
 
  // Get the address of the function
  inp32 = ( inpfuncPtr )GetProcAddress( hLib, "Inp32" );
 
  if ( inp32 == NULL )
  {
    printf( "GetProcAddress for Inp32 Failed.\n" );
    return -1;
  }
 
 
  oup32 = ( oupfuncPtr )GetProcAddress( hLib, "Out32" );
 
  if ( oup32 == NULL )
  {
    printf( "GetProcAddress for Oup32 Failed.\n" );
    return -1;
  }

//------------------------------------------------------------
  //printf("INITIALIZING PORT\n");
  //(oup32)(0x307, 0x9B);
  //(oup32)(0x378, 0x0000);
  //printf("PORT INIT FINISHED\n");

  for (j = 0x201;j<=0x201;j++)
  {
    printf("INITIATING READ OF PORT %04x\n", j);
    for(i = 100;i>0;i--)
    {
      InValue = (inp32)(j);
      printf("%04x \n", InValue);
      Sleep(100);
    }
  }
  printf("FINISHED READ\n");
  return 0;
}