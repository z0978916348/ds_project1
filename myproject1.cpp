#include <iostream>

using namespace std;


class Tetris {
public:
    string str;     
    int position;   // 落下的左下方的col
    int temp[4][4]; // 接收當前是哪一個方塊
    int wide;       // 水平接觸長度
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
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_T1[i][j]; wide = 3;
        } else if (str == "T2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_T2[i][j]; wide = 2;
        } else if (str == "T3") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_T3[i][j]; wide = 3;
        } else if (str == "T4") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_T4[i][j]; wide = 2;
        } else if (str == "L1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_L1[i][j]; wide = 2;
        } else if (str == "L2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_L2[i][j]; wide = 3;
        } else if (str == "L3") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_L3[i][j]; wide = 2; 
        } else if (str == "L4") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_L4[i][j]; wide = 3;
        } else if (str == "J1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_J1[i][j]; wide = 2;
        } else if (str == "J2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_J2[i][j]; wide = 3;
        } else if (str == "J3") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_J3[i][j]; wide = 2;
        } else if (str == "J4") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_J4[i][j]; wide = 3;
        } else if (str == "S1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_S1[i][j]; wide = 3;
        } else if (str == "S2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_S2[i][j]; wide = 2;
        } else if (str == "Z1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_Z1[i][j]; wide = 3;
        } else if (str == "Z2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_Z2[i][j]; wide = 2;
        } else if (str == "I1") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_I1[i][j]; wide = 1;
        } else if (str == "I2") {
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_I2[i][j]; wide = 4;
        } else  {                              
            for (int i=0; i<4; i++) for (int j=0; j<4; j++) temp[i][j] = tetris_O[i][j] ; wide = 2;
        }
}
int main()
{
    Tetris tetris;
    int rows, cols;
    cin >> rows >> cols >> tetris.str >> tetris.position;


    int **Map = new int*[rows+4];
    for (int i=0; i<rows+4; i++) Map[i] = new int[cols+1];

    for (int i=0; i<rows+4; i++) {
        for (int j=0; j<cols+1; j++) {
            if (j==0) Map[i][j] = -1;
            else Map[i][j] = 0;
        }
    }
    

    int empty[cols+1]; // 紀錄每個col的最高堆積方塊的位置 position(empty[col], col)
    for (int i=1; i<cols+1; i++) empty[i] = rows+3;

    while ( tetris.str != "End") {
        /*for (int i =1; i<=cols; i++)
            cout << "empty[" << i << "] = " << empty[i] << endl;   ***test empty[col] */ 
        int pos = tetris.position;
        if ( tetris.str == "T1") {
            
            if (pos>cols-2 || pos<1 ) {
                cin >> tetris.str >> tetris.position;  
                cout << "invalid" << endl;
                continue;
            }
            int place = empty[pos+1];
            while ( !(Map[place-1][pos]==0 && Map[place-1][pos+2]==0) ) place--;
            Map[place][pos+1] = Map[place-1][pos+1] = Map[place-1][pos] = Map[place-1][pos+2] = 1;   

        } else if ( tetris.str == "T2") {

        } else if ( tetris.str == "T3") {
            
        } else if ( tetris.str == "T4") {
            
        } else if ( tetris.str == "L1") {
            
        } else if ( tetris.str == "L2") {
            
        } else if ( tetris.str == "L3") {
            
        } else if ( tetris.str == "L4") {
            
        } else if ( tetris.str == "J1") {
            
        } else if ( tetris.str == "J2") {
            
        } else if ( tetris.str == "J3") {
            
        } else if ( tetris.str == "J4") {
            
        } else if ( tetris.str == "S1") {
            
        } else if ( tetris.str == "S2") {
            
        } else if ( tetris.str == "Z1") {
            
        } else if ( tetris.str == "Z2") {
            
        } else if ( tetris.str == "I1") {
            
        } else if ( tetris.str == "I2") {
            
        } else {     // tetris.str == "O"

        }
        int flag = 1, floor = 0, index; 
        for (int i=rows+3; i>3; i--) {   //  消掉排
            flag = 1;
            for (int j=1; j<=cols+1; j++) 
                if (Map[i][j]==0) flag = 0;
            //cout << "flag = " << flag << endl;
            //cout << "i = " << i << endl;
            if (flag) {
                floor++;
                for (int j=1; j<=cols+1; j++)
                    Map[i][j] = 0;
            }
            
            //cout << "i = " << i << " flag = " << flag << endl;
            if ( flag )index = i;
        }
        
        index = index + floor - 1;
        //cout << "index = " << index << " floor = " << floor << endl;
        if (floor > 0) {
                for (int i=index; i>floor-1; i--) {         //消掉後下降
                    for (int j=1; j<cols+1; j++) {
                        if (Map[i-floor][j] == 1) Map[i][j] = 1;
                        else Map[i][j] = 0;
                    }
                }
                //cout << "OK" << endl;
                for (int i=0; i<floor; i++)
                for (int j=1; j<cols+1; j++)
                    Map[i][j] = 0;
        }
        
        for (int i=rows+3; i>=0; i--) {   // 存每個col第幾個row可用 size (rows+4)*cols
            for (int j=1; j<cols+1; j++) {
                if (Map[i][j]==1) empty[j] = i-1;
                else if (Map[0][j]==1) empty[j] = 0; // 如果整個col連額外的4格都滿了 最上面那格設為0
            }
        }
        //cout << "empty[2] = " << empty[2] << endl;              ***for debug
        /*cout << "---------------------------------" << endl;
        for (int i=1; i<cols+1; i++)
                cout << Map[9][i] << " ";
        cout << endl;
        cout << "---------------------------------" << endl;*/
        for (int i=1; i<cols+1; i++) {
            if (empty[i] < 3) {
                cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG" << endl;
                return 0;
            }
        }
        for (int i=4; i<rows+4; i++) {  //show Map
                for (int j=1; j<cols+1; j++) {
                    cout << Map[i][j] << " ";
                }
                cout << endl;
        }
        cin >> tetris.str >> tetris.position;  //指令輸入
    }
    
    
    return 0;
}