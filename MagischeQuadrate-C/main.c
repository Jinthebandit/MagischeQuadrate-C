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
    
    const int n = 3;
    int *pm = malloc( n * n * sizeof( int ) );
    
    // initialize values
    for( int ix = 0; ix < n*n; ++ix ) {
        pm[ ix ] = 5;
    }
    
    if(n == 3){
        create_magic_3(pm, n);
    } else {
        puts("Magisches Quadrat mit n>3 noch nicht implementiert");
    }

    
    if(is_magic(pm, n) != 0){
        print_magic(pm, n);
        printf("\nMagische Zahl: %i", is_magic(pm, n));
    } else {
        print_magic(pm, n);
        printf("\nDas Quadrat ist nicht magisch.");
    }
    
    // release memory
    free( pm );

    return (EXIT_SUCCESS);
}

/*
 * Ausgabe des Magischen Quadrats
 */
void print_magic ( const int *pm, const int n) {
    
    puts("\nDas magische Quadrat:");
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
    int *ps = malloc( szArray * sizeof(int));
    
    // initialize values
    for( int ix = 0; ix < szArray; ++ix ) {
        ps[ ix ] = 0;
    }
        
    // calculate sums
    for(int iR = 0; iR<n; iR++) {
        ps[n+n] = ps[n+n] + pm[iR+iR*n]; // sum of diagonal 1
        ps[n+n+1] = ps[n+n+1] + pm[iR*n+n-iR-1]; // sum of diagonal 2
        
        for(int iC = 0; iC<n; iC++) {
            ps[iR] = ps[iR] + pm[iC+iR*n]; // sum of row
            ps[n+iR] = ps[n+iR] + pm[iC+iR*n]; // sum of column 
        }       
    }
        
    // sum of all sums
    int sum = 0;
    for( int iS = 0; iS<szArray; iS++) {
        sum = sum + ps[iS];
    }
    
    
    // check if all sums are equal
    if(sum/szArray == ps[0]) {
        isMagic = sum/szArray;
    } else {
        isMagic = 0;
    }
    
    free( ps );
    
    return isMagic;
}

void create_magic_3(int *pm, const int n) {
    int a = 1;
    int b = 2;
    int c = 3;
    
    // Magisches Quadrat
    pm[0] = c - b;
    pm[1] = c + a + b;
    pm[2] = c - a;
    pm[3] = c - a + b;
    pm[4] = c;
    pm[5] = c + a - b;
    pm[6] = c + a;
    pm[7] = c - a - b;
    pm[8] = c + b;            
}