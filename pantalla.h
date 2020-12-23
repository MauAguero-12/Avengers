#ifndef PANTALLA_H
#define PANTALLA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class pantalla; }
QT_END_NAMESPACE

class pantalla : public QMainWindow
{
    Q_OBJECT

public:
    pantalla(QWidget *parent = nullptr);
    ~pantalla();

private:
    Ui::pantalla *ui;
};
#endif // PANTALLA_H
