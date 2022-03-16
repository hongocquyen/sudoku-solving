#include <iostream>

using namespace std;

void printSolution(int S[][9]){
    for(int i = 0; i< 9 ; i++){
        for(int j = 0; j < 9; j++){
            cout<<S[i][j] <<" ";
        }
        cout<<endl;
    }
}

bool checkValid(int S[][9], int x, int y, int k){
    for(int i = 0; i < 9; i++){
        if(S[x][i] == k) return false;
    }
    for(int i = 0 ; i < 9; i++){
        if(S[i][y] == k) return false;
    }
    int a = x/3;
    int b = y/3;
    for(int i =3*a; i < 3*a + 3;i++){
        for( int j = 3*b; j< 3*b + 3;j++){
            if(S[i][j] == k ) return false;
        }
    }
    return true;
}

void solveSodoku(int S[][9], int x, int y){
    if(y==9){
        if(x==8){
            printSolution(S);
            exit(0);
        }
        else solveSodoku(S,x+1,0);
    }
    else if(S[x][y] == 0)
    {
        for(int k = 1; k <= 9; k++){
            if(checkValid(S,x,y,k)){
                S[x][y] = k;
                solveSodoku(S,x,y+1);
                S[x][y] = 0;
            }
        }
    }
    else solveSodoku(S,x,y+1);

}


void solve(int S[][9],int x,int y){
    if(y==9){
        if (x == 8) 
        {
            printSolution(S);
            exit(0);
        }
        else
            solve(S, x + 1, 0);
    }
    else if(S[x][y] == 0){
        for (int k = 1; k <= 9;k++)
        {
            if(checkValid(S,x,y,k))
            {
                S[x][y] = k;
                solve(S, x, y+1);
                S[x][y] = 0;
            }
        }
    }
    else solve(S, x , y+1);
}
int main(){
    int S[9][9] = 
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},    
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    solve(S,0,0);
}