from distutils.core import setup, Extension
setup(name='PortFunctions', version='1.0',
      description = 'A Windows port reader for Python, built in C',
      author = 'Bradley Poulette',
      author_email = 'bpoulett@ualberta.ca',
      ext_modules=[Extension('readPort', ['PortFunctions.c'])])
