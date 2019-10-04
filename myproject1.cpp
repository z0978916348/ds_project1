#include <iostream>
#include <fstream>
using namespace std;


class Tetris {
public:
    string str;     
    int position;   // 落下的左下方的col
};

int main()
{
    Tetris tetris;
    int rows, cols;
    //cin >> rows >> cols >> tetris.str >> tetris.position;
    
    ifstream inFile("myin.out", ios::in);
    if (! inFile) {
        cout << "cannot open myin.out" << endl;
        return 1;
    }
    inFile >> rows >> cols >> tetris.str >> tetris.position;

    ofstream outFile("myout.out", ios::out);   //輸出檔案
    if (! outFile) {
        cout << "cannot open myout.out" << endl;
        return 1;
    }

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
        //cout << "position = " << tetris.position << endl;
        if ( tetris.str == "T1") {
            if (pos>cols-2 || pos<1 || cols<3 ) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos+1];  
            //cout << "place = " << place << endl;                  
            while ( !(Map[place-1][pos]==0 && Map[place-1][pos+2]==0) ) place--;
            Map[place][pos+1] = Map[place-1][pos+1] = Map[place-1][pos] = Map[place-1][pos+2] = 1;   
        } else if ( tetris.str == "T2") {
            if (pos>cols-1 || pos<1 || cols<2 ) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos+1];
            while ( Map[place-1][pos]!=0 ) place--;
            Map[place][pos+1] = Map[place-1][pos+1] = Map[place-2][pos+1] = Map[place-1][pos] = 1;
        } else if ( tetris.str == "T3") {
            if (pos>cols-2 || pos<1 || cols<3) {                 //判斷測資是否合法 
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos+1];
            while ( !(Map[place][pos]==0 && Map[place][pos+2]==0) ) place--;
            Map[place][pos+1] = Map[place-1][pos+1] = Map[place][pos] = Map[place][pos+2] = 1;
        } else if ( tetris.str == "T4") {
            if (pos>cols-1 || pos<1 || cols<2) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( Map[place-1][pos+1]!=0 ) place--; 
            Map[place][pos] = Map[place-1][pos] = Map[place-2][pos] = Map[place-1][pos+1] = 1;
        } else if ( tetris.str == "L1") {
            if (pos>cols-1 || pos<1 || cols<2) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( Map[place][pos+1]!=0 ) place--;
            Map[place][pos] = Map[place][pos+1] = Map[place-1][pos] = Map[place-2][pos] = 1;
        } else if ( tetris.str == "L2") {
            if (pos>cols-2 || pos<1 || cols<3) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( !(Map[place-1][pos+1]==0 && Map[place-1][pos+2]==0) ) place--;
            Map[place][pos] = Map[place-1][pos] = Map[place-1][pos+1] = Map[place-1][pos+2] = 1;
        } else if ( tetris.str == "L3") {
            if (pos>cols-1 || pos<1 || cols<2) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos+1];
            while ( Map[place-2][pos]!=0 ) place--;
            Map[place][pos+1] = Map[place-1][pos+1] = Map[place-2][pos+1] = Map[place-2][pos] = 1; 
        } else if ( tetris.str == "L4") {
            if (pos>cols-2 || pos<1 || cols<3) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( !(Map[place][pos+1]==0 && Map[place][pos+1]==0) ) place--;
            Map[place][pos] = Map[place][pos+1] = Map[place][pos+2] = Map[place-1][pos+2] = 1;
        } else if ( tetris.str == "J1") {
            if (pos>cols-1 || pos<1 || cols<2) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( Map[place][pos+1]!=0 ) place--;
            Map[place][pos] = Map[place][pos+1] = Map[place-1][pos+1] = Map[place-2][pos+1] = 1;
        } else if ( tetris.str == "J2") {
            if (pos>cols-2 || pos<1 || cols<3) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( !(Map[place][pos+1]==0 && Map[place][pos+2]==0) ) place--;
            Map[place][pos] = Map[place-1][pos] = Map[place][pos+1] = Map[place][pos+2] = 1;
        } else if ( tetris.str == "J3") {
            if (pos>cols-1 || pos<1 || cols<2) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( Map[place-2][pos+1]!=0 ) place--;
            Map[place][pos] = Map[place-1][pos] = Map[place-2][pos] = Map[place-2][pos+1] = 1;
        } else if ( tetris.str == "J4") {
            if (pos>cols-2 || pos<1 || cols<3) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos+2];
            while( !(Map[place-1][pos]==0 && Map[place-1][pos+1]==0) ) place--;
            Map[place][pos+2] = Map[place-1][pos] = Map[place-1][pos+1] = Map[place-1][pos+2] = 1;
        } else if ( tetris.str == "S1") {
            if (pos>cols-2 || pos<1 || cols<3) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( !(Map[place][pos+1]==0 && Map[place-1][pos+2]==0) ) place--;
            Map[place][pos] = Map[place][pos+1] = Map[place-1][pos+1] = Map[place-1][pos+2] = 1;
        } else if ( tetris.str == "S2") {
            if (pos>cols-1 || pos<1 || cols<2) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos+1];
            while ( Map[place-1][pos]!=0 ) place--;
            Map[place][pos+1] = Map[place-1][pos] = Map[place-1][pos+1] = Map[place-2][pos] = 1;
        } else if ( tetris.str == "Z1") {
            if (pos>cols-2 || pos<1 || cols<3) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos+1];
            while ( !(Map[place-1][pos]==0 && Map[place][pos+2]==0) ) place--;
            Map[place][pos+1] = Map[place][pos+2] = Map[place-1][pos] = Map[place-1][pos+1] = 1;
        } else if ( tetris.str == "Z2") {
            if (pos>cols-1 || pos<1 || cols<2) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( Map[place-1][pos+1]!=0 ) place--;
            Map[place][pos] = Map[place-1][pos] = Map[place-1][pos+1] = Map[place-2][pos+1] = 1;
        } else if ( tetris.str == "I1") {
            if (pos>cols || pos<1 || cols<1) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            //cout << "place = " << place << endl;
            //cout << "pos = " << pos << endl;
            //cout << "empty[pos] = " <<empty[pos] << endl;
            Map[place][pos] = Map[place-1][pos] = Map[place-2][pos] = Map[place-3][pos] = 1;
        } else if ( tetris.str == "I2") {
            if (pos>cols-3 || pos<1 || cols<4) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( !(Map[place][pos+1]==0 && Map[place][pos+2]==0 && Map[place][pos+3]==0) ) place--;
            Map[place][pos] = Map[place][pos+1] = Map[place][pos+2] = Map[place][pos+3] = 1;
        } else {     // tetris.str == "O"
            if (pos>cols-1 || pos<1 || cols<2) {                 //判斷測資是否合法
                outFile << "invalid" << endl;
                break;
            }
            int place = empty[pos];
            while ( Map[place][pos+1]!=0 ) place--;
            Map[place][pos] = Map[place][pos+1] = Map[place-1][pos] = Map[place-1][pos+1] = 1;
        }
        int flag = 1, floor = 0;
        int index[5] = {0}; 
        for (int i=rows+3; i>3; i--) {   //  消掉排
            flag = 1;
            for (int j=1; j<cols+1; j++) 
                if (Map[i][j]==0) flag = 0;
            if (flag) {
                for (int j=1; j<=cols+1; j++)
                    Map[i][j] = 0;
            }
            //cout << "flag = " << flag << endl;
            //cout << "i = " << i << endl;
            //cout << "i = " << i << " flag = " << flag << endl;
            if ( flag ) {
                index[floor] = i+floor;
                floor++;
            }           
        }
        /*for (int i=4; i<rows+4; i++) {  //show Map
            for (int j=1; j<cols+1; j++) {
                //outFile << Map[i][j];
                cout << Map[i][j] << " ";
            }
            //outFile << endl;
            cout << endl;
        }*/
        //cout << "---------------after-----------------------------------" << endl;
        //cout << "index[0] = " << index[0] << " index[1] = " << index[1] << endl;
        if ( floor > 0) {
            for (int k=0; k<floor; k++) {         //消掉後下降
                for (int i=index[k]; i>0; i--)
                    for (int j=1; j<cols+1; j++) {
                        if (Map[i-1][j]==1) Map[i][j] = 1;
                        else Map[i][j] = 0;
                    }
                
                 //cout << "****************************************************" << endl;
            }
            for (int j=1; j<cols+1; j++)
                Map[0][j] = 0;
        }
        
        //cout << "--------------------------------------------------------" << endl;
        for (int i=rows+3; i>=0; i--) {   // 存每個col第幾個row可用 size (rows+4)*cols
            for (int j=1; j<cols+1; j++) {
                if (Map[i][j]==1) empty[j] = i-1;
                else if (Map[0][j]==1) empty[j] = 0; // 如果整個col連額外的4格都滿了 最上面那格設為0
            }
        }
        /*cout << "----------------------------------------------------" << endl ;
        for (int i=4; i<rows+4; i++) {  //show Map
            for (int j=1; j<cols+1; j++) {
                //outFile << Map[i][j];
                cout << Map[i][j] << " ";
            }
            //outFile << endl;
            cout << endl;
        }
        cout << "----------------------------------------------------" << endl ;*/
        
        for (int i=1; i<cols+1; i++) {
            flag = 1;         //如果消除完 col為全空 則將empty[col]設為rows+3
            for (int j=rows+3; j>0; j--) {
                if (Map[j][i]==1) {
                    flag = 0; 
                    //cout << "j = " << j << " i = " << i << " Map[j][i] = " << Map[j][i] << endl;
                    break;
                }
            }
            //cout << "flag = " << flag << endl;
            if ( flag ) empty[i] = rows+3;
        }
        
        //cout << "empty[2] = " << empty[2] << endl;              ***for debug
        /*cout << "---------------------------------" << endl;
        for (int i=1; i<cols+1; i++)
                cout << Map[9][i] << " ";
        cout << endl;
        cout << "---------------------------------" << endl;*/
        int jump = 0;
        for (int i=1; i<cols+1; i++) {
            if (empty[i] < 3) {
                jump = 1;
                break;
            }
        }
        if (jump) break;

        /*for (int i=4; i<rows+4; i++) {  //show Map
            for (int j=1; j<cols+1; j++) {
                //outFile << Map[i][j];
                cout << Map[i][j] << " ";
            }
            //outFile << endl;
            cout << endl;
        }*/

        //cin >> tetris.str;
        inFile >> tetris.str;
        if (tetris.str == "End") break;
        inFile >> tetris.position;
        //cin >> tetris.position;  //指令輸入

    }
    
    
    for (int i=4; i<rows+4; i++) {  //show Map
            for (int j=1; j<cols+1; j++) {
                outFile << Map[i][j];
                //cout << Map[i][j] << " ";
            }
            outFile << endl;
            //cout << endl;
    }
    
    return 0;
}