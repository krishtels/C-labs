#include <assert.h>
#include "main.h"

void test() {
    assert(YearLength(2,314) - 0.04 < 0.001);
    assert(YearLength(315,628) - 3.15 < 0.001);
    assert(Distance(10, 13, 5, 26, 10) - 13 < 0.001);
    assert(Distance(14, 112, 12, 28, 3) - 84 < 0.001);
    assert(Power(100, 1, 2) - 13.34 < 0.001);
    assert(Power(90, 3, 10) - 6.67 < 0.001);
}

#undef main
int main() {
    test();
    return 0;
}