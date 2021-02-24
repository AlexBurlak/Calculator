#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

public slots:
    void on_button_number_clicked();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();


private:
    Ui::Calculator *ui;
    QString pendingAdditionOperation;
    QString pendingMultiplicateOperation;
    bool waitingForOperand;
    bool waitingForDot;
    int numberOfUnlockedBrackets;
    QString calc(QString equation);
    QString getSimplierEquation(QString equation);
    QString mltp(QString equation);
    QString sum(QString equation);
};
#endif // CALCULATOR_H
