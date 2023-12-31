#include <iostream>

using namespace std;

void Board(char *spaces);
void player1Move(char *spaces, char player1);
void player2Move(char *spaces, char player2);
bool checkWinner(char *spaces, char player1, char player2);
bool checkTie(char *spaces);

void Board(char *spaces)
{
    cout << '\n';
    cout << "     |     |     \n";
    cout << " " << spaces[0] << "   | " << spaces[1] << "   | " << spaces[2] << "    " << '\n';
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << " " << spaces[3] << "   | " << spaces[4] << "   | " << spaces[5] << "    " << '\n';
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << " " << spaces[6] << "   | " << spaces[7] << "   | " << spaces[8] << "    " << '\n';
    cout << "     |     |     \n";
    cout << '\n';
}
void player1Move(char *spaces, char player1)
{
    int number;
    do{
    cout <<" make a move Player 1(1-9): ";
    cin>>number;
    number--;
    if(spaces[number]==' '){
        spaces[number] = player1;
        break;
        }
    }while(!number > 0 || !number < 8);
}
void player2Move(char *spaces, char player2)
{
    int number;
    do{
    cout <<" make a move Player 2(1-9): ";
    cin>>number;
    number--;
        if(spaces[number] ==' '){
        spaces[number] = player2;
        break;
        }
    }while(!number > 0 || !number < 8);
}
bool checkWinner(char *spaces, char player1, char player2)
{
    if((spaces[0]!= ' ')&& (spaces[0]==spaces[1])&&(spaces[1]==spaces[2])){
        spaces[0] == player1 ? cout << "Player 1 WINS!!\n" : cout << "Player 2 WINS!!\n";
    }
    else if((spaces[3]!= ' ')&& (spaces[3]==spaces[4])&&(spaces[4]==spaces[5])){
        spaces[3] == player1 ? cout << "Player 1 WINS!!\n" : cout << "Player 2 WINS!!\n";
    }
    else if((spaces[6]!= ' ')&& (spaces[6]==spaces[7])&&(spaces[7]==spaces[8])){
        spaces[6] == player1 ? cout << "Player 1 WINS!!\n" : cout <<"Player 2 WINS!!\n";
    }
    else if((spaces[0]!= ' ')&& (spaces[0]==spaces[3])&&(spaces[3]==spaces[6])){
        spaces[0] == player1 ? cout << "Player 1 WINS!!\n" : cout << "Player 2 WINS!!\n";
    }
    else if((spaces[1]!= ' ')&& (spaces[1]==spaces[4])&&(spaces[4]==spaces[7])){
        spaces[1] == player1 ? cout << "Player 1 WINS!!\n" : cout << "Player 2 WINS!!\n";
    }
    else if((spaces[2]!= ' ')&& (spaces[2]==spaces[5])&&(spaces[5]==spaces[8])){
        spaces[2] == player1 ? cout << "Player 1 WINS!!\n" : cout << "Player 2 WINS!!\n";
    }
    else if((spaces[0]!= ' ')&& (spaces[0]==spaces[4])&&(spaces[4]==spaces[8])){
        spaces[0] == player1 ? cout << "Player 1 WINS!!\n" : cout << "Player 2 WINS!!\n";
    }
    else if((spaces[2]!= ' ')&& (spaces[2]==spaces[4])&&(spaces[4]==spaces[6])){
        spaces[2] == player1 ? cout << "Player 1 WINS!!\n" : cout << "Player 2 WINS!!\n";
    }
    else{
        return false;
    }
    return true;
}
bool checkTie(char *spaces)
{
    for(int i=0;i<9;i++){
    if(spaces[i]==' '){
    return false;
   }
  }
 cout << "IT'S A TIE\n";
 return true;

}
int main()
{
    string name1;
    string name2;
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X';
    char player2 = 'O';
    bool running = true;

    cout << "*************************\n";
    cout << "*******TIC-TAC-TOE*******\n";
    cout << "*************************\n";


        Board(spaces);

        while(running){
         player1Move(spaces, player1);
        Board(spaces);
        if(checkWinner(spaces, player1, player2)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running=false;
            break;
        }

        player2Move(spaces, player2);
        Board(spaces);
         if(checkWinner(spaces, player1, player2)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running=false;
            break;
        }
    }
    cout << "Thanks for playing\n";
    return 0;
}
