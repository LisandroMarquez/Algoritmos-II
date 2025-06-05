#include <stdbool.h>
#include <stdio.h>

#include "weather_table.h"
#include "queries.h"

#define N_TESTCASES 5

struct testcase {
    int year;
    int result;
};

int main(void) {
    WeatherTable a;

    struct testcase tests[N_TESTCASES] = {
        // año, resultado
        {1980, 27},
        {1985, 40},
        {1990, 29},
        {2000, 27},
        {2005, 19},
    };

    int result;
    
    table_from_file(a, "../input/weather_cordoba.in");

    printf("TESTING year_min_moisture\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = year_min_moisture(a, tests[i].year);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED: expected %i but got %i\n", tests[i].result, result);
        }
    }

    return 0;
}
