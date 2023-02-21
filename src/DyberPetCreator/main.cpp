#include "dyberpetcreator.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    qputenv("QT_SCALE_FACTOR", "1.5");

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "DyberPetCreator_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    int globalFont = QFontDatabase::addApplicationFont(":/fonts/resources/fonts/SourceHanSansCN-Regular.otf");
    QStringList fontIDList(QFontDatabase::applicationFontFamilies(globalFont));
    QFont SourceHanSansCNRegular(fontIDList.at(0));
    a.setFont(SourceHanSansCNRegular);

    DyberPetCreator w;
    w.show();
    return a.exec();
}
