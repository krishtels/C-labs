#include <assert.h>
#include <math.h>
#include "main.h"

void test() {
    assert(fabs(YearLength(2,314) - 0.04) < 0.001);
    assert(fabs(YearLength(315,628) - 3.15) < 0.001);
    assert(fabs(Distance(10, 13, 5, 26, 10) - 13) < 0.001);
    assert(fabs(Distance(14, 112, 12, 28, 3) - 84) < 0.001);
    assert(fabs(Power(100, 1, 2) - 13.34) < 0.001);
    assert(fabs(Power(90, 3, 10) - 6.67) < 0.001);
}

#undef main
int main() {
    test();
    return 0;
}