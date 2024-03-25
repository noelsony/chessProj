#include <iostream>
#include <string>
using namespace std;

int chessBoard[8][8];
void capture(int a, int b);
bool inCheck(char c);

class board {
public:
  board() {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        chessBoard[i][j] = 0;
      }
    }
  }
  void displayBoard() {
    for (int i = 7; i >= 0; i--) {
      for (int j = 0; j < 8; j++) {
        if (chessBoard[i][j] == 0)
          cout << "\t";
        else {
          switch (chessBoard[i][j]) {
            case 1:
                cout << "Kw"<< "\t";
                break;
            case 2:
                cout << "Qw"<< "\t";
                break;
            case 3:
                cout << "R1w"<< "\t";
                break;
            case 4:
                cout << "R2w"<< "\t";
                break;
            case 5:
                cout << "B1w"<< "\t";
                break;
            case 6:
                cout << "B2w"<< "\t";
                break;
            case 7:
                cout << "N1w"<< "\t";
                break;
            case 8:
                cout << "N2w"<< "\t";
                break;
            case 9:
                cout << "p1w"<< "\t";
                break;
            case 10:
                cout << "p2w"<< "\t";
                break;
            case 11:
                cout << "p3w"<< "\t";
                break;
            case 12:
                cout << "p4w"<< "\t";
                break;
            case 13:
                cout << "p5w"<< "\t";
                break;
            case 14:
                cout << "p6w"<< "\t";
                break;
            case 15:
                cout << "p7w"<< "\t";
                break;
            case 16:
                cout << "p8w"<< "\t";
                break;
            case 17:
                cout << "Kb"<< "\t";
                break;
            case 18:
                cout << "Qb"<< "\t";
                break;
            case 19:
                cout << "R1b" << "\t";
                break;
            case 20:
                cout << "R2b"<< "\t";
                break;
            case 21:
                cout << "B1b"<< "\t";
                break;
            case 22:
                cout << "B2b"<< "\t";
                break;
            case 23:
                cout << "N1b"<< "\t";
                break;
            case 24:
                cout << "N2b"<< "\t";
                break;
            case 25:
                cout << "p1b"<< "\t";
                break;
            case 26:
                cout << "p2b"<< "\t";
                break;
            case 27:
                cout << "p3b"<< "\t";
                break;
            case 28:
                cout << "p4b"<< "\t";
                break;
            case 29:
                cout << "p5b"<< "\t";
                break;
            case 30:
                cout << "p6b"<< "\t";
                break;
            case 31:
                cout << "p7b"<< "\t";
                break;
            case 32:
                cout << "p8b"<< "\t";
                break;
            default:
                break;
          }
        }
      }
      cout << "\n\n";
    }
  }
} setBoard;

class piece {
public:
  int type = 0;
  int file = 0;
  int rank = 0;
  char setType = 'u';
  bool captured = false;

  piece(char f, int r, char s, int t) {
    file = (int)(f - 'a' + 1);
    rank = r;
    setType = s;
    type = t;
    chessBoard[rank - 1][file - 1] = type;
  }

  virtual bool inRange(int xr, int xf) { 
    return false; 
  }

  void move(char mf, int mr) {
    int t = (int)(mf - 'a' + 1);
    if(captured==false){
      if (inRange(mr - 1, t - 1) == true) {
        chessBoard[rank - 1][file - 1] = 0;
        capture(mr - 1, t - 1);
        rank = mr;
        file = (int)(mf - 'a' + 1);
        chessBoard[rank - 1][file - 1] = type;
        cout << "Moved to " << mf << mr << "\n\n";
        setBoard.displayBoard();
        } else {
        cout << "Not available\n\n";
      }
    }
    else
        cout<<"Piece already captured\n\n";
  }
};

class king : public piece {
public:
  king(char f, int r, char s, int t) : piece(f, r, s, t) {}
};

class queen : public piece {
public:
  queen(char f, int r, char s, int t) : piece(f, r, s, t) {}

