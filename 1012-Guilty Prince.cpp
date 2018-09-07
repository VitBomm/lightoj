
#include <iostream>
#include <queue>
#define MAX 21
using namespace std;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int w,h;
int dem=1;
bool visited[MAX][MAX];
string maze[MAX];
struct Cell {
    int r, c;
    bool operator == (const Cell &other) {
        return r == other.r && c == other.c;
    }
};

bool isValid(int r, int c) {
    return r >= 0 && r < h && c >= 0 && c < w;
}

int BFS(Cell s) {
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    while (!q.empty()) {
        Cell u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            if (isValid(r, c) && maze[r][c] == '.' && !visited[r][c]) {
                visited[r][c] = true;
                q.push((Cell) {r, c});
                dem++;
            }
        }
    }
    
    return dem;
}

int main() {
    int result =0;
    int Q;
    cin >> Q;
    while (Q--) {
        result++;
        if(Q<0)
        {
            break;
        }
        dem = 1;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            cin >> maze[i];
        }
        Cell start;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                visited[i][j] = false;
                if(maze[i][j]=='@')
                {
                    start.r = i;
                    start.c = j;
                }
            }
        }
        cout <<"Case "<<result<<": "<<BFS(start) << endl;
    }
    return 0;
}
