#include <bits/stdc++.h>
using namespace std;
int n,m;
int k = 10;
int gameMap[100][100];
string screenMap[100][100];

void initMap(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            gameMap[i][j] = 0;
            screenMap[i][j] = "*";
        }
    }
    int numOfbombs = k;
    srand(unsigned(time(NULL)));
    while(numOfbombs > 0){
        int randIndex1 = rand() % n;
        int randIndex2 = rand() % m;
        if(gameMap[randIndex1][randIndex2] != -1){
            gameMap[randIndex1][randIndex2] = -1;
            numOfbombs --;
        }
    }
}

int checkBombs(int x, int y){
    int surroundBombs = 0;
    if(gameMap[x][y] == -1){
        k--;
        return -1;
    }
    for(int i = x - 1; i <= x + 1; i++){
        for(int j = y - 1; j <= y + 1; j++){
            if(gameMap[i][j] == -1)surroundBombs ++;
        }
    }
return surroundBombs;
}

bool checkWin(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(screenMap[i][j] == "*" && gameMap[i][j] != -1)return false;
        }
    }
return true;
}

void input(){
    while(k == 10){
        int x,y; cout << "Enter your coordinates: ";
        cin >> x >> y;
        string temp = to_string(checkBombs(x,y));
        screenMap[x][y] = temp;
        cout << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << screenMap[i][j] << " ";
            }
            cout << endl;
        }
        if(checkWin() == true){
            cout << "You won!" << endl;
            k++;
        }
    }
}

int main(){
    cout << "Enter your map'size: ";
    cin >> n >> m; 
    initMap(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << screenMap[i][j] << " ";
        }
        cout << endl;
    }
    input();
    
if(k <= 10)cout << "GAME OVER!";
    
return 0;
}