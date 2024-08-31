class Solution {
public:
    // Function to check if it's possible to color the graph with m colors
    bool canColor(bool graph[101][101], int m, vector<int>& color, int v, int n) {
        // Check if all vertices are colored
        if (v == n) {
            return true;
        }

        // Try coloring vertex v with each of the m colors
        for (int c = 1; c <= m; c++) {
            // Check if this color is valid for vertex v
            bool isValid = true;
            for (int i = 0; i < n; i++) {
                if (graph[v][i] && color[i] == c) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                color[v] = c;
                // Recur to color the next vertex
                if (canColor(graph, m, color, v + 1, n)) {
                    return true;
                }
                // If coloring with color c didn't work, reset color
                color[v] = 0;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        // Vector to store color assigned to each vertex
        vector<int> color(n, 0);
        
        // Start coloring from the first vertex
        return canColor(graph, m, color, 0, n);
    }
};
