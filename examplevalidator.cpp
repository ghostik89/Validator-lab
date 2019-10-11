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
    QRegExp strong_reg("((\\d+ ((неделя)|(недель)|(недели)) ?)|(\\d+ ((день)|(дня)|(дней)) ?)|(\\d+ ((час)|(часа)|(часов)) ?)|(\\d+ ((минута)|(минуты)|(минут)) ?)|(\\d+ ((секунда)|(секунды)|(секунд)) ?)){1,2}");

    //выражения для не строгой проверки
    QRegExp light_reg("((\\d* ?(н?е?д?е?л?я?ь?и?) ?)|(\\d* ?((д?е?н?ь?)|(д?н?я?е?й?)) ?)|(\\d* ?(ч?а?с?а?о?в?) ?)|(\\d* ?(м?и?н?у?т?а?ы?) ?)|(\\d* ?(с?е?к?у?н?д?а?ы?))){0,2}");


    if(strong_reg.exactMatch(string))
        return QValidator::Acceptable;
    else if(light_reg.exactMatch(string)){
        return QValidator::Intermediate;
    }
    else {
        return QValidator::Invalid;
    }
}
