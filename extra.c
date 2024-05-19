int A[36][36];
int sq[36][36];
int hx[36][36];
int count = 0;
int bn = 0, gn = 0;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
int A[36][36] = { 
        {25, 32, 28, 16, 20, 19, 17, 10, 10, 21, 32, 28, 27, 32, 21, 14, 16, 18, 22, 28, 22, 25, 34, 15, 17, 30, 27, 16, 21, 13, 14, 12,  8, 18, 31, 32},//1 
        {33, 25, 30, 18, 19, 21, 19, 17, 20, 31, 28, 27, 29, 31, 34, 27, 23, 20 ,24, 27, 24, 27, 23, 29, 27, 29, 32, 21, 17, 14, 15, 14, 20, 30, 22, 33},//2
        {31, 30, 25, 21, 16, 13, 11, 14, 12, 23, 27, 21, 26, 29, 26, 18, 21, 22, 26, 25, 11, 14, 30, 31, 32, 25, 16,  5,  7, 17, 18, 23, 13, 23, 28, 18},//3
        
        {27, 26, 29, 25, 29, 27, 25, 27, 26, 13, 17, 11, 13, 15, 12, 25, 29, 28, 29, 30, 14, 11, 27, 28, 20, 13,  4, 16, 18, 28, 28, 33, 23, 11, 16,  6},//4
        {26, 30, 17, 29, 25, 35, 33, 29, 30, 19, 17,  7,  3, 19, 20, 32, 29, 27, 28, 14, 20, 17, 26, 25, 12, 19, 10, 22, 19, 27, 27, 24, 32, 20, 17, 11},//5
        {30, 25, 26, 30, 34, 25, 31, 30, 28, 17, 21, 13, 15, 14, 18, 30, 32, 18, 19, 33, 26, 23, 30, 23, 16, 14, 16, 28, 31, 18, 18, 28, 27, 15, 18, 17},//6
        
        {20, 15, 16, 27, 31, 30, 25, 32, 30, 17, 21, 13, 26, 15, 29, 31, 33, 19, 18, 32, 15, 20, 27, 20, 16, 14, 16, 26, 29, 16, 17, 20, 19, 15, 18, 17},//7
        { 8, 20, 12, 23, 31, 30, 33, 25, 32, 11, 17, 15, 23, 31, 20, 22, 24, 18, 27, 28, 28, 22, 21, 12,  6, 20, 17, 27, 22, 25, 19,  8, 16, 12, 17, 19},//8
        {13, 15, 17, 28, 25, 30, 33, 31, 25, 20, 21, 16, 25, 24, 22, 24, 23, 29, 28, 33, 25, 12, 28, 13,  7, 15, 18, 21, 27, 26, 20, 13, 11,  7, 19, 17},//9 
        
        {23, 25, 27, 18, 15, 20, 26, 16, 26, 25, 35, 29, 25, 24, 22, 11, 10, 16, 15, 20, 12, 26, 34, 19, 18, 26, 22, 17, 16, 15, 15,  8,  6, 11, 23, 21},//10 
        {28, 29, 25, 16, 19, 18, 24, 25, 28, 35, 25, 31, 25, 30, 27, 16, 21, 12, 11, 20 ,14, 28, 31, 30, 24, 20, 26, 14, 17, 11, 11, 16, 16, 21, 20, 25},//11 
        {27, 22, 23, 14,  4, 16, 22, 18, 25, 32, 31, 25, 21, 21, 27, 15, 12, 20, 19,  3, 11, 25, 28, 31, 23, 22, 17,  5,  2, 19, 19, 17, 14, 19, 20,  9},//12
        
        {27, 29, 23,  9,  5, 11, 22, 25, 21, 23, 28, 22, 25, 31, 27, 15, 18, 20, 18,  8, 10, 21, 29, 33, 29, 27, 15,  8, 12, 22, 15, 20, 10, 23, 28, 14},//13
        {33, 31, 29, 15, 15, 17, 28, 27, 27, 29, 29, 25, 31, 25, 35, 24, 20, 18, 16, 18, 16, 27, 29, 28, 27, 29, 31, 25, 22, 20, 13, 12, 18, 31, 23, 32},//14
        {25, 34, 26, 12, 19, 15, 26, 22, 19, 21, 32, 25, 30, 35, 25, 22, 15, 13, 11, 21, 11, 22, 32, 17, 19, 32, 29, 23, 25, 17, 10,  7,  7, 13, 34, 29},//15
        
        {12, 21, 13, 25, 32, 28, 30, 26, 23, 10, 21, 14, 27, 32, 20, 25, 34, 24, 24, 34, 24, 10, 20,  5,  7, 20, 17, 21, 23, 15, 22, 19, 12,  9, 23, 18},//16
        { 7, 19, 17, 29, 27, 32, 34, 21, 27, 14, 19, 18, 25, 30, 22, 33, 25, 29, 23, 33, 29, 15, 18,  9,  5, 18, 18, 22, 21, 21, 28,  7, 22, 21, 17, 22},//17
        {15, 13, 19, 31, 27, 18, 20, 29, 27, 14, 16, 18, 31, 21, 24, 27, 29, 25, 33, 29, 33, 19, 13, 16, 20, 11, 14, 18, 18, 22, 22, 30, 23, 13, 13, 13},//18
        
        {24, 22, 28, 32, 28, 19, 17, 26, 24, 13, 15, 17, 22, 14, 15, 25, 27, 31, 25, 29, 33, 22, 16, 19, 20, 11, 14, 27, 28, 23, 22, 30, 24, 19, 19, 19},//19 
        {24, 28, 15, 19, 16, 33, 31, 26, 32, 21, 18,  9,  8, 21, 18, 28, 34, 27, 29, 25, 29, 10, 21, 20, 13, 18,  7, 19, 24, 29, 28, 22, 30, 36, 23, 20},//20 
        {22, 21, 13, 17, 17, 29, 27, 26, 24, 13, 15,  9, 14, 14, 15, 25, 24, 34, 36, 29, 25, 22, 16, 19, 20, 11,  6, 19, 17, 33, 32, 30, 24, 19, 19, 11},//21 
        
        {28, 26, 17, 13, 13, 25, 15, 14, 12, 26, 28, 22, 23, 23, 24, 12, 11, 21, 31, 16, 28, 25, 29, 30, 31, 23, 18,  5,  2, 20, 20, 18, 11, 25, 25, 18},//22
        {31, 25, 27, 23, 27, 26, 16, 15, 20, 33, 30, 29, 24, 29, 27, 15, 20, 11, 21, 30, 24, 29, 25, 32, 22, 29, 26, 14, 19, 11, 11, 16, 16, 29, 28, 33},//23
        {15, 26, 34, 30, 20, 25, 15,  1,  8, 22, 30, 31, 31, 23, 19,  7,  5, 18, 28, 23, 28, 33, 32, 25, 21, 23, 26, 13, 10, 18, 18,  9,  4, 18, 28, 26},//24
        
        {16, 26, 28, 23, 20, 17, 10,  8,  3, 17, 29, 25, 29, 27, 16,  3,  7, 16, 17, 16, 17, 29, 26, 22, 25, 29, 26, 13, 16, 19, 26, 21, 12, 17, 28, 29},//25
        {30, 28, 24, 19, 23, 25, 18, 16, 18, 32, 20, 28, 27, 29, 32, 19, 15, 14, 15, 16, 15, 27, 28, 27, 29, 25, 34, 22, 20, 17, 24, 21, 29, 33, 30, 32},//26
        {30, 31, 15, 10, 16, 20, 13, 19, 15, 22, 32, 17, 19, 32, 29, 16, 18, 11, 21, 11,  4, 16, 31, 24, 29, 34, 25, 21, 13, 14, 21, 24, 26, 30, 33, 21},//27
        
        {20, 21,  5, 16, 22, 26, 25, 31, 20, 16, 19,  4,  7, 20, 17, 21, 23, 16, 26, 25, 18,  4, 19, 12, 25, 30, 29, 25, 33, 26, 25, 28, 30, 29, 32, 20},//28
        {18, 19,  7, 18, 19, 32, 31, 19, 31, 20, 15,  8,  5, 18, 18, 22, 21, 20, 30, 23, 22,  8, 17, 16, 23, 30, 20, 32, 25, 30, 29, 26, 31, 30, 27, 24},//29 
        {14, 10, 20, 31, 26, 17, 14, 25, 22, 11, 13, 14, 20, 12, 14, 18, 19, 22, 25, 29, 32, 18, 15, 16, 30, 22, 25, 29, 30, 25, 32, 32, 27, 25, 25, 21},//30 
        
        {14, 10, 20, 30, 25, 14, 14, 18, 15, 18, 20, 24, 20, 12, 14, 24, 25, 21, 23, 27, 30, 18, 15, 16, 30, 22, 25, 28, 29, 32, 25, 33, 28, 16, 16, 12},//31 
        { 6, 15, 19, 29, 26, 27, 18,  7, 11, 14, 19, 28, 18, 16,  5, 15,  9, 29, 31, 23, 31, 19, 14, 13, 19, 25, 22, 25, 29, 32, 33, 25, 28,  8, 15, 17},//32
        {11, 16, 15, 25, 27, 29, 22, 16, 12, 15, 25, 19, 15, 17, 11, 14, 17, 26, 28, 30, 24, 13, 18,  3, 17, 27, 30, 33, 29, 30, 31, 28, 25, 22, 22, 17},//33
        
        {21, 26, 25, 13, 15, 17, 17, 11,  7, 12, 22, 16, 26, 28, 15, 12,  8, 17, 15, 17, 12, 25, 30, 15, 20, 30, 33, 30, 26, 27, 26, 15, 28, 25, 33, 28},//34
        {28, 24, 24, 12, 19, 15, 15, 19, 19, 24, 21, 20, 24, 25, 30, 20, 21, 11,  9, 19, 12, 25, 29, 28, 25, 33, 30, 27, 29, 21, 20, 25, 28, 33, 25, 34},//35
        {31, 28, 20,  8,  6, 19, 19, 14, 20, 25, 25, 10, 13, 27, 30, 20, 19, 16, 14,  9,  6, 19, 33, 26, 29, 28, 23, 20, 19, 24, 23, 22, 25, 30, 33, 25} //36 
    };
  int sq[36][36] = { 
        {0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0},//1
        {0,25,30,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//2
        {0,30,25,21,0,0,0,0,12,23,0,0,0,0,26,18,0,0,0,0,11,14,0,0,0,0,16,5,0,0,0,0,13,23,0,0},//3
        {0,0,29,25,29,0,0,0,26,13,0,0,0,0,12,25,0,0,0,0,14,11,0,0,0,0,4,16,0,0,0,0,23,11,0,0},//4
        {0,0,0,0,0,35,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//5
        {0,0,0,0,0,0,0,30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//6
        {0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//7
        {0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,0,0,0,0,0,0,0},//8
        {0,0,17,28,0,0,0,0,25,20,21,0,0,0,22,24,0,0,0,0,0,12,0,0,0,0,18,21,0,0,0,0,11,7,0,0},//9
        {0,0,27,18,0,0,0,0,26,25,35,0,0,0,22,11,0,0,0,0,12,26,0,0,0,0,22,17,0,0,0,0,6,11,0,0},//10
        {0,0,0,0,0,0,0,0,0,0,0,31,0,0,0,0,0,0,0,0,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0},//11
        {0,0,0,0,0,0,0,0,0,0,31,25,0,0,0,0,0,0,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,0,0,0},//12
        {0,0,0,0,0,0,0,0,0,0,0,0,0,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//13
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,35,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//14
        {0,0,26,12,0,0,0,0,19,21,0,0,0,0,25,22,0,0,0,0,11,22,0,0,0,0,29,23,0,0,0,0,7,0,0,0},//15
        {0,0,13,0,0,0,0,0,23,10,0,0,0,0,30,25,34,0,0,0,24,10,0,0,0,0,17,21,0,0,0,0,12,9,0,0},//16
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,29,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0},//17
        {15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,33,0,0,0,0,0,0,0,0,0,0,22,22,0,0,0,0,0},//18
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,23,22,0,0,0,0,0},//19
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//20
        {0,0,13,17,0,0,0,0,24,13,0,0,0,0,15,25,0,0,0,0,25,22,0,0,0,0,6,19,0,0,0,0,24,19,0,0},//21
        {0,0,17,13,0,0,0,0,12,26,0,0,0,0,24,12,0,0,0,0,28,25,29,0,0,0,18,5,0,0,0,0,11,25,0,0},//22
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0},//23
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,21,0,0,0,0,0,0,0,0,0,0,0},//24
        {0,0,0,0,0,0,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,25,29,0,0,0,0,0,0,0,0,0,0},//25
        {0,0,0,0,0,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,34,0,0,0,0,0,0,0,0,0},//26
        {0,0,15,10,0,0,0,0,15,22,0,0,0,0,29,16,0,0,0,0,4,16,0,0,0,0,25,21,0,0,0,0,26,30,0,0},//27
        {0,0,5,16,0,0,0,0,20,16,0,0,0,0,17,21,0,0,0,0,18,4,0,0,0,0,29,25,0,0,0,0,30,29,0,0},//28
        {0,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,0,0,0,0,0,0},//29
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,25,0,0,0,0,0,0,0,0,0,0,25,32,32,0,0,0,0},//30
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,23,0,0,0,0,0,0,0,0,0,0,32,25,33,0,0,0,0},//31
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,28,0,0,0},//32
        {0,0,15,25,0,0,0,0,12,15,0,0,0,0,11,14,0,0,0,0,24,13,0,0,0,0,30,33,0,0,0,0,25,22,22,0},//33
        {0,0,25,13,0,0,0,0,7,12,0,0,0,0,15,12,0,0,0,0,12,25,0,0,0,0,33,30,0,0,0,0,28,25,33,0},//34
        {0,0,0,0,0,0,0,0,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,34},//35
	      {31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}//36    
    };

  int hx[36][36] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//1
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//2
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//3
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//4
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//5
        {0,0,0,0,0,0,0,0,0,17,0,13,15,14,0,0,0,0,0,0,0,0,0,0,16,14,16,0,0,0,0,0,0,15,0,17,},//6
        {0,15,16,0,0,0,0,0,0,17,0,13,0,0,0,0,0,0,0,0,0,0,0,0,16,14,16,0,0,16,17,0,0,15,0,17},//7
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//8
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//9
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//10
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//11
        {0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//12
        {0,0,0,9,5,11,0,0,0,0,0,0,0,0,0,15,0,0,0,8,10,0,0,0,0,0,15,8,12,0,15,0,10,0,0,14},//13
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//14
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//15
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//16
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//17
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//18
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//19
        {0,0,15,0,16,0,0,0,0,0,0,9,8,0,0,0,0,0,0,0,0,10,0,0,13,0,7,0,0,0,0,0,0,0,0,0},//20
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//21
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//22
        {0,0,0,0,0,0,16,15,0,0,0,0,0,0,0,15,0,11,0,0,0,0,0,0,0,0,0,14,0,11,11,16,16,0,0,0},//23
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//24
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//25
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//26
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//27
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//28
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//29
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//30
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//31
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//32
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//33
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//34
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//35
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}//36
    };
}

  // put your main code here, to run repeatedly:
