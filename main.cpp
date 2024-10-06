/*
░█████╗░███╗░░░███╗░█████╗░██████╗░
██╔══██╗████╗░████║██╔══██╗██╔══██╗
██║░░██║██╔████╔██║███████║██████╔╝
██║░░██║██║╚██╔╝██║██╔══██║██╔══██╗
╚█████╔╝██║░╚═╝░██║██║░░██║██║░░██║
░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝
*/

#include <conio.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define endl '\n';

struct point {
    int x;
    int y;
};

struct Bullet {
    point posbullet;
};

struct Hero {
    point poshero;
    int health;
};
struct Spider {
    point posspider;
};

struct SpiderEgg {
    point posspideregg;
};

struct Elevator {
    point posElevator;
};
struct enmy {
    point posenmy;
};
struct Dragon {
    point posdragon;
};


void clearAndDrawFxObjects(char game[][950]) {
    for (int i = 0; i < 75; ++i) {
        for (int j = 0; j < 950; ++j) {
            game[i][j] = ' ';
        }
    }
    //----------------------------------------laser head
    int r = 30, c = 510;
    game[r][c + 1] = '/';
    game[r][c - 1] = 92;
    game[r + 1][c] = 167;
    game[r][c + 1] = '/';
    game[r][c - 1] = 92;
    game[r + 1][c] = 167;
    //---------------------------------------- grass
    r = 74;
    for (int i = 0; i < 950; i += 2) {
        game[r][i] = 'w';
        game[r][i + 1] = 'W';

    }
    for (int i = 5; i < 950; i += 7) {
        game[73][i] = '\\';
        game[73][i + 1] = '\\';
        game[73][i + 2] = '/';
        game[73][i + 3] = '/';
    }
    //--------------------------------------------------clouds
    int x = 8, y = 3;
    for (int j = 0; j < 950; j += 50) {

        game[x - 5][j + 10] = '.';
        game[x - 5][j + 11] = '-';
        game[x - 5][j + 12] = '~';
        game[x - 5][j + 13] = '~';
        game[x - 5][j + 14] = '~';
        game[x - 5][j + 15] = '-';
        game[x - 5][j + 16] = '.';
        game[x - 4][j + 2] = '.';
        game[x - 4][j + 3] = '-';
        game[x - 4][j + 5] = '~';
        game[x - 4][j + 7] = '~';
        game[x - 4][j + 8] = '-';
        game[x - 4][j + 9] = '(';
        game[x - 4][j + 17] = ')';
        game[x - 4][j + 18] = '_';
        game[x - 4][j + 20] = '_';
        game[x - 3][j + 1] = '/';
        game[x - 3][j + 23] = '~';
        game[x - 3][j + 25] = '-';
        game[x - 3][j + 26] = '.';
        game[x - 2][j + 0] = '|';
        game[x - 2][j + 28] = '\\';
        game[x - 1][j + 1] = '\\';
        game[x - 1][j + 27] = '.';
        game[x - 1][j + 28] = '\'';
        game[x - 0][j + 3] = '~';
        game[x - 0][j + 4] = '-';
        game[x - 0][j + 6] = '.';
        game[x - 0][j + 8] = '_';
        game[x - 0][j + 9] = '_';
        game[x - 0][j + 10] = '_';
        game[x - 0][j + 11] = '_';
        game[x - 0][j + 12] = '_';
        game[x - 0][j + 13] = '_';
        game[x - 0][j + 14] = '_';
        game[x - 0][j + 15] = '_';
        game[x - 0][j + 16] = '_';
        game[x - 0][j + 17] = '_';
        game[x - 0][j + 18] = '_';
        game[x - 0][j + 19] = '_';
        game[x - 0][j + 20] = '_';
        game[x - 0][j + 22] = '.';
        game[x - 0][j + 24] = '-';
        game[x - 0][j + 25] = '~';


    }
    //-------------------------------------------------------tree
    x = 65, y = 140;
    game[x - 26][y + 48] = '.';
    game[x - 26][y + 56] = ';';
    game[x - 25][y + 17] = '.';
    game[x - 25][y + 32] = '.';
    game[x - 25][y + 49] = '\\';
    game[x - 25][y + 55] = '/';
    game[x - 24][y + 19] = ',';
    game[x - 24][y + 31] = ',';
    game[x - 24][y + 50] = '\\';
    game[x - 24][y + 51] = '\\';
    game[x - 24][y + 53] = '/';
    game[x - 24][y + 54] = '/';
    game[x - 23][y + 20] = '\\';
    game[x - 23][y + 30] = '/';
    game[x - 23][y + 51] = '\\';
    game[x - 23][y + 53] = '/';
    game[x - 23][y + 62] = '.';
    game[x - 23][y + 63] = ',';
    game[x - 22][y + 11] = ',';
    game[x - 22][y + 12] = '.';
    game[x - 22][y + 21] = '\\';
    game[x - 22][y + 22] = '\\';
    game[x - 22][y + 28] = '/';
    game[x - 22][y + 29] = '/';
    game[x - 22][y + 42] = ';';
    game[x - 22][y + 51] = '/';
    game[x - 22][y + 52] = '/';
    game[x - 22][y + 59] = ',';
    game[x - 22][y + 60] = '_';
    game[x - 22][y + 61] = '_';
    game[x - 22][y + 62] = '/';
    game[x - 21][y + 13] = '\\';
    game[x - 21][y + 22] = '\\';
    game[x - 21][y + 23] = '\\';
    game[x - 21][y + 27] = '/';
    game[x - 21][y + 28] = '/';
    game[x - 21][y + 42] = '|';
    game[x - 21][y + 43] = '|';
    game[x - 21][y + 49] = '|';
    game[x - 21][y + 51] = '|';
    game[x - 21][y + 56] = ',';
    game[x - 21][y + 57] = '/';
    game[x - 21][y + 58] = '/';
    game[x - 20][y + 14] = '\\';
    game[x - 20][y + 23] = '\\';
    game[x - 20][y + 24] = '\\';
    game[x - 20][y + 26] = '/';
    game[x - 20][y + 27] = '/';
    game[x - 20][y + 36] = ';';
    game[x - 20][y + 43] = '\\';
    game[x - 20][y + 44] = '\\';
    game[x - 20][y + 48] = '|';
    game[x - 20][y + 50] = '|';
    game[x - 20][y + 54] = ',';
    game[x - 20][y + 55] = '/';
    game[x - 20][y + 57] = '/';
    game[x - 20][y + 58] = '\'';
    game[x - 19][y + 15] = '\\';
    game[x - 19][y + 16] = '_';
    game[x - 19][y + 17] = '_';
    game[x - 19][y + 24] = '\\';
    game[x - 19][y + 26] = '/';
    game[x - 19][y + 34] = '/';
    game[x - 19][y + 35] = '/';
    game[x - 19][y + 44] = '\\';
    game[x - 19][y + 45] = '\\';
    game[x - 19][y + 47] = '/';
    game[x - 19][y + 49] = '/';
    game[x - 19][y + 53] = ';';
    game[x - 19][y + 54] = '/';
    game[x - 19][y + 56] = '/';
    game[x - 19][y + 57] = '\'';
    game[x - 18][y + 17] = '`';
    game[x - 18][y + 18] = '\\';
    game[x - 18][y + 19] = '.';
    game[x - 18][y + 25] = '\\';
    game[x - 18][y + 26] = '\\';
    game[x - 18][y + 33] = '/';
    game[x - 18][y + 34] = '/';
    game[x - 18][y + 35] = '\'';
    game[x - 18][y + 40] = '\\';
    game[x - 18][y + 45] = '\\';
    game[x - 18][y + 49] = '/';
    game[x - 18][y + 52] = ';';
    game[x - 18][y + 53] = '/';
    game[x - 18][y + 55] = '/';
    game[x - 18][y + 56] = '\'';
    game[x - 17][y + 17] = '`';
    game[x - 17][y + 19] = '\\';
    game[x - 17][y + 20] = '\\';
    game[x - 17][y + 21] = '.';
    game[x - 17][y + 26] = '\\';
    game[x - 17][y + 27] = '\\';
    game[x - 17][y + 29] = '\\';
    game[x - 17][y + 30] = '\\';
    game[x - 17][y + 32] = '/';
    game[x - 17][y + 33] = '/';
    game[x - 17][y + 41] = '\\';
    game[x - 17][y + 42] = '\\';
    game[x - 17][y + 46] = '|';
    game[x - 17][y + 49] = '|';
    game[x - 17][y + 50] = '_';
    game[x - 17][y + 51] = '_';
    game[x - 17][y + 52] = '/';
    game[x - 17][y + 54] = '/';
    game[x - 17][y + 55] = '\'';
    game[x - 16][y + 20] = '`';
    game[x - 16][y + 21] = '\\';
    game[x - 16][y + 23] = '\\';
    game[x - 16][y + 24] = '.';
    game[x - 16][y + 27] = '\\';
    game[x - 16][y + 28] = '\\';
    game[x - 16][y + 29] = '/';
    game[x - 16][y + 30] = '_';
    game[x - 16][y + 32] = '/';
    game[x - 16][y + 42] = '\\';
    game[x - 16][y + 43] = '\\';
    game[x - 16][y + 44] = '_';
    game[x - 16][y + 45] = '_';
    game[x - 16][y + 46] = '|';
    game[x - 16][y + 49] = '_';
    game[x - 16][y + 50] = '_';
    game[x - 16][y + 51] = '_';
    game[x - 16][y + 52] = '_';
    game[x - 16][y + 53] = '/';
    game[x - 15][y + 22] = '`';
    game[x - 15][y + 23] = '\\';
    game[x - 15][y + 25] = '\\';
    game[x - 15][y + 26] = '.';
    game[x - 15][y + 28] = '\\';
    game[x - 15][y + 30] = '_';
    game[x - 15][y + 32] = '\\';
    game[x - 15][y + 33] = '_';
    game[x - 15][y + 42] = '_';
    game[x - 15][y + 43] = '/';
    game[x - 15][y + 47] = '_';
    game[x - 15][y + 48] = '_';
    game[x - 15][y + 49] = '/';
    game[x - 14][y + 24] = '`';
    game[x - 14][y + 25] = '\\';
    game[x - 14][y + 27] = '\\';
    game[x - 14][y + 31] = '\\';
    game[x - 14][y + 34] = '\\';
    game[x - 14][y + 35] = '_';
    game[x - 14][y + 41] = '|';
    game[x - 14][y + 45] = '|';
    game[x - 13][y + 26] = '`';
    game[x - 13][y + 27] = '\\';
    game[x - 13][y + 29] = '\\';
    game[x - 13][y + 30] = '_';
    game[x - 13][y + 33] = '\\';
    game[x - 13][y + 36] = '\\';
    game[x - 13][y + 41] = '|';
    game[x - 13][y + 44] = '/';
    game[x - 12][y + 28] = ';';
    game[x - 12][y + 29] = '\\';
    game[x - 12][y + 32] = '\\';
    game[x - 12][y + 33] = '_';
    game[x - 12][y + 34] = '\\';
    game[x - 12][y + 37] = '\\';
    game[x - 12][y + 40] = '/';
    game[x - 12][y + 43] = '/';
    game[x - 11][y + 31] = '\\';
    game[x - 11][y + 38] = '|';
    game[x - 11][y + 39] = '/';
    game[x - 11][y + 42] = '/';
    game[x - 10][y + 32] = '|';
    game[x - 10][y + 41] = '|';
    game[x - 9][y + 32] = '|';
    game[x - 9][y + 41] = '|';
    game[x - 9][y + 44] = '/';
    game[x - 9][y + 45] = '/';
    game[x - 8][y + 32] = '|';
    game[x - 8][y + 41] = ';';
    game[x - 8][y + 42] = '_';
    game[x - 8][y + 43] = '/';
    game[x - 8][y + 44] = '/';
    game[x - 8][y + 46] = '.';
    game[x - 8][y + 48] = '\'';
    game[x - 7][y + 28] = '_';
    game[x - 7][y + 32] = '|';
    game[x - 7][y + 42] = '_';
    game[x - 7][y + 43] = '/';
    game[x - 7][y + 44] = '.';
    game[x - 7][y + 45] = ',';
    game[x - 7][y + 46] = '\'';
    game[x - 6][y + 26] = '`';
    game[x - 6][y + 27] = '.';
    game[x - 6][y + 29] = '\\';
    game[x - 6][y + 30] = '\\';
    game[x - 6][y + 31] = '_';
    game[x - 6][y + 32] = '|';
    game[x - 6][y + 41] = '|';
    game[x - 5][y + 29] = '`';
    game[x - 5][y + 30] = '\\';
    game[x - 5][y + 31] = '_';
    game[x - 5][y + 41] = '|';
    game[x - 4][y + 32] = '|';
    game[x - 4][y + 41] = '|';
    game[x - 3][y + 32] = '|';
    game[x - 3][y + 41] = '|';
    game[x - 2][y + 32] = '|';
    game[x - 2][y + 41] = '|';
    game[x - 1][y + 32] = '|';
    game[x - 1][y + 41] = '|';
    game[x][y + 32] = '|';
    game[x][y + 41] = '|';
    game[x + 1][y + 32] = '|';
    game[x + 1][y + 41] = '|';
    game[x + 2][y + 32] = '|';
    game[x + 2][y + 41] = '|';
    game[x + 3][y + 32] = '|';
    game[x + 3][y + 41] = '|';
    game[x + 4][y + 32] = '|';
    game[x + 4][y + 41] = '|';
    game[x + 5][y + 32] = '|';
    game[x + 5][y + 41] = '|';
    game[x + 6][y + 31] = '/';
    game[x + 6][y + 42] = '\\';
    game[x + 6][y + 30] = '/';
    game[x + 6][y + 43] = '\\';
    //------------------------------spider
    /*x = 52, y = 197;
    game[x - 5][y + 4] = '|';
    game[x - 4][y + 4] = '|';
    game[x - 6][y + 4] = '|';
    game[x - 7][y + 4] = '|';

    game[x - 3][y + 2] = '/';
    game[x - 3][y + 6] = '\\';
    game[x - 2][y + 0] = '\\';
    game[x - 2][y + 1] = '_';
    game[x - 2][y + 2] = '\\';
    game[x - 2][y + 3] = '(';
    game[x - 2][y + 4] = '_';
    game[x - 2][y + 5] = ')';
    game[x - 2][y + 6] = '/';
    game[x - 2][y + 7] = '_';
    game[x - 2][y + 8] = '/';
    game[x - 1][y + 1] = '_';
    game[x - 1][y + 2] = '/';
    game[x - 1][y + 3] = '/';
    game[x - 1][y + 4] = 'o';
    game[x - 1][y + 5] = '\\';
    game[x - 1][y + 6] = '\\';
    game[x - 1][y + 7] = '_';
    game[x - 0][y + 2] = '/';
    game[x - 0][y + 6] = '\\';*/
    //--------------------------------------shouk bbigg
    x = 72, y = 300;
    game[x - 18][y + 73] = '/';
    game[x - 18][y + 74] = '/';
    game[x - 18][y + 75] = '\\';
    game[x - 17][y + 72] = '/';
    game[x - 17][y + 76] = '\\';
    game[x - 16][y + 44] = '/';
    game[x - 16][y + 45] = '\\';
    game[x - 16][y + 71] = '/';
    game[x - 16][y + 77] = '\\';
    game[x - 16][y + 78] = '\\';
    game[x - 15][y + 43] = '/';
    game[x - 15][y + 46] = '\\';
    game[x - 15][y + 70] = '/';
    game[x - 15][y + 79] = '\\';
    game[x - 14][y + 42] = '/';
    game[x - 14][y + 47] = '\\';
    game[x - 14][y + 69] = '/';
    game[x - 14][y + 80] = '\\';
    game[x - 14][y + 106] = '/';
    game[x - 14][y + 107] = '\\';
    game[x - 13][y + 25] = '/';
    game[x - 13][y + 26] = '\\';
    game[x - 13][y + 39] = '/';
    game[x - 13][y + 40] = '/';
    game[x - 13][y + 41] = '/';
    game[x - 13][y + 47] = '\\';
    game[x - 13][y + 48] = '\\';
    game[x - 13][y + 49] = '\\';
    game[x - 13][y + 67] = '/';
    game[x - 13][y + 68] = '/';
    game[x - 13][y + 69] = '/';
    game[x - 13][y + 81] = '\\';
    game[x - 13][y + 82] = '\\';
    game[x - 13][y + 104] = '/';
    game[x - 13][y + 105] = '/';
    game[x - 13][y + 108] = '\\';
    game[x - 12][y + 24] = '/';
    game[x - 12][y + 27] = '\\';
    game[x - 12][y + 38] = '/';
    game[x - 12][y + 49] = '\\';
    game[x - 12][y + 66] = '/';
    game[x - 12][y + 83] = '\\';
    game[x - 12][y + 102] = '/';
    game[x - 12][y + 103] = '/';
    game[x - 12][y + 108] = '\\';
    game[x - 12][y + 109] = '\\';
    game[x - 11][y + 15] = '/';
    game[x - 11][y + 16] = '\\';
    game[x - 11][y + 23] = '/';
    game[x - 11][y + 28] = '\\';
    game[x - 11][y + 36] = '/';
    game[x - 11][y + 37] = '/';
    game[x - 11][y + 50] = '\\';
    game[x - 11][y + 65] = '/';
    game[x - 11][y + 84] = '\\';
    game[x - 11][y + 99] = '/';
    game[x - 11][y + 100] = '/';
    game[x - 11][y + 110] = '\\';
    game[x - 10][y + 14] = '/';
    game[x - 10][y + 16] = '\\';
    game[x - 10][y + 21] = '/';
    game[x - 10][y + 22] = '/';
    game[x - 10][y + 29] = '\\';
    game[x - 10][y + 34] = '/';
    game[x - 10][y + 35] = '/';
    game[x - 10][y + 51] = '\\';
    game[x - 10][y + 63] = '/';
    game[x - 10][y + 64] = '/';
    game[x - 10][y + 85] = '\\';
    game[x - 10][y + 97] = '/';
    game[x - 10][y + 98] = '/';
    game[x - 10][y + 111] = '\\';
    game[x - 10][y + 125] = '/';
    game[x - 10][y + 126] = '\\';
    game[x - 9][y + 13] = '/';
    game[x - 9][y + 18] = '\\';
    game[x - 9][y + 19] = '/';
    game[x - 9][y + 20] = '/';
    game[x - 9][y + 30] = '\\';
    game[x - 9][y + 31] = '\\';
    game[x - 9][y + 33] = '/';
    game[x - 9][y + 52] = '\\';
    game[x - 9][y + 62] = '/';
    game[x - 9][y + 85] = '\\';
    game[x - 9][y + 86] = '\\';
    game[x - 9][y + 96] = '/';
    game[x - 9][y + 112] = '\\';
    game[x - 9][y + 124] = '/';
    game[x - 9][y + 127] = '\\';
    game[x - 8][y + 12] = '/';
    game[x - 8][y + 18] = '/';
    game[x - 8][y + 31] = '\\';
    game[x - 8][y + 32] = '/';
    game[x - 8][y + 53] = '\\';
    game[x - 8][y + 54] = '\\';
    game[x - 8][y + 55] = '\\';
    game[x - 8][y + 60] = '/';
    game[x - 8][y + 61] = '/';
    game[x - 8][y + 87] = '\\';
    game[x - 8][y + 95] = '/';
    game[x - 8][y + 113] = '\\';
    game[x - 8][y + 122] = '/';
    game[x - 8][y + 123] = '/';
    game[x - 8][y + 128] = '\\';
    game[x - 7][y + 7] = '/';
    game[x - 7][y + 8] = '\\';
    game[x - 7][y + 11] = '/';
    game[x - 7][y + 17] = '/';
    game[x - 7][y + 32] = '\\';
    game[x - 7][y + 56] = '\\';
    game[x - 7][y + 59] = '/';
    game[x - 7][y + 88] = '\\';
    game[x - 7][y + 89] = '\\';
    game[x - 7][y + 90] = '\\';
    game[x - 7][y + 93] = '/';
    game[x - 7][y + 94] = '/';
    game[x - 7][y + 114] = '\\';
    game[x - 7][y + 121] = '/';
    game[x - 7][y + 129] = '\\';
    game[x - 6][y + 6] = '/';
    game[x - 6][y + 9] = '\\';
    game[x - 6][y + 10] = '/';
    game[x - 6][y + 15] = '/';
    game[x - 6][y + 16] = '/';
    game[x - 6][y + 33] = '\\';
    game[x - 6][y + 34] = '\\';
    game[x - 6][y + 57] = '\\';
    game[x - 6][y + 58] = '/';
    game[x - 6][y + 90] = '\\';
    game[x - 6][y + 93] = '/';
    game[x - 6][y + 115] = '\\';
    game[x - 6][y + 116] = '\\';
    game[x - 6][y + 120] = '/';
    game[x - 6][y + 130] = '\\';
    game[x - 5][y + 5] = '/';
    game[x - 5][y + 10] = '\\';
    game[x - 5][y + 13] = '/';
    game[x - 5][y + 34] = '\\';
    game[x - 5][y + 35] = '\\';
    game[x - 5][y + 57] = '\\';
    game[x - 5][y + 58] = '\\';
    game[x - 5][y + 59] = '\\';
    game[x - 5][y + 91] = '\\';
    game[x - 5][y + 92] = '/';
    game[x - 5][y + 117] = '\\';
    game[x - 5][y + 118] = '/';
    game[x - 5][y + 119] = '/';
    game[x - 5][y + 130] = '\\';
    game[x - 5][y + 131] = '\\';
    game[x - 4][y + 4] = '/';
    game[x - 4][y + 11] = '\\';
    game[x - 4][y + 12] = '/';
    game[x - 4][y + 35] = '\\';
    game[x - 4][y + 59] = '\\';
    game[x - 4][y + 60] = '\\';
    game[x - 4][y + 91] = '/';
    game[x - 4][y + 92] = '/';
    game[x - 4][y + 118] = '\\';
    game[x - 4][y + 132] = '\\';
    game[x - 3][y + 3] = '/';
    game[x - 3][y + 12] = '\\';
    game[x - 3][y + 36] = '\\';
    game[x - 3][y + 59] = '\\';
    game[x - 3][y + 60] = '\\';
    game[x - 3][y + 91] = '/';
    game[x - 3][y + 119] = '\\';
    game[x - 3][y + 133] = '\\';
    game[x - 2][y + 2] = '/';
    game[x - 2][y + 13] = '\\';
    game[x - 2][y + 36] = '\\';
    game[x - 2][y + 37] = '\\';
    game[x - 2][y + 61] = '\\';
    game[x - 2][y + 63] = '\\';
    game[x - 2][y + 64] = '\\';
    game[x - 2][y + 90] = '/';
    game[x - 2][y + 91] = '/';
    game[x - 2][y + 120] = '\\';
    game[x - 2][y + 134] = '\\';
    game[x - 1][y + 0] = '/';
    game[x - 1][y + 1] = '/';
    game[x - 1][y + 14] = '\\';
    game[x - 1][y + 38] = '\\';
    game[x - 1][y + 40] = '\\';
    game[x - 1][y + 62] = '\\';
    game[x - 1][y + 90] = '/';
    game[x - 1][y + 91] = '/';
    game[x - 1][y + 135] = '\\';
    game[x - 0][y + 0] = '/';
    game[x - 0][y + 1] = '_';
    game[x - 0][y + 2] = '_';
    game[x - 0][y + 3] = '_';
    game[x - 0][y + 4] = '_';
    game[x - 0][y + 5] = '_';
    game[x - 0][y + 6] = '_';
    game[x - 0][y + 7] = '_';
    game[x - 0][y + 8] = '_';
    game[x - 0][y + 9] = '_';
    game[x - 0][y + 10] = '_';
    game[x - 0][y + 11] = '_';
    game[x - 0][y + 12] = '_';
    game[x - 0][y + 13] = '_';
    game[x - 0][y + 14] = '_';
    game[x - 0][y + 15] = '_';
    game[x - 0][y + 16] = '_';
    game[x - 0][y + 17] = '_';
    game[x - 0][y + 18] = '_';
    game[x - 0][y + 19] = '_';
    game[x - 0][y + 20] = '_';
    game[x - 0][y + 21] = '_';
    game[x - 0][y + 22] = '_';
    game[x - 0][y + 23] = '_';
    game[x - 0][y + 24] = '_';
    game[x - 0][y + 25] = '_';
    game[x - 0][y + 26] = '_';
    game[x - 0][y + 27] = '_';
    game[x - 0][y + 28] = '_';
    game[x - 0][y + 29] = '_';
    game[x - 0][y + 30] = '_';
    game[x - 0][y + 31] = '_';
    game[x - 0][y + 32] = '_';
    game[x - 0][y + 33] = '_';
    game[x - 0][y + 34] = '_';
    game[x - 0][y + 35] = '_';
    game[x - 0][y + 36] = '_';
    game[x - 0][y + 37] = '_';
    game[x - 0][y + 38] = '_';
    game[x - 0][y + 39] = '_';
    game[x - 0][y + 40] = '_';
    game[x - 0][y + 41] = '_';
    game[x - 0][y + 42] = '_';
    game[x - 0][y + 43] = '_';
    game[x - 0][y + 44] = '_';
    game[x - 0][y + 45] = '_';
    game[x - 0][y + 46] = '_';
    game[x - 0][y + 47] = '_';
    game[x - 0][y + 48] = '_';
    game[x - 0][y + 49] = '_';
    game[x - 0][y + 50] = '_';
    game[x - 0][y + 51] = '_';
    game[x - 0][y + 52] = '_';
    game[x - 0][y + 53] = '_';
    game[x - 0][y + 54] = '_';
    game[x - 0][y + 55] = '_';
    game[x - 0][y + 56] = '_';
    game[x - 0][y + 57] = '_';
    game[x - 0][y + 58] = '_';
    game[x - 0][y + 59] = '_';
    game[x - 0][y + 60] = '_';
    game[x - 0][y + 61] = '_';
    game[x - 0][y + 62] = '_';
    game[x - 0][y + 63] = '_';
    game[x - 0][y + 64] = '_';
    game[x - 0][y + 65] = '_';
    game[x - 0][y + 66] = '_';
    game[x - 0][y + 67] = '_';
    game[x - 0][y + 68] = '_';
    game[x - 0][y + 69] = '_';
    game[x - 0][y + 70] = '_';
    game[x - 0][y + 71] = '_';
    game[x - 0][y + 72] = '_';
    game[x - 0][y + 73] = '_';
    game[x - 0][y + 74] = '_';
    game[x - 0][y + 75] = '_';
    game[x - 0][y + 76] = '_';
    game[x - 0][y + 77] = '_';
    game[x - 0][y + 78] = '_';
    game[x - 0][y + 79] = '_';
    game[x - 0][y + 80] = '_';
    game[x - 0][y + 81] = '_';
    game[x - 0][y + 82] = '_';
    game[x - 0][y + 83] = '_';
    game[x - 0][y + 84] = '_';
    game[x - 0][y + 85] = '_';
    game[x - 0][y + 86] = '_';
    game[x - 0][y + 87] = '_';
    game[x - 0][y + 88] = '_';
    game[x - 0][y + 89] = '_';
    game[x - 0][y + 90] = '_';
    game[x - 0][y + 91] = '_';
    game[x - 0][y + 92] = '_';
    game[x - 0][y + 93] = '_';
    game[x - 0][y + 94] = '_';
    game[x - 0][y + 95] = '_';
    game[x - 0][y + 96] = '_';
    game[x - 0][y + 97] = '_';
    game[x - 0][y + 98] = '_';
    game[x - 0][y + 99] = '_';
    game[x - 0][y + 100] = '_';
    game[x - 0][y + 101] = '_';
    game[x - 0][y + 102] = '_';
    game[x - 0][y + 103] = '_';
    game[x - 0][y + 104] = '_';
    game[x - 0][y + 105] = '_';
    game[x - 0][y + 106] = '_';
    game[x - 0][y + 107] = '_';
    game[x - 0][y + 108] = '_';
    game[x - 0][y + 109] = '_';
    game[x - 0][y + 110] = '_';
    game[x - 0][y + 111] = '_';
    game[x - 0][y + 112] = '_';
    game[x - 0][y + 113] = '_';
    game[x - 0][y + 114] = '_';
    game[x - 0][y + 115] = '_';
    game[x - 0][y + 116] = '_';
    game[x - 0][y + 117] = '_';
    game[x - 0][y + 118] = '_';
    game[x - 0][y + 119] = '_';
    game[x - 0][y + 120] = '_';
    game[x - 0][y + 121] = '_';
    game[x - 0][y + 122] = '_';
    game[x - 0][y + 123] = '_';
    game[x - 0][y + 124] = '_';
    game[x - 0][y + 125] = '_';
    game[x - 0][y + 126] = '_';
    game[x - 0][y + 127] = '_';
    game[x - 0][y + 128] = '_';
    game[x - 0][y + 129] = '_';
    game[x - 0][y + 130] = '_';
    game[x - 0][y + 131] = '_';
    game[x - 0][y + 132] = '_';
    game[x - 0][y + 133] = '_';
    game[x - 0][y + 134] = '_';
    game[x - 0][y + 135] = '_';
    game[x - 0][y + 136] = '\\';
    //---------------------------------ladder
    c = 751;
    for (int r = 73; r > 45; r--) {

        game[r][c] = 185;
        game[r][c + 1] = 205;
        game[r][c + 2] = 205;
        game[r][c + 3] = 205;
        game[r][c + 4] = 205;
        game[r][c + 5] = 205;
        game[r][c + 6] = 205;
        game[r][c + 7] = 204;

    }

    //   //------------------------------------uper ground
    //   r = 45, c = 650;
    //   for (int j = 0; j < 29; j++) {
    //       for (int i = 0; i < 41; i++) {
    //           game[r + j][c + i] = '_';
    //       }
    //   }

    //   for (int j = 1; j < 29; j += 2) {
    //       for (int i = 0; i < 41; i++) {
    //           if (i % 5 == 0) {
    //               game[r + j][c + i] = '|';
    //           }
    //       }
    //   }

    //   for (int j = 2; j < 29; j += 2) {
    //       for (int i = 0; i < 41; i++) {
    //           if ((i % 5) - 2 == 0) {
    //               game[r + j][c + i] = '|';
    //           }
    //       }
    //   }

    //   for (int i = r + 1; i < 74; i += 2) {
    //       game[i][c + 40] = '|';
    //   }

    //   //-------------------------------------uper ground 2
    //r = 45, c = 692;
    //   for (int j = 0; j < 29; j++) {
    //       for (int i = 0; i < 41; i++) {
    //           game[r + j][c + i] = '_';
    //       }
    //   }

    //   for (int j = 1; j < 29; j += 2) {
    //       for (int i = 0; i < 41; i++) {
    //           if (i % 5 == 0) {
    //               game[r + j][c + i] = '|';
    //           }
    //       }
    //   }

    //   for (int j = 2; j < 29; j += 2) {
    //       for (int i = 0; i < 41; i++) {
    //           if ((i % 5) - 2 == 0) {
    //               game[r + j][c + i] = '|';
    //           }
    //       }
    //   }

    //   for (int i = r + 1; i < 74; i += 2) {
    //       game[i][c + 40] = '|';
    //   }

    r = 73, c = 650;
    for (int i = r; i > 45; i--) {
        game[i][750] = 179;
    }
    for (int i = c; i < c + 63; i += 7) {
        for (int j = 0; j < 3; j++) {
            game[r--][i] = '|';
        }
    }
    //------------------------------------
    x = 73, y = 651;
    for (int i = x - 3; i > 45; i -= 3) {
        for (int j = y; j < 750; j++) {
            game[i][j] = 'W';
            game[i][j] = 'W';
            game[i][j] = 'W';
            game[i][j] = 'w';
            game[i][j] = 'w';
            game[i][j] = 'W';
            game[i][j] = 'W';
            
        }
        y += 7;
    }
    //----------------------------------------
    r = 46;
    for (int i = 713; i < 751; i += 2) {
        game[r][i] = 'w';
        game[r][i + 1] = 'W';
    }
    for (int i = 718; i < 751; i += 7) {
        game[r - 1][i] = '\\';
        game[r - 1][i + 1] = '\\';
        game[r - 1][i + 2] = '/';
        game[r - 1][i + 3] = '/';
    }
}
void drawSpider(char game[][950], int x, int y) {
    // x = 52, y = 197;
    game[x - 5][y + 4] = '|';
    game[x - 4][y + 4] = '|';
    game[x - 6][y + 4] = '|';
    game[x - 7][y + 4] = '|';

    game[x - 3][y + 2] = '/';
    game[x - 3][y + 6] = '\\';
    game[x - 2][y + 0] = '\\';
    game[x - 2][y + 1] = '_';
    game[x - 2][y + 2] = '\\';
    game[x - 2][y + 3] = '(';
    game[x - 2][y + 4] = '_';
    game[x - 2][y + 5] = ')';
    game[x - 2][y + 6] = '/';
    game[x - 2][y + 7] = '_';
    game[x - 2][y + 8] = '/';
    game[x - 1][y + 1] = '_';
    game[x - 1][y + 2] = '/';
    game[x - 1][y + 3] = '/';
    game[x - 1][y + 4] = 'o';
    game[x - 1][y + 5] = '\\';
    game[x - 1][y + 6] = '\\';
    game[x - 1][y + 7] = '_';
    game[x - 0][y + 2] = '/';
    game[x - 0][y + 6] = '\\';

}
void drawshouk1(char game[][950]) {
    int r = 72, c = 50;
    game[r - 3][c + 4] = '/';
    game[r - 3][c + 5] = '\\';
    game[r - 2][c + 3] = '/';
    game[r - 2][c + 6] = '\\';
    game[r - 1][c + 2] = '/';
    game[r - 1][c + 7] = '\\';
    game[r - 0][c + 1] = '/';
    game[r - 0][c + 8] = '\\';

}
void checkshook1(int xh, int yh, int xshook, int yshook, int& F, int& health) {

    if (yh >= 37 && yh <= 50 && xh >= 70) {
        health -= 20;
        if (health <= 0)
            F = 0;
    }
}

