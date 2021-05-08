/*
 * CS 106B/X, Marty Stepp
 *
 * This program contains an example of a sublist function
 * that uses the "recursive backtracking" algorithmic strategy.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"
using namespace std;

// function prototype declarations
void sublists(Vector<string>& v);

int main_sublists() {
    Vector<string> names {"Jane", "Bob", "Matt", "Sara"};
    cout << "sublists of " << names << ":" << endl << endl;
    sublists(names);
    return 0;
}

void sublistsHelper(Vector<string>& v, Vector<string>& chosen);

/*
 * Prints all subsets of the given vector.
 * This is somewhat similar to printing permutations, except that a permutation
 * includes all elements of the vector, and what differs is their order.
 * For subsets, the order is irrelevant; what matters is which elements are
 * included and which are excluded from the subset.
 * So those decisions (include/exclude?) represent our "choices".
 */
void sublists(Vector<string>& v) {
    Vector<string> chosen;
    sublistsHelper(v, chosen);
}

/*
 * Recursive helper to implement sublists behavior.
 * Explores options for sublists of a vector,
 * given a vector of strings that are already chosen to be included
 * or excluded from the sublist.
 */
void sublistsHelper(Vector<string>& v, Vector<string>& chosen) {
    // TODO
}

