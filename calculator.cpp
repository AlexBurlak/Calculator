#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    ui->textEdit->setReadOnly(true);
    connect(ui->button_0, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_1, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_2, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_3, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_4, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_5, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_6, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_7, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_8, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_9, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    waitingForOperand = true;
    waitingForDot = false;
    numberOfUnlockedBrackets = 0;
}

Calculator::~Calculator()
{
    delete ui;
}



void Calculator::on_button_number_clicked()
{
    QObject* obj = sender();
    if(obj == ui->button_0) {
        if(ui->textEdit->toPlainText() == "") {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "0");
            waitingForDot = true;
        }

        else if(ui->textEdit->toPlainText().back() == "0" && !waitingForOperand) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "0");

        }

        else if (ui->textEdit->toPlainText().back() == ".") {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "0");
            waitingForOperand = false;
        }

        else if(ui->textEdit->toPlainText().back() != "0" && waitingForOperand) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "0");
            waitingForDot = true;
        }
        else if(ui->textEdit->toPlainText().back() != "0" && !waitingForOperand) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "0");
        }
    } else {
        if (obj == ui->button_1) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "1");
            }
        } else if (obj == ui->button_2) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "2");
            }
        } else if (obj == ui->button_3) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "3");
            }
        } else if (obj == ui->button_4) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "4");
            }
        } else if (obj == ui->button_5) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "5");
            }
        } else if (obj == ui->button_6) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "6");
            }
        } else if (obj == ui->button_7) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "7");
            }
        } else if (obj == ui->button_8) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "8");
            }
        } else if (obj == ui->button_9) {
            if(!waitingForDot) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + "9");
            }
        }
        waitingForOperand = false;
    }
}


void Calculator::on_pushButton_clicked()
{

    ui->textEdit->setText("");
    waitingForOperand = true;
}

void Calculator::on_pushButton_2_clicked()
{
    if(!waitingForDot && waitingForOperand) {
        ui->textEdit->setText(ui->textEdit->toPlainText() + "(");
        numberOfUnlockedBrackets++;
        waitingForOperand = true;
    }
}

void Calculator::on_pushButton_3_clicked()
{
    if(numberOfUnlockedBrackets > 0){
        QString equation = ui->textEdit->toPlainText();
        int openBracketPosition = equation.lastIndexOf('(',equation.length()-1);
        int numberOfOperators = 0;
        QString subStringOfEquation = equation.mid(openBracketPosition, equation.length()-1);
        numberOfOperators += subStringOfEquation.count("+") + subStringOfEquation.count("-")
                + subStringOfEquation.count("*") + subStringOfEquation.count("/");

        if((numberOfOperators > 0) && !waitingForOperand ) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + ")");
            numberOfUnlockedBrackets--;
        }
    }
}


void Calculator::on_pushButton_4_clicked()
{
    QRegExp allSignsExp("(\\+|\\-|\\*|\\/|\\(|\\))");
    QString equation = ui->textEdit->toPlainText();
    int signPos = equation.lastIndexOf(allSignsExp);
    if(signPos == -1) {
        equation.insert(0,"-");
    } else if(equation.at(signPos) == "+" || equation.at(signPos) == "-") {
        if(equation.at(signPos) == "+") {
            equation.replace(signPos, 1, "-");
        } else {
            equation.replace(signPos,1, "");
        }
    } else {
        equation.insert(signPos+1,"-");
    }
    ui->textEdit->setText(equation);
}

void Calculator::on_pushButton_21_clicked()
{
    if(!waitingForOperand || waitingForDot){
    ui->textEdit->setText(ui->textEdit->toPlainText() + "/");
    waitingForOperand = true;
    waitingForDot = false;
    }
}

void Calculator::on_pushButton_25_clicked()
{
    if(!waitingForOperand || waitingForDot){
    ui->textEdit->setText(ui->textEdit->toPlainText() + "*");
    waitingForOperand = true;
    waitingForDot = false;
    }
}

void Calculator::on_pushButton_29_clicked()
{
    if(!waitingForOperand || waitingForDot){
    ui->textEdit->setText(ui->textEdit->toPlainText() + "-");
    waitingForOperand = true;
    waitingForDot = false;
    }
}

void Calculator::on_pushButton_33_clicked()
{
    if(!waitingForOperand || waitingForDot){
    ui->textEdit->setText(ui->textEdit->toPlainText() + "+");
    waitingForOperand = true;
    waitingForDot = false;
    }
}

void Calculator::on_pushButton_31_clicked()
{

    if(!waitingForOperand || (waitingForOperand && ui->textEdit->toPlainText().back() == "0")){
    ui->textEdit->setText(ui->textEdit->toPlainText() + ".");
    waitingForOperand = true;
    waitingForDot = false;
    }
}