void checkshook2(int xh, int yh, int xshook, int yshook, int& F, int& health) {
    if (yh >= 69 && yh <= 83 && xh >= 70) {
        health -= 20;
        if (health <= 0)
            F = 0;
    }
}
void checkBigshook(int xh, int yh, int xshook, int yshook, int& F, int& health) {
    if (yh >= 300 && yh <= 429 && xh >= 60) {
        health -= 20;
        if (health <= 0)
            F = 0;
    }
}

void drawshouk2(char game[][950]) {
    int r = 72, c = 51;
    game[r - 3][c + 41] = '/';
    game[r - 3][c + 42] = '\\';
    game[r - 2][c + 40] = '/';
    game[r - 2][c + 43] = '\\';
    game[r - 1][c + 39] = '/';
    game[r - 1][c + 44] = '\\';
    game[r - 0][c + 38] = '/';
    game[r - 0][c + 45] = '\\';
}

void drawhero(char game[][950], int x, int y) {
    game[x - 15][y + 15] = '_';
    game[x - 15][y + 16] = '_';
    game[x - 14][y + 14] = '/';
    game[x - 14][y + 17] = 92;
    game[x - 13][y + 13] = '/';
    game[x - 13][y + 15] = '_';
    game[x - 13][y + 16] = '/';
    game[x - 13][y + 17] = 92;
    game[x - 13][y + 18] = 92;
    game[x - 12][y + 11] = '_';
    game[x - 12][y + 12] = '<';
    game[x - 12][y + 14] = '<';
    game[x - 12][y + 15] = '_';
    game[x - 12][y + 16] = '_';
    game[x - 12][y + 17] = '_';
    game[x - 12][y + 18] = '>';
    game[x - 12][y + 19] = '>';
    game[x - 11][y + 8] = '_';
    game[x - 11][y + 9] = '_';
    game[x - 11][y + 10] = '/';
    game[x - 10][y + 19] = 92;
    /*  game[x - 10][y + 0] = '_';*/
    /* game[x - 10][y + 1] = '_';*/
    game[x - 10][y + 6] = '_';
    game[x - 10][y + 7] = '/';
    game[x - 10][y + 9] = '_';
    game[x - 10][y + 20] = '>';
    /* game[x - 9][y + 1] = 92;
     game[x - 9][y + 2] = 39;
     game[x - 9][y + 3] = '_';
     game[x - 9][y + 4] = '_';
     game[x - 9][y + 5] = 39;
     game[x - 9][y + 7] = '-';
     game[x - 9][y + 8] = 39;
     game[x - 9][y + 9] = '/';*/
    game[x - 9][y + 10] = 39;
    game[x - 9][y + 12] = '.';
    game[x - 9][y + 13] = '_';
    game[x - 9][y + 14] = '_';
    game[x - 9][y + 15] = '_';
    game[x - 9][y + 16] = '.';
    game[x - 9][y + 17] = '_';
    game[x - 9][y + 18] = '-';
    game[x - 9][y + 19] = 39;
    game[x - 8][y + 8] = '/';
    game[x - 8][y + 9] = '/';
    game[x - 8][y + 17] = '<';
    game[x - 8][y + 18] = 39;
    game[x - 8][y + 19] = '|';
    game[x - 8][y + 20] = '|';
    game[x - 7][y + 7] = '/';
    game[x - 7][y + 8] = '/';
    game[x - 7][y + 9] = '>';
    game[x - 7][y + 10] = '_';
    game[x - 7][y + 11] = '_';
    game[x - 7][y + 12] = 249;
    game[x - 7][y + 13] = 196;
    game[x - 7][y + 14] = 196;
    game[x - 7][y + 15] = 196;
    game[x - 7][y + 16] = 39;
    game[x - 7][y + 18] = '>';
    game[x - 7][y + 19] = '|';
    game[x - 7][y + 20] = ':';
    game[x - 6][y + 9] = '|';
    game[x - 6][y + 18] = 92;
    game[x - 5][y + 9] = ':';
    game[x - 5][y + 15] = '_';
    game[x - 5][y + 19] = 92;
    game[x - 4][y + 9] = '>';
    game[x - 4][y + 12] = '_';
    game[x - 4][y + 14] = '/';
    game[x - 4][y + 16] = 92;
    game[x - 4][y + 20] = 92;
    game[x - 4][y + 8] = '<';
    game[x - 4][y + 11] = '/';
    game[x - 4][y + 17] = 92;
    game[x - 4][y + 21] = '>';
    game[x - 3][y + 8] = '|';
    game[x - 3][y + 11] = '>';
    game[x - 3][y + 18] = '>';
    game[x - 3][y + 20] = '/';
    game[x - 2][y + 8] = 179;
    game[x - 2][y + 10] = 179;
    game[x - 2][y + 19] = 179;
    game[x - 2][y + 19] = '<';
    game[x - 1][y + 8] = 179;
    game[x - 1][y + 9] = 179;
    game[x - 1][y + 18] = 179;
    game[x - 1][y + 19] = 179;
    game[x][y + 18] = 179;
    game[x][y + 19] = '_';
    game[x][y + 20] = 92;
    game[x][y + 8] = '|';
    game[x][y + 9] = '_';
    game[x][y + 10] = 92;
}

