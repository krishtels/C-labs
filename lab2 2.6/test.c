#include <assert.h>
#include "main.h"

void test() {
    assert(Fact(3)==6);
    assert(Fact(4)==24);
    assert(FactLoop(4, 2)==24);
    assert(FactLoop(3, 1)==6);
    assert(CountN(3, 0.5, 1, 0)==3);
}

#undef main
int main() {
    test();
    return 0;
}