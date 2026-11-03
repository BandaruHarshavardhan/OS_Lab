#include <stdio.h>
#define max 25
int main(){
int frag[max], b[max], f[max];
int i, j, nb, nf, temp;
static int bf[max], ff[max];
printf("Enter the number of blocks: ");
scanf("%d", &nb);
printf("Enter the number of files: ");
scanf("%d", &nf);
printf("\nEnter the size of the blocks:\n");
for(i = 1; i <= nb; i++){
printf("Block %d: ", i);
scanf("%d", &b[i]);
}
printf("\nEnter the size of the files:\n");
for(i = 1; i <= nf; i++){
printf("File %d: ", i);
scanf("%d", &f[i]);
}
for(i = 1; i <= nf; i++){
ff[i] = 0; // Initially no block is allocated
for(j = 1; j <= nb; j++){
if(bf[j] != 1){
temp = b[j] - f[i];
if(temp >= 0){
ff[i] = j;
frag[i] = temp;
bf[j] = 1;
break;
}
}
}
}
printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment");
for(i = 1; i <= nf; i++){
if(ff[i] != 0){
printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",i, f[i], ff[i], b[ff[i]], frag[i]);
}else
printf("\n%d\t%d\tNot Allocated\t-\t\t-",i, f[i]);
}
return 0;
}