/* 
 * Ian Henderson
 * CSCE 4110
 *
 * Term Project
 *
 * termProject.cpp
 *     Compile: g++ *.cpp -o termProject;
 *     Use: ./termProject arg, where arg is the number of vertices and at least 10
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h> // atoi()
#include "generateGraph.h"
#include "dijkstra.h"
#include "floyd_warshall.h"
#define NODE_RANGE 9999
#define TEST_RUNS_PER_COUNT 10
#define START 50
#define INCREMENT 25

using namespace std;

int main(int argc, char **argv) {
    // Error checks the number of arguments
    if(argc<2) {
        // Error message
        cout << "Error: too few arguments. Expecting a single argument." 
            << endl;
    } else {

        int vertices = atoi(argv[1]);


        /* -RANDOM-GRAPH-GENERATION- */

        // Dijkstra's Algorithm Implementation
        printf("\nDijkstra's Algorithm Implementation:\n\n\tRuns per average: %d\n\tGraph Generation: Random\n\n\tVertex Count\tAverage Run Time (seconds)\tGraph Generation Time (seconds)\n", 
                TEST_RUNS_PER_COUNT);
        for(int i=START; i<=vertices; i+=INCREMENT) {
            clock_t genTime = generateRandomGraph(i);
            clock_t average = 0;
            for(int j=0; j<TEST_RUNS_PER_COUNT; j++) {
                average += dijkstra(i);
            }
            average /= TEST_RUNS_PER_COUNT;
            printf("\t%d\t\t%.3f\t\t\t\t%.3f\n", 
                    i, ((float)average)/CLOCKS_PER_SEC, ((float)genTime)/CLOCKS_PER_SEC);
        }
        printf("\n");

        // Floyd-Warshall Algorithm Implementation
        printf("\nFloyd-Warshall Algorithm Implementation:\n\n\tRuns per average: %d\n\tGraph Generation: Random\n\n\tVertex Count\tAverage Run Time (seconds)\tGraph Generation Time (seconds)\n", 
                TEST_RUNS_PER_COUNT);
        for(int i=START; i<=vertices; i+=INCREMENT) {
            clock_t genTime = generateRandomGraph(i);
            clock_t average = 0;
            for(int j=0; j<TEST_RUNS_PER_COUNT; j++) {
                average += floyd_warshall(i);
            }
            average /= TEST_RUNS_PER_COUNT;
            printf("\t%d\t\t%.3f\t\t\t\t%.3f\n", 
                    i, ((float)average)/CLOCKS_PER_SEC, ((float)genTime)/CLOCKS_PER_SEC);
        }
        printf("\n");


        /* -ASCENDING-GRAPH-GENERATION- */

        // Dijkstra's Algorithm Implementation
        printf("\nDijkstra's Algorithm Implementation:\n\n\tRuns per average: %d\n\tGraph Generation: Ascending\n\n\tVertex Count\tAverage Run Time (seconds)\tGraph Generation Time (seconds)\n", 
                TEST_RUNS_PER_COUNT);
        for(int i=START; i<=vertices; i+=INCREMENT) {
            clock_t genTime = generateAscendingGraph(i);
            clock_t average = 0;
            for(int j=0; j<TEST_RUNS_PER_COUNT; j++) {
                average += dijkstra(i);
            }
            average /= TEST_RUNS_PER_COUNT;
            printf("\t%d\t\t%.3f\t\t\t\t%.3f\n", 
                    i, ((float)average)/CLOCKS_PER_SEC, ((float)genTime)/CLOCKS_PER_SEC);
        }
        printf("\n");

        // Floyd-Warshall Algorithm Implementation
        printf("\nFloyd-Warshall Algorithm Implementation:\n\n\tRuns per average: %d\n\tGraph Generation: Ascending\n\n\tVertex Count\tAverage Run Time (seconds)\tGraph Generation Time (seconds)\n", 
                TEST_RUNS_PER_COUNT);
        for(int i=START; i<=vertices; i+=INCREMENT) {
            clock_t genTime = generateAscendingGraph(i);
            clock_t average = 0;
            for(int j=0; j<TEST_RUNS_PER_COUNT; j++) {
                average += floyd_warshall(i);
            }
            average /= TEST_RUNS_PER_COUNT;
            printf("\t%d\t\t%.3f\t\t\t\t%.3f\n", 
                    i, ((float)average)/CLOCKS_PER_SEC, ((float)genTime)/CLOCKS_PER_SEC);
        }
        printf("\n");


        /* -DESCENDING-GRAPH-GENERATION- */

        // Dijkstra's Algorithm Implementation
        printf("\nDijkstra's Algorithm Implementation:\n\n\tRuns per average: %d\n\tGraph Generation: Descending\n\n\tVertex Count\tAverage Run Time (seconds)\tGraph Generation Time (seconds)\n", 
                TEST_RUNS_PER_COUNT);
        for(int i=START; i<=vertices; i+=INCREMENT) {
            clock_t genTime = generateDescendingGraph(i);
            clock_t average = 0;
            for(int j=0; j<TEST_RUNS_PER_COUNT; j++) {
                average += dijkstra(i);
            }
            average /= TEST_RUNS_PER_COUNT;
            printf("\t%d\t\t%.3f\t\t\t\t%.3f\n", 
                    i, ((float)average)/CLOCKS_PER_SEC, ((float)genTime)/CLOCKS_PER_SEC);
        }
        printf("\n");

        // Floyd-Warshall Algorithm Implementation
        printf("\nFloyd-Warshall Algorithm Implementation:\n\n\tRuns per average: %d\n\tGraph Generation: Descending\n\n\tVertex Count\tAverage Run Time (seconds)\tGraph Generation Time (seconds)\n", 
                TEST_RUNS_PER_COUNT);
        for(int i=START; i<=vertices; i+=INCREMENT) {
            clock_t genTime = generateDescendingGraph(i);
            clock_t average = 0;
            for(int j=0; j<TEST_RUNS_PER_COUNT; j++) {
                average += floyd_warshall(i);
            }
            average /= TEST_RUNS_PER_COUNT;
            printf("\t%d\t\t%.3f\t\t\t\t%.3f\n", 
                    i, ((float)average)/CLOCKS_PER_SEC, ((float)genTime)/CLOCKS_PER_SEC);
        }
        printf("\n");
    }

    return 0;
}
