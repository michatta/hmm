#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QButtonGroup>
#include <QLineEdit>
#include <QMovie>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void leftButton1_clicked();
    void rightButton1_clicked();
    void leftButton2_clicked();
    void rightButton2_clicked();

    void domesticButton1_clicked();
    void foreignButton1_clicked();
    void domesticButton2_clicked();
    void foreignButton2_clicked();
    void domesticButton3_clicked();
    void foreignButton3_clicked();
    void domesticButton4_clicked();
    void foreignButton4_clicked();

    void brandButton_clicked();
    void typeButton_clicked();
    void ventireButton_clicked();
    void vbrandButton_clicked();
    void vmodelButton_clicked();

    void monthButton1_clicked();
    void periodButton1_clicked();
    void monthButton2_clicked();
    void periodButton2_clicked();
    void monthButton3_clicked();
    void periodButton3_clicked();
    void monthButton4_clicked();
    void periodButton4_clicked();
    void monthButton5_clicked();
    void periodButton5_clicked();

    void pushButton1_clicked();
    void pushButton2_clicked();
    void pushButton3_clicked();
    void pushButton4_clicked();
    void pushButton7_clicked();
    void pushButton9_clicked();
    void pushButton10_clicked();

    void on_startButton_clicked();
    void on_JOIN_clicked();
    void on_FIND_id_clicked();
    void on_FIND_pw_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_18_clicked();
    void on_LOGIN_2_clicked();
    void on_pushButton_11_clicked();
    void on_LOGIN_clicked();
    void on_ID_du_clicked();

    void on_Join_clicked();
    void on_LOGIN_5_clicked();
    void on_LOGIN_3_clicked();
    void on_ID_find2_clicked();
    void on_PW_find2_clicked();
    void on_LOGIN_4_clicked();

    void pushButton5_clicked();
    void pushButton6_clicked();
    void pushButton8_clicked();

    void updateButton();
    void on_checkBox_2_stateChanged(int arg1);
    void on_checkBox_4_stateChanged(int arg1);
    void on_comboBox_activated(int index);

    void on_PW_find_2_clicked();

    void on_pushButton_16_clicked();
    void on_PW_du_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QButtonGroup *brandButtonGroup;
};

#endif // MAINWINDOW_H
