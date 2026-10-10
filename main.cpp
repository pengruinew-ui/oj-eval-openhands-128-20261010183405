#include <bits/stdc++.h>
using namespace std;

bool win(const vector<string>& b, char p) {
    // rows
    for (int i = 0; i < 3; ++i) {
        if (b[i][0] == p && b[i][1] == p && b[i][2] == p) return true;
    }
    // cols
    for (int j = 0; j < 3; ++j) {
        if (b[0][j] == p && b[1][j] == p && b[2][j] == p) return true;
    }
    // diags
    if (b[0][0] == p && b[1][1] == p && b[2][2] == p) return true;
    if (b[0][2] == p && b[1][1] == p && b[2][0] == p) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(3);
    for (int i = 0; i < 3; ++i) {
        if(!(cin >> board[i])) return 0;
    }
    int cntX = 0, cntO = 0, cntEmpty = 0;
    for (auto &row : board) {
        for (char c : row) {
            if (c == 'x') cntX++;
            else if (c == 'o') cntO++;
            else if (c == '-') cntEmpty++;
        }
    }
    bool winX = win(board, 'x');
    bool winO = win(board, 'o');
    // basic count validation
    if (!(cntX == cntO || cntX == cntO + 1)) {
        cout << "invalid\n";
        return 0;
    }
    if (winX && winO) {
        cout << "invalid\n";
        return 0;
    }
    if (winX) {
        if (cntX != cntO + 1) {
            cout << "invalid\n";
        } else {
            cout << "win\n";
        }
        return 0;
    }
    if (winO) {
        if (cntX != cntO) {
            cout << "invalid\n";
        } else {
            cout << "lose\n";
        }
        return 0;
    }
    if (cntEmpty == 0) {
        cout << "tie\n";
    } else {
        cout << "ongoing\n";
    }
    return 0;
}
