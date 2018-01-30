#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    const int maxString = 1024;
    const char *fname = "test.txt";
    const char *str = "This is literal C-string\n";
    FILE *fp = NULL;

    printf("Writing data to file\n");
    fp = fopen(fname, "w");

    if (fp) {
        for (int i = 1; i <= 100; i++) {
            fputs(str, fp);
        }
        fclose(fp);
    }

    printf("done writing\n");
    char buf[maxString];
    fp = fopen(fname, "r");

    while (fgets(buf, maxString, fp)) {
        fputs(buf, stdout);
    }

    fclose(fp);
    remove(fname);

    return 0;
}