void drawEnmy(char game[][950], int& x, int& y) {

    game[x - 16][y + 10] = '(';
    game[x - 16][y + 11] = 'o';
    game[x - 16][y + 12] = ')';
    game[x - 16][y + 17] = '(';
    game[x - 16][y + 18] = 'o';
    game[x - 16][y + 19] = ')';
    game[x - 15][y + 12] = '\\';
    game[x - 15][y + 17] = '/';
    game[x - 14][y + 3] = '/';
    game[x - 14][y + 4] = '\\';
    game[x - 14][y + 13] = '\\';
    game[x - 14][y + 16] = '/';
    game[x - 13][y + 3] = '|';
    game[x - 13][y + 4] = '|';
    game[x - 13][y + 13] = '-';
    game[x - 13][y + 14] = '-';
    game[x - 13][y + 15] = '-';
    game[x - 13][y + 16] = '-';
    game[x - 12][y + 3] = '|';
    game[x - 12][y + 4] = '|';
    game[x - 12][y + 12] = '/';
    game[x - 12][y + 13] = '(';
    game[x - 12][y + 14] = 'o';
    game[x - 12][y + 15] = ')';
    game[x - 12][y + 17] = '\\';
    game[x - 11][y + 3] = '|';
    game[x - 11][y + 4] = '|';
    game[x - 11][y + 11] = '(';
    game[x - 11][y + 14] = '<';
    game[x - 11][y + 18] = ')';
    game[x - 10][y + 3] = '|';
    game[x - 10][y + 4] = '|';
    game[x - 10][y + 12] = '\\';
    game[x - 10][y + 14] = '-';
    game[x - 10][y + 15] = '-';
    game[x - 10][y + 17] = '/';
    game[x - 9][y + 0] = '/';
    game[x - 9][y + 1] = '|';
    game[x - 9][y + 2] = '_';
    game[x - 9][y + 3] = '|';
    game[x - 9][y + 4] = '|';
    game[x - 9][y + 5] = '_';
    game[x - 9][y + 6] = '|';
    game[x - 9][y + 7] = '\\';
    game[x - 9][y + 8] = '_';
    game[x - 9][y + 9] = '_';
    game[x - 9][y + 10] = '(';
    game[x - 9][y + 11] = '-';
    game[x - 9][y + 12] = '-';
    game[x - 9][y + 13] = '=';
    game[x - 9][y + 14] = '=';
    game[x - 9][y + 15] = '=';
    game[x - 9][y + 16] = '=';
    game[x - 9][y + 17] = '-';
    game[x - 9][y + 18] = '-';
    game[x - 9][y + 19] = ')';
    game[x - 8][y + 2] = '(';
    game[x - 8][y + 3] = '|';
    game[x - 8][y + 4] = '_';
    game[x - 8][y + 5] = '_';
    game[x - 8][y + 6] = '_';
    game[x - 8][y + 7] = '_';
    game[x - 8][y + 8] = '_';
    game[x - 8][y + 9] = '_';
    game[x - 8][y + 10] = '_';
    game[x - 8][y + 11] = '\\';
    game[x - 8][y + 12] = '=';
    game[x - 8][y + 13] = '=';
    game[x - 8][y + 14] = '=';
    game[x - 8][y + 15] = '=';
    game[x - 8][y + 16] = '=';
    game[x - 8][y + 17] = '=';
    game[x - 8][y + 18] = '/';
    game[x - 8][y + 19] = '\\';
    game[x - 8][y + 21] = '\\';
    game[x - 8][y + 22] = '[';
    game[x - 8][y + 23] = '[';
    game[x - 8][y + 24] = '/';
    game[x - 7][y + 3] = '|';
    game[x - 7][y + 4] = '|';
    game[x - 7][y + 13] = '(';
    game[x - 7][y + 14] = '-';
    game[x - 7][y + 15] = '-';
    game[x - 7][y + 16] = ')';
    game[x - 7][y + 18] = '\\';
    game[x - 7][y + 20] = '\\';
    game[x - 7][y + 21] = '/';
    game[x - 7][y + 23] = '/';
    game[x - 6][y + 13] = '/';
    game[x - 6][y + 16] = '\\';
    game[x - 6][y + 19] = '\\';
    game[x - 6][y + 20] = '_';
    game[x - 6][y + 21] = '-';
    game[x - 6][y + 22] = '/';
    game[x - 5][y + 12] = '|';
    game[x - 5][y + 13] = '=';
    game[x - 5][y + 14] = '=';
    game[x - 5][y + 15] = '=';
    game[x - 5][y + 16] = '=';
    game[x - 5][y + 17] = '|';
    game[x - 4][y + 11] = '(';
    game[x - 4][y + 14] = '/';
    game[x - 4][y + 15] = '\\';
    game[x - 4][y + 18] = ')';
    game[x - 3][y + 11] = '|';
    game[x - 3][y + 14] = ')';
    game[x - 3][y + 15] = '(';
    game[x - 3][y + 18] = '|';
    game[x - 2][y + 11] = '[';
    game[x - 2][y + 14] = ']';
    game[x - 2][y + 15] = '[';
    game[x - 2][y + 18] = ']';
    game[x - 1][y + 11] = '_';
    game[x - 1][y + 12] = '|';
    game[x - 1][y + 13] = '|';
    game[x - 1][y + 16] = '|';
    game[x - 1][y + 17] = '|';
    game[x - 1][y + 18] = '_';
    game[x - 0][y + 10] = '(';
    game[x - 0][y + 14] = ']';
    game[x - 0][y + 15] = '[';
    game[x - 0][y + 19] = ')';
}
void checkEnmy(int& xh, int& yh, int xe, int ye, int& F, int& health) {
    if (yh + 18 >= ye + 2 && xh - 15 >= xe - 16 && yh <= ye + 20) {
        // xh -= 3;
        // yh -= 5;
        health -= 35;
        if (health <= 0)
            F = 0;
    }
}

