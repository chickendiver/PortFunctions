from distutils.core import setup, Extension

data_files = [("DLLs", ["inpout32.dll"])]

setup(name='PortFunctions', version='1.1',
      description = 'A Windows port reader for Python, built in C',
      author = 'Bradley Poulette',
      author_email = 'bpoulett@ualberta.ca',
      data_files = data_files,
      ext_modules=[Extension('readPort', ['PortFunctions.c'])])
