#include "menu.h"
#include "main.h"
#include "statusData.h"
#include "gatcha.h"
#include "initialGame.h"
#include "load.h"
#include "end.h"
#include "gallery.h"
#include "cardPackage.h"
#include "numberCount.h"

double RandomRangeNumber(double a, double b)
{
    double result = 0.0;
    result = (b - a) * rand() / RAND_MAX + a;
    return result;
}

int intFlow(int x, double range)
{
    int result = 0;
    result = (double)x * (1.0 + RandomRangeNumber(-range, range));
    return (int)result;
}

double doubleFlow(double x, double range)
{
    double result = 0.0;
    result = x * (1.0 + RandomRangeNumber(-range, range));
    return result;
}
