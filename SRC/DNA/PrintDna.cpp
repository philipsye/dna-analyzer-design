#include "PrintDna.h"
#include "iostream"


void printUpperHalf(char* str)
{
    char first, second;
    int pos = 0;

    // Each half of the DNA is made of
    // combination of two compounds
    for (int i = 1; i <= 4; i++) {

        // Taking the two carbon
        // compounds from the string
        first = str[pos];
        second = str[pos + 1];
        pos += 2;

        for (int j = 4 - i; j >= 1; j--)
            std::cout << " ";
        std::cout << first;
        for (int j = 1; j < i; j++)
            std::cout << "--";
        std::cout << second << std::endl;
    }
}

// Function to print lower half
// of the DNA or the lower lobe
void printLowerHalf(char* str)
{
    char first, second;
    int pos = 0;
    for (int i = 1; i <= 4; i++) {

        first = str[pos];
        second = str[pos + 1];
        pos += 2;

        for (int j = 1; j < i; j++)
            std::cout << " ";
        std::cout << first;
        for (int j = 4 - i; j >= 1; j--)
            std::cout << "--";
        std::cout << second << std::endl;
    }
}

// Function to print 'n' parts of DNA
void printDNA(char * dna, int n)
{
    for (int i = 0; i < n; i++) {

        int x = i % 6;

        // Calling for upperhalf
        if (x % 2 == 0)
            printUpperHalf(&dna[x]);
        else

            // Calling for lowerhalf
            printLowerHalf(&dna[x]);
    }
}
/*
int main()
{

    int n = 8;

    // combinations stored in the array
    string DNA[] = { "ATTAATTA", "TAGCTAGC", "CGCGATAT",
                     "TAATATGC", "ATCGTACG", "CGTAGCAT" };
    printDNA(DNA, n);

    return 0;
}
*/