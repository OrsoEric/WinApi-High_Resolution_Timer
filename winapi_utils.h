/**********************************************************************************
**	ENVIROMENT VARIABILE
**********************************************************************************/

#ifndef WIN_API_UTILS_H_
	#define WIN_API_UTILS_H_

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


//Maximum users allowed
#define WINAPI_UTILS_SEM_MAX_USERS		10

/**********************************************************************************
**	MACROS
**********************************************************************************/

//handle have a special invalid value (0xf..f). NULL is 0x0..0)
#define IS_BAD_HANDLE( handle )	\
	((handle == NULL) || (handle == INVALID_HANDLE_VALUE))

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

using namespace std;

/****************************************************************************
**	Class
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

class Winapi_utils
{
	//Visible to all
	public:
		///--------------------------------------------------------------------------
		///	CONSTRUCTORS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	DESTRUCTORS
		///--------------------------------------------------------------------------

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

		///--------------------------------------------------------------------------
		///	PUBLIC STATIC METHODS
		///--------------------------------------------------------------------------

			///--------------------------------------------------------------------------
			///	MISCELLEANOUS UTILITY FUNCTION
			///--------------------------------------------------------------------------

		//Get a random float
		static float rand_float( float min, float max );

			///--------------------------------------------------------------------------
			///	HANDLE
			///--------------------------------------------------------------------------

		//Close an handle. FALSE -> OK
		static bool close_handle( HANDLE htmp );

			///--------------------------------------------------------------------------
			///	Performance Counter
			///--------------------------------------------------------------------------
			//		System Call that get the performance counter value
			//	QueryPerformanceCounter( &time_stamp );
			//		System call that get the frequency of the system
			//	QueryPerformanceFrequency( &freq );
			//

		//Calculate the difference in tick between two timestamps
		static LARGE_INTEGER deltat( LARGE_INTEGER scnt, LARGE_INTEGER ecnt );
		//Calculate the difference in tick between two timestamps
		static float deltat( LARGE_INTEGER scnt, LARGE_INTEGER ecnt, LARGE_INTEGER freq );
 		//Calculate elapsed time
		static float time_calc( LARGE_INTEGER scnt, LARGE_INTEGER ecnt );

			///--------------------------------------------------------------------------
			///	QueueTimer
			///--------------------------------------------------------------------------


			///--------------------------------------------------------------------------
			///	Semaphores
			///--------------------------------------------------------------------------

		//Create a semaphore
		static HANDLE born_sem( int max_users );
		//Reserve a semaphore. return == FALSE: OK
		static bool lock_sem( HANDLE hsem, int timeout );
		//Release a semaphore. return == FALSE: OK
		static bool unlock_sem( HANDLE hsem );

			///--------------------------------------------------------------------------
			///	Threads
			///--------------------------------------------------------------------------

		//Suspend a thread. Simple wrapper that prints errors
		static bool pause_thread( HANDLE hthread );
		//Resume a thread. return == FALSE: OK
		static bool resume_thread( HANDLE hthread );

		///--------------------------------------------------------------------------
		///	PUBLIC VARS
		///--------------------------------------------------------------------------

	//Visible to derived classes
	protected:
		///--------------------------------------------------------------------------
		///	PROTECTED VARS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PROTECTED METHODS
		///--------------------------------------------------------------------------

	//Visible only inside the class
	private:
		///--------------------------------------------------------------------------
		///	PRIVATE VARS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PRIVATE METHODS
		///--------------------------------------------------------------------------
		//Here so that i can easly copy the code.
		bool dummy( void );
};

#else
	#error "multiple inclusion of H"
#endif
