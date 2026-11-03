#include <stdio.h>
int main(){
int frames[10],ref[50];
int nof,nor;
int i,j,pageFault=0,found,pointer=0;
printf("FIFO PAGE REPLACEMENT ALGORITHM\n");
printf("Enter no of frames: ");
scanf("%d",&nof);
printf("Enter no of reference strings: ");
scanf("%d",&nor);
printf("Enter Reference String: ");
for(i = 0; i < nor; i++)
scanf("%d", &ref[i]);
for(i = 0; i < nof; i++)
frames[i] = -1;
printf("\nReference\tFrames\t\tStatus\n");
for(i=0;i<nor;i++){
found=0;
for(j=0;j<nof;j++){
if (frames[j]==ref[i]){
found=1;
break;
}
}
if(found==0){
pageFault++;
frames[pointer]=ref[i];
pointer=(pointer+1)%nof;
}
printf("%d\t\t", ref[i]);
for (j = 0; j < nof; j++){
if (frames[j] == -1)
printf("- ");
else
printf("%d ", frames[j]);
}
if (found == 0)
printf("\t\tPage Fault");
else
printf("\t\tPage Hit");
printf("\n");
}
printf("\nNo of page faults: %d\n", pageFault);
return 0;
}