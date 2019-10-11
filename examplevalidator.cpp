#include "examplevalidator.h"
#include <QChar>
#include <QString>
#include <QRegExp>
#include <QStringList>
#include <QDebug>

using namespace std;

ExampleValidator::ExampleValidator(QObject* parent)
    : QValidator (parent)
{

}

ExampleValidator::~ExampleValidator()
{

}


QValidator::State ExampleValidator::validate(QString &string, int &pos) const{
    QString week ("(неделя|недели|недели)");
    QString day ("(день|дня|дней)");
    QString hour ("(час|часа|часов)");
    QString minute("(минута|минуты|минут)");
    QString second("(секунда|секунды|секунд)");
    QRegExp strong_reg("((\\d неделя|недели|недели)|(\\d день|дня|дней)|(\\d "+ minute +")|(\\d "+ second +")) (\\d "+ week +")|(\\d "+ day +")|(\\d "+ minute +")|(\\d "+ second +"))");

    //выражения для не строгой проверки
    QString l_week ("н?е?д?е?л?я?|н?е?д?е?л?и?|н?е?д?е?л?и?");
    QString l_day ("д?е?н?ь?|д?н?я?|д?н?е?й?");
    QString l_hour ("ч?а?с?|ч?а?с?а?|ч?а?с?о?в?");
    QString l_minute("м?и?н?у?т?а?|м?и?н?у?т?ы?|м?и?н?у?т?");
    QString l_second("с?е?к?у?н?д?а?|с?е?к?у?н?д?ы?|с?е?к?у?н?д?");
    QRegExp light_reg("(\\d? ?(н?е?д?е?л?ь?|н?е?д?е?л?я?))))|(\\d? ?("+ l_day +"))|(\\d? ?("+ l_minute +"))|(\\d? ?("+ l_second +"))) ?(\\d? ?("+ l_week +"))|(\\d? ?("+ l_day +"))|(\\d? ?("+ l_minute +"))|(\\d? ?("+ l_second +")))");


    if(strong_reg.exactMatch(string))
        return QValidator::Acceptable;
    else if(light_reg.exactMatch(string)){
        return QValidator::Intermediate;
    }
    else {
        return QValidator::Invalid;
    }
}
