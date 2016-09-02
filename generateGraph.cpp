#include <iostream>
#include <stdio.h> // printf(), fopen(), fclose(), fprintf()
#include <stdlib.h> // rand()
#include <time.h> // clock(), clock_t
#include "generateGraph.h"
#define NODE_RANGE 1000

using namespace std;

clock_t generateRandomGraph(int vertices) {

    // Starts the clock
    clock_t t = clock();
    // Dynamically allocates memory for graph
    int **graph = new int*[vertices];
    for(int i=0; i<vertices; i++)
        graph[i] = new int[vertices];
    // Opens/creates new file "graph.txt", else returns error message.
    FILE *pFile;
    pFile = fopen("graph.txt", "w");
    if(!pFile) {
        cout << "Could not create or open graph.txt" << endl;
    } else {
        // Random graph generation
        for(int i=0; i<vertices; i++) {
            // The limit for the second for loop reduces the number of 
            // redundant iterations.
            for(int j=0; j<(vertices-(vertices-i)); j++) {
                if (i==j) {
                    // Writes 0 to the graph
                    graph[i][j] = 0;
                } else {
                    int randomNumber = (rand() % NODE_RANGE) + 1;
                    graph[i][j] = randomNumber;
                    graph[j][i] = randomNumber;
                }
            }
        }

        // Writes the graph to graph.txt.
        for(int i=0; i<vertices; i++) {
            for(int j=0; j<vertices; j++) {
                fprintf(pFile, "%d\t", graph[i][j]);
            }
            fprintf(pFile, "\n");
        }

        // Closes graph.txt.
        fclose(pFile);

        // Run time
        return clock() - t;
    }
}

clock_t generateAscendingGraph(int vertices) {
    // Starts the clock
    clock_t t = clock();
    // Dynamically allocates memory for graph
    int **graph = new int*[vertices];
    for(int i=0; i<vertices; i++)
        graph[i] = new int[vertices];
    // Opens/creates new file "graph.txt", else returns error message.
    FILE *pFile;
    pFile = fopen("graph.txt", "w");
    if(!pFile) {
        cout << "Could not create or open graph.txt" << endl;
    } else {
        // Ascending graph generation
        for(int i=0; i<vertices; i++) {
            // The limit for the second for loop reduces the number of 
            // redundant iterations.
            for(int j=0; j<(vertices-(vertices-i)); j++) {
                if (i==j) {
                    // Writes 0 to the graph
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = i;
                    graph[j][i] = i;
                }
            }
        }

        // Writes the graph to graph.txt.
        for(int i=0; i<vertices; i++) {
            for(int j=0; j<vertices; j++) {
                fprintf(pFile, "%d\t", graph[i][j]);
                // printf("%d\t", graph[i][j]);
            }
            fprintf(pFile, "\n");
            // printf("\n");
        }

        // Closes graph.txt.
        fclose(pFile);

        // Run time
        return clock() - t;
    }
}

clock_t generateDescendingGraph(int vertices) {
    // Starts the clock
    clock_t t = clock();
    // Dynamically allocates memory for graph
    int **graph = new int*[vertices];
    for(int i=0; i<vertices; i++)
        graph[i] = new int[vertices];
    // Opens/creates new file "graph.txt", else returns error message.
    FILE *pFile;
    pFile = fopen("graph.txt", "w");
    if(!pFile) {
        cout << "Could not create or open graph.txt" << endl;
    } else {
        // Ascending graph generation
        for(int i=0; i<vertices; i++) {
            // The limit for the second for loop reduces the number of 
            // redundant iterations.
            for(int j=0; j<(vertices-(vertices-i)); j++) {
                if (i==j) {
                    // Writes 0 to the graph
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = vertices-i;
                    graph[j][i] = vertices-i;
                }
            }
        }

        // Writes the graph to graph.txt.
        for(int i=0; i<vertices; i++) {
            for(int j=0; j<vertices; j++) {
                fprintf(pFile, "%d\t", graph[i][j]);
            }
            fprintf(pFile, "\n");
        }

        // Closes graph.txt.
        fclose(pFile);

        // Run time
        return clock() - t;
    }
}
