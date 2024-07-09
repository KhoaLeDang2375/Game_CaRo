#include <bits/stdc++.h>
using namespace std;

class CaRo_Game {
public:
    int SL_O;
    vector<vector<pair<int, int>>> Ban_Co;
    int step;

    CaRo_Game(int sl = 4) : SL_O(sl), Ban_Co(SL_O, vector<pair<int, int>>(SL_O, {0, 0})), step(0) {
        cout << "\nTao thanh cong man choi!\n";
    }

    void Display();
    int FinishGame(int a, int b);
    void Play_Game();
};

void CaRo_Game::Display() {
    cout << " | ";
    for (int k = 0; k < SL_O; k++) {
        cout << k << " | ";
    }
    cout << endl;
    for (int k = 0; k <= SL_O; ++k) {
        cout << "---";
        if (k <= SL_O - 1) cout << "+";
    }
    cout << endl;
    for (int i = 0; i < SL_O; ++i) {
        cout << i << " |";
        for (int j = 0; j < SL_O; ++j) {
            if (Ban_Co[i][j].second == 1)
                cout << " O";
            else if (Ban_Co[i][j].second == 2)
                cout << " X";
            else
                cout << "  ";
            if (j < SL_O - 1) cout << " |";
        }
        cout << " |" << endl;
        if (i < SL_O - 1) {
            for (int k = 0; k <= SL_O; ++k) {
                cout << "---";
                if (k <= SL_O - 1) cout << "+";
            }
            cout << endl;
        }
    }
    cout << endl;
}

int CaRo_Game::FinishGame(int x, int y) {
    step++;
    if (step >= SL_O * SL_O)
        return 3;

    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    int player = Ban_Co[x][y].second;

    for (auto& dir : directions) {
        int count = 1;
        for (int i = 1; i < 5; ++i) {
            int nx = x + dir[0] * i;
            int ny = y + dir[1] * i;
            if (nx < 0 || ny < 0 || nx >= SL_O || ny >= SL_O || Ban_Co[nx][ny].second != player) break;
            count++;
        }
        for (int i = 1; i < 5; ++i) {
            int nx = x - dir[0] * i;
            int ny = y - dir[1] * i;
            if (nx < 0 || ny < 0 || nx >= SL_O || ny >= SL_O || Ban_Co[nx][ny].second != player) break;
            count++;
        }
        if (count >= 5) return 1;
    }
    return 0;
}

void CaRo_Game::Play_Game() {
    while (true) {
        int i, j;
        cout << "\n\tMoi nguoi thu nhat nhap vi tri o: ";
        while (true) {
            cin >> i >> j;
            if (i >= 0 && j >= 0 && i < SL_O && j < SL_O && Ban_Co[i][j].first == 0) {
                Ban_Co[i][j] = {1, 1};
                break;
            }
            cout << "\n\tVi tri khong hop le vui long nhap lai!!\n\tMoi nguoi choi thu nhat nhap vi tri o: ";
        }
        if (FinishGame(i, j) == 1) {
            cout << "\nNguoi choi thu nhat thang!!!\n";
            return;
        }

        cout << "\n\tMoi nguoi choi thu hai nhap vi tri o: ";
        while (true) {
            cin >> i >> j;
            if (i >= 0 && j >= 0 && i < SL_O && j < SL_O && Ban_Co[i][j].first == 0) {
                Ban_Co[i][j] = {1, 2};
                break;
            }
            cout << "\n\tVi tri khong hop le vui long nhap lai!!\n\tMoi nguoi choi thu hai nhap vi tri o: ";
        }
        if (FinishGame(i, j) == 1) {
            cout << "\nNguoi choi thu hai thang!!!\n";
            return;
        }
        Display();
    }
    cout << "\nKet qua: Hoa.\n";
}

int main() {
    cout << "\nNhap so luong o tro choi: ";
    int n;
    do {
        cin >> n;
    } while (n < 5);
    CaRo_Game game(n);
    game.Play_Game();
}
