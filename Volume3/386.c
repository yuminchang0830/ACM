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
    int CubeVolMinusDSquare;
    int CubeVolMinusDSquareCSquare;    
    CubeVol = PerfectCubeVol[SideLen];
    
    for ( IdxD = SideLen -1; IdxD > (SideLen/2); IdxD--) {
        CubeVolMinusDSquare = CubeVol - PerfectCubeVol[IdxD];
        /* Find Suitable Idx for IdxC by remain CubeVol */
        /*printf("IdxD = %d, CubeVol-d^2=%d\n", IdxD, CubeVolMinusDSquare);*/
       
        for ( IdxC = IdxD-1; (PerfectCubeVol[IdxC] > CubeVolMinusDSquare) && (IdxC > 1) ; IdxC--) {                                    
            SuitableIdx = IdxC;                      
        }  
        /*printf("IdxC = %d\n", IdxC);*/

        for ( ; IdxC > (SideLen/3); IdxC--) {          
            CubeVolMinusDSquareCSquare = CubeVolMinusDSquare - PerfectCubeVol[IdxC];
            /*printf("IdxC = %d, CubeVol-d^2-c^2=%d\n", IdxC, CubeVolMinusDSquareCSquare);*/
            for ( IdxB = IdxC-1; (PerfectCubeVol[IdxB] > CubeVol) && (IdxB > 1); IdxB--) {   
                 SuitableIdx = IdxB;                                 
                 
            }  
            /*printf("IdxB = %d\n", IdxB);  */
            for ( ; IdxB > 0; IdxB--)
            {
                if ( (CubeVolMinusDSquareCSquare - PerfectCubeVol[IdxB]) == 0)
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


freopen("p386_in.txt", "r", stdin);
freopen("p386_out.txt", "w", stdout);

for ( IdxCubeSize = 0; IdxCubeSize < MAXCUBESIZE; IdxCubeSize++) {
    PerfectCubeVol[IdxCubeSize] = IdxCubeSize*IdxCubeSize*IdxCubeSize;
}

for ( IdxCubeSize = 6; IdxCubeSize <= 200; IdxCubeSize++) 
{
   IsPerfectCube(IdxCubeSize);
}



return 0;
}

