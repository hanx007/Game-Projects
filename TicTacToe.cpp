#include <iostream>

using namespace std;

char board[3][3]={'1','2','3','4','5','6','7','8','9'};
char current_marker;
int current_player;
void drawboard(){
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"-----------\n";
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"-----------\n";
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";
}
bool placemarker(int slot){
    int row=slot/3;
    int col;
    if(slot % 3==0){
        row=row-1;
        col=2;
    }
    else{
        col=(slot % 3) -1;

    }

    if(board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]=current_marker;
        return true;
    }
    else
        return false;
}
int winner(){
    for(int i=0;i<3;i++){
        //for rows
        if(board[i][0]==board[i][1]&& board[i][1]==board[i][2]) return current_player;
        //for column
        if(board[0][i]==board[1][i]&& board[1][i]==board[2][i]) return current_player;
    }
        //for diagonals
        if(board[0][0]==board[1][1]&& board[1][1]==board[2][2]) return current_player;
        if(board[0][2]==board[1][1]&& board[1][1]==board[2][0]) return current_player;

        return 0;

}
void swap_player_and_marker(){
    if(current_player==1) current_player=2;
    else current_player=1;

    if(current_marker=='X') current_marker='O';
    else current_marker='X';
}
void game(){
    cout<<"Player one,choose your marker:\n";
    char marker1;
    int player_won;
    cin>>marker1;
    current_marker=marker1;
    current_player=1;
    drawboard();
    for(int i=0;i<9;i++){
        cout<<"Its Player "<<current_player<<"'s turn. Enter your slot:\n";
        int slot;
        cin>>slot;
        if(slot<1  || slot>9){
            cout<<"The slot is invalid!Try another slot.\n";
            i--;
            continue;
        }
        if(!placemarker(slot)){
            cout<<"The slot is occupied!Try another slot.\n";
            i--;
            continue;
        }
        drawboard();
        player_won=winner();
        if(player_won==1){
            cout<<"Player one won!!Congratulations!!\n";
            break;

        }
        if(player_won==2) {
            cout<<"Player two won!!Congratulations!!\n";
            break;
        }
        swap_player_and_marker();
    }
    if(player_won==0) cout<<"Its a tie game!\n";
}
int main(){
    drawboard();
    cout<<"\n";
    game();
}

