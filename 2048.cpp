#include <iostream>
using namespace std;

int grid[4][4]= {0};
int Gcopy[4][4]= {0};
int prevGrid[4][4]={0};

void displayGrid(){
    cout << endl;
    for(int i=0;i<4;i++){
        cout << "|";
        for(int j=0;j<4;j++){
            if(grid[i][j]){
                if(grid[i][j]<10)
                    cout << grid[i][j] << "   |";
                else if (grid[i][j]<100)
                    cout << grid[i][j] << "  |";
                else if (grid[i][j] < 1000)
                    cout << grid[i][j] << " |";
                else
                    cout << grid[i][j] << "|";
            }
            else
                cout << "    |";
        }
        cout << endl;
    }
}

void prevState(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            prevGrid[i][j] = grid[i][j];
        }
    }
}

bool isSame(){
    int zCount = 0;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j]!=prevGrid[i][j])
                return false;
            if(!grid[i][j])
                zCount++;
        }
    }
    if(zCount==16)
        return false;
    
return true;
}

int randomNumber(){
    return ( ((rand() % 10) < 8) ? 2 : 4 ); // Return 2 90 % of the times, otherwise 4
}

void randomPosition(){
    
    if(isSame())
        return;
    
    int i,j;
    
    while(1){
        i = rand()%4;
        j = rand()%4;
        if(!grid[i][j])
            break;
        else
            continue;
    }
    grid[i][j] = randomNumber();
    Gcopy[i][j] = grid[i][j];
    return;
}

void newGame(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid[i][j]=0;
            Gcopy[i][j]=0;
        }
    }
    randomPosition();
    randomPosition();
    return;
}


void moveLeft(){
    int i,j,k;
    
        for(i=0;i<4;i++){
            
            for(j=1;j<4;j++){
                if(grid[i][j]){
                    for(k=j;k>0 && !grid[i][k-1];k--){
                        grid[i][k-1] = grid[i][k];
                        grid[i][k] = 0;
                        Gcopy[i][k-1] = grid[i][k-1];
                        Gcopy[i][k] = grid[i][k];
                        
                    }
                }
            }
            
            for(j=1;j<4;j++){
                if(grid[i][j]){
                    if(grid[i][j] == grid[i][j-1]){
                        grid[i][j-1] *= 2;
                        grid[i][j] = 0;
                        Gcopy[i][j-1] = grid[i][j-1];
                        Gcopy[i][j] = grid[i][j];
                    }
                }
            }
            
            for(j=1;j<4;j++){
                if(grid[i][j]){
                    for(k=j;k>0 && !grid[i][k-1];k--){
                        grid[i][k-1] = grid[i][k];
                        grid[i][k] = 0;
                        Gcopy[i][k-1] = grid[i][k-1];
                        Gcopy[i][k] = grid[i][k];
                        
                    }
                }
            }
            
            
    }
    randomPosition();
return;
}


void moveDown(){
    int i,j,k;
    
        for(j=0;j<4;j++){
            
            for(i=2;i>=0;i--){
                if(grid[i][j]){
                    for(k=i;k<3 && !grid[k+1][j];k++){
                        
                        grid[k+1][j] = grid[k][j];
                        grid[k][j] = 0;
                        Gcopy[k+1][j] = grid[k+1][j];
                        Gcopy[k][j] = grid[k][j];
                    }
                }
            }
            
            for(i=2;i>=0;i--){
                if(grid[i][j]){
                    if(grid[i][j] == grid[i+1][j]){
                        grid[i+1][j] *= 2;
                        grid[i][j] = 0;
                        Gcopy[i+1][j] = grid[i+1][j];
                        Gcopy[i][j] = grid[i][j];
                    }
                }
            }
            
            for(i=2;i>=0;i--){
                if(grid[i][j]){
                    for(k=i;k<3 && !grid[k+1][j];k++){
                        
                        grid[k+1][j] = grid[k][j];
                        grid[k][j] = 0;
                        Gcopy[k+1][j] = grid[k+1][j];
                        Gcopy[k][j] = grid[k][j];
                    }
                }
            }
            
            
        }
    randomPosition();
    return;
}


