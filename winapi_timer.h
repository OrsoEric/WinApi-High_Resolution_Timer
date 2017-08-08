/**********************************************************************************
**	ENVIROMENT VARIABILE
**********************************************************************************/

#ifndef WINAPI_TIMER_H_
	#define WINAPI_TIMER_H_

//Enable the code that rounds the period to the nearest time step
//#define WINAPI_TIMER_ROUND

/**********************************************************************************
**	GLOBAL INCLUDES
**********************************************************************************/

/**********************************************************************************
**	DEFINES
**********************************************************************************/

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

	///--------------------------------------------------------------------------
	///	Winapi_timer
	///--------------------------------------------------------------------------

//Maximum number of concurrent timers
#define WINAPI_MAX_TIMERS	1

//Minimum timer resoltion. Also the time slice of the scheduler.
//A timer that is not a int multiple of this will have irregular period
#define WINAPI_TIME_STEP	5

	///--------------------------------------------------------------------------
	///	Winapi_chrono
	///--------------------------------------------------------------------------

//maximum concurrent chrono reading
#define WINAPI_MAX_CHRONOS	4
//Error code
#define WINAPI_CHRONOS_ERR	-1.0

/**********************************************************************************
**	MACROS
**********************************************************************************/

/**********************************************************************************
**	TYPEDEF
**********************************************************************************/

/**********************************************************************************
**	PROTOTYPE: STRUCTURE
**********************************************************************************/

/**********************************************************************************
**	PROTOTYPE: GLOBAL VARIABILE
**********************************************************************************/

/**********************************************************************************
**	PROTOTYPE: CLASS
**********************************************************************************/

/****************************************************************************
**	Class
**	Winapi_timer
*****************************************************************************
**	This class is meant to handle repeatable timers with callback function
****************************************************************************/

class Winapi_timer
{
	//Visible to all
	public:
		///--------------------------------------------------------------------------
		///	CONSTRUCTORS
		///--------------------------------------------------------------------------

		//Empty constructor
		Winapi_timer( void );
		//Frequency constructor
		Winapi_timer( int freq, WAITORTIMERCALLBACK callback );
		//Period Constructor
		//Winapi_timer( float period, WAITORTIMERCALLBACK callback );

		///--------------------------------------------------------------------------
		///	DESTRUCTORS
		///--------------------------------------------------------------------------

		//Destructor
		~Winapi_timer();

		///--------------------------------------------------------------------------
		///	SETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	GETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	TESTERS
		///--------------------------------------------------------------------------

		//TRUE: the tmer is up and running
		//bool is_running( void );

		///--------------------------------------------------------------------------
		///	PUBLIC METHODS
		///--------------------------------------------------------------------------

		//Add a timer to the timer queue
		//bool add_timer( int period_ms, WAITORTIMERCALLBACK callback_function );

		///--------------------------------------------------------------------------
		///	PUBLIC VARS
		///--------------------------------------------------------------------------

	//Visible to derived classes
	protected:
		///--------------------------------------------------------------------------
		///	PROTECTED METHODS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PROTECTED VARS
		///--------------------------------------------------------------------------

	//Visible only inside the class
	private:
		///--------------------------------------------------------------------------
		///	PRIVATE METHODS
		///--------------------------------------------------------------------------

		//Create a timer queue
		bool born_timer_queue( void );
		//create a timer within a timer queue
		bool born_timer( int period_ms, WAITORTIMERCALLBACK callback );
		//calculate delay in mS rounded to the nearest resolution
		int from_freq( int freq );
		//calculate delay in mS from period in S. round to nearest resolution step
		//int from_period( float period );
		//release all timers
		//bool release( void );
		//Initialize class vars to thir default value
		void init_vars( void );
		//Here so that i can easly copy the code.
		bool dummy( void );

		///--------------------------------------------------------------------------
		///	PRIVATE VARS
		///--------------------------------------------------------------------------

		//number of timers currently active
		int g_num_timer;
		//Timer queue. It's a special thread inside the kernel
		HANDLE g_timer_queue;

		HANDLE g_timer[WINAPI_MAX_TIMERS];

};	//End Class: Winapi_timer

/****************************************************************************
**	Class
**	Winapi_chrono
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	This class is a wrapper to the performance counters.
**	It provides chronometer functionality.
****************************************************************************/

class Winapi_chrono
{
	//Visible to all
	public:
		///--------------------------------------------------------------------------
		///	CONSTRUCTORS
		///--------------------------------------------------------------------------

		//Empty constructor
		Winapi_chrono( void );

		///--------------------------------------------------------------------------
		///	DESTRUCTORS
		///--------------------------------------------------------------------------

		//Default constructor
		~Winapi_chrono( void );

		///--------------------------------------------------------------------------
		///	SETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	GETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	TESTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PUBLIC METHODS
		///--------------------------------------------------------------------------

		//Start time [index]
		void start( int index );
		//Stop time [index]. Get DeltaT in Seconds. Stop doesn't change start. Multiple stop refers to same start. Return 0.0 if no start
		float stop( int index );
		//Stop than start
		float stop_start( int index );
		//snap processor frequency. Automatically done by constructor. Can be done by user.
		void get_freq( void );

		///--------------------------------------------------------------------------
		///	PUBLIC VARS
		///--------------------------------------------------------------------------

	//Visible to derived classes
	protected:
		///--------------------------------------------------------------------------
		///	PROTECTED METHODS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PROTECTED VARS
		///--------------------------------------------------------------------------

	//Visible only inside the class
	private:
		///--------------------------------------------------------------------------
		///	PRIVATE METHODS
		///--------------------------------------------------------------------------

		//Initialize all vars to safe value.
		void init_vars( void );
		//Here so that i can easly copy the code.
		bool dummy( void );

		///--------------------------------------------------------------------------
		///	PRIVATE VARS
		///--------------------------------------------------------------------------

		//Processor frequency
		LARGE_INTEGER g_freq;
		//Start time. tme delta are referred to this
		LARGE_INTEGER g_start[WINAPI_MAX_CHRONOS];
};	//End Class:


#endif
