#include "stats.h"

//Global variables shared by other .c files
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

// Function to compute min, max and average from the input array of values
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    float sum;
    int arrayIndex;
    sum = 0;
    arrayIndex = 0;
    s.average = 0;
    s.min = 0;
    s.max = 0;
	
    if(numberset != (void *) 0)
    {
	    s.min = s.max = numberset[0];
	    for(arrayIndex=0; arrayIndex<setlength; arrayIndex++)
	    {
		if(s.min>numberset[arrayIndex])
		{
		    s.min=numberset[arrayIndex]; 
		}
		if(s.max<numberset[arrayIndex])
		{
		    s.max=numberset[arrayIndex];
		}
		// Sum to calculate average subsequently 
		sum = (sum + numberset[arrayIndex]);
	    }
	    s.average = (sum / setlength);
    }
    else
    {
	s.min = 0;
	s.max = 0;
	s.average = (0/0);
    }
    // Return the structure with the computed min, max and average values
    return s;    
}

// Function to check and raise alert based on the computed value and the threshold limit
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    // If computedStats.max breaches the maxThreshold value, then raise alert !
    if(computedStats.max > maxThreshold)
    {
	// Raise email alert
	if(alerters[0] != (void*)0)
	{
            alerters[0]();
	}
	// Raise LED alert
	if(alerters[1] != (void*)0)
	{
            alerters[1]();
	}
    }	
}
	

