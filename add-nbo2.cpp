#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
uint32_t add(char* filename){
    FILE* file = fopen(filename,"rb");
    uint32_t f;
    size_t readlen = fread(&f,1,4,file);
    if(readlen !=sizeof(uint32_t)){
        fprintf(stderr,"fread return $lu\n",readlen);
        exit(-1);
    }
    f = ntohl(f);
    fclose(file);
    return f;
}
int main(int argc,char*argv[]){
    if(argc!=3){
        printf("syntax : add-nbo <file1> <file2>\n");
        printf("sample: add-nbo a.bin b.bin\n");
        return -1;
    }
    uint32_t f1,f2;
    f1 = add(argv[1]);
    f2 = add(argv[2]);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",f1,f1,f2,f2,f1+f2,f1+f2);
    return 0;
}
