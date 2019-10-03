#include <iostream>

using namespace std;

int cols;

class Tetris {
public:
    string str;     
    int position;   // 落下的左下方的col
    int temp[4][4]; // 接收當前是哪一個方塊
    int wide, depth;
    void Identify_Tetris();
    
    
private:
    const int tetris_T1[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {1, 1, 1, 0},
                                  {0, 1, 0, 0} };
    const int tetris_T2[4][4] = { {0, 0, 0, 0}, 
                                  {0, 1, 0, 0},
                                  {1, 1, 0, 0},
                                  {0, 1, 0, 0} };
    const int tetris_T3[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {0, 1, 0, 0},
                                  {1, 1, 1, 0} };
    const int tetris_T4[4][4] = { {0, 0, 0, 0}, 
                                  {1, 0, 0, 0},
                                  {1, 1, 0, 0},
                                  {1, 0, 0, 0} };
    const int tetris_L1[4][4] = { {0, 0, 0, 0}, 
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 0},
                                  {1, 1, 0, 0} };
    const int tetris_L2[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {1, 1, 1, 0},
                                  {1, 0, 0, 0} };
    const int tetris_L3[4][4] = { {0, 0, 0, 0}, 
                                  {1, 1, 0, 0},
                                  {0, 1, 0, 0},
                                  {0, 1, 0, 0} };
    const int tetris_L4[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {0, 0, 1, 0},
                                  {1, 1, 1, 0} };
    const int tetris_J1[4][4] = { {0, 0, 0, 0}, 
                                  {0, 1, 0, 0},
                                  {0, 1, 0, 0},
                                  {1, 1, 0, 0} };
    const int tetris_J2[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {1, 0, 0, 0},
                                  {1, 1, 1, 0} };
    const int tetris_J3[4][4] = { {0, 0, 0, 0}, 
                                  {1, 1, 0, 0},
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 0} };
    const int tetris_J4[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {1, 1, 1, 0},
                                  {0, 0, 1, 0} };
    const int tetris_S1[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {0, 1, 1, 0},
                                  {1, 1, 0, 0} };
    const int tetris_S2[4][4] = { {0, 0, 0, 0}, 
                                  {1, 0, 0, 0},
                                  {1, 1, 0, 0},
                                  {0, 1, 0, 0} };
    const int tetris_Z1[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {1, 1, 0, 0},
                                  {0, 1, 1, 0} };
    const int tetris_Z2[4][4] = { {0, 0, 0, 0}, 
                                  {0, 1, 0, 0},
                                  {1, 1, 0, 0},
                                  {1, 0, 0, 0} };

    const int tetris_I1[4][4] = { {1, 0, 0, 0}, 
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 0} };
    const int tetris_I2[4][4] = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {1, 1, 1, 1} };
    const int tetris_O[4][4]  = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {1, 1, 0, 0},
                                  {1, 1, 0, 0} };
};

void Tetris::Identify_Tetris() {
        if (str == "T1" ) {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_T1[i][j]; wide = 3; depth = 2;
        } else if (str == "T2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_T2[i][j]; wide = 2; depth = 3;
        } else if (str == "T3") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_T3[i][j]; wide = 3; depth = 2;
        } else if (str == "T4") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_T4[i][j]; wide = 2; depth = 3;
        } else if (str == "L1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_L1[i][j]; wide = 2; depth = 3;
        } else if (str == "L2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_L2[i][j]; wide = 3; depth = 2;
        } else if (str == "L3") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_L3[i][j]; wide = 2; depth = 3;
        } else if (str == "L4") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_L4[i][j]; wide = 3; depth = 2;
        } else if (str == "J1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_J1[i][j]; wide = 2; depth = 3;
        } else if (str == "J2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_J2[i][j]; wide = 3; depth = 2;
        } else if (str == "J3") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_J3[i][j]; wide = 2; depth = 3;
        } else if (str == "J4") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_J4[i][j]; wide = 3; depth = 2;
        } else if (str == "S1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_S1[i][j]; wide = 3; depth = 2;
        } else if (str == "S2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_S2[i][j]; wide = 2; depth = 3;
        } else if (str == "Z1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_Z1[i][j]; wide = 3; depth = 2;
        } else if (str == "Z2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_Z2[i][j]; wide = 2; depth = 3;
        } else if (str == "I1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_I1[i][j]; wide = 1; depth = 4;
        } else if (str == "I2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_I2[i][j]; wide = 4; depth = 1;
        } else  {                              
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_O[i][j] ; wide = 2; depth = 2;
        }
}
int main()
{
    Tetris tetris;
    int rows;
    cin >> rows >> cols >> tetris.str;


    int Map[rows+4][cols+1] = {0};
    int empty[cols+1]; // 紀錄每個col的最高堆積方塊的位置 position(empty[col], col)

    while ( tetris.str != "End") {
        tetris.Identify_Tetris();

        for (int i = rows; i>=1; i--)           // 找出已經堆積的方塊
        for (int j = 1; j<=cols; j++) {
            if ( Map[i][j] == 1 ) empty[j] = i;  // 若 empty[col] !=0 代表這個col最高堆積處為 empty[col]
            else empty[j] = 0; // 若 empty[col] == 0 代表這個col皆可放置 
        }

        


        cin >> tetris.position >> tetris.str;
    }
    
    
    return 0;
}