#include <stdio.h>
#include <string.h>

int main(void) {
    char a[1005], b[1005];
    while (scanf("%s %s", a, b) == 2) {
        if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0) break;
        int la = strlen(a), lb = strlen(b);
        if (la == 0 || lb == 0) {
            printf("No\n");
            continue;
        }
        int va = a[la-1] - 'a';
        int vb = b[lb-1] - 'a';
        if (((va + vb) & 1) == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}