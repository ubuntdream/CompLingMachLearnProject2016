#include "csvwriter.h"





CSVWriter::CSVWriter()
{

}

bool CSVWriter::writeToCSV(int callValue, int rolledValue, int formerValue, bool isNewGame){

    //Here it would be possible to ask user where to put csv but for the first time it would be sufficient to code it hard.
    QFile datafile(this->csvdatapath);
    QTextStream stream(&datafile);

    if(datafile.open(QFile::WriteOnly|QFile::Append))
    {
        //catch invalid formervalue in round 1
        if(formerValue > 66){
            formerValue = 0;
        }
        int lier=0;
        if(callValue!=rolledValue){
            lier=1;
        }

        stream << callValue << ";" << rolledValue << ";"<<formerValue<<";"<<isNewGame <<";" <<lier <<"\n";

    }
    datafile.close();
}