void Calculator::on_pushButton_32_clicked()
{
    QString resultativeString = getSimplierEquation(ui->textEdit->toPlainText());

    ui->textEdit->setText(resultativeString);
}

QString Calculator::getSimplierEquation(QString equation) {

    int openBracketPosition = equation.indexOf("(");

    while(openBracketPosition != -1) {

            int statPosition = 0;
            QRegExp regEx("(\\(|\\))");
            statPosition = openBracketPosition;
            int numbOfOpenBrackets = 1;
            while(numbOfOpenBrackets > 0) {
                statPosition = equation.indexOf(regEx, statPosition+1);
                if(equation.at(statPosition) == ")") {
                    numbOfOpenBrackets -= 1;
                } else {
                    numbOfOpenBrackets += 1;
                }

            }
            equation.replace(openBracketPosition, statPosition-openBracketPosition+1,
                             getSimplierEquation(equation.mid(openBracketPosition+1, statPosition-openBracketPosition-1)));
            openBracketPosition = equation.indexOf("(");
    }

    int mltpSign = -1;
    QRegExp regEx("(\\*|\\/)");
    mltpSign = equation.indexOf(regEx,0);

    while(mltpSign != -1) {
        int leftSign = -1, rightSign = -1;
        QRegExp addRemoveSigns("(\\+|\\-|\\*|\\/)");
        leftSign = equation.lastIndexOf(addRemoveSigns, mltpSign-1);
        rightSign = equation.indexOf(addRemoveSigns, mltpSign+1);
        if(leftSign == 0) {
            leftSign = -1;
        }
        if(rightSign == -1) {
            rightSign = equation.length();
        }
        if(rightSign - mltpSign == 1) {
            rightSign = equation.indexOf(addRemoveSigns, rightSign+1);
            if(rightSign == -1) {
                rightSign = equation.length();
            }
        }
        equation.replace(leftSign+1,rightSign-leftSign-1,
                        mltp(equation.mid(leftSign+1,rightSign-leftSign-1)));
        mltpSign = equation.indexOf(regEx,0);

    }
    int sumSign = -1;
    QRegExp sumExp("(\\+|\\-)");
    sumSign = equation.indexOf(sumExp,0);
    while(sumSign != -1) {
        int leftSign = -1, rightSign = -1;
        leftSign = equation.lastIndexOf(sumExp,sumSign-1);
        rightSign = equation.indexOf(sumExp, sumSign+1);
        if(leftSign == -1) {
            leftSign = -1;
        } else {
            if(equation.at(leftSign) == "-") {
                leftSign = -1;
            }
        }
        if(rightSign == -1) {
            rightSign = equation.length();
        }
        if(leftSign == sumSign || sumSign == 0) {
            sumSign = equation.indexOf(sumExp,sumSign+1);
            continue;
        }

        equation.replace(leftSign+1,rightSign-leftSign-1,
                        sum(equation.mid(leftSign+1,rightSign-leftSign-1)));
        sumSign = equation.indexOf(sumExp,0);
    }
    return equation;
}

QString Calculator::sum(QString equation) {
    QString answer = "";
    QRegExp sumSign("(\\+|\\-)");
    int signPos = equation.indexOf(sumSign);
    if(signPos == 0) {
        signPos = equation.indexOf(sumSign, signPos + 1);
    }
    if(equation.at(signPos) == "+") {
        double leftNumb = equation.mid(0, signPos).toDouble();
        double rightNumb = equation.mid(signPos+1, equation.length()-1-signPos).toDouble();
        answer = QString::number(leftNumb+rightNumb,'g',9);

    } else if (equation.at(signPos) == "-" ) {
        double leftNumb = equation.mid(0, signPos).toDouble();
        double rightNumb = equation.mid(signPos+1, equation.length()-1-signPos).toDouble();
        answer = QString::number(leftNumb-rightNumb,'g',9);
    }
    else {
        ui->textEdit->setText(equation.at(signPos));
    }
    return answer;
}

QString Calculator::mltp(QString equation) {
    QString answer = "";
    QRegExp mltpSign("(\\*|\\/)");
    int signPos = equation.indexOf(mltpSign);
    if(equation.at(signPos) == "*") {
        double leftNumb = equation.mid(0, signPos).toDouble();
        double rightNumb = equation.mid(signPos+1, equation.length()-1-signPos).toDouble();
        double resNumb = (double)(qRound((leftNumb*rightNumb)*1000))/1000;
        answer = QString::number(resNumb, 'g', 9);
    } else if (equation.at(signPos) == "/" ) {
        double leftNumb = equation.mid(0, signPos).toDouble();
        double rightNumb = equation.mid(signPos+1, equation.length()-1-signPos).toDouble();
        double resNumb = (double)(qRound((leftNumb/rightNumb)*1000))/1000;
        answer = QString::number(resNumb,'g',9);
    }
    else {
        ui->textEdit->setText(equation.at(signPos));
    }
    return answer;
}
