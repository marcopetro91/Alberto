#ifndef ALBERTO_H
#define ALBERTO_H

#include <QMainWindow>

namespace Ui {
class Alberto;
}

class Alberto : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alberto(QWidget *parent = 0);
    ~Alberto();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Alberto *ui;
};

#endif // ALBERTO_H
