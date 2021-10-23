#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    float indexedArrayElement,sum;
    int arrayIndex;
    indexedArrayElement = 0;
    sum = 0;
    arrayIndex = 0;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
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
        sum = (sum + numberset[arrayIndex]);
    }
    s.average = (sum / setlength);
    return s;
    
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
