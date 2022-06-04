//================================================== file = timeitWin.c =====
//=  Program to time program execution using precision timers               =
//===========================================================================
//=  Notes:                                                                 =
//=    1) This program compiles only for Windows and uses functions         =
//=       QueryPerformanceFrequency() and QueryPerformanceCounter()         =
//=    2) Input is prompted from user (to enter their name)                 =
//=    3) Output is to stdout                                               =
//=    4) The accuracy of this program is a function of the internal        =
//=       counter where accuracy can vary if the CPU speed varies.          =
//=    5) Code inspiration from:                                            =
//=       http://stackoverflow.com/questions/1739259/                       =
//=         how-to-use-queryperformancecounter                              =
//=-------------------------------------------------------------------------=
//= Example execution:                                                      =
//=                                                                         =
//=   --------------------------------------------- timeitWin.c -----       =
//=     Enter your full name =====> Ken C.                                  =
//=     Your name is Ken C. and it took 2981.233 millisec to execute        =
//=   ---------------------------------------------------------------       =
//=-------------------------------------------------------------------------=
//=  Build: cl timeitWin.c, bcc32 timeinWin.c                               =
//=-------------------------------------------------------------------------=
//=  Execute: timeitWin                                                     =
//=-------------------------------------------------------------------------=
//=  Author: Ken Christensen                                                =
//=          University of South Florida                                    =
//=          WWW: http://www.csee.usf.edu/~christen                         =
//=          Email: christen@csee.usf.edu                                   =
//=-------------------------------------------------------------------------=
//=  History: KJC (02/13/14) - Genesis (from timeit.c)                      =
//===========================================================================
//----- Include files -------------------------------------------------------
#include <stdio.h>          // Needed for printf()
#include <windows.h>        // Needed for QueryPerformance functions
#include "ListaDinamica.h"

//===========================================================================
//=  Main program                                                           =
//===========================================================================
double CalculaTempo (void (*func)(void*), ListaDinamica *Lista)
{
  double        pcFreq;        // Counter frequency (timer resolution)
  __int64       counterStart;  // Timer value
  LARGE_INTEGER li;            // Large interger for timer value
  double        elapsed;       // Elapsed time in seconds
  int           retcode;       // Return code


  // Get frequency of counter
  retcode = QueryPerformanceFrequency(&li);
  if (retcode == 0)
    printf("*** ERRO - QueryPerformanceFrequency() falhou \n");
  pcFreq = li.QuadPart;

  // Start timing (read current counter value)
  QueryPerformanceCounter(&li);
  counterStart = li.QuadPart;

  // Task to be timed
//  int Max, Min;
  func(Lista);
  //MaxMin1Estatico(Lista, Max, Min);

  //printf("Aqui Min: %d\nMax: %d\n",*Min,*Max);

  // Stop timing (read current counter value) and determine elapsed time
  QueryPerformanceCounter(&li);
  elapsed = 1000.0 * ((li.QuadPart - counterStart) / pcFreq);

  return elapsed;
}
