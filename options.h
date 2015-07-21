#ifndef OPTIONS_H
#define OPTIONS_H

#include "ui_options.h"
#include "someapi.h"

class Options : public QDialog, private Ui::Options
{
    Q_OBJECT
private:
    QList<QString>opt;
    void SetWidgets();
public:
    explicit Options(QWidget *parent = 0);
};

#endif // OPTIONS_H
