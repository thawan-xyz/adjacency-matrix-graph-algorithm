#include <iostream>
#include <vector>
using namespace std;

class AdjacencyMatrixGraph {
private:
    const int vertices;
    int edges;
    vector<vector<int>> matrix;
    vector<bool> mark;

public:
    AdjacencyMatrixGraph(const int vertices) : vertices(vertices), edges(0) {
        matrix.assign(vertices, vector<int>(vertices, 0));
        mark.assign(vertices, false);
    }

    ~AdjacencyMatrixGraph() = default;

    void setEdge(const int v, const int w, const int x) {
        if (matrix[v][w] == 0) {
            edges++;
        }
        matrix[v][w] = x;
    }

    void delEdge(const int v, const int w) {
        if (matrix[v][w] != 0) {
            edges--;
        }
        matrix[v][w] = 0;
    }

    bool hasEdge(int v, int w) const {
        if (matrix[v][w] != 0) {
            return true;
        }
        return false;
    }

    int getWeight(const int v, const int w) const {
        return matrix[v][w];
    }

    int getAdjacent(const int v) const {
        for (int i = 0; i < vertices; ++i) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return vertices;
    }

    int getNext(const int v, const int p) const {
        for (int i = p + 1; i < vertices; ++i) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return vertices;
    }

    void setMark(const int v, const bool m) {
        mark[v] = m;
    }

    bool getMark(const int v) const {
        return mark[v];
    }

    int numVertices() const {
        return vertices;
    }

    int numEdges() const {
        return edges;
    }

    void DFS() {

    }

    void BFS() {

    }
};

int main() {
    cerr << "Thawan";
    return 0;
}
