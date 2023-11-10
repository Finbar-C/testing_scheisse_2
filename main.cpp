#include "mbed.h"
#include <type_traits>

// main() runs in its own thread in the OS
int main()
{
    int delay;
    delay = 2;
    for (int x = 0; x < 10; x++) {
        thread_sleep_for(delay);
        delay = delay * 2;
        printf("Guten Tag\n");
    }
}
