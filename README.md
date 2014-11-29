PortFunctions V 0.1.0
=============

A Python extension module written in C which reads port values on Windows machines. 

The module currently contains only one function: readPort(port).

To use this function in Python:

    import readPort
    readPort.readPort(port)

  Where "port" is a hexadecimal value representing the port's address (Ex.: 0x0201).

To install using a GUI:
  Run "readPort-1.0.win32-py2.7" from within the "dist" folder.
  
To install from the command line:

  Navigate to this directory and type "C:\Python27\python setup.py install"
