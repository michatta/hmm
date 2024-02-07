#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>

//내용 추가
//소스코드 변경
//함수든 뭐든 추가한다고 가정해봅시다.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->statusbar->setSizeGripEnabled(false);
    ui->stackedWidget->setCurrentIndex(1); // 메인 페이지 시작
    ui->stackedWidget_1->setCurrentIndex(2); // view_entire 시작
    ui->stackedWidget_2->setCurrentIndex(0); // 브랜드 버튼 현대 시작
    ui->stackedWidget_3->setCurrentIndex(0); // search_by_brand,search_by_month 시작
    ui->stackedWidget_4->setCurrentIndex(0); // 차종 버튼 경차 시작
    ui->stackedWidget_5->setCurrentIndex(0); // search_by_type,search_by_month 시작
    ui->stackedWidget_6->setCurrentIndex(0); // view_entire,search_by_month 시작
    ui->stackedWidget_7->setCurrentIndex(0); // view_brand,search_by_month 시작
    ui->stackedWidget_8->setCurrentIndex(0); // brand_top3,domestic_car 시작
    ui->stackedWidget_9->setCurrentIndex(0); // model_top5,domestic_car 시작
    ui->stackedWidget_11->setCurrentIndex(0); // model_top5, dome
    ui->stackedWidget_10->setCurrentIndex(0); // brand_top3,domestic_car 시작stic_car 시작
    ui->stackedWidget_12->setCurrentIndex(0); // view_model, search_by_month 시작

    ui->toolButton_ventire->setStyleSheet("QToolButton{background-color:rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_month_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_month_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_month_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_month_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_month_5->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_domestic_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_domestic_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_domestic_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_domestic_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");

    // 테이블 헤더 사이즈 조절
    ui->tableWidget_1->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_1->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_1->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_1->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_2->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_2->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_2->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_2->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_3->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_3->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_3->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_3->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_4->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_4->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_4->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_4->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_5->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_5->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_5->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_5->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_6->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_6->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_6->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_6->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_7->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_7->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_7->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_7->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_8->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_8->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_8->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_8->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_9->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_9->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_9->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_9->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_10->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_10->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_10->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_10->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_11->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_11->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_11->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_11->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_12->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_12->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_12->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_12->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_13->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_13->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_13->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_13->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_14->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_14->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_14->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_14->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_15->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_15->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_15->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_15->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_16->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_16->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_16->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_16->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_17->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_17->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_17->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_17->horizontalHeader()->resizeSection(3, 70);
    ui->tableWidget_18->horizontalHeader()->resizeSection(0, 40);
    ui->tableWidget_18->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_18->horizontalHeader()->resizeSection(2, 70);
    ui->tableWidget_18->horizontalHeader()->resizeSection(3, 70);

    // 데이터베이스에 연결
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db");

    if (!db.open())
        qDebug() << "Database connection failed:" << db.lastError().text();
    else
        qDebug() << "Database connected successfully!";

    connect(ui->toolButton_left_1, &QPushButton::clicked, this, &MainWindow::leftButton1_clicked); // 브랜드 왼쪽 클릭
    connect(ui->toolButton_right_1, &QPushButton::clicked, this, &MainWindow::rightButton1_clicked); // 브랜드 오른쪽 클릭
    connect(ui->toolButton_left_2, &QPushButton::clicked, this, &MainWindow::leftButton2_clicked); // 차종 왼쪽 클릭
    connect(ui->toolButton_right_2, &QPushButton::clicked, this, &MainWindow::rightButton2_clicked); // 차종 오른쪽 클릭

    connect(ui->toolButton_domestic_1, &QPushButton::clicked, this, &MainWindow::domesticButton1_clicked); // top3 국산차 클릭
    connect(ui->toolButton_foreign_1, &QPushButton::clicked, this, &MainWindow::foreignButton1_clicked); // top3 수입차 클릭
    connect(ui->toolButton_domestic_2, &QPushButton::clicked, this, &MainWindow::domesticButton2_clicked); // top5 국산차 클릭
    connect(ui->toolButton_foreign_2, &QPushButton::clicked, this, &MainWindow::foreignButton2_clicked); // top5 수입차 클릭
    connect(ui->toolButton_domestic_3, &QPushButton::clicked, this, &MainWindow::domesticButton3_clicked); // top3 국산차 클릭
    connect(ui->toolButton_foreign_3, &QPushButton::clicked, this, &MainWindow::foreignButton3_clicked); // top3 수입차 클릭
    connect(ui->toolButton_domestic_4, &QPushButton::clicked, this, &MainWindow::domesticButton4_clicked); // top5 국산차 클릭
    connect(ui->toolButton_foreign_4, &QPushButton::clicked, this, &MainWindow::foreignButton4_clicked); // top5 수입차 클릭

    connect(ui->toolButton_month_1, &QPushButton::clicked, this, &MainWindow::monthButton1_clicked); // 브랜드 월별 클릭
    connect(ui->toolButton_period_1, &QPushButton::clicked, this, &MainWindow::periodButton1_clicked); // 브랜드 기간별 클릭
    connect(ui->toolButton_month_2, &QPushButton::clicked, this, &MainWindow::monthButton2_clicked); // 차종 월별 클릭
    connect(ui->toolButton_period_2, &QPushButton::clicked, this, &MainWindow::periodButton2_clicked); // 차종 기간별 클릭
    connect(ui->toolButton_month_3, &QPushButton::clicked, this, &MainWindow::monthButton3_clicked); // view_entire 월별 클릭
    connect(ui->toolButton_period_3, &QPushButton::clicked, this, &MainWindow::periodButton3_clicked); // view_entire 기간별 클릭
    connect(ui->toolButton_month_4, &QPushButton::clicked, this, &MainWindow::monthButton4_clicked); // view_brand 월별 클릭
    connect(ui->toolButton_period_4, &QPushButton::clicked, this, &MainWindow::periodButton4_clicked); // view_brand 기간별 클릭
    connect(ui->toolButton_month_5, &QPushButton::clicked, this, &MainWindow::monthButton5_clicked); // view_model 월별 클릭
    connect(ui->toolButton_period_5, &QPushButton::clicked, this, &MainWindow::periodButton5_clicked); // view_model 기간별 클릭

    connect(ui->toolButton_brand, &QPushButton::clicked, this, &MainWindow::brandButton_clicked); // 브랜드별 클릭
    connect(ui->toolButton_type, &QPushButton::clicked, this, &MainWindow::typeButton_clicked); // 차종별 클릭
    connect(ui->toolButton_ventire, &QPushButton::clicked, this, &MainWindow::ventireButton_clicked); // 전체뷰 클릭
    connect(ui->toolButton_vbrand, &QPushButton::clicked, this, &MainWindow::vbrandButton_clicked); // 브랜드뷰 클릭
    connect(ui->toolButton_vmodel, &QPushButton::clicked, this, &MainWindow::vmodelButton_clicked); // 브랜드뷰 클릭

    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::pushButton1_clicked); // 브랜드 월별 검색 클릭
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::pushButton2_clicked); // 브랜드 기간별 검색 클릭
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::pushButton3_clicked); // 차종 월별 검색 클릭
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::pushButton4_clicked); // 차종 기간별 검색 클릭
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::pushButton5_clicked); // view_entire 월별 검색 클릭
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::pushButton6_clicked); // view_entire 기간별 검색 클릭
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::pushButton7_clicked); // view_brand 월별 검색 클릭
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::pushButton8_clicked); // view_brand 기간별 검색 클릭
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::pushButton9_clicked); // view_model 월별 검색 클릭
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::pushButton10_clicked); // view_model 기간별 검색 클릭

    //버튼 클릭 그룹 중복 선택 x
    brandButtonGroup = new QButtonGroup(this);
    brandButtonGroup->setExclusive(true);

    brandButtonGroup->addButton(ui->toolButton_hyundai);
    brandButtonGroup->addButton(ui->toolButton_kia);
    brandButtonGroup->addButton(ui->toolButton_genesis);
    brandButtonGroup->addButton(ui->toolButton_chevrolet);
    brandButtonGroup->addButton(ui->toolButton_kg_mobility);
    brandButtonGroup->addButton(ui->toolButton_renaul_korea);
    brandButtonGroup->addButton(ui->toolButton_benz);
    brandButtonGroup->addButton(ui->toolButton_bmw);
    brandButtonGroup->addButton(ui->toolButton_volvo);
    brandButtonGroup->addButton(ui->toolButton_volkswagen);
    brandButtonGroup->addButton(ui->toolButton_audi);
    brandButtonGroup->addButton(ui->toolButton_lexus);
    brandButtonGroup->addButton(ui->toolButton_light_car);
    brandButtonGroup->addButton(ui->toolButton_small_car);
    brandButtonGroup->addButton(ui->toolButton_semi_mid_car);
    brandButtonGroup->addButton(ui->toolButton_mid_car);
    brandButtonGroup->addButton(ui->toolButton_semi_large_car);
    brandButtonGroup->addButton(ui->toolButton_large_car);
    brandButtonGroup->addButton(ui->toolButton_sports_car);
    brandButtonGroup->addButton(ui->toolButton_small_suv);
    brandButtonGroup->addButton(ui->toolButton_mid_suv);
    brandButtonGroup->addButton(ui->toolButton_large_suv);
    brandButtonGroup->addButton(ui->toolButton_rv_mpv);
    brandButtonGroup->addButton(ui->toolButton_commercial);

    ui->Join->setEnabled(false);
    ui->comboBox->setCurrentIndex(0);
    //수정된 부분
    ui->checkBox_2->setEnabled(false);
    ui->checkBox_4->setEnabled(false);

    connect(ui->Join_pw2, &QLineEdit::editingFinished, this, &MainWindow::on_PW_du_clicked);

    QMovie*Movie = new QMovie("C:/Users/IOT/Desktop/project/untitled_mk7/ad.gif"); //광고 띄우기
    ui->ad->setMovie(Movie);
    Movie->setScaledSize(QSize(371,91));
    Movie->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::leftButton1_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::rightButton1_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::leftButton2_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::rightButton2_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::domesticButton1_clicked()
{
    ui->toolButton_domestic_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_foreign_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_8->setCurrentIndex(0);
}

