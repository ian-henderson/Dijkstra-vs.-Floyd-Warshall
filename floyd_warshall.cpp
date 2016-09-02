#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

clock_t floyd_warshall(int vertices) {

    // Dynamically allocates memory for graph
    int **graph = new int*[vertices];
    for(int i=0; i<vertices; i++)
        graph[i] = new int[vertices];

    // Attempts to open "graph.txt".
    FILE *pFile = fopen("graph.txt", "r");

    // Error checks graph.txt's existence.
    if(!pFile) {
        cout << "Error, graph.txt does not exist." << endl;
    } else {
        // Reads graph.txt into the graph array.
        for(int i=0; i<vertices; i++) {
            for(int j=0; j<vertices; j++) {
                fscanf(pFile, "%d", &graph[i][j]);
            }
            char x; // Variable to read the spare "\n"s into
            fscanf(pFile, "%c", &x);
        } 

        // Closes graph.txt
        fclose(pFile);

        // Floyd-Warshall Algorithm Implementation        
        clock_t t = clock();
        for(int k=0; k<vertices; k++) {
            for(int i=0; i<vertices; i++) {
                for(int j=0; j<vertices; j++) {
                    if(graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        return clock() - t;
    }
}
