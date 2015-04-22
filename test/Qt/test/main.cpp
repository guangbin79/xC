#include <QCoreApplication>
#include "../../xC-Test.h"

void result_cb(const char * file, int line, const char * description) {

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    xC_API_Test(xMemory, result_cb);

    return a.exec();
}

