#include <QtGui/QApplication>
#include "pandora.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    pandora foo;
    foo.show();
    return app.exec();
}
