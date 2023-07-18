#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QLabel>
#include <QTime>
#include <QTimer>
QT_BEGIN_NAMESPACE
#include "querydialog.h"
#include "bookoridatadialog.h"
#include "attitudedialog.h"
#include "shoploaddialog.h"
#include "calibratparadialog.h"
#include "tempcompencoeffdialog.h"
#include "leverarmdialog.h"
#include "serialinterfacedialog.h"
#include <QFile>
#include <QFileDialog>
#include "qextserialport.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include "serialworker.h"
#include <QTableWidget>
#include <QTextStream>
#include "qextserialport.h"
#include <QProgressDialog>
#include "sysbasegdialog.h"
#include "sysheightdialog.h"
#include "handleresultdelaydialog.h"
#include <QDir>
#include "xxwcustomplot.h"
#include "xxwtracer.h"

#define QEXTSERIALPORT
//#define SERIALPORT
#define INSIDE          //内部版
//#define USER          //用户版

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setLED1(QLabel* label, int color, int size);
    void InitClear();
    //void wheelEvent(QWheelEvent *event);
    void doDataReciveWork();
    void doDataSendWork(const QByteArray data);
    void closeEvent(QCloseEvent *e);
    void drawAllCurve();
    void reSet();
    ~MainWindow();

    void C6getCurveData();
    void C5getCurveData();
    void C3getCurveData();
    void C1getCurveData();
    void C8getCurveData();
    int findMaxRecord();
    void setY88_89_90_91_92_93();
    void drawAllHisCurve();
    void setY94_95_96_97_98_99();
    void setY100_101_102();
    void setY106_103_108_105_104_107();
    void resetY();
    int graphPointNum;
private:
    void InitSerialPortName();
    QByteArray HexStringToByteArray(QString HexString);
    QString ByteArrayToHexString(QByteArray data);
    void serialPort_readyRead();

signals:
    void serialDataSend(const QByteArray data);

public slots:


#ifdef QEXTSERIALPORT
void handleResults();
#endif
#ifdef SERIALPORT
void handleResults(QByteArray result);
#endif

    void startTimer();
    //void getCurveData();
private slots:
    void on_btn_openPort_clicked();
    void drawCurveLatitude();
    //void timeToAddData();
    //void timeToRePlot();
   // void on_btn_start2_clicked();
    void bookLog(QString bookStr);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    //void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_triggered();

    void on_pushButton_15_clicked();
    void set_checkBox_19_18_17();
    void set_checkBox_12_13_11_15_16_14();
    void set_checkBox_6_7_8();
    void set_checkBox_9_10_76_77_78();
    void set_checkBox_5_3_4_79_80_81();
    void set_checkBox_1_2_73_74_75();
    void set_checkBox_20_21_22();
    void set_checkBox_23_24_25();
    void set_checkBox_26_27_28();
    void set_checkBox_29_30_31();
    void set_checkBox_32_33_34();
    void set_checkBox_37_35_36();
    void set_checkBox_40_38_39();
    void set_checkBox_42_43_41();
    void set_checkBox_45_46_44();
    void set_checkBox_48_49_47();
    void set_checkBox_51_54_50_52_53_60();
    void set_checkBox_59_56_57_55_58();
    void set_checkBox_61_63_62();
    void set_checkBox_65_64_66();
    void set_checkBox_67_69_68();
    void set_checkBox_70_72_71();
//    void on_checkBox1_stateChanged(int arg1);

//    void on_checkBox2_stateChanged(int arg1);

//    void on_checkBox3_stateChanged(int arg1);

//    void on_checkBox4_stateChanged(int arg1);

//    void on_checkBox5_stateChanged(int arg1);

//    void on_checkBox6_stateChanged(int arg1);

    void on_action_ms_triggered();

    void on_comboBox_2_currentIndexChanged(int index);


//    void on_checkBox6_2_stateChanged(int arg1);