void loop() {
  int input1, input2;

  // Wait until there's data available on the serial port
  while (!Serial.available()) {
    // do nothing
  }

  // Read the first integer input from the serial monitor
  input1 = Serial.parseInt();

  // Wait until there's data available on the serial port
  while (!Serial.available()) {
    // do nothing
  }

  // Read the second integer input from the serial monitor
  input2 = Serial.parseInt();

  // Print the inputs back
  Serial.print("Input 1: ");
  Serial.println(input1);
  Serial.print("Input 2: ");
  Serial.println(input2);

  // Clear the serial buffer
  while (Serial.available()) {
    Serial.read();
  }

  delay(1000); // Delay for stability
  // bn = input1;
  // gn = input2;

  
    
    
    // if(A[bn][gn] >= 18){
    //   if(sq[bn][gn] == 0){
    //     Serial.println("Marriage Possible");
    //   }
    //   else{
    //     Serial.println("Marriage not possible");
    //   }
    // }
    // else if(A[bn][gn] < 18){
    //   if(hx[bn][gn] == 0){
    //     Serial.println("Marriage Not Possible");
    //   }
    //   else{
    //     Serial.println("Marriage Possible");        
    //   }
    // }
    // else
    //   Serial.println("ganeshana maduve");
     
  //   delay(1000);
}
