#include <QImage>

bool isDifferent(const QString &file1, const QString &file2)
{
    QImage img1(file1);
    QImage img2(file2);

    // Check size.
    if (img1.size() != img2.size()) {
        qDebug("Different size - %dx%d vs %dx%d.", img1.width(), img1.height(), img2.width(), img2.height());
        return true;
    }

    int w = img1.width();
    int h = img1.height();
    for (int ii = 0; ii < w; ii++) {
        for (int jj = 0; jj < h; jj++) {
            const QRgb px1 = img1.pixel(ii, jj);
            const QRgb px2 = img2.pixel(ii, jj);
            if (px1 != px2) {
                qDebug("Pixel (%d,%d) differs - (%d,%d,%d,%d) vs (%d,%d,%d,%d).\n",
                       ii, jj,
                       qAlpha(px1), qRed(px1), qGreen(px1), qBlue(px1),
                       qAlpha(px2), qRed(px2), qGreen(px2), qBlue(px2));
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        qDebug("Bad arguments.");
        return 2;
    }

    return isDifferent(argv[1], argv[2]);
}