void drawLaser(char game[][950]) {
    int r = 30, c = 510;
    for (int i = r + 2; i < 74; i++) {
        game[i][c] = 179;
    }
}

void drawelevator(int r, int c, char game[][950]) {

    game[r][c] = 218;
    game[r + 1][c] = 192;
    game[r][c + 1] = 196;
    game[r][c + 2] = 196;
    game[r][c + 3] = 196;
    game[r][c + 4] = 196;
    game[r][c + 5] = 196;
    game[r][c + 6] = 196;
    game[r][c + 7] = 196;
    game[r][c + 8] = 196;
    game[r][c + 9] = 196;
    game[r][c + 10] = 196;
    game[r][c + 11] = 196;
    game[r][c + 12] = 196;
    game[r][c + 13] = 196;
    game[r][c + 14] = 196;
    game[r][c + 15] = 196;
    game[r][c + 16] = 196;
    game[r][c + 17] = 196;
    game[r][c + 18] = 191;
    game[r + 1][c + 1] = 196;
    game[r + 1][c + 2] = 196;
    game[r + 1][c + 3] = 196;
    game[r + 1][c + 4] = 196;
    game[r + 1][c + 5] = 196;
    game[r + 1][c + 6] = 196;
    game[r + 1][c + 7] = 196;
    game[r + 1][c + 8] = 196;
    game[r + 1][c + 9] = 196;
    game[r + 1][c + 10] = 196;
    game[r + 1][c + 11] = 196;
    game[r + 1][c + 12] = 196;
    game[r + 1][c + 13] = 196;
    game[r + 1][c + 14] = 196;
    game[r + 1][c + 15] = 196;
    game[r + 1][c + 16] = 196;
    game[r + 1][c + 17] = 196;
    game[r + 1][c + 18] = 217;
}

void drawelevator2(int r, int c, char game[][950]) {

    game[r][c] = 218;
    game[r + 1][c] = 192;
    game[r][c + 1] = 196;
    game[r][c + 2] = 196;
    game[r][c + 3] = 196;
    game[r][c + 4] = 196;
    game[r][c + 5] = 196;
    game[r][c + 6] = 196;
    game[r][c + 7] = 196;
    game[r][c + 8] = 196;
    game[r][c + 9] = 196;
    game[r][c + 10] = 196;
    game[r][c + 11] = 196;
    game[r][c + 12] = 196;
    game[r][c + 13] = 196;
    game[r][c + 14] = 196;
    game[r][c + 15] = 196;
    game[r][c + 16] = 196;
    game[r][c + 17] = 196;
    game[r][c + 18] = 191;
    game[r + 1][c + 1] = 196;
    game[r + 1][c + 2] = 196;
    game[r + 1][c + 3] = 196;
    game[r + 1][c + 4] = 196;
    game[r + 1][c + 5] = 196;
    game[r + 1][c + 6] = 196;
    game[r + 1][c + 7] = 196;
    game[r + 1][c + 8] = 196;
    game[r + 1][c + 9] = 196;
    game[r + 1][c + 10] = 196;
    game[r + 1][c + 11] = 196;
    game[r + 1][c + 12] = 196;
    game[r + 1][c + 13] = 196;
    game[r + 1][c + 14] = 196;
    game[r + 1][c + 15] = 196;
    game[r + 1][c + 16] = 196;
    game[r + 1][c + 17] = 196;
    game[r + 1][c + 18] = 217;
}
void drawDragon(char game[][950], int& x, int& y) {

    game[x - 21][y + 19] = '(';
    game[x - 21][y + 24] = ')';
    game[x - 20][y + 18] = '(';
    game[x - 20][y + 19] = '(';
    game[x - 20][y + 20] = '(';
    game[x - 20][y + 21] = '(';
    game[x - 20][y + 22] = '(';
    game[x - 20][y + 23] = ')';
    game[x - 20][y + 24] = ')';
    game[x - 20][y + 25] = ')';
    game[x - 19][y + 18] = '|';
    game[x - 19][y + 19] = 'o';
    game[x - 19][y + 20] = '\\';
    game[x - 19][y + 22] = '/';
    game[x - 19][y + 23] = 'o';
    game[x - 19][y + 24] = ')';
    game[x - 19][y + 25] = '|';
    game[x - 18][y + 18] = '(';
    game[x - 18][y + 20] = '(';
    game[x - 18][y + 23] = '_';
    game[x - 18][y + 24] = '\'';
    game[x - 18][y + 25] = ')';
    game[x - 17][y + 19] = '(';
    game[x - 17][y + 20] = '.';
    game[x - 17][y + 21] = '_';
    game[x - 17][y + 22] = '.';
    game[x - 17][y + 25] = '/';
    game[x - 17][y + 26] = '\\';
    game[x - 17][y + 27] = '_';
    game[x - 17][y + 28] = '_';
    game[x - 16][y + 18] = ',';
    game[x - 16][y + 19] = '\\';
    game[x - 16][y + 20] = '_';
    game[x - 16][y + 21] = '_';
    game[x - 16][y + 22] = '_';
    game[x - 16][y + 23] = ',';
    game[x - 16][y + 24] = '/';
    game[x - 16][y + 26] = '\'';
    game[x - 16][y + 29] = '\'';
    game[x - 16][y + 30] = ')';
    game[x - 15][y + 4] = '\'';
    game[x - 15][y + 5] = '.';
    game[x - 15][y + 6] = ',';
    game[x - 15][y + 7] = '_';
    game[x - 15][y + 8] = ',';
    game[x - 15][y + 9] = ',';
    game[x - 15][y + 17] = '(';
    game[x - 15][y + 20] = '.';
    game[x - 15][y + 21] = '-';
    game[x - 15][y + 23] = '.';
    game[x - 15][y + 27] = '.';
    game[x - 15][y + 32] = ')';
    game[x - 14][y + 5] = '\\';
    game[x - 14][y + 9] = '\\';
    game[x - 14][y + 10] = '\\';
    game[x - 14][y + 16] = '(';
    game[x - 14][y + 18] = '\'';
    game[x - 14][y + 27] = ')';
    game[x - 14][y + 28] = '(';
    game[x - 14][y + 33] = ')';
    game[x - 13][y + 6] = '\\';
    game[x - 13][y + 10] = '\\';
    game[x - 13][y + 11] = '\\';
    game[x - 13][y + 16] = '\\';
    game[x - 13][y + 17] = '.';
    game[x - 13][y + 20] = '_';
    game[x - 13][y + 21] = '.';
    game[x - 13][y + 22] = '_';
    game[x - 13][y + 23] = '_';
    game[x - 13][y + 25] = '_';
    game[x - 13][y + 26] = '_';
    game[x - 13][y + 27] = '_';
    game[x - 13][y + 28] = '_';
    game[x - 13][y + 29] = '(';
    game[x - 13][y + 31] = '.';
    game[x - 13][y + 34] = '|';
    game[x - 12][y + 7] = '\\';
    game[x - 12][y + 10] = '/';
    game[x - 12][y + 11] = '\\';
    game[x - 12][y + 12] = '\\';
    game[x - 12][y + 16] = '.';
    game[x - 12][y + 17] = '(';
    game[x - 12][y + 21] = '.';
    game[x - 12][y + 22] = '\'';
    game[x - 12][y + 25] = '/';
    game[x - 12][y + 26] = '\\';
    game[x - 12][y + 29] = '\'';
    game[x - 12][y + 30] = '.';
    game[x - 12][y + 33] = ')';
    game[x - 11][y + 8] = '\\';
    game[x - 11][y + 9] = '(';
    game[x - 11][y + 12] = '\\';
    game[x - 11][y + 13] = '\\';
    game[x - 11][y + 14] = '.';
    game[x - 11][y + 15] = '-';
    game[x - 11][y + 16] = '\'';
    game[x - 11][y + 18] = '(';
    game[x - 11][y + 20] = '/';
    game[x - 11][y + 25] = '\\';
    game[x - 11][y + 26] = '/';
    game[x - 11][y + 31] = '\\';
    game[x - 11][y + 32] = ')';
    game[x - 10][y + 9] = '\'';
    game[x - 10][y + 12] = '(';
    game[x - 10][y + 13] = ')';
    game[x - 10][y + 14] = ')';
    game[x - 10][y + 16] = '_';
    game[x - 10][y + 17] = '\'';
    game[x - 10][y + 18] = '.';
    game[x - 10][y + 19] = '-';
    game[x - 10][y + 20] = '|';
    game[x - 10][y + 21] = '/';
    game[x - 10][y + 22] = '\\';
    game[x - 10][y + 23] = '/';
    game[x - 10][y + 24] = '\\';
    game[x - 10][y + 25] = '/';
    game[x - 10][y + 26] = '\\';
    game[x - 10][y + 27] = '/';
    game[x - 10][y + 28] = '\\';
    game[x - 10][y + 29] = '/';
    game[x - 10][y + 30] = '\\';
    game[x - 10][y + 31] = '|';
    game[x - 9][y + 13] = '\'';
    game[x - 9][y + 14] = '\\';
    game[x - 9][y + 15] = '\\';
    game[x - 9][y + 17] = '.';
    game[x - 9][y + 18] = '(';
    game[x - 9][y + 20] = '|';
    game[x - 9][y + 21] = '\\';
    game[x - 9][y + 22] = '/';
    game[x - 9][y + 23] = '\\';
    game[x - 9][y + 24] = '/';
    game[x - 9][y + 25] = '\\';
    game[x - 9][y + 26] = '/';
    game[x - 9][y + 27] = '\\';
    game[x - 9][y + 28] = '/';
    game[x - 9][y + 29] = '\\';
    game[x - 9][y + 30] = '/';
    game[x - 9][y + 31] = '|';
    game[x - 8][y + 15] = '\'';
    game[x - 8][y + 16] = '(';
    game[x - 8][y + 17] = '(';
    game[x - 8][y + 20] = '\\';
    game[x - 8][y + 25] = '/';
    game[x - 8][y + 26] = '\\';
    game[x - 8][y + 31] = '/';
    game[x - 7][y + 15] = '(';
    game[x - 7][y + 16] = '(';
    game[x - 7][y + 17] = '(';
    game[x - 7][y + 18] = '(';
    game[x - 7][y + 21] = '\'';
    game[x - 7][y + 22] = '.';
    game[x - 7][y + 23] = '_';
    game[x - 7][y + 24] = '_';
    game[x - 7][y + 25] = '\\';
    game[x - 7][y + 26] = '/';
    game[x - 7][y + 27] = '_';
    game[x - 7][y + 28] = '_';
    game[x - 7][y + 29] = '.';
    game[x - 7][y + 30] = '\'';
    game[x - 7][y + 31] = ')';
    game[x - 6][y + 16] = '(';
    game[x - 6][y + 17] = '(';
    game[x - 6][y + 18] = ',';
    game[x - 6][y + 19] = ')';
    game[x - 6][y + 21] = '/';
    game[x - 6][y + 25] = '(';
    game[x - 6][y + 26] = '(';
    game[x - 6][y + 27] = '(';
    game[x - 6][y + 28] = ')';
    game[x - 6][y + 32] = ')';
    game[x - 5][y + 17] = '"';
    game[x - 5][y + 18] = '.';
    game[x - 5][y + 19] = '.';
    game[x - 5][y + 20] = '-';
    game[x - 5][y + 21] = ',';
    game[x - 5][y + 24] = '(';
    game[x - 5][y + 25] = '(';
    game[x - 5][y + 26] = ')';
    game[x - 5][y + 27] = '(';
    game[x - 5][y + 28] = '"';
    game[x - 5][y + 32] = '/';
    game[x - 4][y + 17] = '_';
    game[x - 4][y + 18] = '/';
    game[x - 4][y + 19] = '/';
    game[x - 4][y + 20] = '.';
    game[x - 4][y + 24] = '(';
    game[x - 4][y + 25] = '(';
    game[x - 4][y + 26] = '(';
    game[x - 4][y + 27] = ')';
    game[x - 4][y + 29] = '.';
    game[x - 4][y + 30] = '"';
    game[x - 3][y + 16] = '/';
    game[x - 3][y + 17] = '/';
    game[x - 3][y + 18] = ',';
    game[x - 3][y + 19] = '/';
    game[x - 3][y + 20] = '"';
    game[x - 3][y + 26] = '(';
    game[x - 3][y + 27] = '(';
    game[x - 3][y + 28] = '(';
    game[x - 3][y + 30] = '\'';
    game[x - 3][y + 31] = ',';
    game[x - 2][y + 27] = '(';
    game[x - 2][y + 28] = '(';
    game[x - 2][y + 31] = ')';
    game[x - 1][y + 28] = '/';
    game[x - 1][y + 30] = '/';
    game[x - 0][y + 26] = '_';
    game[x - 0][y + 27] = '/';
    game[x - 0][y + 28] = ',';
    game[x - 0][y + 29] = '/';
    game[x - 0][y + 30] = '\'';
}
void moveDragon(int& x, int& y, int& dir) {
    if (y >= 890) {
        dir = -1;
    }
    else if (y <= 860) {
        dir = 1;
    }

    y += dir * 3;
}
void checkDragon(int& xh, int& yh, int xdr, int ydr, int& F, int& health) {
    if (yh + 20 >= ydr && xh - 15 >= xdr - 21 && yh <= ydr + 5) {
        health -= 35;
        if (health <= 0)
            F = 0;
    }
}
void moveElevatorDiagonalUpRight(int& x, int& y, int& dir, int& xh, int& yh, char game[][950]) {
    if (dir == 1) {
        if (x + 1 == 70) {
            dir *= -1;
        }
    }
    else {
        if (x == 40) {
            dir *= -1;
        }
    }

    x += dir;
    y += (dir * -1) * 3;
    if (xh <= (x + 1) && (yh + 10 >= y && yh + 19 <= y + 18)) {
        xh = x;
        if (dir == 1) {
            xh = x - 2;
        }
        xh += dir; // row hero place
        yh += (dir * -1) * 3; // col hero place
    }
}

