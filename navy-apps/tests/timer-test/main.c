#include <stdio.h>
#include <NDL.h>

int main() {
    long int elapsed_time = 0; // elapsed_time in microseconds
    const long int interval = 500; // 0.5 seconds in microseconds
    uint32_t start_time = NDL_GetTicks();

    while (1) {
        uint32_t current_time = NDL_GetTicks();
        // Calculate elapsed time in microseconds
        if (current_time - start_time >= interval) {
            printf("Half a second has passed!\n");
            // Reset start_time for the next interval
            start_time = current_time;
        }
    }

    return 0;
}
