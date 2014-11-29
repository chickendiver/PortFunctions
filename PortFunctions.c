#include <Python.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

// -----------------------------------------------------------
// Inputs a port number in hex and outputs a hex value read from the port

typedef short (_stdcall * inpfuncPtr ) ( short portaddr );
typedef void ( _stdcall * oupfuncPtr ) ( short portaddr, short datum );

static short portRead(short port)
{
  HINSTANCE hLib;
  inpfuncPtr inp32;
  oupfuncPtr oup32;
 
  short InValue; //Value
 
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

  printf("INITIATING READ OF PORT %04x\n", port);

  InValue = (inp32)(port);
  printf("%04x \n", InValue);
  printf("FINISHED READ\n");
  return InValue;
}

// -----------------------------------------------------------


// The function called by Python which invokes the local function read()
static PyObject *PortFunctions_readPort( PyObject *self, PyObject *args ){
	short readValue;
	short portToRead;

	if (!PyArg_ParseTuple(args, "h", &portToRead)) {
      		return NULL;
   	}
	
	readValue = portRead(portToRead);
	printf("TEST: %04x \n", readValue);
	return Py_BuildValue("h", readValue);
}


// Method mapping table for PortFunctions
static PyMethodDef PortFunctions_methods[] = {
   	{ "readPort", (PyCFunction)PortFunctions_readPort, METH_VARARGS, "The function called by Python which invokes the local function read()"},
  	{ NULL, NULL, 0, NULL }
};

// Initialization function for the module (PortFunctions)
PyMODINIT_FUNC initreadPort() {
	Py_InitModule3("readPort", PortFunctions_methods, "a function which allows the user to directly read from Windows ports. Takes port in hex as input, outputs read value in hex to 4 places.");
}
