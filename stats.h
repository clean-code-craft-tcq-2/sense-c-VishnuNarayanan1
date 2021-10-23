
struct Stats
{
    float average;
    float min;
    float max;
};

struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

// Extern is applied as it is being used by alerter.c file also
extern int emailAlertCallCount;
extern int ledAlertCallCount;

