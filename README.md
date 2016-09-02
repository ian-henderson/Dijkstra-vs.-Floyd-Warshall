# Dijkstra-vs.-Floyd-Warshall

This was a project for my Algorithms 4110 course at the University of North Texas. Compile and run the program with the command `g++ *.cpp; ./a.out`.

## Rubric

In this project you will write the code and implement 2 different algorithms for solving all pairs shortest path problem in DIRECTED Graphs and compare the performance of these algorithms in practice. Both algorithms have the time complexity of O(n3). You must write a report that contains your data, summarizes the experiments and has your conclusions. Your report should also have an introduction that explains the purpose of the project. Your code should be written in C, or its variations, say C++, and must compile and properly execute on CSE machines.
Your first algorithm is the O(n2) version of Dijkstras algorithm that you should run n times, (once from each node of the graph), resulting in O(n3) time. Your second algorithm is the Floyd-Warshall dynamic programming algorithm that runs in O(n3) time. The input to each algorithm is the cost matrix. The output is a matrix that stores the cost of shortest path between every pair of the vertices.
Try at least 30 COMPLETE graphs, ranging from 50 to about 1000 vertices. Note that a complete directed graph has 2 edges in the opposite directions for every vertex pair. You should write your own code for graph generation. Your report must contain tables AND charts which show the CPU time for the execution of your programs. You must have a conclusion in your report, regarding your findings and try to explain any differences between theory and the experimental results, if any.
You must have a specific section in your report which tells the reader how the graphs were generated. Particularly, you need to explain how the costs are assigned to edges. RANDOM COSTS are one source, but you should try other sources as well. You must include all data generators as a part of your code.
Give us your hard copies of report in class on the due date. Submit your programs using PROJECT on the due date. For correct code, you only get 100 points. The remaining 200 points are allocated to your report and experiments in the report.
Note that your program(s) should read from an input file, and should write to an output file so that we can verify the correctness of the results, for input graphs of our choice. Particularly, we should be able to test your programs on graphs that are not generated by your graph generators.