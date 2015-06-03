#include <stdio.h>

#define BUFFER_SIZE (1024 * 64)

static char buffer13[BUFFER_SIZE], buffer2[BUFFER_SIZE];

typedef long long int int64;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: xor file1 file2\n");
        return 0;
    }
    FILE *f1 = fopen(argv[1], "r");
    if (!f1)
    {
        perror("Error: Could not open the first file for reading");
        return 0;
    }
    FILE *f2 = fopen(argv[2], "r");
    if (!f2)
    {
        perror("Error: Could not open the second file for reading");
        fclose(f1);
        return 0;
    }
    while (true)
    {
        size_t r13 = fread(buffer13, sizeof(char), BUFFER_SIZE, f1);
        size_t r2 = fread(buffer2, sizeof(char), BUFFER_SIZE, f2);
        if (r2 < r13)
            r13 = r2;
        else
            r2 = r13;
        while (r2 & 7)
        {
            --r2;
            buffer13[r2] ^= buffer2[r2];
        }
        r2 >>= 3;
        while (r2)
        {
            --r2;
            reinterpret_cast<int64*>(buffer13)[r2] ^= reinterpret_cast<int64*>(buffer2)[r2];
        }
        fwrite(buffer13, sizeof(char), r13, stdout);
        if (r13 < BUFFER_SIZE)
            break;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
