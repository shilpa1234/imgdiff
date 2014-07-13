#include <QImage>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Bad arguments.\n");
        return 2;
    }
    if (QImage(argv[1]) != QImage(argv[2])) {
        printf("Images differ.\n");
        return 1;
    } else {
        return 0;
    }
}
