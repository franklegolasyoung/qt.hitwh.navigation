#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

namespace Ui {
class welcome;
}

class welcome : public QWidget
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = 0);
    ~welcome();

private:
    Ui::welcome *ui;
};

#endif // WELCOME_H
