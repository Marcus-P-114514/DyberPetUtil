#ifndef FONTLOADER_H
#define FONTLOADER_H

#include <QFontDatabase>

int regularFontID = QFontDatabase::addApplicationFont(":/fonts/resources/fonts/SourceHanSansCN-Regular.otf");
QStringList regularFontIDList(QFontDatabase::applicationFontFamilies(regularFontID));
QFont regularFont(regularFontIDList.at(0));

int boldFontID = QFontDatabase::addApplicationFont(":/fonts/resources/fonts/SourceHanSansCN-Bold.otf");
QStringList boldFontIDList(QFontDatabase::applicationFontFamilies(boldFontID));
QFont boldFont(regularFontIDList.at(0));

#endif // FONTLOADER_H
