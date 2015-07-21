#include "stat.h"

Stat::Stat(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    getStat();
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(clearstat()));
}

void Stat::getStat(){
    stat = ReadFromFile("pl.txt");
    listWidget->addItems(stat);
}

void Stat::clearstat(){
    listWidget->clear();
}