void moveElevatorDiagonalUpLeft(int& x, int& y, int& dir, int& xh, int& yh, char game[][950]) {
    if (dir == 1) {
        if (x + 1 == 70) {
            dir *= -1;
        }
    }
    else {
        if (x == 40) {
            dir *= -1;
        }
    }

    x += dir;
    y += (dir) * 3;
    if (xh <= (x + 1) && (yh + 10 >= y && yh + 19 <= y + 18)) {
        xh = x;
        if (dir == 1) {
            xh = x - 2;
        }
        xh += dir; // row hero place
        yh += (dir) * 3; // col hero place
    }
}

void MoveEnmy(char game[][950], int& x, int& y, int& dir) {
    if (y >= 737) {
        dir = -1;
    }
    else if (y <= 710) {
        dir = 1;
    }
    y += dir * 2;
}
void drawseif(char game[][950],int x,int y) {

    game[x - 6][y + 4] = '\'';
    game[x - 6][y + 5] = '.';
    game[x - 6][y + 6] = ',';
    game[x - 6][y + 7] = '_';
    game[x - 6][y + 8] = ',';
    game[x - 6][y + 9] = ',';
    game[x - 5][y + 5] = '\\';
    game[x - 5][y + 9] = '\\';
    game[x - 5][y + 10] = '\\';
    game[x - 4][y + 6] = '\\';
    game[x - 4][y + 10] = '\\';
    game[x - 4][y + 11] = '\\';
    game[x - 3][y + 7] = '\\';
    game[x - 3][y + 10] = '/';
    game[x - 3][y + 11] = '\\';
    game[x - 3][y + 12] = '\\';
    game[x - 2][y + 8] = '\\';
    game[x - 2][y + 9] = '(';
    game[x - 2][y + 12] = '\\';
    game[x - 2][y + 13] = '\\';
    game[x - 1][y + 9] = '\'';
    game[x - 1][y + 13] = '\\';
    game[x - 1][y + 14] = '\\';
    game[x - 0][y + 14] = '\\';
    game[x - 0][y + 15] = '\\';
}

void moveSeif(int& xSeif, int& ySeif) {
    if (xSeif < 72) {
        xSeif++;
        ySeif-=7 ;
	}
	if (xSeif >= 72)
    {
		xSeif = 61;
		ySeif = 876;
	}
    

}    
void checkSeif( int& yh, int ySeif, int& F, int& health) {
    if ( ySeif <= yh + 13) {
		health -= 50;
		if (health == 0)
			F = 0;
	}
}   

int moveHero(int& x, int& y, char UDes, char game[][950]) {
    int flag = 1;
    int F = 1;
    //======================================================left
    if (UDes == 'a') {
        /*if (game[x][y - 1] == 179) {
            F = 0;
            return F;
        }*/
        /*for (int i = x - 2; i > x - 16; i--) {
            if (game[i][y - 1] != ' ') {
                flag = 0;
            }
        }*/
        if (y - 1 > 0 && flag == 1) {
            y -= 2;
        }
    }
    //==================================================right
    else if (UDes == 'd') {
        flag = 1;
        /*if (game[x][y + 22] == 179) {
            F = 0;
            return F;
        }*/
        /*for (int i = x - 2; i > x - 16; i--) {
            if (game[i][y + 22] != ' ') {
                flag = 0;
            }
        }*/
        if (y + 1 < 950 && flag == 1 && y + 24 != 93 && y + 24 != 55)
            y += 2;
    }
    //--------------------jump
    else if (UDes == 'w') {
        flag = 1;
        for (int i = x - 15; i > x - 21; i--) {
            if (game[i][y] != ' ') {
                flag = 0;
            }
        }
        if (y + 10 >= 751 && x > 45)
        {
            x--;
        }
        else if (game[x + 1][y + 10] != ' ' || game[x + 1][y + 19] != ' ' && flag == 1 && x - 5 > 0) {

            x -= 5;
        }
    }
    else if (UDes == 'e') {
        flag = 1;
        for (int i = x - 15; i > x - 21; i--) {
            for (int j = y + 20; j < y + 24; j++) {
                if (game[i][j] != ' ') {
                    flag = 0;
                }
            }
        }
        if (game[x + 1][y + 10] != ' ' || game[x + 1][y + 19] != ' ' && flag == 1 && x - 5 > 0 && y + 3 < 950) {
            x -= 8;
            y += 8;
        }
    }
    else if (UDes == 'q') {
        flag = 1;
        for (int i = x - 15; i > x - 21; i--) {
            for (int j = y; j > y - 3; j--) {
                if (game[i][j] != ' ') {
                    flag = 0;
                }
            }
        }
        if (game[x + 1][y + 10] != ' ' ||
            game[x + 1][y + 19] != ' ' && flag == 1 && x - 5 > 0 && y - 3 > 0) {
            x -= 6;
            y -= 5;
        }
    }
    else if (UDes == 's' && y+10 >= 751 && x < 72)
    {
        x++;
    }
    return F;
}

void herohit(int x, int y, char game[][950], char UDes, Bullet bullets[]) {

    if (UDes == 'b') {
        int chosen_idx = -1;
        for (int i = 0; i < 20; ++i) {
            if (bullets[i].posbullet.x == -1) {
                chosen_idx = i;
                break;
            }
        }

        if (chosen_idx != -1) {
            bullets[chosen_idx].posbullet.x = x - 8;
            bullets[chosen_idx].posbullet.y = y + 20;
        }
    }
}

void dropSpiderEggg(char game[][950], int xspid, int yspid, int& xegg, int& yegg) {
    if (xegg < 73) {
        xegg += 1;
        game[xegg][yegg] = 254;
    }
    if (xegg >= 71) {
        xegg = xspid;
        yegg = yspid + 13;
        game[xegg][yegg] = 254;
    }
}

void checkEgg(int xh, int yh, int xegg, int yegg, int& F, int& health) {
    if (xegg >= xh - 15 && yegg >= yh + 5 && yegg <= yh + 20) {
        health -= 35;
        if (health == 0)
            F = 0;
    }
}

void MoveBullet(char game[][950], Bullet bullets[], int& xspid, int& yspid, int& xenmy, int& yenmy, int& xDragon, int& yDragon, int& flagDrawDragon, int& flageDrawenmy, int& Flagspid, int &ct) {
    
    for (int i = 0; i < 20; i++) {
        if (bullets[i].posbullet.x != -1) {
            game[bullets[i].posbullet.x][bullets[i].posbullet.y] = '>';
            bullets[i].posbullet.y += 5;

            if (bullets[i].posbullet.x >= xspid - 5 && bullets[i].posbullet.x <= xspid + 2 && bullets[i].posbullet.y >= yspid + 1) {
                Flagspid = 0;
                bullets[i].posbullet.x = -1;
                bullets[i].posbullet.y = -1;
            }

            if (bullets[i].posbullet.x >= xenmy - 16 && bullets[i].posbullet.x <= xenmy && bullets[i].posbullet.y >= yenmy) {
                flageDrawenmy = 0;
                bullets[i].posbullet.x = -1;
                bullets[i].posbullet.y = -1;
            }
            if (bullets[i].posbullet.x >= xDragon - 21 && bullets[i].posbullet.x <= xDragon && bullets[i].posbullet.y >= yDragon+3)
            {
                ct --;
                if (ct <= -10)
                {
                    flagDrawDragon = 0;
                    bullets[i].posbullet.x = -1;
                    bullets[i].posbullet.y = -1;
                }
            }

            if (bullets[i].posbullet.y >= 950 || game[bullets[i].posbullet.x][bullets[i].posbullet.y + 1] != ' ') {

                bullets[i].posbullet.x = -1;
                bullets[i].posbullet.y = -1;
            }
        }
    }
}

void gravity(char game[][950], int& x, int& y) {
    if (game[x + 1][y + 10] == ' ' && game[x + 1][y + 19] == ' ' && y != 755) {
        x++;
    }
}

void checkLaser(int xh, int yh, int ylaser, int& F, int laserTimer, int& health) {
    if (ylaser >= yh + 5 && ylaser <= yh + 20 && (laserTimer / 10) % 2 == 0) {
        health -= 20;
        if (health <= 0)
            F = 0;
    }
}

void coutGAMEOVER(char game[][950]) {
    system("cls");
    for (int i = 0; i < 75; ++i) {
        for (int j = 0; j < 950; ++j) {
            game[i][j] = ' ';
        }
    }
    //________________________________________________________shreeta
    int r = 35, c = 15;
    game[r][c] = '/';
    game[r][c + 1] = '_';
    game[r][c + 2] = '_';
    game[r][c + 3] = '_';
    game[r][c + 4] = '_';
    game[r][c + 5] = '_';
    game[r][c + 6] = '_';
    game[r][c + 7] = '_';
    game[r][c + 8] = '_';
    game[r][c + 9] = '_';
    game[r][c + 10] = '_';
    game[r][c + 11] = '_';
    game[r][c + 12] = ')';
    game[r][c + 60] = '(';
    game[r][c + 61] = '_';
    game[r][c + 62] = '_';
    game[r][c + 63] = '_';
    game[r][c + 64] = '_';
    game[r][c + 65] = '_';
    game[r][c + 66] = '_';
    game[r][c + 67] = '_';
    game[r][c + 68] = '_';
    game[r][c + 69] = '_';
    game[r][c + 70] = '_';
    game[r][c + 71] = '_';
    game[r][c + 72] = 92;
    game[r - 1][c + 1] = '/';
    game[r - 1][c + 7] = '|';
    game[r - 1][c + 8] = '_';
    game[r - 1][c + 9] = '_';
    game[r - 1][c + 10] = '_';
    game[r - 1][c + 11] = '_';
    game[r - 1][c + 12] = '_';
    game[r - 1][c + 13] = '_';
    game[r - 1][c + 14] = '_';
    game[r - 1][c + 15] = '_';
    game[r - 1][c + 16] = '_';
    game[r - 1][c + 17] = '_';
    game[r - 1][c + 18] = '_';
    game[r - 1][c + 19] = '_';
    game[r - 1][c + 20] = '_';
    game[r - 1][c + 21] = '_';
    game[r - 1][c + 22] = '_';
    game[r - 1][c + 23] = '_';
    game[r - 1][c + 24] = '_';
    game[r - 1][c + 25] = '_';
    game[r - 1][c + 26] = '_';
    game[r - 1][c + 27] = '_';
    game[r - 1][c + 28] = '_';
    game[r - 1][c + 29] = '_';
    game[r - 1][c + 30] = '_';
    game[r - 1][c + 31] = '_';
    game[r - 1][c + 32] = '_';
    game[r - 1][c + 33] = '_';
    game[r - 1][c + 34] = '_';
    game[r - 1][c + 35] = '_';
    game[r - 1][c + 36] = '_';
    game[r - 1][c + 37] = '_';
    game[r - 1][c + 38] = '_';
    game[r - 1][c + 39] = '_';
    game[r - 1][c + 40] = '_';
    game[r - 1][c + 41] = '_';
    game[r - 1][c + 42] = '_';
    game[r - 1][c + 43] = '_';
    game[r - 1][c + 44] = '_';
    game[r - 1][c + 45] = '_';
    game[r - 1][c + 46] = '_';
    game[r - 1][c + 47] = '_';
    game[r - 1][c + 48] = '_';
    game[r - 1][c + 49] = '_';
    game[r - 1][c + 50] = '_';
    game[r - 1][c + 51] = '_';
    game[r - 1][c + 52] = '_';
    game[r - 1][c + 53] = '_';
    game[r - 1][c + 54] = '_';
    game[r - 1][c + 55] = '_';
    game[r - 1][c + 56] = '_';
    game[r - 1][c + 57] = '_';
    game[r - 1][c + 58] = '_';
    game[r - 1][c + 59] = '_';
    game[r - 1][c + 60] = '_';
    game[r - 1][c + 61] = '_';
    game[r - 1][c + 62] = '_';
    game[r - 1][c + 63] = '_';
    game[r - 1][c + 64] = '_';
    game[r - 1][c + 65] = '|';
    game[r - 1][c + 71] = 92;
    game[r - 2][c + 1] = 92;
    game[r - 2][c + 71] = '/';
    game[r - 2][c + 7] = '|';
    game[r - 2][c + 65] = '|';
    game[r - 3][c + 72] = '/';
    game[r - 3][c] = 92;
    game[r - 4][c] = '_';
    game[r - 4][c + 1] = '_';
    game[r - 4][c + 2] = '_';
    game[r - 4][c + 3] = '_';
    game[r - 4][c + 4] = '_';
    game[r - 4][c + 5] = '_';
    game[r - 4][c + 6] = '_';
    game[r - 3][c + 7] = '|';
    game[r - 4][c + 7] = '|';
    game[r - 3][c + 65] = '|';
    game[r - 4][c + 65] = '|';
    game[r - 4][c + 66] = '_';
    game[r - 4][c + 67] = '_';
    game[r - 4][c + 68] = '_';
    game[r - 4][c + 69] = '_';
    game[r - 4][c + 70] = '_';
    game[r - 4][c + 71] = '_';
    game[r - 4][c + 72] = '_';
    game[r - 5][c + 8] = '_';
    game[r - 5][c + 9] = '_';
    game[r - 5][c + 10] = '_';
    game[r - 5][c + 11] = '_';
    game[r - 5][c + 12] = '_';
    game[r - 5][c + 13] = '_';
    game[r - 5][c + 14] = '_';
    game[r - 5][c + 15] = '_';
    game[r - 5][c + 16] = '_';
    game[r - 5][c + 17] = '_';
    game[r - 5][c + 18] = '_';
    game[r - 5][c + 19] = '_';
    game[r - 5][c + 20] = '_';
    game[r - 5][c + 21] = '_';
    game[r - 5][c + 22] = '_';
    game[r - 5][c + 23] = '_';
    game[r - 5][c + 24] = '_';
    game[r - 5][c + 25] = '_';
    game[r - 5][c + 26] = '_';
    game[r - 5][c + 27] = '_';
    game[r - 5][c + 28] = '_';
    game[r - 5][c + 29] = '_';
    game[r - 5][c + 30] = '_';
    game[r - 5][c + 31] = '_';
    game[r - 5][c + 32] = '_';
    game[r - 5][c + 33] = '_';
    game[r - 5][c + 34] = '_';
    game[r - 5][c + 35] = '_';
    game[r - 5][c + 36] = '_';
    game[r - 5][c + 37] = '_';
    game[r - 5][c + 38] = '_';
    game[r - 5][c + 39] = '_';
    game[r - 5][c + 40] = '_';
    game[r - 5][c + 41] = '_';
    game[r - 5][c + 42] = '_';
    game[r - 5][c + 43] = '_';
    game[r - 5][c + 44] = '_';
    game[r - 5][c + 45] = '_';
    game[r - 5][c + 46] = '_';
    game[r - 5][c + 47] = '_';
    game[r - 5][c + 48] = '_';
    game[r - 5][c + 49] = '_';
    game[r - 5][c + 50] = '_';
    game[r - 5][c + 51] = '_';
    game[r - 5][c + 52] = '_';
    game[r - 5][c + 53] = '_';
    game[r - 5][c + 54] = '_';
    game[r - 5][c + 55] = '_';
    game[r - 5][c + 56] = '_';
    game[r - 5][c + 57] = '_';
    game[r - 5][c + 58] = '_';
    game[r - 5][c + 59] = '_';
    game[r - 5][c + 60] = '_';
    game[r - 5][c + 61] = '_';
    game[r - 5][c + 62] = '_';
    game[r - 5][c + 63] = '_';
    game[r - 5][c + 64] = '_';

    //-------------------------------------------------------------------Game Over

    game[r - 2][c + 10] = 92;
    game[r - 2][c + 11] = '_';
    game[r - 2][c + 12] = 191;
    game[r - 3][c + 10] = '/';
    game[r - 4][c + 11] = '_';
    game[r - 3][c + 12] = 39;

    game[r - 2][c + 15] = '|';
    game[r - 2][c + 17] = '-';
    game[r - 2][c + 19] = '|';
    game[r - 3][c + 16] = '/';
    game[r - 3][c + 18] = 92;
    game[r - 4][c + 17] = '_';


    game[r - 2][c + 22] = '|';
    game[r - 2][c + 24] = 92;
    game[r - 2][c + 25] = '/';
    game[r - 2][c + 27] = '|';
    game[r - 3][c + 22] = '|';
    game[r - 3][c + 23] = 92;
    game[r - 3][c + 26] = '/';
    game[r - 3][c + 27] = '|';

    game[r - 2][c + 30] = '|';
    game[r - 2][c + 31] = '_';
    game[r - 3][c + 30] = '|';
    game[r - 3][c + 31] = '_';
    game[r - 4][c + 31] = '_';
    game[r - 2][c + 32] = '_';
    game[r - 3][c + 32] = '_';
    game[r - 4][c + 32] = '_';

    //______________________________________

    game[r - 2][c + 38] = '|';
    game[r - 2][c + 39] = '_';
    game[r - 2][c + 40] = '_';
    game[r - 2][c + 41] = '|';
    game[r - 3][c + 38] = '|';
    game[r - 3][c + 41] = '|';
    game[r - 4][c + 39] = '_';
    game[r - 4][c + 40] = '_';

    game[r - 2][c + 45] = 92;
    game[r - 2][c + 46] = '/';
    game[r - 3][c + 44] = 92;
    game[r - 3][c + 47] = '/';

    game[r - 2][c + 50] = '|';
    game[r - 2][c + 51] = '_';
    game[r - 3][c + 50] = '|';
    game[r - 3][c + 51] = '_';
    game[r - 4][c + 51] = '_';
    game[r - 2][c + 52] = '_';
    game[r - 3][c + 52] = '_';
    game[r - 4][c + 52] = '_';

    game[r - 2][c + 55] = '|';
    game[r - 2][c + 58] = 92;
    game[r - 3][c + 55] = '|';
    game[r - 3][c + 56] = '_';
    game[r - 3][c + 57] = '_';
    game[r - 3][c + 58] = '/';
    game[r - 4][c + 56] = '_';
    game[r - 4][c + 57] = '_';

    for (int i = 0; i < 75; i++) {
        for (int j = 0; j < 100; j++) {
            cout << game[i][j];
        }
        cout << endl;
    }

}

