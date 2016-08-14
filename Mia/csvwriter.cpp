#include "csvwriter.h"





CSVWriter::CSVWriter()
{

}

bool CSVWriter::writeToCSV(int callValue, int rolledValue, int formerValue){

    //Here it would be possible to ask user where to put csv but for the first time it would be sufficient to code it hard.
    QFile datafile(this->csvdatapath);
    QTextStream stream(&datafile);
    if(datafile.open(QFile::ReadWrite|QFile::Append))
    {
        int lier=0;
        if(callValue!=rolledValue){
            lier=1;
        }
        stream << callValue << ";" << rolledValue << ";"<<formerValue<<";" <<lier <<"\n";

    }
    datafile.close();
}
