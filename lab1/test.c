#include <assert.h>
#include "main.h"

int test() {
    assert(check(100) == 0);
    assert(check(370) == 1);
    assert(check(407) == 1);
    assert(check(999) == 0);
}
#undef main
int main() {
    test();
}
