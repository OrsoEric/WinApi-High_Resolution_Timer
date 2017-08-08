# WinApi-High_Resolution_Timer
This is a wrapper for the windows API with a simple example. It measure the shortest measurable time and wait 1s.

# Chrono Class
winapi.h/.cpp
This file contains the winapi_timer and winapi_chrono class. 
The core functions it wraps are:
CreateTimerQueue
QueryPerformanceFrequency
QueryPerformanceCounter

# winapi_utils.h/.cpp
This file contains more general wrappers for the windows API
Stuffs about handle, threads etc...

# How it works
Using QueryPerformanceCounter require the user several steps
getting QueryPerformanceFrequency
calling QueryPerformanceCounter two times
and use a formula to get the TeltaT
the type LARGE_INTEGER is a wrapper for u64


Winapi_chrono()
This class add a layer of abstraction, the timer becomes several indipendent start/stop timers

Winapi_chrono::Winapi_chrono( void )
  The constructor initialize the class. Get the frequency.
  
Winapi_chrono::start( index )
  Start the timer of index [index]
  
Winapi_chrono::stop( index )
  Get the time passed since start

Winapi_chrono::stop_start( index )
  Get the time, than reset the timer
  
Winapi_chrono~Winapi_chrono( void )
  Destroy all underlying structures
