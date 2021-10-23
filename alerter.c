#include "stats.h"
#include "alerter.h"

//Function to capture the number of times email alert has been received
void emailAlerter(void)
{
    emailAlertCallCount = emailAlertCallCount + 1;
}

//Function to capture the number of times LED alert has been received
void ledAlerter(void)
{
    ledAlertCallCount = ledAlertCallCount + 1;
}
