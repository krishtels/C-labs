#include <assert.h>
#include "main.h"

void test() {
    assert(check(100) == 0);
    assert(check(370) == 1);
    assert(check(407) == 1);
    assert(check(999) == 0);
    assert(power(2) == 8);
    assert(power(3) == 27);
    assert(power(4) == 64);
}
#undef main
int main() {
    test();
    return 0;
}
