#include "pantalla.h"
#include "ui_pantalla.h"

pantalla::pantalla(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pantalla)
{
    ui->setupUi(this);
}

pantalla::~pantalla()
{
    delete ui;
}

