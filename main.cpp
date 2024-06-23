#include <iostream>
#include <vector>
using namespace std;

class Adjacency_Matrix_Graph {
private:
    const int VERTICES;
    int edges;
    vector<vector<int>> matrix;
    vector<bool> marked;

    void depth_first_search(int v) {
    }

    void breadth_first_search(int v) {
    }

public:
    Adjacency_Matrix_Graph(const int n) : VERTICES(n), edges(0) {
        matrix.assign(VERTICES, vector<int>(VERTICES, 0));
        marked.assign(VERTICES, false);
    }

    ~Adjacency_Matrix_Graph() = default;

    void set_edge(const int v, const int w, const int x) {
        if (matrix[v][w] == 0) {
            edges++;
        }
        matrix[v][w] = x;
    }

    void del_edge(const int v, const int w) {
        if (matrix[v][w] != 0) {
            edges--;
        }
        matrix[v][w] = 0;
    }

    bool has_edge(int v, int w) const {
        if (matrix[v][w] != 0) {
            return true;
        }
        return false;
    }

    int get_weight(const int v, const int w) const {
        return matrix[v][w];
    }

    int get_adjacent(const int v) const {
        for (int w = 0; w < VERTICES; ++w) {
            if (matrix[v][w] != 0) {
                return w;
            }
        }
        return VERTICES;
    }

    int get_next(const int v, const int p) const {
        for (int w = p + 1; w < VERTICES; ++w) {
            if (matrix[v][w] != 0) {
                return w;
            }
        }
        return VERTICES;
    }

    void set_mark(const int v, const bool m) {
        marked[v] = m;
    }

    bool get_mark(const int v) const {
        return marked[v];
    }

    int num_vertices() const {
        return VERTICES;
    }

    int num_edges() const {
        return edges;
    }

    void dfs_traversal() {
        marked.assign(VERTICES, false);

        for (int v = 0; v < VERTICES; ++v) {
            if (get_mark(v) == false) {
                depth_first_search(v);
            }
        }
    }

    void bfs_traversal() {
        marked.assign(VERTICES, false);

        for (int v = 0; v < VERTICES; ++v) {
            if (get_mark(v) == false) {
                breadth_first_search(v);
            }
        }
    }
};

int main() {
    cerr << "Thawan";
    return 0;
}
