#include <iostream>
using namespace std;

#define MAX 4
#define TUBES 4

class Stack {
private:
    char balls[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    int isEmpty() {
        if (top == -1)
           return 1;
        return 0;
    }

    int isFull() {
        if(top == MAX-1)
            return 1;

        return 0;
    }

    void push(char color) {
        if (!isFull()) {
            top++;
            balls[top] = color;
        }
    }

    char pop() {
        if (!isEmpty()) {
            char temp = balls[top];
            top--;
            return temp;
        }
        return 0;
    }

    char peek() {
        if (!isEmpty())
            return balls[top];
        return 0;
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << balls[i] << " ";
        }
    }

    int allsame() {
        if (isEmpty())
            return 1;

        char first = balls[0];
        for (int i = 1; i <= top; i++) {
            if (balls[i] != first)
                return 0;
        }
        return 1;
    }
};

class Game {
private:
    Stack tubes[TUBES];

public:
    void startGame() {

        tubes[0].push('R');
        tubes[0].push('B');
        tubes[0].push('G');
        tubes[0].push('R');


        tubes[1].push('B');
        tubes[1].push('R');
        tubes[1].push('B');
        tubes[1].push('G');


        tubes[2].push('G');
        tubes[2].push('G');
        tubes[2].push('B');
        tubes[2].push('R');

        // Tube 4
    }

    void displayGame() {
        cout << "\n===== GAME STATE =====\n";
        for (int i = 0; i < TUBES; i++) {
            cout << "Tube " << i + 1 << ": ";
            tubes[i].display();
            cout << endl;
        }
        cout << endl;
    }

    void moveBall(int from, int to) {
        from--;
        to--;

        if (from < 0 || from >= TUBES || to < 0 || to >= TUBES) {
            cout << "Invalid tube number!\n";
            return;
        }

        if (tubes[from].isEmpty()) {
            cout << "this tube has no ball!\n";
            return;
        }

        if (tubes[to].isFull()) {
            cout << "Tube is full!\n";
            return;
        }

        char ball = tubes[from].pop();
        tubes[to].push(ball);

        cout << "ok moved!\n";
    }

    int checkWin() {
        for (int i = 0; i < TUBES; i++) {
            if (tubes[i].isEmpty())
                continue;

            if (!tubes[i].isFull())
                return 0;

            if (!tubes[i].allsame())
                return 0;
        }
        return 1;
    }

    void start() {
        int from, to;

        while (true) {
            displayGame();

            if (checkWin()) {
                cout << "you win all of tubes are sorted!\n";
                break;
            }

            cout << "Move FROM tube: ";
            cin >> from;

            cout << "Move TO tube: ";
            cin >> to;

            moveBall(from, to);
        }
    }
};

int main() {

    cout<<"welcome to the < BALL SORT> Game"<<endl;
    cout<<"sort all the ball by color"<<endl;

    Game game;
    game.startGame();
    game.start();
    cout<<"tnx for playing"<<endl;
    return 0;
}
