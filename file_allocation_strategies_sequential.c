#include <stdio.h>
#include <string.h>

struct fileTable {
    char name[20];
    int sb, nob;
} ft[30];

void main() {
    int i, j, n;
    char s[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name, start block, and number of blocks for file %d: ", i + 1);
        scanf("%s %d %d", ft[i].name, &ft[i].sb, &ft[i].nob);
    }

    printf("\nEnter file name to search: ");
    scanf("%s", s);

    for (i = 0; i < n && strcmp(s, ft[i].name) != 0; i++);

    if (i == n) printf("\nFile Not Found\n");
    else {
        printf("\nFILE NAME\tSTART BLOCK\tNO OF BLOCKS\tBLOCKS OCCUPIED\n%s\t\t%d\t\t%d\t\t", ft[i].name, ft[i].sb, ft[i].nob);
        for (j = 0; j < ft[i].nob; j++) printf("%d, ", ft[i].sb + j);
        printf("\n");
    }
}