void moveRight(){
    int i,j,k;
    
        for(i=0;i<4;i++){
            
            for(j=2;j>=0;j--){
                if(grid[i][j]){
                    for(k=j;k<3 && !grid[i][k+1];k++){
                        grid[i][k+1] = grid[i][k];
                        grid[i][k] = 0;
                        Gcopy[i][k+1] = grid[i][k+1];
                        Gcopy[i][k] = grid[i][k];
                    }
                }
            }
            
            for(j=2;j>=0;j--){
                if(grid[i][j]){
                    if(grid[i][j] == grid[i][j+1]){
                        grid[i][j+1] *= 2;
                        grid[i][j] = 0;
                        Gcopy[i][j+1] = grid[i][j+1];
                        Gcopy[i][j] = grid[i][j];
                    }
                }
            }
            
            for(j=2;j>=0;j--){
                if(grid[i][j]){
                    for(k=j;k<3 && !grid[i][k+1];k++){
                        grid[i][k+1] = grid[i][k];
                        grid[i][k] = 0;
                        Gcopy[i][k+1] = grid[i][k+1];
                        Gcopy[i][k] = grid[i][k];
                    }
                }
            }
        }
    randomPosition();
    return;
}


void moveUp() {
    int i,j,k;
    
        for(j=0;j<4;j++){
            
            for(i=1;i<4;i++){
                if(grid[i][j]){
                    for(k=i;k>0 && !grid[k-1][j];k--){
                        grid[k-1][j] = grid[k][j];
                        grid[k][j] = 0;
                        Gcopy[k-1][j] = grid[k-1][j];
                        Gcopy[k][j] = grid[k][j];
                    }
                }
            }
            
            for(i=1;i<4;i++){
                if(grid[i][j]){
                    if(grid[i][j] == grid[i-1][j]){
                        grid[i-1][j] *= 2;
                        grid[i][j] = 0;
                        Gcopy[i-1][j] = grid[i-1][j];
                        Gcopy[i][j] = grid[i][j];
                    }
                }
            }
            
            for(i=1;i<4;i++){
                if(grid[i][j]){
                    for(k=i;k>0 && !grid[k-1][j];k--){
                        grid[k-1][j] = grid[k][j];
                        grid[k][j] = 0;
                        Gcopy[k-1][j] = grid[k-1][j];
                        Gcopy[k][j] = grid[k][j];
                    }
                }
            }
        }
    randomPosition();
    return;
}

void undo(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid[i][j] = prevGrid[i][j];
        }
    }
return;
}


bool isGameOver(){
    int zCount = 0;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(!grid[i][j])
                zCount++;
        }
    }
    return ( zCount != 0 ? false : true );
}

bool win(){
    int max = 0;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j] > max)
                max = grid[i][j];
        }
    }
    return ( max == 2048 ? true : false);
}

int main(){
    srand(time(NULL));
    newGame();
    displayGrid();
    
    
    char input;
    cin >> input;
    
    while(1){
        switch (input){
            case 'a':
            case 'A':
                prevState();
                moveLeft();
                break;
                
            case 's':
            case 'S':
                prevState();
                moveDown();
                break;
                
            case 'w':
            case 'W':
                prevState();
                moveUp();
                break;
                
            case 'd':
            case 'D':
                prevState();
                moveRight();
                break;
            
            case 'n':
            case 'N':
                newGame();
                break;
            
            case 'u':
            case 'U':
                undo();
                break;
                
            case 'Q':
                exit(0);
                
            default:
                cout << "Wrong Input, Try Again" << endl;
        }
        
        displayGrid();
        
        if (isGameOver()){
            cout << "\n\n======GAME OVER======\n\n";
            return 0;
        }
        
        if(win()){
            cout << "\n\n======YOU WON!=======\n\n";
            return 0;
        }
        
        cin >> input;
        
    }
    
    return 0;
}

