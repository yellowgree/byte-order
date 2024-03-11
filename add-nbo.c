#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    
    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("File  ERROR\n");
        return 2;
    }

    uint32_t value1, value2;
    uint32_t sum = 0;
    
    while ((fread(&value1, sizeof(uint32_t), 1, file1) && 
	   fread(&value2, sizeof(uint32_t), 1, file2)) !=1) {
		printf("Read ERROR\n");
		fclose(file1);
		fclose(file2);
		return 2;

    }

    uint32_t data1 = ntohl(value1);
    uint32_t data2 = ntohl(value2);
	
    sum = data1+data2;
    printf("%d(%08x)+%d(%08x) = %d(%08x) ",data1,data1, data2,data2,sum, sum);

    fclose(file1);
    fclose(file2);


    return 0;

}

