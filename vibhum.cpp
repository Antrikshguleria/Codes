#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1005; // Adjust this based on the problem constraints

int N, M; // Dimensions of the 2D plane
bool reachable[MAX_N][MAX_N]; // To track reachable cells

// Check if a cell (x, y) is within bounds
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

// Update reachable cells
void updateReachable(int x, int y, int X) {
    for (int dx = -X; dx <= X; ++dx) {
        for (int dy = -X; dy <= X; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (isValid(nx, ny)) {
                reachable[nx][ny] = true;
            }
        }
    }
}

int main() {
    int p, g, u, v, X;
    cin >> N >> M >> p >> g >> u >> v >> X;

    // Initialize reachable cells
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            reachable[i][j] = false;
        }
    }

    // Mark the starting position as reachable
    reachable[p][g] = true;

    // Update reachable cells based on X
    updateReachable(p, g, X); 

    // Check if the destination cell is reachable
    if (reachable[u][v]) {
        // Calculate the minimum number of jumps needed
        int minJumps = abs(u - p) / X + abs(v - g) / X;
        cout << "Kady can reach the destination in " << minJumps << " jumps." << endl;
    } else {
        cout << "Kady cannot reach the destination." << endl;
    }

    return 0;
}
