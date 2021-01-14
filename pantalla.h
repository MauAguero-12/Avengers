#ifndef PANTALLA_H
#define PANTALLA_H

#include <QMainWindow>
#include "estructuras.h"

QT_BEGIN_NAMESPACE
namespace Ui { class pantalla; }
QT_END_NAMESPACE

class pantalla : public QMainWindow
{
    Q_OBJECT

public:
    Mundo * mundo;
    pantalla(QWidget *parent = nullptr);
    ~pantalla();

private slots:
    void on_btnGenerarHumanos_clicked();

    void on_btnConsultar_clicked();

    void on_btnConsultarHumanos_clicked();

    void on_btnImprimirArbol_clicked();

    void on_btnCorvusGlaive_clicked();

    void on_btnMidnight_clicked();

    void on_btnNebula_clicked();

    void on_btnEbonyMaw_clicked();

    void on_btnBlackDwarf_clicked();

    void on_btnThanos_clicked();

    void on_btnConsultaVillanos_clicked();

    void on_btnAntMan_clicked();

    void on_btnIronMan_clicked();

    void on_btnThor_clicked();

    void on_btnSpiderman_clicked();

    void on_btnConsultarVengadores_clicked();

    void on_btnConsultarDeporte_clicked();

private:

    Ui::pantalla *ui;
};
#endif // PANTALLA_H