void MainWindow::foreignButton1_clicked()
{
    ui->toolButton_foreign_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_domestic_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_8->setCurrentIndex(1);
}

void MainWindow::domesticButton2_clicked()
{
    ui->toolButton_domestic_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_foreign_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_9->setCurrentIndex(0);
}

void MainWindow::foreignButton2_clicked()
{
    ui->toolButton_foreign_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_domestic_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_9->setCurrentIndex(1);
}

void MainWindow::domesticButton3_clicked()
{
    ui->toolButton_domestic_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_foreign_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_10->setCurrentIndex(0);
}

void MainWindow::foreignButton3_clicked()
{
    ui->toolButton_foreign_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_domestic_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_10->setCurrentIndex(1);
}

void MainWindow::domesticButton4_clicked()
{
    ui->toolButton_domestic_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_foreign_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_11->setCurrentIndex(0);
}

void MainWindow::foreignButton4_clicked()
{
    ui->toolButton_foreign_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_domestic_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_11->setCurrentIndex(1);
}

void MainWindow::brandButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0); // 브랜드 버튼 현대 시작
    ui->tableWidget_1->clearContents();
    ui->tableWidget_2->clearContents();
    ui->label_image->setText("IMAGE");
    ui->label_sales->setText("-");
    ui->label_premonth->setText("-");
    ui->label_preyear->setText("-");
    ui->label_premonthtri->setText("");
    ui->label_preyeartri->setText("");
    ui->label_minusmonth->setText("");
    ui->label_minusyear->setText("");
    ui->toolButton_brand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_type->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_ventire->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_vbrand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_vmodel->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_1->setCurrentIndex(0);
}

void MainWindow::typeButton_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0); // 차종 버튼 경차 시작
    ui->tableWidget_3->clearContents();
    ui->tableWidget_4->clearContents();
    ui->toolButton_type->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_brand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_ventire->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_vbrand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_vmodel->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_1->setCurrentIndex(1);
}

void MainWindow::ventireButton_clicked()
{
    ui->tableWidget_5->clearContents();
    ui->tableWidget_6->clearContents();
    ui->tableWidget_7->clearContents();
    ui->tableWidget_8->clearContents();
    ui->tableWidget_9->clearContents();
    ui->tableWidget_10->clearContents();
    ui->tableWidget_11->clearContents();
    ui->tableWidget_12->clearContents();
    ui->toolButton_ventire->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_vbrand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_vmodel->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_brand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_type->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_1->setCurrentIndex(2);
}

void MainWindow::vbrandButton_clicked()
{
    ui->tableWidget_13->clearContents();
    ui->tableWidget_14->clearContents();
    ui->tableWidget_15->clearContents();
    ui->tableWidget_16->clearContents();
    ui->toolButton_vbrand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_ventire->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_vmodel->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_brand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_type->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_1->setCurrentIndex(3);
}

void MainWindow::vmodelButton_clicked()
{
    ui->tableWidget_17->clearContents();
    ui->tableWidget_18->clearContents();
    ui->toolButton_vmodel->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_ventire->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_vbrand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_brand->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_type->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_1->setCurrentIndex(4);
}