void coutGAMEWIN(char game[][950]) {

    system("cls");
    for (int i = 0; i < 75; ++i) {
        for (int j = 0; j < 950; ++j) {
            game[i][j] = ' ';
        }
    }
    int r = 50, c = 50;
    game[r][c] = '/';
    game[r][c + 1] = '_';
    game[r][c + 2] = '_';
    game[r][c + 3] = '_';
    game[r][c + 4] = '_';
    game[r][c + 5] = '_';
    game[r][c + 6] = '_';
    game[r][c + 7] = '_';
    game[r][c + 8] = '_';
    game[r][c + 9] = '_';
    game[r][c + 10] = '_';
    game[r][c + 11] = '_';
    game[r][c + 12] = ')';
    game[r][c + 60] = '(';
    game[r][c + 61] = '_';
    game[r][c + 62] = '_';
    game[r][c + 63] = '_';
    game[r][c + 64] = '_';
    game[r][c + 65] = '_';
    game[r][c + 66] = '_';
    game[r][c + 67] = '_';
    game[r][c + 68] = '_';
    game[r][c + 69] = '_';
    game[r][c + 70] = '_';
    game[r][c + 71] = '_';
    game[r][c + 72] = 92;
    game[r - 1][c + 1] = '/';
    game[r - 1][c + 7] = '|';
    game[r - 1][c + 8] = '_';
    game[r - 1][c + 9] = '_';
    game[r - 1][c + 10] = '_';
    game[r - 1][c + 11] = '_';
    game[r - 1][c + 12] = '_';
    game[r - 1][c + 13] = '_';
    game[r - 1][c + 14] = '_';
    game[r - 1][c + 15] = '_';
    game[r - 1][c + 16] = '_';
    game[r - 1][c + 17] = '_';
    game[r - 1][c + 18] = '_';
    game[r - 1][c + 19] = '_';
    game[r - 1][c + 20] = '_';
    game[r - 1][c + 21] = '_';
    game[r - 1][c + 22] = '_';
    game[r - 1][c + 23] = '_';
    game[r - 1][c + 24] = '_';
    game[r - 1][c + 25] = '_';
    game[r - 1][c + 26] = '_';
    game[r - 1][c + 27] = '_';
    game[r - 1][c + 28] = '_';
    game[r - 1][c + 29] = '_';
    game[r - 1][c + 30] = '_';
    game[r - 1][c + 31] = '_';
    game[r - 1][c + 32] = '_';
    game[r - 1][c + 33] = '_';
    game[r - 1][c + 34] = '_';
    game[r - 1][c + 35] = '_';
    game[r - 1][c + 36] = '_';
    game[r - 1][c + 37] = '_';
    game[r - 1][c + 38] = '_';
    game[r - 1][c + 39] = '_';
    game[r - 1][c + 40] = '_';
    game[r - 1][c + 41] = '_';
    game[r - 1][c + 42] = '_';
    game[r - 1][c + 43] = '_';
    game[r - 1][c + 44] = '_';
    game[r - 1][c + 45] = '_';
    game[r - 1][c + 46] = '_';
    game[r - 1][c + 47] = '_';
    game[r - 1][c + 48] = '_';
    game[r - 1][c + 49] = '_';
    game[r - 1][c + 50] = '_';
    game[r - 1][c + 51] = '_';
    game[r - 1][c + 52] = '_';
    game[r - 1][c + 53] = '_';
    game[r - 1][c + 54] = '_';
    game[r - 1][c + 55] = '_';
    game[r - 1][c + 56] = '_';
    game[r - 1][c + 57] = '_';
    game[r - 1][c + 58] = '_';
    game[r - 1][c + 59] = '_';
    game[r - 1][c + 60] = '_';
    game[r - 1][c + 61] = '_';
    game[r - 1][c + 62] = '_';
    game[r - 1][c + 63] = '_';
    game[r - 1][c + 64] = '_';
    game[r - 1][c + 65] = '|';
    game[r - 1][c + 71] = 92;
    game[r - 2][c + 1] = 92;
    game[r - 2][c + 71] = '/';
    game[r - 2][c + 7] = '|';
    game[r - 2][c + 65] = '|';
    game[r - 3][c + 72] = '/';
    game[r - 3][c] = 92;
    game[r - 4][c] = '_';
    game[r - 4][c + 1] = '_';
    game[r - 4][c + 2] = '_';
    game[r - 4][c + 3] = '_';
    game[r - 4][c + 4] = '_';
    game[r - 4][c + 5] = '_';
    game[r - 4][c + 6] = '_';
    game[r - 3][c + 7] = '|';
    game[r - 4][c + 7] = '|';
    game[r - 3][c + 65] = '|';
    game[r - 4][c + 65] = '|';
    game[r - 4][c + 66] = '_';
    game[r - 4][c + 67] = '_';
    game[r - 4][c + 68] = '_';
    game[r - 4][c + 69] = '_';
    game[r - 4][c + 70] = '_';
    game[r - 4][c + 71] = '_';
    game[r - 4][c + 72] = '_';
    game[r - 5][c + 8] = '_';
    game[r - 5][c + 9] = '_';
    game[r - 5][c + 10] = '_';
    game[r - 5][c + 11] = '_';
    game[r - 5][c + 12] = '_';
    game[r - 5][c + 13] = '_';
    game[r - 5][c + 14] = '_';
    game[r - 5][c + 15] = '_';
    game[r - 5][c + 16] = '_';
    game[r - 5][c + 17] = '_';
    game[r - 5][c + 18] = '_';
    game[r - 5][c + 19] = '_';
    game[r - 5][c + 20] = '_';
    game[r - 5][c + 21] = '_';
    game[r - 5][c + 22] = '_';
    game[r - 5][c + 23] = '_';
    game[r - 5][c + 24] = '_';
    game[r - 5][c + 25] = '_';
    game[r - 5][c + 26] = '_';
    game[r - 5][c + 27] = '_';
    game[r - 5][c + 28] = '_';
    game[r - 5][c + 29] = '_';
    game[r - 5][c + 30] = '_';
    game[r - 5][c + 31] = '_';
    game[r - 5][c + 32] = '_';
    game[r - 5][c + 33] = '_';
    game[r - 5][c + 34] = '_';
    game[r - 5][c + 35] = '_';
    game[r - 5][c + 36] = '_';
    game[r - 5][c + 37] = '_';
    game[r - 5][c + 38] = '_';
    game[r - 5][c + 39] = '_';
    game[r - 5][c + 40] = '_';
    game[r - 5][c + 41] = '_';
    game[r - 5][c + 42] = '_';
    game[r - 5][c + 43] = '_';
    game[r - 5][c + 44] = '_';
    game[r - 5][c + 45] = '_';
    game[r - 5][c + 46] = '_';
    game[r - 5][c + 47] = '_';
    game[r - 5][c + 48] = '_';
    game[r - 5][c + 49] = '_';
    game[r - 5][c + 50] = '_';
    game[r - 5][c + 51] = '_';
    game[r - 5][c + 52] = '_';
    game[r - 5][c + 53] = '_';
    game[r - 5][c + 54] = '_';
    game[r - 5][c + 55] = '_';
    game[r - 5][c + 56] = '_';
    game[r - 5][c + 57] = '_';
    game[r - 5][c + 58] = '_';
    game[r - 5][c + 59] = '_';
    game[r - 5][c + 60] = '_';
    game[r - 5][c + 61] = '_';
    game[r - 5][c + 62] = '_';
    game[r - 5][c + 63] = '_';
    game[r - 5][c + 64] = '_';
    //----------------------------------------------------WINNER
    r = 50, c = 54;
    game[r - 3][c + 15] = 92;
    game[r - 2][c + 16] = 92;
    game[r - 2][c + 17] = '/';
    game[r - 2][c + 18] = 92;
    game[r - 2][c + 19] = '/';
    game[r - 3][c + 20] = '/';

    game[r - 2][c + 23] = '_';
    game[r - 2][c + 24] = '|';
    game[r - 3][c + 24] = '|';
    game[r - 4][c + 23] = '_';
    game[r - 2][c + 25] = '_';
    game[r - 4][c + 25] = '_';

    game[r - 2][c + 28] = '|';
    game[r - 3][c + 28] = '|';
    game[r - 3][c + 29] = 92;
    game[r - 2][c + 30] = 92;
    game[r - 2][c + 31] = '|';
    game[r - 3][c + 31] = '|';

    game[r - 2][c + 34] = '|';
    game[r - 3][c + 34] = '|';
    game[r - 3][c + 35] = 92;
    game[r - 2][c + 36] = 92;
    game[r - 2][c + 37] = '|';
    game[r - 3][c + 37] = '|';

    //-------------------------------------------------------E
    game[r - 2][c + 40] = '|';
    game[r - 2][c + 41] = '_';
    game[r - 3][c + 40] = '|';
    game[r - 3][c + 41] = '_';
    game[r - 4][c + 41] = '_';
    game[r - 2][c + 42] = '_';
    game[r - 3][c + 42] = '_';
    game[r - 4][c + 42] = '_';

    //---------------------------------------------------------R
    game[r - 2][c + 45] = '|';
    game[r - 2][c + 48] = 92;
    game[r - 3][c + 45] = '|';
    game[r - 3][c + 46] = '_';
    game[r - 3][c + 47] = '_';
    game[r - 3][c + 48] = '/';
    game[r - 4][c + 46] = '_';
    game[r - 4][c + 47] = '_';

    //-----------------------------------------------------------------coin1

    r = 38, c = 8;
    game[r][c + 13] = 39;
    game[r][c + 14] = 39;
    game[r][c + 15] = '=';
    game[r][c + 16] = '-';
    game[r][c + 17] = '-';
    game[r][c + 18] = 39;

    game[r - 1][c + 9] = '~';
    game[r - 1][c + 10] = '~';
    game[r - 1][c + 11] = ';';
    game[r - 1][c + 12] = ';';
    game[r - 1][c + 13] = ';';
    game[r - 1][c + 14] = ',';
    game[r - 1][c + 15] = '.';
    game[r - 1][c + 16] = '_';
    game[r - 1][c + 17] = 179;
    game[r - 1][c + 18] = '_';
    game[r - 1][c + 19] = '_';
    game[r - 1][c + 20] = '_';
    game[r - 1][c + 21] = '.';
    game[r - 1][c + 22] = ',';
    game[r - 1][c + 23] = '-';
    game[r - 1][c + 24] = ';';
    game[r - 1][c + 25] = ';';
    game[r - 1][c + 26] = ';';
    game[r - 1][c + 27] = '~';
    game[r - 1][c + 28] = 39;

    game[r - 2][c + 7] = 96;
    game[r - 2][c + 8] = ';';
    game[r - 2][c + 9] = '.';
    game[r - 2][c + 10] = ',';
    game[r - 2][c + 11] = 179;
    game[r - 2][c + 12] = '.';
    game[r - 2][c + 17] = 179;
    game[r - 2][c + 24] = 39;
    game[r - 2][c + 25] = 92;
    game[r - 2][c + 26] = '.';
    game[r - 2][c + 27] = '-';
    game[r - 2][c + 28] = 39;
    game[r - 2][c + 29] = '/';

    game[r - 3][c + 6] = 92;
    game[r - 3][c + 7] = 92;
    game[r - 3][c + 11] = 179;
    game[r - 3][c + 17] = 179;
    game[r - 3][c + 24] = 92;
    game[r - 3][c + 29] = '/';
    game[r - 3][c + 30] = '/';

    game[r - 4][c + 5] = 92;
    game[r - 4][c + 6] = 92;
    game[r - 4][c + 12] = ',';
    game[r - 4][c + 13] = 179;
    game[r - 4][c + 15] = 39;
    game[r - 4][c + 16] = 92;
    game[r - 4][c + 19] = 39;
    game[r - 4][c + 20] = 179;
    game[r - 4][c + 21] = '>';
    game[r - 4][c + 22] = '<';
    game[r - 4][c + 23] = 179;
    game[r - 4][c + 30] = '/';
    game[r - 4][c + 31] = '/';

    game[r - 5][c + 4] = 179;
    game[r - 5][c + 5] = 179;
    game[r - 5][c + 14] = 179;
    game[r - 5][c + 16] = 39;
    game[r - 5][c + 17] = 39;
    game[r - 5][c + 18] = 92;
    game[r - 5][c + 19] = ';';
    game[r - 5][c + 20] = ';';
    game[r - 5][c + 21] = ';';
    game[r - 5][c + 22] = ';';
    game[r - 5][c + 23] = ';';
    game[r - 5][c + 24] = ';';
    game[r - 5][c + 31] = 179;
    game[r - 5][c + 32] = 179;

    game[r - 6][c + 4] = 179;
    game[r - 6][c + 5] = 179;
    game[r - 6][c + 13] = 39;
    game[r - 6][c + 14] = ';';
    game[r - 6][c + 15] = ';';
    game[r - 6][c + 18] = ';';
    game[r - 6][c + 19] = ';';
    game[r - 6][c + 20] = ';';
    game[r - 6][c + 21] = ';';
    game[r - 6][c + 22] = '=';
    game[r - 6][c + 31] = 179;
    game[r - 6][c + 32] = 179;

    game[r - 7][c + 4] = 179;
    game[r - 7][c + 5] = 179;
    game[r - 7][c + 13] = ';';
    game[r - 7][c + 14] = ';';
    game[r - 7][c + 15] = ';';
    game[r - 7][c + 16] = ';';
    game[r - 7][c + 17] = ';';
    game[r - 7][c + 18] = ';';
    game[r - 7][c + 19] = ';';
    game[r - 7][c + 23] = '_';
    game[r - 7][c + 24] = 92;
    game[r - 7][c + 31] = 179;
    game[r - 7][c + 32] = 179;

    game[r - 8][c + 4] = 179;
    game[r - 8][c + 5] = 179;
    game[r - 8][c + 13] = ';';
    game[r - 8][c + 14] = ';';
    game[r - 8][c + 15] = ';';
    game[r - 8][c + 16] = ';';
    game[r - 8][c + 17] = '(';
    game[r - 8][c + 21] = '/';
    game[r - 8][c + 22] = '.';
    game[r - 8][c + 23] = 179;
    game[r - 8][c + 31] = 179;
    game[r - 8][c + 32] = 179;

    game[r - 9][c + 4] = '.';
    game[r - 9][c + 5] = '/';
    game[r - 9][c + 6] = '/';
    game[r - 9][c + 13] = ';';
    game[r - 9][c + 14] = ';';
    game[r - 9][c + 15] = ';';
    game[r - 9][c + 16] = ';';
    game[r - 9][c + 17] = ';';
    game[r - 9][c + 22] = 92;
    game[r - 9][c + 30] = 92;
    game[r - 9][c + 31] = 92;

    game[r - 10][c + 6] = '/';
    game[r - 10][c + 7] = '/';
    game[r - 10][c + 14] = ',';
    game[r - 10][c + 15] = ';';
    game[r - 10][c + 16] = ';';
    game[r - 10][c + 17] = ';';
    game[r - 10][c + 18] = ';';
    game[r - 10][c + 19] = ';';
    game[r - 10][c + 20] = ';';
    game[r - 10][c + 21] = ';';
    game[r - 10][c + 22] = ';';
    game[r - 10][c + 29] = 92;
    game[r - 10][c + 30] = 92;

    game[r - 11][c + 7] = '/';
    game[r - 11][c + 8] = ';';
    game[r - 11][c + 9] = '-';
    game[r - 11][c + 10] = '~';
    game[r - 11][c + 25] = '~';
    game[r - 11][c + 26] = '-';
    game[r - 11][c + 27] = '.';
    game[r - 11][c + 28] = 92;

    game[r - 12][c + 9] = '.';
    game[r - 12][c + 10] = '.';
    game[r - 12][c + 11] = ';';
    game[r - 12][c + 12] = ';';
    game[r - 12][c + 13] = ';';
    game[r - 12][c + 14] = '-';
    game[r - 12][c + 15] = '-';
    game[r - 12][c + 16] = 39;
    game[r - 12][c + 17] = '~';
    game[r - 12][c + 18] = '~';
    game[r - 12][c + 19] = '~';
    game[r - 12][c + 20] = '`';
    game[r - 12][c + 21] = '-';
    game[r - 12][c + 22] = '-';
    game[r - 12][c + 23] = ';';
    game[r - 12][c + 24] = ';';
    game[r - 12][c + 25] = ';';
    game[r - 12][c + 26] = '.';

    game[r - 13][c + 14] = '_';
    game[r - 13][c + 15] = '_';
    game[r - 13][c + 21] = '_';
    game[r - 13][c + 22] = '_';

    game[r - 13][c + 16] = '-';
    game[r - 13][c + 17] = '-';
    game[r - 13][c + 18] = '-';
    game[r - 13][c + 19] = '-';
    game[r - 13][c + 20] = '-';

    //------------------------------------------------------------coin1 again
    r = 70, c = 135;
    game[r][c + 13] = 39;
    game[r][c + 14] = 39;
    game[r][c + 15] = '=';
    game[r][c + 16] = '-';
    game[r][c + 17] = '-';
    game[r][c + 18] = 39;

    game[r - 1][c + 9] = '~';
    game[r - 1][c + 10] = '~';
    game[r - 1][c + 11] = ';';
    game[r - 1][c + 12] = ';';
    game[r - 1][c + 13] = ';';
    game[r - 1][c + 14] = ',';
    game[r - 1][c + 15] = '.';
    game[r - 1][c + 16] = '_';
    game[r - 1][c + 17] = 179;
    game[r - 1][c + 18] = '_';
    game[r - 1][c + 19] = '_';
    game[r - 1][c + 20] = '_';
    game[r - 1][c + 21] = '.';
    game[r - 1][c + 22] = ',';
    game[r - 1][c + 23] = '-';
    game[r - 1][c + 24] = ';';
    game[r - 1][c + 25] = ';';
    game[r - 1][c + 26] = ';';
    game[r - 1][c + 27] = '~';
    game[r - 1][c + 28] = 39;

    game[r - 2][c + 7] = 96;
    game[r - 2][c + 8] = ';';
    game[r - 2][c + 9] = '.';
    game[r - 2][c + 10] = ',';
    game[r - 2][c + 11] = 179;
    game[r - 2][c + 12] = '.';
    game[r - 2][c + 17] = 179;
    game[r - 2][c + 24] = 39;
    game[r - 2][c + 25] = 92;
    game[r - 2][c + 26] = '.';
    game[r - 2][c + 27] = '-';
    game[r - 2][c + 28] = 39;
    game[r - 2][c + 29] = '/';

    game[r - 3][c + 6] = 92;
    game[r - 3][c + 7] = 92;
    game[r - 3][c + 11] = 179;
    game[r - 3][c + 17] = 179;
    game[r - 3][c + 24] = 92;
    game[r - 3][c + 29] = '/';
    game[r - 3][c + 30] = '/';

    game[r - 4][c + 5] = 92;
    game[r - 4][c + 6] = 92;
    game[r - 4][c + 12] = ',';
    game[r - 4][c + 13] = 179;
    game[r - 4][c + 15] = 39;
    game[r - 4][c + 16] = 92;
    game[r - 4][c + 19] = 39;
    game[r - 4][c + 20] = 179;
    game[r - 4][c + 21] = '>';
    game[r - 4][c + 22] = '<';
    game[r - 4][c + 23] = 179;
    game[r - 4][c + 30] = '/';
    game[r - 4][c + 31] = '/';

    game[r - 5][c + 4] = 179;
    game[r - 5][c + 5] = 179;
    game[r - 5][c + 14] = 179;
    game[r - 5][c + 16] = 39;
    game[r - 5][c + 17] = 39;
    game[r - 5][c + 18] = 92;
    game[r - 5][c + 19] = ';';
    game[r - 5][c + 20] = ';';
    game[r - 5][c + 21] = ';';
    game[r - 5][c + 22] = ';';
    game[r - 5][c + 23] = ';';
    game[r - 5][c + 24] = ';';
    game[r - 5][c + 31] = 179;
    game[r - 5][c + 32] = 179;

    game[r - 6][c + 4] = 179;
    game[r - 6][c + 5] = 179;
    game[r - 6][c + 13] = 39;
    game[r - 6][c + 14] = ';';
    game[r - 6][c + 15] = ';';
    game[r - 6][c + 18] = ';';
    game[r - 6][c + 19] = ';';
    game[r - 6][c + 20] = ';';
    game[r - 6][c + 21] = ';';
    game[r - 6][c + 22] = '=';
    game[r - 6][c + 31] = 179;
    game[r - 6][c + 32] = 179;

    game[r - 7][c + 4] = 179;
    game[r - 7][c + 5] = 179;
    game[r - 7][c + 13] = ';';
    game[r - 7][c + 14] = ';';
    game[r - 7][c + 15] = ';';
    game[r - 7][c + 16] = ';';
    game[r - 7][c + 17] = ';';
    game[r - 7][c + 18] = ';';
    game[r - 7][c + 19] = ';';
    game[r - 7][c + 23] = '_';
    game[r - 7][c + 24] = 92;
    game[r - 7][c + 31] = 179;
    game[r - 7][c + 32] = 179;

    game[r - 8][c + 4] = 179;
    game[r - 8][c + 5] = 179;
    game[r - 8][c + 13] = ';';
    game[r - 8][c + 14] = ';';
    game[r - 8][c + 15] = ';';
    game[r - 8][c + 16] = ';';
    game[r - 8][c + 17] = '(';
    game[r - 8][c + 21] = '/';
    game[r - 8][c + 22] = '.';
    game[r - 8][c + 23] = 179;
    game[r - 8][c + 31] = 179;
    game[r - 8][c + 32] = 179;

    game[r - 9][c + 4] = '.';
    game[r - 9][c + 5] = '/';
    game[r - 9][c + 6] = '/';
    game[r - 9][c + 13] = ';';
    game[r - 9][c + 14] = ';';
    game[r - 9][c + 15] = ';';
    game[r - 9][c + 16] = ';';
    game[r - 9][c + 17] = ';';
    game[r - 9][c + 22] = 92;
    game[r - 9][c + 30] = 92;
    game[r - 9][c + 31] = 92;

    game[r - 10][c + 6] = '/';
    game[r - 10][c + 7] = '/';
    game[r - 10][c + 14] = ',';
    game[r - 10][c + 15] = ';';
    game[r - 10][c + 16] = ';';
    game[r - 10][c + 17] = ';';
    game[r - 10][c + 18] = ';';
    game[r - 10][c + 19] = ';';
    game[r - 10][c + 20] = ';';
    game[r - 10][c + 21] = ';';
    game[r - 10][c + 22] = ';';
    game[r - 10][c + 29] = 92;
    game[r - 10][c + 30] = 92;

    game[r - 11][c + 7] = '/';
    game[r - 11][c + 8] = ';';
    game[r - 11][c + 9] = '-';
    game[r - 11][c + 10] = '~';
    game[r - 11][c + 25] = '~';
    game[r - 11][c + 26] = '-';
    game[r - 11][c + 27] = '.';
    game[r - 11][c + 28] = 92;

    game[r - 12][c + 9] = '.';
    game[r - 12][c + 10] = '.';
    game[r - 12][c + 11] = ';';
    game[r - 12][c + 12] = ';';
    game[r - 12][c + 13] = ';';
    game[r - 12][c + 14] = '-';
    game[r - 12][c + 15] = '-';
    game[r - 12][c + 16] = 39;
    game[r - 12][c + 17] = '~';
    game[r - 12][c + 18] = '~';
    game[r - 12][c + 19] = '~';
    game[r - 12][c + 20] = '`';
    game[r - 12][c + 21] = '-';
    game[r - 12][c + 22] = '-';
    game[r - 12][c + 23] = ';';
    game[r - 12][c + 24] = ';';
    game[r - 12][c + 25] = ';';
    game[r - 12][c + 26] = '.';

    game[r - 13][c + 14] = '_';
    game[r - 13][c + 15] = '_';
    game[r - 13][c + 21] = '_';
    game[r - 13][c + 22] = '_';

    game[r - 13][c + 16] = '-';
    game[r - 13][c + 17] = '-';
    game[r - 13][c + 18] = '-';
    game[r - 13][c + 19] = '-';
    game[r - 13][c + 20] = '-';

    //-----------------------------------------------------------------------coin2

    r = 70, c = 8;
    game[r + 3][c + 10] = '-';
    game[r + 3][c + 11] = '.';
    game[r + 3][c + 12] = '.';
    game[r + 3][c + 13] = ',';
    game[r + 3][c + 14] = ',';
    game[r + 3][c + 15] = ',';
    game[r + 3][c + 16] = ',';
    game[r + 3][c + 17] = '.';
    game[r + 3][c + 18] = '.';
    game[r + 3][c + 19] = '-';
    game[r + 3][c + 8] = '`';
    game[r + 3][c + 9] = 39;
    game[r + 3][c + 20] = '`';
    game[r + 3][c + 21] = 39;

    game[r + 2][c + 7] = '_';
    game[r + 2][c + 22] = '_';
    game[r + 2][c + 6] = '.';
    game[r + 2][c + 23] = '.';
    game[r + 2][c + 5] = 39;
    game[r + 2][c + 24] = 39;

    game[r + 1][c + 3] = '`';
    game[r + 1][c + 4] = 92;
    game[r + 1][c + 25] = '/';
    game[r + 1][c + 26] = '`';

    game[r][c + 2] = 92;
    game[r][c + 11] = 39;
    game[r][c + 12] = '.';
    game[r][c + 13] = '_';
    game[r][c + 14] = '_';
    game[r][c + 15] = '_';
    game[r][c + 16] = '.';
    game[r][c + 17] = '-';
    game[r][c + 18] = 39;
    game[r][c + 2] = '`';
    game[r][c + 2] = 22;
    game[r][c + 27] = '/';

    game[r - 1][c + 1] = ';';
    game[r - 1][c + 12] = '/';
    game[r - 1][c + 18] = 92;
    game[r - 1][c + 19] = 92;
    game[r - 1][c + 20] = ')';
    game[r - 1][c + 28] = ';';

    game[r - 2][c] = ';';
    game[r - 2][c + 9] = '`';
    game[r - 2][c + 10] = '~';
    game[r - 2][c + 11] = '~';
    game[r - 2][c + 12] = ';';
    game[r - 2][c + 18] = 92;
    game[r - 2][c + 19] = 92;
    game[r - 2][c + 29] = ';';

    game[r - 3][c] = '|';
    game[r - 3][c + 9] = '|';
    game[r - 3][c + 10] = '-';
    game[r - 3][c + 13] = '_';
    game[r - 3][c + 14] = '.';
    game[r - 3][c + 15] = 39;
    game[r - 3][c + 17] = 92;
    game[r - 3][c + 19] = '|';
    game[r - 3][c + 29] = '|';

    game[r - 4][c] = '|';
    game[r - 4][c + 8] = '/';
    game[r - 4][c + 9] = '_';
    game[r - 4][c + 15] = 39;
    game[r - 4][c + 16] = '-';
    game[r - 4][c + 17] = '.';
    game[r - 4][c + 18] = '_';
    game[r - 4][c + 19] = '_';
    game[r - 4][c + 20] = ')';
    game[r - 4][c + 29] = '|';

    game[r - 5][c] = ';';
    game[r - 5][c + 9] = '/';
    game[r - 5][c + 10] = '>';
    game[r - 5][c + 13] = '`';
    game[r - 5][c + 14] = '.';
    game[r - 5][c + 17] = '-';
    game[r - 5][c + 18] = '.';
    game[r - 5][c + 19] = '|';
    game[r - 5][c + 29] = ';';

    game[r - 6][c + 1] = ';';
    game[r - 6][c + 10] = '/';
    game[r - 6][c + 12] = '`';
    game[r - 6][c + 13] = '-';
    game[r - 6][c + 18] = 92;
    game[r - 6][c + 28] = ';';

    game[r - 7][c + 2] = '/';
    game[r - 7][c + 3] = '`';
    game[r - 7][c + 11] = '.';
    game[r - 7][c + 12] = '-';
    game[r - 7][c + 13] = 39;
    game[r - 7][c + 14] = '~';
    game[r - 7][c + 15] = 34;
    game[r - 7][c + 16] = '-';
    game[r - 7][c + 17] = '.';
    game[r - 7][c + 26] = '`';
    game[r - 7][c + 27] = 92;

    game[r - 8][c + 4] = '/';
    game[r - 8][c + 25] = 92;

    game[r - 9][c + 5] = '.';
    game[r - 9][c + 24] = '.';
    game[r - 9][c + 6] = 39;
    game[r - 9][c + 7] = '`';
    game[r - 9][c + 22] = '`';
    game[r - 9][c + 23] = 39;

    game[r - 10][c + 8] = '_';
    game[r - 10][c + 9] = '.';
    game[r - 10][c + 10] = '-';
    game[r - 10][c + 11] = 39;
    game[r - 10][c + 12] = '~';
    game[r - 10][c + 13] = '~';
    game[r - 10][c + 14] = '`';
    game[r - 10][c + 15] = '~';
    game[r - 10][c + 16] = '~';
    game[r - 10][c + 17] = 39;
    game[r - 10][c + 18] = '-';
    game[r - 10][c + 19] = '.';
    game[r - 10][c + 20] = '_';

    //-------------------------------------------------------coin2again
    r = 38, c = 130;
    game[r + 3][c + 10] = '-';
    game[r + 3][c + 11] = '.';
    game[r + 3][c + 12] = '.';
    game[r + 3][c + 13] = ',';
    game[r + 3][c + 14] = ',';
    game[r + 3][c + 15] = ',';
    game[r + 3][c + 16] = ',';
    game[r + 3][c + 17] = '.';
    game[r + 3][c + 18] = '.';
    game[r + 3][c + 19] = '-';
    game[r + 3][c + 8] = '`';
    game[r + 3][c + 9] = 39;
    game[r + 3][c + 20] = '`';
    game[r + 3][c + 21] = 39;

    game[r + 2][c + 7] = '_';
    game[r + 2][c + 22] = '_';
    game[r + 2][c + 6] = '.';
    game[r + 2][c + 23] = '.';
    game[r + 2][c + 5] = 39;
    game[r + 2][c + 24] = 39;

    game[r + 1][c + 3] = '`';
    game[r + 1][c + 4] = 92;
    game[r + 1][c + 25] = '/';
    game[r + 1][c + 26] = '`';

    game[r][c + 2] = 92;
    game[r][c + 11] = 39;
    game[r][c + 12] = '.';
    game[r][c + 13] = '_';
    game[r][c + 14] = '_';
    game[r][c + 15] = '_';
    game[r][c + 16] = '.';
    game[r][c + 17] = '-';
    game[r][c + 18] = 39;
    game[r][c + 2] = '`';
    game[r][c + 2] = 22;
    game[r][c + 27] = '/';

    game[r - 1][c + 1] = ';';
    game[r - 1][c + 12] = '/';
    game[r - 1][c + 18] = 92;
    game[r - 1][c + 19] = 92;
    game[r - 1][c + 20] = ')';
    game[r - 1][c + 28] = ';';

    game[r - 2][c] = ';';
    game[r - 2][c + 9] = '`';
    game[r - 2][c + 10] = '~';
    game[r - 2][c + 11] = '~';
    game[r - 2][c + 12] = ';';
    game[r - 2][c + 18] = 92;
    game[r - 2][c + 19] = 92;
    game[r - 2][c + 29] = ';';

    game[r - 3][c] = '|';
    game[r - 3][c + 9] = '|';
    game[r - 3][c + 10] = '-';
    game[r - 3][c + 13] = '_';
    game[r - 3][c + 14] = '.';
    game[r - 3][c + 15] = 39;
    game[r - 3][c + 17] = 92;
    game[r - 3][c + 19] = '|';
    game[r - 3][c + 29] = '|';

    game[r - 4][c] = '|';
    game[r - 4][c + 8] = '/';
    game[r - 4][c + 9] = '_';
    game[r - 4][c + 15] = 39;
    game[r - 4][c + 16] = '-';
    game[r - 4][c + 17] = '.';
    game[r - 4][c + 18] = '_';
    game[r - 4][c + 19] = '_';
    game[r - 4][c + 20] = ')';
    game[r - 4][c + 29] = '|';

    game[r - 5][c] = ';';
    game[r - 5][c + 9] = '/';
    game[r - 5][c + 10] = '>';
    game[r - 5][c + 13] = '`';
    game[r - 5][c + 14] = '.';
    game[r - 5][c + 17] = '-';
    game[r - 5][c + 18] = '.';
    game[r - 5][c + 19] = '|';
    game[r - 5][c + 29] = ';';

    game[r - 6][c + 1] = ';';
    game[r - 6][c + 10] = '/';
    game[r - 6][c + 12] = '`';
    game[r - 6][c + 13] = '-';
    game[r - 6][c + 18] = 92;
    game[r - 6][c + 28] = ';';

    game[r - 7][c + 2] = '/';
    game[r - 7][c + 3] = '`';
    game[r - 7][c + 11] = '.';
    game[r - 7][c + 12] = '-';
    game[r - 7][c + 13] = 39;
    game[r - 7][c + 14] = '~';
    game[r - 7][c + 15] = 34;
    game[r - 7][c + 16] = '-';
    game[r - 7][c + 17] = '.';
    game[r - 7][c + 26] = '`';
    game[r - 7][c + 27] = 92;

    game[r - 8][c + 4] = '/';
    game[r - 8][c + 25] = 92;

    game[r - 9][c + 5] = '.';
    game[r - 9][c + 24] = '.';
    game[r - 9][c + 6] = 39;
    game[r - 9][c + 7] = '`';
    game[r - 9][c + 22] = '`';
    game[r - 9][c + 23] = 39;

    game[r - 10][c + 8] = '_';
    game[r - 10][c + 9] = '.';
    game[r - 10][c + 10] = '-';
    game[r - 10][c + 11] = 39;
    game[r - 10][c + 12] = '~';
    game[r - 10][c + 13] = '~';
    game[r - 10][c + 14] = '`';
    game[r - 10][c + 15] = '~';
    game[r - 10][c + 16] = '~';
    game[r - 10][c + 17] = 39;
    game[r - 10][c + 18] = '-';
    game[r - 10][c + 19] = '.';
    game[r - 10][c + 20] = '_';

    for (int i = 0; i < 75; i++) {
        for (int j = 0; j < 170; j++) {
            cout << game[i][j];
        }
        cout << endl;
    }
}

