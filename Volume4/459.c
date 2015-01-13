/* @JUDGE_ID:50418EN 459 C */
#include <stdio.h>
#include <string.h>

#define MAX_NODE_NUM 26+1

#define TheSmallestNodeName ('A')

int NodeGroup[MAX_NODE_NUM];

void UnionTwoNode(int StartNode,int EndNode, int NumNodes)
{	
  int IdxNode;  
  int Ruler;
  int Beruler;
  
  if ( StartNode < EndNode) {
  	Ruler = NodeGroup[EndNode];
	Beruler = NodeGroup[StartNode];  	
  } else if ( StartNode > EndNode) {
    Ruler = NodeGroup[StartNode];
    Beruler = NodeGroup[EndNode];
  } else {
    return;
  }
  for ( IdxNode = 1; IdxNode <= NumNodes; IdxNode++) {
  	 if (NodeGroup[IdxNode] == Beruler) {
	    NodeGroup[IdxNode] = Ruler;
	 }
  }  	  
}

int main(void)
{
	int NumCase, NumNodes;	
	int IdxNodeNum;
    int NumInputChar;
	char InputLine[80];
	char EdgeStartNode, EdgeDstNode;
	int StartNode, DetNode;
	int RecordPresent[MAX_NODE_NUM];
	int NumMaxConnSubGraph;    	      
    
    /*
	freopen("p459_in.txt", "r", stdin);
	freopen("p459_out.txt", "w", stdout);
    */
    	
	scanf("%d\n", &NumCase);
	while(NumCase--) {				
		scanf("%s", &InputLine);          
		
        NumNodes = InputLine[0] - 'A' + 1;				
        
		for (IdxNodeNum = 1; IdxNodeNum <= NumNodes ; IdxNodeNum++) {
			NodeGroup[IdxNodeNum] = IdxNodeNum;
		}			
		gets(InputLine);		
		while ( gets(InputLine) != NULL) {	
  		   if (InputLine[0] == '\n' || InputLine[0] == '\0') {
 		   	  break;	
  		   }
           StartNode = (int) (InputLine[0] - 'A') + 1;
		   DetNode = (int) (InputLine[1] - 'A') + 1; 		 		 
		   if ( NodeGroup[StartNode] != NodeGroup[DetNode]) {
		   	  UnionTwoNode(StartNode, DetNode, NumNodes );
		   }		
		}
		
		for ( IdxNodeNum = 0; IdxNodeNum <= NumNodes; IdxNodeNum++) {
            RecordPresent[IdxNodeNum] = 0;
        }        
        
        NumMaxConnSubGraph = 0;
		for (IdxNodeNum = 1;  IdxNodeNum <= NumNodes;  IdxNodeNum++){
           if  ( RecordPresent[NodeGroup[IdxNodeNum]] == 0) {               
               NumMaxConnSubGraph++;
               RecordPresent[NodeGroup[IdxNodeNum]] = 1;
           }		
		}
		printf("%d\n", NumMaxConnSubGraph);	
		if ( NumCase > 0) {
             	printf("\n");	
        }            
             
	}
	return 0;
}
