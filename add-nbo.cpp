#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
int main(int argc,char*argv[]){
	FILE* f1 = fopen(argv[1],"rb");
	FILE* f2 = fopen(argv[2],"rb");
	if(f1==NULL||f2 == NULL){
		printf("No File");
		return 0;
	}
	uint32_t*n1 = (uint32_t*)malloc(2);
	uint32_t*n2 = (uint32_t*)malloc(2);
	fread(n1,1,4,f1);
	fread(n2,1,4,f2);
	uint32_t tot1 = ntohl(*n1);
	uint32_t tot2 = ntohl(*n2);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",tot1,tot1,tot2,tot2,tot1+tot2,tot1+tot2);
	fclose(f1);
	fclose(f2);
	return 0;
}
