#include <math.h>
#include "stats.h"


//Global variables shared by other .c files.
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

// Function to compute min, max and average from the input array of values.
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats computedStatistics;
    computedStatistics.min = 0;
    computedStatistics.max = 0;
    computedStatistics.average = 0;
    float sum = 0;
    int arrayIndex = 0;
	
    // Check if the array passed is not NULL.
    if(numberset != (void *) 0)
    {
    	computedStatistics.min = computedStatistics.max = numberset[0];
    	for(arrayIndex=0; arrayIndex<setlength; arrayIndex++)
    	{
	    if(computedStatistics.min>numberset[arrayIndex])
	    {
	        computedStatistics.min=numberset[arrayIndex]; 
	    }
	    if(computedStatistics.max<numberset[arrayIndex])
	    {
	        computedStatistics.max=numberset[arrayIndex];
	    }
	    // Sum to calculate average subsequently after the for loop termination
	    sum = (sum + numberset[arrayIndex]);
        }
        computedStatistics.average = (sum / setlength);
    }
    // If the array passed is NULL then set min, max and average values to NAN (Not A Number).
    else
    {
	computedStatistics.min = NAN;
	computedStatistics.max = NAN;
	computedStatistics.average = NAN;
    }
    // Return the structure with the computed min, max and average values.
    return computedStatistics;    
}

// Function to check and raise alert based on the computed value and the threshold limit
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    // If computedStats.max breaches the maxThreshold value, then raise alert !
    if(computedStats.max > maxThreshold)
    {
	// Check if the function pointer is not NULL
	if(alerters[0] != (void*)0)
	{
	    // Raise email alert
            alerters[0]();
	}
	// Check if the function pointer is not NULL
	if(alerters[1] != (void*)0)
	{
 	    // Raise LED alert
            alerters[1]();
	}
    }	
}
	