//    void on_checkBox6_3_stateChanged(int arg1);



    void on_pushButton_9_clicked();


    void on_comboBox_3_currentIndexChanged(int index);
    void on_checkBox_91_toggled(bool checked);


    void on_checkBox_88_toggled(bool checked);

    void on_checkBox_93_toggled(bool checked);

    void on_checkBox_90_toggled(bool checked);

    void on_checkBox_89_toggled(bool checked);

    void on_checkBox_92_toggled(bool checked);

    void on_checkBox_94_toggled(bool checked);

    void on_checkBox_95_toggled(bool checked);

    void on_checkBox_96_toggled(bool checked);

    void on_checkBox_97_toggled(bool checked);

    void on_checkBox_98_toggled(bool checked);

    void on_checkBox_99_toggled(bool checked);

    void on_checkBox_100_toggled(bool checked);

    void on_checkBox_101_toggled(bool checked);

    void on_checkBox_102_toggled(bool checked);

    void on_checkBox_106_toggled(bool checked);

    void on_checkBox_103_toggled(bool checked);

    void on_checkBox_108_toggled(bool checked);

    void on_checkBox_105_toggled(bool checked);

    void on_checkBox_104_toggled(bool checked);

    void on_checkBox_107_toggled(bool checked);

    void on_checkBox_113_toggled(bool checked);

    void on_checkBox_111_toggled(bool checked);

    void on_checkBox_112_toggled(bool checked);

    void on_checkBox_110_toggled(bool checked);

    void on_checkBox_109_toggled(bool checked);

    void on_checkBox_114_toggled(bool checked);

    void on_checkBox_117_toggled(bool checked);

    void on_checkBox_116_toggled(bool checked);

    void on_checkBox_115_toggled(bool checked);

    void on_checkBox_120_toggled(bool checked);

    void on_checkBox_118_toggled(bool checked);

    void on_checkBox_119_toggled(bool checked);

    void on_checkBox_123_toggled(bool checked);

    void on_checkBox_122_toggled(bool checked);

    void on_checkBox_121_toggled(bool checked);

    void on_checkBox_124_toggled(bool checked);

    void on_checkBox_125_toggled(bool checked);

    void on_checkBox_126_toggled(bool checked);

    void on_checkBox_127_toggled(bool checked);

    void on_checkBox_128_toggled(bool checked);

    void on_checkBox_129_toggled(bool checked);

    void on_checkBox_130_toggled(bool checked);

    void on_checkBox_131_toggled(bool checked);

    void on_checkBox_132_toggled(bool checked);

    void on_checkBox_133_toggled(bool checked);

    void on_checkBox_134_toggled(bool checked);

    void on_checkBox_135_toggled(bool checked);

    void on_checkBox_137_toggled(bool checked);

    void on_checkBox_138_toggled(bool checked);

    void on_checkBox_136_toggled(bool checked);

    void on_checkBox_141_toggled(bool checked);

    void on_checkBox_140_toggled(bool checked);

    void on_checkBox_139_toggled(bool checked);

    void on_checkBox_143_toggled(bool checked);

    void on_checkBox_144_toggled(bool checked);

    void on_checkBox_142_toggled(bool checked);

    void on_checkBox_145_toggled(bool checked);

    void on_checkBox_146_toggled(bool checked);

    void on_checkBox_147_toggled(bool checked);

    void on_checkBox_151_toggled(bool checked);

    void on_checkBox_152_toggled(bool checked);

    void on_checkBox_153_toggled(bool checked);

    void on_checkBox_149_toggled(bool checked);

    void on_checkBox_150_toggled(bool checked);

    void on_checkBox_148_toggled(bool checked);

    void on_checkBox_154_toggled(bool checked);

    void on_checkBox_155_toggled(bool checked);

    void on_checkBox_157_toggled(bool checked);

    void on_checkBox_158_toggled(bool checked);

    void on_checkBox_159_toggled(bool checked);

    void on_checkBox_156_toggled(bool checked);

    void on_checkBox_161_toggled(bool checked);

    void on_checkBox_162_toggled(bool checked);

    void on_checkBox_160_toggled(bool checked);

    void on_checkBox_163_toggled(bool checked);

    void on_checkBox_164_toggled(bool checked);

    void on_checkBox_165_toggled(bool checked);

    void on_checkBox_166_toggled(bool checked);

    void on_checkBox_167_toggled(bool checked);

    void on_checkBox_168_toggled(bool checked);

    void on_checkBox_169_toggled(bool checked);

    void on_checkBox_170_toggled(bool checked);

    void on_checkBox_171_toggled(bool checked);


    void on_checkBox_172_toggled(bool checked);

    void on_checkBox_173_toggled(bool checked);

    void on_checkBox_174_toggled(bool checked);


    void on_pushButton_111_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray result;

    //第三方库
#ifdef QEXTSERIALPORT
    QextSerialPort *serial_1;   // 声明串口
#endif
   #ifdef SERIALPORT
    QSerialPort serial_1;
    QThread serialThread_1; // 定义子线程
