//+ Imports
#include <stdio.h>
#include <stdbool.h>

//+ Data Types
const int N = 5;
struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

//+ Functions
struct bound_data check_bound(int value, int arr[], int length) {
    //# Init Vars
    struct bound_data res;
    bool less = true, more = true;
    res.exists = false;

    //% Main Loop
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            if (!res.exists) {
                res.exists = true;
                res.where = i;
            }
            res.exists = true;
        } else if (arr[i] >= value) {
            more = false;
        } else if (arr[i] <= value) {
            less = false;
        } else {
            printf("Nigga that's not possible ????");
        }
    }

    //& Set res values
    res.is_lowerbound = less;
    res.is_upperbound = more;

    //! Return
    return res;
}

//+ Main
int main(void) {
    //# Init Vars
    struct bound_data result; 
    int pos = 0, value, array[N];

    //? Loop for insert data into array
    while(pos < N) {
        //% Required input
            printf("Ingresa el valor para A[%d]: ", pos);
            scanf("%d", &array[pos]);
            pos++;
    } pos = 0;

    //% Ask for a value
    printf("\nIngresa un valor para buscar en el array: ");
    scanf("%d", &value);

    //? Call functions
    result = check_bound(value, array, N); 

    //* Output
    printf("El valor '%d', es el mayor de todo el arreglo? %s", value, result.is_upperbound ? "Si\n" : "No\n");
    printf("El valor '%d', es el menor de todo el arreglo? %s", value, result.is_lowerbound ? "Si\n" : "No\n");
    printf("El valor '%d', aparece en el arreglo?          %s", value, result.exists ? "Si" : "No\n");
    if (result.exists) {
        printf(", en la posicion: %u\n", result.where);
    }
}