#include "someapi.h"

QList<QString>ReadFromFile(QString filename){
    QFile file(filename);
    QList<QString>list;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return list;
    }
    QTextStream data(&file);
    while(!data.atEnd()){
        QString line = data.readLine();
        list.push_back(line);
    }
    file.close();
    return list;
}

void WriteToFile(QList<QString> list, QString filename){
    QFile file(filename);
    file.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&file);
    QList<QString>::Iterator iter = list.begin();
    while(iter != list.end()){
        out << (QString)iter->data() << "\n";
        iter++;
    }
    file.close();
}

player parsePlayer(QString str){
    player gamer;
    int pos = 0, cpos = 0, last;
    QString name, score;
    int tmp;
    return gamer;
}
