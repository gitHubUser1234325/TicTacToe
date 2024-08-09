#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawBoard(char board[3][3]){
    cout<<"---------------"<<endl;
    for(int i = 0; i < 3; i++){
        cout<<" | ";
        for(int j = 0; j < 3; j++){
            cout<<board[i][j]<<" | ";
        }
        cout<<endl<<"---------------"<<endl;
    }
}

bool checkWin(char board[3][3], char player){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }
    if(board[2][0] == player && board[1][1] ==  player && board[0][2] == player){
        return true;
    }
    return false;
}

int main(){
    srand((unsigned) time(NULL));
    int choice;
    cout<<"Tic Tac Toe"<<endl;
    int row = 0, col = 0, turn;
    char player = 'X';
    char board [3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    cout<<"Enter choice: "<<endl<<"1. Single Player"<<endl<<"2. Multiplayer"<<endl;
    cout<<"Enter: ";
    cin>>choice;
    if(choice == 2){
        for(turn = 0; turn < 9; turn++){
            drawBoard(board);
            cout<<"Player "<<player<<" move"<<endl;
            while(true){
                cout<<"Enter row(0-2) and col(0-2)"<<endl;
                cin>>row>>col;
                if(board[row][col] != ' ' || row < 0 || col < 0 || row > 2 || col > 2){
                    cout<<"Invalid Choice, enter row(0-2) and col(0-2)"<<endl;
                }
                else{
                    break;
                }
            }
            board[row][col] = player;
            if(checkWin(board, player)){
                drawBoard(board);
                cout<<"Player "<<player<<" wins!"<<endl;
                break;
            }
            player = (player == 'X') ? 'O' : 'X';
        }
        
        if(turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')){
            drawBoard(board);
            cout<<"Its a draw"<<endl;
        }
    }
    else if(choice == 1){
        for(turn = 0; turn < 9; turn++){
            drawBoard(board);
            cout<<"Player "<<player<<" move"<<endl;
            if(player == 'X'){
                while(true){
                    cout<<"Enter row(0-2) and col(0-2)"<<endl;
                    cin>>row>>col;
                    if(board[row][col] != ' ' || row < 0 || col < 0 || row > 2 || col > 2){
                        cout<<"Invalid Choice, enter row(0-2) and col(0-2)"<<endl;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                
                
                bool moved = false;
            
            if(!moved){
                for(int i = 0; i < 3 && !moved; i++){
                    for(int j = 0; j < 3 && !moved; j++){
                        if(board[i][j] == ' '){
                            board[i][j] = 'O';
    
                        if(checkWin(board, 'O')){
                            row = i;
                            col = j;
                            moved = true;
                        }
                        board[i][j] = ' ';
                        }
                    }
                }
            }
            
            if(!moved){
                for(int i = 0; i < 3 && !moved; i++){
                    for(int j = 0; j < 3 && !moved; j++){
                        if(board[i][j] == ' '){
                            board[i][j] = 'X';
                            if(checkWin(board, 'X')){
                                row = i;
                                col = j;
                                moved = true;
                            }
                            board[i][j] = ' ';
                        }
                    }
                }
            }
            
            if(!moved){
                do{
                    row = rand()%3;
                    col = rand()%3;
                }
                while(board[row][col] != ' ');
            }
                
                
                
            }
                board[row][col] = player;
                if(checkWin(board, player)){
                    drawBoard(board);
                    if(player == 'X'){
                        cout<<"You won"<<endl;
                    }
                    else{
                        cout<<"You lost, better luck next time"<<endl;
                    }
                    break;
                }
                player = (player == 'X') ? 'O' : 'X';
        }
            
            if(turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')){
                drawBoard(board);
                cout<<"Its a draw"<<endl;
            }
        }
            else{
                cout<<"You chose to exit"<<endl;
            }
            return 0;
        }

