#ifndef DICEVALIDATOR_H
#define DICEVALIDATOR_H

#include <QObject>
#include <QValidator>
#include <QtDebug>

class DiceValidator : public QValidator
{
    Q_OBJECT
public:
    explicit DiceValidator(QObject *parent = 0);
    ~DiceValidator();
    virtual State validate(QString & input, int &pos) const
    {
        State res =Invalid;
        if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6"){
            res= Intermediate;
        }
        else if(input == "11"
                || input == "21" || input == "22"
                || input == "31" || input == "32" || input == "33"
                || input == "41" || input == "42" || input == "43" || input == "44"
                || input == "51" || input == "52" || input == "53" || input == "54" || input == "55"
                || input == "61" || input == "62" || input == "63" || input == "64" || input == "65" || input == "66"){
            res= Acceptable;
        }
        qDebug() << input << " res=" << res;
        return res;
    }

signals:

public slots:
};

#endif // DICEVALIDATOR_H