#endif
    QTimer *qtime;
    QueryDialog * paraQuery;
    BookOriDataDialog * bookOriData;
    AttitudeDialog * attitudeData;
    ShopLoadDialog * shipLoadData;
    CalibratParaDialog *calbratParaData;
    TempCompenCoeffDialog *tempCompenCoeffData;
    LeverArmDialog *leverArmData;
    SerialInterfaceDialog *serialInterfaceData;
    sysBaseGDialog *sysBaseGData;
    sysHeightDialog * sysHeightData;
    handleResultDelayDialog *handleResultDelayData;
    int datanum;


    void init_darw2();
    QTimer rePlotTimer;
    QTimer dataTimer2;
    bool  m_start2;
    int  m_countGraph;    
    int m_xLength;                       //曲线点数
    long C1m_xLength;
    long C3m_xLength;
    long C5m_xLength;
    long C6m_xLength;
    long C8m_xLength;
    long SaveFileRecord;                //单个文件历史数据记录最大值
    long dataInvaildRecord;             //有效记录数，用于保存历史数据
    int isDegree;

    QVector<double> curveX;
    QVector<double> C1curveX;
    QVector<double> C3curveX;
    QVector<double> C5curveX;
    QVector<double> C6curveX;
    QVector<double> C8curveX;

    QVector<double> C1Vlatitude;           //存储C1的纬度数据
    QVector<double> C1Vlatitude_bk;           //存储C1的纬度数据
    qreal latitude;
    int C1latitudeCurveRun;               //判断C1纬度曲线是否存在
    int C1latitudeGraphNum;              //纬度在当前画图板中是第几条曲线

    qreal headingAngle;
    QVector<double> C1VheadingAngle;      //存储C1的航向数据
    QVector<double> C1VheadingAngle_bk;      //存储C1的航向数据
    int C1headingAngleRun;                //判断C1航向曲线是否存在
    int C1headingAngleNum;              //航向在当前画图板qreal rollAngle中是第几条曲线

    qreal longitude;
    QVector<double> C1Vlongitude;      //存储C1的经度数据
    QVector<double> C1Vlongitude_bk;      //存储C1的经度数据
    int C1longitudeRun;                //判断C1经度曲线是否存在
    int C1longitudeNum;              //经度在当前画图板中是第几条曲线

    qreal rollAngle;
    QVector<double> C1VrollAngle;      //存储C1的横摇角数据
    QVector<double> C1VrollAngle_bk;      //存储C1的横摇角数据
    int C1rollAngleRun;                //判断C1横摇角曲线是否存在
    int C1rollAngleNum;              //横摇角在当前画图板中是第几条曲线

    qreal pitchAngle;
    QVector<double> C1VpitchAngle;      //存储C1的纵摇角数据
    QVector<double> C1VpitchAngle_bk;      //存储C1的纵摇角数据
    int C1pitchAngleRun;                //判断C1纵摇角曲线是否存在
    int C1pitchAngleNum;              //纵摇角在当前画图板中是第几条曲线

    qreal northSpeed;
    QVector<double> C1VnorthSpeed;      //存储C1的北速数据
    QVector<double> C1VnorthSpeed_bk;      //存储C1的北速数据
    int C1northSpeedRun;                //判断C1北速曲线是否存在
    int C1northSpeedNum;              //北速在当前画图板中是第几条曲线

    qreal eastSpeed;
    QVector<double> C1VeastSpeed;      //存储C1的东速数据
    QVector<double> C1VeastSpeed_bk;      //存储C1的东速数据
    int C1eastSpeedRun;                //判断C1东速曲线是否存在
    int C1eastSpeedNum;              //东速在当前画图板中是第几条曲线

    qreal headingAngularSpeed;
    QVector<double> C1VheadingAngularSpeed;      //存储C1的航向角速度数据
    QVector<double> C1VheadingAngularSpeed_bk;      //存储C1的航向角速度数据
    int C1headingAngularSpeedRun;                //判断C1航向角速度曲线是否存在
    int C1headingAngularSpeedNum;

    qreal rollAngleSpeed;
    QVector<double> C1VrollAngleSpeed;      //存储C1的横摇角速度数据
    QVector<double> C1VrollAngleSpeed_bk;      //存储C1的横摇角速度数据
    int C1rollAngleSpeedRun;                //判断C1横摇角速度曲线是否存在
    int C1rollAngleSpeedNum;

    qreal pitchAngleSpeed;
    QVector<double> C1VpitchAngleSpeed;      //存储C1的纵摇角速度数据
    QVector<double> C1VpitchAngleSpeed_bk;      //存储C1的纵摇角速度数据
    int C1pitchAngleSpeedRun;                //判断C1纵摇角速度曲线是否存在
    int C1pitchAngleSpeedNum;

    qreal heave;
    QVector<double> C1Vheave;      //存储C1的垂荡数据
    QVector<double> C1Vheave_bk;      //存储C1的垂荡数据
    int C1heaveRun;                //判断C1垂荡曲线是否存在
    int C1heaveNum;

    qreal verticalVelocity;
    QVector<double> C1VverticalVelocity;      //存储C1的垂速数据
    QVector<double> C1VverticalVelocity_bk;      //存储C1的垂速数据
    int C1verticalVelocityRun;                //判断C1垂速曲线是否存在
    int C1verticalVelocityNum;

    qreal sway;
    QVector<double> C1Vsway;      //存储C1的横荡数据
    QVector<double> C1Vsway_bk;      //存储C1的横荡数据
    int C1swayRun;                //判断C1横荡曲线是否存在
    int C1swayNum;

    qreal transverseVelocity;
    QVector<double> C1VtransverseVelocity;      //存储C1的横速数据
    QVector<double> C1VtransverseVelocity_bk;      //存储C1的横速数据
    int C1transverseVelocityRun;                //判断C1横速曲线是否存在
    int C1transverseVelocityNum;

    qreal surge;
    QVector<double> C1Vsurge;      //存储C1的纵荡数据
    QVector<double> C1Vsurge_bk;      //存储C1的纵荡数据
    int C1surgeRun;                //判断C1纵荡曲线是否存在
    int C1surgeNum;

    qreal longitudinalVelocity;
    QVector<double> C1VlongitudinalVelocity;      //存储C1的纵速数据
    QVector<double> C1VlongitudinalVelocity_bk;      //存储C1的纵速数据
    int C1longitudinalVelocityRun;                //判断C1纵速曲线是否存在
    int C1longitudinalVelocityNum;

    float C5XGyroAngleIncreaseFloat;
    QVector<double> C5VXGyroAngleIncreaseFloat;      //存储C5的X陀螺增量数据
    QVector<double> C5VXGyroAngleIncreaseFloat_bk;      //存储C5的X陀螺增量数据
    int C5XGyroAngleIncreaseFloatRun;                //判断C5X陀螺增量曲线是否存在
    int C5XGyroAngleIncreaseFloatNum;

    float C5YGyroAngleIncreaseFloat;
    QVector<double> C5VYGyroAngleIncreaseFloat;      //存储C5的Y陀螺增量数据
    QVector<double> C5VYGyroAngleIncreaseFloat_bk;      //存储C5的Y陀螺增量数据
    int C5YGyroAngleIncreaseFloatRun;                //判断C5Y陀螺增量曲线是否存在
    int C5YGyroAngleIncreaseFloatNum;

    float C5ZGyroAngleIncreaseFloat;
    QVector<double> C5VZGyroAngleIncreaseFloat;      //存储C5的Z陀螺增量数据
    QVector<double> C5VZGyroAngleIncreaseFloat_bk;      //存储C5的Z陀螺增量数据
    int C5ZGyroAngleIncreaseFloatRun;                //判断C5Z陀螺增量曲线是否存在
    int C5ZGyroAngleIncreaseFloatNum;

    float C5XAccelerometerSpeedIncrementFloat;
    QVector<double> C5VXAccelerometerSpeedIncrementFloat;      //存储C5的X加表增量数据
    QVector<double> C5VXAccelerometerSpeedIncrementFloat_bk;      //存储C5的X加表增量数据
    int C5XAccelerometerSpeedIncrementFloatRun;                //判断C5X加表增量曲线是否存在
    int C5XAccelerometerSpeedIncrementFloatNum;

    float C5YAccelerometerSpeedIncrementFloat;
    QVector<double> C5VYAccelerometerSpeedIncrementFloat;      //存储C5的Y加表增量数据
    QVector<double> C5VYAccelerometerSpeedIncrementFloat_bk;      //存储C5的Y加表增量数据
    int C5YAccelerometerSpeedIncrementFloatRun;                //判断C5Y加表增量曲线是否存在
    int C5YAccelerometerSpeedIncrementFloatNum;

    float C5ZAccelerometerSpeedIncrementFloat;
    QVector<double> C5VZAccelerometerSpeedIncrementFloat;      //存储C5的Z加表增量数据
    QVector<double> C5VZAccelerometerSpeedIncrementFloat_bk;      //存储C5的Z加表增量数据
    int C5ZAccelerometerSpeedIncrementFloatRun;                //判断C5Z加表增量曲线是否存在
    int C5ZAccelerometerSpeedIncrementFloatNum;

    float C5XgyroCompensatedAngleIncrementFloat;
    QVector<double> C5VXgyroCompensatedAngleIncrementFloat;      //存储C5的x陀螺1s补偿后角增量数据
    QVector<double> C5VXgyroCompensatedAngleIncrementFloat_bk;      //存储C5的x陀螺1s补偿后角增量数据
    int C5XgyroCompensatedAngleIncrementFloatRun;                //判断C5的x陀螺1s补偿后角增量曲线是否存在
    int C5XgyroCompensatedAngleIncrementFloatNum;

    float C5YgyroCompensatedAngleIncrementFloat;
    QVector<double> C5VYgyroCompensatedAngleIncrementFloat;      //存储C5的Y陀螺1s补偿后角增量数据
    QVector<double> C5VYgyroCompensatedAngleIncrementFloat_bk;      //存储C5的Y陀螺1s补偿后角增量数据
    int C5YgyroCompensatedAngleIncrementFloatRun;                //判断C5的Y陀螺1s补偿后角增量曲线是否存在
    int C5YgyroCompensatedAngleIncrementFloatNum;

    float C5ZgyroCompensatedAngleIncrementFloat;
    QVector<double> C5VZgyroCompensatedAngleIncrementFloat;      //存储C5的Z陀螺1s补偿后角增量数据
    QVector<double> C5VZgyroCompensatedAngleIncrementFloat_bk;      //存储C5的Z陀螺1s补偿后角增量数据
    int C5ZgyroCompensatedAngleIncrementFloatRun;                //判断C5的Z陀螺1s补偿后角增量曲线是否存在
    int C5ZgyroCompensatedAngleIncrementFloatNum;

    float C5XAccVelocityIncrementFloat;
    QVector<double> C5VXAccVelocityIncrementFloat;      //存储C5的x加速度计1s补偿后速度增量数据
    QVector<double> C5VXAccVelocityIncrementFloat_bk;      //存储C5的x加速度计1s补偿后速度增量数据
    int C5XAccVelocityIncrementFloatRun;                //判断C5的x加速度计1s补偿后速度增量曲线是否存在
    int C5XAccVelocityIncrementFloatNum;

    float C5YAccVelocityIncrementFloat;
    QVector<double> C5VYAccVelocityIncrementFloat;      //存储C5的Y加速度计1s补偿后速度增量数据
    QVector<double> C5VYAccVelocityIncrementFloat_bk;      //存储C5的Y加速度计1s补偿后速度增量数据
    int C5YAccVelocityIncrementFloatRun;                //判断C5的Y加速度计1s补偿后速度增量曲线是否存在
    int C5YAccVelocityIncrementFloatNum;

    float C5ZAccVelocityIncrementFloat;
    QVector<double> C5VZAccVelocityIncrementFloat;      //存储C5的Z加速度计1s补偿后速度增量数据
    QVector<double> C5VZAccVelocityIncrementFloat_bk;      //存储C5的Z加速度计1s补偿后速度增量数据
    int C5ZAccVelocityIncrementFloatRun;                //判断C5的Z加速度计1s补偿后速度增量曲线是否存在
    int C5ZAccVelocityIncrementFloatNum;

    float C5XgyroDifFrequency;
    QVector<double> C5VXgyroDifFrequency;      //存储C5的X陀螺差频数据
    QVector<double> C5VXgyroDifFrequency_bk;      //存储C5的X陀螺差频数据
    int C5XgyroDifFrequencyRun;                //判断C5的X陀螺差频曲线是否存在
    int C5XgyroDifFrequencyNum;

    float C5YgyroDifFrequency;
    QVector<double> C5VYgyroDifFrequency;      //存储C5的Y陀螺差频数据
    QVector<double> C5VYgyroDifFrequency_bk;      //存储C5的Y陀螺差频数据
    int C5YgyroDifFrequencyRun;                //判断C5的Y陀螺差频曲线是否存在
    int C5YgyroDifFrequencyNum;

    float C5ZgyroDifFrequency;
    QVector<double> C5VZgyroDifFrequency;      //存储C5的Z陀螺差频数据
    QVector<double> C5VZgyroDifFrequency_bk;      //存储C5的Z陀螺差频数据
    int C5ZgyroDifFrequencyRun;                //判断C5的Z陀螺差频曲线是否存在
    int C5ZgyroDifFrequencyNum;

    float C5XaccelerometerDifFre;
    QVector<double> C5VXaccelerometerDifFre;      //存储C5的X加速度计差频数据
    QVector<double> C5VXaccelerometerDifFre_bk;      //存储C5的X加速度计差频数据
    int C5XaccelerometerDifFreRun;                //判断C5的X加速度计差频曲线是否存在
    int C5XaccelerometerDifFreNum;

    float C5YaccelerometerDifFre;
    QVector<double> C5VYaccelerometerDifFre;      //存储C5的Y加速度计差频数据
    QVector<double> C5VYaccelerometerDifFre_bk;      //存储C5的Y加速度计差频数据
    int C5YaccelerometerDifFreRun;                //判断C5的Y加速度计差频曲线是否存在
    int C5YaccelerometerDifFreNum;

    float C5ZaccelerometerDifFre;
    QVector<double> C5VZaccelerometerDifFre;      //存储C5的Z加速度计差频数据
    QVector<double> C5VZaccelerometerDifFre_bk;      //存储C5的Z加速度计差频数据
    int C5ZaccelerometerDifFreRun;                //判断C5的Z加速度计差频曲线是否存在
    int C5ZaccelerometerDifFreNum;

    float C5XgyroTemp1;
    QVector<double> C5VXgyroTemp1;      //存储C5的X陀螺温度1数据
    QVector<double> C5VXgyroTemp1_bk;      //存储C5的X陀螺温度1数据
    int C5XgyroTemp1Run;                //判断C5的X陀螺温度1是否存在
    int C5XgyroTemp1Num;

    float C5YgyroTemp1;
    QVector<double> C5VYgyroTemp1;      //存储C5的Y陀螺温度1数据
    QVector<double> C5VYgyroTemp1_bk;      //存储C5的Y陀螺温度1数据
    int C5YgyroTemp1Run;                //判断C5的Y陀螺温度1是否存在
    int C5YgyroTemp1Num;

    float C5ZgyroTemp1;
    QVector<double> C5VZgyroTemp1;      //存储C5的Z陀螺温度1数据
    QVector<double> C5VZgyroTemp1_bk;      //存储C5的Z陀螺温度1数据
    int C5ZgyroTemp1Run;                //判断C5的Z陀螺温度1曲线是否存在
    int C5ZgyroTemp1Num;

    float C5XAccelerometerTemperture;
    QVector<double> C5VXAccelerometerTemperture;      //存储C5的X加速度计温度1数据
    QVector<double> C5VXAccelerometerTemperture_bk;      //存储C5的X加速度计温度1数据
    int C5XAccelerometerTempertureRun;                //判断C5的X加速度计温度1是否存在
    int C5XAccelerometerTempertureNum;

    float C5YAccelerometerTemperture;
    QVector<double> C5VYAccelerometerTemperture;      //存储C5的Y加速度计温度1数据
    QVector<double> C5VYAccelerometerTemperture_bk;      //存储C5的Y加速度计温度1数据
    int C5YAccelerometerTempertureRun;                //判断C5的Y加速度计温度1是否存在
    int C5YAccelerometerTempertureNum;

    float C5ZAccelerometerTemperture;
    QVector<double> C5VZAccelerometerTemperture;      //存储C5的Z加速度计温度1数据
    QVector<double> C5VZAccelerometerTemperture_bk;      //存储C5的Z加速度计温度1数据
    int C5ZAccelerometerTempertureRun;                //判断C5的Z加速度计温度1曲线是否存在
    int C5ZAccelerometerTempertureNum;

    float C5XgyroTemp2;
    QVector<double> C5VXgyroTemp2;      //存储C5的X陀螺温度2数据
    QVector<double> C5VXgyroTemp2_bk;      //存储C5的X陀螺温度2数据
    int C5XgyroTemp2Run;                //判断C5的X陀螺温度2是否存在
    int C5XgyroTemp2Num;

    float C5YgyroTemp2;
    QVector<double> C5VYgyroTemp2;      //存储C5的Y陀螺温度2数据
    QVector<double> C5VYgyroTemp2_bk;      //存储C5的Y陀螺温度2数据
    int C5YgyroTemp2Run;                //判断C5的Y陀螺温度2是否存在
    int C5YgyroTemp2Num;

    float C5ZgyroTemp2;
    QVector<double> C5VZgyroTemp2;      //存储C5的Z陀螺温度2数据
    QVector<double> C5VZgyroTemp2_bk;      //存储C5的Z陀螺温度2数据
    int C5ZgyroTemp2Run;                //判断C5的Z陀螺温度2曲线是否存在
    int C5ZgyroTemp2Num;

    float C5XgyroAmplitudeJitter;
    QVector<double> C5VXgyroAmplitudeJitter;      //存储C5的X陀螺抖幅数据
    QVector<double> C5VXgyroAmplitudeJitter_bk;      //存储C5的X陀螺抖幅数据
    int C5XgyroAmplitudeJitterRun;                //判断C5的X陀螺抖幅曲线是否存在
    int C5XgyroAmplitudeJitterNum;

    float C5YgyroAmplitudeJitter;
    QVector<double> C5VYgyroAmplitudeJitter;      //存储C5的Y陀螺抖幅数据
    QVector<double> C5VYgyroAmplitudeJitter_bk;      //存储C5的Y陀螺抖幅数据
    int C5YgyroAmplitudeJitterRun;                //判断C5的Y陀螺抖幅曲线是否存在
    int C5YgyroAmplitudeJitterNum;

    float C5ZgyroAmplitudeJitter;
    QVector<double> C5VZgyroAmplitudeJitter;      //存储C5的Z陀螺抖幅数据
    QVector<double> C5VZgyroAmplitudeJitter_bk;      //存储C5的Z陀螺抖幅数据
    int C5ZgyroAmplitudeJitterRun;                //判断C5的Z陀螺抖幅曲线是否存在
    int C5ZgyroAmplitudeJitterNum;

    float C5XgyroAmpl1itudeFre;
    QVector<double> C5VXgyroAmpl1itudeFre;      //存储C5的X陀螺抖频数据
    QVector<double> C5VXgyroAmpl1itudeFre_bk;      //存储C5的X陀螺抖频数据
    int C5XgyroAmpl1itudeFreRun;                //判断C5的X陀螺抖频曲线是否存在
    int C5XgyroAmpl1itudeFreNum;

    float C5YgyroAmpl1itudeFre;
    QVector<double> C5VYgyroAmpl1itudeFre;      //存储C5的Y陀螺抖频数据
    QVector<double> C5VYgyroAmpl1itudeFre_bk;      //存储C5的Y陀螺抖频数据
    int C5YgyroAmpl1itudeFreRun;                //判断C5的Y陀螺抖频曲线是否存在
    int C5YgyroAmpl1itudeFreNum;

    float C5ZgyroAmpl1itudeFre;
    QVector<double> C5VZgyroAmpl1itudeFre;      //存储C5的Z陀螺抖频数据
    QVector<double> C5VZgyroAmpl1itudeFre_bk;      //存储C5的Z陀螺抖频数据
    int C5ZgyroAmpl1itudeFreRun;                //判断C5的Z陀螺抖频曲线是否存在
    int C5ZgyroAmpl1itudeFreNum;

    float C3longitude;
    QVector<double> C3Vlongitude;      //存储C3的GPS经度数据
    QVector<double> C3Vlongitude_bk;      //存储C3的GPS经度数据
    int C3longitudeRun;                //判断C3的GPS经度曲线是否存在
    int C3longitudeNum;

    float C3GPSlatitude;
    QVector<double> C3VGPSlatitude;      //存储C3的GPS纬度数据
    QVector<double> C3VGPSlatitude_bk;      //存储C3的GPS纬度数据
    int C3GPSlatitudeRun;                //判断C3的GPS纬度曲线是否存在
    int C3GPSlatitudeNum;

    float C3togetherSpeed;
    QVector<double> C3VtogetherSpeed;      //存储C3的GPS合速数据
    QVector<double> C3VtogetherSpeed_bk;      //存储C3的GPS合速数据
    int C3togetherSpeedRun;                //判断C3的GPS合速曲线是否存在
    int C3togetherSpeedNum;

    float C3headingAngle;
    QVector<double> C3VheadingAngle;      //存储C3的GPS航向数据
    QVector<double> C3VheadingAngle_bk;      //存储C3的GPS航向数据
    int C3headingAngleRun;                //判断C3的GPS航向曲线是否存在
    int C3headingAngleNum;

    float C3combinedEastSpeed;
    QVector<double> C3VcombinedEastSpeed;      //存储C3的GPS东速数据
    QVector<double> C3VcombinedEastSpeed_bk;      //存储C3的GPS东速数据
    int C3combinedEastSpeedRun;                //判断C3的GPS东速曲线是否存在
    int C3combinedEastSpeedNum;

    float C3combinedNorthSpeed;
    QVector<double> C3VcombinedNorthSpeed;      //存储C3的GPS北速数据
    QVector<double> C3VcombinedNorthSpeed_bk;      //存储C3的GPS北速数据
    int C3combinedNorthSpeedRun;                //判断C3的GPS北速曲线是否存在
    int C3combinedNorthSpeedNum;

    float C3waterX;
    QVector<double> C3VwaterX;      //存储C3的多普勒对水横向速度数据
    QVector<double> C3VwaterX_bk;      //存储C3的多普勒对水横向速度数据
    int C3waterXRun;                //判断C3的G多普勒对水横向速度曲线是否存在
    int C3waterXNum;

    float C3waterY;
    QVector<double> C3VwaterY;      //存储C3的多普勒对水纵向速度数据
    QVector<double> C3VwaterY_bk;      //存储C3的多普勒对水纵向速度数据
    int C3waterYRun;                //判断C3的G多普勒对水纵向速度曲线是否存在
    int C3waterYNum;

    float C3bottomX;
    QVector<double> C3VbottomX;      //存储C3的多普勒对底横向速度数据
    QVector<double> C3VbottomX_bk;      //存储C3的多普勒对底横向速度数据
    int C3bottomXRun;                //判断C3的G多普勒对底横向速度曲线是否存在
    int C3bottomXNum;

    float C3bottomY;
    QVector<double> C3VbottomY;      //存储C3的多普勒对底纵向速度数据
    QVector<double> C3VbottomY_bk;      //存储C3的多普勒对底纵向速度数据
    int C3bottomYRun;                //判断C3的G多普勒对底纵向速度曲线是否存在
    int C3bottomYNum;

    float C3electromagnetismSpeed;
    QVector<double> C3VelectromagnetismSpeed;      //存储C3的电磁速度数据
    QVector<double> C3VelectromagnetismSpeed_bk;      //存储C3的电磁速度数据
    int C3electromagnetismSpeedRun;                //判断C3的电磁速度曲线是否存在
    int C3electromagnetismSpeedNum;



    float C6UndampedRollAngleFloat;
    QVector<double> C6VC6UndampedRollAngleFloat;      //存储C6无阻尼横摇角
    QVector<double> C6VC6UndampedRollAngleFloat_bk;      //存储C6无阻尼横摇角
    int C6UndampedRollAngleFloatRun;                //判断C6无阻尼横摇角曲线是否存在
    int C6UndampedRollAngleFloatNum;

    float C6UndampedPitchAngleFloat;
    QVector<double> C6VC6UndampedPitchAngleFloat;      //存储C6的无阻尼纵摇角
    QVector<double> C6VC6UndampedPitchAngleFloat_bk;      //存储C6的无阻尼纵摇角
    int C6UndampedPitchAngleFloatRun;                //判断C6的无阻尼纵摇角曲线是否存在
    int C6UndampedPitchAngleFloatNum;

    float C6UndampedHeadingAngularFloat;
    QVector<double> C6VC6UndampedHeadingAngularFloat;      //存储C6的无阻尼航向角
    QVector<double> C6VC6UndampedHeadingAngularFloat_bk;      //存储C6的无阻尼航向角
    int C6UndampedHeadingAngularFloatRun;                //判断C6的无阻尼航向角曲线是否存在
    int C6UndampedHeadingAngularFloatNum;

    float C6UndampedNorthSpeedFloat;
    QVector<double> C6VC6UndampedNorthSpeedFloat;      //存储C6的无阻尼北速
    QVector<double> C6VC6UndampedNorthSpeedFloat_bk;      //存储C6的无阻尼北速
    int C6UndampedNorthSpeedFloatRun;                //判断C6的无阻尼北速是否存在
    int C6UndampedNorthSpeedFloatNum;

    float C6UndampedEastSpeedFloat;
    QVector<double> C6VC6UndampedEastSpeedFloat;      //存储C6的无阻尼东速
    QVector<double> C6VC6UndampedEastSpeedFloat_bk;      //存储C6的无阻尼东速
    int C6UndampedEastSpeedFloatRun;                //判断C6的无阻尼东速曲线是否存在
    int C6UndampedEastSpeedFloatNum;

    float C6VerticalVelocityFloat;
    QVector<double> C6VC6VerticalVelocityFloat;      //存储C6的无阻尼垂速
    QVector<double> C6VC6VerticalVelocityFloat_bk;      //存储C6的无阻尼垂速
    int C6VerticalVelocityFloatRun;                //判断C6的无阻尼垂速曲线是否存在
    int C6VerticalVelocityFloatNum;

    float C6UndampedLatFloat;
    QVector<double> C6VC6UndampedLatFloat;      //存储C6的无阻尼纬度
    QVector<double> C6VC6UndampedLatFloat_bk;      //存储C6的无阻尼纬度
    int C6UndampedLatFloatRun;                //判断C6的无阻尼纬度曲线是否存在
    int C6UndampedLatFloatNum;

    float C6UndampedLongFloat;
    QVector<double> C6VC6UndampedLongFloat;      //存储C6的无阻尼经度
    QVector<double> C6VC6UndampedLongFloat_bk;      //存储C6的无阻尼经度
    int C6UndampedLongFloatRun;                //判断C6的无阻尼经度曲线是否存在
    int C6UndampedLongFloatNum;

    float C6UndampedHeightFloat;
    QVector<double> C6VC6UndampedHeightFloat;      //存储C6的无阻尼高度
    QVector<double> C6VC6UndampedHeightFloat_bk;      //存储C6的无阻尼高度
    int C6UndampedHeightFloatRun;                //判断C6的无阻尼高度曲线是否存在
    int C6UndampedHeightFloatNum;

    float C6XGroyFloat;
    QVector<double> C6VC6XGroyFloat;      //存储C6的X陀螺零偏
    QVector<double> C6VC6XGroyFloat_bk;      //存储C6的X陀螺零偏
    int C6XGroyFloatRun;                //判断C6的X陀螺零偏曲线是否存在
    int C6XGroyFloatNum;

    float C6YGroyFloat;
    QVector<double> C6VC6YGroyFloat;      //存储C6的Y陀螺零偏
    QVector<double> C6VC6YGroyFloat_bk;      //存储C6的Y陀螺零偏
    int C6YGroyFloatRun;                //判断C6的Y陀螺零偏曲线是否存在
    int C6YGroyFloatNum;

    float C6ZGroyFloat;
    QVector<double> C6VC6ZGroyFloat;      //存储C6的Z陀螺零偏
    QVector<double> C6VC6ZGroyFloat_bk;      //存储C6的Z陀螺零偏
    int C6ZGroyFloatRun;                //判断C6的Z陀螺零偏曲线是否存在
    int C6ZGroyFloatNum;

    float C6XAccelerometerFloat;
    QVector<double> C6VC6XAccelerometerFloat;      //存储C6的X加速度计零偏
    QVector<double> C6VC6XAccelerometerFloat_bk;      //存储C6的X加速度计零偏
    int C6XAccelerometerFloatRun;                //判断C6的X加速度计零偏曲线是否存在
    int C6XAccelerometerFloatNum;

    float C6YAccelerometerFloat;
    QVector<double> C6VC6YAccelerometerFloat;      //存储C6的Y加速度计零偏
    QVector<double> C6VC6YAccelerometerFloat_bk;      //存储C6的Y加速度计零偏
    int C6YAccelerometerFloatRun;                //判断C6的Y加速度计零偏曲线是否存在
    int C6YAccelerometerFloatNum;

    float C6ZAccelerometerFloat;
    QVector<double> C6VC6ZAccelerometerFloat;      //存储C6的Z加速度计零偏
    QVector<double> C6VC6ZAccelerometerFloat_bk;      //存储C6的Z加速度计零偏
    int C6ZAccelerometerFloatRun;                //判断C6的Z加速度计零偏曲线是否存在
    int C6ZAccelerometerFloatNum;


    float eastSpeedError;
    QVector<double> VeastSpeedError;      //存储东速误差
    QVector<double> VeastSpeedError_bk;      //存储东速误差
    int eastSpeedErrorRun;                //判断东速误差曲线是否存在
    int eastSpeedErrorNum;

    float northSpeedError;
    QVector<double> VnorthSpeedError;      //存储北速误差
    QVector<double> VnorthSpeedError_bk;      //存储北速误差
    int northSpeedErrorRun;                //判断北速误差曲线是否存在
    int northSpeedErrorNum;

    float togetherSpeedError;
    QVector<double> VtogetherSpeedError;      //存储合速误差
    QVector<double> VtogetherSpeedError_bk;      //存储合速速误差
    int togetherSpeedErrorRun;                //判断合速速误差曲线是否存在
    int togetherSpeedErrorNum;

    float latitudeError;
    QVector<double> VlatitudeError;      //存储纬度误差
    QVector<double> VlatitudeError_bk;      //存储纬度误差
    int latitudeErrorRun;                //判断纬度误差曲线是否存在
    int latitudeErrorNum;

    float longitudeError;
    QVector<double> VlongitudeError;      //存储经度误差
    QVector<double> VlongitudeError_bk;      //存储经度误差
    int longitudeErrorRun;                //判断经度误差曲线是否存在
    int longitudeErrorNum;

    float positionError;
    QVector<double> VpositionError;      //存储位置误差
    QVector<double> VpositionError_bk;      //存储位置误差
    int positionErrorRun;                //判断位置误差曲线是否存在
    int positionErrorNum;

    QTimer *qGetdataTime;
    QTimer *qDrawTime;
    QFile C1fileSave;
    QFile C2fileSave;
    QFile C3fileSave;
    QFile C5fileSave;
    QFile C6fileSave;
    QFile C8fileSave;

    int fileSaveNum;        //保存文件数
    UINT64  noVaildMessage;
    int restartTime;

    QVector<double> valueVector1;
    QVector<double> valueVector2;
    QVector<double> valueVector3;
    QVector<double> valueVector4;
    QVector<double> valueVector5;
    QVector<double> valueVector6;
    QVector<double> valueVector7;
    QVector<double> valueVector8;
    QVector<double> valueVector9;
    QVector<double> valueVector10;
    QVector<double> valueVector11;
    QVector<double> valueVector12;
    QVector<double> valueVector13;
    QVector<double> valueVector14;
    QVector<double> valueVector15;
    QVector<double> valueVector16;
    QVector<double> valueVector17;
    QVector<double> valueVector18;
    QVector<double> valueVector19;
    QVector<double> valueVector20;
    QVector<double> valueVector21;
    QVector<double> valueVector22;
    QVector<double> valueVector23;
    QVector<double> valueVector24;
    QVector<double> valueVector25;
    QVector<double> valueVector26;
    QVector<double> valueVector27;
    QVector<double> valueVector28;
    QVector<double> valueVector29;
    QVector<double> valueVector30;
    QVector<double> valueVector31;
    QVector<double> valueVector32;
    QVector<double> valueVector33;
    QVector<double> valueVector34;
    QVector<double> valueVector35;
    QVector<double> valueVector36;
    QVector<double> valueVector37;
    QVector<double> valueVector38;
    QVector<double> valueVector39;
    QVector<double> valueVector40;
    QVector<double> valueVector41;
    QVector<double> valueVector42;
    QVector<double> valueVector43;
    QVector<double> valueVector44;
    QVector<double> valueVector45;
    QVector<double> valueVector46;
    QVector<double> valueVector47;
    QVector<double> valueVector48;
    QVector<double> valueVector49;
    QVector<double> valueVector50;
    QVector<double> valueVector51;
    QVector<double> valueVector52;
    QVector<double> valueVector53;
    QVector<double> valueVector54;
    QVector<double> valueVector55;
    QVector<double> valueVector56;
    QVector<double> valueVector57;
    QVector<double> valueVector58;
    QVector<double> valueVector59;
    QVector<double> valueVector60;
    QVector<double> valueVector61;
    QVector<double> valueVector62;
    QVector<double> valueVector63;
    QVector<double> valueVector64;
    QVector<double> valueVector65;
    QVector<double> valueVector66;
    QVector<double> valueVector67;
    QVector<double> valueVector68;
    QVector<double> valueVector69;
    QVector<double> valueVector70;
    QVector<double> valueVector71;
    QVector<double> valueVector72;
    QVector<double> valueVector73;
    QVector<double> valueVector74;
    QVector<double> valueVector75;
    QVector<double> valueVector76;
    QVector<double> valueVector77;
    QVector<double> valueVector78;
    QVector<double> valueVector79;
    QVector<double> valueVector80;
    QVector<double> valueVector81;
    QVector<double> valueVector82;
    QVector<double> valueVector83;
    QVector<double> valueVector84;
    QVector<double> valueVector85;
    QVector<double> valueVector86;
    QVector<double> valueVector87;

    QVector<double> valueVector1X;
    QVector<double> valueVector2X;
    QVector<double> valueVector3X;
    QVector<double> valueVector4X;
    QVector<double> valueVector5X;
    QVector<double> valueVector6X;
    QVector<double> valueVector7X;
    QVector<double> valueVector8X;
    QVector<double> valueVector9X;
    QVector<double> valueVector10X;
    QVector<double> valueVector11X;
    QVector<double> valueVector12X;
    QVector<double> valueVector13X;
    QVector<double> valueVector14X;
    QVector<double> valueVector15X;
    QVector<double> valueVector16X;
    QVector<double> valueVector17X;
    QVector<double> valueVector18X;
    QVector<double> valueVector19X;
    QVector<double> valueVector20X;
    QVector<double> valueVector21X;
    QVector<double> valueVector22X;
    QVector<double> valueVector23X;
    QVector<double> valueVector24X;
    QVector<double> valueVector25X;
    QVector<double> valueVector26X;
    QVector<double> valueVector27X;
    QVector<double> valueVector28X;
    QVector<double> valueVector29X;
    QVector<double> valueVector30X;
    QVector<double> valueVector31X;
    QVector<double> valueVector32X;
    QVector<double> valueVector33X;
    QVector<double> valueVector34X;
    QVector<double> valueVector35X;
    QVector<double> valueVector36X;
    QVector<double> valueVector37X;
    QVector<double> valueVector38X;
    QVector<double> valueVector39X;
    QVector<double> valueVector40X;
    QVector<double> valueVector41X;
    QVector<double> valueVector42X;
    QVector<double> valueVector43X;
    QVector<double> valueVector44X;
    QVector<double> valueVector45X;
    QVector<double> valueVector46X;
    QVector<double> valueVector47X;
    QVector<double> valueVector48X;
    QVector<double> valueVector49X;
    QVector<double> valueVector50X;
    QVector<double> valueVector51X;
    QVector<double> valueVector52X;
    QVector<double> valueVector53X;
    QVector<double> valueVector54X;
    QVector<double> valueVector55X;
    QVector<double> valueVector56X;
    QVector<double> valueVector57X;
    QVector<double> valueVector58X;
    QVector<double> valueVector59X;
    QVector<double> valueVector60X;
    QVector<double> valueVector61X;
    QVector<double> valueVector62X;
    QVector<double> valueVector63X;
    QVector<double> valueVector64X;
    QVector<double> valueVector65X;
    QVector<double> valueVector66X;
    QVector<double> valueVector67X;
    QVector<double> valueVector68X;
    QVector<double> valueVector69X;
    QVector<double> valueVector70X;
    QVector<double> valueVector71X;
    QVector<double> valueVector72X;
    QVector<double> valueVector73X;
    QVector<double> valueVector74X;
    QVector<double> valueVector75X;
    QVector<double> valueVector76X;
    QVector<double> valueVector77X;
    QVector<double> valueVector78X;
    QVector<double> valueVector79X;
    QVector<double> valueVector80X;
    QVector<double> valueVector81X;
    QVector<double> valueVector82X;
    QVector<double> valueVector83X;
    QVector<double> valueVector84X;
    QVector<double> valueVector85X;
    QVector<double> valueVector86X;
    QVector<double> valueVector87X;

    int valueVector1Use;
    int valueVector2Use;
    int valueVector3Use;
    int valueVector4Use;
    int valueVector5Use;
    int valueVector6Use;
    int valueVector6_2Use;
    int valueVector6_3Use;
    UINT64 restart;
    int datanum2;

    QVector<double> X;



    float C8Height;
    QVector<double> C8VC8Height;      //存储C8的导航高度
    QVector<double> C8VC8Height_bk;
    int C8HeightRun;
    int C8HeightNum;

    float C8UpSpeed;                //存储C8的导航天速
    QVector<double> C8VC8UpSpeed;
    QVector<double> C8VC8UpSpeed_bk;
    int C8UpSpeedRun;
    int C8UpSpeedNum;

    float C8GPSHeight;
    QVector<double> C8VC8GPSHeight;      //存储C8的GPS高度
    QVector<double> C8VC8GPSHeight_bk;
    int C8GPSHeightRun;
    int C8GPSHeightNum;

    float C8GPTUpSpeed;
    QVector<double> C8VC8GPTUpSpeed;      //存储C8的GPS天速
    QVector<double> C8VC8GPTUpSpeed_bk;
    int C8GPTUpSpeedRun;
    int C8GPTUpSpeedNum;

    float C8LogDownSpeed2Ground;
    QVector<double> C8VC8LogDownSpeed2Ground;      //存储C8的计程仪Z速（向下速度，对地）
    QVector<double> C8VC8LogDownSpeed2Ground_bk;
    int C8LogDownSpeed2GroundRun;
    int C8LogDownSpeed2GroundNum;

    float C8LogDownSpeed2Water;
    QVector<double> C8VC8LogDownSpeed2Water;      //存储C8的计程仪Z速（向下速度，对水）
    QVector<double> C8VC8LogDownSpeed2Water_bk;
    int C8LogDownSpeed2WaterRun;
    int C8LogDownSpeed2WaterNum;
protected:
    //声明
    void mouseDoubleClickEvent(QMouseEvent*);

};
#endif // MAINWINDOW_H
