#include "options.h"

Options::Options(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    SetWidgets();
}
void Options::SetWidgets(){
    opt = ReadFromFile("pl.txt");
    listWidget->addItems(opt);
}