  bool inRange(int xr, int xf) {
    int curR = rank - 1, curF = file - 1;
    while (curR + 1 < 8 && curR <= xr && curF + 1 < 8 && curF <= xf) {
      curR += 1;
      curF += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }
    curR = rank - 1, curF = file - 1;
    while (curR + 1 < 8 && curR <= xr && curF - 1 >= 0 && curF >= xf) {
      curR += 1;
      curF -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }
    curR = rank - 1, curF = file - 1;
    while (curR - 1 >= 0 && curR >= xr && curF - 1 >= 0 && curF >= xf) {
      curR -= 1;
      curF -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }
    curR = rank - 1, curF = file - 1;
    while (curR - 1 >= 0 && curR >= xr && curF + 1 < 8 && curF <= xf) {
      curR -= 1;
      curF += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }
    curR = rank - 1, curF = file - 1;
    while (curR + 1 < 8 && curR <= xr) {
      curR += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    curR = rank - 1, curF = file - 1;
    while (curR - 1 >= 0 && curR >= xr) {
      curR -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    curR = rank - 1, curF = file - 1;
    while (curF + 1 < 8 && curF <= xf) {
      curF += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    curR = rank - 1, curF = file - 1;
    while (curF - 1 >= 0 && curF >= xf) {
      curF -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    return false;
  }
};

class bishop : public piece {
public:
  bishop(char f, int r, char s, int t) : piece(f, r, s, t) {}
  bool inRange(int xr, int xf) {
    int curR = rank - 1, curF = file - 1;
    while (curR + 1 < 8 && curR <= xr && curF + 1 < 8 && curF <= xf) {
      curR += 1;
      curF += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }
    curR = rank - 1, curF = file - 1;
    while (curR + 1 < 8 && curR <= xr && curF - 1 >= 0 && curF >= xf) {
      curR += 1;
      curF -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }
    curR = rank - 1, curF = file - 1;
    while (curR - 1 >= 0 && curR >= xr && curF - 1 >= 0 && curF >= xf) {
      curR -= 1;
      curF -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }
    curR = rank - 1, curF = file - 1;
    while (curR - 1 >= 0 && curR >= xr && curF + 1 < 8 && curF <= xf) {
      curR -= 1;
      curF += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    return false;
  }
};

class rook : public piece {
public:
  rook(char f, int r, char s, int t) : piece(f, r, s, t) {}
  bool inRange(int xr, int xf) {
    int curR = rank - 1, curF = file - 1;
    while (curR + 1 < 8 && curR <= xr) {
      curR += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    curR = rank - 1, curF = file - 1;
    while (curR - 1 >= 0 && curR >= xr) {
      curR -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    curR = rank - 1, curF = file - 1;
    while (curF + 1 < 8 && curF <= xf) {
      curF += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    curR = rank - 1, curF = file - 1;
    while (curF - 1 >= 0 && curF >= xf) {
      curF -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }

      if (chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 32) {
        break;
      }
    }

    return false;
  }
};

class knight : public piece {
public:
  knight(char f, int r, char s, int t) : piece(f, r, s, t) {}

  bool inRange(int xr, int xf) {
    int curR = rank - 1, curF = file - 1;
    if (curR + 2 < 8 && curR <= xr && curF + 1 < 8 && curF <= xf) {
      curR += 2;
      curF += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }
      }
    curR = rank - 1, curF = file - 1;
    if (curR + 2 < 8 && curR <= xr && curF - 1 >= 0 && curF >= xf) {
      curR += 2;
      curF -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }
    }
    curR = rank - 1, curF = file - 1;
    if (curR - 2 >= 0 && curR >= xr && curF - 1 >= 0 && curF >= xf) {
      curR -= 2;
      curF -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }
    }
    curR = rank - 1, curF = file - 1;
    if (curR - 2 >= 0 && curR >= xr && curF + 1 < 8 && curF <= xf) {
      curR -= 2;
      curF += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }
    }
    curR = rank - 1, curF = file - 1;
    if (curF + 2 < 8 && curF <= xf && curR +1 < 8 && curR <= xr) {
      curF += 2;
      curR += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }
      }
      curR = rank - 1, curF = file - 1;
    if (curF + 2 < 8 && curF <= xf && curR - 1 >= 0 && curR >= xr) {
      curF += 2;
      curR -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }
    }
    curR = rank - 1, curF = file - 1;
    if (curF - 2 >= 0 && curF >= xf && curR - 1 >= 0 && curR >= xr) {
      curF -= 2;
      curR -= 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }
    }
    curR = rank - 1, curF = file - 1;
    if (curF - 2 >= 0 && curF >= xf && curR + 1 < 8 && curR <= xr) {
      curF -= 2;
      curR += 1;
      if (curR == xr && curF == xf && chessBoard[curR][curF] == 0) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'w' &&
          chessBoard[curR][curF] >= 17 && chessBoard[curR][curF] <= 32) {
        return true;
      }
      if (curR == xr && curF == xf && setType == 'b' &&
          chessBoard[curR][curF] >= 1 && chessBoard[curR][curF] <= 16) {
        return true;
      }
    }

