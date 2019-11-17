/* 
 * File:   main.c
 * Author: Lukas Fischer
 * GitHub: https://github.com/Jinthebandit/MagischeQuadrate-C.git
 * 
 * REQUIREMENTS HW-09:
 * 
 * 
 * DEVELOPMENT CYCLE:
 * Gesucht: Magische Quadrate
 * Gegeben: 
 * 
 * 
 * Created on 17. November 2019
 */

// Benötigte Bibliotheken importieren
#include <stdio.h>
#include <stdlib.h>

// initialize functions
void print_magic( const int *pm, const int n);
int is_magic( const int *pm, const int n);
void create_magic_3(int *pm, const int n);
void create_magic_odd(int *pm, const int n);

/*
 * Magisches Quadrat
 */
int main(int argc, char** argv) {
    
    const int n = 5;
    int *pm = malloc( n * n * sizeof( int ) );
    
    // initialize values
    for( int ix = 0; ix < n*n; ++ix ) {
        pm[ ix ] = 5;
    }

    
    if(is_magic(pm, n) != 0){
        print_magic(pm, n);
        printf("\nMagische Zahl: %i", is_magic(pm, n));
    } else {
        printf("Das Quadrat ist nicht magisch.");
    }
    
    // release memory
    free( pm );

    return (EXIT_SUCCESS);
}

/*
 * Ausgabe des Magischen Quadrats
 */
void print_magic ( const int *pm, const int n) {
    
    for(int iR = 0; iR<n; iR++){
        
        for(int iC = 0; iC<n; iC++){
            printf("| %i | ", pm[ iC+iR*n ]);
        }
        printf("\n");
    }
}

/*
 * Ueberpruefen ob Quadrat magisch ist
 */
int is_magic( const int *pm, const int n) {
    int isMagic = 0;
    int szArray = n+n+2;
    int *ps = malloc( sizeof(int) + szArray);
    
    // initialize values
    for( int ix = 0; ix < szArray; ++ix ) {
        ps[ ix ] = 0;
    }
    
    // calculate sums
    for(int iR = 0; iR<n; iR++){
        for(int iC = 0; iC<n; iC++) {
            ps[iR] = ps[iR] + pm[iC+iR*n]; // sum of row
            ps[n+iR] = ps[n+iR] + pm[iC+iR*n]; // sum of column 
        }       
    }
    
    ps[szArray-1] = ps[0];
    ps[szArray] = ps[0];
    
    // sum of all sums
    int sum = 0;
    for( int iS = 0; iS<szArray; iS++) {
        printf("%i, ", ps[iS]);
        sum = sum + ps[iS];
    }
    
    // check if all sums are equal
    if(sum/szArray == ps[0]) {
        isMagic = sum/szArray;
    } else {
        isMagic = 0;
    }
    
    return isMagic;
}