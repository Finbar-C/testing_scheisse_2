#include "mbed.h"
#include <type_traits>

void flash(int num_flashes, DigitalOut target) {
        for (int x=0; x<num_flashes; ++x) {
            target = true;
            thread_sleep_for(100);
            target = false;
            thread_sleep_for(200);
        }
    }

// main() runs in its own thread in the OS
int main()
{
    DigitalOut Green(D5);
    DigitalOut Yellow(D4);
    DigitalOut Red(D3);
    DigitalOut Blue(D2);

    flash(1, Green);
    flash(2, Yellow);
    flash(3, Red);
    flash(4, Blue);

    int flashes;
    char choice;

    while(true) {
        printf("Test point");
        scanf("\nEnter the choice of LED to flash (R, Y, G, B): %c", &choice);
        scanf("\nEnter the number of times to flash: %d", &flashes);
        switch (choice) {
            case 'R':
                flash(flashes, Red);
            case 'Y':
                flash(flashes, Yellow);
            case 'G':
                flash(flashes, Green);
            case 'B':
                flash(flashes, Blue);
            default:
                printf("Invalid input format\n");
        }
    }
}
