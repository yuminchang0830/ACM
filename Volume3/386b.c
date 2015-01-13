#include <stdio.h>
#include <stdlib.h>

#define MAXCUBESIZE 201

int PerfectCubeVol[MAXCUBESIZE];



void IsPerfectCube(int SideLen)
{
    int IdxD;
    int IdxC;
    int IdxB;
    int SuitableIdx;
    int CubeVol;
    int CubeVolMinusBSquare;
    int CubeVolMinusBSquareCSquare;    
    CubeVol = PerfectCubeVol[SideLen];
    
    for ( IdxB = 2; IdxB < (SideLen); IdxB++) {    
        CubeVolMinusBSquare = CubeVol - PerfectCubeVol[IdxB];   
        for (IdxC=IdxB+1; IdxC < (SideLen);IdxC++) {
            CubeVolMinusBSquareCSquare = CubeVolMinusBSquare - PerfectCubeVol[IdxC];   
            for (IdxD=IdxC+1; IdxD < (SideLen);IdxD++) {
                if ( (CubeVolMinusBSquareCSquare - PerfectCubeVol[IdxD]) == 0)
                {
                     printf("Cube = %d, Triple = (%d,%d,%d)\n", SideLen, IdxB, IdxC, IdxD);
                }
            }
        }
    }
}


int main(void)
{

int IdxCubeSize;

/*
freopen("p386_in.txt", "r", stdin);
freopen("p386_out.txt", "w", stdout);
*/
for ( IdxCubeSize = 0; IdxCubeSize < MAXCUBESIZE; IdxCubeSize++) {
    PerfectCubeVol[IdxCubeSize] = IdxCubeSize*IdxCubeSize*IdxCubeSize;
}

for ( IdxCubeSize = 6; IdxCubeSize <= 200; IdxCubeSize++) 
{
   IsPerfectCube(IdxCubeSize);
}



return 0;
}

