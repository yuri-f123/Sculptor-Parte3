#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief A classe MainWindow - A janela principal do programa
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    /**
     * @brief salvar - slot que chama a função que salva o desenho feito
     */
    void salvar(void);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