    return false;
  }
};    

class pawn : public piece {
public:
  pawn(char f, int r, char s, int t) : piece(f, r, s, t) {}
  bool inRange(int xr, int xf) {
    int curR = rank - 1, curF = file - 1;
    if (curR + 1 < 8 && setType == 'w') {
      if (curR + 1 == xr && curF == xf && chessBoard[curR + 1][curF] == 0) {
        return true;
      }
      if (curR + 1 == xr && curF == xf && chessBoard[curR + 1][curF] >= 1 &&
          chessBoard[curR + 1][curF] <= 32) {
        return false;
      }

      if (setType == 'w' &&
          ((chessBoard[curR + 1][curF + 1] >= 17 &&
            chessBoard[curR + 1][curF + 1] <= 32 && curR + 1 < 8 &&
            curF + 1 < 8 && curR + 1 == xr && curF + 1 == xf) ||
           (chessBoard[curR + 1][curF - 1] >= 17 &&
            chessBoard[curR + 1][curF - 1] <= 32 && curR + 1 < 8 &&
            curF - 1 >= 0 && curR + 1 == xr && curF - 1 == xf))) {
        return true;
      }
    } else if (curR - 1 >= 0 && setType == 'b') {
      if (curR - 1 == xr && curF == xf && chessBoard[curR - 1][curF] == 0) {
        return true;
      }
      if (curR - 1 == xr && curF == xf && chessBoard[curR - 1][curF] >= 1 &&
          chessBoard[curR - 1][curF] <= 32) {
        return false;
      }

      if (setType == 'b' &&
          ((chessBoard[curR - 1][curF + 1] >= 1 &&
            chessBoard[curR - 1][curF + 1] <= 16 && curR - 1 >= 0 &&
            curF + 1 < 8 && curR - 1 == xr && curF + 1 == xf) ||
           (chessBoard[curR - 1][curF - 1] >= 1 &&
            chessBoard[curR - 1][curF - 1] <= 16 && curR - 1 >= 0 &&
            curF - 1 >= 0 && curR - 1 == xr && curF - 1 == xf))) {
        return true;
      }
    }

    return false;
  }
};

king Kw('e', 1, 'w', 1), Kb('e', 8, 'b', 17);
queen Qw('d', 1, 'w', 2), Qb('d', 8, 'b', 18);
rook R1w('a', 1, 'w', 3), R2w('h', 1, 'w', 4), R1b('a', 8, 'b', 19),
    R2b('h', 8, 'b', 20);
bishop B1w('c', 1, 'w', 5), B2w('f', 1, 'w', 6), B1b('c', 8, 'b', 21),
    B2b('f', 8, 'b', 22);
knight N1w('b', 1, 'w', 7), N2w('g', 1, 'w', 8), N1b('b', 8, 'b', 23),
    N2b('g', 8, 'b', 24);
pawn P1w('a', 2, 'w', 9), P2w('b', 2, 'w', 10), P3w('c', 2, 'w', 11),
    P4w('d', 2, 'w', 12), P5w('e', 2, 'w', 13), P6w('f', 2, 'w', 14),
    P7w('g', 2, 'w', 15), P8w('h', 2, 'w', 16), P1b('a', 7, 'b', 25),
    P2b('b', 7, 'b', 26), P3b('c', 7, 'b', 27), P4b('d', 7, 'b', 28),
    P5b('e', 7, 'b', 29), P6b('f', 7, 'b', 30), P7b('g', 7, 'b', 31),
    P8b('h', 7, 'b', 32);

