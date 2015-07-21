#ifndef STAT_H
#define STAT_H

#include "ui_stat.h"
#include "someapi.h"
class Stat : public QDialog, private Ui::Stat
{
    Q_OBJECT
private:
    QList<QString>stat;
    void getStat();
public:
    explicit Stat(QWidget *parent = 0);
private slots:
    void clearstat();
};

#endif // STAT_H
