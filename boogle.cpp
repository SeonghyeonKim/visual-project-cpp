/*
보글은 5*5 크기의 알파벳 격자인 게임판의 한 글자에서
시작해서 펜을 움직이면서 만나는 글자를 그 순서대로
나열하여 만들어지는 영어단어를 찾아내는 게임
 
펜은 상하좌우 혹은 대각선으로 인접한 칸으로 이동할 수 있으며
글자를 건너뛸 수는 없다. 지나간 글자를 다시 지나가는 것은 가능하지만
펜을 이동하지 않고 같은 글자를 여러번 사용은 불가능
 
보글 게임판과 알고 있는 단어들의 목록이 주어질 때,
보글 게임판에서 각 단어를 찾을 수 있는지 여부를 출력하시오
*/
#include <iostream>
#include <cstring>
using namespace std;

const int dx[]={-1,-1,-1,1,1,1,0,0};
const int dy[]={-1,0,1,-1,0,1,-1,1};
string word;
char board[5][5]={{'a','a','a','a','a'},{'b','b','b','b','b'},{'c','c','c','c','c'},{'d','d','d','d','d'},{'e','e','e','e','e'}};
bool record[5][5][10];

bool hasWord(int, int, int);
void showBoard(void);
void makeBoard(void);
void checkWord(void);

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout << "=====================================================\n";
    cout << "==================== B O O G L E ====================\n";
    cout << "=====================================================\n";
    while(1) {
        int mode;
        cout << "\n1. Show board\t2. Make board\t3. Check word\t 4. quit\n";
        cout << "INPUT MODE NUMBER : ";
        cin >> mode;
        if(mode==1) showBoard();
        else if(mode==2) makeBoard();
        else if(mode==3) checkWord();
        else if(mode==4) {
            cout << "\nTurn off the program...\n";
            break;
        }
        else cout << "\nWrong Number. Try Again\n";
    }
    return 0;
}

bool hasWord(int x, int y, int idx) {
    record[y][x][idx]=1;
    if(board[y][x]!=word[idx]) return false;
    if(idx==word.size()-1) return true;
    for(int direction=0; direction<8; direction++) {
        int nextX=x+dx[direction], nextY=y+dy[direction];
        if(nextX>=0 && nextY>=0 && nextX<5 && nextY<5) {
            if(record[nextY][nextX][idx+1]) continue;
            if(hasWord(nextX, nextY, idx+1)) return true;
        }
    }
    return false;
}

void showBoard(void) {
    cout << "\n========== Show Board ==========\n";
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void makeBoard(void) {
    cout << "\n========== Make Board ==========\n";
    cout << "Input 5x5 letter by letter\n";
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> board[i][j];
        }
    }
}

void checkWord(void) {
    int word_num;
    cout << "\n========== Check Word ==========\n";
    cout << "How many word do you want to find? : ";
    cin >> word_num;
    for(int i=0; i<word_num; i++) {
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                for(int l=0; l<10; l++) {
                    record[j][k][l]=false;
                }
            }
        }
        cout << "Input Word (max lenght = 10) : ";
        cin >> word;
        bool result=false;
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                if(hasWord(k,j,0)) result=true;
                if(result) break;
            }
        }
        if(result) cout << "\n" << word << " : YES\n";
        else cout << "\n" << word << " : NO\n";
    }
}