void coutMatrix(char game[][950], int x, int y) {
    system("cls");
    int s = 0, e = 170;
    int end = e + y;
    if (end >= 950) {
        end = 950;
    }
    for (int i = 0; i < 75; i++) {
        for (int j = s + y; j < end; j++) {
            cout << game[i][j];
        }
        cout << endl;
    }
}


int main() {
    char gameGrid[75][950];
    char UDes = ' ';
    int ct = 20;
    //----------------------------------------------
    Hero hero;
    hero.poshero.x = 70;
    hero.poshero.y = 5;
    hero.health = 100;
    int flagshook1 = 1;
    int flagshook2 = 1;
    //------------------------------------
    Spider spider;
    spider.posspider.x = 50;
    spider.posspider.y = 188;
    int Flagspid = 1;
    //------------------------------------
    SpiderEgg spiderEgg;
    spiderEgg.posspideregg.x = spider.posspider.x - 1;
    spiderEgg.posspideregg.y = spider.posspider.y + 3;
    int flagSpiderEgg = 1;
    //------------------------------------
    Bullet bullets[20];
    for (int i = 0; i < 20; i++) {
        bullets[i].posbullet.x = -1;
        bullets[i].posbullet.y = -1;
    }
    //------------------------------------
    Elevator elevator;
    elevator.posElevator.x = 70;
    elevator.posElevator.y = 269;
    int direlevator1 = -1;
    //------------------------------------
    Elevator elevator2;
    elevator2.posElevator.x = 70;
    elevator2.posElevator.y = 452;
    int direlevator2 = -1;
    //------------------------------------
    enmy enmy1;
    enmy1.posenmy.x = 44;
    enmy1.posenmy.y = 735;
    int flagenmy1 = 1;
    int direnmy = -1;
    int flageDrawenmy = 1;
    //------------------------------------
    Dragon dragon;
    dragon.posdragon.x = 72;
    dragon.posdragon.y = 870;
    int direDragon = -1;
    int flagDragon = 1;
    int flagDrawDragon = 1;
    int flagDragonCheck = 1;
    //------------------------------------
    int F = 1;
    int laserTimer = 0;
    int flaglaser = 1;
    int flagBigshook = 1;
    //------------------------------------
	int xseif = dragon.posdragon.x-11;
	int yseif = dragon.posdragon.y+6 ;
    int flagSeif = 1;
    //------------------------------------

    while (true) {
        for (; !_kbhit();) {
            clearAndDrawFxObjects(gameGrid);
            drawshouk1(gameGrid);
            drawshouk2(gameGrid);
            drawhero(gameGrid, hero.poshero.x, hero.poshero.y);
            drawelevator(elevator.posElevator.x, elevator.posElevator.y, gameGrid);
            drawelevator2(elevator2.posElevator.x, elevator2.posElevator.y, gameGrid);

            if ((laserTimer / 10) % 2 == 0) {
                drawLaser(gameGrid);
            }
            MoveEnmy(gameGrid, enmy1.posenmy.x, enmy1.posenmy.y, direnmy);
            moveElevatorDiagonalUpRight(elevator.posElevator.x, elevator.posElevator.y, direlevator1, hero.poshero.x,
                hero.poshero.y, gameGrid);
            moveElevatorDiagonalUpLeft(elevator2.posElevator.x, elevator2.posElevator.y, direlevator2,
                hero.poshero.x, hero.poshero.y, gameGrid);
            gravity(gameGrid, hero.poshero.x, hero.poshero.y);
            //----------------------------------------------------------------------------
            checkshook1(hero.poshero.x, hero.poshero.y, 72, 50, flagshook1, hero.health);
            checkshook2(hero.poshero.x, hero.poshero.y, 70, 269, flagshook2, hero.health);
            //----------------------------------------------------------------------------
            drawDragon(gameGrid, dragon.posdragon.x, dragon.posdragon.y);


            // moveDragon(dragon.posdragon.x, dragon.posdragon.x, direDragon);


            MoveBullet(gameGrid, bullets, spider.posspider.x, spider.posspider.y, enmy1.posenmy.x, enmy1.posenmy.y, dragon.posdragon.x, dragon.posdragon.y, flagDrawDragon, flageDrawenmy, Flagspid,ct );
            if (Flagspid == 1) {

                dropSpiderEggg(gameGrid, spider.posspider.x, spider.posspider.y, spiderEgg.posspideregg.x, spiderEgg.posspideregg.y);
                drawSpider(gameGrid, 52, 197);
            }
            if (flagDrawDragon == 1) {
                
                drawDragon(gameGrid, dragon.posdragon.x, dragon.posdragon.y);
				checkSeif( hero.poshero.y, yseif, flagSeif, hero.health);
                checkDragon(hero.poshero.x, hero.poshero.y, dragon.posdragon.x, dragon.posdragon.y, flagDragonCheck, hero.health);
				moveSeif(xseif, yseif);  
				drawseif(gameGrid, xseif, yseif); 

            }
            if (flageDrawenmy == 1) {
                drawEnmy(gameGrid, enmy1.posenmy.x, enmy1.posenmy.y);
                checkEnmy(hero.poshero.x, hero.poshero.y, enmy1.posenmy.x, enmy1.posenmy.y, flagenmy1, hero.health);
            }
            if (Flagspid == 0) {
                spider.posspider.x = -1, spider.posspider.y = -1;

            }
            checkLaser(hero.poshero.x, hero.poshero.y, 510, flaglaser, laserTimer, hero.health);
            checkEgg(hero.poshero.x, hero.poshero.y, spiderEgg.posspideregg.x, spiderEgg.posspideregg.y, flagSpiderEgg, hero.health);
            checkBigshook(hero.poshero.x, hero.poshero.y, 73, 300, flagBigshook, hero.health);
            if (F == 0 || flagshook1 == 0 || flagshook2 == 0 || flagSpiderEgg == 0 || flagBigshook == 0 || flaglaser == 0 || flagenmy1 == 0 || flagDragonCheck == 0|| flagSeif==0) {
                coutGAMEOVER(gameGrid);
                break;
            }
            if (flagDrawDragon == 0) {
                coutGAMEWIN(gameGrid);
                break;
            }
            coutMatrix(gameGrid, hero.poshero.x, hero.poshero.y);
            laserTimer++;
        }
        UDes = _getch();
        F = moveHero(hero.poshero.x, hero.poshero.y, UDes, gameGrid);
        drawhero(gameGrid, hero.poshero.x, hero.poshero.y);
        herohit(hero.poshero.x, hero.poshero.y, gameGrid, UDes, bullets);
        if (F == 0 || flagshook1 == 0 || flagshook2 == 0 || flagSpiderEgg == 0 || flagBigshook == 0 || flaglaser == 0 || flagenmy1 == 0 || flagDragonCheck == 0 || flagSeif == 0) {
            coutGAMEOVER(gameGrid);
            break;
        }
        if (flagDrawDragon == 0) {
            coutGAMEWIN(gameGrid);
            break;
        }

    }
}
