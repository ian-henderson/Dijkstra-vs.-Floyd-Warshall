#include <iostream>
#include <stdio.h>
#include <vector>
#include "dijkstra.h"

using namespace std;
const int inf = 1 << 30;

clock_t dijkstra(int vertices) {

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

        // Cycles through each vertex, running Dijkstra's Alg on each one.
        clock_t t = clock();
        for(int vertex=0; vertex<vertices; vertex++) {
            // Dijkstra Implementation
            int a=vertex, b=vertices-1;
            vector<int> dist(vertices);
            vector<bool> vis(vertices);
            // int shortest_path[vertices];

            for(int i=0; i<vertices; ++i) {
                dist[i] = inf;
            }
            dist[a] = 0;

            for(int i=0; i<vertices; ++i) {
                int cur = -1;
                for(int j=0; j<vertices; ++j) {
                    if(vis[j]) continue;
                    if(cur == -1 || dist[j] < dist[cur]) {
                        cur = j;
                    }
                }

                vis[cur] = true;
                // shortest_path[i] = cur;

                for(int j=0; j<vertices; ++j) {
                    int path = dist[cur] + graph[cur][j];
                    if(path < dist[j]) {
                        dist[j] = path;
                    }
                }
            }

            // Outputs the shortest path
            /*
            cout << "Shortest path from " << vertex << ": ";
            for(int i=0; i<vertices; i++) {
                cout << shortest_path[i] << " ";
            }
            cout << "\n";
            */
        }
        return clock() - t;
    }
}
