#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <qtextstream.h>
#include <qfile.h>
#include <Model/value.h>

class CSVWriter
{
private:
    QString csvdatapath = "data.csv";
public:
    CSVWriter();

    //writes one observation to csv file
    bool writeToCSV(int, int, int);

    QTextStream readCSV();
};

#endif // CSVWRITER_H