void capture(int a, int b) {
  if (chessBoard[a][b] != 0) {
    switch (chessBoard[a][b]) {
      case 1:
        Kw.captured = true;
        cout<<"\nCaptured Kw\n";
        break;
      case 2:
        Qw.captured = true;
        cout<<"\nCaptured Qw\n";
        break;
      case 3:
        R1w.captured = true;
        cout<<"\nCaptured R1w\n";
        break;
      case 4:
        R2w.captured = true;
        cout<<"\nCaptured R2w\n";
        break;
      case 5:
        B1w.captured = true;
        cout<<"\nCaptured B1w\n";
        break;
      case 6:
        B2w.captured = true;
        cout<<"\nCaptured B2w\n";
        break;
      case 7:
        N1w.captured = true;
        cout<<"\nCaptured N1w\n";
        break;
      case 8:
        N2w.captured = true;
        cout<<"\nCaptured N2w\n";
        break;
      case 9:
        P1w.captured = true;
        cout<<"\nCaptured P1w\n";
        break;
      case 10:
        P2w.captured = true;
        cout<<"\nCaptured P2w\n";
        break;
      case 11:
        P3w.captured = true;
        cout<<"\nCaptured P3w\n";
        break;
      case 12:
        P4w.captured = true;
        cout<<"\nCaptured P4w\n";
        break;
      case 13:
        P5w.captured = true;
        cout<<"\nCaptured P5w\n";
        break;
      case 14:
        P6w.captured = true;
        cout<<"\nCaptured P6w\n";
        break;
      case 15:
        P7w.captured = true;
        cout<<"\nCaptured P7w\n";
        break;
      case 16:
        P8w.captured = true;
        cout<<"\nCaptured P8w\n";
        break;
      case 17:
        Kb.captured = true;
        cout<<"\nCaptured Kb\n";
        break;
      case 18:
        Qb.captured = true;
        cout<<"\nCaptured Qb\n";
        break;
      case 19:
        R1b.captured = true;
        cout<<"\nCaptured R1b\n";
        break;
      case 20:
        R2b.captured = true;
        cout<<"\nCaptured R2b\n";
        break;
      case 21:
        B1b.captured = true;
        cout<<"\nCaptured B1b\n";
        break;
      case 22:
        B2b.captured = true;
        cout<<"\nCaptured B2b\n";
        break;
      case 23:
        N1b.captured = true;
        cout<<"\nCaptured N1b\n";
        break;
      case 24:
        N2b.captured = true;
        cout<<"\nCaptured N2b\n";
        break;
      case 25:
        P1b.captured = true;
        cout<<"\nCaptured P1b\n";
        break;
      case 26:
        P2b.captured = true;
        cout<<"\nCaptured P2b\n";
        break;
      case 27:
        P3b.captured = true;
        cout<<"\nCaptured P3b\n";
        break;
      case 28:
        P4b.captured = true;
        cout<<"\nCaptured P4b\n";
        break;
      case 29:
        P5b.captured = true;
        cout<<"\nCaptured P5b\n";
        break;
      case 30:
        P6b.captured = true;
        cout<<"\nCaptured P6b\n";
        break;
      case 31:
        P7b.captured = true;
        cout<<"\nCaptured P7b\n";
        break;
      case 32:
        P8b.captured = true;
        cout<<"\nCaptured P8b\n";
        break;
      default:
        break;
    }
  }
}

bool inCheck(char c){
  if(c=='w'){
    int cr=Kw.rank-1, cf=Kw.file-1;
    if(Kb.inRange(cr,cf)||Qb.inRange(cr,cf)||R1b.inRange(cr,cf)||R2b.inRange(cr,cf)||B1b.inRange(cr,cf)||B2b.inRange(cr,cf)||N1b.inRange(cr,cf)||N2b.inRange(cr,cf)||P1b.inRange(cr,cf)||P2b.inRange(cr,cf)||P3b.inRange(cr,cf)||P4b.inRange(cr,cf)||P5b.inRange(cr,cf)||P6b.inRange(cr,cf)||P7b.inRange(cr,cf)||P8b.inRange(cr,cf))
      return true;
  }
  if(c=='b'){
    int cr=Kb.rank-1, cf=Kb.file-1;
    if(Kw.inRange(cr,cf)||Qw.inRange(cr,cf)||R1w.inRange(cr,cf)||R2w.inRange(cr,cf)||B1w.inRange(cr,cf)||B2w.inRange(cr,cf)||N1w.inRange(cr,cf)||N2w.inRange(cr,cf)||P1w.inRange(cr,cf)||P2w.inRange(cr,cf)||P3w.inRange(cr,cf)||P4w.inRange(cr,cf)||P5w.inRange(cr,cf)||P6w.inRange(cr,cf)||P7w.inRange(cr,cf)||P8w.inRange(cr,cf))
      return true;
  }
  return false;
}

int main() {
  setBoard.displayBoard();

  return 0;
}