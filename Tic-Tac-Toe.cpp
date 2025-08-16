#include<iostream>
#include<ctime>
using namespace std;


void board(char *spaces){
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] <<"  |  " << spaces[1] <<"  |  " << spaces[2] <<"  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] <<"  |  " << spaces[4] <<"  |  " << spaces[5] <<"  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] <<"  |  " << spaces[7] <<"  |  " << spaces[8] <<"  " << endl;
    cout << "_____|_____|_____" << endl;
}

void playerInput(char *spaces){
    int num;
    do{
        cout << "Enter your position :";
        cin >> num;
        num--;
    }
    while(spaces[num] != ' ');
    
    spaces[num] = 'X';
}

void computerInput(char *spaces){
    srand(time(NULL));
    int result;

    for(int i = 0;i < 7;i+=3){
        if(((spaces[i] == spaces[i+1]) && spaces[i] != ' ') || ((spaces[i+1] == spaces[i+2]) && spaces[i+1] != ' ') || ((spaces[i] == spaces[i+2]) && spaces[i] != ' ')){
            for(int j = i;j < (i+3);j++){
                if(spaces[j] == ' '){
                    spaces[j] = 'O';
                    cout << endl << j << endl;
                    return;
                }
            }
        }
    }

    for(int i = 0;i < 3;i++){
        if(((spaces[i] == spaces[i+3]) && spaces[i] != ' ') || ((spaces[i+3] == spaces[i+6]) && spaces[i+3] != ' ') || ((spaces[i] == spaces[i+6]) && spaces[i] != ' ')){
            for(int j = i;j < 10;j+=3){
                if(spaces[j] == ' '){
                    spaces[j] = 'O';
                    cout << endl << j << endl;
                    return;
                }
            }
        }
    }


    // for(int i = 0 ; i < 9 ; i++){
    //     if(i == 4){
    //         continue;
    //     }
        

    //     if((spaces[0] == spaces[2]) && spaces[1] == ' ' && spaces[0] != ' '){
    //         spaces[1] == 'O';
    //         return;
    //     }
    //     else if( spaces[0] == spaces[6] && spaces[3] == ' ' && spaces[0] != ' '){
    //         spaces[3] == 'O';
    //         return;
    //     }
    //     else if(spaces[8] == spaces[2] && spaces[5] == ' ' && spaces[8] != ' '){
    //         spaces[5] == 'O';
    //         return;
    //     }
    //     else if(spaces[8] == spaces[6] && spaces[7] == ' ' && spaces[8] != ' '){
    //         spaces[7] == 'O';
    //         return;
    //     }

    //     if((spaces[0] == spaces[1]) && spaces[2] == ' ' && spaces[0] != ' '){
    //         spaces[2] == 'O';
    //         return;
    //     }
    //     else if( spaces[1] == spaces[2] && spaces[0] == ' ' && spaces[1] != ' '){
    //         spaces[0] == 'O';
    //         return;
    //     }
    //     else if(spaces[6] == spaces[7] && spaces[8] == ' ' && spaces[6] != ' '){
    //         spaces[8] == 'O';
    //         return;
    //     }
    //     else if(spaces[7] == spaces[8] && spaces[6] == ' ' && spaces[7] != ' '){
    //         spaces[6] == 'O';
    //         return;
    //     }

    //     // 
    //     //

    //     if((spaces[0] == spaces[3]) && spaces[6] == ' ' && spaces[0] != ' '){
    //         spaces[6] == 'O';
    //         return;
    //     }
    //     else if( spaces[3] == spaces[6] && spaces[0] == ' ' && spaces[3] != ' '){
    //         spaces[0] == 'O';
    //         return;
    //     }
    //     else if(spaces[2] == spaces[5] && spaces[8] == ' ' && spaces[2] != ' '){
    //         spaces[8] == 'O';
    //         return;
    //     }
    //     else if(spaces[5] == spaces[8] && spaces[2] == ' ' && spaces[5] != ' '){
    //         spaces[2] == 'O';
    //         return;
    //     }



    //     else{
    //         for(int j = 8;j >= 0;j--){
    //             if(j == 4){
    //                 continue;
    //             }
    //             else if((j + i) == 8 && (spaces[i] == spaces[j]) && spaces[i] != ' ' && spaces[4] == ' '){
    //                 spaces[4] = 'O';   
    //                 return;
    //             }

    //         }
    //     }

    //     for(int k = 0; k < 9; k++){
    //         if (k==4){
    //             continue;
    //         }
    //         else if(spaces[4] == spaces[k] && spaces[4] != ' '){
    //             for(int j = 8;j >= 0;j--){
    //                 if((j + k) == 8 && spaces[j] == ' '){
    //                     spaces[j] = 'O';
    //                     return;
    //                 }
                
    //             }
        
    //         }
    //     }

    // }
    int i = 0;

    do{
        result = (rand() % 9);
        i++;
    }
    while(spaces[result] != ' ' && i<9);
    spaces[result] = 'O';
    cout << endl << result << endl;
}
bool whoWon(char *spaces, int *score){
        int i = 0;
        for(int i = 0;i < 7 ;i+=3){
            if(((spaces[i] == spaces[i+1]) && (spaces[i+1] == spaces[i+2])) && spaces[i] != ' '){
                if(spaces[i] == 'X'){
                        cout << "Player Won!1";
                        score[0]++;
                    }
                    else{
                        cout << "Player Lose!1";
                        score[1]++;
                    }
                    return false;
            }
        }

        for(int i = 0; i < 3 ; i++){
            if((spaces[i] == spaces[i+3]) && (spaces[i+3] == spaces[i+6]) && spaces[i] != ' '){
                if(spaces[i] == 'X'){
                    cout << "Player Won!2";
                    score[0]++;
                }
                else{
                    cout << "Player Lose!2";
                    score[1]++;
                }
                
                return false;
            }
        }

        if ((spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' ') || (spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' ')) {
            if (spaces[4] == 'X') {
                cout << "Player Won!3" << endl;
                score[0]++;
            } else {
                cout << "Player Lose!3" << endl;
                score[1]++;
            }
            return false;
        }
    
    return true;
}



int main(){
    srand(time(NULL));
    int score[2] = {0,0};
    
    char choice = 'Y';
    while(choice == 'Y'){
        
        char spaces[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
        board(spaces);


        int moveCount = 0;  

        bool running = true;


        while(running){
        playerInput(spaces);
        computerInput(spaces);
        board(spaces);

        cout << endl;

        moveCount = moveCount + 2;

        if(moveCount >= 9){
            if(whoWon(spaces,score)){
                cout << "Match was a tie!";
            }
                running = false;
        }
        else{
            running = whoWon(spaces, score);
        }
    }

    cout << endl << endl << "*****_____ " << "  Won : " << score[0] << "     Lose : "<< score[1] << "  _____*****" << endl << endl;

    cout << endl << "Play Again! [Y/N] : ";
    cin >> choice;
    }

}