void MainWindow::monthButton1_clicked()
{
    ui->tableWidget_1->clearContents();
    ui->label_image->setText("IMAGE");
    ui->label_sales->setText("-");
    ui->label_premonth->setText("-");
    ui->label_preyear->setText("-");
    ui->label_premonthtri->setText("");
    ui->label_preyeartri->setText("");
    ui->label_minusmonth->setText("");
    ui->label_minusyear->setText("");
    ui->tableWidget_1->clearContents();
    ui->toolButton_month_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_period_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::periodButton1_clicked()
{
    ui->tableWidget_2->clearContents();
    ui->toolButton_month_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_period_1->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::monthButton2_clicked()
{
    ui->tableWidget_3->clearContents();
    ui->toolButton_month_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_period_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::periodButton2_clicked()
{
    ui->tableWidget_4->clearContents();
    ui->toolButton_month_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_period_2->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::monthButton3_clicked()
{
    ui->tableWidget_5->clearContents();
    ui->tableWidget_6->clearContents();
    ui->tableWidget_7->clearContents();
    ui->tableWidget_8->clearContents();
    ui->toolButton_month_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_period_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_6->setCurrentIndex(0);
}

void MainWindow::periodButton3_clicked()
{
    ui->tableWidget_9->clearContents();
    ui->tableWidget_10->clearContents();
    ui->tableWidget_11->clearContents();
    ui->tableWidget_12->clearContents();
    ui->toolButton_month_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_period_3->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->stackedWidget_6->setCurrentIndex(1);
}

void MainWindow::monthButton4_clicked()
{
    ui->tableWidget_13->clearContents();
    ui->tableWidget_14->clearContents();
    ui->toolButton_month_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_period_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_7->setCurrentIndex(0);
}

void MainWindow::periodButton4_clicked()
{
    ui->tableWidget_15->clearContents();
    ui->tableWidget_16->clearContents();
    ui->toolButton_month_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_period_4->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->stackedWidget_7->setCurrentIndex(1);
}

void MainWindow::monthButton5_clicked()
{
    ui->tableWidget_17->clearContents();
    ui->toolButton_month_5->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->toolButton_period_5->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->stackedWidget_12->setCurrentIndex(0);
}

void MainWindow::periodButton5_clicked()
{
    ui->tableWidget_18->clearContents();
    ui->toolButton_month_5->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:normal;}");
    ui->toolButton_period_5->setStyleSheet("QToolButton{background-color: rgb(0,0,0,0);font-weight:bold;color:blue;}");
    ui->stackedWidget_12->setCurrentIndex(1);
}

void MainWindow::pushButton1_clicked()
{
    // 툴버튼 및 콤보박스 선택 항목 저장
    QString brand;
    if (ui->toolButton_hyundai->isChecked())
        brand = "HYUNDAI";
    else if (ui->toolButton_kia->isChecked())
        brand = "KIA";
    else if (ui->toolButton_genesis->isChecked())
        brand = "GENESIS";
    else if (ui->toolButton_chevrolet->isChecked())
        brand = "CHEVROLET";
    else if (ui->toolButton_kg_mobility->isChecked())
        brand = "KG_MOBILITY";
    else if (ui->toolButton_renaul_korea->isChecked())
        brand = "RENAUL_KOREA";
    else if (ui->toolButton_benz->isChecked())
        brand = "BENZ";
    else if (ui->toolButton_bmw->isChecked())
        brand = "BMW";
    else if (ui->toolButton_audi->isChecked())
        brand = "AUDI";
    else if (ui->toolButton_volvo->isChecked())
        brand = "VOLVO";
    else if (ui->toolButton_volkswagen->isChecked())
        brand = "VOLKSWAGEN";
    else if (ui->toolButton_lexus->isChecked())
        brand = "LEXUS";


    QString year = ui->comboBox_year_1->currentText();
    QString month = ui->comboBox_month_1->currentText();
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";
    QString tempyear;
    if (month == "01")
    {
        if (year == "2023")
            tempyear = "2022";
        else if (year == "2022")
            tempyear = "2021";
        else if (year == "2021")
            tempyear = "2020";
        else if (year == "2020")
            tempyear = "2019";
    }
    else
        tempyear = year;

    qDebug() << "Selected Brand:" << brand;
    qDebug() << "Selected Year:" << year;
    qDebug() << "Selected Month:" << month;

    // 쿼리문 실행
    QSqlQuery query1;
    QString query1String = "SELECT model, " + monthlist[month.toInt()] + year + " FROM " + brand + " WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND (" + monthlist[month.toInt()] + year + ") <> 0) ORDER BY " + monthlist[month.toInt()] + year + " DESC";
    qDebug() << query1String;

    if (!query1.exec(query1String))
    {
        qDebug() << "Query execution failed:" << query1.lastError().text();
        QMessageBox::warning(this,"","브랜드를 선택해주시고 조회바랍니다.");
        return;
    }

    QSqlQuery query2;
    QString query2String = "SELECT " + monthlist[month.toInt() - 1] + tempyear + ", " + monthlist[month.toInt()] + QString::number(year.toInt() - 1) + " FROM ALL_SALES WHERE brand = '" + brand + "'";

    if (!query2.exec(query2String))
    {
        qDebug() << "Query execution failed:" << query2.lastError().text();
        return;
    }

    // 이미지 삽입
    QPixmap hyundaiImage("hyundai.png");
    QPixmap kiaImage("kia.png");
    QPixmap genesisImage("genesis.png");
    QPixmap chevroletImage("chevrolet.png");
    QPixmap kg_mobilityImage("kg_mobility.png");
    QPixmap renaul_koreaImage("renaul_korea.png");
    QPixmap benzImage("benz.png");
    QPixmap bmwImage("bmw.png");
    QPixmap audiImage("audi.png");
    QPixmap volvoImage("volvo.png");
    QPixmap volkswagenImage("volkswagen.png");
    QPixmap lexusImage("lexus.png");

    if (brand == "HYUNDAI")
        ui->label_image->setPixmap(hyundaiImage.scaled(ui->label_image->size()));
    else if (brand == "KIA")
        ui->label_image->setPixmap(kiaImage.scaled(ui->label_image->size()));
    else if (brand == "GENESIS")
        ui->label_image->setPixmap(genesisImage.scaled(ui->label_image->size()));
    else if (brand == "CHEVROLET")
        ui->label_image->setPixmap(chevroletImage.scaled(ui->label_image->size()));
    else if (brand == "KG_MOBILITY")
        ui->label_image->setPixmap(kg_mobilityImage.scaled(ui->label_image->size()));
    else if (brand == "RENAUL_KOREA")
        ui->label_image->setPixmap(renaul_koreaImage.scaled(ui->label_image->size()));
    else if (brand == "BENZ")
        ui->label_image->setPixmap(benzImage.scaled(ui->label_image->size()));
    else if (brand == "BMW")
        ui->label_image->setPixmap(bmwImage.scaled(ui->label_image->size()));
    else if (brand == "AUDI")
        ui->label_image->setPixmap(audiImage.scaled(ui->label_image->size()));
    else if (brand == "VOLVO")
        ui->label_image->setPixmap(volvoImage.scaled(ui->label_image->size()));
    else if (brand == "VOLKSWAGEN")
        ui->label_image->setPixmap(volkswagenImage.scaled(ui->label_image->size()));
    else if (brand == "LEXUS")
        ui->label_image->setPixmap(lexusImage.scaled(ui->label_image->size()));

    // 테이블 초기화
    ui->tableWidget_1->clearContents();
    ui->tableWidget_1->setRowCount(0);

    // 테이블에 데이터 삽입
    int row = 0;
    while (query1.next())
    {
        QString model = query1.value(0).toString();
        QString sales = query1.value(1).toString();

        ui->tableWidget_1->insertRow(row);
        ui->tableWidget_1->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_1->setItem(row, 1, new QTableWidgetItem(model));
        ui->tableWidget_1->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_1->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_1->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }
    ui->label_sales->setText(QString::number(salessum));
    query2.next();

    // 전월, 전년 판매량 라벨에 삽입
    QString premonthsum = query2.value(0).toString();
    QString preyearsum = query2.value(1).toString();
    ui->label_premonth->setText(premonthsum);
    ui->label_preyear->setText(preyearsum);

    int minusmonth = salessum - premonthsum.toInt();
    if (minusmonth > 0) // 빨강
    {
        ui->label_premonthtri->setStyleSheet("QLabel{color:red;}");
        ui->label_minusmonth->setStyleSheet("QLabel{color:red;}");
        ui->label_premonthtri->setText("▲");
        ui->label_minusmonth->setText(QString::number(minusmonth));
    }
    else if (minusmonth < 0) // 파랑
    {
        ui->label_premonthtri->setStyleSheet("QLabel{color:blue;}");
        ui->label_minusmonth->setStyleSheet("QLabel{color:blue;}");
        ui->label_premonthtri->setText("▼");
        ui->label_minusmonth->setText(QString::number(minusmonth * (-1)));
    }

    int minusyear = salessum - preyearsum.toInt();
    if (minusyear > 0) // 빨강
    {
        ui->label_preyeartri->setStyleSheet("QLabel{color:red;}");
        ui->label_minusyear->setStyleSheet("QLabel{color:red;}");
        ui->label_preyeartri->setText("▲");
        ui->label_minusyear->setText(QString::number(minusyear));
    }
    else if (minusyear < 0) // 파랑
    {
        ui->label_preyeartri->setStyleSheet("QLabel{color:blue;}");
        ui->label_minusyear->setStyleSheet("QLabel{color:blue;}");
        ui->label_preyeartri->setText("▼");
        ui->label_minusyear->setText(QString::number(minusyear * (-1)));
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_1->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_1->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_1->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_1->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_1->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_1->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_1->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_1->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_1->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::pushButton2_clicked()
{
    // 툴버튼 및 콤보박스 선택 항목 저장
    QString brand;
    if (ui->toolButton_hyundai->isChecked())
        brand = "HYUNDAI";
    else if (ui->toolButton_kia->isChecked())
        brand = "KIA";
    else if (ui->toolButton_genesis->isChecked())
        brand = "GENESIS";
    else if (ui->toolButton_chevrolet->isChecked())
        brand = "CHEVROLET";
    else if (ui->toolButton_kg_mobility->isChecked())
        brand = "KG_MOBILITY";
    else if (ui->toolButton_renaul_korea->isChecked())
        brand = "RENAUL_KOREA";
    else if (ui->toolButton_benz->isChecked())
        brand = "BENZ";
    else if (ui->toolButton_bmw->isChecked())
        brand = "BMW";
    else if (ui->toolButton_audi->isChecked())
        brand = "AUDI";
    else if (ui->toolButton_volvo->isChecked())
        brand = "VOLVO";
    else if (ui->toolButton_volkswagen->isChecked())
        brand = "VOLKSWAGEN";
    else if (ui->toolButton_lexus->isChecked())
        brand = "LEXUS";
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";
    int firstyear = ui->comboBox_firstyear_1->currentText().toInt();
    int firstmonth = ui->comboBox_firstmonth_1->currentText().toInt();
    int secondyear = ui->comboBox_secondyear_1->currentText().toInt();
    int secondmonth = ui->comboBox_secondmonth_1->currentText().toInt();

    QString period;
    if (firstyear == secondyear) // 첫 번째, 두 번째 선택 년 같을 경우
    {
        if (firstmonth <= secondmonth) // 첫 번째 선택 월이 두 번째 선택 월보다 작거나 같을 경우
        {
            for (int i = firstmonth; i <= secondmonth; i++) // 첫 번째 선택 월 ~ 두 번째 선택 월 반복
            {
                if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                    period += monthlist[i] + QString::number(firstyear);
                else
                    period += monthlist[i] + QString::number(firstyear) + " + ";
            }
        }
        else // 첫 번째 선택 월이 두 번째 선택 월보다 클 경우
        {
            QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
            ui->tableWidget_2->clearContents();
            return;
        }
    }
    else if (firstyear < secondyear) // 첫 번째 선택 년이 두 번째 선택 년보다 작을 경우
    {
        for (int i = firstmonth; i <= 12; i++) // 첫 번째 선택 년의 선택 월 ~ 12월 반복
            period += monthlist[i] + QString::number(firstyear) + " + ";
        for (int i = 1; i <= secondmonth; i++) // 두 번째 선택 년의 1월 ~ 선택 월 반복
        {
            if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                period += monthlist[i] + QString::number(secondyear);
            else
                period += monthlist[i] + QString::number(secondyear) + " + ";
        }
    }
    else // 첫 번째 선택 월이 두 번째 선택 월보다 클 경우
    {
        QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
        ui->tableWidget_2->clearContents();
        return;
    }
    // 쿼리문 실행
    QSqlQuery query;
    QString queryString = "SELECT model, " + period + " FROM " + brand + " WHERE ((" + period + ") <> 0 AND LENGTH(" + period + ") > 0) ORDER BY " + period + " DESC";
    if (!query.exec(queryString))
    {
        qDebug() << "Query execution failed:" << query.lastError().text();
        QMessageBox::warning(this,"","브랜드를 선택해주시고 조회해주시길 바랍니다.");
        return;
    }

    // 테이블 초기화
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);

    // 테이블에 데이터 삽입
    int row = 0;
    while (query.next())
    {
        QString model = query.value(0).toString();
        QString sales = query.value(1).toString();

        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(model));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_2->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_2->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_2->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_2->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_2->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::pushButton3_clicked()
{
    // 툴버튼 및 콤보박스 선택 항목 저장
    QString type;
    if (ui->toolButton_light_car->isChecked())
        type = "light_car";
    else if (ui->toolButton_small_car->isChecked())
        type = "small_car";
    else if (ui->toolButton_semi_mid_car->isChecked())
        type = "semi_mid_car";
    else if (ui->toolButton_mid_car->isChecked())
        type = "mid_car";
    else if (ui->toolButton_semi_large_car->isChecked())
        type = "semi_large_car";
    else if (ui->toolButton_large_car->isChecked())
        type = "large_car";
    else if (ui->toolButton_sports_car->isChecked())
        type = "sports_car";
    else if (ui->toolButton_small_suv->isChecked())
        type = "small_suv";
    else if (ui->toolButton_mid_suv->isChecked())
        type = "mid_suv";
    else if (ui->toolButton_large_suv->isChecked())
        type = "large_suv";
    else if (ui->toolButton_rv_mpv->isChecked())
        type = "mpv";
    else if (ui->toolButton_commercial->isChecked())
        type = "commercial";
    QString year = ui->comboBox_year_2->currentText();
    QString month = ui->comboBox_month_2->currentText();
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";

    qDebug() << "Selected Type:" << type;
    qDebug() << "Selected Year:" << year;
    qDebug() << "Selected Month:" << month;

    // 쿼리문 실행
    QSqlQuery query;
    QString queryString = "SELECT model, " + monthlist[month.toInt()] + year + " FROM HYUNDAI WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM KIA WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM GENESIS WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM CHEVROLET WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM KG_MOBILITY WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM RENAUL_KOREA WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM BENZ WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM BMW WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM AUDI WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM VOLVO WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM VOLKSWAGEN WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM LEXUS WHERE (type = '" + type + "' AND LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "ORDER BY " + monthlist[month.toInt()] + year + " DESC";

    if (!query.exec(queryString))
    {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return;
    }

    if(type=="")
    {
        QMessageBox::warning(this,"","차종을 선택해주시고 조회해주시길 바랍니다.");
    }
    // 테이블 초기화
    ui->tableWidget_3->clearContents();
    ui->tableWidget_3->setRowCount(0);

    // 테이블에 데이터 삽입
    int row = 0;
    while (query.next())
    {
        QString model = query.value(0).toString();
        QString sales = query.value(1).toString();

        ui->tableWidget_3->insertRow(row);
        ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(model));
        ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    //테이블 기록x 출력
    if(!ui->tableWidget_3->item(0,0) && type !="")
    {
        qDebug()<<"can't search";
        QMessageBox::information(this,"","검색되는 기록이 없습니다.");
        ui->tableWidget_3->clearContents();
    }

    // 총 판매량 저장 및 라벨에 삽입
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_3->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_3->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_3->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_3->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_3->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_3->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_3->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_3->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_3->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_3->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_3->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::pushButton4_clicked()
{
    // 툴버튼 및 콤보박스 선택 항목 저장
    QString type;
    if (ui->toolButton_light_car->isChecked())
        type = "light_car";
    else if (ui->toolButton_small_car->isChecked())
        type = "small_car";
    else if (ui->toolButton_semi_mid_car->isChecked())
        type = "semi_mid_car";
    else if (ui->toolButton_mid_car->isChecked())
        type = "mid_car";
    else if (ui->toolButton_semi_large_car->isChecked())
        type = "semi_large_car";
    else if (ui->toolButton_large_car->isChecked())
        type = "large_car";
    else if (ui->toolButton_sports_car->isChecked())
        type = "sports_car";
    else if (ui->toolButton_small_suv->isChecked())
        type = "small_suv";
    else if (ui->toolButton_mid_suv->isChecked())
        type = "mid_suv";
    else if (ui->toolButton_large_suv->isChecked())
        type = "large_suv";
    else if (ui->toolButton_rv_mpv->isChecked())
        type = "mpv";
    else if (ui->toolButton_commercial->isChecked())
        type = "commercial";
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";
    int firstyear = ui->comboBox_firstyear_2->currentText().toInt();
    int firstmonth = ui->comboBox_firstmonth_2->currentText().toInt();
    int secondyear = ui->comboBox_secondyear_2->currentText().toInt();
    int secondmonth = ui->comboBox_secondmonth_2->currentText().toInt();

    QString period;
    if (firstyear == secondyear) // 첫 번째, 두 번째 선택 년 같을 경우
    {
        if (firstmonth <= secondmonth) // 첫 번째 선택 월이 두 번째 선택 월보다 작거나 같을 경우
        {
            for (int i = firstmonth; i <= secondmonth; i++) // 첫 번째 선택 월 ~ 두 번째 선택 월 반복
            {
                if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                    period += monthlist[i] + QString::number(firstyear);
                else
                    period += monthlist[i] + QString::number(firstyear) + " + ";
            }
        }
        else // 첫 번째 선택 월이 두 번째 선택 월보다 클 경우
        {
            QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
            ui->tableWidget_4->clearContents();
            return;
        }
    }
    else if (firstyear < secondyear) // 첫 번째 선택 년이 두 번째 선택 년보다 작을 경우
    {
        for (int i = firstmonth; i <= 12; i++) // 첫 번째 선택 년의 선택 월 ~ 12월 반복
            period += monthlist[i] + QString::number(firstyear) + " + ";
        for (int i = 1; i <= secondmonth; i++) // 두 번째 선택 년의 1월 ~ 선택 월 반복
        {
            if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                period += monthlist[i] + QString::number(secondyear);
            else
                period += monthlist[i] + QString::number(secondyear) + " + ";
        }
    }
    else // 첫 번째 선택 년이 두 번째 선택 년보다 클 경우
    {
        QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
        ui->tableWidget_4->clearContents();
        return;
    }
    // 쿼리문 실행
    QSqlQuery query;
    QString queryString = "SELECT model, " + period + " FROM HYUNDAI WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM KIA WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM GENESIS WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM CHEVROLET WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM KG_MOBILITY WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM RENAUL_KOREA WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM BENZ WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM BMW WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM AUDI WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM VOLVO WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM VOLKSWAGEN WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM LEXUS WHERE (type = '" + type + "' AND LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "ORDER BY " + period + " DESC";
    if (!query.exec(queryString))
    {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return;
    }

    if(type=="")
    {
        QMessageBox::warning(this,"","차종을 선택해주시고 조회해주시길 바랍니다.");
    }
    // 테이블 초기화
    ui->tableWidget_4->clearContents();
    ui->tableWidget_4->setRowCount(0);

    // 테이블에 데이터 삽입
    int row = 0;
    while (query.next())
    {
        QString model = query.value(0).toString();
        QString sales = query.value(1).toString();

        ui->tableWidget_4->insertRow(row);
        ui->tableWidget_4->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_4->setItem(row, 1, new QTableWidgetItem(model));
        ui->tableWidget_4->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    //테이블 기록x 출력
    if(!ui->tableWidget_4->item(0,0) && type!="")
    {
        qDebug()<<"can't search";
        QMessageBox::information(this,"","검색되는 기록이 없습니다.");
        ui->tableWidget_4->clearContents();
    }
    // 총 판매량 저장 및 라벨에 삽입
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_4->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_4->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_4->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_4->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_4->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_4->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_4->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_4->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_4->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_4->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_4->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::pushButton7_clicked()
{
    QString year = ui->comboBox_year_4->currentText();
    QString month = ui->comboBox_month_4->currentText();
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";

    qDebug() << "Selected Year:" << year;
    qDebug() << "Selected Month:" << month;

    QSqlQuery query1;
    QString query1String = "SELECT brand, " + monthlist[month.toInt()] + year + " FROM ALL_SALES WHERE (brand = 'HYUNDAI' OR brand = 'KIA' OR brand = 'GENESIS' OR brand = 'CHEVROLET' OR brand = 'KG_MOBILITY' or brand = 'RENAUL_KOREA') ORDER BY " + monthlist[month.toInt()] + year + " DESC";

    if (!query1.exec(query1String))
    {
        qDebug() << "Query execution failed:" << query1.lastError().text();
        return;
    }

    QSqlQuery query2;
    QString query2String = "SELECT brand, " + monthlist[month.toInt()] + year + " FROM ALL_SALES WHERE (brand = 'BENZ' OR brand = 'BMW' OR brand = 'AUDI' OR brand = 'VOLVO' OR brand = 'VOLKSWAGEN' or brand = 'LEXUS') ORDER BY " + monthlist[month.toInt()] + year + " DESC";

    if (!query2.exec(query2String))
    {
        qDebug() << "Query execution failed:" << query2.lastError().text();
        return;
    }

    ui->tableWidget_13->clearContents();
    ui->tableWidget_13->setRowCount(0);

    int row = 0;
    while (query1.next())
    {
        QString brand = query1.value(0).toString();
        QString sales = query1.value(1).toString();

        ui->tableWidget_13->insertRow(row);
        ui->tableWidget_13->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_13->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_13->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_13->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_13->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_13->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_13->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_13->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    ui->tableWidget_14->clearContents();
    ui->tableWidget_14->setRowCount(0);

    row = 0;
    while (query2.next())
    {
        QString brand = query2.value(0).toString();
        QString sales = query2.value(1).toString();

        ui->tableWidget_14->insertRow(row);
        ui->tableWidget_14->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_14->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_14->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    salessum = 0;
    for (int i = 0; i < ui->tableWidget_14->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_14->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_14->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_14->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_14->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_13->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_13->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_13->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_13->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_13->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_13->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_14->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_14->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_14->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_14->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_14->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_14->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::pushButton9_clicked()
{
    QString year = ui->comboBox_year_5->currentText();
    QString month = ui->comboBox_month_5->currentText();
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";

    qDebug() << "Selected Year:" << year;
    qDebug() << "Selected Month:" << month;

    QSqlQuery query;
    QString queryString = "SELECT model, " + monthlist[month.toInt()] + year + " FROM HYUNDAI WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM KIA WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM GENESIS WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM CHEVROLET WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM KG_MOBILITY WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM RENAUL_KOREA WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM BENZ WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM BMW WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM AUDI WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM VOLVO WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM VOLKSWAGEN WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM LEXUS WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                          + "ORDER BY " + monthlist[month.toInt()] + year + " DESC";

    if (!query.exec(queryString))
    {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return;
    }

    ui->tableWidget_17->clearContents();
    ui->tableWidget_17->setRowCount(0);

    int row = 0;
    while (query.next())
    {
        QString model = query.value(0).toString();
        QString sales = query.value(1).toString();

        ui->tableWidget_17->insertRow(row);
        ui->tableWidget_17->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_17->setItem(row, 1, new QTableWidgetItem(model));
        ui->tableWidget_17->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_17->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_17->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    row = 0;
    for (int i = 0; i < ui->tableWidget_17->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_17->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_17->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_17->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_17->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_17->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_17->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_17->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_17->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::pushButton10_clicked()
{
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";
    int firstyear = ui->comboBox_firstyear_5->currentText().toInt();
    int firstmonth = ui->comboBox_firstmonth_5->currentText().toInt();
    int secondyear = ui->comboBox_secondyear_5->currentText().toInt();
    int secondmonth = ui->comboBox_secondmonth_5->currentText().toInt();

    QString period;
    if (firstyear == secondyear) // 첫 번째, 두 번째 선택 년 같을 경우
    {
        if (firstmonth <= secondmonth) // 첫 번째 선택 월이 두 번째 선택 월보다 작거나 같을 경우
        {
            for (int i = firstmonth; i <= secondmonth; i++) // 첫 번째 선택 월 ~ 두 번째 선택 월 반복
            {
                if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                    period += monthlist[i] + QString::number(firstyear);
                else
                    period += monthlist[i] + QString::number(firstyear) + " + ";
            }
        }
        else // 첫 번째 선택 월이 두 번째 선택 월보다 클 경우
        {
            QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
            ui->tableWidget_18->clearContents();
            return;
        }
    }
    else if (firstyear < secondyear) // 첫 번째 선택 년이 두 번째 선택 년보다 작을 경우
    {
        for (int i = firstmonth; i <= 12; i++) // 첫 번째 선택 년의 선택 월 ~ 12월 반복
            period += monthlist[i] + QString::number(firstyear) + " + ";
        for (int i = 1; i <= secondmonth; i++) // 두 번째 선택 년의 1월 ~ 선택 월 반복
        {
            if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                period += monthlist[i] + QString::number(secondyear);
            else
                period += monthlist[i] + QString::number(secondyear) + " + ";
        }
    }
    else // 첫 번째 선택 년이 두 번째 선택 년보다 클 경우
    {
        QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
        ui->tableWidget_18->clearContents();
        return;
    }

    QSqlQuery query;
    QString queryString = "SELECT model, " + period + " FROM HYUNDAI WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM KIA WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM GENESIS WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM CHEVROLET WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM KG_MOBILITY WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM RENAUL_KOREA WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM BENZ WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM BMW WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM AUDI WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM VOLVO WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM VOLKSWAGEN WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "UNION SELECT model, " + period + " FROM LEXUS WHERE (LENGTH(" + period + ") > 0 AND (" + period + ") <> 0) "
                          + "ORDER BY " + period + " DESC";
    if (!query.exec(queryString))
    {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return;
    }

    // 테이블 초기화
    ui->tableWidget_18->clearContents();
    ui->tableWidget_18->setRowCount(0);

    // 테이블에 데이터 삽입
    int row = 0;
    while (query.next())
    {
        QString model = query.value(0).toString();
        QString sales = query.value(1).toString();

        ui->tableWidget_18->insertRow(row);
        ui->tableWidget_18->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_18->setItem(row, 1, new QTableWidgetItem(model));
        ui->tableWidget_18->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_18->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_18->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_18->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_18->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_18->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_18->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_18->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_18->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_18->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_18->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_18->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}
void MainWindow::pushButton5_clicked()
{
    QString year = ui->comboBox_year_3->currentText();
    QString month = ui->comboBox_month_3->currentText();
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";

    qDebug() << "Selected Year:" << year;
    qDebug() << "Selected Month:" << month;

    QSqlQuery query1;
    QString query1String = "SELECT brand, " + monthlist[month.toInt()] + year + " FROM ALL_SALES WHERE (brand = 'HYUNDAI' OR brand = 'KIA' OR brand = 'GENESIS' OR brand = 'CHEVROLET' OR brand = 'KG_MOBILITY' or brand = 'RENAUL_KOREA') ORDER BY " + monthlist[month.toInt()] + year + " DESC LIMIT 3";

    if (!query1.exec(query1String))
    {
        qDebug() << "Query execution failed:" << query1.lastError().text();
        return;
    }

    QSqlQuery query2;
    QString query2String = "SELECT brand, " + monthlist[month.toInt()] + year + " FROM ALL_SALES WHERE (brand = 'BENZ' OR brand = 'BMW' OR brand = 'AUDI' OR brand = 'VOLVO' OR brand = 'VOLKSWAGEN' or brand = 'LEXUS') ORDER BY " + monthlist[month.toInt()] + year + " DESC LIMIT 3";

    if (!query2.exec(query2String))
    {
        qDebug() << "Query execution failed:" << query2.lastError().text();
        return;
    }

    QSqlQuery query3;
    QString query3String = "SELECT model, " + monthlist[month.toInt()] + year + " FROM HYUNDAI WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM KIA WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM GENESIS WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM CHEVROLET WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM KG_MOBILITY WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM RENAUL_KOREA WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "ORDER BY " + monthlist[month.toInt()] + year + " DESC LIMIT 5";

    if (!query3.exec(query3String))
    {
        qDebug() << "Query execution failed:" << query3.lastError().text();
        return;
    }

    QSqlQuery query4;
    QString query4String = "SELECT model, " + monthlist[month.toInt()] + year + " FROM BENZ WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM BMW WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM AUDI WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM VOLVO WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM VOLKSWAGEN WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "UNION SELECT model, " + monthlist[month.toInt()] + year + " FROM LEXUS WHERE (LENGTH(" + monthlist[month.toInt()] + year + ") > 0 AND " + monthlist[month.toInt()] + year + " <> 0) "
                           + "ORDER BY " + monthlist[month.toInt()] + year + " DESC LIMIT 5";

    if (!query4.exec(query4String))
    {
        qDebug() << "Query execution failed:" << query4.lastError().text();
        return;
    }

    ui->tableWidget_5->clearContents();
    ui->tableWidget_5->setRowCount(0);

    int row = 0;
    while (query1.next())
    {
        QString brand = query1.value(0).toString();
        QString sales = query1.value(1).toString();

        ui->tableWidget_5->insertRow(row);
        ui->tableWidget_5->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_5->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_5->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_5->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_5->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_5->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_5->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_5->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    ui->tableWidget_6->clearContents();
    ui->tableWidget_6->setRowCount(0);

    row = 0;
    while (query2.next())
    {
        QString brand = query2.value(0).toString();
        QString sales = query2.value(1).toString();

        ui->tableWidget_6->insertRow(row);
        ui->tableWidget_6->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_6->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_6->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    salessum = 0;
    for (int i = 0; i < ui->tableWidget_6->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_6->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_6->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_6->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_6->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    ui->tableWidget_7->clearContents();
    ui->tableWidget_7->setRowCount(0);

    row = 0;
    while (query3.next())
    {
        QString brand = query3.value(0).toString();
        QString sales = query3.value(1).toString();

        ui->tableWidget_7->insertRow(row);
        ui->tableWidget_7->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_7->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_7->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    salessum = 0;
    for (int i = 0; i < ui->tableWidget_7->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_7->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_7->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_7->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_7->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    ui->tableWidget_8->clearContents();
    ui->tableWidget_8->setRowCount(0);

    row = 0;
    while (query4.next())
    {
        QString brand = query4.value(0).toString();
        QString sales = query4.value(1).toString();

        ui->tableWidget_8->insertRow(row);
        ui->tableWidget_8->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_8->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_8->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    salessum = 0;
    for (int i = 0; i < ui->tableWidget_8->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_8->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_8->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_8->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_8->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_5->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_5->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_5->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_5->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_5->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_5->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_6->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_6->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_6->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_6->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_6->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_6->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_7->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_7->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_7->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_7->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_7->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_7->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_8->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_8->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_8->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_8->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_8->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_8->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::pushButton6_clicked()
{
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";
    int firstyear = ui->comboBox_firstyear_3->currentText().toInt();
    int firstmonth = ui->comboBox_firstmonth_3->currentText().toInt();
    int secondyear = ui->comboBox_secondyear_3->currentText().toInt();
    int secondmonth = ui->comboBox_secondmonth_3->currentText().toInt();

    QString period;
    if (firstyear == secondyear) // 첫 번째, 두 번째 선택 년 같을 경우
    {
        if (firstmonth <= secondmonth) // 첫 번째 선택 월이 두 번째 선택 월보다 작거나 같을 경우
        {
            for (int i = firstmonth; i <= secondmonth; i++) // 첫 번째 선택 월 ~ 두 번째 선택 월 반복
            {
                if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                    period += monthlist[i] + QString::number(firstyear);
                else
                    period += monthlist[i] + QString::number(firstyear) + " + ";
            }
        }
        else // 첫 번째 선택 월이 두 번째 선택 월보다 클 경우
        {
            QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
            ui->tableWidget_9->clearContents();
            ui->tableWidget_10->clearContents();
            ui->tableWidget_11->clearContents();
            ui->tableWidget_12->clearContents();
            return;
        }
    }
    else if (firstyear < secondyear) // 첫 번째 선택 년이 두 번째 선택 년보다 작을 경우
    {
        for (int i = firstmonth; i <= 12; i++) // 첫 번째 선택 년의 선택 월 ~ 12월 반복
            period += monthlist[i] + QString::number(firstyear) + " + ";
        for (int i = 1; i <= secondmonth; i++) // 두 번째 선택 년의 1월 ~ 선택 월 반복
        {
            if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                period += monthlist[i] + QString::number(secondyear);
            else
                period += monthlist[i] + QString::number(secondyear) + " + ";
        }
    }
    else // 첫 번째 선택 년이 두 번째 선택 년보다 클 경우
    {
        QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
        ui->tableWidget_9->clearContents();
        ui->tableWidget_10->clearContents();
        ui->tableWidget_11->clearContents();
        ui->tableWidget_12->clearContents();
        return;
    }

    QSqlQuery query1;
    QString query1String = "SELECT brand, " + period + " FROM ALL_SALES WHERE (brand = 'HYUNDAI' OR brand = 'KIA' OR brand = 'GENESIS' OR brand = 'CHEVROLET' OR brand = 'KG_MOBILITY' or brand = 'RENAUL_KOREA') ORDER BY " + period + " DESC LIMIT 3";

    if (!query1.exec(query1String))
    {
        qDebug() << "Query execution failed:" << query1.lastError().text();
        return;
    }

    QSqlQuery query2;
    QString query2String = "SELECT brand, " + period + " FROM ALL_SALES WHERE (brand = 'BENZ' OR brand = 'BMW' OR brand = 'AUDI' OR brand = 'VOLVO' OR brand = 'VOLKSWAGEN' or brand = 'LEXUS') ORDER BY " + period + " DESC LIMIT 3";

    if (!query2.exec(query2String))
    {
        qDebug() << "Query execution failed:" << query2.lastError().text();
        return;
    }

    QSqlQuery query3;
    QString query3String = "SELECT model, " + period + " FROM HYUNDAI WHERE (LENGTH(" + period + ") > 0 AND " + period + " <> 0) "
                           + "UNION SELECT model, " + period + " FROM KIA WHERE (LENGTH(" + period + ") > 0 AND " + period + " <> 0) "
                           + "UNION SELECT model, " + period + " FROM GENESIS WHERE (LENGTH(" + period + ") > 0 AND " + period + " <> 0) "
                           + "UNION SELECT model, " + period + " FROM CHEVROLET WHERE (LENGTH(" + period + ") > 0 AND " + period + " <> 0) "
                           + "UNION SELECT model, " + period + " FROM KG_MOBILITY WHERE (LENGTH(" + period + ") > 0 AND " + period + " <> 0) "
                           + "UNION SELECT model, " + period + " FROM RENAUL_KOREA WHERE (LENGTH(" + period + ") > 0 AND " + period + " <> 0) "
                           + "ORDER BY " + period + " DESC LIMIT 5";

    if (!query3.exec(query3String))
    {
        qDebug() << "Query execution failed:" << query3.lastError().text();
        return;
    }

    QSqlQuery query4;
    QString query4String = "SELECT model, " + period + " FROM BENZ WHERE (LENGTH(" + period+ ") > 0 AND " + period+ " <> 0) "
                           + "UNION SELECT model, " + period + " FROM BMW WHERE (LENGTH(" + period+ ") > 0 AND " + period+ " <> 0) "
                           + "UNION SELECT model, " + period + " FROM AUDI WHERE (LENGTH(" + period+ ") > 0 AND " + period+ " <> 0) "
                           + "UNION SELECT model, " + period + " FROM VOLVO WHERE (LENGTH(" + period+ ") > 0 AND " + period+ " <> 0) "
                           + "UNION SELECT model, " + period + " FROM VOLKSWAGEN WHERE (LENGTH(" + period+ ") > 0 AND " + period+ " <> 0) "
                           + "UNION SELECT model, " + period + " FROM LEXUS WHERE (LENGTH(" + period+ ") > 0 AND " + period+ " <> 0) "
                           + "ORDER BY " + period + " DESC LIMIT 5";

    if (!query4.exec(query4String))
    {
        qDebug() << "Query execution failed:" << query4.lastError().text();
        return;
    }

    ui->tableWidget_9->clearContents();
    ui->tableWidget_9->setRowCount(0);

    int row = 0;
    while (query1.next())
    {
        QString brand = query1.value(0).toString();
        QString sales = query1.value(1).toString();

        ui->tableWidget_9->insertRow(row);
        ui->tableWidget_9->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_9->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_9->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_9->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_9->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_9->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_9->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_9->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    ui->tableWidget_10->clearContents();
    ui->tableWidget_10->setRowCount(0);

    row = 0;
    while (query2.next())
    {
        QString brand = query2.value(0).toString();
        QString sales = query2.value(1).toString();

        ui->tableWidget_10->insertRow(row);
        ui->tableWidget_10->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_10->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_10->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    salessum = 0;
    for (int i = 0; i < ui->tableWidget_10->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_10->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_10->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_10->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_10->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    ui->tableWidget_11->clearContents();
    ui->tableWidget_11->setRowCount(0);

    row = 0;
    while (query3.next())
    {
        QString brand = query3.value(0).toString();
        QString sales = query3.value(1).toString();

        ui->tableWidget_11->insertRow(row);
        ui->tableWidget_11->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_11->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_11->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    salessum = 0;
    for (int i = 0; i < ui->tableWidget_11->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_11->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_11->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_11->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_11->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    ui->tableWidget_12->clearContents();
    ui->tableWidget_12->setRowCount(0);

    row = 0;
    while (query4.next())
    {
        QString brand = query4.value(0).toString();
        QString sales = query4.value(1).toString();

        ui->tableWidget_12->insertRow(row);
        ui->tableWidget_12->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_12->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_12->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    salessum = 0;
    for (int i = 0; i < ui->tableWidget_12->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_12->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_12->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_12->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_12->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_9->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_9->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_9->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_9->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_9->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_9->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_10->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_10->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_10->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_10->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_10->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_10->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_11->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_11->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_11->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_11->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_11->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_11->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_12->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_12->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_12->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_12->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_12->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_12->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::pushButton8_clicked()
{
    QStringList monthlist = QStringList() << "dec" << "jan" << "feb" << "mar" << "apr" << "may" << "jun" << "jul" << "aug" << "sep" << "oct" << "nov" << "dec";
    int firstyear = ui->comboBox_firstyear_4->currentText().toInt();
    int firstmonth = ui->comboBox_firstmonth_4->currentText().toInt();
    int secondyear = ui->comboBox_secondyear_4->currentText().toInt();
    int secondmonth = ui->comboBox_secondmonth_4->currentText().toInt();

    QString period;
    if (firstyear == secondyear) // 첫 번째, 두 번째 선택 년 같을 경우
    {
        if (firstmonth <= secondmonth) // 첫 번째 선택 월이 두 번째 선택 월보다 작거나 같을 경우
        {
            for (int i = firstmonth; i <= secondmonth; i++) // 첫 번째 선택 월 ~ 두 번째 선택 월 반복
            {
                if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                    period += monthlist[i] + QString::number(firstyear);
                else
                    period += monthlist[i] + QString::number(firstyear) + " + ";
            }
        }
        else // 첫 번째 선택 월이 두 번째 선택 월보다 클 경우
        {
            QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
            ui->tableWidget_15->clearContents();
            ui->tableWidget_16->clearContents();
            return;
        }
    }
    else if (firstyear < secondyear) // 첫 번째 선택 년이 두 번째 선택 년보다 작을 경우
    {
        for (int i = firstmonth; i <= 12; i++) // 첫 번째 선택 년의 선택 월 ~ 12월 반복
            period += monthlist[i] + QString::number(firstyear) + " + ";
        for (int i = 1; i <= secondmonth; i++) // 두 번째 선택 년의 1월 ~ 선택 월 반복
        {
            if (i == secondmonth) // 반복문의 마지막에 도달했을 경우
                period += monthlist[i] + QString::number(secondyear);
            else
                period += monthlist[i] + QString::number(secondyear) + " + ";
        }
    }
    else // 첫 번째 선택 년이 두 번째 선택 년보다 클 경우
    {
        QMessageBox::warning(this,"","잘못된 선택입니다.\n기한을 정확하게 선택해주세요");
        ui->tableWidget_15->clearContents();
        ui->tableWidget_16->clearContents();
        return;
    }

    QSqlQuery query1;
    QString query1String = "SELECT brand, " + period + " FROM ALL_SALES WHERE (brand = 'HYUNDAI' OR brand = 'KIA' OR brand = 'GENESIS' OR brand = 'CHEVROLET' OR brand = 'KG_MOBILITY' or brand = 'RENAUL_KOREA') ORDER BY " + period + " DESC";

    if (!query1.exec(query1String))
    {
        qDebug() << "Query execution failed:" << query1.lastError().text();
        return;
    }

    QSqlQuery query2;
    QString query2String = "SELECT brand, " + period + " FROM ALL_SALES WHERE (brand = 'BENZ' OR brand = 'BMW' OR brand = 'AUDI' OR brand = 'VOLVO' OR brand = 'VOLKSWAGEN' or brand = 'LEXUS') ORDER BY " + period + " DESC";

    if (!query2.exec(query2String))
    {
        qDebug() << "Query execution failed:" << query2.lastError().text();
        return;
    }

    ui->tableWidget_15->clearContents();
    ui->tableWidget_15->setRowCount(0);

    int row = 0;
    while (query1.next())
    {
        QString brand = query1.value(0).toString();
        QString sales = query1.value(1).toString();

        ui->tableWidget_15->insertRow(row);
        ui->tableWidget_15->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_15->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_15->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    int salessum = 0;
    for (int i = 0; i < ui->tableWidget_15->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_15->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_15->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_15->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_15->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    ui->tableWidget_16->clearContents();
    ui->tableWidget_16->setRowCount(0);

    row = 0;
    while (query2.next())
    {
        QString brand = query2.value(0).toString();
        QString sales = query2.value(1).toString();

        ui->tableWidget_16->insertRow(row);
        ui->tableWidget_16->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_16->setItem(row, 1, new QTableWidgetItem(brand));
        ui->tableWidget_16->setItem(row, 2, new QTableWidgetItem(sales));
        row++;
    }

    // 총 판매량 저장 및 라벨에 삽입
    salessum = 0;
    for (int i = 0; i < ui->tableWidget_16->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_16->item(i, 2);
        QString text = item->text();
        int value = text.toInt();
        salessum += value;
    }

    // 테이블에 점유율 데이터 삽입
    row = 0;
    for (int i = 0; i < ui->tableWidget_16->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_16->item(i, 2);
        QString text = item->text();
        double value = text.toDouble();
        double rate = round((value / salessum) * 100 * 10) / 10;
        ui->tableWidget_16->setItem(row, 3, new QTableWidgetItem(QString("%1%").arg(rate, 0, 'f', 1))); // 변수, 길이, 포맷지정자('f' = 소수점 표기), 표시할 소수점의 자리 수
        row++;
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_15->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_15->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_15->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_15->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_15->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_15->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 첫 번째 열 가운데 정렬
    for (int i = 0; i < ui->tableWidget_16->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_16->item(i, 0);
        item->setTextAlignment(Qt::AlignCenter);
    }

    // 테이블 세 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_16->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_16->item(i, 2);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    // 테이블 네 번째 열 오른쪽 정렬
    for (int i = 0; i < ui->tableWidget_16->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget_16->item(i, 3);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

void MainWindow::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_JOIN_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_FIND_id_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_FIND_pw_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_LOGIN_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_LOGIN_clicked()
{
    QSqlQuery qry;
    QString id = ui->ID_input->text();
    QString pw = ui->PW_input->text();
    QString ment = "아이디 또는 비밀번호를 잘못 입력하셨습니다.";

    qry.prepare("SELECT id,pw FROM MEMBERSHIP WHERE id = :id AND pw = :pw");
    qry.bindValue(":id",id);
    qry.bindValue(":pw",pw);

    ui->LOGIN_ducheck->setText(ment);

    if(qry.exec() && qry.next())
        ui->stackedWidget->setCurrentIndex(0);
    else
    {
        ui->LOGIN_ducheck->setText(ment);
        ui->ID_input->clear();
        ui->PW_input->clear();
        ui->ID_input->setFocus();
    }
}

void MainWindow::on_ID_du_clicked()
{
    QSqlQuery qry;
    QString id = ui->Join_id->text();

    qry.prepare("SELECT id FROM MEMBERSHIP WHERE id= :id");
    qry.bindValue(":id",id);
    if(qry.exec())
    {
        if(qry.next())
        {
            ui->ID_ducheck->setText("사용중이거나 탈퇴한 아이디입니다.");
            ui->Join->setEnabled(false);
            ui->Join->setStyleSheet("QPushButton{background-color: rgb(170, 170, 127);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");
            ui->Join_id->clear();
            return;
        }
        else
        {
            ui->ID_ducheck->setText("사용가능한 아이디입니다.");
            ui->Join_id->setEnabled(false);
        }
    }


    QString pw = ui->Join_pw->text();
    QString pw_2 = ui->Join_pw2->text();
    QString email = ui->Join_email->text()+"@"+ui->comboBox->currentText();

    bool checkBox = ui->checkBox_2->isChecked() && ui->checkBox_4->isChecked();
    ui->Join->setEnabled(checkBox);
    if(ui->checkBox_2->isChecked() && ui->checkBox_4->isChecked() && !(id.isEmpty() || pw.isEmpty() || email.isEmpty() || pw_2.isEmpty()) && pw == pw_2)
        ui->Join->setStyleSheet("QPushButton{background-color: rgb(0, 85, 255);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");

}

void MainWindow::on_comboBox_activated(int index)
{
    QSqlQuery qry;
    QString email = ui->Join_email->text()+"@"+ui->comboBox->currentText();

    qry.prepare("SELECT email FROM MEMBERSHIP WHERE email = :email");
    qry.bindValue(":email",email);

    if(qry.exec())
    {
        if(qry.next())
        {
            ui->EMAIL_ducheck->setText("사용중인 이메일입니다.");
            ui->Join->setEnabled(false);
            ui->Join->setStyleSheet("QPushButton{background-color: rgb(170, 170, 127);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");
            return;

        }
        else
        {
            ui->EMAIL_ducheck->setText("사용가능한 이메일입니다.");
            ui->checkBox_2->setEnabled(true);
            ui->checkBox_4->setEnabled(true);
        }
    }

    QString id = ui->Join_id->text();
    QString pw = ui->Join_pw->text();
    QString pw_2 = ui->Join_pw2->text();

    bool checkBox = ui->checkBox_2->isChecked() && ui->checkBox_4->isChecked();
    ui->Join->setEnabled(checkBox);
    if(ui->checkBox_2->isChecked() && ui->checkBox_4->isChecked() && !(id.isEmpty() || pw.isEmpty() || email.isEmpty() || pw_2.isEmpty()) && pw == pw_2)
        ui->Join->setStyleSheet("QPushButton{background-color: rgb(0, 85, 255);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");

}


void MainWindow::on_Join_clicked() //회원가입 눌렀을 때
{
    QSqlQuery qry;
    QString id = ui->Join_id->text();
    QString pw = ui->Join_pw->text();
    QString pw_2 = ui->Join_pw2->text();
    QString email = ui->Join_email->text()+"@"+ui->comboBox->currentText();

    if(id.isEmpty() || pw.isEmpty() || email.isEmpty() || pw_2.isEmpty())
    {
        ui->Join->setEnabled(true);
        return;
    }

    if(pw != pw_2)
    {
        ui->Join->setEnabled(false);
        return;
    }
    qry.prepare("INSERT INTO MEMBERSHIP(id,pw,email) VALUES (:id,:pw,:email)" );
    qry.bindValue(":id",id);
    qry.bindValue(":pw",pw);
    qry.bindValue(":email",email);
    qry.exec();


    ui->stackedWidget->setCurrentIndex(7);

    ui->Join_id->clear();
    ui->Join_pw->clear();
    ui->Join_pw2->clear();
    ui->Join_email->clear();
    ui->checkBox_2->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_2->setEnabled(false);
    ui->checkBox_4->setEnabled(false);
    ui->PW_ducheck->clear();
    ui->Join_id->setEnabled(true);
    ui->Join->setStyleSheet("QPushButton{background-color: rgb(170, 170, 127);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");

}


void MainWindow::on_LOGIN_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_LOGIN_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_ID_find2_clicked()
{
    QSqlQuery qry;
    QString email = ui->ID_find->text();

    qry.prepare("SELECT id FROM MEMBERSHIP WHERE email = :email");
    qry.bindValue(":email",email);

    if(qry.exec())
    {
        if(qry.next())
        {
            QString id = qry.value("id").toString();
            ui->ID_find3->setText("찾으시는 아이디는 " + id + " 입니다.");
        }
        else
        {
            ui->ID_find3->setText("입력하신 정보와 일치하는 아이디가 없습니다.");
        }
    }

}


void MainWindow::on_PW_find2_clicked()
{
    QSqlQuery qry;
    QString id = ui->PW_find->text();

    qry.prepare("SELECT pw FROM MEMBERSHIP WHERE email = :id OR id = :id");
    qry.bindValue(":email",id);
    qry.bindValue(":id",id);

    if(qry.exec())
    {
        if(qry.next())
        {
            QString pw = qry.value("pw").toString();
            ui->PW_find3->setText("찾으시는 비밀번호는 " + pw + " 입니다.");
        }
        else
        {
            ui->PW_find3->setText("입력하신 정보와 일치하는 비밀번호가 없습니다.");
        }
    }
}

void MainWindow::on_LOGIN_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    updateButton();
    if(ui->checkBox_2->checkState()== false)
        ui->Join->setStyleSheet("QPushButton{background-color: rgb(170, 170, 127);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");

}


void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    updateButton();
    if(ui->checkBox_4->checkState()== false)
        ui->Join->setStyleSheet("QPushButton{background-color: rgb(170, 170, 127);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");
}

void MainWindow::updateButton()
{
    QSqlQuery qry;
    QString id = ui->Join_id->text();
    QString pw = ui->Join_pw->text();
    QString pw_2 = ui->Join_pw2->text();
    QString email = ui->Join_email->text()+"@"+ui->comboBox->currentText();

    bool checkBox = ui->checkBox_2->isChecked() && ui->checkBox_4->isChecked();
    ui->Join->setEnabled(checkBox);
    if(ui->checkBox_2->isChecked() && ui->checkBox_4->isChecked() && !(id.isEmpty() || pw.isEmpty() || email.isEmpty() || pw_2.isEmpty()) && pw == pw_2)
        ui->Join->setStyleSheet("QPushButton{background-color: rgb(0, 85, 255);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");

}

void MainWindow::on_PW_find_2_clicked()
{
    QSqlQuery qry;
    QString id = ui->lineEdit_2->text();

    qry.prepare("SELECT pw FROM MEMBERSHIP WHERE email = :id OR id = :id");
    qry.bindValue(":email",id);
    qry.bindValue(":id",id);

    if(qry.exec())
    {
        if(qry.next())
        {
            QString pw = qry.value("pw").toString();
            ui->PW_find3_2->setText("찾으시는 비밀번호는 " + pw + " 입니다.");
        }
        else
        {
            ui->PW_find3_2->setText("입력하신 정보와 일치하는 비밀번호가 없습니다.");
        }
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    QSqlQuery qry;
    QString email = ui->lineEdit_5->text();

    qry.prepare("SELECT id FROM MEMBERSHIP WHERE email = :email");
    qry.bindValue(":email",email);

    if(qry.exec())
    {
        if(qry.next())
        {
            QString id = qry.value("id").toString();
            ui->ID_find3_3->setText("찾으시는 아이디는 " + id + " 입니다.");
        }
        else
        {
            ui->ID_find3_3->setText("입력하신 정보와 일치하는 아이디가 없습니다.");
        }
    }
}

void MainWindow::on_PW_du_clicked()
{
    QString pw = ui->Join_pw->text();
    QString pw_2 = ui->Join_pw2->text();
    QSqlQuery qry;
    QString id = ui->Join_id->text();
    QString email = ui->Join_email->text()+"@"+ui->comboBox->currentText();

    if (pw != pw_2)
    {
        ui->PW_ducheck->setText("불일치");
        ui->Join->setEnabled(false);
        ui->Join->setStyleSheet("QPushButton{background-color: rgb(170, 170, 127);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");
        return;
    }
    else
    {

        ui->PW_ducheck->setText("일치");
        bool checkBox = ui->checkBox_2->isChecked() && ui->checkBox_4->isChecked();
        ui->Join->setEnabled(checkBox);
        if(ui->checkBox_2->isChecked() && ui->checkBox_4->isChecked() && !(id.isEmpty() || pw.isEmpty() || email.isEmpty() || pw_2.isEmpty()) && pw == pw_2)
            ui->Join->setStyleSheet("QPushButton{background-color: rgb(0, 85, 255);border-color: rgb(0, 0, 0);color: rgb(255, 255, 255);}");
    }


}

