#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define array vector
using namespace std;

// @author: Thawan Ribeiro, 2024-06-22

class Graph {
private:
    const int VERTICES;
    int edges;
    array<array<int>> matrix;
    array<bool> marked;

    void depth_first_search(int v, array<int> &result) {
        set_mark(v);

        result.push_back(v);

        int w = get_first_adjacent(v);
        while (w < VERTICES) {
            if (!is_marked(v)) {
                depth_first_search(w, result);
            }
            w = get_next_adjacent(v, w);
        }
    }

    void breadth_first_search(int v, array<int> &result) {
        queue<int> queue;
        queue.push(v);

        set_mark(v);
        while (!queue.empty()) {
            v = queue.front();
            queue.pop();

            result.push_back(v);

            int w = get_first_adjacent(v);
            while (w < VERTICES) {
                if (!is_marked(v)) {
                    set_mark(w);
                    queue.push(w);
                }
                w = get_next_adjacent(v, w);
            }
        }
    }

public:
    Graph(const int n) : VERTICES(n), edges(0), matrix(n, array<int>(n, 0)), marked(n, false) {}

    ~Graph() = default;

    void set_edge(const int v, const int w, const int x = 1) {
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

    int get_first_adjacent(const int v) const {
        for (int w = 0; w < VERTICES; ++w) {
            if (has_edge(v, w)) {
                return w;
            }
        }
        return VERTICES;
    }

    int get_next_adjacent(const int v, const int p) const {
        for (int w = p + 1; w < VERTICES; ++w) {
            if (has_edge(v, w)) {
                return w;
            }
        }
        return VERTICES;
    }

    int get_last_adjacent(const int v) const {
        for (int w = VERTICES - 1; w >= 0; --w) {
            if (has_edge(v, w)) {
                return w;
            }
        }
        return VERTICES;
    }

    void set_mark(const int v) {
        marked[v] = true;
    }

    void del_mark(const int v) {
        marked[v] = false;
    }

    bool is_marked(const int v) const {
        return marked[v];
    }

    int num_vertices() const {
        return VERTICES;
    }

    int num_edges() const {
        return edges;
    }

    array<int> dfs_traversal() {
        marked.assign(VERTICES, false);

        array<int> result;
        for (int v = 0; v < VERTICES; ++v) {
            if (!is_marked(v)) {
                depth_first_search(v, result);
            }
        }
        
        return result;
    }

    array<int> bfs_traversal() {
        marked.assign(VERTICES, false);

        array<int> result;
        for (int v = 0; v < VERTICES; ++v) {
            if (!is_marked(v)) {
                breadth_first_search(v, result);
            }
        }
        
        return result;
    }
};

int main() {
    cerr << "Thawan";
    return 0;
}
