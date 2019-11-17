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
#include <string.h>     // strcspn()
#include <math.h>       // log10

// initialize functions
void print_magic( const int *pm, const int n);
int is_magic( const int *pm, const int n);
void create_magic_3(int *pm, const int n);
void create_magic_odd(int *pm, const int n);

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int n = 1;
    void *pm = malloc( sizeof( int ) );
    
    print_magic(pm, n);
    
    // release memory
    free( pm );

    return (EXIT_SUCCESS);
}

void print_magic ( const int *pm, const int n) {
    
    printf("Magisches Quadrat: %i %i\n", pm, n);
}