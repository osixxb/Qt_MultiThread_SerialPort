#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialworker.h"

#define addDataPeri  1000
#define drawDataPeri 1000
#define handleResultDelay  200

int hasDataVaildC1;
int hasDataVaildC2;
int hasDataVaildC3;
int hasDataVaildC8;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_xLength(0),C1m_xLength(0),C3m_xLength(0),C5m_xLength(0),C6m_xLength(0),C8m_xLength(0),SaveFileRecord(400000),dataInvaildRecord(0),isDegree(1),latitude(0),C1latitudeCurveRun(0),headingAngle(0),C1headingAngleRun(0),longitude(0),C1longitudeRun(0),rollAngle(0),C1rollAngleRun(0),pitchAngle(0),C1pitchAngleRun(0),northSpeed(0),C1northSpeedRun(0),eastSpeed(0),C1eastSpeedRun(0),headingAngularSpeed(0),C1headingAngularSpeedRun(0),rollAngleSpeed(0),C1rollAngleSpeedRun(0),pitchAngleSpeed(0),C1pitchAngleSpeedRun(0),
      heave(0),C1heaveRun(0),verticalVelocity(0),C1verticalVelocityRun(0),sway(0),C1swayRun(0),transverseVelocity(0),C1transverseVelocityRun(0),surge(0),C1surgeRun(0),longitudinalVelocity(0),C1longitudinalVelocityRun(0),C5XGyroAngleIncreaseFloat(0),C5XGyroAngleIncreaseFloatRun(0),C5YGyroAngleIncreaseFloat(0),C5YGyroAngleIncreaseFloatRun(0),C5ZGyroAngleIncreaseFloat(0),C5ZGyroAngleIncreaseFloatRun(0),
      C5XAccelerometerSpeedIncrementFloat(0),C5XAccelerometerSpeedIncrementFloatRun(0),C5YAccelerometerSpeedIncrementFloat(0),C5YAccelerometerSpeedIncrementFloatRun(0),C5ZAccelerometerSpeedIncrementFloat(0),C5ZAccelerometerSpeedIncrementFloatRun(0),
      C5XgyroCompensatedAngleIncrementFloat(0),C5XgyroCompensatedAngleIncrementFloatRun(0),C5YgyroCompensatedAngleIncrementFloat(0),C5YgyroCompensatedAngleIncrementFloatRun(0),C5ZgyroCompensatedAngleIncrementFloat(0),C5ZgyroCompensatedAngleIncrementFloatRun(0),
      C5XAccVelocityIncrementFloat(0),C5XAccVelocityIncrementFloatRun(0),C5YAccVelocityIncrementFloat(0),C5YAccVelocityIncrementFloatRun(0),C5ZAccVelocityIncrementFloat(0),C5ZAccVelocityIncrementFloatRun(0),
      C5XgyroDifFrequency(0),C5XgyroDifFrequencyRun(0),C5YgyroDifFrequency(0),C5YgyroDifFrequencyRun(0),C5ZgyroDifFrequency(0),C5ZgyroDifFrequencyRun(0),
      C5XaccelerometerDifFre(0),C5XaccelerometerDifFreRun(0),C5YaccelerometerDifFre(0),C5YaccelerometerDifFreRun(0),C5ZaccelerometerDifFre(0),C5ZaccelerometerDifFreRun(0),
      C5XgyroTemp1(0),C5XgyroTemp1Run(0),C5YgyroTemp1(0),C5YgyroTemp1Run(0),C5ZgyroTemp1(0),C5ZgyroTemp1Run(0),
      C5XAccelerometerTemperture(0),C5XAccelerometerTempertureRun(0),C5YAccelerometerTemperture(0),C5YAccelerometerTempertureRun(0),C5ZAccelerometerTemperture(0),C5ZAccelerometerTempertureRun(0),
      C5XgyroTemp2(0),C5XgyroTemp2Run(0),C5YgyroTemp2(0),C5YgyroTemp2Run(0),C5ZgyroTemp2(0),C5ZgyroTemp2Run(0),
      C5XgyroAmplitudeJitter(0),C5XgyroAmplitudeJitterRun(0),C5YgyroAmplitudeJitter(0),C5YgyroAmplitudeJitterRun(0),C5ZgyroAmplitudeJitter(0),C5ZgyroAmplitudeJitterRun(0),
      C5XgyroAmpl1itudeFre(0),C5XgyroAmpl1itudeFreRun(0),C5YgyroAmpl1itudeFre(0),C5YgyroAmpl1itudeFreRun(0),C5ZgyroAmpl1itudeFre(0),C5ZgyroAmpl1itudeFreRun(0),
      C3longitude(0),C3longitudeRun(0),C3GPSlatitude(0),C3GPSlatitudeRun(0),
      C3togetherSpeed(0),C3togetherSpeedRun(0),C3headingAngle(0),C3headingAngleRun(0),C3combinedEastSpeed(0),C3combinedEastSpeedRun(0),C3combinedNorthSpeed(0),C3combinedNorthSpeedRun(0),
      C3waterX(0),C3waterXRun(0),C3waterY(0),C3waterYRun(0),C3bottomX(0),C3bottomXRun(0),C3bottomY(0),C3bottomYRun(0),C3electromagnetismSpeed(0),C3electromagnetismSpeedRun(0),C6UndampedRollAngleFloatRun(0),C6UndampedPitchAngleFloatRun(0),C6UndampedHeadingAngularFloatRun(0),C6UndampedNorthSpeedFloatRun(0),C6UndampedEastSpeedFloatRun(0),C6VerticalVelocityFloatRun(0),C6UndampedLatFloatRun(0),C6UndampedLongFloatRun(0),C6UndampedHeightFloatRun(0),
      C6XGroyFloat(0),C6XGroyFloatRun(0),C6YGroyFloat(0),C6YGroyFloatRun(0),C6ZGroyFloat(0),C6ZGroyFloatRun(0),C6XAccelerometerFloat(0),C6XAccelerometerFloatRun(0),C6YAccelerometerFloat(0),C6YAccelerometerFloatRun(0),C6ZAccelerometerFloat(0),C6ZAccelerometerFloatRun(0),
      eastSpeedError(0),eastSpeedErrorRun(0),northSpeedError(0),northSpeedErrorRun(0),togetherSpeedError(0),togetherSpeedErrorRun(0),latitudeError(0),latitudeErrorRun(0),longitudeError(0),longitudeErrorRun(0),positionError(0),positionErrorRun(0),noVaildMessage(0),restartTime(0),restart(200),datanum2(0),C8Height(0),C8HeightRun(0),C8UpSpeed(0),C8UpSpeedRun(0),C8GPSHeight(0),C8GPSHeightRun(0),C8GPTUpSpeed(0),C8GPTUpSpeedRun(0),C8LogDownSpeed2Ground(0),C8LogDownSpeed2GroundRun(0),C8LogDownSpeed2Water(0),C8LogDownSpeed2WaterRun(0),graphPointNum(0)

{
    ui->setupUi(this);
    this->setLED1(ui->label_69,1,15);

    this->setWindowTitle("惯导调试上位机v3.2.2");
    ui->comboBox->setVisible(true);
    ui->comboBox_2->setVisible(false);

    ui->customPlot2->showTracer(true);
    ui->customPlot3->showTracer(true);
    // 检查目录是否存在，若不存在则新建
    QDir dir;

    if (!dir.exists("./curve"))
    {
        bool res = dir.mkpath("./curve");
        if(!res)
        {
            QMessageBox::warning(NULL, "提示", "创建曲线文件夹失败！");
        }
    }

    // 检查目录是否存在，若不存在则新建
    QDir dir2;
    if (!dir2.exists("./history"))
    {
        bool res = dir2.mkpath("./history");
        if(!res)
        {
            QMessageBox::warning(NULL, "提示", "创建历史数据文件夹失败！");
            return;
        }
    }

    paraQuery = new QueryDialog(this);              //状态切换
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    paraQuery->setWindowFlags(flags);

    bookOriData = new BookOriDataDialog(this);      //原始数据
    bookOriData->setWindowFlags(flags);

    attitudeData = new AttitudeDialog(this);        //姿态零位

    attitudeData->setWindowFlags(flags);

    shipLoadData = new ShopLoadDialog(this);            //装舰参数
    shipLoadData->setWindowFlags(flags);

    calbratParaData = new CalibratParaDialog(this);     //标定参数
    calbratParaData->setWindowFlags(flags);

    tempCompenCoeffData = new TempCompenCoeffDialog(this);     //温补系数
    tempCompenCoeffData->setWindowFlags(flags);

    leverArmData = new LeverArmDialog(this);     //杆臂装订
    leverArmData->setWindowFlags(flags);

    serialInterfaceData = new SerialInterfaceDialog(this);     //串口接口装订,暂时不需要实现
    serialInterfaceData->setWindowFlags(flags);

    sysHeightData = new sysHeightDialog(this);     //系统高度装订
    sysHeightData->setWindowFlags(flags);

    sysBaseGData = new sysBaseGDialog(this);
    sysBaseGData->setWindowFlags(flags);

    handleResultDelayData = new handleResultDelayDialog(this);
    sysBaseGData->setWindowFlags(flags);

    //this->resize(QSize(1195,720));
    qtime = new QTimer(this);
    qtime->setInterval(50);


    qDrawTime = new QTimer(this);
    qDrawTime->setInterval(drawDataPeri);

    if(1)
    {
        ui->tableWidget->setStyleSheet("QTableWidget{background-color.rgb(200,200,200)}");
        ui->tableWidget->verticalHeader()->setVisible(true);
        ui->tableWidget->horizontalHeader()->setVisible(true);

        ui->tableWidget->setColumnWidth(0, 125);
        ui->tableWidget->setColumnWidth(1, 125);
        ui->tableWidget->setColumnWidth(2, 125);
        ui->tableWidget->setColumnWidth(3, 125);
        ui->tableWidget->setColumnWidth(4, 125);
        ui->tableWidget->setColumnWidth(5, 125);
        ui->tableWidget->setColumnWidth(6, 125);
        ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_2->horizontalHeader()->setDefaultSectionSize(139);
        ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_3->horizontalHeader()->setDefaultSectionSize(102);
        ui->tableWidget_4->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_4->horizontalHeader()->setDefaultSectionSize(117);
        ui->tableWidget_6->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_6->horizontalHeader()->setDefaultSectionSize(167);
        ui->tableWidget_7->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_7->horizontalHeader()->setDefaultSectionSize(140);

        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_7->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_8->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_9->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        ui->checkBox->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_2->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_82->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");

        ui->checkBox_3->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_4->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_5->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_6->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_7->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_8->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_9->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_83->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
        ui->checkBox_10->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_11->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_12->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_13->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_14->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_15->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_16->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_17->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_18->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_19->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_20->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_21->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_22->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_23->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_24->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_25->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_26->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_27->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_28->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_29->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_31->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_30->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_32->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_33->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_34->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_37->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_35->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_36->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_40->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_38->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_39->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_42->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_43->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_41->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_45->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_46->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_44->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_48->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_49->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_47->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_51->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_54->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_50->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_52->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_53->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_60->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
         ui->checkBox_84->setStyleSheet("QCheckBox{color:rgb(0,71,75)}");
         ui->checkBox_87->setStyleSheet("QCheckBox{color:rgb(0,200,244)}");

        ui->checkBox_59->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_56->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_57->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_55->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_58->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_85->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
        ui->checkBox_86->setStyleSheet("QCheckBox{color:rgb(0,71,75)}");

        ui->checkBox_61->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_63->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_62->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_65->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_64->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_66->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_67->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_69->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_68->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_70->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_72->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_71->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_73->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_74->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_75->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

        ui->checkBox_76->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_77->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_78->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

        ui->checkBox_79->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_80->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_81->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
        /*********************************************************************************/

        ui->checkBox_91->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_88->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_93->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
        ui->checkBox_90->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_89->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_92->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

        ui->checkBox_94->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_95->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_96->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_97->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_98->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_99->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");


        ui->checkBox_100->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_101->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_102->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_106->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_108->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
        ui->checkBox_103->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_105->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_104->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_107->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");


        ui->checkBox_109->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_110->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
        ui->checkBox_111->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_112->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_113->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_114->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

        ui->checkBox_115->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_116->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_117->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

        ui->checkBox_118->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_119->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_120->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_121->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_122->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_123->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_124->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_125->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_126->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_127->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_128->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_129->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_130->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_131->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_132->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_133->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_134->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_135->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_136->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_137->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_138->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_139->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_140->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_141->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_142->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_143->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_144->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_145->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_146->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_147->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_148->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_149->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_150->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_151->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_152->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_153->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
        ui->checkBox_154->setStyleSheet("QCheckBox{color:rgb(0,71,75)}");
        ui->checkBox_155->setStyleSheet("QCheckBox{color:rgb(0,200,244)}");

        ui->checkBox_156->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_157->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_158->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_159->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_160->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_161->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
        ui->checkBox_162->setStyleSheet("QCheckBox{color:rgb(0,71,75)}");

        ui->checkBox_163->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_164->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_165->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_166->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_167->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_168->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_169->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_170->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_171->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_172->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_173->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_174->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    }


    InitSerialPortName();

    // 状态切换装订和日志打印
    connect(paraQuery, &QueryDialog::statesChangeCMD,this, &MainWindow::doDataSendWork);
    connect(paraQuery, &QueryDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 初始数据装订和日志打印
    connect(bookOriData, &BookOriDataDialog::OriDataCMD,this, &MainWindow::doDataSendWork);
    connect(bookOriData, &BookOriDataDialog::bookLogCMD,this, &MainWindow::bookLog);


    // 姿态零位装订和日志打印
    connect(attitudeData, &AttitudeDialog::attitudeDataCMD,this, &MainWindow::doDataSendWork);
    connect(attitudeData, &AttitudeDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 舰艇参数装订和日志打印
    connect(shipLoadData, &ShopLoadDialog::systemIDCMD,this, &MainWindow::doDataSendWork);
    connect(shipLoadData, &ShopLoadDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 陀螺标定参数装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::GyroParaCMD,this, &MainWindow::doDataSendWork);
    connect(calbratParaData, &CalibratParaDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 加速度计标定参数装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::AccelerometerParaCMD,this, &MainWindow::doDataSendWork);

    // 陀螺等效零偏装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::GyroEqZeroBiasCMD,this, &MainWindow::doDataSendWork);

    //陀螺温补系数装订和日志打印
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::GyroTempComCoeffCMD,this, &MainWindow::doDataSendWork);
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::bookLogCMD,this, &MainWindow::bookLog);

    //加计温补系数装订和日志打印
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::AccelerometerComCoeffCMD,this, &MainWindow::doDataSendWork);

    //杆臂装订和日志打印
    connect(leverArmData, &LeverArmDialog::leverArmDataCMD,this, &MainWindow::doDataSendWork);
    connect(leverArmData, &LeverArmDialog::bookLogCMD,this, &MainWindow::bookLog);

    //系统高度装订和日志打印
    connect(sysHeightData, &sysHeightDialog::sysHeightDataCMD,this, &MainWindow::doDataSendWork);
    connect(sysHeightData, &sysHeightDialog::bookLogCMD,this, &MainWindow::bookLog);

    //系统基准重力值装订和日志打印
    connect(sysBaseGData, &sysBaseGDialog::sysBaseGDataCMD,this, &MainWindow::doDataSendWork);
    connect(sysBaseGData, &sysBaseGDialog::bookLogCMD,this, &MainWindow::bookLog);

    //串口接口装订
    connect(serialInterfaceData, &SerialInterfaceDialog::serialInterCMD,this, &MainWindow::doDataSendWork);


    //读取数据(采用定时器读取数据，不采用事件，方便移植到linux)
    connect(qtime,SIGNAL(timeout()),this,SLOT(handleResults()));
    connect(qDrawTime,SIGNAL(timeout()),this,SLOT(drawCurveLatitude()));   //每秒绘图

    this->setStyleSheet("QMainWindow{color:rgb(200,200,200)}");
    init_darw2();
}

//void MainWindow::getCurveData()
//{
//    curveX.append(m_xLength);
//    C1Vlatitude.append(latitude);

//    C1VheadingAngle.append(headingAngle);
//    C1Vlongitude.append(longitude);
//    C1VrollAngle.append(rollAngle);
//    C1VpitchAngle.append(pitchAngle);
//    C1VnorthSpeed.append(northSpeed);
//    C1VeastSpeed.append(eastSpeed);

//    C1VheadingAngularSpeed.append(headingAngularSpeed);
//    C1VrollAngleSpeed.append(rollAngleSpeed);
//    C1VpitchAngleSpeed.append(pitchAngleSpeed);

//    C1Vheave.append(heave);
//    C1VverticalVelocity.append(verticalVelocity);
//    C1Vsway.append(sway);
//    C1VtransverseVelocity.append(transverseVelocity);
//    C1Vsurge.append(surge);
//    C1VlongitudinalVelocity.append(longitudinalVelocity);


//    C5VXGyroAngleIncreaseFloat.append(C5XGyroAngleIncreaseFloat);
//    C5VYGyroAngleIncreaseFloat.append(C5YGyroAngleIncreaseFloat);
//    C5VZGyroAngleIncreaseFloat.append(C5ZGyroAngleIncreaseFloat);

//    C5VXAccelerometerSpeedIncrementFloat.append(C5XAccelerometerSpeedIncrementFloat);
//    C5VYAccelerometerSpeedIncrementFloat.append(C5YAccelerometerSpeedIncrementFloat);
//    C5VZAccelerometerSpeedIncrementFloat.append(C5ZAccelerometerSpeedIncrementFloat);

//    C5VXgyroCompensatedAngleIncrementFloat.append(C5XgyroCompensatedAngleIncrementFloat);
//    C5VYgyroCompensatedAngleIncrementFloat.append(C5YgyroCompensatedAngleIncrementFloat);
//    C5VZgyroCompensatedAngleIncrementFloat.append(C5ZgyroCompensatedAngleIncrementFloat);

//    C5VXAccVelocityIncrementFloat.append(C5XAccVelocityIncrementFloat);
//    C5VYAccVelocityIncrementFloat.append(C5YAccVelocityIncrementFloat);
//    C5VZAccVelocityIncrementFloat.append(C5ZAccVelocityIncrementFloat);

//    C5VXgyroDifFrequency.append(C5XgyroDifFrequency);
//    C5VYgyroDifFrequency.append(C5YgyroDifFrequency);
//    C5VZgyroDifFrequency.append(C5ZgyroDifFrequency);

//    C5VXaccelerometerDifFre.append(C5XaccelerometerDifFre);
//    C5VYaccelerometerDifFre.append(C5YaccelerometerDifFre);
//    C5VZaccelerometerDifFre.append(C5ZaccelerometerDifFre);


//    C5VXgyroTemp1.append(C5XgyroTemp1);
//    C5VYgyroTemp1.append(C5YgyroTemp1);
//    C5VZgyroTemp1.append(C5ZgyroTemp1);

//    C5VXAccelerometerTemperture.append(C5XAccelerometerTemperture);
//    C5VYAccelerometerTemperture.append(C5YAccelerometerTemperture);
//    C5VZAccelerometerTemperture.append(C5ZAccelerometerTemperture);

//    C5VXgyroTemp2.append(C5XgyroTemp2);
//    C5VYgyroTemp2.append(C5YgyroTemp2);
//    C5VZgyroTemp2.append(C5ZgyroTemp2);

//    C5VXgyroAmplitudeJitter.append(C5XgyroAmplitudeJitter);
//    C5VYgyroAmplitudeJitter.append(C5YgyroAmplitudeJitter);
//    C5VZgyroAmplitudeJitter.append(C5ZgyroAmplitudeJitter);

//    C5VXgyroAmpl1itudeFre.append(C5XgyroAmpl1itudeFre);
//    C5VYgyroAmpl1itudeFre.append(C5YgyroAmpl1itudeFre);
//    C5VZgyroAmpl1itudeFre.append(C5ZgyroAmpl1itudeFre);

//    C3Vlongitude.append(C3longitude);
//    C3VGPSlatitude.append(C3GPSlatitude);
//    C3VtogetherSpeed.append(C3togetherSpeed);
//    C3VheadingAngle.append(C3headingAngle);
//    C3VcombinedEastSpeed.append(C3combinedEastSpeed);
//    C3VcombinedNorthSpeed.append(C3combinedNorthSpeed);

//    C3VwaterX.append(C3waterX);
//    C3VwaterY.append(C3waterY);
//    C3VbottomX.append(C3bottomX);
//    C3VbottomY.append(C3bottomY);

//    C3VelectromagnetismSpeed.append(C3electromagnetismSpeed);

//    C6VC6UndampedRollAngleFloat.append(C6UndampedRollAngleFloat);
//    C6VC6UndampedPitchAngleFloat.append(C6UndampedPitchAngleFloat);
//    C6VC6UndampedHeadingAngularFloat.append(C6UndampedHeadingAngularFloat);
//    C6VC6UndampedNorthSpeedFloat.append(C6UndampedNorthSpeedFloat);
//    C6VC6UndampedEastSpeedFloat.append(C6UndampedEastSpeedFloat);
//    C6VC6VerticalVelocityFloat.append(C6VerticalVelocityFloat);
//    C6VC6UndampedLatFloat.append(C6UndampedLatFloat);
//    C6VC6UndampedLongFloat.append(C6UndampedLongFloat);
//    C6VC6UndampedHeightFloat.append(C6UndampedHeightFloat);


//    C6VC6XGroyFloat.append(C6XGroyFloat);
//    C6VC6YGroyFloat.append(C6YGroyFloat);
//    C6VC6ZGroyFloat.append(C6ZGroyFloat);
//    C6VC6XAccelerometerFloat.append(C6XAccelerometerFloat);
//    C6VC6YAccelerometerFloat.append(C6YAccelerometerFloat);
//    C6VC6ZAccelerometerFloat.append(C6ZAccelerometerFloat);




//    VeastSpeedError.append(eastSpeedError);
//    VnorthSpeedError.append(northSpeedError);
//    VtogetherSpeedError.append(togetherSpeedError);
//    VlatitudeError.append(latitudeError);
//    VlongitudeError.append(longitudeError);
//    VpositionError.append(positionError);

//    m_xLength++;
//}

MainWindow::~MainWindow()
{
    delete qtime;
    qtime = NULL;

    delete qDrawTime;
    qDrawTime = NULL;
    C1fileSave.close();
    C2fileSave.close();
    C3fileSave.close();
    C5fileSave.close();
    C6fileSave.close();
    C8fileSave.close();
    delete ui;
}

void MainWindow::startTimer()
{

    if(!qtime->isActive())
    {
        qtime->start(handleResultDelay);
    }
}

void MainWindow::drawCurveLatitude()
{

    QCustomPlot* customPlot = ui->customPlot2;

    /*************************************绘制C1纬度曲线****************************************/
    if(ui->checkBox->isChecked())
    {

        if(C1latitudeCurveRun == 0)
        {
            QPen pen;
            C1latitudeGraphNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C1latitudeGraphNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1latitudeGraphNum)->setData(C1curveX,C1Vlatitude);
           // customPlot->graph(C1latitudeGraphNum)->rescaleAxes(true);                   //使曲线平铺整个画面

            customPlot->replot(QCustomPlot::rpQueuedReplot);

            C1latitudeCurveRun = 1;
            set_checkBox_1_2_73_74_75();

        }
        else
        {
            customPlot->graph(C1latitudeGraphNum)->setData(C1curveX,C1Vlatitude);

            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1latitudeCurveRun == 1)
        {
            C1latitudeCurveRun = 0;
            C1longitudeRun = 0;
            C8HeightRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedLongFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
             ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /*************************************绘制C1经度曲线****************************************/
    if(ui->checkBox_2->isChecked())
    {

        if(C1longitudeRun == 0)
        {

            QPen pen;
            C1longitudeNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C1longitudeNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1longitudeNum)->setData(C1curveX,C1Vlongitude);
            customPlot->graph(C1longitudeNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1longitudeRun = 1;
            set_checkBox_1_2_73_74_75();
        }
        else
        {
            customPlot->graph(C1longitudeNum)->setData(C1curveX,C1Vlongitude);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1longitudeRun == 1)
        {
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C8HeightRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedLongFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /*************************************绘制C8高度曲线****************************************/
    if(ui->checkBox_82->isChecked())
    {

        if(C8HeightRun == 0)
        {

            QPen pen;
            C8HeightNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,0,255));
            customPlot->graph(C8HeightNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C8HeightNum)->setData(C8curveX,C8VC8Height);
            customPlot->graph(C8HeightNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C8HeightRun = 1;
            set_checkBox_1_2_73_74_75();
        }
        else
        {
            customPlot->graph(C8HeightNum)->setData(C8curveX,C8VC8Height);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C8HeightRun == 1)
        {
            C8HeightRun = 0;
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedLongFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /*************************************绘制C6无阻尼纬度曲线****************************************/
    if(ui->checkBox_73->isChecked())
    {

        if(C6UndampedLatFloatRun == 0)
        {

            QPen pen;
            C6UndampedLatFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C6UndampedLatFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedLatFloatNum)->setData(C6curveX,C6VC6UndampedLatFloat);
            customPlot->graph(C6UndampedLatFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedLatFloatRun = 1;
            set_checkBox_1_2_73_74_75();
        }
        else
        {
            customPlot->graph(C6UndampedLatFloatNum)->setData(C6curveX,C6VC6UndampedLatFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedLatFloatRun == 1)
        {
            C6UndampedLatFloatRun = 0;
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C8HeightRun = 0;
            C6UndampedLongFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /*************************************绘制C6无阻尼经度曲线****************************************/
    if(ui->checkBox_74->isChecked())
    {

        if(C6UndampedLongFloatRun == 0)
        {

            QPen pen;
            C6UndampedLongFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C6UndampedLongFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedLongFloatNum)->setData(C6curveX,C6VC6UndampedLongFloat);
            customPlot->graph(C6UndampedLongFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedLongFloatRun = 1;
            set_checkBox_1_2_73_74_75();
        }
        else
        {
            customPlot->graph(C6UndampedLongFloatNum)->setData(C6curveX,C6VC6UndampedLongFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedLongFloatRun == 1)
        {
            C6UndampedLongFloatRun = 0;
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C8HeightRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /*************************************绘制C6无阻尼高度曲线****************************************/
    if(ui->checkBox_75->isChecked())
    {

        if(C6UndampedHeightFloatRun == 0)
        {

            QPen pen;
            C6UndampedHeightFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C6UndampedHeightFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedHeightFloatNum)->setData(C6curveX,C6VC6UndampedHeightFloat);
            customPlot->graph(C6UndampedHeightFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedHeightFloatRun = 1;
            set_checkBox_1_2_73_74_75();
        }
        else
        {
            customPlot->graph(C6UndampedHeightFloatNum)->setData(C6curveX,C6VC6UndampedHeightFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedHeightFloatRun == 1)
        {
            C6UndampedHeightFloatRun = 0;
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C8HeightRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedLongFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }


     if(ui->checkBox_5->isChecked())
     {
         if(C1headingAngleRun == 0)
         {
             QPen pen;
             C1headingAngleNum = customPlot->graphCount();
             customPlot->addGraph();
             pen.setColor(QColor(0,143,122));
             customPlot->graph(C1headingAngleNum)->setPen(pen);
             customPlot->yAxis->setNumberPrecision(7);
             customPlot->graph(C1headingAngleNum)->setData(C1curveX,C1VheadingAngle);
             customPlot->graph(C1headingAngleNum)->rescaleAxes();                   //使曲线平铺整个画面
             //重绘
             customPlot->replot(QCustomPlot::rpQueuedReplot);
             C1headingAngleRun = 1;
             set_checkBox_5_3_4_79_80_81();
         }
         else
         {
             customPlot->graph(C1headingAngleNum)->setData(C1curveX,C1VheadingAngle);
             //重绘
             customPlot->replot(QCustomPlot::rpQueuedReplot);

         }
     }
     else
     {
         if(C1headingAngleRun == 1)
         {
             C1headingAngleRun = 0;
             C1rollAngleRun = 0;
             C1pitchAngleRun = 0;
             C6UndampedRollAngleFloatRun = 0;
             C6UndampedPitchAngleFloatRun = 0;
             C6UndampedHeadingAngularFloatRun = 0;
             ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);


         }
     }
        /**********************************横摇角曲线****************************************/
        if(ui->checkBox_3->isChecked())
        {
            if(C1rollAngleRun == 0)
            {
                QPen pen;
                C1rollAngleNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C1rollAngleNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C1rollAngleNum)->setData(C1curveX,C1VrollAngle);
                customPlot->graph(C1rollAngleNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C1rollAngleRun = 1;
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
                customPlot->graph(C1rollAngleNum)->setData(C1curveX,C1VrollAngle);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C1rollAngleRun == 1)
            {
                C1rollAngleRun = 0;
                C1headingAngleRun = 0;
                C1pitchAngleRun = 0;
                C6UndampedRollAngleFloatRun = 0;
                C6UndampedPitchAngleFloatRun = 0;
                C6UndampedHeadingAngularFloatRun = 0;
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************纵摇角曲线****************************************/
        if(ui->checkBox_4->isChecked())
        {
            if(C1pitchAngleRun == 0)
            {
                QPen pen;
                C1pitchAngleNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                 customPlot->graph(C1pitchAngleNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C1pitchAngleNum)->setData(C1curveX,C1VpitchAngle);
                customPlot->graph(C1pitchAngleNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C1pitchAngleRun = 1;
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
                customPlot->graph(C1pitchAngleNum)->setData(C1curveX,C1VpitchAngle);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C1pitchAngleRun == 1)
            {
                C1pitchAngleRun = 0;
                C1headingAngleRun = 0;
                C1rollAngleRun = 0;
                C6UndampedRollAngleFloatRun = 0;
                C6UndampedPitchAngleFloatRun = 0;
                C6UndampedHeadingAngularFloatRun = 0;
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6无阻尼横摇角曲线****************************************/
        if(ui->checkBox_79->isChecked())
        {
            if(C6UndampedRollAngleFloatRun == 0)
            {
                QPen pen;
                C6UndampedRollAngleFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,128));
                customPlot->graph(C6UndampedRollAngleFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6UndampedRollAngleFloatNum)->setData(C6curveX,C6VC6UndampedRollAngleFloat);
                customPlot->graph(C6UndampedRollAngleFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6UndampedRollAngleFloatRun = 1;
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
                customPlot->graph(C6UndampedRollAngleFloatNum)->setData(C6curveX,C6VC6UndampedRollAngleFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C6UndampedRollAngleFloatRun == 1)
            {
                C6UndampedRollAngleFloatRun = 0;
                C1headingAngleRun = 0;
                C1rollAngleRun = 0;
                C1pitchAngleRun = 0;
                C6UndampedPitchAngleFloatRun = 0;
                C6UndampedHeadingAngularFloatRun = 0;
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************无阻尼纵摇角曲线****************************************/
        if(ui->checkBox_80->isChecked())
        {
            if(C6UndampedPitchAngleFloatRun == 0)
            {
                QPen pen;
                C6UndampedPitchAngleFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(147,108,0));
                customPlot->graph(C6UndampedPitchAngleFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6UndampedPitchAngleFloatNum)->setData(C6curveX,C6VC6UndampedPitchAngleFloat);
                customPlot->graph(C6UndampedPitchAngleFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6UndampedPitchAngleFloatRun = 1;
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
                customPlot->graph(C6UndampedPitchAngleFloatNum)->setData(C6curveX,C6VC6UndampedPitchAngleFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C6UndampedPitchAngleFloatRun == 1)
            {
                C6UndampedPitchAngleFloatRun = 0;
                C1headingAngleRun = 0;
                C1rollAngleRun = 0;
                C1pitchAngleRun = 0;
                C6UndampedRollAngleFloatRun = 0;
                C6UndampedHeadingAngularFloatRun = 0;
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************无阻尼航向角曲线****************************************/
        if(ui->checkBox_81->isChecked())
        {
            if(C6UndampedHeadingAngularFloatRun == 0)
            {
                QPen pen;
                C6UndampedHeadingAngularFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,0,255));
                customPlot->graph(C6UndampedHeadingAngularFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6UndampedHeadingAngularFloatNum)->setData(C6curveX,C6VC6UndampedHeadingAngularFloat);
                customPlot->graph(C6UndampedHeadingAngularFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6UndampedHeadingAngularFloatRun = 1;
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
                customPlot->graph(C6UndampedHeadingAngularFloatNum)->setData(C6curveX,C6VC6UndampedHeadingAngularFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C6UndampedHeadingAngularFloatRun == 1)
            {
                C6UndampedHeadingAngularFloatRun = 0;
                C1headingAngleRun = 0;
                C1rollAngleRun = 0;
                C1pitchAngleRun = 0;
                C6UndampedRollAngleFloatRun = 0;
                C6UndampedPitchAngleFloatRun = 0;
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }


    /**********************************绘北速曲线****************************************/
    if(ui->checkBox_9->isChecked())
    {
        if(C1northSpeedRun == 0)
        {
            QPen pen;
            C1northSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C1northSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1northSpeedNum)->setData(C1curveX,C1VnorthSpeed);
            customPlot->graph(C1northSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1northSpeedRun = 1;
            set_checkBox_9_10_76_77_78();
        }
        else
        {
            customPlot->graph(C1northSpeedNum)->setData(C1curveX,C1VnorthSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1northSpeedRun == 1)
        {
            C1northSpeedRun = 0;
            C1eastSpeedRun = 0;
            C8UpSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘东速曲线****************************************/
    if(ui->checkBox_10->isChecked())
    {
        if(C1eastSpeedRun == 0)
        {
            QPen pen;
            C1eastSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C1eastSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1eastSpeedNum)->setData(C1curveX,C1VeastSpeed);
            customPlot->graph(C1eastSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1eastSpeedRun = 1;
            set_checkBox_9_10_76_77_78();
        }
        else
        {
            customPlot->graph(C1eastSpeedNum)->setData(C1curveX,C1VeastSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1eastSpeedRun == 1)
        {
            C1eastSpeedRun = 0;
            C1northSpeedRun = 0;
            C8UpSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    if(ui->checkBox_83->isChecked())
    {
        if(C8UpSpeedRun == 0)
        {
            QPen pen;
            C8UpSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,0,255));
            customPlot->graph(C8UpSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C8UpSpeedNum)->setData(C8curveX,C8VC8UpSpeed);
            customPlot->graph(C8UpSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C8UpSpeedRun = 1;
            set_checkBox_9_10_76_77_78();
        }
        else
        {
            customPlot->graph(C8UpSpeedNum)->setData(C8curveX,C8VC8UpSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C8UpSpeedRun == 1)
        {
            C8UpSpeedRun = 0;
            C1eastSpeedRun = 0;
            C1northSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************绘C6的无阻尼北速曲线****************************************/
    if(ui->checkBox_76->isChecked())
    {
        if(C6UndampedNorthSpeedFloatRun == 0)
        {
            QPen pen;
            C6UndampedNorthSpeedFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C6UndampedNorthSpeedFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedNorthSpeedFloatNum)->setData(C6curveX,C6VC6UndampedNorthSpeedFloat);
            customPlot->graph(C6UndampedNorthSpeedFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedNorthSpeedFloatRun = 1;
            set_checkBox_9_10_76_77_78();
        }
        else
        {
            customPlot->graph(C6UndampedNorthSpeedFloatNum)->setData(C6curveX,C6VC6UndampedNorthSpeedFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedNorthSpeedFloatRun == 1)
        {
            C6UndampedNorthSpeedFloatRun = 0;
            C1northSpeedRun = 0;
            C1eastSpeedRun = 0;
            C8UpSpeedRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘C6的无阻尼东速曲线****************************************/
    if(ui->checkBox_77->isChecked())
    {
        if(C6UndampedEastSpeedFloatRun == 0)
        {
            QPen pen;
            C6UndampedEastSpeedFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C6UndampedEastSpeedFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedEastSpeedFloatNum)->setData(C6curveX,C6VC6UndampedEastSpeedFloat);
            customPlot->graph(C6UndampedEastSpeedFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedEastSpeedFloatRun = 1;
            set_checkBox_9_10_76_77_78();
        }
        else
        {
            customPlot->graph(C6UndampedEastSpeedFloatNum)->setData(C6curveX,C6VC6UndampedEastSpeedFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedEastSpeedFloatRun == 1)
        {
            C6UndampedEastSpeedFloatRun = 0;
            C1northSpeedRun = 0;
            C1eastSpeedRun = 0;
            C8UpSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘C6的无阻尼垂速曲线****************************************/
    if(ui->checkBox_78->isChecked())
    {
        if(C6VerticalVelocityFloatRun == 0)
        {
            QPen pen;
            C6VerticalVelocityFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C6VerticalVelocityFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6VerticalVelocityFloatNum)->setData(C6curveX,C6VC6VerticalVelocityFloat);
            customPlot->graph(C6VerticalVelocityFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6VerticalVelocityFloatRun = 1;
            set_checkBox_9_10_76_77_78();
        }
        else
        {
            customPlot->graph(C6VerticalVelocityFloatNum)->setData(C6curveX,C6VC6VerticalVelocityFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6VerticalVelocityFloatRun == 1)
        {
            C6VerticalVelocityFloatRun = 0;
            C1northSpeedRun = 0;
            C1eastSpeedRun = 0;
            C8UpSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘航向角速度曲线****************************************/
    if(ui->checkBox_6->isChecked())
    {
        if(C1headingAngularSpeedRun == 0)
        {
            QPen pen;
            C1headingAngularSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C1headingAngularSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1headingAngularSpeedNum)->setData(C1curveX,C1VheadingAngularSpeed);
            customPlot->graph(C1headingAngularSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1headingAngularSpeedRun = 1;
            set_checkBox_6_7_8();
        }
        else
        {
            customPlot->graph(C1headingAngularSpeedNum)->setData(C1curveX,C1VheadingAngularSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1headingAngularSpeedRun == 1)
        {
            C1headingAngularSpeedRun = 0;
            C1pitchAngleSpeedRun = 0;
            C1rollAngleSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************绘横摇角速度曲线****************************************/
    if(ui->checkBox_7->isChecked())
    {
        if(C1rollAngleSpeedRun == 0)
        {
            QPen pen;
            C1rollAngleSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C1rollAngleSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1rollAngleSpeedNum)->setData(C1curveX,C1VrollAngleSpeed);
            customPlot->graph(C1rollAngleSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1rollAngleSpeedRun = 1;
            set_checkBox_6_7_8();
        }
        else
        {
            customPlot->graph(C1rollAngleSpeedNum)->setData(C1curveX,C1VrollAngleSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1rollAngleSpeedRun == 1)
        {
            C1rollAngleSpeedRun = 0;
             C1headingAngularSpeedRun = 0;
             C1pitchAngleSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘纵摇角速度曲线****************************************/
    if(ui->checkBox_8->isChecked())
    {
        if(C1pitchAngleSpeedRun == 0)
        {
            QPen pen;
            C1pitchAngleSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C1pitchAngleSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1pitchAngleSpeedNum)->setData(C1curveX,C1VpitchAngleSpeed);
            customPlot->graph(C1pitchAngleSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1pitchAngleSpeedRun = 1;
            set_checkBox_6_7_8();
        }
        else
        {
            customPlot->graph(C1pitchAngleSpeedNum)->setData(C1curveX,C1VpitchAngleSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1pitchAngleSpeedRun == 1)
        {
            C1pitchAngleSpeedRun = 0;
            C1rollAngleSpeedRun = 0;
            C1headingAngularSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************垂荡曲线****************************************/
    if(ui->checkBox_12->isChecked())
    {
        if(C1heaveRun == 0)
        {
            QPen pen;
            C1heaveNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C1heaveNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1heaveNum)->setData(C1curveX,C1Vheave);
            customPlot->graph(C1heaveNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1heaveRun = 1;
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
            customPlot->graph(C1heaveNum)->setData(C1curveX,C1Vheave);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1heaveRun == 1)
        {
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1swayRun = 0;
            C1transverseVelocityRun = 0;
            C1surgeRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************垂速曲线****************************************/
    if(ui->checkBox_13->isChecked())
    {
        if(C1verticalVelocityRun == 0)
        {
            QPen pen;
            C1verticalVelocityNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C1verticalVelocityNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1verticalVelocityNum)->setData(C1curveX,C1VverticalVelocity);
            customPlot->graph(C1verticalVelocityNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1verticalVelocityRun = 1;
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
            customPlot->graph(C1verticalVelocityNum)->setData(C1curveX,C1VverticalVelocity);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1verticalVelocityRun == 1)
        {
            C1verticalVelocityRun = 0;
            C1heaveRun = 0;
            C1swayRun = 0;
            C1transverseVelocityRun = 0;
            C1surgeRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************横荡曲线****************************************/
    if(ui->checkBox_11->isChecked())
    {
        if(C1swayRun == 0)
        {
            QPen pen;
            C1swayNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
             customPlot->graph(C1swayNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1swayNum)->setData(C1curveX,C1Vsway);
            customPlot->graph(C1swayNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1swayRun = 1;
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
            customPlot->graph(C1swayNum)->setData(C1curveX,C1Vsway);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1swayRun == 1)
        {
            C1swayRun = 0;
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1transverseVelocityRun = 0;
            C1surgeRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************横速曲线****************************************/
    if(ui->checkBox_15->isChecked())
    {
        if(C1transverseVelocityRun == 0)
        {
            QPen pen;
            C1transverseVelocityNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C1transverseVelocityNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1transverseVelocityNum)->setData(C1curveX,C1VtransverseVelocity);
            customPlot->graph(C1transverseVelocityNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1transverseVelocityRun = 1;
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
            customPlot->graph(C1transverseVelocityNum)->setData(C1curveX,C1VtransverseVelocity);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1transverseVelocityRun == 1)
        {
            C1transverseVelocityRun = 0;
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1swayRun = 0;
            C1surgeRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************纵荡曲线****************************************/
    if(ui->checkBox_16->isChecked())
    {
        if(C1surgeRun == 0)
        {
            QPen pen;
            C1surgeNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C1surgeNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1surgeNum)->setData(C1curveX,C1Vsurge);
            customPlot->graph(C1surgeNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1surgeRun = 1;
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
            customPlot->graph(C1surgeNum)->setData(C1curveX,C1Vsurge);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1surgeRun == 1)
        {
            C1surgeRun = 0;
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1swayRun = 0;
            C1transverseVelocityRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************纵速曲线****************************************/
    if(ui->checkBox_14->isChecked())
    {
        if(C1longitudinalVelocityRun == 0)
        {
            QPen pen;
            C1longitudinalVelocityNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,0,255));
            customPlot->graph(C1longitudinalVelocityNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1longitudinalVelocityNum)->setData(C1curveX,C1VlongitudinalVelocity);
            customPlot->graph(C1longitudinalVelocityNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1longitudinalVelocityRun = 1;
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
            customPlot->graph(C1longitudinalVelocityNum)->setData(C1curveX,C1VlongitudinalVelocity);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1longitudinalVelocityRun == 1)
        {
            C1longitudinalVelocityRun = 0;
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1swayRun = 0;
            C1transverseVelocityRun = 0;
            C1surgeRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
#ifdef INSIDE
    if(1)//增量曲线和原始脉冲曲线不显示2022-1-20
    {
        /**********************************X陀螺增量曲线****************************************/
        if(ui->checkBox_19->isChecked())
        {
            if(C5XGyroAngleIncreaseFloatRun == 0)
            {
                QPen pen;
                C5XGyroAngleIncreaseFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C5XGyroAngleIncreaseFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5XGyroAngleIncreaseFloatNum)->setData(C5curveX,C5VXGyroAngleIncreaseFloat);
                 customPlot->graph(C5XGyroAngleIncreaseFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5XGyroAngleIncreaseFloatRun = 1;
                set_checkBox_19_18_17();
            }
            else
            {
                customPlot->graph(C5XGyroAngleIncreaseFloatNum)->setData(C5curveX,C5VXGyroAngleIncreaseFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5XGyroAngleIncreaseFloatRun == 1)
            {
                C5XGyroAngleIncreaseFloatRun = 0;
                C5YGyroAngleIncreaseFloatRun = 0;
                C5ZGyroAngleIncreaseFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************Y陀螺增量曲线****************************************/
        if(ui->checkBox_18->isChecked())
        {
            if(C5YGyroAngleIncreaseFloatRun == 0)
            {
                QPen pen;
                C5YGyroAngleIncreaseFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C5YGyroAngleIncreaseFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5YGyroAngleIncreaseFloatNum)->setData(C5curveX,C5VYGyroAngleIncreaseFloat);
                customPlot->graph(C5YGyroAngleIncreaseFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5YGyroAngleIncreaseFloatRun = 1;
                set_checkBox_19_18_17();
            }
            else
            {
                customPlot->graph(C5YGyroAngleIncreaseFloatNum)->setData(C5curveX,C5VYGyroAngleIncreaseFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5YGyroAngleIncreaseFloatRun == 1)
            {
                C5YGyroAngleIncreaseFloatRun = 0;
                C5ZGyroAngleIncreaseFloatRun = 0;
                C5XGyroAngleIncreaseFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************Z陀螺增量曲线****************************************/
        if(ui->checkBox_17->isChecked())
        {
            if(C5ZGyroAngleIncreaseFloatRun == 0)
            {
                QPen pen;
                C5ZGyroAngleIncreaseFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->setData(C5curveX,C5VZGyroAngleIncreaseFloat);
                customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5ZGyroAngleIncreaseFloatRun = 1;
                set_checkBox_19_18_17();
            }
            else
            {
                customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->setData(C5curveX,C5VZGyroAngleIncreaseFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5ZGyroAngleIncreaseFloatRun == 1)
            {
                C5ZGyroAngleIncreaseFloatRun = 0;
                C5YGyroAngleIncreaseFloatRun = 0;
                C5XGyroAngleIncreaseFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************X加表增量曲线****************************************/
        if(ui->checkBox_20->isChecked())
        {
            if(C5XAccelerometerSpeedIncrementFloatRun == 0)
            {
                QPen pen;
                C5XAccelerometerSpeedIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->setData(C5curveX,C5VXAccelerometerSpeedIncrementFloat);
                customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5XAccelerometerSpeedIncrementFloatRun = 1;
                set_checkBox_20_21_22();
            }
            else
            {
                customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->setData(C5curveX,C5VXAccelerometerSpeedIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5XAccelerometerSpeedIncrementFloatRun == 1)
            {
                C5XAccelerometerSpeedIncrementFloatRun = 0;
                C5YAccelerometerSpeedIncrementFloatRun = 0;
                C5ZAccelerometerSpeedIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************Y加表增量曲线****************************************/
        if(ui->checkBox_21->isChecked())
        {
            if(C5YAccelerometerSpeedIncrementFloatRun == 0)
            {
                QPen pen;
                C5YAccelerometerSpeedIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->setData(C5curveX,C5VYAccelerometerSpeedIncrementFloat);
                customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5YAccelerometerSpeedIncrementFloatRun = 1;
                set_checkBox_20_21_22();
            }
            else
            {
                customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->setData(C5curveX,C5VYAccelerometerSpeedIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5YAccelerometerSpeedIncrementFloatRun == 1)
            {
                C5YAccelerometerSpeedIncrementFloatRun = 0;
                C5ZAccelerometerSpeedIncrementFloatRun = 0;
                C5XAccelerometerSpeedIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Z加表增量曲线****************************************/
        if(ui->checkBox_22->isChecked())
        {
            if(C5ZAccelerometerSpeedIncrementFloatRun == 0)
            {
                QPen pen;
                C5ZAccelerometerSpeedIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->setData(C5curveX,C5VZAccelerometerSpeedIncrementFloat);
                customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5ZAccelerometerSpeedIncrementFloatRun = 1;
                set_checkBox_20_21_22();
            }
            else
            {
                customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->setData(C5curveX,C5VZAccelerometerSpeedIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5ZAccelerometerSpeedIncrementFloatRun == 1)
            {
                C5ZAccelerometerSpeedIncrementFloatRun = 0;
                C5YAccelerometerSpeedIncrementFloatRun = 0;
                C5XAccelerometerSpeedIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************x陀螺1s补偿后角增量曲线****************************************/
        if(ui->checkBox_23->isChecked())
        {
            if(C5XgyroCompensatedAngleIncrementFloatRun == 0)
            {
                QPen pen;
                C5XgyroCompensatedAngleIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->setData(C5curveX,C5VXgyroCompensatedAngleIncrementFloat);
                customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5XgyroCompensatedAngleIncrementFloatRun = 1;
                set_checkBox_23_24_25();
            }
            else
            {
                customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->setData(C5curveX,C5VXgyroCompensatedAngleIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5XgyroCompensatedAngleIncrementFloatRun == 1)
            {
                C5XgyroCompensatedAngleIncrementFloatRun = 0;
                C5YgyroCompensatedAngleIncrementFloatRun = 0;
                C5ZgyroCompensatedAngleIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Y陀螺1s补偿后角增量曲线****************************************/
        if(ui->checkBox_24->isChecked())
        {
            if(C5YgyroCompensatedAngleIncrementFloatRun == 0)
            {
                QPen pen;
                C5YgyroCompensatedAngleIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->setData(C5curveX,C5VYgyroCompensatedAngleIncrementFloat);
                customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5YgyroCompensatedAngleIncrementFloatRun = 1;
                set_checkBox_23_24_25();
            }
            else
            {
                customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->setData(C5curveX,C5VYgyroCompensatedAngleIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5YgyroCompensatedAngleIncrementFloatRun == 1)
            {
                C5YgyroCompensatedAngleIncrementFloatRun = 0;
                C5XgyroCompensatedAngleIncrementFloatRun = 0;
                C5ZgyroCompensatedAngleIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Z陀螺1s补偿后角增量曲线****************************************/
        if(ui->checkBox_25->isChecked())
        {
            if(C5ZgyroCompensatedAngleIncrementFloatRun == 0)
            {
                QPen pen;
                C5ZgyroCompensatedAngleIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->setData(C5curveX,C5VZgyroCompensatedAngleIncrementFloat);
                customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5ZgyroCompensatedAngleIncrementFloatRun = 1;
                set_checkBox_23_24_25();
            }
            else
            {
                customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->setData(C5curveX,C5VZgyroCompensatedAngleIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5ZgyroCompensatedAngleIncrementFloatRun == 1)
            {
                C5ZgyroCompensatedAngleIncrementFloatRun = 0;
                C5XgyroCompensatedAngleIncrementFloatRun = 0;
                C5YgyroCompensatedAngleIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************x加表1s补偿后角增量曲线****************************************/
        if(ui->checkBox_26->isChecked())
        {
            if(C5XAccVelocityIncrementFloatRun == 0)
            {
                QPen pen;
                C5XAccVelocityIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C5XAccVelocityIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5XAccVelocityIncrementFloatNum)->setData(C5curveX,C5VXAccVelocityIncrementFloat);
                customPlot->graph(C5XAccVelocityIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5XAccVelocityIncrementFloatRun = 1;
                set_checkBox_26_27_28();
            }
            else
            {
                customPlot->graph(C5XAccVelocityIncrementFloatNum)->setData(C5curveX,C5VXAccVelocityIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5XAccVelocityIncrementFloatRun == 1)
            {
                C5XAccVelocityIncrementFloatRun = 0;
                C5YAccVelocityIncrementFloatRun = 0;
                C5ZAccVelocityIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Y加表1s补偿后角增量曲线****************************************/
        if(ui->checkBox_27->isChecked())
        {
            if(C5YAccVelocityIncrementFloatRun == 0)
            {
                QPen pen;
                C5YAccVelocityIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C5YAccVelocityIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5YAccVelocityIncrementFloatNum)->setData(C5curveX,C5VYAccVelocityIncrementFloat);
                customPlot->graph(C5YAccVelocityIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5YAccVelocityIncrementFloatRun = 1;
                set_checkBox_26_27_28();
            }
            else
            {
                customPlot->graph(C5YAccVelocityIncrementFloatNum)->setData(C5curveX,C5VYAccVelocityIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5YAccVelocityIncrementFloatRun == 1)
            {
                C5YAccVelocityIncrementFloatRun = 0;
                C5XAccVelocityIncrementFloatRun = 0;
                C5ZAccVelocityIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Z加表1s补偿后角增量曲线****************************************/
        if(ui->checkBox_28->isChecked())
        {
            if(C5ZAccVelocityIncrementFloatRun == 0)
            {
                QPen pen;
                C5ZAccVelocityIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C5ZAccVelocityIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5ZAccVelocityIncrementFloatNum)->setData(C5curveX,C5VZAccVelocityIncrementFloat);
                customPlot->graph(C5ZAccVelocityIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5ZAccVelocityIncrementFloatRun = 1;
                set_checkBox_26_27_28();
            }
            else
            {
                customPlot->graph(C5ZAccVelocityIncrementFloatNum)->setData(C5curveX,C5VZAccVelocityIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5ZAccVelocityIncrementFloatRun == 1)
            {
                C5ZAccVelocityIncrementFloatRun = 0;
                C5XAccVelocityIncrementFloatRun = 0;
                C5YAccVelocityIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
    }
#endif
    /**********************************C5的X陀螺差频曲线****************************************/
    if(ui->checkBox_29->isChecked())
    {
        if(C5XgyroDifFrequencyRun == 0)
        {
            QPen pen;
            C5XgyroDifFrequencyNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroDifFrequencyNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroDifFrequencyNum)->setData(C5curveX,C5VXgyroDifFrequency);
            customPlot->graph(C5XgyroDifFrequencyNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroDifFrequencyRun = 1;
            set_checkBox_29_30_31();
        }
        else
        {
            customPlot->graph(C5XgyroDifFrequencyNum)->setData(C5curveX,C5VXgyroDifFrequency);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroDifFrequencyRun == 1)
        {
            C5XgyroDifFrequencyRun = 0;
            C5YgyroDifFrequencyRun = 0;
            C5ZgyroDifFrequencyRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺差频曲线****************************************/
    if(ui->checkBox_31->isChecked())
    {
        if(C5YgyroDifFrequencyRun == 0)
        {
            QPen pen;
            C5YgyroDifFrequencyNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroDifFrequencyNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroDifFrequencyNum)->setData(C5curveX,C5VYgyroDifFrequency);
            customPlot->graph(C5YgyroDifFrequencyNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroDifFrequencyRun = 1;
            set_checkBox_29_30_31();
        }
        else
        {
            customPlot->graph(C5YgyroDifFrequencyNum)->setData(C5curveX,C5VYgyroDifFrequency);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroDifFrequencyRun == 1)
        {
            C5YgyroDifFrequencyRun = 0;
            C5XgyroDifFrequencyRun = 0;
            C5ZgyroDifFrequencyRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺差频曲线****************************************/
    if(ui->checkBox_30->isChecked())
    {
        if(C5ZgyroDifFrequencyRun == 0)
        {
            QPen pen;
            C5ZgyroDifFrequencyNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroDifFrequencyNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroDifFrequencyNum)->setData(C5curveX,C5VZgyroDifFrequency);
            customPlot->graph(C5ZgyroDifFrequencyNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroDifFrequencyRun = 1;
            set_checkBox_29_30_31();
        }
        else
        {
            customPlot->graph(C5ZgyroDifFrequencyNum)->setData(C5curveX,C5VZgyroDifFrequency);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroDifFrequencyRun == 1)
        {
            C5ZgyroDifFrequencyRun = 0;
            C5XgyroDifFrequencyRun = 0;
            C5YgyroDifFrequencyRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X加表差频曲线****************************************/
    if(ui->checkBox_32->isChecked())
    {
        if(C5XaccelerometerDifFreRun == 0)
        {
            QPen pen;
            C5XaccelerometerDifFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XaccelerometerDifFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XaccelerometerDifFreNum)->setData(C5curveX,C5VXaccelerometerDifFre);
            customPlot->graph(C5XaccelerometerDifFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XaccelerometerDifFreRun = 1;
            set_checkBox_32_33_34();
        }
        else
        {
            customPlot->graph(C5XaccelerometerDifFreNum)->setData(C5curveX,C5VXaccelerometerDifFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XaccelerometerDifFreRun == 1)
        {
            C5XaccelerometerDifFreRun = 0;
            C5YaccelerometerDifFreRun = 0;
            C5ZaccelerometerDifFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y加表差频曲线****************************************/
    if(ui->checkBox_33->isChecked())
    {
        if(C5YaccelerometerDifFreRun == 0)
        {
            QPen pen;
            C5YaccelerometerDifFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YaccelerometerDifFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YaccelerometerDifFreNum)->setData(C5curveX,C5VYaccelerometerDifFre);
            customPlot->graph(C5YaccelerometerDifFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YaccelerometerDifFreRun = 1;
            set_checkBox_32_33_34();
        }
        else
        {
            customPlot->graph(C5YaccelerometerDifFreNum)->setData(C5curveX,C5VYaccelerometerDifFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YaccelerometerDifFreRun == 1)
        {
            C5YaccelerometerDifFreRun = 0;
            C5XaccelerometerDifFreRun = 0;
            C5ZaccelerometerDifFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z加表差频曲线****************************************/
    if(ui->checkBox_34->isChecked())
    {
        if(C5ZaccelerometerDifFreRun == 0)
        {
            QPen pen;
            C5ZaccelerometerDifFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZaccelerometerDifFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZaccelerometerDifFreNum)->setData(C5curveX,C5VZaccelerometerDifFre);
            customPlot->graph(C5ZaccelerometerDifFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZaccelerometerDifFreRun = 1;
            set_checkBox_32_33_34();
        }
        else
        {
            customPlot->graph(C5ZaccelerometerDifFreNum)->setData(C5curveX,C5VZaccelerometerDifFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZaccelerometerDifFreRun == 1)
        {
            C5ZaccelerometerDifFreRun = 0;
            C5XaccelerometerDifFreRun = 0;
            C5YaccelerometerDifFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X陀螺温度1曲线****************************************/
    if(ui->checkBox_37->isChecked())
    {
        if(C5XgyroTemp1Run == 0)
        {
            QPen pen;
             C5XgyroTemp1Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroTemp1Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroTemp1Num)->setData(C5curveX,C5VXgyroTemp1);
            customPlot->graph(C5XgyroTemp1Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroTemp1Run = 1;
            //customPlot->graph(C5XgyroTemp1Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_37_35_36();
        }
        else
        {
           // customPlot->graph(C5XgyroTemp1Num)->setVisible(true);
            customPlot->graph(C5XgyroTemp1Num)->setData(C5curveX,C5VXgyroTemp1);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroTemp1Run == 1)
        {
            C5XgyroTemp1Run = 0;
            C5YgyroTemp1Run = 0;
            C5ZgyroTemp1Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺温度1曲线****************************************/
    if(ui->checkBox_35->isChecked())
    {
        if(C5YgyroTemp1Run == 0)
        {
            QPen pen;
            C5YgyroTemp1Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroTemp1Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroTemp1Num)->setData(C5curveX,C5VYgyroTemp1);
            customPlot->graph(C5YgyroTemp1Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroTemp1Run = 1;
            //customPlot->graph(C5YgyroTemp1Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_37_35_36();
        }
        else
        {
           // customPlot->graph(C5YgyroTemp1Num)->setVisible(true);
            customPlot->graph(C5YgyroTemp1Num)->setData(C5curveX,C5VYgyroTemp1);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroTemp1Run == 1)
        {
            C5YgyroTemp1Run = 0;
            C5XgyroTemp1Run = 0;
            C5ZgyroTemp1Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺温度1曲线****************************************/
    if(ui->checkBox_36->isChecked())
    {
        if(C5ZgyroTemp1Run == 0)
        {
            QPen pen;
            C5ZgyroTemp1Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroTemp1Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroTemp1Num)->setData(C5curveX,C5VZgyroTemp1);
            customPlot->graph(C5ZgyroTemp1Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroTemp1Run = 1;
            //customPlot->graph(C5ZgyroTemp1Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_37_35_36();
        }
        else
        {
           // customPlot->graph(C5ZgyroTemp1Num)->setVisible(true);
            customPlot->graph(C5ZgyroTemp1Num)->setData(C5curveX,C5VZgyroTemp1);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroTemp1Run == 1)
        {
            C5ZgyroTemp1Run = 0;
            C5XgyroTemp1Run = 0;
            C5YgyroTemp1Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X加表温度1曲线****************************************/
    if(ui->checkBox_40->isChecked())
    {
        if(C5XAccelerometerTempertureRun == 0)
        {
            QPen pen;
             C5XAccelerometerTempertureNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XAccelerometerTempertureNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XAccelerometerTempertureNum)->setData(C5curveX,C5VXAccelerometerTemperture);
            customPlot->graph(C5XAccelerometerTempertureNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XAccelerometerTempertureRun = 1;
            set_checkBox_40_38_39();
        }
        else
        {
           // customPlot->graph(C5XAccelerometerTempertureNum)->setVisible(true);
            customPlot->graph(C5XAccelerometerTempertureNum)->setData(C5curveX,C5VXAccelerometerTemperture);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XAccelerometerTempertureRun == 1)
        {
            C5XAccelerometerTempertureRun = 0;
            C5YAccelerometerTempertureRun = 0;
            C5ZAccelerometerTempertureRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y加表温度1曲线****************************************/
    if(ui->checkBox_38->isChecked())
    {
        if(C5YAccelerometerTempertureRun == 0)
        {
            QPen pen;
            C5YAccelerometerTempertureNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YAccelerometerTempertureNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YAccelerometerTempertureNum)->setData(C5curveX,C5VYAccelerometerTemperture);
            customPlot->graph(C5YAccelerometerTempertureNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YAccelerometerTempertureRun = 1;
            set_checkBox_40_38_39();
        }
        else
        {
            customPlot->graph(C5YAccelerometerTempertureNum)->setData(C5curveX,C5VYAccelerometerTemperture);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YAccelerometerTempertureRun == 1)
        {
            C5YAccelerometerTempertureRun = 0;
            C5XAccelerometerTempertureRun = 0;
            C5ZAccelerometerTempertureRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z加表温度1曲线****************************************/
    if(ui->checkBox_39->isChecked())
    {
        if(C5ZAccelerometerTempertureRun == 0)
        {
            QPen pen;
            C5ZAccelerometerTempertureNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZAccelerometerTempertureNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZAccelerometerTempertureNum)->setData(C5curveX,C5VZAccelerometerTemperture);
            customPlot->graph(C5ZAccelerometerTempertureNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZAccelerometerTempertureRun = 1;
            set_checkBox_40_38_39();
        }
        else
        {
            customPlot->graph(C5ZAccelerometerTempertureNum)->setData(C5curveX,C5VZAccelerometerTemperture);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZAccelerometerTempertureRun == 1)
        {
            C5ZAccelerometerTempertureRun = 0;
            C5XAccelerometerTempertureRun = 0;
            C5YAccelerometerTempertureRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X陀螺温度2曲线****************************************/
    if(ui->checkBox_42->isChecked())
    {
        if(C5XgyroTemp2Run == 0)
        {
            QPen pen;
             C5XgyroTemp2Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroTemp2Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroTemp2Num)->setData(C5curveX,C5VXgyroTemp2);
            customPlot->graph(C5XgyroTemp2Num)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroTemp2Run = 1;
            //customPlot->graph(C5XgyroTemp2Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_42_43_41();
        }
        else
        {
            customPlot->graph(C5XgyroTemp2Num)->setData(C5curveX,C5VXgyroTemp2);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroTemp2Run == 1)
        {
            C5XgyroTemp2Run = 0;
            C5YgyroTemp2Run = 0;
            C5ZgyroTemp2Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺温度2曲线****************************************/
    if(ui->checkBox_43->isChecked())
    {
        if(C5YgyroTemp2Run == 0)
        {
            QPen pen;
            C5YgyroTemp2Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroTemp2Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroTemp2Num)->setData(C5curveX,C5VYgyroTemp2);
            customPlot->graph(C5YgyroTemp2Num)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroTemp2Run = 1;
            set_checkBox_42_43_41();
        }
        else
        {
            customPlot->graph(C5YgyroTemp2Num)->setData(C5curveX,C5VYgyroTemp2);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroTemp2Run == 1)
        {
            C5YgyroTemp2Run = 0;
            C5XgyroTemp2Run = 0;
            C5ZgyroTemp2Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺温度2曲线****************************************/
    if(ui->checkBox_41->isChecked())
    {
        if(C5ZgyroTemp2Run == 0)
        {
            QPen pen;
            C5ZgyroTemp2Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroTemp2Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroTemp2Num)->setData(C5curveX,C5VZgyroTemp2);
            customPlot->graph(C5ZgyroTemp2Num)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroTemp2Run = 1;
            set_checkBox_42_43_41();
        }
        else
        {
            customPlot->graph(C5ZgyroTemp2Num)->setData(C5curveX,C5VZgyroTemp2);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroTemp2Run == 1)
        {
            C5ZgyroTemp2Run = 0;
            C5XgyroTemp2Run = 0;
            C5YgyroTemp2Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X陀螺抖幅曲线****************************************/
    if(ui->checkBox_45->isChecked())
    {
        if(C5XgyroAmplitudeJitterRun == 0)
        {
            QPen pen;
             C5XgyroAmplitudeJitterNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroAmplitudeJitterNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroAmplitudeJitterNum)->setData(C5curveX,C5VXgyroAmplitudeJitter);
            customPlot->graph(C5XgyroAmplitudeJitterNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroAmplitudeJitterRun = 1;
            set_checkBox_45_46_44();
        }
        else
        {
            customPlot->graph(C5XgyroAmplitudeJitterNum)->setData(C5curveX,C5VXgyroAmplitudeJitter);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroAmplitudeJitterRun == 1)
        {
            C5XgyroAmplitudeJitterRun = 0;
            C5YgyroAmplitudeJitterRun = 0;
            C5ZgyroAmplitudeJitterRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺抖幅曲线****************************************/
    if(ui->checkBox_46->isChecked())
    {
        if(C5YgyroAmplitudeJitterRun == 0)
        {
            QPen pen;
            C5YgyroAmplitudeJitterNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroAmplitudeJitterNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroAmplitudeJitterNum)->setData(C5curveX,C5VYgyroAmplitudeJitter);
            customPlot->graph(C5YgyroAmplitudeJitterNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroAmplitudeJitterRun = 1;
            set_checkBox_45_46_44();
        }
        else
        {
            customPlot->graph(C5YgyroAmplitudeJitterNum)->setData(C5curveX,C5VYgyroAmplitudeJitter);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroAmplitudeJitterRun == 1)
        {
            C5YgyroAmplitudeJitterRun = 0;
            C5XgyroAmplitudeJitterRun = 0;
            C5ZgyroAmplitudeJitterRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺抖幅曲线****************************************/
    if(ui->checkBox_44->isChecked())
    {
        if(C5ZgyroAmplitudeJitterRun == 0)
        {
            QPen pen;
            C5ZgyroAmplitudeJitterNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroAmplitudeJitterNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroAmplitudeJitterNum)->setData(C5curveX,C5VZgyroAmplitudeJitter);
            customPlot->graph(C5ZgyroAmplitudeJitterNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroAmplitudeJitterRun = 1;
            set_checkBox_45_46_44();
        }
        else
        {
            customPlot->graph(C5ZgyroAmplitudeJitterNum)->setData(C5curveX,C5VZgyroAmplitudeJitter);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroAmplitudeJitterRun == 1)
        {
            C5ZgyroAmplitudeJitterRun = 0;
            C5XgyroAmplitudeJitterRun = 0;
            C5YgyroAmplitudeJitterRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X陀螺抖频曲线****************************************/
    if(ui->checkBox_48->isChecked())
    {
        if(C5XgyroAmpl1itudeFreRun == 0)
        {
            QPen pen;
             C5XgyroAmpl1itudeFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroAmpl1itudeFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroAmpl1itudeFreNum)->setData(C5curveX,C5VXgyroAmpl1itudeFre);
            customPlot->graph(C5XgyroAmpl1itudeFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroAmpl1itudeFreRun = 1;
            set_checkBox_48_49_47();
        }
        else
        {
            customPlot->graph(C5XgyroAmpl1itudeFreNum)->setData(C5curveX,C5VXgyroAmpl1itudeFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroAmpl1itudeFreRun == 1)
        {
            C5XgyroAmpl1itudeFreRun = 0;
            C5YgyroAmpl1itudeFreRun = 0;
            C5ZgyroAmpl1itudeFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺抖频曲线****************************************/
    if(ui->checkBox_49->isChecked())
    {
        if(C5YgyroAmpl1itudeFreRun == 0)
        {
            QPen pen;
            C5YgyroAmpl1itudeFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroAmpl1itudeFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroAmpl1itudeFreNum)->setData(C5curveX,C5VYgyroAmpl1itudeFre);
            customPlot->graph(C5YgyroAmpl1itudeFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroAmpl1itudeFreRun = 1;
            set_checkBox_48_49_47();
        }
        else
        {
            customPlot->graph(C5YgyroAmpl1itudeFreNum)->setData(C5curveX,C5VYgyroAmpl1itudeFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroAmpl1itudeFreRun == 1)
        {
            C5YgyroAmpl1itudeFreRun = 0;
            C5XgyroAmpl1itudeFreRun = 0;
            C5ZgyroAmpl1itudeFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺抖频曲线****************************************/
    if(ui->checkBox_47->isChecked())
    {
        if(C5ZgyroAmpl1itudeFreRun == 0)
        {
            QPen pen;
            C5ZgyroAmpl1itudeFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroAmpl1itudeFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroAmpl1itudeFreNum)->setData(C5curveX,C5VZgyroAmpl1itudeFre);
            customPlot->graph(C5ZgyroAmpl1itudeFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroAmpl1itudeFreRun = 1;
            set_checkBox_48_49_47();
        }
        else
        {
            customPlot->graph(C5ZgyroAmpl1itudeFreNum)->setData(C5curveX,C5VZgyroAmpl1itudeFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroAmpl1itudeFreRun == 1)
        {
            C5ZgyroAmpl1itudeFreRun = 0;
            C5XgyroAmpl1itudeFreRun = 0;
            C5YgyroAmpl1itudeFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS纬度曲线****************************************/
    if(ui->checkBox_51->isChecked())
    {
        if(C3GPSlatitudeRun == 0)
        {
            QPen pen;
            C3GPSlatitudeNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C3GPSlatitudeNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3GPSlatitudeNum)->setData(C3curveX,C3VGPSlatitude);
            customPlot->graph(C3GPSlatitudeNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3GPSlatitudeRun = 1;
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
            customPlot->graph(C3GPSlatitudeNum)->setData(C3curveX,C3VGPSlatitude);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3GPSlatitudeRun == 1)
        {
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C8GPSHeightRun = 0;
            C8GPTUpSpeedRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS经度曲线****************************************/
    if(ui->checkBox_54->isChecked())
    {
        if(C3longitudeRun == 0)
        {
            QPen pen;
            C3longitudeNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C3longitudeNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3longitudeNum)->setData(C3curveX,C3Vlongitude);
            customPlot->graph(C3longitudeNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3longitudeRun = 1;
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
            customPlot->graph(C3longitudeNum)->setData(C3curveX,C3Vlongitude);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3longitudeRun == 1)
        {
            C3longitudeRun = 0;
            C3GPSlatitudeRun = 0;
            C3togetherSpeedRun = 0;
            C8GPTUpSpeedRun = 0;
            C8GPSHeightRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C8的GPS高度曲线****************************************/
    if(ui->checkBox_84->isChecked())
    {
        if(C8GPSHeightRun == 0)
        {
            QPen pen;
            C8GPSHeightNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,71,75));
            customPlot->graph(C8GPSHeightNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C8GPSHeightNum)->setData(C8curveX,C8VC8GPSHeight);
            customPlot->graph(C8GPSHeightNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C8GPSHeightRun = 1;
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
            customPlot->graph(C8GPSHeightNum)->setData(C8curveX,C8VC8GPSHeight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C8GPSHeightRun == 1)
        {
            C8GPSHeightRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C8GPTUpSpeedRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C8的GPS天速曲线****************************************/
    if(ui->checkBox_87->isChecked())
    {
        if(C8GPTUpSpeedRun == 0)
        {
            QPen pen;
            C8GPTUpSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,200,244));
            customPlot->graph(C8GPTUpSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C8GPTUpSpeedNum)->setData(C8curveX,C8VC8GPTUpSpeed);
            customPlot->graph(C8GPTUpSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C8GPTUpSpeedRun = 1;
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
            customPlot->graph(C8GPTUpSpeedNum)->setData(C8curveX,C8VC8GPTUpSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C8GPTUpSpeedRun == 1)
        {
            C8GPTUpSpeedRun = 0;
            C8GPSHeightRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS合速曲线****************************************/
    if(ui->checkBox_50->isChecked())
    {
        if(C3togetherSpeedRun == 0)
        {
            QPen pen;
            C3togetherSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C3togetherSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3togetherSpeedNum)->setData(C3curveX,C3VtogetherSpeed);
            customPlot->graph(C3togetherSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3togetherSpeedRun = 1;
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
            customPlot->graph(C3togetherSpeedNum)->setData(C3curveX,C3VtogetherSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3togetherSpeedRun == 1)
        {

            C3togetherSpeedRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C8GPSHeightRun = 0;
            C8GPTUpSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS航向曲线****************************************/
    if(ui->checkBox_52->isChecked())
    {
        if(C3headingAngleRun == 0)
        {
            QPen pen;
            C3headingAngleNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C3headingAngleNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3headingAngleNum)->setData(C3curveX,C3VheadingAngle);
            customPlot->graph(C3headingAngleNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3headingAngleRun = 1;
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
            customPlot->graph(C3headingAngleNum)->setData(C3curveX,C3VheadingAngle);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3headingAngleRun == 1)
        {
            C3headingAngleRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C8GPSHeightRun = 0;
            C8GPTUpSpeedRun = 0;
            C3togetherSpeedRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS东速曲线****************************************/
    if(ui->checkBox_53->isChecked())
    {
        if(C3combinedEastSpeedRun == 0)
        {
            QPen pen;
            C3combinedEastSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C3combinedEastSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3combinedEastSpeedNum)->setData(C3curveX,C3VcombinedEastSpeed);
            customPlot->graph(C3combinedEastSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3combinedEastSpeedRun = 1;
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
            customPlot->graph(C3combinedEastSpeedNum)->setData(C3curveX,C3VcombinedEastSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3combinedEastSpeedRun == 1)
        {
            C3combinedEastSpeedRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C8GPSHeightRun = 0;
            C8GPTUpSpeedRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS北速曲线****************************************/
    if(ui->checkBox_60->isChecked())
    {
        if(C3combinedNorthSpeedRun == 0)
        {
            QPen pen;
            C3combinedNorthSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,0,255));
            customPlot->graph(C3combinedNorthSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3combinedNorthSpeedNum)->setData(C3curveX,C3VcombinedNorthSpeed);
            customPlot->graph(C3combinedNorthSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3combinedNorthSpeedRun = 1;
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
            customPlot->graph(C3combinedNorthSpeedNum)->setData(C3curveX,C3VcombinedNorthSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3combinedNorthSpeedRun == 1)
        {
            C3combinedNorthSpeedRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C8GPSHeightRun = 0;
            C8GPTUpSpeedRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;

            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的C3多普勒对水横向速度曲线****************************************/
    if(ui->checkBox_59->isChecked())
    {
        if(C3waterXRun == 0)
        {
            QPen pen;
            C3waterXNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C3waterXNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3waterXNum)->setData(C3curveX,C3VwaterX);
            customPlot->graph(C3waterXNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3waterXRun = 1;
            set_checkBox_59_56_57_55_58();
        }
        else
        {
            customPlot->graph(C3waterXNum)->setData(C3curveX,C3VwaterX);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3waterXRun == 1)
        {
            C3waterXRun = 0;
            C8LogDownSpeed2WaterRun = 0;
            C8LogDownSpeed2GroundRun = 0;
            C3waterYRun = 0;
            C3bottomXRun = 0;
            C3bottomYRun = 0;
            C3electromagnetismSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3多普勒对水纵向速度曲线****************************************/
    if(ui->checkBox_56->isChecked())
    {
        if(C3waterYRun == 0)
        {
            QPen pen;
            C3waterYNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C3waterYNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3waterYNum)->setData(C3curveX,C3VwaterY);
            customPlot->graph(C3waterYNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3waterYRun = 1;
            set_checkBox_59_56_57_55_58();
        }
        else
        {
            customPlot->graph(C3waterYNum)->setData(C3curveX,C3VwaterY);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3waterYRun == 1)
        {
            C3waterYRun = 0;
            C8LogDownSpeed2WaterRun = 0;
            C8LogDownSpeed2GroundRun = 0;
            C3waterXRun = 0;
            C3bottomXRun = 0;
            C3bottomYRun = 0;
            C3electromagnetismSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C3的C3多普勒对底横向速度曲线****************************************/
    if(ui->checkBox_57->isChecked())
    {
        if(C3bottomXRun == 0)
        {
            QPen pen;
            C3bottomXNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C3bottomXNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3bottomXNum)->setData(C3curveX,C3VbottomX);
            customPlot->graph(C3bottomXNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3bottomXRun = 1;
            set_checkBox_59_56_57_55_58();
        }
        else
        {
            customPlot->graph(C3bottomXNum)->setData(C3curveX,C3VbottomX);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3bottomXRun == 1)
        {
            C3bottomXRun = 0;
            C8LogDownSpeed2WaterRun = 0;
            C8LogDownSpeed2GroundRun = 0;
            C3bottomYRun = 0;
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3electromagnetismSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3多普勒对底纵向速度曲线****************************************/
    if(ui->checkBox_55->isChecked())
    {
        if(C3bottomYRun == 0)
        {
            QPen pen;
            C3bottomYNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C3bottomYNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3bottomYNum)->setData(C3curveX,C3VbottomY);
            customPlot->graph(C3bottomYNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3bottomYRun = 1;
            set_checkBox_59_56_57_55_58();
        }
        else
        {
            customPlot->graph(C3bottomYNum)->setData(C3curveX,C3VbottomY);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3bottomYRun == 1)
        {
            C3bottomYRun = 0;
            C8LogDownSpeed2WaterRun = 0;
            C8LogDownSpeed2GroundRun = 0;
            C3bottomXRun = 0;
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3electromagnetismSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3电磁速度曲线****************************************/
    if(ui->checkBox_58->isChecked())
    {
        if(C3electromagnetismSpeedRun == 0)
        {
            QPen pen;
            C3electromagnetismSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C3electromagnetismSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3electromagnetismSpeedNum)->setData(C3curveX,C3VelectromagnetismSpeed);
            customPlot->graph(C3electromagnetismSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3electromagnetismSpeedRun = 1;
            set_checkBox_59_56_57_55_58();
        }
        else
        {
            customPlot->graph(C3electromagnetismSpeedNum)->setData(C3curveX,C3VelectromagnetismSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3electromagnetismSpeedRun == 1)
        {
            C3electromagnetismSpeedRun = 0;
            C8LogDownSpeed2GroundRun = 0;
            C8LogDownSpeed2WaterRun = 0;
            C3bottomXRun = 0;
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3bottomYRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C8对水曲线****************************************/
    if(ui->checkBox_85->isChecked())
    {
        if(C8LogDownSpeed2WaterRun == 0)
        {
            QPen pen;
            C8LogDownSpeed2WaterNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,0,255));
            customPlot->graph(C8LogDownSpeed2WaterNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C8LogDownSpeed2WaterNum)->setData(C8curveX,C8VC8LogDownSpeed2Water);
            customPlot->graph(C8LogDownSpeed2WaterNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C8LogDownSpeed2WaterRun = 1;
            set_checkBox_59_56_57_55_58();
        }
        else
        {
            customPlot->graph(C8LogDownSpeed2WaterNum)->setData(C8curveX,C8VC8LogDownSpeed2Water);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C8LogDownSpeed2WaterRun == 1)
        {
            C8LogDownSpeed2WaterRun = 0;
            C8LogDownSpeed2GroundRun = 0;
            C3electromagnetismSpeedRun = 0;
            C3bottomXRun = 0;
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3bottomYRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C8对地曲线****************************************/
    if(ui->checkBox_86->isChecked())
    {
        if(C8LogDownSpeed2GroundRun == 0)
        {
            QPen pen;
            C8LogDownSpeed2GroundNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,71,75));
            customPlot->graph(C8LogDownSpeed2GroundNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C8LogDownSpeed2GroundNum)->setData(C8curveX,C8VC8LogDownSpeed2Ground);
            customPlot->graph(C8LogDownSpeed2GroundNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C8LogDownSpeed2GroundRun = 1;
            set_checkBox_59_56_57_55_58();
        }
        else
        {
            customPlot->graph(C8LogDownSpeed2GroundNum)->setData(C8curveX,C8VC8LogDownSpeed2Ground);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C8LogDownSpeed2GroundRun == 1)
        {
            C8LogDownSpeed2GroundRun = 0;
            C8LogDownSpeed2WaterRun = 0;
            C3electromagnetismSpeedRun = 0;
            C3bottomXRun = 0;
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3bottomYRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

#ifdef INSIDE
    if(1)//不显示零偏曲线2022-1-20
    {
        /**********************************C6X陀螺零偏****************************************/
        if(ui->checkBox_61->isChecked())
        {
            if(C6XGroyFloatRun == 0)
            {
                QPen pen;
                C6XGroyFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C6XGroyFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6XGroyFloatNum)->setData(C6curveX,C6VC6XGroyFloat);
                customPlot->graph(C6XGroyFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6XGroyFloatRun = 1;
                set_checkBox_61_63_62();
            }
            else
            {
                customPlot->graph(C6XGroyFloatNum)->setData(C6curveX,C6VC6XGroyFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6XGroyFloatRun == 1)
            {
                C6XGroyFloatRun = 0;
                C6YGroyFloatRun = 0;
                C6ZGroyFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6Y陀螺零偏****************************************/
        if(ui->checkBox_63->isChecked())
        {
            if(C6YGroyFloatRun == 0)
            {
                QPen pen;
                C6YGroyFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C6YGroyFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6YGroyFloatNum)->setData(C6curveX,C6VC6YGroyFloat);
                customPlot->graph(C6YGroyFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6YGroyFloatRun = 1;
                set_checkBox_61_63_62();
            }
            else
            {
                customPlot->graph(C6YGroyFloatNum)->setData(C6curveX,C6VC6YGroyFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6YGroyFloatRun == 1)
            {
                C6YGroyFloatRun = 0;
                C6XGroyFloatRun = 0;
                C6ZGroyFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6Z陀螺零偏****************************************/
        if(ui->checkBox_62->isChecked())
        {
            if(C6ZGroyFloatRun == 0)
            {
                QPen pen;
                C6ZGroyFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C6ZGroyFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6ZGroyFloatNum)->setData(C6curveX,C6VC6ZGroyFloat);
                customPlot->graph(C6ZGroyFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6ZGroyFloatRun = 1;
                set_checkBox_61_63_62();
            }
            else
            {
                customPlot->graph(C6ZGroyFloatNum)->setData(C6curveX,C6VC6ZGroyFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6ZGroyFloatRun == 1)
            {
                C6ZGroyFloatRun = 0;
                C6XGroyFloatRun = 0;
                C6YGroyFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6X加速度计零偏****************************************/
        if(ui->checkBox_65->isChecked())
        {
            if(C6XAccelerometerFloatRun == 0)
            {
                QPen pen;
                C6XAccelerometerFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C6XAccelerometerFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6XAccelerometerFloatNum)->setData(C6curveX,C6VC6XAccelerometerFloat);
                customPlot->graph(C6XAccelerometerFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6XAccelerometerFloatRun = 1;
                set_checkBox_65_64_66();
            }
            else
            {
                customPlot->graph(C6XAccelerometerFloatNum)->setData(C6curveX,C6VC6XAccelerometerFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6XAccelerometerFloatRun == 1)
            {
                C6XAccelerometerFloatRun = 0;
                C6YAccelerometerFloatRun = 0;
                C6ZAccelerometerFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6Y加速度计零偏****************************************/
        if(ui->checkBox_64->isChecked())
        {
            if(C6YAccelerometerFloatRun == 0)
            {
                QPen pen;
                C6YAccelerometerFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C6YAccelerometerFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6YAccelerometerFloatNum)->setData(C6curveX,C6VC6YAccelerometerFloat);
                customPlot->graph(C6YAccelerometerFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6YAccelerometerFloatRun = 1;
                set_checkBox_65_64_66();
            }
            else
            {
                customPlot->graph(C6YAccelerometerFloatNum)->setData(C6curveX,C6VC6YAccelerometerFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6YAccelerometerFloatRun == 1)
            {
                C6YAccelerometerFloatRun = 0;
                C6XAccelerometerFloatRun = 0;
                C6ZAccelerometerFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6Z加速度计零偏****************************************/
        if(ui->checkBox_66->isChecked())
        {
            if(C6ZAccelerometerFloatRun == 0)
            {
                QPen pen;
                C6ZAccelerometerFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C6ZAccelerometerFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6ZAccelerometerFloatNum)->setData(C6curveX,C6VC6ZAccelerometerFloat);
                customPlot->graph(C6ZAccelerometerFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6ZAccelerometerFloatRun = 1;
                set_checkBox_65_64_66();
            }
            else
            {
                customPlot->graph(C6ZAccelerometerFloatNum)->setData(C6curveX,C6VC6ZAccelerometerFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6ZAccelerometerFloatRun == 1)
            {
                C6ZAccelerometerFloatRun = 0;
                C6XAccelerometerFloatRun = 0;
                C6YAccelerometerFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
    }
#endif
    /**********************************东速误差****************************************/
    if(ui->checkBox_67->isChecked())
    {
        if(eastSpeedErrorRun == 0)
        {
            QPen pen;
            eastSpeedErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(eastSpeedErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(eastSpeedErrorNum)->setData(C1curveX,VeastSpeedError);
            customPlot->graph(eastSpeedErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            eastSpeedErrorRun = 1;
            set_checkBox_67_69_68();
        }
        else
        {
            customPlot->graph(eastSpeedErrorNum)->setData(C1curveX,VeastSpeedError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(eastSpeedErrorRun == 1)
        {
            eastSpeedErrorRun = 0;
            northSpeedErrorRun = 0;
            togetherSpeedErrorRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************北速误差****************************************/
    if(ui->checkBox_69->isChecked())
    {
        if(northSpeedErrorRun == 0)
        {
            QPen pen;
            northSpeedErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(northSpeedErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(northSpeedErrorNum)->setData(C1curveX,VnorthSpeedError);
            customPlot->graph(northSpeedErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            northSpeedErrorRun = 1;
            set_checkBox_67_69_68();
        }
        else
        {
            customPlot->graph(northSpeedErrorNum)->setData(C1curveX,VnorthSpeedError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(northSpeedErrorRun == 1)
        {
            northSpeedErrorRun = 0;
            togetherSpeedErrorRun = 0;
            eastSpeedErrorRun = 0;
            ui->customPlot2->clearGraphs();
            customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************合速误差****************************************/
    if(ui->checkBox_68->isChecked())
    {
        if(togetherSpeedErrorRun == 0)
        {
            QPen pen;
            togetherSpeedErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(togetherSpeedErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(togetherSpeedErrorNum)->setData(C1curveX,VtogetherSpeedError);
            customPlot->graph(togetherSpeedErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            togetherSpeedErrorRun = 1;
            set_checkBox_67_69_68();
        }
        else
        {
            customPlot->graph(togetherSpeedErrorNum)->setData(C1curveX,VtogetherSpeedError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(togetherSpeedErrorRun == 1)
        {
            togetherSpeedErrorRun = 0;
            northSpeedErrorRun = 0;
            eastSpeedErrorRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************纬度误差****************************************/
    if(ui->checkBox_70->isChecked())
    {
        if(latitudeErrorRun == 0)
        {
            QPen pen;
            latitudeErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(latitudeErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(5);
            customPlot->graph(latitudeErrorNum)->setData(C1curveX,VlatitudeError);
            customPlot->graph(latitudeErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            latitudeErrorRun = 1;
            set_checkBox_70_72_71();
        }
        else
        {
            customPlot->graph(latitudeErrorNum)->setData(C1curveX,VlatitudeError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(latitudeErrorRun == 1)
        {
            latitudeErrorRun = 0;
            longitudeErrorRun = 0;
            positionErrorRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************经度误差****************************************/
    if(ui->checkBox_72->isChecked())
    {
        if(longitudeErrorRun == 0)
        {
            QPen pen;
            longitudeErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(longitudeErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(5);
            customPlot->graph(longitudeErrorNum)->setData(C1curveX,VlongitudeError);
            customPlot->graph(longitudeErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            longitudeErrorRun = 1;
            set_checkBox_70_72_71();
        }
        else
        {
            customPlot->graph(longitudeErrorNum)->setData(C1curveX,VlongitudeError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(longitudeErrorRun == 1)
        {
            longitudeErrorRun = 0;
            latitudeErrorRun = 0;
            positionErrorRun = 0;
            ui->customPlot2->clearGraphs();
            customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************合速误差****************************************/
    if(ui->checkBox_71->isChecked())
    {
        if(positionErrorRun == 0)
        {
            QPen pen;
            positionErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(positionErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(5);
            customPlot->graph(positionErrorNum)->setData(C1curveX,VpositionError);
            customPlot->graph(positionErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            positionErrorRun = 1;
            set_checkBox_70_72_71();
        }
        else
        {
            customPlot->graph(positionErrorNum)->setData(C1curveX,VpositionError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(positionErrorRun == 1)
        {
            positionErrorRun = 0;
            latitudeErrorRun = 0;
            longitudeErrorRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
}

/*b
 * @breif 设置LED灯，通讯正常为绿色，通讯失败为红色
 */
void MainWindow::setLED1(QLabel* label, int color, int size)
{
    // 将label中的文字清空
       label->setText("");
       // 先设置矩形大小
       // 如果ui界面设置的label大小比最小宽度和高度小，矩形将被设置为最小宽度和最小高度；
       // 如果ui界面设置的label大小比最小宽度和高度大，矩形将被设置为最大宽度和最大高度；
       QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
       QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
       QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
       QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
       // 再设置边界形状及边框
       QString border_radius = QString("border-radius: %1px;").arg(size/2);    // 边框是圆角，半径为size/2
       QString border = QString("border:1px solid black;");                    // 边框为1px黑色
       // 最后设置背景颜色
       QString background = "background-color:";
       switch (color) {
       case 0:
           // 灰色
           background += "rgb(190,190,190)";
           break;
       case 1:
           // 红色
           background += "rgb(255,0,0)";
           break;
       case 2:
           // 绿色
           background += "rgb(0,255,0)";
           break;
       case 3:
           // 黄色
           background += "rgb(255,255,0)";
           break;
       default:
           break;
       }

       const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
       label->setStyleSheet(SheetStyle);

}
#ifdef QEXTSERIALPORT
void MainWindow::InitSerialPortName()
{
    // 清空下拉框
    ui->box_portName->clear();
    QStringList comList;//串口号
    comList<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5"<<"COM6"
          <<"COM7"<<"COM8"<<"COM9"<<"COM10"<<"COM11"<<"COM12"
         <<"COM13"<<"COM14"<<"COM15";
    //通过QSerialPortInfo查找可用串口
     ui->box_portName->addItems(comList);
}
#endif

/*
 * @breif 将16进制字符串转换为对应的字节序列
 */
QByteArray MainWindow::HexStringToByteArray(QString HexString)
{
    bool ok;
    QByteArray ret;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    QStringList sl = HexString.split(" ");

    foreach (QString s, sl) {
        if(!s.isEmpty())
        {
            char c = s.toInt(&ok,16)&0xFF;
            if(ok){
                ret.append(c);
            }
        }
    }
    return ret;
}

/*
 * @breif 将字节序列转换为对应的16进制字符串
 */
QString MainWindow::ByteArrayToHexString(QByteArray data)
{
    QString ret(data.toHex().toUpper());
    int len = ret.length()/2;
    for(int i=1;i<len;i++)
    {
        ret.insert(2*i+i-1," ");
    }

    return ret;
}

void MainWindow::   handleResults()
{
    hasDataVaildC1++;
    hasDataVaildC2++;
    hasDataVaildC3++;
    hasDataVaildC8++;
    if(hasDataVaildC1 > 60)
    {

        ui->lineEdit_7	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_8	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_9	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_10	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_11	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_12	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_13	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_14	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_15	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_16	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_17	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_18	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_19	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_20	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_21	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_22	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_23	->setStyleSheet("color: rgb(0, 0, 0);");


        ui->lineEdit_31	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_32	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_33	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_34	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_55 ->setStyleSheet("color: rgb(0, 0, 0);");

    }
    if(hasDataVaildC3> 60)
    {
        ui->lineEdit_27	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_28	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_29	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_30	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_46 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_35	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_36	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_37	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_38	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_39	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_40	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_41	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_42	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_43	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_44	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_51 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_52 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_54 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_49	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_24	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_25	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_26	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_48 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_53 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_50 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->label_53->setStyleSheet("font:bold;color:Red");
        ui->label_17->setStyleSheet("font:bold;color:Red");
        ui->label_27->setStyleSheet("font:bold;color:Red");
        ui->label_28->setStyleSheet("font:bold;color:Red");
        ui->label_25->setStyleSheet("font:bold;color:Red");
        ui->label_55->setStyleSheet("font:bold;color:Red");

    }
    if(hasDataVaildC2>60)
    {
        ui->label_16->setStyleSheet("font:bold;color:Red");

    }
    if(hasDataVaildC8>60)
    {
        ui->lineEdit_45 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_47 ->setStyleSheet("color: rgb(0, 0, 0);");

    }
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    QByteArray result;
    if(serial_1 !=NULL)
    {
        if(serial_1->bytesAvailable()<=0)
        {
            return;
        }
        else
        {
            noVaildMessage++;
            if(noVaildMessage > restart)
            {
                restartTime++;
                serial_1->close();
                //设置串口名
                QString portName = (ui->box_portName->currentText()).split(":").at(0);
                serial_1 = new QextSerialPort(portName);

                if(serial_1->open(QIODevice::ReadWrite))
                {
                    //清空缓冲区
                    serial_1->flush();
                    //设置波特率
                    serial_1->setBaudRate((BaudRateType)ui->box_baudrate->currentText().toInt());

                    //设置停止位
                    if(ui->box_stopBit->currentText() == "1")
                        serial_1->setStopBits(STOP_1);
                    else if(ui->box_stopBit->currentText() == "1.5")
                        serial_1->setStopBits(STOP_1_5);
                    else if(ui->box_stopBit->currentText() == "2")
                        serial_1->setStopBits(STOP_2);

                    //设置数据位数
                    if(ui->box_dataBits->currentText() == "8")
                        serial_1->setDataBits(DATA_8);
                    else if(ui->box_dataBits->currentText() == "7")
                        serial_1->setDataBits(DATA_7);
                    else if(ui->box_dataBits->currentText() == "6")
                        serial_1->setDataBits(DATA_6);
                    else if(ui->box_dataBits->currentText() == "5")
                        serial_1->setDataBits(DATA_5);

                    //设置奇偶校验
                    if(ui->box_parityBit->currentText() == "None")
                        serial_1->setParity(PAR_NONE);
                    else if(ui->box_parityBit->currentText() == "Even")
                        serial_1->setParity(PAR_EVEN);
                    else if(ui->box_parityBit->currentText() == "Odd")
                        serial_1->setParity(PAR_ODD);

                    //设置流控制
                    serial_1->setFlowControl(FLOW_OFF);

                    //下拉菜单控件失能
                    ui->box_portName->setEnabled(false);
                    ui->box_baudrate->setEnabled(false);
                    ui->box_dataBits->setEnabled(false);
                    ui->box_parityBit->setEnabled(false);
                    ui->box_stopBit->setEnabled(false);

                    ui->btn_openPort->setText(QString("关闭串口"));

                    this->setLED1(ui->label_69,2,15);
                    serial_1->setTimeout(10);

                }
                else
                {
                    QMessageBox::about(NULL, "提示", "无法打开串口！");
                    return;
                }
                noVaildMessage = 0;
                if(restartTime>=3)
                {
                    restart = restartTime * 200;
                }

                return;
            }
            else
            {
                mySleep(handleResultDelay2);
                QByteArray buffertemp = serial_1->readAll();
                result = buffertemp.toHex();

            }
        }
    }

    union C5ValueUnion_
    {
        qint32 qint32Value;
        float floatValue;
    }C5ValueUnion;

    ui->lineEdit_4->setText(dateStr);  //显示界面的北京时间
    if(1)   //新建历史数据文件
    {
        if(dataInvaildRecord > SaveFileRecord)
        {
            C1fileSave.close();
            C2fileSave.close();
            C3fileSave.close();
            C5fileSave.close();
            C6fileSave.close();
            C8fileSave.close();
             fileSaveNum++;
            QString fileSaveNumStr = QString::number(fileSaveNum,10);
            SaveFileRecord = SaveFileRecord + 400000;
            QDateTime current_date_time =QDateTime::currentDateTime();
            QString dateStr =current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
            QString C1HisDataName = "./history/nav1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
            QString C2HisDataName = "./history/cond1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
            QString C3HisDataName = "./history/ref1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
            QString C5HisDataName = "./history/imu1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
            QString C6HisDataName = "./history/calInfo1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
            QString C8HisDataName = "./history/addInfo1s_"+ dateStr+"_"+fileSaveNumStr+".csv";

             C1fileSave.setFileName(C1HisDataName);
            if(!C1fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C1文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC1(&C1fileSave);
            //QString headStr1 = "时间序号,标识号,系统时间,状态时间,纬度°,经度°,东速kn,北速kn,航向角°,横摇角°,纵摇角°,航向角速度°/s,横摇角速度°/s,纵摇角速度°/s,垂荡m,垂速m/s,横荡m,横速m/s,纵荡m,纵速m/s,导航信息有效位,系统状态,时码,参考纬度°,参考经度°,参考组合东速kn,参考组合北速kn,参考阻尼东速kn,参考阻尼北速kn,参考航向°,参考信息有效位";
            //完整保存字符串
            //QString headStr1 = "时间序号,标识号,系统时间,状态时间,纬度°,经度°,东速kn,北速kn,航向角°,横摇角°,纵摇角°,航向角速度°/s,横摇角速度°/s,纵摇角速度°/s,垂荡m,垂速m/s,横荡m,横速m/s,纵荡m,纵速m/s,时码有效,经纬度有效,东北速有效,航向有效,纵横摇有效,角速度有效,升沉有效,纵横荡有效,导航状态,工作位置,切换模式,时码,参考纬度°,参考经度°,参考组合东速kn,参考组合北速kn,参考阻尼东速kn,参考阻尼北速kn,参考航向°,参考经纬度,参考组合速度,参考阻尼,参考航向";
            //dataOutC1<<headStr1.toUtf8();

            C2fileSave.setFileName(C2HisDataName);
            if(!C2fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C2文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC2(&C2fileSave);
            //QString headStr2 = "时间序号,标识号,系统时间,信息传输标识,信息有效标识,故障码,GX陀螺常值漂移°/h,GY陀螺常值漂移°/h,GZ陀螺常值漂移°/h,AX加速度计零偏mg,AY加速度计零偏mg,AZ加速度计零偏mg";
            //完整保存字符串
            //QString headStr2 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到陀螺标定参数,收到加速度计标定参数,收到陀螺零偏温补系数,收到加速度计零位温补系数,收到装订航向,收到等效零偏,收到漂移补偿,收到状态切换命令,收到系统姿态零位,收到惯组和输出姿态零位,收到杆臂,收到显控参考信息,收到1PPS信号,收到录取同步信号,收到主惯导信息,收到系统编号,收到在舰位置,收到IP地址,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GX漂移估计补偿,GY漂移估计补偿,GZ漂移估计补偿,AX零偏估计补偿,AY零偏估计补偿,AZ零偏估计补偿,水平姿态误差估计补偿,航向误差估计补偿,速度误差估计补偿,位置误差估计补偿,直航状态,静止状态,锚泊状态,振动状态,冲击状态,主惯导位置有效,主惯导速度有效,主惯导姿态有效,主惯导角速度有效,陀螺故障,加速度计故障,IF板故障,采集板故障,通信板故障,接口板故障,解算异常故障,备用电源故障,GX陀螺常值漂移°/h,GY陀螺常值漂移°/h,GZ陀螺常值漂移°/h,AX加速度计零偏mg,AY加速度计零偏mg,AZ加速度计零偏mg";
            //dataOutC2<<headStr2.toUtf8();

            C3fileSave.setFileName(C3HisDataName);
            if(!C3fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C3文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC3(&C3fileSave);
            // QString headStr3 = "时间序号,标识号,系统时间,信息收到标识,信息有效标识,GPS纬度°,GPS经度°,GPS合速kn,GPS航向°,GPS东速kn,GPS北速kn,电磁速度kn,多普勒对水横向速度kn,多普勒对水纵向速度kn,多普勒对底横向速度kn,多普勒对底纵向速度kn,时码：日月年,时码：天秒s,插值时间us,GPS卫星数,GPS水平精度因子";

            //完整保存字符串
            //QString headStr3 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到1PPS信号,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GPS纬度°,GPS经度°,GPS合速kn,GPS航向°,GPS东速kn,GPS北速kn,电磁速度kn,多普勒对水横向速度kn,多普勒对水纵向速度kn,多普勒对底横向速度kn,多普勒对底纵向速度kn,时码：日月年,时码：天秒s,插值时间us,GPS卫星数,GPS水平精度因子";
            //dataOutC3<<headStr3.toUtf8();

            C5fileSave.setFileName(C5HisDataName);
            if(!C5fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C5文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC5(&C5fileSave);
            //QString headStr5 = "时间序号,标识号,系统时间,X陀螺1s角增量°/h,Y陀螺1s角增量°/h,Z陀螺1s角增量°/h,X加速度计1s速度增量m/s/s,Y加速度计1s速度增量m/s/s,Z加速度计1s速度增量m/s/s,X陀螺1s补偿后角增量°/h,Y陀螺1s补偿后角增量°/h,Z陀螺1s补偿后角增量°/h,X加速度计1s补偿后速度增量m/s/s,Y加速度计1s补偿后速度增量m/s/s,Z加速度计1s补偿后速度增量m/s/s,X陀螺差频p/s,Y陀螺差频p/s,Z陀螺差频p/s,X加速度计差频p/s,Y加速度计差频p/s,Z加速度计差频p/s,X陀螺抖幅p/s,Y陀螺抖幅p/s,Z陀螺抖幅p/s,X陀螺抖频Hz,Y陀螺抖频Hz,Z陀螺抖频Hz,X陀螺温度1°C,X陀螺温度2°C,Y陀螺温度1°C,Y陀螺温度2°C,Z陀螺温度1°C,Z陀螺温度2°C,IF板温度°C,X加速度计温度°C,Y加速度计温度°C,Z加速度计温度°C,采集板温度°C";
            //完整保存字符串
            //QString headStr5 = "时间序号,标识号,系统时间,X陀螺1s角增量°/h,Y陀螺1s角增量°/h,Z陀螺1s角增量°/h,X加速度计1s速度增量m/s/s,Y加速度计1s速度增量m/s/s,Z加速度计1s速度增量m/s/s,X陀螺1s补偿后角增量°/h,Y陀螺1s补偿后角增量°/h,Z陀螺1s补偿后角增量°/h,X加速度计1s补偿后速度增量m/s/s,Y加速度计1s补偿后速度增量m/s/s,Z加速度计1s补偿后速度增量m/s/s,X陀螺差频p/s,Y陀螺差频p/s,Z陀螺差频p/s,X加速度计差频p/s,Y加速度计差频p/s,Z加速度计差频p/s,X陀螺抖幅p/s,Y陀螺抖幅p/s,Z陀螺抖幅p/s,X陀螺抖频Hz,Y陀螺抖频Hz,Z陀螺抖频Hz,X陀螺温度1°C,X陀螺温度2°C,Y陀螺温度1°C,Y陀螺温度2°C,Z陀螺温度1°C,Z陀螺温度2°C,IF板温度°C,X加速度计温度°C,Y加速度计温度°C,Z加速度计温度°C,采集板温度°C";
            //dataOutC5<<headStr5.toUtf8();

            C6fileSave.setFileName(C6HisDataName);
            if(!C6fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C6文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC6(&C6fileSave);

            C8fileSave.setFileName(C8HisDataName);
            if(!C8fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C8文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC8(&C8fileSave);
        }


    }

    QString bufferStrOri = QString(result);
    QStringList startList = bufferStrOri.split("eb90");
    for(int ii = 0;ii<startList.size();ii++)
    {
        QString bufferStr = "eb90"+ startList[ii];
        /**********************************************解析导航信息C1******************************************************************/
        if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == '1')
        {
            if(bufferStr.size() != 184)
            {
                continue;
            }
            dataInvaildRecord++;
            int C1checkNumInt = 0;
            QString C1checkNumStr;
            for(int i= 4;i<182;i=i+2)
            {
                C1checkNumInt = C1checkNumInt + bufferStr.mid(i,2).toInt(nullptr,16);
            }
            C1checkNumStr = QString::number(C1checkNumInt,16).right(2);

            if(C1checkNumStr == bufferStr.mid(182,2))
            {
                /****************************************解析导航信息有效位**********************************************/
                QString bufferStrC1Vaild = QString(bufferStr);
                QString bufferStrC1 = QString(bufferStr);
                bufferStrC1Vaild.remove(0,126); //定位到导航信息有效位置
                quint8 NavVaildBuff = quint8(bufferStrC1Vaild.left(2).toUInt(nullptr,16)); //暂时不采用有效位
                quint8 NavVaild = 0xFF;
                QString timeFramesVaild = QString::number((NavVaild) >> (1-1)&1);           //时码有效标志位     Bit0
                QString longitudeLatitudeVaild = QString::number((NavVaild) >> (2-1)&1);    //经纬度有效标志位   Bit1
                QString northeastSpeed = QString::number((NavVaild) >> (3-1)&1);            //东北速有效标志位   Bit2
                QString headingVaild = QString::number((NavVaild) >> (4-1)&1);              //航向有效标志位     Bit3
                QString verHorShakVaild = QString::number((NavVaild) >> (5-1)&1);           //纵横摇有效标志位   Bit4
                QString angulaVelocityVaild = QString::number((NavVaild) >> (6-1)&1);       //角速度有效标志位   Bit5
                QString heaveVaild = QString::number((NavVaild) >> (7-1)&1);                //升沉有效标志位     Bit6
                QString swayVaild = QString::number((NavVaild) >> (8-1)&1);                 //纵横荡有效标志位    Bit7

                /****************************************解析系统时间3-6字节*********************************************/
                bufferStrC1.remove(0,6);

                QString SysTimeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);

                quint32 sysTimeMs = quint32(SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒

                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                int dayInt = houInt * 24;

                long day = 0;
                long hour = (sysTimeMs - day * dayInt) / houInt;
                long minute = (sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;

                ui->lineEdit_5->setText(sysTimeStr);

                /****************************************解析状态时间7-10字节*********************************************/
                bufferStrC1.remove(0,8);
                QString stateMsStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);

                quint32 stateMs = quint32(stateMsStr.toUInt(nullptr,16));   //状态时间，毫秒

                hour = (stateMs - day * dayInt) / houInt;
                minute = (stateMs - day * dayInt- hour * houInt) / minInt ;
                second = (stateMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                milliSecond = stateMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;
                houQStr  = QString::number(hour,10);
                minQStr  = QString::number(minute,10);
                secQStr  = QString::number(second,10);
                msecQStr = QString::number(milliSecond,10);
                QString stateTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;
                ui->lineEdit_6->setText(stateTimeStr);

                /****************************************解析纬度11-14字节*********************************************/
                bufferStrC1.remove(0,8);
                QString latitudeStrDis;
                QString latitudeStrDis_D;
                if(longitudeLatitudeVaild == "1")
                {
                    QString latitudeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 latitudeInt32 = qint32(latitudeStr.toUInt(nullptr,16));   //状态时间，毫秒
                    latitude = latitudeInt32 * 90.0 * qPow(2,-31);
                    char NS = 'N';
                    if(latitude > 0){
                        NS = 'N';
                    }
                    else{
                        NS= 'S';
                    }
                    QString latStr = QString::number(latitude,'f',4);
                    qreal latitudeAbs = fabs(latStr.toFloat());
                    double latitudeAbsDeg =  floor(latitudeAbs);
                    QString latitudeDegStr = QString("%1").arg(latitudeAbsDeg);
                    double latitudeAbsMin  =  (latitudeAbs - latitudeAbsDeg)* 60.0;

                    QString latitudeMinStr = QString::number(latitudeAbsMin,'f',3);
                    latitudeStrDis = NS+latitudeDegStr+"°"+latitudeMinStr+"′";
                    latitudeStrDis_D = QString::number(latitude,'f',9);

                    if(isDegree == 0)
                        ui->lineEdit_7->setText(latitudeStrDis);
                    else
                        ui->lineEdit_7->setText(NS+latStr+"°");


                }

                /****************************************解析经度15-18字节*********************************************/
                bufferStrC1.remove(0,8);
                QString longitudeStrDis;
                QString longitudeStrDis_D;
                if(longitudeLatitudeVaild == "1")
                {
                    QString longitudeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 longitudeInt32 = qint32(longitudeStr.toUInt(nullptr,16));   //状态时间，毫秒
                    longitude = longitudeInt32 * 180.0 * qPow(2,-31);
                    char WE = 'E';
                    if(longitudeInt32 > 0){
                        WE = 'E';
                    }
                    else{
                        WE= 'W';
                    }
                    QString lontStr = QString::number(longitude,'f',4);
                    qreal longitudeAbs = fabs(lontStr.toFloat());
                    double longitudeAbsDeg =  floor(longitudeAbs);
                    QString longitudeDegStr = QString("%1").arg(longitudeAbsDeg);
                    double longitudeAbsMin  =  (longitudeAbs - longitudeAbsDeg)* 60.0;
                    QString longitudeMinStr = QString::number(longitudeAbsMin,'f',3);
                    longitudeStrDis = WE+longitudeDegStr+"°"+longitudeMinStr+"′";
                    longitudeStrDis_D = QString::number(longitude,'f',9);


                    if(isDegree == 0)
                        ui->lineEdit_8->setText(longitudeStrDis);
                    else
                        ui->lineEdit_8->setText(WE+lontStr+"°");

                }

                /****************************************解析东速19-22字节*********************************************/
                bufferStrC1.remove(0,8);
                QString eastSpeedStrDis;
                QString eastSpeedStrDis_D;
                if(northeastSpeed == "1")
                {
                    QString eastSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 eastSpeedInt32 = qint32(eastSpeedStr.toUInt(nullptr,16));
                    eastSpeed = eastSpeedInt32 * 1000.0 * qPow(2,-31);
                    eastSpeedStrDis = QString::number(eastSpeed,'f',4)+"kn";
                    eastSpeedStrDis_D = QString::number(eastSpeed,'f',4);

                    ui->lineEdit_16->setText(eastSpeedStrDis);
                }

                /****************************************解析北速23-26字节*********************************************/
                bufferStrC1.remove(0,8);
                QString northSpeedStrDis;
                QString northSpeedStrDis_D;
                if(northeastSpeed == "1")
                {
                    QString northSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 northSpeedInt32 = qint32(northSpeedStr.toUInt(nullptr,16));
                    northSpeed = northSpeedInt32 * 1000.0 * qPow(2,-31);
                    northSpeedStrDis = QString::number(northSpeed,'f',4)+"kn";
                    northSpeedStrDis_D = QString::number(northSpeed,'f',4);

                    ui->lineEdit_15->setText(northSpeedStrDis);
                }

                /*******************************************计算合速*********************************************************/
                qreal togetherSpeed = sqrt(qPow(northSpeed,2) + qPow(eastSpeed,2));
                QString togetherSpeedStrDis = QString::number(togetherSpeed,'f',4)+"kn";

                ui->lineEdit_17->setText(togetherSpeedStrDis);

                /****************************************解析航向角27-30字节*********************************************/
                bufferStrC1.remove(0,8);
                QString headingAngleStrDis;
                QString headingAngleStrDis_D;
                if(headingVaild == "1")
                {
                    QString headingStr;
                    double headingAngleAbsDeg;
                    QString headingAngleAbsStr;
                    double headingAngleMin;
                    QString headingAngleMinStr;

                    QString headingAngleStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    quint32 headingAngleInt32 = quint32(headingAngleStr.toUInt(nullptr,16));
                    headingAngle = headingAngleInt32 * 360.00000 * qPow(2,-32);
                    //headingAngle = 214.56;

//                    if(headingAngle<=180)
//                    {
                        headingStr = QString::number(headingAngle,'f',4);
                        headingAngleAbsDeg =  floor(headingStr.toFloat());
                        headingAngleAbsStr = QString("%1").arg(headingAngleAbsDeg);
                        headingAngleMin  =  (headingAngle - headingAngleAbsDeg)* 60.0;
                        headingAngleMinStr = QString::number(headingAngleMin,'f',3);
                        headingAngleStrDis = headingAngleAbsStr+"°"+headingAngleMinStr+"′";
                        headingAngleStrDis_D = headingStr;
                    //}
//                    else
//                    {
//                        headingAngle = headingAngle - 360.0;
//                        headingStr = QString::number(headingAngle,'f',4);
//                        headingAngleAbsDeg =  floor(fabs(headingAngle));
//                        headingAngleAbsStr = QString("%1").arg(headingAngleAbsDeg);
//                        headingAngleMin  =  (fabs(headingAngle) - headingAngleAbsDeg)* 60.0;
//                        headingAngleMinStr = QString::number(headingAngleMin,'f',3);
//                        headingAngleStrDis = "-"+headingAngleAbsStr+"°"+headingAngleMinStr+"′";
//                        headingAngleStrDis_D =  QString::number(headingAngle,'f',4);
//                    }


                    if(isDegree == 0)
                        ui->lineEdit_9->setText(headingAngleStrDis);
                    else
                        ui->lineEdit_9->setText(headingStr+"°");
                }

                /****************************************解析横摇角31-34字节*********************************************/
                bufferStrC1.remove(0,8);
                QString rollAngleStrDis;
                QString rollAngleStrDis_D;
                if(verHorShakVaild == "1")
                {
                    QString rollAngleStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 rollAngleInt32 = qint32(rollAngleStr.toUInt(nullptr,16));
                    rollAngle = rollAngleInt32 * 180.0 * qPow(2,-31);
                    QString rolStr = QString::number(rollAngle,'f',4);
                    double rollAngleAbsDegTemp =fabs(rolStr.toFloat());
                    double rollAngleAbsDeg =  floor(rollAngleAbsDegTemp);
                    QString rollAngleAbsStr = QString("%1").arg(rollAngleAbsDeg);
                    double rollAngleMin  =  (rollAngleAbsDegTemp - rollAngleAbsDeg)* 60.0;
                    QString rollAngleMinStr = QString::number(rollAngleMin,'f',3);
                    rollAngleStrDis_D = rolStr;
                    if(rollAngle <0){
                        rollAngleStrDis = "-" + rollAngleAbsStr+"°"+rollAngleMinStr+"′";
                    }
                    else{
                        rollAngleStrDis = rollAngleAbsStr+"°"+rollAngleMinStr+"′";
                    }

                    if(isDegree == 0)
                        ui->lineEdit_10->setText(rollAngleStrDis);
                    else
                        ui->lineEdit_10->setText(rolStr+"°");
                }


                /****************************************解析纵摇角35-38字节*********************************************/
                bufferStrC1.remove(0,8);
                QString pitchAngleStrDis;
                QString pitchAngleStrDis_D;
                if(verHorShakVaild == "1")
                {
                    QString pitchAngleStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 pitchAngleInt32 = qint32(pitchAngleStr.toUInt(nullptr,16));
                    pitchAngle = pitchAngleInt32 * 180.0 * qPow(2,-31);
                    QString pitchStr = QString::number(pitchAngle,'f',4);
                    double pitchAngleAbsDegTemp =fabs(pitchStr.toFloat());
                    double pitchAngleAbsDeg =  floor(pitchAngleAbsDegTemp);
                    QString pitchAngleAbsStr = QString("%1").arg(pitchAngleAbsDeg);
                    double pitchAngleMin  =  (pitchAngleAbsDegTemp - pitchAngleAbsDeg)* 60.0;
                    QString pitchAngleMinStr = QString::number(pitchAngleMin,'f',3);
                    pitchAngleStrDis_D = pitchStr;
                    if(pitchAngle <0){
                        pitchAngleStrDis = "-" + pitchAngleAbsStr+"°"+pitchAngleMinStr+"′";
                    }
                    else{
                        pitchAngleStrDis = pitchAngleAbsStr+"°"+pitchAngleMinStr+"′";
                    }

                    if(isDegree == 0)
                        ui->lineEdit_11->setText(pitchAngleStrDis);
                    else
                        ui->lineEdit_11->setText(pitchStr+"°");
                }


                /****************************************解析航向角速度39-42字节*********************************************/
                bufferStrC1.remove(0,8);
                QString headingAngularSpeedStrDis;
                QString headingAngularSpeedStrDis_D;
                if(angulaVelocityVaild == "1")
                {
                    QString headingAngularSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 headingAngularSpeedInt32 = qint32(headingAngularSpeedStr.toUInt(nullptr,16));
                    headingAngularSpeed = headingAngularSpeedInt32 * 400.0 * qPow(2,-31);
                    headingAngularSpeedStrDis = QString::number(headingAngularSpeed,'f',4)+ "°/s";
                    headingAngularSpeedStrDis_D = QString::number(headingAngularSpeed,'f',4);
                    ui->lineEdit_12->setText(headingAngularSpeedStrDis);
                }

                /****************************************解析横摇角速度43-46字节*********************************************/
                bufferStrC1.remove(0,8);
                QString rollAngleSpeedStrDis;
                QString rollAngleSpeedStrDis_D;
                if(angulaVelocityVaild == "1")
                {
                    QString rollAngleSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 rollAngleSpeedInt32 = qint32(rollAngleSpeedStr.toUInt(nullptr,16));
                    rollAngleSpeed = rollAngleSpeedInt32 * 400.0 * qPow(2,-31);
                    rollAngleSpeedStrDis = QString::number(rollAngleSpeed,'f',4)+ "°/s";
                    rollAngleSpeedStrDis_D = QString::number(rollAngleSpeed,'f',4);
                    ui->lineEdit_13->setText(rollAngleSpeedStrDis);
                }

                /****************************************解析纵摇角速度37-50字节*********************************************/
                bufferStrC1.remove(0,8);
                QString pitchAngleSpeedStrDis;
                QString pitchAngleSpeedStrDis_D;
                if(angulaVelocityVaild == "1")
                {
                    QString pitchAngleSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 pitchAngleSpeedInt32 = qint32(pitchAngleSpeedStr.toUInt(nullptr,16));
                    pitchAngleSpeed = pitchAngleSpeedInt32 * 400.0 * qPow(2,-31);
                    pitchAngleSpeedStrDis = QString::number(pitchAngleSpeed,'f',4) + "°/s";
                    pitchAngleSpeedStrDis_D = QString::number(pitchAngleSpeed,'f',4);

                    ui->lineEdit_14->setText(pitchAngleSpeedStrDis);
                }

                /****************************************解析垂荡51-52字节*********************************************/
                bufferStrC1.remove(0,8);
                QString heaveStrDis;
                QString heaveStrDis_D;
                if(heaveVaild == "1")
                {
                    QString heaveStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 heaveInt16 = qint16(heaveStr.toUInt(nullptr,16));
                    heave = heaveInt16 * 100.0 * qPow(2,-15);
                    heaveStrDis = QString::number(heave,'f',2) + "m";
                    heaveStrDis_D = QString::number(heave,'f',2);

                    ui->lineEdit_18->setText(heaveStrDis);
                }

                /****************************************解析垂速53-54字节*********************************************/
                QString verticalVelocityStrDis;
                QString verticalVelocityStrDis_D;
                if(heaveVaild == "1")

                {
                    bufferStrC1.remove(0,4);
                    QString verticalVelocityStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 verticalVelocityInt16 = qint16(verticalVelocityStr.toUInt(nullptr,16));
                    verticalVelocity = verticalVelocityInt16 * 100.0 * qPow(2,-15);
                    verticalVelocityStrDis = QString::number(verticalVelocity,'f',2) + "m/s";
                    verticalVelocityStrDis_D = QString::number(verticalVelocity,'f',2);

                    ui->lineEdit_19->setText(verticalVelocityStrDis);
                }

                /****************************************解析横荡55-56字节*********************************************/
                bufferStrC1.remove(0,4);
                QString swayStrDis;
                QString swayStrDis_D;
                if(swayVaild == "1")
                {
                    QString swayStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 swayInt16 = qint16(swayStr.toUInt(nullptr,16));
                    sway = swayInt16 * 100.0 * qPow(2,-15);
                    swayStrDis = QString::number(sway,'f',2) + "m";
                    swayStrDis_D = QString::number(sway,'f',2);

                    ui->lineEdit_20->setText(swayStrDis);
                }

                /****************************************解析横速57-58字节*********************************************/
                bufferStrC1.remove(0,4);
                QString transverseVelocityStrDis;
                QString transverseVelocityStrDis_D;
                if(swayVaild == "1")
                {
                    QString transverseVelocityStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 transverseVelocityInt16 = qint16(transverseVelocityStr.toUInt(nullptr,16));
                    transverseVelocity = transverseVelocityInt16 * 100.0 * qPow(2,-15);
                    transverseVelocityStrDis = QString::number(transverseVelocity,'f',2) + "m/s";
                    transverseVelocityStrDis_D = QString::number(transverseVelocity,'f',2);

                    ui->lineEdit_21->setText(transverseVelocityStrDis);
                }

                /****************************************解析纵荡59-60字节*********************************************/
                bufferStrC1.remove(0,4);
                QString surgeStrDis;
                QString surgeStrDis_D;
                if(swayVaild == "1")
                {
                    QString surgeStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 surgeInt16 = qint16(surgeStr.toUInt(nullptr,16));
                    surge = surgeInt16 * 100.0 * qPow(2,-15);
                    surgeStrDis = QString::number(surge,'f',2) + "m";
                    surgeStrDis_D= QString::number(surge,'f',2);

                    ui->lineEdit_22->setText(surgeStrDis);
                }

                /****************************************解析纵速61-62字节*********************************************/
                bufferStrC1.remove(0,4);
                QString longitudinalVelocityStrDis;
                QString longitudinalVelocityStrDis_D;
                if(swayVaild == "1")
                {
                    QString longitudinalVelocityStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 longitudinalVelocityInt16 = qint16(longitudinalVelocityStr.toUInt(nullptr,16));
                    longitudinalVelocity = longitudinalVelocityInt16 * 100.0 * qPow(2,-15);
                    longitudinalVelocityStrDis = QString::number(longitudinalVelocity,'f',2) + "m/s";
                    longitudinalVelocityStrDis_D = QString::number(longitudinalVelocity,'f',2);

                    ui->lineEdit_23->setText(longitudinalVelocityStrDis);
                }

                /****************************************去除导航信息有效位63字节*********************************************/
                bufferStrC1.remove(0,4);

                /****************************************解析系统状态64字节*********************************************/
                bufferStrC1.remove(0,2);
                quint8 sysStateBuff = quint8(bufferStrC1.left(2).toUInt(nullptr,16));
                quint8 sysState = quint8(bufferStrC1.left(2).toUInt(nullptr,16)) & 0x3F ;
                if(sysState == 0) //准备
                {
                    ui->lineEdit_3->setText("准备") ;
                }
                else if(sysState == 1) //自对准/粗阶段0x01
                {
                    ui->lineEdit_3->setText("自对准/粗阶段");
                }
                else if(sysState == 17) //自对准/精阶段0x11
                {
                    ui->lineEdit_3->setText("自对准/精阶段");
                }
                else if(sysState == 2) //传递对准/粗阶段0x02
                {
                    ui->lineEdit_3->setText("传递对准/粗阶段");
                }
                else if(sysState == 18) //传递对准/精阶段0x12
                {
                    ui->lineEdit_3->setText("传递对准/精阶段");
                }
                else if(sysState == 3) //罗经对准/粗阶段0x3
                {
                    ui->lineEdit_3->setText("传递对准/粗阶段");
                }
                else if(sysState == 19) //罗经对准/方位阶段0x13
                {
                    ui->lineEdit_3->setText("罗经对准/方位阶段");
                }
                else if(sysState == 4) //自主导航/无阻尼0x04
                {
                    ui->lineEdit_3->setText("自主导航/无阻尼");
                }
                else if(sysState == 20) //自主导航/水平阻尼0x14
                {
                    ui->lineEdit_3->setText("自主导航/水平阻尼");
                }
                else if(sysState == 36) //自主导航/全阻尼0x24
                {
                    ui->lineEdit_3->setText("自主导航/全阻尼");
                }
                else if(sysState == 5) //罗经导航0x05
                {
                    ui->lineEdit_3->setText("罗经导航");
                }
                else if(sysState == 6) //组合导航/卫导x06
                {
                    ui->lineEdit_3->setText("组合导航/卫导");
                }
                else if(sysState == 22) //组合导航/多普勒0x16
                {
                    ui->lineEdit_3->setText("组合导航/多普勒");
                }
                else if(sysState == 38) //组合导航/天文0x26
                {
                    ui->lineEdit_3->setText("组合导航/天文");
                }
                else if(sysState == 54) //组合导航/超短基线0x36
                {
                    ui->lineEdit_3->setText("组合导航/超短基线");
                }

                else if(sysState == 7) //在舰标定/粗对准0x07
                {
                    ui->lineEdit_3->setText("在舰标定/粗对准");
                }
                else if(sysState == 23) //在舰标定/位置1 0x17
                {
                    ui->lineEdit_3->setText("在舰标定/位置1");
                }
                else if(sysState == 39) //在舰标定/位置2 0x27
                {
                    ui->lineEdit_3->setText("在舰标定/位置2");
                }
                else if(sysState == 8) //零速校准0x08
                {
                    ui->lineEdit_3->setText("零速校准");
                }
                else if(sysState == 24) //点位置校准0x18
                {
                    ui->lineEdit_3->setText("点位置校准");
                }
                else if(sysState == 40) //综合校准0x28
                {
                    ui->lineEdit_3->setText("综合校准");
                }

                /****************************************解析系统状态64字节*********************************************/
                quint8 workPlace = quint8(bufferStrC1.left(2).toUInt(nullptr,16)) & 0x40;
                if(workPlace == 0)
                {
                    ui->lineEdit->setText("码头");
                }
                else
                    ui->lineEdit->setText("海上");

                quint8 toggleMode = quint8(bufferStrC1.left(2).toUInt(nullptr,16)) & 0x80;
                if(toggleMode == 0)
                {
                    ui->lineEdit_2->setText("自动");
                }
                else
                    ui->lineEdit_2->setText("手动");

                /****************************************解析时码65-68字节，时码没有放在北京时间进行显示*********************************************/
                bufferStrC1.remove(0,2);
                quint32 timeFramesInt32;
                //if(timeFramesVaild== "1")
                {
                    QString timeFramesStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    timeFramesInt32 = quint32(timeFramesStr.toUInt(nullptr,16)); //得到距离1970-1-1号的秒数
                    QDateTime dateTime = QDateTime::fromTime_t(timeFramesInt32);            //得到UTC时间
                    //ui->lineEdit_4->setPlainText(dateTime.toString( Qt::ISODate));         //得到的UTC时间没有放到界面显示
                    //目前北京时间用的是计算机当前时间
                }

                /****************************************解析参考纬度69-72字节*********************************************/
                bufferStrC1.remove(0,8);

                QString refLatitudeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                qint32 refLatitudeInt32 = qint32(refLatitudeStr.toUInt(nullptr,16));

                qreal refLatitude = refLatitudeInt32 * 90.0 * qPow(2,-31);
                char NS = 'N';
                if(refLatitude > 0){
                    NS = 'N';
                }
                else{
                    NS= 'S';
                }
                QString refLatStr = QString::number(refLatitude,'f',4);
                qreal refLatitudeAbs = fabs(refLatStr.toFloat());
                double refLatitudeAbsDeg =  floor(refLatitudeAbs);
                QString refLatitudeDegStr = QString("%1").arg(refLatitudeAbsDeg);
                double refLatitudeAbsMin  =  (refLatitudeAbs - refLatitudeAbsDeg)* 60.0;
                QString refLatitudeMinStr = QString::number(refLatitudeAbsMin,'f',3);
                QString refLatitudeStrDis = NS+refLatitudeDegStr+"°"+refLatitudeMinStr+"′";
                QString refLatitudeStrDis_D = QString::number(refLatitude,'f',8);
                if(isDegree == 0)
                    ui->lineEdit_24->setText(refLatitudeStrDis);
                else
                    ui->lineEdit_24->setText(NS+refLatStr+"°");

                /****************************************解析参考经度73-76字节*********************************************/
                bufferStrC1.remove(0,8);

                QString reflongitudeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                qint32 reflongitudeInt32 = qint32(reflongitudeStr.toUInt(nullptr,16));   //状态时间，毫秒
                qreal reflongitude = reflongitudeInt32 * 180.0 * qPow(2,-31);
                char WE = 'E';
                if(reflongitudeInt32 > 0){
                    WE = 'E';
                }
                else{
                    WE= 'W';
                }
                QString reflongStr = QString::number(reflongitude,'f',4);
                qreal reflongitudeAbs = fabs(reflongStr.toFloat());
                double reflongitudeAbsDeg =  floor(reflongitudeAbs);
                QString reflongitudeDegStr = QString("%1").arg(reflongitudeAbsDeg);
                double reflongitudeAbsMin  =  (reflongitudeAbs - reflongitudeAbsDeg)* 60.0;
                QString reflongitudeMinStr = QString::number(reflongitudeAbsMin,'f',3);
                QString reflongitudeStrDis = WE+reflongitudeDegStr+"°"+reflongitudeMinStr+"′";
                QString reflongitudeStrDis_D = QString::number(reflongitude,'f',8);;
                if(isDegree == 0)
                    ui->lineEdit_25->setText(reflongitudeStrDis);
                else
                    ui->lineEdit_25->setText(WE+reflongStr+"°");

                /****************************************解析参考组合东速77-78字节*********************************************/
                bufferStrC1.remove(0,8);

                QString combinedEastSpeedStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 combinedEastSpeedInt16 = qint16(combinedEastSpeedStr.toUInt(nullptr,16));
                qreal combinedEastSpeed = combinedEastSpeedInt16 * 100.0 * qPow(2,-15);
                QString combinedEastSpeedStrDis = QString::number(combinedEastSpeed,'f',2)+"kn";
                QString combinedEastSpeedStrDis_D = QString::number(combinedEastSpeed,'f',2);

                ui->lineEdit_27->setText(combinedEastSpeedStrDis);

                /****************************************解析参考组合北速79-80字节*********************************************/
                bufferStrC1.remove(0,4);
                QString combinedNorthSpeedStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 combinedNorthSpeedInt16 = qint16(combinedNorthSpeedStr.toUInt(nullptr,16));
                qreal combinedNorthSpeed = combinedNorthSpeedInt16 * 100.0 * qPow(2,-15);
                QString combinedNorthSpeedStrDis = QString::number(combinedNorthSpeed,'f',2)+"kn";
                QString combinedNorthSpeedStrDis_D = QString::number(combinedNorthSpeed,'f',2);

                ui->lineEdit_28->setText(combinedNorthSpeedStrDis);


                /****************************************解析参考阻尼东速81-82字节*********************************************/
                bufferStrC1.remove(0,4);
                QString dampedEastSpeedStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 dampedEastSpeedInt16 = qint16(dampedEastSpeedStr.toUInt(nullptr,16));
                qreal dampedEastSpeed = dampedEastSpeedInt16 * 100.0 * qPow(2,-15);
                QString dampedEastSpeedStrDis = QString::number(dampedEastSpeed,'f',2)+"kn";
                QString dampedEastSpeedStrDis_D = QString::number(dampedEastSpeed,'f',2);

                ui->lineEdit_29->setText(dampedEastSpeedStrDis);


                /****************************************解析参考阻尼北速83-84字节*********************************************/
                bufferStrC1.remove(0,4);
                QString dampedNorthSpeedStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 dampedNorthSpeedInt16 = qint16(dampedNorthSpeedStr.toUInt(nullptr,16));
                qreal dampedNorthSpeed = dampedNorthSpeedInt16 * 100.0 * qPow(2,-15);
                QString dampedNorthSpeedStrDis = QString::number(dampedNorthSpeed,'f',2)+"kn";
                QString dampedNorthSpeedStrDis_D = QString::number(dampedNorthSpeed,'f',2);

                ui->lineEdit_30->setText(dampedNorthSpeedStrDis);

                /****************************************解析参考航向85-88字节*********************************************/
                bufferStrC1.remove(0,4);
                QString reHeadingAngleStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                quint32 reHeadingAngleInt32 = quint32(reHeadingAngleStr.toUInt(nullptr,16));
                qreal reHeadingAngle = reHeadingAngleInt32 * 360.0 * qPow(2,-32);
                QString reHeadingStr = QString::number(reHeadingAngle,'f',4);
                double reHeadingAngleAbsDeg =  floor(reHeadingStr.toFloat());
                QString reHeadingAngleAbsStr = QString("%1").arg(reHeadingAngleAbsDeg);
                double reHeadingAngleMin  =  (reHeadingAngle - reHeadingAngleAbsDeg)* 60.0;
                QString reHeadingAngleMinStr = QString::number(reHeadingAngleMin,'f',3);
                QString reHeadingAngleStrDis = reHeadingAngleAbsStr+"°"+reHeadingAngleMinStr+"′";
                QString reHeadingAngleStrDis_D = reHeadingStr;
                if(isDegree == 0)
                    ui->lineEdit_26->setText(reHeadingAngleStrDis);
                else
                    ui->lineEdit_26->setText(reHeadingStr+"°");

                /****************************************解析参考信息有效位89-90**********************************************/
                bufferStrC1.remove(0,8);
                QString RefLatiLongiStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 RefLatiLongiBuff = qint16(RefLatiLongiStr.toUInt(nullptr,16));

                qint16 RefLatiLongi = qint16(RefLatiLongiStr.toUInt(nullptr,16)) &0x000F;
                if(RefLatiLongi == 0)
                {
                    ui->lineEdit_31->setText("装订位置");
//                    ui->lineEdit_24->setStyleSheet("color: rgb(0, 0, 0);");
//                    ui->lineEdit_25->setStyleSheet("color: rgb(0, 0, 0);");
//                    ui->lineEdit_48->setStyleSheet("color: rgb(0, 0, 0);");

                }
                else if(RefLatiLongi == 1)
                {
                    ui->lineEdit_31->setText("GPS位置");
//                    ui->lineEdit_24->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_25->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_48->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefLatiLongi == 2)
                {
                    ui->lineEdit_31->setText("主惯导位置");
//                    ui->lineEdit_24->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_25->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_48->setStyleSheet("color: rgb(0, 0, 255);");

                }
                qint16 RefComspeed = (qint16(RefLatiLongiStr.toUInt(nullptr,16)) &0x00F0)>>4;
                if(RefComspeed == 0)
                {
                    ui->lineEdit_32->setText("装订速度");
//                    ui->lineEdit_28->setStyleSheet("color: rgb(0, 0, 0);");
//                    ui->lineEdit_27->setStyleSheet("color: rgb(0, 0, 0);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 0);");
                    }
                else if(RefComspeed == 1)
                {
                    ui->lineEdit_32->setText("GPS速度");
//                    ui->lineEdit_27->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_28->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefComspeed == 2)
                {
                    ui->lineEdit_32->setText("电磁速度");
//                    ui->lineEdit_27->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_28->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefComspeed == 3)
                {
                    ui->lineEdit_32->setText("多普勒对水速度");
//                    ui->lineEdit_27->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_28->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefComspeed == 4)
                {
                    ui->lineEdit_32->setText("多普勒对底速度");
//                    ui->lineEdit_27->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_28->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefComspeed == 5)
                {
                    ui->lineEdit_32->setText("主惯导速度");
//                    ui->lineEdit_27->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_28->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                qint16 RefDamSpeed = (qint16(RefLatiLongiStr.toUInt(nullptr,16)) &0x0F00)>>8;
                if(RefDamSpeed == 0)
                {
                    ui->lineEdit_33->setText("装订速度");
//                    ui->lineEdit_29->setStyleSheet("color: rgb(0, 0, 0);");
//                    ui->lineEdit_30->setStyleSheet("color: rgb(0, 0, 0);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 0);");

                }
                else if(RefDamSpeed == 1)
                {
                    ui->lineEdit_33->setText("GPS速度");
//                    ui->lineEdit_29->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_30->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefDamSpeed == 2)
                {
                    ui->lineEdit_33->setText("电磁速度");
//                    ui->lineEdit_29->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_30->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefDamSpeed == 3)
                {
                    ui->lineEdit_33->setText("多普勒对水速度");
//                    ui->lineEdit_29->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_30->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefDamSpeed == 4)
                {
                    ui->lineEdit_33->setText("多普勒对底速度");
//                    ui->lineEdit_29->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_30->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else if(RefDamSpeed == 5)
                {
                    ui->lineEdit_33->setText("主惯导速度");
//                    ui->lineEdit_29->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_30->setStyleSheet("color: rgb(0, 0, 255);");
//                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");

                }
                qint16 Referencehead = (qint16(RefLatiLongiStr.toUInt(nullptr,16)) &0xF000)>>12;
                if(Referencehead == 0)
                {
                    ui->lineEdit_34->setText("装订航向");
//                    ui->lineEdit_26->setStyleSheet("color: rgb(0, 0, 0);");

                     }
                else if(Referencehead == 1)
                {
                    ui->lineEdit_34->setText("GPS航迹向");
//                    ui->lineEdit_26->setStyleSheet("color: rgb(0, 0, 255);");
                    }
                else if(Referencehead == 2)
                {
                    ui->lineEdit_34->setText("主惯导航向");
//                    ui->lineEdit_26->setStyleSheet("color: rgb(0, 0, 255);");
                    }


                /******************************************计算误差*******************************************/
                //东速误差
                eastSpeedError = eastSpeed - combinedEastSpeed;
                //北速误差
                northSpeedError = northSpeed - combinedNorthSpeed;
                //合速度误差
                togetherSpeedError = sqrt(qPow(eastSpeedError,2) + qPow(northSpeedError,2));
                //纬度误差
                latitudeError = (latitude - refLatitude)*60.0;

                //经度误差
                longitudeError = (longitude - reflongitude) * 60.0*qCos(latitude*3.1415926/180.0);
                //位置误差
                positionError = sqrt(qPow(latitudeError,2) + qPow(longitudeError,2));

                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC1(&C1fileSave);

                QString dataStr1 = dataInvaildRecordStr + ","+"1"+","+QString::number(sysTimeMs,10)+","+QString::number(stateMs,10)+","+latitudeStrDis_D+","+longitudeStrDis_D+","+eastSpeedStrDis_D+","+northSpeedStrDis_D+","+headingAngleStrDis_D+","+rollAngleStrDis_D+","+pitchAngleStrDis_D+","+headingAngularSpeedStrDis_D+","+rollAngleSpeedStrDis_D+","+pitchAngleSpeedStrDis_D+","+heaveStrDis_D+","+verticalVelocityStrDis_D+","+swayStrDis_D+","+transverseVelocityStrDis_D+","+surgeStrDis_D+","+longitudinalVelocityStrDis_D+","+QString::number(NavVaildBuff,10)+","+QString::number(sysStateBuff,10)+","+QString::number(timeFramesInt32,10)+","+refLatitudeStrDis_D+","+reflongitudeStrDis_D+","+combinedEastSpeedStrDis_D+","+combinedNorthSpeedStrDis_D+","+dampedEastSpeedStrDis_D+","+dampedNorthSpeedStrDis_D+","+reHeadingAngleStrDis_D+","+QString::number(RefLatiLongiBuff,10)+"\n";
                // QString dataStr1 = "\n"+ dataInvaildRecordStr + ","+"C1"+","+sysTimeStr+","+stateTimeStr+","+latitudeStrDis_D+","+longitudeStrDis_D+","+eastSpeedStrDis_D+","+northSpeedStrDis_D+","+headingAngleStrDis_D+","+rollAngleStrDis_D+","+pitchAngleStrDis_D+","+headingAngularSpeedStrDis_D+","+rollAngleSpeedStrDis_D+","+pitchAngleSpeedStrDis_D+","+heaveStrDis_D+","+verticalVelocityStrDis_D+","+swayStrDis_D+","+transverseVelocityStrDis_D+","+surgeStrDis_D+","+longitudinalVelocityStrDis_D+","+timeFramesVaild+","+longitudeLatitudeVaild+","+northeastSpeed+","+headingVaild+","+verHorShakVaild+","+angulaVelocityVaild+","+heaveVaild+","+swayVaild+","+ui->lineEdit_3->text()+","+ui->lineEdit->text()+","+ui->lineEdit_2->text()+","+timeFramesInt32+","+refLatitudeStrDis_D+","+reflongitudeStrDis_D+","+combinedEastSpeedStrDis_D+","+combinedNorthSpeedStrDis_D+","+dampedEastSpeedStrDis_D+","+dampedNorthSpeedStrDis_D+","+reHeadingAngleStrDis_D+","+ui->lineEdit_31->text()+","+ui->lineEdit_32->text()+","+ui->lineEdit_33->text()+","+ui->lineEdit_34->text();
                dataOutC1<<dataStr1.toUtf8();

                ui->lineEdit_7->setStyleSheet( " color:blue; " );
                ui->lineEdit_8->setStyleSheet( " color:blue; " );
                ui->lineEdit_9->setStyleSheet( " color:blue; " );
                ui->lineEdit_10->setStyleSheet( " color:blue; " );
                ui->lineEdit_11->setStyleSheet( " color:blue; " );
                ui->lineEdit_12->setStyleSheet( " color:blue; " );
                ui->lineEdit_13->setStyleSheet( " color:blue; " );
                ui->lineEdit_14->setStyleSheet( " color:blue; " );
                ui->lineEdit_15->setStyleSheet( " color:blue; " );
                ui->lineEdit_16->setStyleSheet( " color:blue; " );
                ui->lineEdit_17->setStyleSheet( " color:blue; " );
                ui->lineEdit_18->setStyleSheet( " color:blue; " );
                ui->lineEdit_19->setStyleSheet( " color:blue; " );
                ui->lineEdit_20->setStyleSheet( " color:blue; " );
                ui->lineEdit_21->setStyleSheet( " color:blue; " );
                ui->lineEdit_22->setStyleSheet( " color:blue; " );
                ui->lineEdit_23->setStyleSheet( " color:blue; " );
                C1getCurveData();

                noVaildMessage = 0;
                restartTime= 0;
                hasDataVaildC1 = 0;
            }
        }

        /**********************************************解析工况信息C2******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == '2')
        {
            QString bufferStrC2 = bufferStr;

            if(bufferStrC2.size() != 88)
            {
                continue;
            }
            int C2checkNumInt = 0;
            QString C2checkNumStr;
            for(int i= 4;i<86;i=i+2)
            {
                C2checkNumInt = C2checkNumInt + bufferStrC2.mid(i,2).toInt(nullptr,16);
            }
            C2checkNumStr = QString::number(C2checkNumInt,16).right(2);
            if(C2checkNumStr == bufferStrC2.mid(86,2))
            {

                bufferStrC2.remove(0,6);

                QString SysTimeStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);

                quint32 sysTimeMs = quint32(SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒

                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                int dayInt = houInt * 24;

                long day = 0;
                long hour = (sysTimeMs - day * dayInt) / houInt;
                long minute = (sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                //QString dayQStr  = QString::number(day,10);
                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;
                /********************************************解析信息传输标志**************************************/
                bufferStrC2.remove(0,8);
                QString informationTransStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);

                quint32 informationTransUnit32 = quint32(informationTransStr.toUInt(nullptr,16));

                QString C2bookPosetion = QString::number((informationTransUnit32) >> (1-1)&1);           //收到装订位置有效     Bit0
                QString C2GPSPosetion = QString::number((informationTransUnit32) >> (2-1)&1);    //收到GPS位置有效   Bit1
                QString C2bookSpeed = QString::number((informationTransUnit32) >> (3-1)&1);            //收到装订速度有效   Bit2
                QString C2GPSSpeed = QString::number((informationTransUnit32) >> (4-1)&1);              //收到GPS速度有效     Bit3
                QString C2ElecSpeed = QString::number((informationTransUnit32) >> (5-1)&1);           //收到电磁计程仪速度有效位   Bit4
                QString C2DopplerSpeed = QString::number((informationTransUnit32) >> (6-1)&1);       //收到多普勒计程仪速度有效   Bit5
                QString C2timeCode = QString::number((informationTransUnit32) >> (7-1)&1);                //收到时码     Bit6
                QString C2gyroScaleParameters = QString::number((informationTransUnit32) >> (8-1)&1);                 //收到陀螺标定参数    Bit7
                QString C2accoParameters = QString::number((informationTransUnit32) >> (9-1)&1);                 //收到加速度计标定参数    Bit8
                QString C2gyroTemp = QString::number((informationTransUnit32) >> (10-1)&1);                 //收到陀螺零偏温补系数    Bit9
                QString C2accoTemp = QString::number((informationTransUnit32) >> (11-1)&1);                 //收到加速度计零位温补系数    Bit10
                QString C2bookHand = QString::number((informationTransUnit32) >> (12-1)&1);                 //收到装订航向    Bit11
                QString C2equal0 = QString::number((informationTransUnit32) >> (13-1)&1);                 //收到等效零偏    Bit12
                QString C2driftCompen = QString::number((informationTransUnit32) >> (14-1)&1);                 //收到漂移补偿    Bit13
                QString C2retain = QString::number((informationTransUnit32) >> (15-1)&1);                 //保留    Bit14
                QString C2stateChange = QString::number((informationTransUnit32) >> (16-1)&1);                 //收到状态切换命令    Bit15
                QString C2sysAttitude0 = QString::number((informationTransUnit32) >> (17-1)&1);                 //收到系统姿态零位   Bit16
                QString C2inertialAttitude0 = QString::number((informationTransUnit32) >> (18-1)&1);                 //收到惯组和输出姿态零位    Bit17
                QString C2leverArm = QString::number((informationTransUnit32) >> (19-1)&1);                 //收到杆臂    Bit18
                QString C2disCtrReferInf = QString::number((informationTransUnit32) >> (20-1)&1);                 //收到显控参考信息    Bit19
                QString C2PPS = QString::number((informationTransUnit32) >> (21-1)&1);                 //收到1PPS信号    Bit20
                QString C2synSignal = QString::number((informationTransUnit32) >> (22-1)&1);                 //收到录取同步信号    Bit21
                QString C2mainInertialNav = QString::number((informationTransUnit32) >> (23-1)&1);                 //收到主惯导信息    Bit22
                QString C2sysCode = QString::number((informationTransUnit32) >> (24-1)&1);                 //收到系统编号    Bit23
                QString C2posetion = QString::number((informationTransUnit32) >> (25-1)&1);                 //收到在舰位置    Bit24
                QString C2IP = QString::number((informationTransUnit32) >> (26-1)&1);                 //收到IP地址    Bit25

                if(C2PPS == "1")
                {

                    ui->label_16->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                    ui->label_16->setStyleSheet("font:bold;color:Red");
                }
                /********************************************解析信息有效标志**************************************/
                bufferStrC2.remove(0,8);
                QString informationValidStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);

                quint32 informationValidUnit32 = quint32(informationValidStr.toUInt(nullptr,16));

                QString C2bookPosetionValid = QString::number((informationValidUnit32) >> (1-1)&1);           //收到装订位置有效     Bit0
                QString C2GPSPosetionValid = QString::number((informationValidUnit32) >> (2-1)&1);    //收到GPS位置有效   Bit1
                QString C2bookSpeedValid = QString::number((informationValidUnit32) >> (3-1)&1);            //收到装订速度有效   Bit2
                QString C2GPSSpeedValid = QString::number((informationValidUnit32) >> (4-1)&1);              //收到GPS速度有效     Bit3
                QString C2ElecSpeedValid = QString::number((informationValidUnit32) >> (5-1)&1);           //收到电磁计程仪速度有效位   Bit4
                QString C2DopplerXValid = QString::number((informationValidUnit32) >> (6-1)&1);      //收到多普勒计程仪速度有效   Bit5
                QString C2DopplerYValid = QString::number((informationValidUnit32) >> (7-1)&1);      //收到多普勒计程仪速度有效   Bit5
                QString C2timeCodeValid = QString::number((informationValidUnit32) >> (8-1)&1);                //收到时码有效     Bit6
                QString C2retain8 = QString::number((informationValidUnit32) >> (9-1)&1);                //收到时码有效     Bit6

                QString C2GXDriftValid = QString::number((informationValidUnit32) >> (10-1)&1);
                QString C2GYDriftValid = QString::number((informationValidUnit32) >> (11-1)&1);
                QString C2GZDriftValid = QString::number((informationValidUnit32) >> (12-1)&1);
                QString C2AX0Valid = QString::number((informationValidUnit32) >> (13-1)&1);
                QString C2AY0Valid = QString::number((informationValidUnit32) >> (14-1)&1);
                QString C2AZ0Valid = QString::number((informationValidUnit32) >> (15-1)&1);
                QString C2HorAttErrorValid = QString::number((informationValidUnit32) >> (16-1)&1);
                QString C2HeadErrorcomValid = QString::number((informationValidUnit32) >> (17-1)&1);
                QString C2SpeedErrorcomValid = QString::number((informationValidUnit32) >> (18-1)&1);
                QString C2posetionErrorcomValid = QString::number((informationValidUnit32) >> (19-1)&1);
                QString C2DirFlightValid = QString::number((informationValidUnit32) >> (20-1)&1);
                QString C2StaticValid = QString::number((informationValidUnit32) >> (21-1)&1);
                QString C2MooringValid = QString::number((informationValidUnit32) >> (22-1)&1);
                QString C2ShockValid = QString::number((informationValidUnit32) >> (23-1)&1);
                QString C2AttackValid = QString::number((informationValidUnit32) >> (24-1)&1);
                QString C2retain24 = QString::number((informationValidUnit32) >> (25-1)&1);
                QString C2retain25 = QString::number((informationValidUnit32) >> (26-1)&1);
                QString C2retain26 = QString::number((informationValidUnit32) >> (27-1)&1);
                QString C2retain27 = QString::number((informationValidUnit32) >> (28-1)&1);
                QString C2INSpositionValid = QString::number((informationValidUnit32) >> (29-1)&1);
                QString C2INSSpeedValid = QString::number((informationValidUnit32) >> (30-1)&1);
                QString C2INSAttitudeValid = QString::number((informationValidUnit32) >> (31-1)&1);
                QString C2INSArgSpeedValid = QString::number((informationValidUnit32) >> (32-1)&1);


                /*****************************************跳转到故障码进行解析**************************************/
                bufferStrC2.remove(0,8);
                QString C2errorCodeStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                quint32 errorCode = quint32(C2errorCodeStr.toUInt(nullptr,16));
                //quint8 errorCode = 0xFF;
                QString groyErrorCode = QString::number((errorCode) >> (1-1)&1);              //陀螺     Bit0
                QString accErrorCode = QString::number((errorCode) >> (2-1)&1);               //加速度计   Bit1
                QString IFErrorCode = QString::number((errorCode) >> (3-1)&1);                //IF板   Bit2
                QString AcqBoardErrorCode = QString::number((errorCode) >> (4-1)&1);          //采集板     Bit3
                QString retain1ErrorCode = QString::number((errorCode) >> (5-1)&1);           //保留   Bit4
                QString commuErrorCode= QString::number((errorCode) >> (6-1)&1);              //通信板   Bit5
                QString retain2ErrorCode = QString::number((errorCode) >> (7-1)&1);           //保留     Bit6
                QString interfaceErrorCode = QString::number((errorCode) >> (8-1)&1);         //接口板故障码    Bit7
                QString solAbnormalErrorCode = QString::number((errorCode) >> (9-1)&1);       //解算异常故障码    Bit8
                QString backPowerErrorCode = QString::number((errorCode) >> (10-1)&1);         //备用电源故障码    Bit9
                if(groyErrorCode == "1")
                {

                    ui->label_13->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_13->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                if(accErrorCode == "1")
                {

                    ui->label_20->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_20->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                if(IFErrorCode == "1")
                {

                    ui->label_14->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_14->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                if(AcqBoardErrorCode == "1")
                {

                    ui->label_19->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_19->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                if(solAbnormalErrorCode == "1")
                {

                    ui->label_21->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_21->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }

                /****************************************解析GX陀螺常值漂移19-22字节*********************************************/
                bufferStrC2.remove(0,8);
                QString GXGyroConstantDriftStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 GXGyroConstantDriftInt32 = qint32(GXGyroConstantDriftStr.toUInt(nullptr,16));
                qreal GXGyroConstantDrift = GXGyroConstantDriftInt32 * qPow(10,-6);
                QString GXGyroConstantDriftStrDis = QString::number(GXGyroConstantDrift,'f',4);

                /****************************************解析GY陀螺常值漂移23-26字节*********************************************/
                bufferStrC2.remove(0,8);
                QString GYGyroConstantDriftStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 GYGyroConstantDriftInt32 = qint32(GYGyroConstantDriftStr.toUInt(nullptr,16));
                qreal GYGyroConstantDrift = GYGyroConstantDriftInt32 * qPow(10,-6);
                QString GYGyroConstantDriftStrDis = QString::number(GYGyroConstantDrift,'f',4);

                /****************************************解析GZ陀螺常值漂移27-30字节*********************************************/
                bufferStrC2.remove(0,8);
                QString GZGyroConstantDriftStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 GZGyroConstantDriftInt32 = qint32(GZGyroConstantDriftStr.toUInt(nullptr,16));
                qreal GZGyroConstantDrift = GZGyroConstantDriftInt32 * qPow(10,-6);
                QString GZGyroConstantDriftStrDis = QString::number(GZGyroConstantDrift,'f',4);

                /****************************************解析AX加速度计零偏31-34字节*********************************************/
                bufferStrC2.remove(0,8);
                QString AXAccelerometerBiasStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 AXAccelerometerBiasInt32 = qint32(AXAccelerometerBiasStr.toUInt(nullptr,16));
                qreal AXAccelerometerBias = AXAccelerometerBiasInt32 * qPow(10,-6);
                QString AXAccelerometerBiasStrDis = QString::number(AXAccelerometerBias,'f',4);

                /****************************************解析AY加速度计零偏35-38字节*********************************************/
                bufferStrC2.remove(0,8);
                QString  AYAccelerometerBiasStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32  AYAccelerometerBiasInt32 = qint32(AYAccelerometerBiasStr.toUInt(nullptr,16));
                qreal  AYAccelerometerBias =  AYAccelerometerBiasInt32 * qPow(10,-6);
                QString  AYAccelerometerBiasStrDis = QString::number(AYAccelerometerBias,'f',4);

                /****************************************解析AZ加速度计零偏39-42字节*********************************************/
                bufferStrC2.remove(0,8);
                QString AZAccelerometerBiasStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 AZAccelerometerBiasInt32 = qint32(AZAccelerometerBiasStr.toUInt(nullptr,16));
                qreal AZAccelerometerBias = AZAccelerometerBiasInt32 * qPow(10,-6);
                QString AZAccelerometerBiasStrDis = QString::number(AZAccelerometerBias,'f',4);


                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC2(&C2fileSave);

              QString dataStr2 = dataInvaildRecordStr +","+"2"+","+QString::number(sysTimeMs,10)+","+QString::number(informationTransUnit32,10)+","+QString::number(informationValidUnit32,10)+","+QString::number(errorCode,10)+","+GXGyroConstantDriftStrDis+","+GYGyroConstantDriftStrDis+","+GZGyroConstantDriftStrDis+","+AXAccelerometerBiasStrDis+","+AYAccelerometerBiasStrDis+","+AZAccelerometerBiasStrDis+"\n";
                dataOutC2<<dataStr2.toUtf8();

                hasDataVaildC2 = 0;

            }
        }

        /**********************************************解析参考信息C3******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == '3')
        {
            QString bufferStrC3 = bufferStr;
            if(bufferStrC3.size() != 116)
            {
                continue;
            }
            int C3checkNumInt = 0;
            QString C3checkNumStr;
            for(int i= 4;i<114;i=i+2)
            {
                C3checkNumInt = C3checkNumInt + bufferStrC3.mid(i,2).toInt(nullptr,16);
            }
            C3checkNumStr = QString::number(C3checkNumInt,16).right(2);
            if(C3checkNumStr == bufferStrC3.mid(114,2))
            {
                /**************************************解析系统时间***************************************************/
                bufferStrC3.remove(0,6);

                QString C3SysTimeStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);

                quint32 C3sysTimeMs = quint32(C3SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒
                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                int dayInt = houInt * 24;

                long day = 0;
                long hour = (C3sysTimeMs - day * dayInt) / houInt;
                long minute = (C3sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (C3sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = C3sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;

                /**************************************解析信息收到标识***************************************************/
                bufferStrC3.remove(0,8);

                QString C3informationTransStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);

                quint32 C3informationTransUnit32 = quint32(C3informationTransStr.toUInt(nullptr,16));

                QString C3bookPosetion = QString::number((C3informationTransUnit32) >> (1-1)&1);           //收到装订位置有效     Bit0
                QString C3GPSPosetion = QString::number((C3informationTransUnit32) >> (2-1)&1);    //收到GPS位置有效   Bit1
                QString C3bookSpeed = QString::number((C3informationTransUnit32) >> (3-1)&1);            //收到装订速度有效   Bit2
                QString C3GPSSpeed = QString::number((C3informationTransUnit32) >> (4-1)&1);              //收到GPS速度有效     Bit3
                QString C3ElecSpeed = QString::number((C3informationTransUnit32) >> (5-1)&1);           //收到电磁计程仪速度有效位   Bit4
                QString C3DopplerSpeed = QString::number((C3informationTransUnit32) >> (6-1)&1);       //收到多普勒计程仪速度有效   Bit5
                QString C3timeCode = QString::number((C3informationTransUnit32) >> (7-1)&1);                //收到时码     Bit6
                QString C3PPS = QString::number((C3informationTransUnit32) >> (8-1)&1);                 //收到PPS信号    Bit7
                QString C3MainINS = QString::number((C3informationTransUnit32) >> (9-1)&1);                 //收到主惯导    Bit8
                QString C3Odometer = QString::number((C3informationTransUnit32) >> (10-1)&1);                 //收到里程计    Bit9
                QString C3BDLogBottomHeight1 = QString::number((C3informationTransUnit32) >> (11-1)&1);        //收到 BD计程仪对底高度1
                QString C3BDLogBottomHeight2 = QString::number((C3informationTransUnit32) >> (12-1)&1);        //收到 BD计程仪对底高度2
                QString C3BDDPLBottomHeight1 = QString::number((C3informationTransUnit32) >> (13-1)&1);        //收到 WD多普勒对底高度1
                QString C3BDDPLBottomHeight2 = QString::number((C3informationTransUnit32) >> (14-1)&1);        //收到 WD多普勒对底高度2
                QString C3WDDPLBottomHeight1 = QString::number((C3informationTransUnit32) >> (17-1)&1);        //收到 BD多普勒对底高度1
                QString C3WDDPLBottomHeight2 = QString::number((C3informationTransUnit32) >> (18-1)&1);        //收到 BD多普勒对底高度2
                QString C3WDLogBottomHeight1 = QString::number((C3informationTransUnit32) >> (19-1)&1);        //收到 WD多普勒对底高度1
                QString C3WDLogBottomHeight2 = QString::number((C3informationTransUnit32) >> (20-1)&1);        //收到 WD多普勒对底高度2

                /**************************************解析信息有效标识***************************************************/
                bufferStrC3.remove(0,8);

                QString bufferStrC3Vaild = QString(bufferStrC3);
                QString C3VaildCodeStr = bufferStrC3Vaild.left(8).mid(6,2)+bufferStrC3Vaild.left(8).mid(4,2)+bufferStrC3Vaild.left(8).mid(2,2)+bufferStrC3Vaild.left(8).mid(0,2);
                quint32 VaildCode = quint32(C3VaildCodeStr.toUInt(nullptr,16));
                QString bookPositionCode = QString::number((VaildCode) >> (1-1)&1);              //装订位置有效    Bit0
                QString GPSPositionCode = QString::number((VaildCode) >> (2-1)&1);               //GPS位置有效   Bit1
                QString bookSpeedCode = QString::number((VaildCode) >> (3-1)&1);                //装订速度有效   Bit2
                QString GPSSpeedCode = QString::number((VaildCode) >> (4-1)&1);          //GPS速度有效     Bit3
                QString electrSpeedCode = QString::number((VaildCode) >> (5-1)&1);           //电磁速度有效   Bit4
                QString waterCode= QString::number((VaildCode) >> (6-1)&1);              //多普勒对水有效   Bit5
                QString bottonCode = QString::number((VaildCode) >> (7-1)&1);           //多普勒对底有效     Bit6
                QString timeCode = QString::number((VaildCode) >> (8-1)&1);         //时码有效    Bit7
                QString MainINSCode = QString::number((VaildCode) >> (9-1)&1);         //主惯导有效   Bit8
                QString C3OdometerCode = QString::number((VaildCode) >> (10-1)&1);         //里程计有效   Bit9
                QString C3WDLogBottomHeightCode1 = QString::number((VaildCode) >> (11-1)&1);        //收到 WD计程仪对底高度1
                QString C3WDLogBottomHeightCode2 = QString::number((VaildCode) >> (12-1)&1);        //收到 WD计程仪对底高度2
                QString C3WDDPLBottomHeightCode1 = QString::number((VaildCode) >> (13-1)&1);        //收到  WD多普勒对底高度有效1
                QString C3WDDPLBottomHeightCode2 = QString::number((VaildCode) >> (14-1)&1);        //收到  WD多普勒对底高度有效2
                QString C3BDDPLBottomHeightCode = QString::number((VaildCode) >> (27-1)&1);        //收到 BD多普勒对底高度有效
                QString C3BDLogBottomHeightCode = QString::number((VaildCode) >> (28-1)&1);        //收到 BD计程仪对底高度

                QString C3BDLogBottomHeightVaild;

                if((C3BDLogBottomHeight1 == "1") && (C3BDLogBottomHeight2 == "1")&&(C3BDLogBottomHeightCode == "1"))
                {
                    C3BDLogBottomHeightVaild = "1";
                }
                else
                    C3BDLogBottomHeightVaild = "0";

                QString C3BDDPLBottomHeightVaild;

                if((C3BDDPLBottomHeight1 == "1") && (C3BDDPLBottomHeight2 == "1")&&(C3BDDPLBottomHeightCode == "1"))
                {
                    C3BDDPLBottomHeightVaild = "1";
                }
                else
                    C3BDDPLBottomHeightVaild = "0";

                QString C3WDLogBottomHeightVaild;

                if((C3WDLogBottomHeight1 == "1") && (C3WDLogBottomHeight2 == "1")&&(C3WDLogBottomHeightCode1 == "1")&&(C3WDLogBottomHeightCode2 == "1"))
                {
                    C3WDLogBottomHeightVaild = "1";
                }
                else
                    C3WDLogBottomHeightVaild = "0";

                QString C3WDDPLBottomHeightVaild;

                if((C3WDDPLBottomHeight1 == "1") && (C3WDDPLBottomHeight2 == "1")&&(C3WDDPLBottomHeightCode1 == "1")&&(C3WDDPLBottomHeightCode2 == "1"))
                {
                    C3WDDPLBottomHeightVaild = "1";
                }
                else
                    C3WDDPLBottomHeightVaild = "0";

                if((C3WDDPLBottomHeightVaild == "1") || (C3WDLogBottomHeightVaild == "1") || (C3BDDPLBottomHeightVaild == "1") ||  C3BDLogBottomHeightVaild == "1")
                {
                    ui->lineEdit_54->setStyleSheet("color: rgb(0, 0, 255);");
                     ui->label_55->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                    ui->lineEdit_54->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->label_55->setStyleSheet("font:bold;color:Red");
                }


                if(C3DopplerSpeed == "1" && (waterCode == "1" || bottonCode =="1"))
                {
                    ui->lineEdit_41->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_42->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_43->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_44->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_51->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_52->setStyleSheet("color: rgb(0, 0, 255);");
                }
                else
                {
                    ui->lineEdit_41->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_42->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_43->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_44->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_51->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_52->setStyleSheet("color: rgb(0, 0, 0);");
                }

                if(C3GPSPosetion == "1" && GPSPositionCode == "1")
                {
                    ui->lineEdit_35->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_36->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_46->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_24->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_25->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_48->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else
                {
                    ui->lineEdit_35->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_36->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_46->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_24->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_25->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_48->setStyleSheet("color: rgb(0, 0, 0);");
                     }
                if((C3GPSSpeed == "1" && GPSSpeedCode == "1"))
                {
                    ui->lineEdit_37->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_38->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_39->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_40->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_50->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_26->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_27->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_28->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_29->setStyleSheet("color: rgb(0, 0, 255);");
                    ui->lineEdit_30->setStyleSheet("color: rgb(0, 0, 255);");

                }
                else
                {
                    ui->lineEdit_37->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_38->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_39->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_40->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_50->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_26->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_53->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_27->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_28->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_29->setStyleSheet("color: rgb(0, 0, 0);");
                    ui->lineEdit_30->setStyleSheet("color: rgb(0, 0, 0);");

                }
                if((C3GPSPosetion == "1" || C3GPSSpeed == '1') && (GPSPositionCode == "1" || GPSSpeedCode == '1'))
                {

                    ui->label_17->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_17->setStyleSheet("font:bold;color:Red");
                }

                if((C3DopplerSpeed == "1")&&(waterCode == "1" || bottonCode == '1'))
                {

                    ui->label_27->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_27->setStyleSheet("font:bold;color:Red");
                }

//                if(C3PPS == "1")
//                {

//                    ui->label_16->setStyleSheet("font:bold;color:rgb(0,200,50)");
//                }
//                else
//                {
//                     ui->label_16->setStyleSheet("font:bold;color:Red");
//                }
                if(C3ElecSpeed == "1" && electrSpeedCode == "1")
                {

                    ui->label_25->setStyleSheet("font:bold;color:rgb(0,200,50)");
                    ui->lineEdit_49->setStyleSheet("color: rgb(0, 0, 255);");
                }
                else
                {
                     ui->label_25->setStyleSheet("font:bold;color:Red");
                     ui->lineEdit_49->setStyleSheet("color: rgb(0, 0, 0);");
                }
                if(C3MainINS == "1" && MainINSCode == "1")
                {

                    ui->label_28->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_28->setStyleSheet("font:bold;color:Red");
                }
                if(C3Odometer == "1" && C3OdometerCode == "1")
                {

                    ui->label_53->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_53->setStyleSheet("font:bold;color:Red");
                }
                /**************************************解析GPS纬度***************************************************/
                bufferStrC3.remove(0,8);
                QString C3GPSlatitudeStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);

                qint32 C3GPSlatitudeInt32 = qint32(C3GPSlatitudeStr.toUInt(nullptr,16));

                C3GPSlatitude = C3GPSlatitudeInt32 * 90.0 * qPow(2,-31);
                char NS = 'N';
                if(C3GPSlatitude >= 0){
                    NS = 'N';
                }
                else{
                    NS= 'S';
                }
                QString C3GPSlattStr = QString::number(C3GPSlatitude,'f',4);
                qreal C3GPSlatitudeAbs = fabs(C3GPSlattStr.toFloat());
                double C3GPSlatitudeAbsDeg =  floor(C3GPSlatitudeAbs);
                QString C3GPSlatitudeDegStr= QString("%1").arg(C3GPSlatitudeAbsDeg);
                QString C3GPSlatitudeMinStr;
                double C3GPSlatitudeAbsMin  =  (C3GPSlatitudeAbs - C3GPSlatitudeAbsDeg)* 60.0;

                if(C3GPSlatitudeAbsMin == 0)
                    C3GPSlatitudeMinStr = QString("0%1.000").arg(C3GPSlatitudeAbsMin);
                else
                    C3GPSlatitudeMinStr = QString("%1").arg(C3GPSlatitudeAbsMin);

                QString C3GPSlatitudeStrDis = NS+C3GPSlatitudeDegStr+"°"+C3GPSlatitudeMinStr+"′";
                QString C3GPSlatitudeStrDis_D = C3GPSlattStr;

                if(isDegree == 0)
                    ui->lineEdit_35->setText(C3GPSlatitudeStrDis);
                else
                    ui->lineEdit_35->setText(NS+C3GPSlattStr+"°");
                /**************************************解析GPS经度19-22***************************************************/
                bufferStrC3.remove(0,8);

                QString C3longitudeStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                qint32 C3longitudeInt32 = qint32(C3longitudeStr.toUInt(nullptr,16));
                C3longitude = C3longitudeInt32 * 180.0 * qPow(2,-31);
                char WE = 'E';
                if(C3longitudeInt32 >= 0){
                    WE = 'E';
                }
                else{
                    WE= 'W';
                }
                QString C3longStr = QString::number(C3longitude,'f',4);
                qreal C3longitudeAbs = fabs(C3longStr.toFloat());
                double C3longitudeAbsDeg =  floor(C3longitudeAbs);
                QString C3longitudeDegStr = QString("%1").arg(C3longitudeAbsDeg);
                double C3longitudeAbsMin  =  (C3longitudeAbs - C3longitudeAbsDeg)* 60.0;
                QString C3longitudeMinStr;
                if(C3longitudeAbsMin == 0)
                {
                    C3longitudeMinStr = QString("0%1.000").arg(C3longitudeAbsMin);
                }
                else
                    C3longitudeMinStr = QString::number(C3longitudeAbsMin,'f',3);
                QString C3longitudeStrDis = WE+C3longitudeDegStr+"°"+C3longitudeMinStr+"′";
                QString C3longitudeStrDis_D = C3longStr;

                if(isDegree == 0)
                    ui->lineEdit_36->setText(C3longitudeStrDis);
                else
                    ui->lineEdit_36->setText(WE+C3longStr+"°");

                /****************************************解析GPS合速23-24字节*********************************************/
                bufferStrC3.remove(0,8);

                QString C3togetherSpeedStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                quint16 C3togetherSpeedInt16 = quint16(C3togetherSpeedStr.toUInt(nullptr,16));
                C3togetherSpeed = C3togetherSpeedInt16 * 100.0 * qPow(2,-16);

                QString C3togetherSpeedStrtemp = QString::number(C3togetherSpeed,'f',2);
                QString C3togetherSpeedStrDis = C3togetherSpeedStrtemp+"kn";

                ui->lineEdit_38->setText(C3togetherSpeedStrDis);

                /****************************************解析航向25-28字节*********************************************/
                bufferStrC3.remove(0,4);

                QString C3headingAngleStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint32 C3headingAngleInt32 = quint32(C3headingAngleStr.toUInt(nullptr,16));
                C3headingAngle = C3headingAngleInt32 * 360.0 * qPow(2,-32);
                QString C3headingStr = QString::number(C3headingAngle,'f',4);
                double C3headingAngleAbsDeg =  floor(C3headingStr.toFloat());
                QString C3headingAngleAbsStr = QString("%1").arg(C3headingAngleAbsDeg);
                double C3headingAngleMin  =  (C3headingAngle - C3headingAngleAbsDeg)* 60.0;
                QString C3headingAngleMinStr = QString::number(C3headingAngleMin,'f',3);
                QString C3headingAngleStrDis = C3headingAngleAbsStr+"°"+C3headingAngleMinStr+"′";
                QString C3headingAngleStrDis_D = C3headingStr;

                if(isDegree ==0)
                 ui->lineEdit_37->setText(C3headingAngleStrDis);
                else
                      ui->lineEdit_37->setText(C3headingStr+"°");


                /****************************************解析C3GPS东速29-30字节*********************************************/
                bufferStrC3.remove(0,8);

                QString C3combinedEastSpeedStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3combinedEastSpeedInt16 = qint16(C3combinedEastSpeedStr.toUInt(nullptr,16));
                C3combinedEastSpeed = C3combinedEastSpeedInt16 * 100.0 * qPow(2,-15);
                QString C3combinedEastSpeedStrDis = QString::number(C3combinedEastSpeed,'f',2)+"kn";
                QString C3combinedEastSpeedStrDis_D = QString::number(C3combinedEastSpeed,'f',2);

                ui->lineEdit_40->setText(C3combinedEastSpeedStrDis);

                /****************************************解析参考组合北速79-80字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3combinedNorthSpeedStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3combinedNorthSpeedInt16 = qint16(C3combinedNorthSpeedStr.toUInt(nullptr,16));
                C3combinedNorthSpeed = C3combinedNorthSpeedInt16 * 100.0 * qPow(2,-15);
                QString C3combinedNorthSpeedStrDis = QString::number(C3combinedNorthSpeed,'f',2)+"kn";
                QString C3combinedNorthSpeedStrDis_D = QString::number(C3combinedNorthSpeed,'f',2);

                ui->lineEdit_39->setText(C3combinedNorthSpeedStrDis);

                /****************************************解析C3电磁速度33-34字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3electromagnetismSpeedStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3electromagnetismSpeedInt16 = qint16(C3electromagnetismSpeedStr.toUInt(nullptr,16));
                C3electromagnetismSpeed = C3electromagnetismSpeedInt16 * 100.0 * qPow(2,-15);
                QString C3electromagnetismSpeedStrDis = QString::number(C3electromagnetismSpeed,'f',2)+"kn";
                QString C3electromagnetismSpeedStrDis_D = QString::number(C3electromagnetismSpeed,'f',2);

                ui->lineEdit_49->setText(C3electromagnetismSpeedStrDis);

                /****************************************解析C3多普勒对水横向速度35-36字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3waterXStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3waterXInt16 = qint16(C3waterXStr.toUInt(nullptr,16));
                C3waterX = C3waterXInt16 * 100.0 * qPow(2,-15);
                QString C3waterXStrDis = QString::number(C3waterX,'f',2)+"kn";
                QString C3waterXStrDis_D = QString::number(C3waterX,'f',2);

                ui->lineEdit_41->setText(C3waterXStrDis);

                /****************************************解析C3多普勒对水纵向速度37-38字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3waterYStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3waterYInt16 = qint16(C3waterYStr.toUInt(nullptr,16));
                C3waterY = C3waterYInt16 * 100.0 * qPow(2,-15);
                QString C3waterYStrDis = QString::number(C3waterY,'f',2)+"kn";
                QString C3waterYStrDis_D = QString::number(C3waterY,'f',2);

                ui->lineEdit_42->setText(C3waterYStrDis);

                /****************************************解析C3多普勒对底横向速度39-40字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3bottomXStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3bottomXInt16 = qint16(C3bottomXStr.toUInt(nullptr,16));
                C3bottomX = C3bottomXInt16 * 100.0 * qPow(2,-15);
                QString C3bottomXStrDis = QString::number(C3bottomX,'f',2)+"kn";
                QString C3bottomXStrDis_D = QString::number(C3bottomX,'f',2);

                ui->lineEdit_43->setText(C3bottomXStrDis);

                /****************************************解析C3多普勒对底纵向速度41-42字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3bottomYStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3bottomYInt16 = qint16(C3bottomYStr.toUInt(nullptr,16));
                C3bottomY = C3bottomYInt16 * 100.0 * qPow(2,-15);
                QString C3bottomYStrDis = QString::number(C3bottomY,'f',2)+"kn";
                QString C3bottomYStrDis_D = QString::number(C3bottomY,'f',2);

                ui->lineEdit_44->setText(C3bottomYStrDis);

                /****************************************解析时码43-46字节*********************************************/
                bufferStrC3.remove(0,4);
                QString timeCodeStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint32 C3TimeCodeDay = quint32(timeCodeStr.toUInt(nullptr,16)) & 0x000000FF; //得到距离1970-1-1号的秒数
                quint32 C3TimeCodeMonth = (quint32(timeCodeStr.toUInt(nullptr,16)) & 0x0000FF00)>>8; //得到距离1970-1-1号的秒数
                quint32 C3TimeCodeYear = (quint32(timeCodeStr.toUInt(nullptr,16)) & 0xFFFF0000)>>16; //得到距离1970-1-1号的秒数
                QString C3timeCodeStr = QString::number(C3TimeCodeYear,10) + QString::number(C3TimeCodeMonth,10)+QString::number(C3TimeCodeDay,10);

                /****************************************解析时码:天秒47-50字节*********************************************/
                bufferStrC3.remove(0,8);
                QString timeCodeDaySecStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint32 timeCodeDaySecUnit32 = quint32(timeCodeDaySecStr.toUInt(nullptr,16));
                QString timeCodeDaySecDisStr = QString::number(timeCodeDaySecUnit32,10);
                quint16 timeHour = timeCodeDaySecUnit32 / 3600+8;
                quint16 timeMin = (timeCodeDaySecUnit32 - (timeHour-8) * 3600.0)/60;
                quint16 timeSec = (timeCodeDaySecUnit32 - (timeHour-8) * 3600.0-timeMin * 60.0);
                timeCodeDaySecDisStr = QString::number(timeHour,10)+QString::number(timeMin,10)+QString::number(timeSec,10);

                /****************************************解析插值时间51-52字节*********************************************/
                bufferStrC3.remove(0,8);
                QString insertValueStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint16 insertValueUnit32 = quint16(insertValueStr.toUInt(nullptr,16));
                QString insertValueDisStr = QString::number(insertValueUnit32,10);

                /****************************************解析GPS卫星数53-54字节*********************************************/
                bufferStrC3.remove(0,4);
                QString GPSNumStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint16 GPSNumUnit32 = quint16(GPSNumStr.toUInt(nullptr,16));
                QString GPSNumDisStr = QString::number(GPSNumUnit32,10);


                /****************************************解析GPS水平精度因子字节*********************************************/
                bufferStrC3.remove(0,4);
                QString HDOPStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint16 HDOPUnit32 = quint16(HDOPStr.toUInt(nullptr,16));
                QString HDOPDisStr = QString::number(HDOPUnit32,10);


                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC3(&C3fileSave);

                QString dataStr3 = dataInvaildRecordStr+","+"3"+","+QString::number(C3sysTimeMs,10)+","+QString::number(C3informationTransUnit32,10)+","+QString::number(VaildCode,10)+","+C3GPSlatitudeStrDis_D+","+C3longitudeStrDis_D+","+C3togetherSpeedStrtemp+","+C3headingAngleStrDis_D+","+C3combinedEastSpeedStrDis_D+","+C3combinedNorthSpeedStrDis_D+","+C3electromagnetismSpeedStrDis_D+","+C3waterXStrDis_D+","+C3waterYStrDis_D+","+C3bottomXStrDis_D+","+C3bottomYStrDis_D+","+C3timeCodeStr+","+timeCodeDaySecDisStr+","+insertValueDisStr+","+GPSNumDisStr+","+HDOPDisStr+"\n";
                        dataOutC3<<dataStr3.toUtf8();
                C3getCurveData();
                hasDataVaildC3 = 0;
            }

        }

        /**********************************************解析惯性信息C5******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == '5')
        {
            QString bufferStrC5 = bufferStr;
            if(bufferStrC5.size() != 284)
            {
                continue;
            }
            int C5checkNumInt = 0;
            QString C5checkNumStr;
            for(int i= 4;i<282;i=i+2)
            {
                C5checkNumInt = C5checkNumInt + bufferStrC5.mid(i,2).toInt(nullptr,16);
            }
            C5checkNumStr = QString::number(C5checkNumInt,16).right(2);
            if(C5checkNumStr == bufferStrC5.mid(282,2))
            {
                /**************************************C5解析系统时间3-6***************************************************/

                bufferStrC5.remove(0,6);

                QString C5SysTimeStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                quint32 C5sysTimeMs = quint32(C5SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒

                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                int dayInt = houInt * 24;

                long day = 0;
                long hour = (C5sysTimeMs - day * dayInt) / houInt;
                long minute = (C5sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (C5sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = C5sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;

                ui->tableWidget->clearContents();
                /**************************************C5解析X陀螺1s角增量7-10字节***************************************************/
                bufferStrC5.remove(0,8);


                QString C5XGyroAngleIncreasetr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5XGyroAngleIncreasetr.toUInt(nullptr,16));
                C5XGyroAngleIncreaseFloat = C5ValueUnion.floatValue;

                QString C5XGyroAngleIncreasetrDis = QString::number(C5XGyroAngleIncreaseFloat,'f',4);

                ui->tableWidget->setItem(0,0,new QTableWidgetItem(C5XGyroAngleIncreasetrDis));
                ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺1s角增量11-14字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YGyroAngleIncreaseStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5YGyroAngleIncreaseStr.toUInt(nullptr,16));
                C5YGyroAngleIncreaseFloat = C5ValueUnion.floatValue;

                QString C5YGyroAngleIncreasetrDis = QString::number(C5YGyroAngleIncreaseFloat,'f',4);

                ui->tableWidget->setItem(1,0,new QTableWidgetItem(C5YGyroAngleIncreasetrDis));
                ui->tableWidget->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析z陀螺1s角增量15-18字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZGyroAngleIncreaseStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5ZGyroAngleIncreaseStr.toUInt(nullptr,16));
                C5ZGyroAngleIncreaseFloat = C5ValueUnion.floatValue;

                QString C5ZGyroAngleIncreasetrDis = QString::number(C5ZGyroAngleIncreaseFloat,'f',4);

                ui->tableWidget->setItem(2,0,new QTableWidgetItem(C5ZGyroAngleIncreasetrDis));
                ui->tableWidget->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X加速度计1s速度增量19-22字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XAccelerometerSpeedIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5XAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
                C5XAccelerometerSpeedIncrementFloat = C5ValueUnion.floatValue;

                QString C5XAccelerometerSpeedIncrementtrDis = QString::number(C5XAccelerometerSpeedIncrementFloat,'f',4);

                ui->tableWidget->setItem(3,0,new QTableWidgetItem(C5XAccelerometerSpeedIncrementtrDis));
                ui->tableWidget->item(3,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析y加速度计1s速度增量23-26字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YAccelerometerSpeedIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5YAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
                C5YAccelerometerSpeedIncrementFloat = C5ValueUnion.floatValue;

                QString C5YAccelerometerSpeedIncrementtrDis = QString::number(C5YAccelerometerSpeedIncrementFloat,'f',4);

                ui->tableWidget->setItem(4,0,new QTableWidgetItem(C5YAccelerometerSpeedIncrementtrDis));
                ui->tableWidget->item(4,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z加速度计1s速度增量27-30字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZAccelerometerSpeedIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5ZAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
                C5ZAccelerometerSpeedIncrementFloat = C5ValueUnion.floatValue;

                QString C5ZAccelerometerSpeedIncrementtrDis = QString::number(C5ZAccelerometerSpeedIncrementFloat,'f',4);

                ui->tableWidget->setItem(5,0,new QTableWidgetItem(C5ZAccelerometerSpeedIncrementtrDis));
                ui->tableWidget->item(5,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析x陀螺1s补偿后角增量31-34字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroCompensatedAngleIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5XgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
                C5XgyroCompensatedAngleIncrementFloat = C5ValueUnion.floatValue;

                QString C5XgyroCompensatedAngleIncrementtrDis = QString::number(C5XgyroCompensatedAngleIncrementFloat,'f',4);

                ui->tableWidget->setItem(0,1,new QTableWidgetItem(C5XgyroCompensatedAngleIncrementtrDis));
                ui->tableWidget->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺1s补偿后角增量35-38字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroCompensatedAngleIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5YgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
                C5YgyroCompensatedAngleIncrementFloat = C5ValueUnion.floatValue;

                QString C5YgyroCompensatedAngleIncrementtrDis = QString::number(C5YgyroCompensatedAngleIncrementFloat,'f',4);

                ui->tableWidget->setItem(1,1,new QTableWidgetItem(C5YgyroCompensatedAngleIncrementtrDis));
                ui->tableWidget->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析z陀螺1s补偿后角增量39-42字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroCompensatedAngleIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5ZgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
                C5ZgyroCompensatedAngleIncrementFloat = C5ValueUnion.floatValue;

                QString C5ZgyroCompensatedAngleIncrementtrDis = QString::number(C5ZgyroCompensatedAngleIncrementFloat,'f',4);

                ui->tableWidget->setItem(2,1,new QTableWidgetItem(C5ZgyroCompensatedAngleIncrementtrDis));
                ui->tableWidget->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析x加速度计1s补偿后速度增量43-46字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XAccVelocityIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5XAccVelocityIncrementStr.toUInt(nullptr,16));
                C5XAccVelocityIncrementFloat = C5ValueUnion.floatValue;

                QString C5XAccVelocityIncrementtrDis = QString::number(C5XAccVelocityIncrementFloat,'f',4);

                ui->tableWidget->setItem(3,1,new QTableWidgetItem(C5XAccVelocityIncrementtrDis));
                ui->tableWidget->item(3,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y加速度计1s补偿后速度增量47-50字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YAccVelocityIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5YAccVelocityIncrementStr.toUInt(nullptr,16));
                C5YAccVelocityIncrementFloat = C5ValueUnion.floatValue;

                QString C5YAccVelocityIncrementtrDis = QString::number(C5YAccVelocityIncrementFloat,'f',4);

                ui->tableWidget->setItem(4,1,new QTableWidgetItem(C5YAccVelocityIncrementtrDis));
                ui->tableWidget->item(4,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z加速度计1s补偿后速度增量51-54字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZAccVelocityIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C5ZAccVelocityIncrementStr.toUInt(nullptr,16));
                C5ZAccVelocityIncrementFloat = C5ValueUnion.floatValue;

                QString C5ZAccVelocityIncrementtrDis = QString::number(C5ZAccVelocityIncrementFloat,'f',4);

                ui->tableWidget->setItem(5,1,new QTableWidgetItem(C5ZAccVelocityIncrementtrDis));
                ui->tableWidget->item(5,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


                /**************************************C5解析X陀螺差频55-58字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroDifFrequencytr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XgyroDifFrequencyInt32 = qint32(C5XgyroDifFrequencytr.toUInt(nullptr,16));
                C5XgyroDifFrequency = C5XgyroDifFrequencyInt32 * qPow(10,-3);
                QString C5XgyroDifFrequencytrDis = QString::number(C5XgyroDifFrequency,'f',4);

                ui->tableWidget->setItem(0,2,new QTableWidgetItem(C5XgyroDifFrequencytrDis));
                ui->tableWidget->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺差频59-62字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroDifFrequencystr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YgyroDifFrequencyInt32 = qint32(C5YgyroDifFrequencystr.toUInt(nullptr,16));
                C5YgyroDifFrequency = C5YgyroDifFrequencyInt32 * qPow(10,-3);
                QString C5YgyroDifFrequencytrDis = QString::number(C5YgyroDifFrequency,'f',4);

                ui->tableWidget->setItem(1,2,new QTableWidgetItem(C5YgyroDifFrequencytrDis));
                ui->tableWidget->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺差频63-66字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroDifFrequencystr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZgyroDifFrequencyInt32 = qint32(C5ZgyroDifFrequencystr.toUInt(nullptr,16));
                C5ZgyroDifFrequency = C5ZgyroDifFrequencyInt32 * qPow(10,-3);
                QString C5ZgyroDifFrequencytrDis = QString::number(C5ZgyroDifFrequency,'f',4);
                ui->tableWidget->setItem(2,2,new QTableWidgetItem(C5ZgyroDifFrequencytrDis));
                ui->tableWidget->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X加速度计差频67-70字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XaccelerometerDifFrestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XaccelerometerDifFreInt32 = qint32(C5XaccelerometerDifFrestr.toUInt(nullptr,16));
                C5XaccelerometerDifFre = C5XaccelerometerDifFreInt32 * qPow(10,-3);
                QString C5XaccelerometerDifFretrDis = QString::number(C5XaccelerometerDifFre,'f',4);

                ui->tableWidget->setItem(3,2,new QTableWidgetItem(C5XaccelerometerDifFretrDis));
                ui->tableWidget->item(3,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y加速度计差频71-74字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YaccelerometerDifFrestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YaccelerometerDifFreInt32 = qint32(C5YaccelerometerDifFrestr.toUInt(nullptr,16));
                C5YaccelerometerDifFre = C5YaccelerometerDifFreInt32 * qPow(10,-3);
                QString C5YaccelerometerDifFretrDis = QString::number(C5YaccelerometerDifFre,'f',4);

                ui->tableWidget->setItem(4,2,new QTableWidgetItem(C5YaccelerometerDifFretrDis));
                ui->tableWidget->item(4,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z加速度计差频75-78字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZaccelerometerDifFrestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZaccelerometerDifFreInt32 = qint32(C5ZaccelerometerDifFrestr.toUInt(nullptr,16));
                C5ZaccelerometerDifFre = C5ZaccelerometerDifFreInt32 * qPow(10,-3);
                QString C5ZaccelerometerDifFretrDis = QString::number(C5ZaccelerometerDifFre,'f',4);

                ui->tableWidget->setItem(5,2,new QTableWidgetItem(C5ZaccelerometerDifFretrDis));
                ui->tableWidget->item(5,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X陀螺抖幅79-82字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroAmplitudeJitterstr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XgyroAmplitudeJitterInt32 = qint32(C5XgyroAmplitudeJitterstr.toUInt(nullptr,16));
                C5XgyroAmplitudeJitter = C5XgyroAmplitudeJitterInt32;
                QString C5XgyroAmplitudeJittertrDis = QString::number(C5XgyroAmplitudeJitter,'f',0);

                ui->tableWidget->setItem(0,5,new QTableWidgetItem(C5XgyroAmplitudeJittertrDis));
                ui->tableWidget->item(0,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺抖幅83-86字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroAmplitudeJitterstr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YgyroAmplitudeJitterInt32 = qint32(C5YgyroAmplitudeJitterstr.toUInt(nullptr,16));
                C5YgyroAmplitudeJitter = C5YgyroAmplitudeJitterInt32;
                QString C5YgyroAmplitudeJittertrDis = QString::number(C5YgyroAmplitudeJitter,'f',0);

                ui->tableWidget->setItem(1,5,new QTableWidgetItem(C5YgyroAmplitudeJittertrDis));
                ui->tableWidget->item(1,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺抖幅87-90字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroAmplitudeJitterstr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZgyroAmplitudeJitterInt32 = qint32(C5ZgyroAmplitudeJitterstr.toUInt(nullptr,16));
                C5ZgyroAmplitudeJitter = C5ZgyroAmplitudeJitterInt32;
                QString C5ZgyroAmplitudeJittertrDis = QString::number(C5ZgyroAmplitudeJitter,'f',0);

                ui->tableWidget->setItem(2,5,new QTableWidgetItem(C5ZgyroAmplitudeJittertrDis));
                ui->tableWidget->item(2,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X陀螺抖频91-92字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroAmplitudeFrestr = bufferStrC5.left(4).mid(2,2)+bufferStrC5.left(4).mid(0,2);
                quint16 C5XgyroAmplitudeFreInt32 = quint16(C5XgyroAmplitudeFrestr.toUInt(nullptr,16));
                C5XgyroAmpl1itudeFre = C5XgyroAmplitudeFreInt32;
                QString C5XgyroAmplitudeFretrDis = QString::number(C5XgyroAmpl1itudeFre,'f',0);

                ui->tableWidget->setItem(0,6,new QTableWidgetItem(C5XgyroAmplitudeFretrDis));
                ui->tableWidget->item(0,6)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺抖频93-94字节***************************************************/
                bufferStrC5.remove(0,4);
                QString C5YgyroAmplitudeFrestr = bufferStrC5.left(4).mid(2,2)+bufferStrC5.left(4).mid(0,2);
                quint16 C5YgyroAmplitudeFreInt32 = quint16(C5YgyroAmplitudeFrestr.toUInt(nullptr,16));
                C5YgyroAmpl1itudeFre = C5YgyroAmplitudeFreInt32;
                QString C5YgyroAmplitudeFretrDis = QString::number(C5YgyroAmpl1itudeFre,'f',0);

                ui->tableWidget->setItem(1,6,new QTableWidgetItem(C5YgyroAmplitudeFretrDis));
                ui->tableWidget->item(1,6)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺抖频95-96字节***************************************************/
                bufferStrC5.remove(0,4);
                QString C5ZgyroAmplitudeFrestr = bufferStrC5.left(4).mid(2,2)+bufferStrC5.left(4).mid(0,2);
                quint16 C5ZgyroAmplitudeFreInt32 = quint16(C5ZgyroAmplitudeFrestr.toUInt(nullptr,16));
                C5ZgyroAmpl1itudeFre = C5ZgyroAmplitudeFreInt32;
                QString C5ZgyroAmplitudeFretrDis = QString::number(C5ZgyroAmpl1itudeFre,'f',0);

                ui->tableWidget->setItem(2,6,new QTableWidgetItem(C5ZgyroAmplitudeFretrDis));
                ui->tableWidget->item(2,6)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X陀螺温度1，97-100字节***************************************************/
                bufferStrC5.remove(0,4);
                QString C5XgyroTemp1str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XgyroTemp1Int32 = qint32(C5XgyroTemp1str.toUInt(nullptr,16));
                C5XgyroTemp1 = C5XgyroTemp1Int32 * qPow(10,-4);
                QString C5XgyroTemp1trDis = QString::number(C5XgyroTemp1,'f',4);

                ui->tableWidget->setItem(0,3,new QTableWidgetItem(C5XgyroTemp1trDis));
                ui->tableWidget->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X陀螺温度2，101-104字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroTemp2str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XgyroTemp2Int32 = qint32(C5XgyroTemp2str.toUInt(nullptr,16));
                C5XgyroTemp2 = C5XgyroTemp2Int32 * qPow(10,-4);
                QString C5XgyroTemp2trDis = QString::number(C5XgyroTemp2,'f',4);

                ui->tableWidget->setItem(0,4,new QTableWidgetItem(C5XgyroTemp2trDis));
                ui->tableWidget->item(0,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺温度1，105-108字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroTemp1str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YgyroTemp1Int32 = qint32(C5YgyroTemp1str.toUInt(nullptr,16));
                C5YgyroTemp1 = C5YgyroTemp1Int32 * qPow(10,-4);
                QString C5YgyroTemp1trDis = QString::number(C5YgyroTemp1,'f',4);

                ui->tableWidget->setItem(1,3,new QTableWidgetItem(C5YgyroTemp1trDis));
                ui->tableWidget->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺温度2，109-112字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroTemp2str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YgyroTemp2Int32 = qint32(C5YgyroTemp2str.toUInt(nullptr,16));
                C5YgyroTemp2 = C5YgyroTemp2Int32 * qPow(10,-4);
                QString C5YgyroTemp2trDis = QString::number(C5YgyroTemp2,'f',4);

                ui->tableWidget->setItem(1,4,new QTableWidgetItem(C5YgyroTemp2trDis));
                ui->tableWidget->item(1,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺温度1，113-116字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroTemp1str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZgyroTemp1Int32 = qint32(C5ZgyroTemp1str.toUInt(nullptr,16));
                C5ZgyroTemp1 = C5ZgyroTemp1Int32 * qPow(10,-4);
                QString C5ZgyroTemp1trDis = QString::number(C5ZgyroTemp1,'f',4);

                ui->tableWidget->setItem(2,3,new QTableWidgetItem(C5ZgyroTemp1trDis));
                ui->tableWidget->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺温度2，117-120字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroTemp2str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZgyroTemp2Int32 = qint32(C5ZgyroTemp2str.toUInt(nullptr,16));
                C5ZgyroTemp2 = C5ZgyroTemp2Int32 * qPow(10,-4);
                QString C5ZgyroTemp2trDis = QString::number(C5ZgyroTemp2,'f',4);

                ui->tableWidget->setItem(2,4,new QTableWidgetItem(C5ZgyroTemp2trDis));
                ui->tableWidget->item(2,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析IF板温度，121-124字节--没有在界面显示***************************************************/
                bufferStrC5.remove(0,8);
                QString C5IFtemperturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5IFtempertureInt32 = qint32(C5IFtemperturestr.toUInt(nullptr,16));
                qreal C5IFtemperture = C5IFtempertureInt32 * qPow(10,-4);
                QString C5IFtemperturetrDis = QString::number(C5IFtemperture,'f',4);

                /**************************************C5解析X加速度计温度，125-128字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XAccelerometerTemperturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XAccelerometerTempertureInt32 = qint32(C5XAccelerometerTemperturestr.toUInt(nullptr,16));
                C5XAccelerometerTemperture = C5XAccelerometerTempertureInt32 * qPow(10,-4);
                QString C5XAccelerometerTemperturetrDis = QString::number(C5XAccelerometerTemperture,'f',4);

                ui->tableWidget->setItem(3,3,new QTableWidgetItem(C5XAccelerometerTemperturetrDis));
                ui->tableWidget->item(3,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y加速度计温度，129-132字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YAccelerometerTemperturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YAccelerometerTempertureInt32 = qint32(C5YAccelerometerTemperturestr.toUInt(nullptr,16));
                C5YAccelerometerTemperture = C5YAccelerometerTempertureInt32 * qPow(10,-4);
                QString C5YAccelerometerTemperturetrDis = QString::number(C5YAccelerometerTemperture,'f',4);

                ui->tableWidget->setItem(4,3,new QTableWidgetItem(C5YAccelerometerTemperturetrDis));
                ui->tableWidget->item(4,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z加速度计温度，133-136字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZAccelerometerTemperturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZAccelerometerTempertureInt32 = qint32(C5ZAccelerometerTemperturestr.toUInt(nullptr,16));
                C5ZAccelerometerTemperture = C5ZAccelerometerTempertureInt32 * qPow(10,-4);
                QString C5ZAccelerometerTemperturetrDis = QString::number(C5ZAccelerometerTemperture,'f',4);

                ui->tableWidget->setItem(5,3,new QTableWidgetItem(C5ZAccelerometerTemperturetrDis));
                ui->tableWidget->item(5,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5采集表温度137-140字节，暂时没显示在界面***************************************************/
                bufferStrC5.remove(0,8);
                QString C5AcquisitionMeterTemperaturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5AcquisitionMeterTemperatureInt32 = qint32(C5AcquisitionMeterTemperaturestr.toUInt(nullptr,16));
                qreal C5AcquisitionMeterTemperature = C5AcquisitionMeterTemperatureInt32 * qPow(10,-4);
                QString C5AcquisitionMeterTemperaturetrDis = QString::number(C5AcquisitionMeterTemperature,'f',4);

                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC5(&C5fileSave);

                QString dataStr5 = dataInvaildRecordStr+","+"5"+","+QString::number(C5sysTimeMs,10)+","+C5XGyroAngleIncreasetrDis+","+C5YGyroAngleIncreasetrDis+","+C5ZGyroAngleIncreasetrDis+","+C5XAccelerometerSpeedIncrementtrDis+","+C5YAccelerometerSpeedIncrementtrDis+","+C5ZAccelerometerSpeedIncrementtrDis+","+C5XgyroCompensatedAngleIncrementtrDis+","+C5YgyroCompensatedAngleIncrementtrDis+","+C5ZgyroCompensatedAngleIncrementtrDis+","+C5XAccVelocityIncrementtrDis+","+C5YAccVelocityIncrementtrDis+","+C5ZAccVelocityIncrementtrDis+","+C5XgyroDifFrequencytrDis+","+C5YgyroDifFrequencytrDis+","+C5ZgyroDifFrequencytrDis+","+C5XaccelerometerDifFretrDis+","+C5YaccelerometerDifFretrDis+","+C5ZaccelerometerDifFretrDis+","+C5XgyroAmplitudeJittertrDis+","+C5YgyroAmplitudeJittertrDis+","+C5ZgyroAmplitudeJittertrDis+","+C5XgyroAmplitudeFretrDis+","+C5YgyroAmplitudeFretrDis+","+C5ZgyroAmplitudeFretrDis+","+C5XgyroTemp1trDis+","+C5XgyroTemp2trDis+","+C5YgyroTemp1trDis+","+C5YgyroTemp2trDis+","+C5ZgyroTemp1trDis+","+C5ZgyroTemp2trDis+","+C5IFtemperturetrDis+","+C5XAccelerometerTemperturetrDis+","+C5YAccelerometerTemperturetrDis+","+C5ZAccelerometerTemperturetrDis+","+C5AcquisitionMeterTemperaturetrDis+"\n";
                dataOutC5<<dataStr5.toUtf8();
                C5getCurveData();

            }

        }

        /**********************************************解算信息数据格式C6******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == '6')
        {
            QString bufferStrC6 = bufferStr;
            if(bufferStrC6.size() != 136)
            {
                continue;
            }
            int C6checkNumInt = 0;
            QString C6checkNumStr;
            for(int i= 4;i<134;i=i+2)
            {
                C6checkNumInt = C6checkNumInt + bufferStrC6.mid(i,2).toInt(nullptr,16);
            }
            C6checkNumStr = QString::number(C6checkNumInt,16).right(2);
            if(C6checkNumStr == bufferStrC6.mid(134,2))
            {
                ui->tableWidget_3->clearContents();
                /**************************************C6无阻尼横摇角7-10字节***************************************************/
                bufferStrC6.remove(0,14);
                QString C6UndampedRollAngletr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6UndampedRollAngletr.toUInt(nullptr,16));
                C6UndampedRollAngleFloat = C5ValueUnion.floatValue;

                QString C6UndampedRollAngletrDis = QString::number(C6UndampedRollAngleFloat,'f',4);

                ui->tableWidget_3->setItem(0,0,new QTableWidgetItem(C6UndampedRollAngletrDis));
                ui->tableWidget_3->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼纵摇角11-14字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedPitchAngletr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6UndampedPitchAngletr.toUInt(nullptr,16));
                C6UndampedPitchAngleFloat = C5ValueUnion.floatValue;

                QString C6UndampedPitchAngletrDis = QString::number(C6UndampedPitchAngleFloat,'f',4);

                ui->tableWidget_3->setItem(1,0,new QTableWidgetItem(C6UndampedPitchAngletrDis));
                ui->tableWidget_3->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼航向角15-18字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedHeadingAngulartr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6UndampedHeadingAngulartr.toUInt(nullptr,16));
                C6UndampedHeadingAngularFloat = C5ValueUnion.floatValue;

                QString C6UndampedHeadingAngulartrDis = QString::number(C6UndampedHeadingAngularFloat,'f',4);

                ui->tableWidget_3->setItem(2,0,new QTableWidgetItem(C6UndampedHeadingAngulartrDis));
                ui->tableWidget_3->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼北速19-22字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedNorthSpeedtr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6UndampedNorthSpeedtr.toUInt(nullptr,16));
                C6UndampedNorthSpeedFloat = C5ValueUnion.floatValue;


                QString C6UndampedNorthSpeedtrDis = QString::number(C6UndampedNorthSpeedFloat,'f',4);

                ui->tableWidget_3->setItem(4,0,new QTableWidgetItem(C6UndampedNorthSpeedtrDis));
                ui->tableWidget_3->item(4,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼东速23-26字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedEastSpeedtr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6UndampedEastSpeedtr.toUInt(nullptr,16));
                C6UndampedEastSpeedFloat = C5ValueUnion.floatValue;

                QString C6UndampedEastSpeedtrDis = QString::number(C6UndampedEastSpeedFloat,'f',4);

                ui->tableWidget_3->setItem(3,0,new QTableWidgetItem(C6UndampedEastSpeedtrDis));
                ui->tableWidget_3->item(3,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼垂速27-30字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6VerticalVelocitytr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6VerticalVelocitytr.toUInt(nullptr,16));
                C6VerticalVelocityFloat = C5ValueUnion.floatValue;

                QString C6VerticalVelocitytrDis = QString::number(C6VerticalVelocityFloat,'f',4);

                ui->tableWidget_3->setItem(5,0,new QTableWidgetItem(C6VerticalVelocitytrDis));
                ui->tableWidget_3->item(5,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼纬度31-34字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedLatStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6UndampedLatStr.toUInt(nullptr,16));
                C6UndampedLatFloat = C5ValueUnion.floatValue;
                QString C6UndampedLattrDis = QString::number(C6UndampedLatFloat,'f',4);

                ui->tableWidget_3->setItem(6,0,new QTableWidgetItem(C6UndampedLattrDis));
                ui->tableWidget_3->item(6,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼经度35-38字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedLongStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
                C5ValueUnion.qint32Value = qint32(C6UndampedLongStr.toUInt(nullptr,16));
                C6UndampedLongFloat = C5ValueUnion.floatValue;

                QString C6UndampedLongtrDis = QString::number(C6UndampedLongFloat,'f',4);

                ui->tableWidget_3->setItem(7,0,new QTableWidgetItem(C6UndampedLongtrDis));
                ui->tableWidget_3->item(7,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼高度39-42字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedHeightStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6UndampedHeightStr.toUInt(nullptr,16));
                C6UndampedHeightFloat = C5ValueUnion.floatValue;

                QString C6UndampedHeighttrDis = QString::number(C6UndampedHeightFloat,'f',4);

                ui->tableWidget_3->setItem(8,0,new QTableWidgetItem(C6UndampedHeighttrDis));
                ui->tableWidget_3->item(8,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6X陀螺零偏43-46字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6XGroyStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6XGroyStr.toUInt(nullptr,16));
                C6XGroyFloat = C5ValueUnion.floatValue;

                QString C6XGroyStrDis = QString::number(C6XGroyFloat,'f',4);

                ui->tableWidget_3->setItem(9,0,new QTableWidgetItem(C6XGroyStrDis));
                ui->tableWidget_3->item(9,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6Y陀螺零偏47-50字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6YGroyStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6YGroyStr.toUInt(nullptr,16));
                C6YGroyFloat = C5ValueUnion.floatValue;

                QString C6YGroyStrDis = QString::number(C6YGroyFloat,'f',4);

                ui->tableWidget_3->setItem(10,0,new QTableWidgetItem(C6YGroyStrDis));
                ui->tableWidget_3->item(10,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6Z陀螺零偏51-54字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6ZGroyStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6ZGroyStr.toUInt(nullptr,16));
                C6ZGroyFloat = C5ValueUnion.floatValue;
                QString C6ZGroyStrDis = QString::number(C6ZGroyFloat,'f',4);

                ui->tableWidget_3->setItem(11,0,new QTableWidgetItem(C6ZGroyStrDis));
                ui->tableWidget_3->item(11,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6X加速度计零位55-58字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6XAccelerometerStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6XAccelerometerStr.toUInt(nullptr,16));
                C6XAccelerometerFloat = C5ValueUnion.floatValue;

                QString C6XAccelerometerStrDis = QString::number(C6XAccelerometerFloat,'f',4);

                ui->tableWidget_3->setItem(12,0,new QTableWidgetItem(C6XAccelerometerStrDis));
                ui->tableWidget_3->item(12,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6Y加速度计零位59-62字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6YAccelerometerStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6YAccelerometerStr.toUInt(nullptr,16));
                C6YAccelerometerFloat = C5ValueUnion.floatValue;

                QString C6YAccelerometerStrDis = QString::number(C6YAccelerometerFloat,'f',4);

                ui->tableWidget_3->setItem(13,0,new QTableWidgetItem(C6YAccelerometerStrDis));
                ui->tableWidget_3->item(13,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6Z加速度计零位63-66字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6ZAccelerometerStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);

                C5ValueUnion.qint32Value = qint32(C6ZAccelerometerStr.toUInt(nullptr,16));
                C6ZAccelerometerFloat = C5ValueUnion.floatValue;

                QString C6ZAccelerometerStrDis = QString::number(C6ZAccelerometerFloat,'f',4);

                ui->tableWidget_3->setItem(14,0,new QTableWidgetItem(C6ZAccelerometerStrDis));
                ui->tableWidget_3->item(14,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                C6getCurveData();

                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC6(&C6fileSave);

                //无阻尼横摇角，无阻尼纵摇角，无阻尼航向角，无阻尼北速，无阻尼东速，无阻尼垂速，无阻尼纬度，无阻尼经度，无阻尼高度，X陀螺零偏，Y陀螺零偏,Z陀螺零偏，X加表零偏，Y加表零偏,Z加表零偏，

                QString dataStr6 = dataInvaildRecordStr+","+"6"+","+C6UndampedRollAngletrDis+","+C6UndampedPitchAngletrDis+","+C6UndampedHeadingAngulartrDis+","+C6UndampedNorthSpeedtrDis+","+C6UndampedEastSpeedtrDis+","+C6VerticalVelocitytrDis+","+C6UndampedLattrDis+","+C6UndampedLongtrDis+","+C6UndampedHeighttrDis+","+C6XGroyStrDis+","+C6YGroyStrDis+","+C6ZGroyStrDis+","+C6XAccelerometerStrDis+","+C6YAccelerometerStrDis+","+C6ZAccelerometerStrDis+"\n";
                dataOutC6<<dataStr6.toUtf8();

            }

        }

        /**********************************************滤波信息数据格式C7******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == '7')
        {
            QString bufferStrC7 = bufferStr;
            if(bufferStrC7.size() != 136)
            {
                continue;
            }
        }


        /**********************************************附加信息数据格式C8******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == '8')
        {
            QString bufferStrC8 = bufferStr;
            if(bufferStrC8.size() != 112)
            {
                continue;
            }
            int C8checkNumInt = 0;
            QString C8checkNumStr;
            for(int i= 4;i<110;i=i+2)
            {
                C8checkNumInt = C8checkNumInt + bufferStrC8.mid(i,2).toInt(nullptr,16);
            }
            C8checkNumStr = QString::number(C8checkNumInt,16).right(2);
            if(C8checkNumStr == bufferStrC8.mid(110,2))
            {
                /**************************************解析系统时间***************************************************/
                bufferStrC8.remove(0,6);

                QString C8SysTimeStr = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                quint32 C8sysTimeMs = quint32(C8SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒
                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                int dayInt = houInt * 24;

                long day = 0;
                long hour = (C8sysTimeMs - day * dayInt) / houInt;
                long minute = (C8sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (C8sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = C8sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;

                /**************************************解析导航高度7-10***************************************************/
                bufferStrC8.remove(0,8);
                QString C8HeightStrBuff = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                qint32 C8HeightInt32 = qint32(C8HeightStrBuff.toUInt(nullptr,16));

                C8Height = C8HeightInt32 * 100000.0 * qPow(2,-31);

                QString C8HeightStr = QString::number(C8Height,'f',4);

                QString C8HeightDis = C8HeightStr+"m";

                ui->lineEdit_47->setText(C8HeightDis);
                ui->lineEdit_47->setStyleSheet( " color:blue; " );


                /**************************************解析导航天速11-14***************************************************/
                bufferStrC8.remove(0,8);
                QString C8UpSpeedStrBuff = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                qint32 C8UpSpeedInt32 = qint32(C8UpSpeedStrBuff.toUInt(nullptr,16));

                C8UpSpeed = C8UpSpeedInt32 * 1000.0 * qPow(2,-31);

                QString C8UpSpeedStr = QString::number(C8UpSpeed,'f',4);

                QString C8UpSpeedDis = C8UpSpeedStr + "kn";

                ui->lineEdit_45->setText(C8UpSpeedDis);
                ui->lineEdit_45->setStyleSheet( " color:blue; " );


                /**************************************解析GPS高度15-18***************************************************/
                bufferStrC8.remove(0,8);
                QString C8GPSHeightStrBuff = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                qint32 C8GPSHeightInt32 = qint32(C8GPSHeightStrBuff.toUInt(nullptr,16));

                C8GPSHeight = C8GPSHeightInt32 * 100000.0 * qPow(2,-31);

                QString C8GPSHeightStr = QString::number(C8GPSHeight,'f',4);

                QString C8GPSHeightDis = C8GPSHeightStr + "m";

                ui->lineEdit_46->setText(C8GPSHeightDis);



                /**************************************解析GPS天速19-22***************************************************/
                bufferStrC8.remove(0,8);
                QString C8GPTUpSpeedStrBuff = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                qint32 C8GPTUpSpeedInt32 = qint32(C8GPTUpSpeedStrBuff.toUInt(nullptr,16));

                C8GPTUpSpeed = C8GPTUpSpeedInt32 * 1000.0 * qPow(2,-31);

                QString C8GPTUpSpeedStr = QString::number(C8GPTUpSpeed,'f',4);

                QString C8GPTUpSpeedDis = C8GPTUpSpeedStr + "kn";

                ui->lineEdit_50->setText(C8GPTUpSpeedDis);

                /**************************************计程仪Z速（向下速度，对地）23-26**************************************************/
                bufferStrC8.remove(0,8);
                QString C8LogDownSpeed2GroundStrBuff = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                qint32 C8LogDownSpeed2GroundInt32 = qint32(C8LogDownSpeed2GroundStrBuff.toUInt(nullptr,16));

                C8LogDownSpeed2Ground = C8LogDownSpeed2GroundInt32 * 1000.0 * qPow(2,-31);

                QString C8LogDownSpeed2GroundStr = QString::number(C8LogDownSpeed2Ground,'f',4);

                QString C8LogDownSpeed2GroundDis = C8LogDownSpeed2GroundStr + "kn";

                ui->lineEdit_52->setText(C8LogDownSpeed2GroundDis);

                /**************************************计程仪Z速（向下速度，对水）27-30**************************************************/
                bufferStrC8.remove(0,8);
                QString C8LogDownSpeed2WaterStrBuff = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                qint32 C8LogDownSpeed2WaterInt32 = qint32(C8LogDownSpeed2WaterStrBuff.toUInt(nullptr,16));

                C8LogDownSpeed2Water = C8LogDownSpeed2WaterInt32 * 1000.0 * qPow(2,-31);

                QString C8LogDownSpeed2WaterStr = QString::number(C8LogDownSpeed2Water,'f',4);

                QString C8LogDownSpeed2WaterDis = C8LogDownSpeed2WaterStr + "kn";

                ui->lineEdit_51->setText(C8LogDownSpeed2WaterDis);

                /**************************************解析参考高度31-34***************************************************/
                bufferStrC8.remove(0,8);
                QString C8RefHeightStrBuff = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                qint32 C8RefHeightInt32 = qint32(C8RefHeightStrBuff.toUInt(nullptr,16));

                qreal C8RefHeight = C8RefHeightInt32 * 100000.0 * qPow(2,-31);

                QString C8RefHeightStr = QString::number(C8RefHeight,'f',4);

                QString C8RefHeightDis = C8RefHeightStr+"m";

                ui->lineEdit_48->setText(C8RefHeightDis);


                /**************************************解析参考天速35-38***************************************************/
                bufferStrC8.remove(0,8);
                QString C8RefUpSpeedStrBuff = bufferStrC8.left(8).mid(6,2)+bufferStrC8.left(8).mid(4,2)+bufferStrC8.left(8).mid(2,2)+bufferStrC8.left(8).mid(0,2);

                qint32 C8RefUpSpeedInt32 = qint32(C8RefUpSpeedStrBuff.toUInt(nullptr,16));

                qreal C8RefUpSpeed = C8RefUpSpeedInt32 * 1000.0 * qPow(2,-31);

                QString C8RefUpSpeedStr = QString::number(C8RefUpSpeed,'f',4);

                QString C8RefUpSpeedDis = C8RefUpSpeedStr + "kn";

                ui->lineEdit_53->setText(C8RefUpSpeedDis);

                C8getCurveData();
                hasDataVaildC8 = 0;
                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC8(&C8fileSave);

                //序号，标识号，导航高度，导航天速，GPS高度，GPS天速，计程仪对地速度，计程仪对水速度，参考高度，参考天速

                QString dataStr8 = dataInvaildRecordStr+","+"8"+","+C8HeightStr+","+C8UpSpeedStr+","+C8GPSHeightStr+","+C8GPTUpSpeedStr+","+C8LogDownSpeed2GroundStr+","+C8LogDownSpeed2WaterStr+","+C8RefHeightStr+","+C8RefUpSpeedStr+"\n";
                dataOutC8<<dataStr8.toUtf8();

            }
        }

        /**********************************************DVL参考信息数据C9******************************************************************/

        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == '9')
        {

            QString bufferStrC9 = bufferStr;
            if(bufferStrC9.size() != 18)
            {
                continue;
            }
            int C9checkNumInt = 0;
            QString C9checkNumStr;
            for(int i= 4;i<16;i=i+2)
            {
                C9checkNumInt = C9checkNumInt + bufferStrC9.mid(i,2).toInt(nullptr,16);
            }
            C9checkNumStr = QString::number(C9checkNumInt,16).right(2);
            if(C9checkNumStr == bufferStrC9.mid(16,2))
            {
                bufferStrC9.remove(0,6);
                QString C9DVLValidStr = bufferStrC9.left(2).mid(0,2);
//                if(C9DVLValidStr == "00")
//                    ui->label_55->setStyleSheet("font:bold;color:Red");
//                else
//                {
//                    ui->label_55->setStyleSheet("font:bold;color:rgb(0,200,50)");
//                    ui->lineEdit_54->setStyleSheet( " color:blue; " );

//                }
                bufferStrC9.remove(0,2);
                QString C9SysTimeStr = bufferStrC9.left(8).mid(6,2)+bufferStrC9.left(8).mid(4,2)+bufferStrC9.left(8).mid(2,2)+bufferStrC9.left(8).mid(0,2);

                qint32 C9sysTimeMs = qint32(C9SysTimeStr.toUInt(nullptr,16)) ;   //多普勒对底高度

                double dC9sysTimeMs = C9sysTimeMs * pow(10,-4);

                ui->lineEdit_54->setText(QString::number(dC9sysTimeMs,'f',4)+"m");


            }
        }

        /**********************************************PS入水深度数据CA******************************************************************/

        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == 'c' && bufferStr[5] == 'a')
        {

            QString bufferStrCA = bufferStr;
            if(bufferStrCA.size() != 18)
            {
                continue;
            }
            int CAcheckNumInt = 0;
            QString CAcheckNumStr;
            for(int i= 4;i<16;i=i+2)
            {
                CAcheckNumInt = CAcheckNumInt + bufferStrCA.mid(i,2).toInt(nullptr,16);
            }
            CAcheckNumStr = QString::number(CAcheckNumInt,16).right(2);
            if(CAcheckNumStr == bufferStrCA.mid(16,2))
            {
                bufferStrCA.remove(0,6);
                QString CAPSValidStr = bufferStrCA.left(2).mid(0,2);
                if(CAPSValidStr == "00")
                    ui->lineEdit_55->setStyleSheet( "color: rgb(0, 0, 0);" );
                else
                {
                    ui->lineEdit_55->setStyleSheet( "color: rgb(0, 0, 255);" );

                }
                bufferStrCA.remove(0,2);
                QString CASysTimeStr = bufferStrCA.left(8).mid(6,2)+bufferStrCA.left(8).mid(4,2)+bufferStrCA.left(8).mid(2,2)+bufferStrCA.left(8).mid(0,2);

                qint32 CAsysTimeMs = qint32(CASysTimeStr.toUInt(nullptr,16)) ;   //ps入水深度

                double dCAsysTimeMs = CAsysTimeMs * pow(10,-4);

                ui->lineEdit_55->setText(QString::number(dCAsysTimeMs,'f',4)+"m");


            }
        }

        /********************************************************初始位置信息数据格式01*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == '1')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 24)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************初始纬度***********************************************/
            QString OriLatStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 OriLatInt32 = qint32(OriLatStr.toUInt(nullptr,16));
            qreal OriLat = OriLatInt32 * 90.0*qPow(2,-31);
            QString OriLatStrDis = QString::number(OriLat,'f',4);
            ui->tableWidget_8->setItem(0,0,new QTableWidgetItem(OriLatStrDis));
            ui->tableWidget_8->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************初始经度***********************************************/
            bufferStrTemp.remove(0,8);
            QString OrilonStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 OrilonInt32 = qint32(OrilonStr.toUInt(nullptr,16));
            qreal Orilon = OrilonInt32 * 180.0*qPow(2,-31);
            QString OrilonStrDis = QString::number(Orilon,'f',4);
            ui->tableWidget_8->setItem(0,1,new QTableWidgetItem(OrilonStrDis));
            ui->tableWidget_8->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************初始航向信息数据格式02*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == '2')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 16)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************初始航向***********************************************/
            QString OriheadingAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            quint32 OriheadingAngleInt32 = quint32(OriheadingAngleStr.toUInt(nullptr,16));
            qreal OriheadingAngle = OriheadingAngleInt32 * 360.0*qPow(2,-32);
            QString OriheadingAngleStrDis = QString::number(OriheadingAngle,'f',4);
            ui->tableWidget_8->setItem(0,2,new QTableWidgetItem(OriheadingAngleStrDis));
            ui->tableWidget_8->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************初始速度信息数据格式03*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == '3')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() !=16)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************初始速度***********************************************/
            QString OriSpeedStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            quint32 OriSpeedInt32 = quint32(OriSpeedStr.toUInt(nullptr,16));
            qreal OriSpeed = OriSpeedInt32 * 1000.0*qPow(2,-32);
            QString OriSpeedStrDis = QString::number(OriSpeed,'f',4);
            ui->tableWidget_8->setItem(0,3,new QTableWidgetItem(OriSpeedStrDis));
            ui->tableWidget_8->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************陀螺标定参数数据格式07*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == '7')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 104)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            QString XGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XGyroScaleInt32 = qint32(XGyroScaleStr.toUInt(nullptr,16));
            qreal XGyroScale = XGyroScaleInt32 * qPow(10,-8);
            QString XGyroScaleStrDis = QString::number(XGyroScale,'f',4);
            ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(XGyroScaleStrDis));
            ui->tableWidget_2->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


            /***************************************Y陀螺标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YGyroScaleInt32 = qint32(YGyroScaleStr.toUInt(nullptr,16));
            qreal YGyroScale = YGyroScaleInt32 * qPow(10,-8);
            QString YGyroScaleStrDis = QString::number(YGyroScale,'f',4);
            ui->tableWidget_2->setItem(1,0,new QTableWidgetItem(YGyroScaleStrDis));
            ui->tableWidget_2->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZGyroScaleInt32 = qint32(ZGyroScaleStr.toUInt(nullptr,16));
            qreal ZGyroScale = ZGyroScaleInt32 * qPow(10,-8);
            QString ZGyroScaleStrDis = QString::number(ZGyroScale,'f',4);
            ui->tableWidget_2->setItem(2,0,new QTableWidgetItem(ZGyroScaleStrDis));
            ui->tableWidget_2->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString XZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XZeroBiasInt32 = qint32(XZeroBiasStr.toUInt(nullptr,16));
            qreal XZeroBias = XZeroBiasInt32 * qPow(10,-6);
            QString XZeroBiasStrDis = QString::number(XZeroBias,'f',4);
            ui->tableWidget_2->setItem(0,3,new QTableWidgetItem(XZeroBiasStrDis));
            ui->tableWidget_2->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString YZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YZeroBiasInt32 = qint32(YZeroBiasStr.toUInt(nullptr,16));
            qreal YZeroBias = YZeroBiasInt32 * qPow(10,-6);
            QString YZeroBiasStrDis = QString::number(YZeroBias,'f',4);
            ui->tableWidget_2->setItem(1,3,new QTableWidgetItem(YZeroBiasStrDis));
            ui->tableWidget_2->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZZeroBiasInt32 = qint32(ZZeroBiasStr.toUInt(nullptr,16));
            qreal ZZeroBias = ZZeroBiasInt32 * qPow(10,-6);
            QString ZZeroBiasStrDis = QString::number(ZZeroBias,'f',4);
            ui->tableWidget_2->setItem(2,3,new QTableWidgetItem(ZZeroBiasStrDis));
            ui->tableWidget_2->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uxy常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUxyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUxyInt32 = qint32(GyroInstallErrorUxyStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUxy = GyroInstallErrorUxyInt32 * qPow(10,-4);
            QString GyroInstallErrorUxyStrDis = QString::number(GyroInstallErrorUxy,'f',4);
            ui->tableWidget_2->setItem(0,1,new QTableWidgetItem(GyroInstallErrorUxyStrDis));
            ui->tableWidget_2->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uxz常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUxzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUxzInt32 = qint32(GyroInstallErrorUxzStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUxz = GyroInstallErrorUxzInt32 * qPow(10,-4);
            QString GyroInstallErrorUxzStrDis = QString::number(GyroInstallErrorUxz,'f',4);
            ui->tableWidget_2->setItem(0,2,new QTableWidgetItem(GyroInstallErrorUxzStrDis));
            ui->tableWidget_2->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uyx常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUyxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUyxInt32 = qint32(GyroInstallErrorUyxStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUyx = GyroInstallErrorUyxInt32 * qPow(10,-4);
            QString GyroInstallErrorUyxStrDis = QString::number(GyroInstallErrorUyx,'f',4);
            ui->tableWidget_2->setItem(1,1,new QTableWidgetItem(GyroInstallErrorUyxStrDis));
            ui->tableWidget_2->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uyz常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUyzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUyzInt32 = qint32(GyroInstallErrorUyzStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUyz = GyroInstallErrorUyzInt32 * qPow(10,-4);
            QString GyroInstallErrorUyzStrDis = QString::number(GyroInstallErrorUyz,'f',4);
            ui->tableWidget_2->setItem(1,2,new QTableWidgetItem(GyroInstallErrorUyzStrDis));
            ui->tableWidget_2->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uzx常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUzxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUzxInt32 = qint32(GyroInstallErrorUzxStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUzx = GyroInstallErrorUzxInt32 * qPow(10,-4);
            QString GyroInstallErrorUzxStrDis = QString::number(GyroInstallErrorUzx,'f',4);
            ui->tableWidget_2->setItem(2,1,new QTableWidgetItem(GyroInstallErrorUzxStrDis));
            ui->tableWidget_2->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uzy常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUzyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUzyInt32 = qint32(GyroInstallErrorUzyStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUzy = GyroInstallErrorUzyInt32 * qPow(10,-4);
            QString GyroInstallErrorUzyStrDis = QString::number(GyroInstallErrorUzy,'f',4);
            ui->tableWidget_2->setItem(2,2,new QTableWidgetItem(GyroInstallErrorUzyStrDis));
            ui->tableWidget_2->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }


        /********************************************************陀螺标定参数2数据格式13*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '1' && bufferStr[5] == '3')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 80)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            QString XGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XGyroScaleInt32 = qint32(XGyroScaleStr.toUInt(nullptr,16));
            qreal XGyroScale = XGyroScaleInt32 * qPow(10,-8);
            QString XGyroScaleStrDis = QString::number(XGyroScale,'f',4);
            ui->tableWidget_5->setItem(0,0,new QTableWidgetItem(XGyroScaleStrDis));
            ui->tableWidget_5->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


            /***************************************Y陀螺标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YGyroScaleInt32 = qint32(YGyroScaleStr.toUInt(nullptr,16));
            qreal YGyroScale = YGyroScaleInt32 * qPow(10,-8);
            QString YGyroScaleStrDis = QString::number(YGyroScale,'f',4);
            ui->tableWidget_5->setItem(1,0,new QTableWidgetItem(YGyroScaleStrDis));
            ui->tableWidget_5->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZGyroScaleInt32 = qint32(ZGyroScaleStr.toUInt(nullptr,16));
            qreal ZGyroScale = ZGyroScaleInt32 * qPow(10,-8);
            QString ZGyroScaleStrDis = QString::number(ZGyroScale,'f',4);
            ui->tableWidget_5->setItem(2,0,new QTableWidgetItem(ZGyroScaleStrDis));
            ui->tableWidget_5->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺序号***********************************************/
            bufferStrTemp.remove(0,8);

            QString XZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XZeroBiasInt32 = qint32(XZeroBiasStr.toUInt(nullptr,16));
            qreal XZeroBias = XZeroBiasInt32 * qPow(10,-8);
            QString XZeroBiasStrDis = QString::number(XZeroBias,'f',4);
            ui->tableWidget_5->setItem(0,1,new QTableWidgetItem(XZeroBiasStrDis));
            ui->tableWidget_5->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺序号***********************************************/
            bufferStrTemp.remove(0,8);

            QString YZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YZeroBiasInt32 = qint32(YZeroBiasStr.toUInt(nullptr,16));
            qreal YZeroBias = YZeroBiasInt32 * qPow(10,-8);
            QString YZeroBiasStrDis = QString::number(YZeroBias,'f',4);
            ui->tableWidget_5->setItem(1,1,new QTableWidgetItem(YZeroBiasStrDis));
            ui->tableWidget_5->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺序号***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZZeroBiasInt32 = qint32(ZZeroBiasStr.toUInt(nullptr,16));
            qreal ZZeroBias = ZZeroBiasInt32 * qPow(10,-8);
            QString ZZeroBiasStrDis = QString::number(ZZeroBias,'f',4);
            ui->tableWidget_5->setItem(2,1,new QTableWidgetItem(ZZeroBiasStrDis));
            ui->tableWidget_5->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺符号***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUxyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUxyInt32 = qint32(GyroInstallErrorUxyStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUxy = GyroInstallErrorUxyInt32 * qPow(10,-8);
            QString GyroInstallErrorUxyStrDis = QString::number(GyroInstallErrorUxy,'f',4);
            ui->tableWidget_5->setItem(0,2,new QTableWidgetItem(GyroInstallErrorUxyStrDis));
            ui->tableWidget_5->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺符号***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUxzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUxzInt32 = qint32(GyroInstallErrorUxzStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUxz = GyroInstallErrorUxzInt32 * qPow(10,-8);
            QString GyroInstallErrorUxzStrDis = QString::number(GyroInstallErrorUxz,'f',4);
            ui->tableWidget_5->setItem(1,2,new QTableWidgetItem(GyroInstallErrorUxzStrDis));
            ui->tableWidget_5->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺符号***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUyxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUyxInt32 = qint32(GyroInstallErrorUyxStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUyx = GyroInstallErrorUyxInt32 * qPow(10,-8);
            QString GyroInstallErrorUyxStrDis = QString::number(GyroInstallErrorUyx,'f',4);
            ui->tableWidget_5->setItem(2,2,new QTableWidgetItem(GyroInstallErrorUyxStrDis));
            ui->tableWidget_5->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************加速度计标定参数数据格式08*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == '8')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 104)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            QString XAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XAccelerometerScaleInt32 = qint32(XAccelerometerScaleStr.toUInt(nullptr,16));
            qreal XAccelerometerScale = XAccelerometerScaleInt32 * qPow(10,-6);
            QString XAccelerometerScaleStrDis = QString::number(XAccelerometerScale,'f',4);
            ui->tableWidget_2->setItem(3,0,new QTableWidgetItem(XAccelerometerScaleStrDis));
            ui->tableWidget_2->item(3,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


            /***************************************Y加速度计标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YAccelerometerScaleInt32 = qint32(YAccelerometerScaleStr.toUInt(nullptr,16));
            qreal YAccelerometerScale = YAccelerometerScaleInt32 * qPow(10,-6);
            QString YAccelerometerScaleStrDis = QString::number(YAccelerometerScale,'f',4);
            ui->tableWidget_2->setItem(4,0,new QTableWidgetItem(YAccelerometerScaleStrDis));
            ui->tableWidget_2->item(4,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZAccelerometerScaleInt32 = qint32(ZAccelerometerScaleStr.toUInt(nullptr,16));
            qreal ZAccelerometerScale = ZAccelerometerScaleInt32 * qPow(10,-6);
            QString ZAccelerometerScaleStrDis = QString::number(ZAccelerometerScale,'f',4);
            ui->tableWidget_2->setItem(5,0,new QTableWidgetItem(ZAccelerometerScaleStrDis));
            ui->tableWidget_2->item(5,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString XZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XZeroBiasInt32 = qint32(XZeroBiasStr.toUInt(nullptr,16));
            qreal XZeroBias = XZeroBiasInt32 * qPow(10,-6);
            QString XZeroBiasStrDis = QString::number(XZeroBias,'f',4);
            ui->tableWidget_2->setItem(3,3,new QTableWidgetItem(XZeroBiasStrDis));
            ui->tableWidget_2->item(3,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString YZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YZeroBiasInt32 = qint32(YZeroBiasStr.toUInt(nullptr,16));
            qreal YZeroBias = YZeroBiasInt32 * qPow(10,-6);
            QString YZeroBiasStrDis = QString::number(YZeroBias,'f',4);
            ui->tableWidget_2->setItem(4,3,new QTableWidgetItem(YZeroBiasStrDis));
            ui->tableWidget_2->item(4,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZZeroBiasInt32 = qint32(ZZeroBiasStr.toUInt(nullptr,16));
            qreal ZZeroBias = ZZeroBiasInt32 * qPow(10,-6);
            QString ZZeroBiasStrDis = QString::number(ZZeroBias,'f',4);
            ui->tableWidget_2->setItem(5,3,new QTableWidgetItem(ZZeroBiasStrDis));
            ui->tableWidget_2->item(5,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uxy常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUxyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUxyInt32 = qint32(AccelerometerInstallErrorUxyStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUxy = AccelerometerInstallErrorUxyInt32 * qPow(10,-4);
            QString AccelerometerInstallErrorUxyStrDis = QString::number(AccelerometerInstallErrorUxy,'f',4);
            ui->tableWidget_2->setItem(3,1,new QTableWidgetItem(AccelerometerInstallErrorUxyStrDis));
            ui->tableWidget_2->item(3,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uxz常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUxzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUxzInt32 = qint32(AccelerometerInstallErrorUxzStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUxz = AccelerometerInstallErrorUxzInt32 * qPow(10,-4);
            QString AccelerometerInstallErrorUxzStrDis = QString::number(AccelerometerInstallErrorUxz,'f',4);
            ui->tableWidget_2->setItem(3,2,new QTableWidgetItem(AccelerometerInstallErrorUxzStrDis));
            ui->tableWidget_2->item(3,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uyx常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUyxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUyxInt32 = qint32(AccelerometerInstallErrorUyxStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUyx = AccelerometerInstallErrorUyxInt32 * qPow(10,-4);
            QString AccelerometerInstallErrorUyxStrDis = QString::number(AccelerometerInstallErrorUyx,'f',4);
            ui->tableWidget_2->setItem(4,1,new QTableWidgetItem(AccelerometerInstallErrorUyxStrDis));
            ui->tableWidget_2->item(4,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uyz常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUyzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUyzInt32 = qint32(AccelerometerInstallErrorUyzStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUyz = AccelerometerInstallErrorUyzInt32 * qPow(10,-4);
            QString AccelerometerInstallErrorUyzStrDis = QString::number(AccelerometerInstallErrorUyz,'f',4);
            ui->tableWidget_2->setItem(4,2,new QTableWidgetItem(AccelerometerInstallErrorUyzStrDis));
            ui->tableWidget_2->item(4,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uzx常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUzxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUzxInt32 = qint32(AccelerometerInstallErrorUzxStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUzx = AccelerometerInstallErrorUzxInt32 * qPow(10,-4);
            QString AccelerometerInstallErrorUzxStrDis = QString::number(AccelerometerInstallErrorUzx,'f',4);
            ui->tableWidget_2->setItem(5,1,new QTableWidgetItem(AccelerometerInstallErrorUzxStrDis));
            ui->tableWidget_2->item(5,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uzy常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUzyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUzyInt32 = qint32(AccelerometerInstallErrorUzyStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUzy = AccelerometerInstallErrorUzyInt32 * qPow(10,-4);
            QString AccelerometerInstallErrorUzyStrDis = QString::number(AccelerometerInstallErrorUzy,'f',4);
            ui->tableWidget_2->setItem(5,2,new QTableWidgetItem(AccelerometerInstallErrorUzyStrDis));
            ui->tableWidget_2->item(5,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

        /********************************************************加速度计标定参数数据格式14*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '1' && bufferStr[5] == '4')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 160)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            QString XAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XAccelerometerScaleInt32 = qint32(XAccelerometerScaleStr.toUInt(nullptr,16));
            qreal XAccelerometerScale = XAccelerometerScaleInt32 * qPow(10,-6);
            QString XAccelerometerScaleStrDis = QString::number(XAccelerometerScale,'f',4);
            ui->tableWidget_10->setItem(0,0,new QTableWidgetItem(XAccelerometerScaleStrDis));
            ui->tableWidget_10->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


            /***************************************Y加速度计名义标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YAccelerometerScaleInt32 = qint32(YAccelerometerScaleStr.toUInt(nullptr,16));
            qreal YAccelerometerScale = YAccelerometerScaleInt32 * qPow(10,-6);
            QString YAccelerometerScaleStrDis = QString::number(YAccelerometerScale,'f',4);
            ui->tableWidget_10->setItem(1,0,new QTableWidgetItem(YAccelerometerScaleStrDis));
            ui->tableWidget_10->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计名义标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZAccelerometerScaleInt32 = qint32(ZAccelerometerScaleStr.toUInt(nullptr,16));
            qreal ZAccelerometerScale = ZAccelerometerScaleInt32 * qPow(10,-6);
            QString ZAccelerometerScaleStrDis = QString::number(ZAccelerometerScale,'f',4);
            ui->tableWidget_10->setItem(2,0,new QTableWidgetItem(ZAccelerometerScaleStrDis));
            ui->tableWidget_10->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计序号***********************************************/
            bufferStrTemp.remove(0,8);

            QString XZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XZeroBiasInt32 = qint32(XZeroBiasStr.toUInt(nullptr,16));
            qreal XZeroBias = XZeroBiasInt32 * qPow(10,-6);
            QString XZeroBiasStrDis = QString::number(XZeroBias,'f',4);
            ui->tableWidget_10->setItem(0,1,new QTableWidgetItem(XZeroBiasStrDis));
            ui->tableWidget_10->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计序号***********************************************/
            bufferStrTemp.remove(0,8);

            QString YZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YZeroBiasInt32 = qint32(YZeroBiasStr.toUInt(nullptr,16));
            qreal YZeroBias = YZeroBiasInt32 * qPow(10,-6);
            QString YZeroBiasStrDis = QString::number(YZeroBias,'f',4);
            ui->tableWidget_10->setItem(1,1,new QTableWidgetItem(YZeroBiasStrDis));
            ui->tableWidget_10->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计序号***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZZeroBiasInt32 = qint32(ZZeroBiasStr.toUInt(nullptr,16));
            qreal ZZeroBias = ZZeroBiasInt32 * qPow(10,-6);
            QString ZZeroBiasStrDis = QString::number(ZZeroBias,'f',4);
            ui->tableWidget_10->setItem(2,1,new QTableWidgetItem(ZZeroBiasStrDis));
            ui->tableWidget_10->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计符号***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUxyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUxyInt32 = qint32(AccelerometerInstallErrorUxyStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUxy = AccelerometerInstallErrorUxyInt32 * qPow(10,-6);
            QString AccelerometerInstallErrorUxyStrDis = QString::number(AccelerometerInstallErrorUxy,'f',4);
            ui->tableWidget_10->setItem(0,2,new QTableWidgetItem(AccelerometerInstallErrorUxyStrDis));
            ui->tableWidget_10->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计符号***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUxzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUxzInt32 = qint32(AccelerometerInstallErrorUxzStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUxz = AccelerometerInstallErrorUxzInt32 * qPow(10,-6);
            QString AccelerometerInstallErrorUxzStrDis = QString::number(AccelerometerInstallErrorUxz,'f',4);
            ui->tableWidget_10->setItem(1,2,new QTableWidgetItem(AccelerometerInstallErrorUxzStrDis));
            ui->tableWidget_10->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计符号***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUyxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUyxInt32 = qint32(AccelerometerInstallErrorUyxStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUyx = AccelerometerInstallErrorUyxInt32 * qPow(10,-6);
            QString AccelerometerInstallErrorUyxStrDis = QString::number(AccelerometerInstallErrorUyx,'f',4);
            ui->tableWidget_10->setItem(2,2,new QTableWidgetItem(AccelerometerInstallErrorUyxStrDis));
            ui->tableWidget_10->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计标度非对称性误差***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUyzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUyzInt32 = qint32(AccelerometerInstallErrorUyzStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUyz = AccelerometerInstallErrorUyzInt32 * qPow(10,-6);
            QString AccelerometerInstallErrorUyzStrDis = QString::number(AccelerometerInstallErrorUyz,'f',4);
            ui->tableWidget_10->setItem(0,3,new QTableWidgetItem(AccelerometerInstallErrorUyzStrDis));
            ui->tableWidget_10->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计标度非对称性误差***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUzxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUzxInt32 = qint32(AccelerometerInstallErrorUzxStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUzx = AccelerometerInstallErrorUzxInt32 * qPow(10,-6);
            QString AccelerometerInstallErrorUzxStrDis = QString::number(AccelerometerInstallErrorUzx,'f',4);
            ui->tableWidget_10->setItem(1,3,new QTableWidgetItem(AccelerometerInstallErrorUzxStrDis));
            ui->tableWidget_10->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计标度非对称性误差***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUzyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUzyInt32 = qint32(AccelerometerInstallErrorUzyStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUzy = AccelerometerInstallErrorUzyInt32 * qPow(10,-6);
            QString AccelerometerInstallErrorUzyStrDis = QString::number(AccelerometerInstallErrorUzy,'f',4);
            ui->tableWidget_10->setItem(2,3,new QTableWidgetItem(AccelerometerInstallErrorUzyStrDis));
            ui->tableWidget_10->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加标尺寸效应L1X***********************************************/
            bufferStrTemp.remove(0,8);

            QString Accelerometer2InstallErrorUyzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 Accelerometer2InstallErrorUyzInt32 = qint32(Accelerometer2InstallErrorUyzStr.toUInt(nullptr,16));
            qreal Accelerometer2InstallErrorUyz = Accelerometer2InstallErrorUyzInt32 * qPow(10,-6);
            QString Accelerometer2InstallErrorUyzStrDis = QString::number(Accelerometer2InstallErrorUyz,'f',4);
            ui->tableWidget_10->setItem(0,4,new QTableWidgetItem(Accelerometer2InstallErrorUyzStrDis));
            ui->tableWidget_10->item(0,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加标尺寸效应L1Y***********************************************/
            bufferStrTemp.remove(0,8);

            QString Accelerometer2InstallErrorUzxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 Accelerometer2InstallErrorUzxInt32 = qint32(Accelerometer2InstallErrorUzxStr.toUInt(nullptr,16));
            qreal Accelerometer2InstallErrorUzx = Accelerometer2InstallErrorUzxInt32 * qPow(10,-6);
            QString Accelerometer2InstallErrorUzxStrDis = QString::number(Accelerometer2InstallErrorUzx,'f',4);
            ui->tableWidget_10->setItem(1,4,new QTableWidgetItem(Accelerometer2InstallErrorUzxStrDis));
            ui->tableWidget_10->item(1,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加标尺寸效应L1Z***********************************************/
            bufferStrTemp.remove(0,8);

            QString Accelerometer2InstallErrorUzyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 Accelerometer2InstallErrorUzyInt32 = qint32(Accelerometer2InstallErrorUzyStr.toUInt(nullptr,16));
            qreal Accelerometer2InstallErrorUzy = Accelerometer2InstallErrorUzyInt32 * qPow(10,-6);
            QString Accelerometer2InstallErrorUzyStrDis = QString::number(Accelerometer2InstallErrorUzy,'f',4);
            ui->tableWidget_10->setItem(2,4,new QTableWidgetItem(Accelerometer2InstallErrorUzyStrDis));
            ui->tableWidget_10->item(2,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加标尺寸效应L2X***********************************************/
            bufferStrTemp.remove(0,8);

            QString Accelerometer3InstallErrorUyzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 Accelerometer3InstallErrorUyzInt32 = qint32(Accelerometer3InstallErrorUyzStr.toUInt(nullptr,16));
            qreal Accelerometer3InstallErrorUyz = Accelerometer3InstallErrorUyzInt32 * qPow(10,-6);
            QString Accelerometer3InstallErrorUyzStrDis = QString::number(Accelerometer3InstallErrorUyz,'f',4);
            ui->tableWidget_10->setItem(0,5,new QTableWidgetItem(Accelerometer3InstallErrorUyzStrDis));
            ui->tableWidget_10->item(0,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加标尺寸效应L2Y***********************************************/
            bufferStrTemp.remove(0,8);

            QString Accelerometer3InstallErrorUzxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 Accelerometer3InstallErrorUzxInt32 = qint32(Accelerometer3InstallErrorUzxStr.toUInt(nullptr,16));
            qreal Accelerometer3InstallErrorUzx = Accelerometer3InstallErrorUzxInt32 * qPow(10,-6);
            QString Accelerometer3InstallErrorUzxStrDis = QString::number(Accelerometer3InstallErrorUzx,'f',4);
            ui->tableWidget_10->setItem(1,5,new QTableWidgetItem(Accelerometer3InstallErrorUzxStrDis));
            ui->tableWidget_10->item(1,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加标尺寸效应L2Z***********************************************/
            bufferStrTemp.remove(0,8);

            QString Accelerometer3InstallErrorUzyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 Accelerometer3InstallErrorUzyInt32 = qint32(Accelerometer3InstallErrorUzyStr.toUInt(nullptr,16));
            qreal Accelerometer3InstallErrorUzy = Accelerometer3InstallErrorUzyInt32 * qPow(10,-6);
            QString Accelerometer3InstallErrorUzyStrDis = QString::number(Accelerometer3InstallErrorUzy,'f',4);
            ui->tableWidget_10->setItem(2,5,new QTableWidgetItem(Accelerometer3InstallErrorUzyStrDis));
            ui->tableWidget_10->item(2,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************温度系数***********************************************/
            bufferStrTemp.remove(0,8);

            QString Accelerometer4InstallErrorUzyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 Accelerometer4InstallErrorUzyInt32 = qint32(Accelerometer4InstallErrorUzyStr.toUInt(nullptr,16));
            qreal Accelerometer4InstallErrorUzy = Accelerometer4InstallErrorUzyInt32 * qPow(10,-6);
            QString Accelerometer4InstallErrorUzyStrDis = QString::number(Accelerometer4InstallErrorUzy,'f',4);
            ui->tableWidget_10->setItem(0,6,new QTableWidgetItem(Accelerometer4InstallErrorUzyStrDis));
            ui->tableWidget_10->item(0,6)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

        /********************************************************等效零偏装据格式09*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == '9')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 32)
            {
                continue;
            }
            /***************************************等效E陀螺零偏***********************************************/
            bufferStrTemp.remove(0,6);
            QString XEqZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XEqZeroBiasInt32 = qint32(XEqZeroBiasStr.toUInt(nullptr,16));
            qreal XEqZeroBias = XEqZeroBiasInt32 * qPow(10,-6);
            QString XEqZeroBiasStrDis = QString::number(XEqZeroBias,'f',4);
            ui->tableWidget_2->setItem(0,4,new QTableWidgetItem(XEqZeroBiasStrDis));
            ui->tableWidget_2->item(0,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


            /***************************************等效N陀螺零偏***********************************************/
            bufferStrTemp.remove(0,8);

            QString YEqZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YEqZeroBiasInt32 = qint32(YEqZeroBiasStr.toUInt(nullptr,16));
            qreal YEqZeroBias = YEqZeroBiasInt32 * qPow(10,-6);
            QString YEqZeroBiasStrDis = QString::number(YEqZeroBias,'f',4);
            ui->tableWidget_2->setItem(1,4,new QTableWidgetItem(YEqZeroBiasStrDis));
            ui->tableWidget_2->item(1,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************等效U陀螺零偏***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZEqZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZEqZeroBiasInt32 = qint32(ZEqZeroBiasStr.toUInt(nullptr,16));
            qreal ZEqZeroBias = ZEqZeroBiasInt32 * qPow(10,-6);
            QString ZEqZeroBiasStrDis = QString::number(ZEqZeroBias,'f',4);
            ui->tableWidget_2->setItem(2,4,new QTableWidgetItem(ZEqZeroBiasStrDis));
            ui->tableWidget_2->item(2,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }

        /********************************************************系统姿态零位数据格式0A*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == 'a')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 32)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************系统横摇角零位***********************************************/
            QString sysRollAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 sysRollAngleInt32 = qint32(sysRollAngleStr.toUInt(nullptr,16));
            qreal sysRollAngle = sysRollAngleInt32 * 90.0*qPow(2,-31);
            QString sysRollAngleStrDis = QString::number(sysRollAngle,'f',4);
            ui->tableWidget_7->setItem(0,0,new QTableWidgetItem(sysRollAngleStrDis));
            ui->tableWidget_7->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************系统纵摇角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString sysPitchAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 sysPitchAngleInt32 = qint32(sysPitchAngleStr.toUInt(nullptr,16));
           // double sysPitchAngle = 47721859 * 90.0 * qPow(2,-31);
            double sysPitchAngle = sysPitchAngleInt32 * 90.0*qPow(2,-31);

            QString sysPitchAngleStrDis = QString::number(sysPitchAngle,'f',4);
            ui->tableWidget_7->setItem(1,0,new QTableWidgetItem(sysPitchAngleStrDis));
            ui->tableWidget_7->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************系统航向角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString sysHeadingAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 sysHeadingAngleInt32 = qint32(sysHeadingAngleStr.toUInt(nullptr,16));
            qreal sysHeadingAngle = sysHeadingAngleInt32 * 180.0*qPow(2,-31);
            QString sysHeadingAngleStrDis = QString::number(sysHeadingAngle,'f',4);
            ui->tableWidget_7->setItem(2,0,new QTableWidgetItem(sysHeadingAngleStrDis));
            ui->tableWidget_7->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

        /********************************************************惯组姿态零位与惯组姿态零位装据格式0B*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == 'b')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 56)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************惯组横摇角零位***********************************************/
            QString IMUrollAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 IMUrollAngleInt32 = qint32(IMUrollAngleStr.toUInt(nullptr,16));
            qreal IMUrollAngle = IMUrollAngleInt32 * 90.0*qPow(2,-31);
            QString IMUrollAngleStrDis = QString::number(IMUrollAngle,'f',4);
            ui->tableWidget_7->setItem(0,1,new QTableWidgetItem(IMUrollAngleStrDis));
            ui->tableWidget_7->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************惯组纵摇角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString IMUpitchAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 IMUpitchAngleInt32 = qint32(IMUpitchAngleStr.toUInt(nullptr,16));
            qreal IMUpitchAngle = IMUpitchAngleInt32 * 90.0*qPow(2,-31);
            QString IMUpitchAngleStrDis = QString::number(IMUpitchAngle,'f',4);
            ui->tableWidget_7->setItem(1,1,new QTableWidgetItem(IMUpitchAngleStrDis));
            ui->tableWidget_7->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************惯组航向角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString IMUheadingAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 IMUheadingAngleInt32 = qint32(IMUheadingAngleStr.toUInt(nullptr,16));
            qreal IMUheadingAngle = IMUheadingAngleInt32 * 180.0*qPow(2,-31);
            QString IMUheadingAngleStrDis = QString::number(IMUheadingAngle,'f',4);
            ui->tableWidget_7->setItem(2,1,new QTableWidgetItem(IMUheadingAngleStrDis));
            ui->tableWidget_7->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************输出横摇角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString outputRollAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 outputRollAngleInt32 = qint32(outputRollAngleStr.toUInt(nullptr,16));
            qreal outputRollAngle = outputRollAngleInt32 * 90.0*qPow(2,-31);
            QString outputRollAngleStrDis = QString::number(outputRollAngle,'f',4);
            ui->tableWidget_7->setItem(0,2,new QTableWidgetItem(outputRollAngleStrDis));
            ui->tableWidget_7->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************输出纵摇角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString outputPitchAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 outputPitchAngleInt32 = qint32(outputPitchAngleStr.toUInt(nullptr,16));
            qreal outputPitchAngle = outputPitchAngleInt32 * 90.0*qPow(2,-31);
            QString outputPitchAngleStrDis = QString::number(outputPitchAngle,'f',4);
            ui->tableWidget_7->setItem(1,2,new QTableWidgetItem(outputPitchAngleStrDis));
            ui->tableWidget_7->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************输出航向角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString outputHeadingAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 outputHeadingAngleInt32 = qint32(outputHeadingAngleStr.toUInt(nullptr,16));
            qreal outputHeadingAngle = outputHeadingAngleInt32 * 180.0*qPow(2,-31);
            QString outputHeadingAngleStrDis = QString::number(outputHeadingAngle,'f',4);
            ui->tableWidget_7->setItem(2,2,new QTableWidgetItem(outputHeadingAngleStrDis));
            ui->tableWidget_7->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************杆臂装订数据格式0C*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == 'c')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 80)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************X1GPS1***********************************************/
            QString X1GPS1Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X1GPS1Int32 = qint16(X1GPS1Str.toUInt(nullptr,16));
            qreal X1GPS1 = X1GPS1Int32 * qPow(10,-2);
            QString X1GPS1StrDis = QString::number(X1GPS1,'f',2);
            ui->tableWidget_4->setItem(0,0,new QTableWidgetItem(X1GPS1StrDis));
            ui->tableWidget_4->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y1GPS1***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y1GPS1Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y1GPS1Int32 = qint16(Y1GPS1Str.toUInt(nullptr,16));
            qreal Y1GPS1 = Y1GPS1Int32 * qPow(10,-2);
            QString Y1GPS1StrDis = QString::number(Y1GPS1,'f',2);
            ui->tableWidget_4->setItem(1,0,new QTableWidgetItem(Y1GPS1StrDis));
            ui->tableWidget_4->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z1GPS1***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z1GPS1Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z1GPS1Int32 = qint16(Z1GPS1Str.toUInt(nullptr,16));
            qreal Z1GPS1 = Z1GPS1Int32 * qPow(10,-2);
            QString Z1GPS1StrDis = QString::number(Z1GPS1,'f',2);
            ui->tableWidget_4->setItem(2,0,new QTableWidgetItem(Z1GPS1StrDis));
            ui->tableWidget_4->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X2GPS2***********************************************/
            bufferStrTemp.remove(0,4);
            QString X2GPS2Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X2GPS2Int32 = qint16(X2GPS2Str.toUInt(nullptr,16));
            qreal X2GPS2 = X2GPS2Int32 * qPow(10,-2);
            QString X2GPS2StrDis = QString::number(X2GPS2,'f',2);
            ui->tableWidget_4->setItem(0,1,new QTableWidgetItem(X2GPS2StrDis));
            ui->tableWidget_4->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y2GPS2***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y2GPS2Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y2GPS2Int32 = qint16(Y2GPS2Str.toUInt(nullptr,16));
            qreal Y2GPS2 = Y2GPS2Int32 * qPow(10,-2);
            QString Y2GPS2StrDis = QString::number(Y2GPS2,'f',2);
            ui->tableWidget_4->setItem(1,1,new QTableWidgetItem(Y2GPS2StrDis));
            ui->tableWidget_4->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z2GPS2***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z2GPS2Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z2GPS2Int32 = qint16(Z2GPS2Str.toUInt(nullptr,16));
            qreal Z2GPS2 = Z2GPS2Int32 * qPow(10,-2);
            QString Z2GPS2StrDis = QString::number(Z2GPS2,'f',2);
            ui->tableWidget_4->setItem(2,1,new QTableWidgetItem(Z2GPS2StrDis));
            ui->tableWidget_4->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X3DOPPLER***********************************************/
            bufferStrTemp.remove(0,4);
            QString X3DOPPLERStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X3DOPPLERInt32 = qint16(X3DOPPLERStr.toUInt(nullptr,16));
            qreal X3DOPPLER = X3DOPPLERInt32 * qPow(10,-2);
            QString X3DOPPLERStrDis = QString::number(X3DOPPLER,'f',2);
            ui->tableWidget_4->setItem(0,2,new QTableWidgetItem(X3DOPPLERStrDis));
            ui->tableWidget_4->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y3DOPPLER***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y3DOPPLERStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y3DOPPLERInt32 = qint16(Y3DOPPLERStr.toUInt(nullptr,16));
            qreal Y3DOPPLER = Y3DOPPLERInt32 * qPow(10,-2);
            QString Y3DOPPLERStrDis = QString::number(Y3DOPPLER,'f',2);
            ui->tableWidget_4->setItem(1,2,new QTableWidgetItem(Y3DOPPLERStrDis));
            ui->tableWidget_4->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z3DOPPLER***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z3DOPPLERStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z3DOPPLERInt32 = qint16(Z3DOPPLERStr.toUInt(nullptr,16));
            qreal Z3DOPPLER = Z3DOPPLERInt32 * qPow(10,-2);
            QString Z3DOPPLERStrDis = QString::number(Z3DOPPLER,'f',2);
            ui->tableWidget_4->setItem(2,2,new QTableWidgetItem(Z3DOPPLERStrDis));
            ui->tableWidget_4->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X4LOG_EM*******************************************/
            bufferStrTemp.remove(0,4);
            QString X4LOG_EMStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X4LOG_EMInt32 = qint16(X4LOG_EMStr.toUInt(nullptr,16));
            qreal X4LOG_EM = X4LOG_EMInt32 * qPow(10,-2);
            QString X4LOG_EMStrDis = QString::number(X4LOG_EM,'f',2);
            ui->tableWidget_4->setItem(0,3,new QTableWidgetItem(X4LOG_EMStrDis));
            ui->tableWidget_4->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y4LOG_EM***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y4LOG_EMStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y4LOG_EMInt32 = qint16(Y4LOG_EMStr.toUInt(nullptr,16));
            qreal Y4LOG_EM = Y4LOG_EMInt32 * qPow(10,-2);
            QString Y4LOG_EMStrDis = QString::number(Y4LOG_EM,'f',2);
            ui->tableWidget_4->setItem(1,3,new QTableWidgetItem(Y4LOG_EMStrDis));
            ui->tableWidget_4->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z4LOG_EM***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z4LOG_EMStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z4LOG_EMInt32 = qint16(Z4LOG_EMStr.toUInt(nullptr,16));
            qreal Z4LOG_EM = Z4LOG_EMInt32 * qPow(10,-2);
            QString Z4LOG_EMStrDis = QString::number(Z4LOG_EM,'f',2);
            ui->tableWidget_4->setItem(2,3,new QTableWidgetItem(Z4LOG_EMStrDis));
            ui->tableWidget_4->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X5MAIN_INS*******************************************/
            bufferStrTemp.remove(0,4);
            QString X5MAIN_INSStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X5MAIN_INSInt32 = qint16(X5MAIN_INSStr.toUInt(nullptr,16));
            qreal X5MAIN_INS = X5MAIN_INSInt32 * qPow(10,-2);
            QString X5MAIN_INSStrDis = QString::number(X5MAIN_INS,'f',2);
            ui->tableWidget_4->setItem(0,4,new QTableWidgetItem(X5MAIN_INSStrDis));
            ui->tableWidget_4->item(0,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y5MAIN_INS***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y5MAIN_INSStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y5MAIN_INSInt32 = qint16(Y5MAIN_INSStr.toUInt(nullptr,16));
            qreal Y5MAIN_INS = Y5MAIN_INSInt32 * qPow(10,-2);
            QString Y5MAIN_INSStrDis = QString::number(Y5MAIN_INS,'f',2);
            ui->tableWidget_4->setItem(1,4,new QTableWidgetItem(Y5MAIN_INSStrDis));
            ui->tableWidget_4->item(1,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z5MAIN_INS***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z5MAIN_INSStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z5MAIN_INSInt32 = qint16(Z5MAIN_INSStr.toUInt(nullptr,16));
            qreal Z5MAIN_INS = Z5MAIN_INSInt32 * qPow(10,-2);
            QString Z5MAIN_INSStrDis = QString::number(Z5MAIN_INS,'f',2);
            ui->tableWidget_4->setItem(2,4,new QTableWidgetItem(Z5MAIN_INSStrDis));
            ui->tableWidget_4->item(2,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X6ACC*******************************************/
            bufferStrTemp.remove(0,4);
            QString X6ACCStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X6ACCInt32 = qint16(X6ACCStr.toUInt(nullptr,16));
            qreal X6ACC = X6ACCInt32 * qPow(10,-2);
            QString X6ACCStrDis = QString::number(X6ACC,'f',2);
            ui->tableWidget_4->setItem(0,5,new QTableWidgetItem(X6ACCStrDis));
            ui->tableWidget_4->item(0,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y6ACC***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y6ACCStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y6ACCInt32 = qint16(Y6ACCStr.toUInt(nullptr,16));
            qreal Y6ACC = Y6ACCInt32 * qPow(10,-2);
            QString Y6ACCStrDis = QString::number(Y6ACC,'f',2);
            ui->tableWidget_4->setItem(1,5,new QTableWidgetItem(Y6ACCStrDis));
            ui->tableWidget_4->item(1,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z6ACC***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z6ACCStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z6ACCInt32 = qint16(Z6ACCStr.toUInt(nullptr,16));
            qreal Z6ACC = Z6ACCInt32 * qPow(10,-2);
            QString Z6ACCStrDis = QString::number(Z6ACC,'f',2);
            ui->tableWidget_4->setItem(2,5,new QTableWidgetItem(Z6ACCStrDis));
            ui->tableWidget_4->item(2,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************陀螺零偏温补系数数据格式0D*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == 'd')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 104)
            {
                continue;
            }
            /***************************************X陀螺零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,6);
            QString XGyroTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            C5ValueUnion.qint32Value = qint32(XGyroTempCompenCoeff0Str.toUInt(nullptr,16));
            float XGyroTempCompenCoeff0 = C5ValueUnion.floatValue;

            QString XGyroTempCompenCoeff0StrDis = QString::number(XGyroTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(0,0,new QTableWidgetItem(XGyroTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(YGyroTempCompenCoeff0Str.toUInt(nullptr,16));
            float YGyroTempCompenCoeff0 = C5ValueUnion.floatValue;

            QString YGyroTempCompenCoeff0StrDis = QString::number(YGyroTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(1,0,new QTableWidgetItem(YGyroTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(ZGyroTempCompenCoeff0Str.toUInt(nullptr,16));
            float ZGyroTempCompenCoeff0 = C5ValueUnion.floatValue;

            QString ZGyroTempCompenCoeff0StrDis = QString::number(ZGyroTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(2,0,new QTableWidgetItem(ZGyroTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XGyroTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(XGyroTempCompenCoeff1Str.toUInt(nullptr,16));
            float XGyroTempCompenCoeff1 = C5ValueUnion.floatValue;

            QString XGyroTempCompenCoeff1StrDis = QString::number(XGyroTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(0,1,new QTableWidgetItem(XGyroTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(YGyroTempCompenCoeff1Str.toUInt(nullptr,16));
            float YGyroTempCompenCoeff1 = C5ValueUnion.floatValue;

            QString YGyroTempCompenCoeff1StrDis = QString::number(YGyroTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(1,1,new QTableWidgetItem(YGyroTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(ZGyroTempCompenCoeff1Str.toUInt(nullptr,16));
            float ZGyroTempCompenCoeff1 = C5ValueUnion.floatValue;

            QString ZGyroTempCompenCoeff1StrDis = QString::number(ZGyroTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(2,1,new QTableWidgetItem(ZGyroTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XGyroTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(XGyroTempCompenCoeff2Str.toUInt(nullptr,16));
            float XGyroTempCompenCoeff2 = C5ValueUnion.floatValue;

            QString XGyroTempCompenCoeff2StrDis = QString::number(XGyroTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(0,2,new QTableWidgetItem(XGyroTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(YGyroTempCompenCoeff2Str.toUInt(nullptr,16));
            float YGyroTempCompenCoeff2 = C5ValueUnion.floatValue;

            QString YGyroTempCompenCoeff2StrDis = QString::number(YGyroTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(1,2,new QTableWidgetItem(YGyroTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(ZGyroTempCompenCoeff2Str.toUInt(nullptr,16));
            float ZGyroTempCompenCoeff2 = C5ValueUnion.floatValue;

            QString ZGyroTempCompenCoeff2StrDis = QString::number(ZGyroTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(2,2,new QTableWidgetItem(ZGyroTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XGyroTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(XGyroTempCompenCoeff3Str.toUInt(nullptr,16));
            float XGyroTempCompenCoeff3 = C5ValueUnion.floatValue;

            QString XGyroTempCompenCoeff3StrDis = QString::number(XGyroTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(0,3,new QTableWidgetItem(XGyroTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(YGyroTempCompenCoeff3Str.toUInt(nullptr,16));
            float YGyroTempCompenCoeff3 = C5ValueUnion.floatValue;

            QString YGyroTempCompenCoeff3StrDis = QString::number(YGyroTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(1,3,new QTableWidgetItem(YGyroTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(ZGyroTempCompenCoeff3Str.toUInt(nullptr,16));
            float ZGyroTempCompenCoeff3 = C5ValueUnion.floatValue;

            QString ZGyroTempCompenCoeff3StrDis = QString::number(ZGyroTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(2,3,new QTableWidgetItem(ZGyroTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************陀螺零偏温补系数数据格式0E*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '0' && bufferStr[5] == 'e')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 104)
            {
                continue;
            }
            /***************************************X加速度计零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,6);
            QString XAccelerTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(XAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
            float XAccelerTempCompenCoeff0 = C5ValueUnion.floatValue;

            QString XAccelerTempCompenCoeff0StrDis = QString::number(XAccelerTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(3,0,new QTableWidgetItem(XAccelerTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(3,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(YAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
            float YAccelerTempCompenCoeff0 = C5ValueUnion.floatValue;

            QString YAccelerTempCompenCoeff0StrDis = QString::number(YAccelerTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(4,0,new QTableWidgetItem(YAccelerTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(4,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(ZAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
            float ZAccelerTempCompenCoeff0 = C5ValueUnion.floatValue;

            QString ZAccelerTempCompenCoeff0StrDis = QString::number(ZAccelerTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(5,0,new QTableWidgetItem(ZAccelerTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(5,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XAccelerTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(XAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
            float XAccelerTempCompenCoeff1 = C5ValueUnion.floatValue;

            QString XAccelerTempCompenCoeff1StrDis = QString::number(XAccelerTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(3,1,new QTableWidgetItem(XAccelerTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(3,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(YAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
            float YAccelerTempCompenCoeff1 = C5ValueUnion.floatValue;

            QString YAccelerTempCompenCoeff1StrDis = QString::number(YAccelerTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(4,1,new QTableWidgetItem(YAccelerTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(4,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(ZAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
            float ZAccelerTempCompenCoeff1 = C5ValueUnion.floatValue;

            QString ZAccelerTempCompenCoeff1StrDis = QString::number(ZAccelerTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(5,1,new QTableWidgetItem(ZAccelerTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(5,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XAccelerTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(XAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
            float XAccelerTempCompenCoeff2 = C5ValueUnion.floatValue;

            QString XAccelerTempCompenCoeff2StrDis = QString::number(XAccelerTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(3,2,new QTableWidgetItem(XAccelerTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(3,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(YAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
            float YAccelerTempCompenCoeff2 = C5ValueUnion.floatValue;

            QString YAccelerTempCompenCoeff2StrDis = QString::number(YAccelerTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(4,2,new QTableWidgetItem(YAccelerTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(4,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            C5ValueUnion.qint32Value = qint32(ZAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
            float ZAccelerTempCompenCoeff2 = C5ValueUnion.floatValue;

            QString ZAccelerTempCompenCoeff2StrDis = QString::number(ZAccelerTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(5,2,new QTableWidgetItem(ZAccelerTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(5,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XAccelerTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(XAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
            float XAccelerTempCompenCoeff3 = C5ValueUnion.floatValue;

            QString XAccelerTempCompenCoeff3StrDis = QString::number(XAccelerTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(3,3,new QTableWidgetItem(XAccelerTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(3,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            C5ValueUnion.qint32Value = qint32(YAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
            float YAccelerTempCompenCoeff3 = C5ValueUnion.floatValue;

            QString YAccelerTempCompenCoeff3StrDis = QString::number(YAccelerTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(4,3,new QTableWidgetItem(YAccelerTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(4,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);

            C5ValueUnion.qint32Value = qint32(ZAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
            float ZAccelerTempCompenCoeff3 = C5ValueUnion.floatValue;

            QString ZAccelerTempCompenCoeff3StrDis = QString::number(ZAccelerTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(5,3,new QTableWidgetItem(ZAccelerTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(5,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************系统高度数据格式D7*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '1' && bufferStr[5] == '1')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 16)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************系统高度***********************************************/
            QString sysHeightStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 sysHeightInt32 = qint32(sysHeightStr.toUInt(nullptr,16));
            qreal sysHeight = sysHeightInt32 * 100000.0*qPow(2,-31);
            QString sysHeightStrDis = QString::number(sysHeight,'f',5);
            ui->tableWidget_9->setItem(0,0,new QTableWidgetItem(sysHeightStrDis));
            ui->tableWidget_9->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

        /********************************************************系统基准重力值D8*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '1' && bufferStr[5] == '2')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 16)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************系统基准重力值***********************************************/
            QString sysGravityStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            quint32 sysGravityInt32 = quint32(sysGravityStr.toUInt(nullptr,16));
            //quint64 sysGravityInt32 = quint64(sysGravityStr.toULongLong(nullptr,16));
            qreal sysGravity = sysGravityInt32 *qPow(2,-32)*100.0;
            QString sysGravityStrDis = QString::number(sysGravity,'f',8);
            ui->tableWidget_9->setItem(0,1,new QTableWidgetItem(sysGravityStrDis));
            ui->tableWidget_9->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

        /********************************************************系统DVL标度*******************************************************************/
        else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&&bufferStr[4] == '1' && bufferStr[5] == '6')
        {
            QString bufferStrTemp = bufferStr;
            if(bufferStrTemp.size() != 20)
            {
                continue;
            }
            bufferStrTemp.remove(0,6);
            /***************************************系统DVL-X标度***********************************************/
            QString DVLXStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            quint16 DVLXInt16 = quint16(DVLXStr.toUInt(nullptr,16));
            qreal DVLX = DVLXInt16 *qPow(10,-4);
            QString DVLXStrDis = QString::number(DVLX,'f',4);
            ui->tableWidget_11->setItem(0,0,new QTableWidgetItem(DVLXStrDis));
            ui->tableWidget_11->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            bufferStrTemp.remove(0,4);
            /***************************************系统DVL-Y标度***********************************************/
            QString DVLYStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            quint16 DVLYInt16 = quint16(DVLYStr.toUInt(nullptr,16));
            qreal DVLY = DVLYInt16 *qPow(10,-4);
            QString DVLYStrDis = QString::number(DVLY,'f',4);
            ui->tableWidget_11->setItem(0,1,new QTableWidgetItem(DVLYStrDis));
            ui->tableWidget_11->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            bufferStrTemp.remove(0,4);
            /***************************************系统DVL-Z标度***********************************************/
            QString DVLZStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            quint16 DVLZInt16 = quint16(DVLZStr.toUInt(nullptr,16));
            qreal DVLZ = DVLZInt16 *qPow(10,-4);
            QString DVLZStrDis = QString::number(DVLZ,'f',4);
            ui->tableWidget_11->setItem(0,2,new QTableWidgetItem(DVLZStrDis));
            ui->tableWidget_11->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

    }
    /******************************************调试信息，打印报文*******************************************/
    if(ui->action->isChecked() == true)
    {
        if(datanum < 20)
        {
            QString displayStr = dateStr+"\n"+QString(result).toUpper()+"\n";

            //从界面中读取以前收到的数据
            QString oldString = ui->browser_dataReceive->toPlainText();
            oldString = oldString + QString(displayStr);
            //清空以前的显示
            ui->browser_dataReceive->clear();
            //重新显示
            ui->browser_dataReceive->append(oldString);
            datanum++;
        }
        else
        {
            ui->browser_dataReceive->clear();
             QString displayStr = dateStr+"\n"+QString(result).toUpper()+"\n";
             ui->browser_dataReceive->append(displayStr);
             datanum = 0;
        }
    }

    result.clear();

}
void MainWindow::on_btn_openPort_clicked()
{
    restartTime = 0;

    if(ui->btn_openPort->text()==QString("打开串口"))
    {
        //设置串口名
        QString portName = (ui->box_portName->currentText()).split(":").at(0);
        serial_1 = new QextSerialPort(portName);

        if(serial_1->open(QIODevice::ReadWrite))
        {

            if(1)
            {
                fileSaveNum = 1;
                QString fileSaveNumStr = QString::number(fileSaveNum,10);
                QDateTime current_date_time =QDateTime::currentDateTime();
                QString dateStr =current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
                QString C1HisDataName = "./history/nav1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
                QString C2HisDataName = "./history/cond1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
                QString C3HisDataName = "./history/ref1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
                QString C5HisDataName = "./history/imu1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
                QString C6HisDataName = "./history/calInfo1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
                QString C8HisDataName = "./history/addInfo1s_"+ dateStr+"_"+fileSaveNumStr+".csv";

                C1fileSave.setFileName(C1HisDataName);
                if(!C1fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C1文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC1(&C1fileSave);
                //QString headStr1 = "时间序号,标识号,系统时间,状态时间,纬度°,经度°,东速kn,北速kn,航向角°,横摇角°,纵摇角°,航向角速度°/s,横摇角速度°/s,纵摇角速度°/s,垂荡m,垂速m/s,横荡m,横速m/s,纵荡m,纵速m/s,导航信息有效位,系统状态,时码,参考纬度°,参考经度°,参考组合东速kn,参考组合北速kn,参考阻尼东速kn,参考阻尼北速kn,参考航向°,参考信息有效位";

                //QString headStr1 = "时间序号,标识号,系统时间,状态时间,纬度°,经度°,东速kn,北速kn,航向角°,横摇角°,纵摇角°,航向角速度°/s,横摇角速度°/s,纵摇角速度°/s,垂荡m,垂速m/s,横荡m,横速m/s,纵荡m,纵速m/s,时码有效,经纬度有效,东北速有效,航向有效,纵横摇有效,角速度有效,升沉有效,纵横荡有效,导航状态,工作位置,切换模式,时码,参考纬度°,参考经度°,参考组合东速kn,参考组合北速kn,参考阻尼东速kn,参考阻尼北速kn,参考航向°,参考经纬度,参考组合速度,参考阻尼,参考航向";
                //dataOutC1<<headStr1.toUtf8();

                C2fileSave.setFileName(C2HisDataName);
                if(!C2fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C2文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC2(&C2fileSave);
                //QString headStr2 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到陀螺标定参数,收到加速度计标定参数,收到陀螺零偏温补系数,收到加速度计零位温补系数,收到装订航向,收到等效零偏,收到漂移补偿,收到状态切换命令,收到系统姿态零位,收到惯组和输出姿态零位,收到杆臂,收到显控参考信息,收到1PPS信号,收到录取同步信号,收到主惯导信息,收到系统编号,收到在舰位置,收到IP地址,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GX漂移估计补偿,GY漂移估计补偿,GZ漂移估计补偿,AX零偏估计补偿,AY零偏估计补偿,AZ零偏估计补偿,水平姿态误差估计补偿,航向误差估计补偿,速度误差估计补偿,位置误差估计补偿,直航状态,静止状态,锚泊状态,振动状态,冲击状态,主惯导位置有效,主惯导速度有效,主惯导姿态有效,主惯导角速度有效,陀螺故障,加速度计故障,IF板故障,采集板故障,通信板故障,接口板故障,解算异常故障,备用电源故障,GX陀螺常值漂移°/h,GY陀螺常值漂移°/h,GZ陀螺常值漂移°/h,AX加速度计零偏mg,AY加速度计零偏mg,AZ加速度计零偏mg";
                // QString headStr2 = "时间序号,标识号,系统时间,信息传输标识,信息有效标识,故障码,GX陀螺常值漂移°/h,GY陀螺常值漂移°/h,GZ陀螺常值漂移°/h,AX加速度计零偏mg,AY加速度计零偏mg,AZ加速度计零偏mg";

                // dataOutC2<<headStr2.toUtf8();

                C3fileSave.setFileName(C3HisDataName);
                if(!C3fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C3文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC3(&C3fileSave);
                //QString headStr3 = "时间序号,标识号,系统时间,信息收到标识,信息有效标识,GPS纬度°,GPS经度°,GPS合速kn,GPS航向°,GPS东速kn,GPS北速kn,电磁速度kn,多普勒对水横向速度kn,多普勒对水纵向速度kn,多普勒对底横向速度kn,多普勒对底纵向速度kn,时码：日月年,时码：天秒s,插值时间us,GPS卫星数,GPS水平精度因子";

                //QString headStr3 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到1PPS信号,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GPS纬度°,GPS经度°,GPS合速kn,GPS航向°,GPS东速kn,GPS北速kn,电磁速度kn,多普勒对水横向速度kn,多普勒对水纵向速度kn,多普勒对底横向速度kn,多普勒对底纵向速度kn,时码：日月年,时码：天秒s,插值时间us,GPS卫星数,GPS水平精度因子";
                //dataOutC3<<headStr3.toUtf8();

                C5fileSave.setFileName(C5HisDataName);
                if(!C5fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C5文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC5(&C5fileSave);
                //QString headStr5 = "时间序号,标识号,系统时间,X陀螺1s角增量°/h,Y陀螺1s角增量°/h,Z陀螺1s角增量°/h,X加速度计1s速度增量m/s/s,Y加速度计1s速度增量m/s/s,Z加速度计1s速度增量m/s/s,X陀螺1s补偿后角增量°/h,Y陀螺1s补偿后角增量°/h,Z陀螺1s补偿后角增量°/h,X加速度计1s补偿后速度增量m/s/s,Y加速度计1s补偿后速度增量m/s/s,Z加速度计1s补偿后速度增量m/s/s,X陀螺差频p/s,Y陀螺差频p/s,Z陀螺差频p/s,X加速度计差频p/s,Y加速度计差频p/s,Z加速度计差频p/s,X陀螺抖幅p/s,Y陀螺抖幅p/s,Z陀螺抖幅p/s,X陀螺抖频Hz,Y陀螺抖频Hz,Z陀螺抖频Hz,X陀螺温度1°C,X陀螺温度2°C,Y陀螺温度1°C,Y陀螺温度2°C,Z陀螺温度1°C,Z陀螺温度2°C,IF板温度°C,X加速度计温度°C,Y加速度计温度°C,Z加速度计温度°C,采集板温度°C";

                //QString headStr5 = "时间序号,标识号,系统时间,X陀螺1s角增量°/h,Y陀螺1s角增量°/h,Z陀螺1s角增量°/h,X加速度计1s速度增量m/s/s,Y加速度计1s速度增量m/s/s,Z加速度计1s速度增量m/s/s,X陀螺1s补偿后角增量°/h,Y陀螺1s补偿后角增量°/h,Z陀螺1s补偿后角增量°/h,X加速度计1s补偿后速度增量m/s/s,Y加速度计1s补偿后速度增量m/s/s,Z加速度计1s补偿后速度增量m/s/s,X陀螺差频p/s,Y陀螺差频p/s,Z陀螺差频p/s,X加速度计差频p/s,Y加速度计差频p/s,Z加速度计差频p/s,X陀螺抖幅p/s,Y陀螺抖幅p/s,Z陀螺抖幅p/s,X陀螺抖频Hz,Y陀螺抖频Hz,Z陀螺抖频Hz,X陀螺温度1°C,X陀螺温度2°C,Y陀螺温度1°C,Y陀螺温度2°C,Z陀螺温度1°C,Z陀螺温度2°C,IF板温度°C,X加速度计温度°C,Y加速度计温度°C,Z加速度计温度°C,采集板温度°C";
                //dataOutC5<<headStr5.toUtf8();

                C6fileSave.setFileName(C6HisDataName);
                if(!C6fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C5文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC6(&C6fileSave);

                C8fileSave.setFileName(C8HisDataName);
                if(!C8fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C5文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC8(&C8fileSave);
            }

            //清空缓冲区
            serial_1->flush();
            //设置波特率
            serial_1->setBaudRate((BaudRateType)ui->box_baudrate->currentText().toInt());

            //设置停止位
            if(ui->box_stopBit->currentText() == "1")
                serial_1->setStopBits(STOP_1);
            else if(ui->box_stopBit->currentText() == "1.5")
                serial_1->setStopBits(STOP_1_5);
            else if(ui->box_stopBit->currentText() == "2")
                serial_1->setStopBits(STOP_2);

            //设置数据位数
            if(ui->box_dataBits->currentText() == "8")
                serial_1->setDataBits(DATA_8);
            else if(ui->box_dataBits->currentText() == "7")
                serial_1->setDataBits(DATA_7);
            else if(ui->box_dataBits->currentText() == "6")
                serial_1->setDataBits(DATA_6);
            else if(ui->box_dataBits->currentText() == "5")
                serial_1->setDataBits(DATA_5);

            //设置奇偶校验
            if(ui->box_parityBit->currentText() == "None")
                serial_1->setParity(PAR_NONE);
            else if(ui->box_parityBit->currentText() == "Even")
                serial_1->setParity(PAR_EVEN);
            else if(ui->box_parityBit->currentText() == "Odd")
                serial_1->setParity(PAR_ODD);

            //设置流控制
            serial_1->setFlowControl(FLOW_OFF);

            //下拉菜单控件失能
            ui->box_portName->setEnabled(false);
            ui->box_baudrate->setEnabled(false);
            ui->box_dataBits->setEnabled(false);
            ui->box_parityBit->setEnabled(false);
            ui->box_stopBit->setEnabled(false);

            ui->btn_openPort->setText(QString("关闭串口"));
            ui->lineEdit_47->setText("0.0000m");
            ui->lineEdit_48->setText("0.0000m");
            ui->lineEdit_45->setText("0.0000kn");
            ui->lineEdit_53->setText("0.0000kn");
            ui->lineEdit_46->setText("0.0000m");
            ui->lineEdit_50->setText("0.0000kn");
            ui->lineEdit_51->setText("0.0000kn");
            ui->lineEdit_52->setText("0.0000kn");
            ui->lineEdit_54->setText("0.0000m");
            ui->lineEdit_55->setText("0.0000m");
            this->setLED1(ui->label_69,2,15);
            serial_1->setTimeout(10);
            qtime->start();
            qDrawTime->start();

        }
        else
        {
            QMessageBox::about(NULL, "提示", "无法打开串口！");
            return;
        }
    }
    else
    {

        //关闭串口
        serial_1->close();
        //InitClear();
        C1fileSave.close();
        C2fileSave.close();
        C3fileSave.close();
        C5fileSave.close();
        C6fileSave.close();
        C8fileSave.close();

        this->setLED1(ui->label_69,1,15);
        //下拉菜单控件使能
        ui->box_portName->setEnabled(true);
        ui->box_baudrate->setEnabled(true);
        ui->box_dataBits->setEnabled(true);
        ui->box_parityBit->setEnabled(true);
        ui->box_stopBit->setEnabled(true);
        qDrawTime->stop();

        qtime->stop();
        ui->btn_openPort->setText(QString("打开串口"));
        ui->lineEdit_7->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_8->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_7	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_8	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_9	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_10	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_11	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_12	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_13	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_14	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_15	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_16	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_17	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_18	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_19	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_20	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_21	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_22	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_23	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_24	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_25	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_26	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_27	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_28	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_29	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_30	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_31	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_32	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_33	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_34	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_35	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_36	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_37	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_38	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_39	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_40	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_41	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_42	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_43	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_44	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_49	->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_47 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_48 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_51 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_52 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_54 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_55 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_50 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_46 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_45 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->lineEdit_53 ->setStyleSheet("color: rgb(0, 0, 0);");
        ui->label_16->setStyleSheet("font:bold;color:Red");
        ui->label_17->setStyleSheet("font:bold;color:Red");
        ui->label_25->setStyleSheet("font:bold;color:Red");
        ui->label_27->setStyleSheet("font:bold;color:Red");
        ui->label_28->setStyleSheet("font:bold;color:Red");
        ui->label_53->setStyleSheet("font:bold;color:Red");
        ui->label_55->setStyleSheet("font:bold;color:Red");

    }
}

/*
 * @breif 串口开始前界面数据清零
 */
void MainWindow::InitClear()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_30->clear();
    ui->lineEdit_24->clear();
    ui->lineEdit_25->clear();
    ui->lineEdit_26->clear();
    ui->lineEdit_28->clear();
    ui->lineEdit_27->clear();
    ui->lineEdit_29->clear();
    ui->lineEdit_31->clear();
    ui->lineEdit_32->clear();
    ui->lineEdit_33->clear();
    ui->lineEdit_34->clear();
    ui->lineEdit_35->clear();
    ui->lineEdit_36->clear();
    ui->lineEdit_37->clear();
    ui->lineEdit_38->clear();
    ui->lineEdit_39->clear();
    ui->lineEdit_40->clear();
    ui->lineEdit_41->clear();
    ui->lineEdit_42->clear();
    ui->lineEdit_43->clear();
    ui->lineEdit_44->clear();
    ui->lineEdit_49->clear();
    ui->lineEdit_47->clear();
    ui->lineEdit_48->clear();
    ui->lineEdit_51->clear();
    ui->lineEdit_52->clear();
    ui->lineEdit_54->clear();
    ui->lineEdit_55->clear();
    ui->lineEdit_50->clear();
    ui->lineEdit_46->clear();
    ui->lineEdit_45->clear();
    ui->lineEdit_53->clear();
      latitude=0;
    headingAngle=0;
    longitude=0;
    rollAngle=0;
    pitchAngle=0;
    northSpeed=0;
    eastSpeed=0;
    headingAngularSpeed=0;
    rollAngleSpeed=0;
    pitchAngleSpeed=0;
    heave=0;
    verticalVelocity=0;
    sway=0;
    transverseVelocity=0;
    surge=0;
    longitudinalVelocity=0;
    C5XGyroAngleIncreaseFloat=0;
    C5YGyroAngleIncreaseFloat=0;
    C5ZGyroAngleIncreaseFloat=0;
    C5XAccelerometerSpeedIncrementFloat=0;
    C5YAccelerometerSpeedIncrementFloat=0;
    C5ZAccelerometerSpeedIncrementFloat=0;
    C5XgyroCompensatedAngleIncrementFloat=0;
    C5YgyroCompensatedAngleIncrementFloat=0;
    C5ZgyroCompensatedAngleIncrementFloat=0;
    C5XAccVelocityIncrementFloat=0;
    C5YAccVelocityIncrementFloat=0;
    C5ZAccVelocityIncrementFloat=0;
    C5XgyroDifFrequency=0;
    C5YgyroDifFrequency=0;
    C5ZgyroDifFrequency=0;
    C5XaccelerometerDifFre=0;
    C5YaccelerometerDifFre=0;
    C5ZaccelerometerDifFre=0;
    C5XgyroTemp1=0;
    C5YgyroTemp1=0;
    C5ZgyroTemp1=0;
    C5XAccelerometerTemperture=0;
    C5YAccelerometerTemperture=0;
    C5ZAccelerometerTemperture=0;
    C5XgyroTemp2=0;
    C5YgyroTemp2=0;
    C5ZgyroTemp2=0;
    C5XgyroAmplitudeJitter=0;
    C5YgyroAmplitudeJitter=0;
    C5ZgyroAmplitudeJitter=0;
    C5XgyroAmpl1itudeFre=0;
    C5YgyroAmpl1itudeFre=0;
    C5ZgyroAmpl1itudeFre=0;
    C3longitude=0;
    C3GPSlatitude=0;
    C3togetherSpeed=0;
    C3headingAngle=0;
    C3combinedEastSpeed=0;
    C3combinedNorthSpeed=0;
    C3waterX=0;
    C3waterY=0;
    C3bottomX=0;
    C3bottomY=0;
    C3electromagnetismSpeed=0;
    C6XGroyFloat=0;
    C6YGroyFloat=0;
    C6ZGroyFloat=0;
    C6XAccelerometerFloat=0;
    C6YAccelerometerFloat=0;
    C6ZAccelerometerFloat=0;
    eastSpeedError=0;
    northSpeedError=0;
    togetherSpeedError=0;
    latitudeError=0;
    longitudeError=0;
    positionError=0;
    C8UpSpeed = 0;
    C8Height = 0;
    QVector<double> a;
    m_xLength = 0;
    QVector<double>().swap(C1Vlongitude);
    QVector<double>().swap(C1Vlongitude_bk);

    QVector<double>().swap(curveX);
    QVector<double>().swap(C1Vlatitude);
    QVector<double>().swap(C1Vlatitude_bk);
    QVector<double>().swap(C1VheadingAngle);
    QVector<double>().swap(C1VheadingAngle_bk);
    QVector<double>().swap(C1VrollAngle);
    QVector<double>().swap(C1VrollAngle_bk);
    QVector<double>().swap(C1VpitchAngle);
    QVector<double>().swap(C1VpitchAngle_bk);
    QVector<double>().swap(C1VnorthSpeed);
    QVector<double>().swap(C1VnorthSpeed_bk);

    QVector<double>().swap(C1VeastSpeed);
    QVector<double>().swap(C1VeastSpeed_bk);
    QVector<double>().swap(C1VrollAngleSpeed);
    QVector<double>().swap(C1VrollAngleSpeed_bk);
    QVector<double>().swap(C1VpitchAngleSpeed);
    QVector<double>().swap(C1VpitchAngleSpeed_bk);
    QVector<double>().swap(C1Vheave);
    QVector<double>().swap(C1Vheave_bk);
    QVector<double>().swap(C1VverticalVelocity);
    QVector<double>().swap(C1VverticalVelocity_bk);
    QVector<double>().swap(C1VheadingAngularSpeed);
    QVector<double>().swap(C1VheadingAngularSpeed_bk);

    QVector<double>().swap(C1Vsway);
    QVector<double>().swap(C1Vsway_bk);
    QVector<double>().swap(C1VtransverseVelocity);
    QVector<double>().swap(C1VtransverseVelocity_bk);
    QVector<double>().swap(C1Vsurge);
    QVector<double>().swap(C1Vsurge_bk);
    QVector<double>().swap(C1VlongitudinalVelocity);
    QVector<double>().swap(C1VlongitudinalVelocity_bk);
    QVector<double>().swap(C5VXGyroAngleIncreaseFloat);
    QVector<double>().swap(C5VXGyroAngleIncreaseFloat_bk);
    QVector<double>().swap(C5VYGyroAngleIncreaseFloat);
    QVector<double>().swap(C5VYGyroAngleIncreaseFloat_bk);

    QVector<double>().swap(C5VZGyroAngleIncreaseFloat);
    QVector<double>().swap(C5VZGyroAngleIncreaseFloat_bk);
    QVector<double>().swap(C5VXAccelerometerSpeedIncrementFloat);
    QVector<double>().swap(C5VXAccelerometerSpeedIncrementFloat_bk);
    QVector<double>().swap(C5VYAccelerometerSpeedIncrementFloat);
    QVector<double>().swap(C5VYAccelerometerSpeedIncrementFloat_bk);
    QVector<double>().swap(C5VZAccelerometerSpeedIncrementFloat);
    QVector<double>().swap(C5VZAccelerometerSpeedIncrementFloat_bk);
    QVector<double>().swap(C5VXgyroCompensatedAngleIncrementFloat);
    QVector<double>().swap(C5VXgyroCompensatedAngleIncrementFloat_bk);
    QVector<double>().swap(C5VYgyroCompensatedAngleIncrementFloat);
    QVector<double>().swap(C5VYgyroCompensatedAngleIncrementFloat_bk);
    QVector<double>().swap(C5VZgyroCompensatedAngleIncrementFloat);
    QVector<double>().swap(C5VZgyroCompensatedAngleIncrementFloat_bk);
    QVector<double>().swap(C5VXAccVelocityIncrementFloat);
    QVector<double>().swap(C5VXAccVelocityIncrementFloat_bk);
    QVector<double>().swap(C5VYAccVelocityIncrementFloat);
    QVector<double>().swap(C5VYAccVelocityIncrementFloat_bk);

    QVector<double>().swap(C5VZAccVelocityIncrementFloat);
    QVector<double>().swap(C5VZAccVelocityIncrementFloat_bk);
    QVector<double>().swap(C5VXgyroDifFrequency);
    QVector<double>().swap(C5VXgyroDifFrequency_bk);
    QVector<double>().swap(C5VYgyroDifFrequency);
    QVector<double>().swap(C5VYgyroDifFrequency_bk);
    QVector<double>().swap(C5VZgyroDifFrequency);
    QVector<double>().swap(C5VZgyroDifFrequency_bk);
    QVector<double>().swap(C5VXaccelerometerDifFre);
    QVector<double>().swap(C5VXaccelerometerDifFre_bk);
    QVector<double>().swap(C5VYaccelerometerDifFre);
    QVector<double>().swap(C5VYaccelerometerDifFre_bk);
    QVector<double>().swap(C5VZaccelerometerDifFre);
    QVector<double>().swap(C5VZaccelerometerDifFre_bk);
    QVector<double>().swap(C5VXgyroTemp1);
    QVector<double>().swap(C5VXgyroTemp1_bk);
    QVector<double>().swap(C5VYgyroTemp1);
    QVector<double>().swap(C5VYgyroTemp1_bk);
    QVector<double>().swap(C5VZgyroTemp1);
    QVector<double>().swap(C5VZgyroTemp1_bk);

    QVector<double>().swap(C5VXAccelerometerTemperture);
    QVector<double>().swap(C5VXAccelerometerTemperture_bk);
    QVector<double>().swap(C5VYAccelerometerTemperture);
    QVector<double>().swap(C5VYAccelerometerTemperture_bk);
    QVector<double>().swap(C5VZAccelerometerTemperture);
    QVector<double>().swap(C5VZAccelerometerTemperture_bk);
    QVector<double>().swap(C5VXgyroTemp2);
    QVector<double>().swap(C5VXgyroTemp2_bk);
    QVector<double>().swap(C5VYgyroTemp2);
    QVector<double>().swap(C5VYgyroTemp2_bk);
    QVector<double>().swap(C5VZgyroTemp2);
    QVector<double>().swap(C5VZgyroTemp2_bk);
    QVector<double>().swap(C5VXgyroAmplitudeJitter);
    QVector<double>().swap(C5VXgyroAmplitudeJitter_bk);
    QVector<double>().swap(C5VYgyroAmplitudeJitter);
    QVector<double>().swap(C5VYgyroAmplitudeJitter_bk);

    QVector<double>().swap(C5VZgyroAmplitudeJitter);
    QVector<double>().swap(C5VZgyroAmplitudeJitter_bk);

    QVector<double>().swap(C5VXgyroAmpl1itudeFre);
    QVector<double>().swap(C5VXgyroAmpl1itudeFre_bk);

    QVector<double>().swap(C5VYgyroAmpl1itudeFre);
    QVector<double>().swap(C5VYgyroAmpl1itudeFre_bk);

    QVector<double>().swap(C5VZgyroAmpl1itudeFre);
    QVector<double>().swap(C5VZgyroAmpl1itudeFre_bk);

    QVector<double>().swap(C3Vlongitude);
    QVector<double>().swap(C3Vlongitude_bk);

    QVector<double>().swap(C3VGPSlatitude);
    QVector<double>().swap(C3VGPSlatitude_bk);

    QVector<double>().swap(C3VtogetherSpeed);
    QVector<double>().swap(C3VtogetherSpeed_bk);

    QVector<double>().swap(C3VheadingAngle);
    QVector<double>().swap(C3VheadingAngle_bk);

    QVector<double>().swap(C3VcombinedEastSpeed);
    QVector<double>().swap(C3VcombinedEastSpeed_bk);

    QVector<double>().swap(C3VcombinedNorthSpeed);
    QVector<double>().swap(C3VcombinedNorthSpeed_bk);


    QVector<double>().swap(C3VwaterX);
    QVector<double>().swap(C3VwaterX_bk);
    QVector<double>().swap(C3VwaterY);
    QVector<double>().swap(C3VwaterY_bk);
    QVector<double>().swap(C3VbottomX);
    QVector<double>().swap(C3VbottomX_bk);
    QVector<double>().swap(C3VbottomY);
    QVector<double>().swap(C3VbottomY_bk);
    QVector<double>().swap(C3VelectromagnetismSpeed);
    QVector<double>().swap(C3VelectromagnetismSpeed_bk);

    QVector<double>().swap(C6VC6XGroyFloat);
    QVector<double>().swap(C6VC6XGroyFloat_bk);
    QVector<double>().swap(C6VC6YGroyFloat);
    QVector<double>().swap(C6VC6YGroyFloat_bk);
    QVector<double>().swap(C6VC6ZGroyFloat);
    QVector<double>().swap(C6VC6ZGroyFloat_bk);

    QVector<double>().swap(C6VC6XAccelerometerFloat);
    QVector<double>().swap(C6VC6XAccelerometerFloat_bk);

    QVector<double>().swap(C6VC6YAccelerometerFloat);
    QVector<double>().swap(C6VC6YAccelerometerFloat_bk);

    QVector<double>().swap(C6VC6ZAccelerometerFloat);
    QVector<double>().swap(C6VC6ZAccelerometerFloat_bk);
    QVector<double>().swap(VeastSpeedError);
    QVector<double>().swap(VeastSpeedError_bk);
    QVector<double>().swap(VnorthSpeedError);
    QVector<double>().swap(VnorthSpeedError_bk);

    QVector<double>().swap(VtogetherSpeedError);
    QVector<double>().swap(VtogetherSpeedError_bk);

    QVector<double>().swap(VlatitudeError_bk);
    QVector<double>().swap(VlatitudeError);

    QVector<double>().swap(VlongitudeError_bk);
    QVector<double>().swap(VlongitudeError);

    QVector<double>().swap(VpositionError);
    QVector<double>().swap(VpositionError_bk);

    QVector<double>().swap(C8VC8Height);
    QVector<double>().swap(C8VC8Height_bk);
    QVector<double>().swap(C8VC8UpSpeed);
    QVector<double>().swap(C8VC8UpSpeed_bk);

    QVector<double>().swap(C8VC8GPSHeight);
    QVector<double>().swap(C8VC8GPSHeight_bk);
    QVector<double>().swap(C8VC8GPTUpSpeed);
    QVector<double>().swap(C8VC8GPTUpSpeed_bk);
    QVector<double>().swap(C8VC8LogDownSpeed2Ground);
    QVector<double>().swap(C8VC8LogDownSpeed2Ground_bk);
    QVector<double>().swap(C8VC8LogDownSpeed2Water);
    QVector<double>().swap(C8VC8LogDownSpeed2Water_bk);


}

//曲线图初始化
void MainWindow::init_darw2()
{
    QCustomPlot* customPlot = ui->customPlot2;
    connect(customPlot,&QCustomPlot::mouseDoubleClick,this,&MainWindow::on_pushButton_15_clicked);
    connect(ui->customPlot3,&QCustomPlot::mouseDoubleClick,this,&MainWindow::resetY);
    //四边安上坐标轴
    customPlot->axisRect()->setupFullAxesBox();
    customPlot->setBackground(QColor(220,220,220));
    // 使上下轴、左右轴范围同步
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));


//    QLinearGradient axisRectGradient;
//    axisRectGradient.setStart(0, 0);
//    axisRectGradient.setFinalStop(0, 350);
//    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
//    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
//    customPlot->axisRect()->setBackground(axisRectGradient);   // 设置QCPAxisRect背景颜色

    customPlot->xAxis->setBasePen(QPen(Qt::white, 1));  // 轴线的画笔
    customPlot->xAxis->setTickPen(QPen(Qt::white, 1));  // 轴刻度线的画笔
    customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1)); // 轴子刻度线的画笔
    customPlot->xAxis->setTickLabelColor(Qt::black);  // 轴刻度文字颜色
//    customPlot->xAxis->setLabel("标签");  // 只有设置了标签，轴标签的颜色才会显示
//    customPlot->xAxis->setLabelColor(Qt::white);   // 轴标签颜色
    customPlot->xAxis->setTickLengthIn(3);       // 轴线内刻度的长度
    customPlot->xAxis->setTickLengthOut(5);      // 轴线外刻度的长度
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);  // 设置轴线结束时的风格为 实角三角形但内部有凹陷的形状， setLowerEnding设置轴线开始时的风格


    customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));     // 网格线(对应刻度)画笔
    customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine)); // 子网格线(对应子刻度)画笔
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridVisible(true);     // 显示子网格线
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->xAxis->grid()->setZeroLinePen(QPen(Qt::black));   // 设置刻度为0时的网格线的画笔
    customPlot->yAxis->grid()->setZeroLinePen(QPen(Qt::black));
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


    customPlot->selectionRect()->setPen(QPen(Qt::black,1,Qt::DashLine));//设置选框的样式：虚线
    customPlot->selectionRect()->setBrush(QBrush(QColor(0,0,100,50)));//设置选框的样式：半透明浅蓝
    customPlot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);


    QCustomPlot* customPlot2 = ui->customPlot3;
    customPlot2->clearGraphs();
    //四边安上坐标轴
    customPlot2->axisRect()->setupFullAxesBox();
    customPlot2->setBackground(QColor(220,220,220));
    // 使上下轴、左右轴范围同步
    //connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    //connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
   // QLinearGradient axisRectGradient;
    //axisRectGradient.setStart(0, 0);
//        axisRectGradient.setFinalStop(0, 350);
//        axisRectGradient.setColorAt(0, QColor(80, 80, 80));
//        axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    //customPlot->axisRect()->setBackground(axisRectGradient);   // 设置QCPAxisRect背景颜色
    customPlot2->xAxis->setBasePen(QPen(Qt::white, 1));  // 轴线的画笔
    customPlot2->xAxis->setTickPen(QPen(Qt::white, 1));  // 轴刻度线的画笔
    customPlot2->xAxis->setSubTickPen(QPen(Qt::white, 1)); // 轴子刻度线的画笔
    customPlot2->xAxis->setTickLabelColor(Qt::black);  // 轴刻度文字颜色
//  customPlot->xAxis->setLabel("标签");  // 只有设置了标签，轴标签的颜色才会显示
//  customPlot->xAxis->setLabelColor(Qt::white);   // 轴标签颜色
    customPlot2->xAxis->setTickLengthIn(3);       // 轴线内刻度的长度
    customPlot2->xAxis->setTickLengthOut(5);      // 轴线外刻度的长度
    customPlot2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);  // 设置轴线结束时的风格为 实角三角形但内部有凹陷的形状， setLowerEnding设置轴线开始时的风格
    customPlot2->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));     // 网格线(对应刻度)画笔
    customPlot2->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot2->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine)); // 子网格线(对应子刻度)画笔
    customPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot2->xAxis->grid()->setSubGridVisible(true);     // 显示子网格线
    customPlot2->yAxis->grid()->setSubGridVisible(true);
    customPlot2->xAxis->grid()->setZeroLinePen(QPen(Qt::black));   // 设置刻度为0时的网格线的画笔
    customPlot2->yAxis->grid()->setZeroLinePen(QPen(Qt::black));
    //customPlot2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    customPlot2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    customPlot2->selectionRect()->setPen(QPen(Qt::black,1,Qt::DashLine));//设置选框的样式：虚线
    customPlot2->selectionRect()->setBrush(QBrush(QColor(0,0,100,50)));//设置选框的样式：半透明浅蓝
    customPlot2->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);

    QFont font;
    font.setPixelSize(14);
    customPlot->xAxis->setTickLabelFont(font);
    customPlot->yAxis->setTickLabelFont(font);

    QFont font2;
    font2.setPixelSize(14);
    customPlot2->xAxis->setTickLabelFont(font2);
    customPlot2->yAxis->setTickLabelFont(font2);

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(index == 1)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(index == 2)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(index == 3)
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if(index == 4)
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(index == 5)
    {
        ui->stackedWidget->setCurrentIndex(5);
    }
    else if(index == 6)
    {
        ui->stackedWidget->setCurrentIndex(6);
    }

    else if(index == 7)
    {
        ui->stackedWidget->setCurrentIndex(7);
    }

    else if(index == 8)
    {
        ui->stackedWidget->setCurrentIndex(8);
    }

    else if(index == 9)
    {
        ui->stackedWidget->setCurrentIndex(9);
    }
    else if(index == 10)
    {
        ui->stackedWidget->setCurrentIndex(10);
    }
    else if(index == 11)
    {
        ui->stackedWidget->setCurrentIndex(11);
    }
    else if(index == 12)
    {
        ui->stackedWidget->setCurrentIndex(12);
    }
    else if(index == 13)
    {
        ui->stackedWidget->setCurrentIndex(13);
    }
    else if(index == 14)
    {
        ui->stackedWidget->setCurrentIndex(14);
    }
    else if(index == 15)
    {
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(index == 16)
    {
        ui->stackedWidget->setCurrentIndex(16);
    }
    else if(index == 17)
    {
        ui->stackedWidget->setCurrentIndex(17);
    }
    else if(index == 18)
    {
        ui->stackedWidget->setCurrentIndex(18);
    }
    else if(index == 19)
    {
        ui->stackedWidget->setCurrentIndex(19);
    }
    else if(index == 20)
    {
        ui->stackedWidget->setCurrentIndex(20);
    }
    else if(index == 21)
    {
        ui->stackedWidget->setCurrentIndex(21);
    }
    ui->checkBox->setChecked(0);
    ui->checkBox->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_2->setChecked(0);
    ui->checkBox_2->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_3->setChecked(0);
    ui->checkBox_3->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_4->setChecked(0);
    ui->checkBox_4->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_5->setChecked(0);
    ui->checkBox_5->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_6->setChecked(0);
    ui->checkBox_6->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_7->setChecked(0);
    ui->checkBox_7->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_8->setChecked(0);
    ui->checkBox_8->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_9->setChecked(0);
    ui->checkBox_9->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_10->setChecked(0);
    ui->checkBox_10->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_11->setChecked(0);
    ui->checkBox_11->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_12->setChecked(0);
    ui->checkBox_12->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_13->setChecked(0);
    ui->checkBox_13->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_14->setChecked(0);
    ui->checkBox_14->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_15->setChecked(0);
    ui->checkBox_15->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");

    ui->checkBox_16->setChecked(0);
    ui->checkBox_16->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

    ui->checkBox_17->setChecked(0);
    ui->checkBox_17->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_18->setChecked(0);
    ui->checkBox_18->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_19->setChecked(0);
    ui->checkBox_19->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_20->setChecked(0);
    ui->checkBox_20->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_21->setChecked(0);
    ui->checkBox_21->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_22->setChecked(0);
    ui->checkBox_22->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_23->setChecked(0);
    ui->checkBox_23->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_24->setChecked(0);
    ui->checkBox_24->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_25->setChecked(0);
    ui->checkBox_25->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_26->setChecked(0);
    ui->checkBox_27->setChecked(0);
    ui->checkBox_28->setChecked(0);
    ui->checkBox_29->setChecked(0);
    ui->checkBox_30->setChecked(0);
    ui->checkBox_31->setChecked(0);
    ui->checkBox_32->setChecked(0);
    ui->checkBox_33->setChecked(0);
    ui->checkBox_34->setChecked(0);
    ui->checkBox_35->setChecked(0);
    ui->checkBox_36->setChecked(0);
    ui->checkBox_37->setChecked(0);
    ui->checkBox_40->setChecked(0);
    ui->checkBox_38->setChecked(0);
    ui->checkBox_39->setChecked(0);
    ui->checkBox_42->setChecked(0);
    ui->checkBox_43->setChecked(0);
    ui->checkBox_41->setChecked(0);
    ui->checkBox_45->setChecked(0);
    ui->checkBox_46->setChecked(0);
    ui->checkBox_44->setChecked(0);
    ui->checkBox_48->setChecked(0);
    ui->checkBox_49->setChecked(0);
    ui->checkBox_47->setChecked(0);
    ui->checkBox_50->setChecked(0);
    ui->checkBox_51->setChecked(0);
    ui->checkBox_52->setChecked(0);
    ui->checkBox_53->setChecked(0);
    ui->checkBox_54->setChecked(0);
    ui->checkBox_55->setChecked(0);
    ui->checkBox_56->setChecked(0);
    ui->checkBox_57->setChecked(0);
    ui->checkBox_58->setChecked(0);
    ui->checkBox_59->setChecked(0);
    ui->checkBox_60->setChecked(0);
    ui->checkBox_61->setChecked(0);
    ui->checkBox_62->setChecked(0);
    ui->checkBox_63->setChecked(0);
    ui->checkBox_64->setChecked(0);
    ui->checkBox_65->setChecked(0);
    ui->checkBox_66->setChecked(0);
    ui->checkBox_67->setChecked(0);
    ui->checkBox_68->setChecked(0);
    ui->checkBox_69->setChecked(0);
    ui->checkBox_70->setChecked(0);
    ui->checkBox_71->setChecked(0);
    ui->checkBox_72->setChecked(0);


    ui->checkBox_73->setChecked(0);
    ui->checkBox_74->setChecked(0);
    ui->checkBox_75->setChecked(0);
    ui->checkBox_76->setChecked(0);
    ui->checkBox_77->setChecked(0);
    ui->checkBox_78->setChecked(0);
    ui->checkBox_79->setChecked(0);
    ui->checkBox_80->setChecked(0);
    ui->checkBox_81->setChecked(0);
    ui->checkBox_82->setChecked(0);
    ui->checkBox_83->setChecked(0);
    ui->checkBox_84->setChecked(0);
    ui->checkBox_85->setChecked(0);
    ui->checkBox_86->setChecked(0);
    ui->checkBox_87->setChecked(0);

    C8HeightRun = 0;
    C8HeightNum = 0;

    C8UpSpeedRun = 0;
    C8UpSpeedNum = 0;

    C8GPSHeightRun = 0;
    C8GPSHeightNum = 0;


    C8GPTUpSpeedRun = 0;
    C8GPTUpSpeedNum = 0;


    C8LogDownSpeed2GroundRun = 0;
    C8LogDownSpeed2GroundNum = 0;


    C8LogDownSpeed2WaterRun = 0;
    C8LogDownSpeed2WaterNum = 0;

    C1latitudeCurveRun=0;               //判断C1纬度曲线是否存在
    C1latitudeGraphNum=0;              //纬度在当前画图板中是第几条曲线


    C1headingAngleRun=0;                //判断C1航向曲线是否存在
    C1headingAngleNum=0;              //航向在当前画图板qreal rollAngle中是第几条曲线


    C1longitudeRun=0;                //判断C1经度曲线是否存在
    C1longitudeNum=0;              //经度在当前画图板中是第几条曲线

    C1rollAngleRun=0;                //判断C1横摇角曲线是否存在
    C1rollAngleNum=0;              //横摇角在当前画图板中是第几条曲线


    C1pitchAngleRun=0;                //判断C1纵摇角曲线是否存在
    C1pitchAngleNum=0;              //纵摇角在当前画图板中是第几条曲线


    C1northSpeedRun=0;                //判断C1北速曲线是否存在
    C1northSpeedNum=0;              //北速在当前画图板中是第几条曲线

    C1eastSpeedRun=0;                //判断C1东速曲线是否存在
    C1eastSpeedNum=0;              //东速在当前画图板中是第几条曲线


    C1headingAngularSpeedRun=0;                //判断C1航向角速度曲线是否存在
    C1headingAngularSpeedNum=0;


    C1rollAngleSpeedRun=0;                //判断C1横摇角速度曲线是否存在
    C1rollAngleSpeedNum=0;

    C1pitchAngleSpeedRun=0;                //判断C1纵摇角速度曲线是否存在
    C1pitchAngleSpeedNum=0;


    C1heaveRun=0;                //判断C1垂荡曲线是否存在
    C1heaveNum=0;


    C1verticalVelocityRun=0;                //判断C1垂速曲线是否存在
    C1verticalVelocityNum=0;


    C1swayRun=0;                //判断C1横荡曲线是否存在
    C1swayNum=0;


    C1transverseVelocityRun=0;                //判断C1横速曲线是否存在
    C1transverseVelocityNum=0;


    C1surgeRun=0;                //判断C1纵荡曲线是否存在
    C1surgeNum=0;


    C1longitudinalVelocityRun=0;                //判断C1纵速曲线是否存在
    C1longitudinalVelocityNum=0;


    C5XGyroAngleIncreaseFloatRun=0;                //判断C5X陀螺增量曲线是否存在
    C5XGyroAngleIncreaseFloatNum=0;


    C5YGyroAngleIncreaseFloatRun=0;                //判断C5Y陀螺增量曲线是否存在
    C5YGyroAngleIncreaseFloatNum=0;


    C5ZGyroAngleIncreaseFloatRun=0;                //判断C5Z陀螺增量曲线是否存在
    C5ZGyroAngleIncreaseFloatNum=0;


    C5XAccelerometerSpeedIncrementFloatRun=0;                //判断C5X加表增量曲线是否存在
    C5XAccelerometerSpeedIncrementFloatNum=0;


    C5YAccelerometerSpeedIncrementFloatRun=0;                //判断C5Y加表增量曲线是否存在
    C5YAccelerometerSpeedIncrementFloatNum=0;


    C5ZAccelerometerSpeedIncrementFloatRun=0;                //判断C5Z加表增量曲线是否存在
    C5ZAccelerometerSpeedIncrementFloatNum=0;


    C5XgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的x陀螺1s补偿后角增量曲线是否存在
    C5XgyroCompensatedAngleIncrementFloatNum=0;

    C5YgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的Y陀螺1s补偿后角增量曲线是否存在
    C5YgyroCompensatedAngleIncrementFloatNum=0;


    C5ZgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的Z陀螺1s补偿后角增量曲线是否存在
    C5ZgyroCompensatedAngleIncrementFloatNum=0;


    C5XAccVelocityIncrementFloatRun=0;                //判断C5的x加速度计1s补偿后速度增量曲线是否存在
    C5XAccVelocityIncrementFloatNum=0;


    C5YAccVelocityIncrementFloatRun=0;                //判断C5的Y加速度计1s补偿后速度增量曲线是否存在
    C5YAccVelocityIncrementFloatNum=0;


    C5ZAccVelocityIncrementFloatRun=0;                //判断C5的Z加速度计1s补偿后速度增量曲线是否存在
    C5ZAccVelocityIncrementFloatNum=0;


    C5XgyroDifFrequencyRun=0;                //判断C5的X陀螺差频曲线是否存在
    C5XgyroDifFrequencyNum=0;


    C5YgyroDifFrequencyRun=0;                //判断C5的Y陀螺差频曲线是否存在
    C5YgyroDifFrequencyNum=0;


    C5ZgyroDifFrequencyRun=0;                //判断C5的Z陀螺差频曲线是否存在
    C5ZgyroDifFrequencyNum=0;


    C5XaccelerometerDifFreRun=0;                //判断C5的X加速度计差频曲线是否存在
    C5XaccelerometerDifFreNum=0;


    C5YaccelerometerDifFreRun=0;                //判断C5的Y加速度计差频曲线是否存在
    C5YaccelerometerDifFreNum=0;


    C5ZaccelerometerDifFreRun=0;                //判断C5的Z加速度计差频曲线是否存在
    C5ZaccelerometerDifFreNum=0;


    C5XgyroTemp1Run=0;                //判断C5的X陀螺温度1是否存在
    C5XgyroTemp1Num=0;


    C5YgyroTemp1Run=0;                //判断C5的Y陀螺温度1是否存在
    C5YgyroTemp1Num=0;


    C5ZgyroTemp1Run=0;                //判断C5的Z陀螺温度1曲线是否存在
    C5ZgyroTemp1Num=0;


    C5XAccelerometerTempertureRun=0;                //判断C5的X加速度计温度1是否存在
    C5XAccelerometerTempertureNum=0;


    C5YAccelerometerTempertureRun=0;                //判断C5的Y加速度计温度1是否存在
    C5YAccelerometerTempertureNum=0;


    C5ZAccelerometerTempertureRun=0;                //判断C5的Z加速度计温度1曲线是否存在
    C5ZAccelerometerTempertureNum=0;


    C5XgyroTemp2Run=0;                //判断C5的X陀螺温度2是否存在
    C5XgyroTemp2Num=0;


    C5YgyroTemp2Run=0;                //判断C5的Y陀螺温度2是否存在
    C5YgyroTemp2Num=0;


    C5ZgyroTemp2Run=0;                //判断C5的Z陀螺温度2曲线是否存在
    C5ZgyroTemp2Num=0;


    C5XgyroAmplitudeJitterRun=0;                //判断C5的X陀螺抖幅曲线是否存在
    C5XgyroAmplitudeJitterNum=0;

    C5YgyroAmplitudeJitterRun=0;                //判断C5的Y陀螺抖幅曲线是否存在
    C5YgyroAmplitudeJitterNum=0;


    C5ZgyroAmplitudeJitterRun=0;                //判断C5的Z陀螺抖幅曲线是否存在
    C5ZgyroAmplitudeJitterNum=0;


    C5XgyroAmpl1itudeFreRun=0;                //判断C5的X陀螺抖频曲线是否存在
    C5XgyroAmpl1itudeFreNum=0;


    C5YgyroAmpl1itudeFreRun=0;                //判断C5的Y陀螺抖频曲线是否存在
    C5YgyroAmpl1itudeFreNum=0;


    C5ZgyroAmpl1itudeFreRun=0;                //判断C5的Z陀螺抖频曲线是否存在
    C5ZgyroAmpl1itudeFreNum=0;

    C3longitudeRun=0;                //判断C3的GPS经度曲线是否存在
    C3longitudeNum=0;


    C3GPSlatitudeRun=0;                //判断C3的GPS纬度曲线是否存在
    C3GPSlatitudeNum=0;


    C3togetherSpeedRun=0;                //判断C3的GPS合速曲线是否存在
    C3togetherSpeedNum=0;


    C3headingAngleRun=0;                //判断C3的GPS航向曲线是否存在
    C3headingAngleNum=0;


    C3combinedEastSpeedRun=0;                //判断C3的GPS东速曲线是否存在
    C3combinedEastSpeedNum=0;


    C3combinedNorthSpeedRun=0;                //判断C3的GPS北速曲线是否存在
    C3combinedNorthSpeedNum=0;


    C3waterXRun=0;                //判断C3的G多普勒对水横向速度曲线是否存在
    C3waterXNum=0;


    C3waterYRun=0;                //判断C3的G多普勒对水纵向速度曲线是否存在
    C3waterYNum=0;

    C3bottomXRun=0;                //判断C3的G多普勒对底横向速度曲线是否存在
    C3bottomXNum=0;

    C3bottomYRun=0;                //判断C3的G多普勒对底纵向速度曲线是否存在
    C3bottomYNum=0;

    C3electromagnetismSpeedRun=0;                //判断C3的电磁速度曲线是否存在
    C3electromagnetismSpeedNum=0;


    C6XGroyFloatRun=0;                //判断C6的X陀螺零偏曲线是否存在
    C6XGroyFloatNum=0;


    C6YGroyFloatRun=0;                //判断C6的Y陀螺零偏曲线是否存在
    C6YGroyFloatNum=0;


    C6ZGroyFloatRun=0;                //判断C6的Z陀螺零偏曲线是否存在
    C6ZGroyFloatNum=0;


    C6XAccelerometerFloatRun=0;                //判断C6的X加速度计零偏曲线是否存在
    C6XAccelerometerFloatNum=0;


    C6YAccelerometerFloatRun=0;                //判断C6的Y加速度计零偏曲线是否存在
    C6YAccelerometerFloatNum=0;

    C6ZAccelerometerFloatRun=0;                //判断C6的Z加速度计零偏曲线是否存在
    C6ZAccelerometerFloatNum=0;


    eastSpeedErrorRun=0;                //判断东速误差曲线是否存在
    eastSpeedErrorNum=0;


    northSpeedErrorRun=0;                //判断北速误差曲线是否存在
    northSpeedErrorNum=0;

    togetherSpeedErrorRun=0;                //判断合速速误差曲线是否存在
    togetherSpeedErrorNum=0;

    latitudeErrorRun=0;                //判断纬度误差曲线是否存在
    latitudeErrorNum=0;

    longitudeErrorRun=0;                //判断经度误差曲线是否存在
    longitudeErrorNum=0;


    positionErrorRun=0;                //判断位置误差曲线是否存在
    positionErrorNum=0;


    C6UndampedRollAngleFloatRun=0;                //判断C6无阻尼横摇角曲线是否存在
    C6UndampedRollAngleFloatNum=0;

    C6UndampedPitchAngleFloatRun=0;                //判断C6的无阻尼纵摇角曲线是否存在
    C6UndampedPitchAngleFloatNum=0;

    C6UndampedHeadingAngularFloatRun=0;                //判断C6的无阻尼航向角曲线是否存在
    C6UndampedHeadingAngularFloatNum=0;

    C6UndampedNorthSpeedFloatRun=0;                //判断C6的无阻尼北速是否存在
    C6UndampedNorthSpeedFloatNum=0;

    C6UndampedEastSpeedFloatRun=0;                //判断C6的无阻尼东速曲线是否存在
    C6UndampedEastSpeedFloatNum=0;

    C6VerticalVelocityFloatRun=0;                //判断C6的无阻尼垂速曲线是否存在
    C6VerticalVelocityFloatNum=0;

    C6UndampedLatFloatRun=0;                //判断C6的无阻尼纬度曲线是否存在
    C6UndampedLatFloatNum=0;

    C6UndampedLongFloatRun=0;                //判断C6的无阻尼经度曲线是否存在
    C6UndampedLongFloatNum=0;

    C6UndampedHeightFloatRun=0;                //判断C6的无阻尼高度曲线是否存在
    C6UndampedHeightFloatNum=0;

    ui->customPlot2->clearGraphs();
    ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);

}

void MainWindow::on_pushButton_clicked()
{

    paraQuery->show();
}

void MainWindow::on_pushButton_2_clicked()
{

    bookOriData->show();

}

void MainWindow::on_pushButton_3_clicked()
{

    attitudeData->show();
}

void MainWindow::on_pushButton_4_clicked()
{

    shipLoadData->show();
}

void MainWindow::on_pushButton_5_clicked()
{

    calbratParaData->show();
}

void MainWindow::on_pushButton_6_clicked()
{

    tempCompenCoeffData->show();
}

void MainWindow::on_pushButton_7_clicked()
{

    leverArmData->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    qtime->stop();
    m_xLength = 0;
    C1m_xLength = 0;
    C3m_xLength = 0;
    C5m_xLength = 0;
    C6m_xLength = 0;
    C8m_xLength = 0;

    C8VC8Height_bk +=C8VC8Height;
    C8VC8UpSpeed_bk +=C8VC8UpSpeed;

    C8VC8GPSHeight_bk +=C8VC8GPSHeight;
    C8VC8GPTUpSpeed_bk +=C8VC8GPTUpSpeed;

    C8VC8LogDownSpeed2Ground_bk +=C8VC8LogDownSpeed2Ground;
    C8VC8LogDownSpeed2Water_bk +=C8VC8LogDownSpeed2Water;

    C1Vlatitude_bk += C1Vlatitude;
    C1VheadingAngle_bk += C1VheadingAngle;
    C1Vlongitude_bk += C1Vlongitude;
    C1VrollAngle_bk += C1VrollAngle;
    C1VpitchAngle_bk += C1VpitchAngle;
    C1VnorthSpeed_bk +=C1VnorthSpeed;
    C1VeastSpeed_bk +=C1VeastSpeed;
    C1VheadingAngularSpeed_bk +=C1VheadingAngularSpeed;
    C1VrollAngleSpeed_bk += C1VrollAngleSpeed;
    C1VpitchAngleSpeed_bk += C1VpitchAngleSpeed;
    C1Vheave_bk += C1Vheave;
    C1VverticalVelocity_bk +=C1VverticalVelocity;
    C1Vsway_bk +=C1Vsway;
    C1VtransverseVelocity_bk +=C1VtransverseVelocity;
    C1Vsurge_bk += C1Vsurge;
    C1VlongitudinalVelocity_bk +=C1VlongitudinalVelocity;

    C5VXGyroAngleIncreaseFloat_bk+=C5VXGyroAngleIncreaseFloat;
    C5VYGyroAngleIncreaseFloat_bk+=C5VYGyroAngleIncreaseFloat;
    C5VZGyroAngleIncreaseFloat_bk+=C5VZGyroAngleIncreaseFloat;
    C5VXAccelerometerSpeedIncrementFloat_bk +=C5VXAccelerometerSpeedIncrementFloat;
    C5VYAccelerometerSpeedIncrementFloat_bk+=C5VYAccelerometerSpeedIncrementFloat;
    C5VZAccelerometerSpeedIncrementFloat_bk+=C5VZAccelerometerSpeedIncrementFloat;
    C5VXgyroCompensatedAngleIncrementFloat_bk+=C5VXgyroCompensatedAngleIncrementFloat;
    C5VYgyroCompensatedAngleIncrementFloat_bk+=C5VYgyroCompensatedAngleIncrementFloat;
    C5VZgyroCompensatedAngleIncrementFloat_bk+=C5VZgyroCompensatedAngleIncrementFloat;
    C5VXAccVelocityIncrementFloat_bk+=C5VXAccVelocityIncrementFloat;
    C5VYAccVelocityIncrementFloat_bk+=C5VYAccVelocityIncrementFloat;
    C5VZAccVelocityIncrementFloat_bk+=C5VZAccVelocityIncrementFloat;

    C5VXgyroDifFrequency_bk+=C5VXgyroDifFrequency;
    C5VYgyroDifFrequency_bk+=C5VYgyroDifFrequency;
    C5VZgyroDifFrequency_bk+=C5VZgyroDifFrequency;
    C5VXaccelerometerDifFre_bk+=C5VXaccelerometerDifFre;
    C5VYaccelerometerDifFre_bk+=C5VYaccelerometerDifFre;
    C5VZaccelerometerDifFre_bk+=C5VZaccelerometerDifFre;

    C5VXgyroTemp1_bk+=C5VXgyroTemp1;
    C5VYgyroTemp1_bk+=C5VYgyroTemp1;
    C5VZgyroTemp1_bk+=C5VZgyroTemp1;
    C5VXAccelerometerTemperture_bk+=C5VXAccelerometerTemperture;
    C5VYAccelerometerTemperture_bk+=C5VYAccelerometerTemperture;
    C5VZAccelerometerTemperture_bk+=C5VZAccelerometerTemperture;
    C5VXgyroTemp2_bk+=C5VXgyroTemp2;
    C5VYgyroTemp2_bk+=C5VYgyroTemp2;
    C5VZgyroTemp2_bk+=C5VZgyroTemp2;
    C5VXgyroAmplitudeJitter_bk+=C5VXgyroAmplitudeJitter;
    C5VYgyroAmplitudeJitter_bk+=C5VYgyroAmplitudeJitter;
    C5VZgyroAmplitudeJitter_bk+=C5VZgyroAmplitudeJitter;
    C5VXgyroAmpl1itudeFre_bk+=C5VXgyroAmpl1itudeFre;
    C5VYgyroAmpl1itudeFre_bk+=C5VYgyroAmpl1itudeFre;
    C5VZgyroAmpl1itudeFre_bk+=C5VZgyroAmpl1itudeFre;
    C3Vlongitude_bk+=C3Vlongitude;
    C3VGPSlatitude_bk+=C3VGPSlatitude;
    C3VtogetherSpeed_bk+=C3VtogetherSpeed;
    C3VheadingAngle_bk+=C3VheadingAngle;
    C3VcombinedEastSpeed_bk+=C3VcombinedEastSpeed;
    C3VcombinedNorthSpeed_bk+=C3VcombinedNorthSpeed;
    C3VwaterX_bk+=C3VwaterX;
    C3VwaterY_bk+=C3VwaterY;
    C3VbottomX_bk+=C3VbottomX;
    C3VbottomY_bk+=C3VbottomY;
    C3VelectromagnetismSpeed_bk+=C3VelectromagnetismSpeed;

    C6VC6UndampedRollAngleFloat_bk +=C6VC6UndampedRollAngleFloat;
    C6VC6UndampedPitchAngleFloat_bk+=C6VC6UndampedPitchAngleFloat;
    C6VC6UndampedHeadingAngularFloat_bk+=C6VC6UndampedHeadingAngularFloat;
    C6VC6UndampedNorthSpeedFloat_bk+=C6VC6UndampedNorthSpeedFloat;
    C6VC6UndampedEastSpeedFloat_bk+=C6VC6UndampedEastSpeedFloat;
    C6VC6VerticalVelocityFloat_bk+=C6VC6VerticalVelocityFloat;
    C6VC6UndampedLatFloat_bk+=C6VC6UndampedLatFloat;
    C6VC6UndampedLongFloat_bk+=C6VC6UndampedLongFloat;
    C6VC6UndampedHeightFloat_bk+=C6VC6UndampedHeightFloat;

    C6VC6XGroyFloat_bk+=C6VC6XGroyFloat;
    C6VC6YGroyFloat_bk+=C6VC6YGroyFloat;
    C6VC6ZGroyFloat_bk+=C6VC6ZGroyFloat;
    C6VC6XAccelerometerFloat_bk+=C6VC6XAccelerometerFloat;
    C6VC6YAccelerometerFloat_bk+=C6VC6YAccelerometerFloat;
    C6VC6ZAccelerometerFloat_bk+=C6VC6ZAccelerometerFloat;

    VeastSpeedError_bk+=VeastSpeedError;
    VnorthSpeedError_bk+=VnorthSpeedError;
    VtogetherSpeedError_bk+=VtogetherSpeedError;
    VlatitudeError_bk+=VlatitudeError;
    VlongitudeError_bk+=VlongitudeError;
    VpositionError_bk+=VpositionError;

    C1Vlatitude.clear();
    C1VheadingAngle.clear();
    C1Vlongitude.clear();
    C1VrollAngle.clear();
    C1VpitchAngle.clear();
    C1VnorthSpeed.clear();
    C1VeastSpeed.clear();
    C1VheadingAngularSpeed.clear();
    C1VrollAngleSpeed.clear();
    C1VpitchAngleSpeed.clear();
    C1Vheave.clear();
    C1VverticalVelocity.clear();
    C1Vsway.clear();
    C1VtransverseVelocity.clear();
    C1Vsurge.clear();
    C1VlongitudinalVelocity.clear();
    C5VXGyroAngleIncreaseFloat.clear();
    C5VYGyroAngleIncreaseFloat.clear();
    C5VZGyroAngleIncreaseFloat.clear();
    C5VXAccelerometerSpeedIncrementFloat.clear();
    C5VYAccelerometerSpeedIncrementFloat.clear();
    C5VZAccelerometerSpeedIncrementFloat.clear();
    C5VXgyroCompensatedAngleIncrementFloat.clear();
    C5VYgyroCompensatedAngleIncrementFloat.clear();
    C5VZgyroCompensatedAngleIncrementFloat.clear();
    C5VXAccVelocityIncrementFloat.clear();
    C5VYAccVelocityIncrementFloat.clear();
    C5VZAccVelocityIncrementFloat.clear();
    C5VXgyroDifFrequency.clear();
    C5VYgyroDifFrequency.clear();
    C5VZgyroDifFrequency.clear();
    C5VXaccelerometerDifFre.clear();
    C5VYaccelerometerDifFre.clear();
    C5VZaccelerometerDifFre.clear();
    C5VXgyroTemp1.clear();
    C5VYgyroTemp1.clear();
    C5VZgyroTemp1.clear();
    C5VXAccelerometerTemperture.clear();
    C5VYAccelerometerTemperture.clear();
    C5VZAccelerometerTemperture.clear();
    C5VXgyroTemp2.clear();
    C5VYgyroTemp2.clear();
    C5VZgyroTemp2.clear();
    C5VXgyroAmplitudeJitter.clear();
    C5VYgyroAmplitudeJitter.clear();
    C5VZgyroAmplitudeJitter.clear();
    C5VXgyroAmpl1itudeFre.clear();
    C5VYgyroAmpl1itudeFre.clear();
    C5VZgyroAmpl1itudeFre.clear();
    C3Vlongitude.clear();
    C3VGPSlatitude.clear();
    C3VtogetherSpeed.clear();
    C3VheadingAngle.clear();
    C3VcombinedEastSpeed.clear();
    C3VcombinedNorthSpeed.clear();
    C3VwaterX.clear();
    C3VwaterY.clear();
    C3VbottomX.clear();
    C3VbottomY.clear();
    C3VelectromagnetismSpeed.clear();
    C6VC6XGroyFloat.clear();
    C6VC6YGroyFloat.clear();
    C6VC6ZGroyFloat.clear();
    C6VC6XAccelerometerFloat.clear();
    C6VC6YAccelerometerFloat.clear();
    C6VC6ZAccelerometerFloat.clear();
    VeastSpeedError.clear();
    VnorthSpeedError.clear();
    VtogetherSpeedError.clear();
    VlatitudeError.clear();
    VlongitudeError.clear();
    VpositionError.clear();
    curveX.clear();
    C1curveX.clear();
    C3curveX.clear();
    C5curveX.clear();
    C6curveX.clear();
    C8curveX.clear();

    C6VC6UndampedRollAngleFloat.clear();
    C6VC6UndampedPitchAngleFloat.clear();
    C6VC6UndampedHeadingAngularFloat.clear();
    C6VC6UndampedNorthSpeedFloat.clear();
    C6VC6UndampedEastSpeedFloat.clear();
    C6VC6VerticalVelocityFloat.clear();
    C6VC6UndampedLatFloat.clear();
    C6VC6UndampedLongFloat.clear();
    C6VC6UndampedHeightFloat.clear();

    C8VC8Height.clear();
    C8VC8UpSpeed.clear();
    C8VC8GPSHeight.clear();
    C8VC8GPTUpSpeed.clear();
    C8VC8LogDownSpeed2Ground.clear();
    C8VC8LogDownSpeed2Water.clear();

    qtime->start();

}

//void MainWindow::on_pushButton_9_clicked()
//{
//       int checkBoxNum = 0;
//    if(ui->checkBox->isChecked()) checkBoxNum++;4
//    if(ui->checkBox_2->isChecked())	checkBoxNum++;
//    if(ui->checkBox_3->isChecked())	checkBoxNum++;
//    if(ui->checkBox_4->isChecked())	checkBoxNum++;
//    if(ui->checkBox_5->isChecked())	checkBoxNum++;
//    if(ui->checkBox_6->isChecked())	checkBoxNum++;
//    if(ui->checkBox_7->isChecked())	checkBoxNum++;
//    if(ui->checkBox_8->isChecked())	checkBoxNum++;
//    if(ui->checkBox_9->isChecked())	checkBoxNum++;
//    if(ui->checkBox_10->isChecked())	checkBoxNum++;
//    if(ui->checkBox_11->isChecked())	checkBoxNum++;
//    if(ui->checkBox_12->isChecked())	checkBoxNum++;
//    if(ui->checkBox_13->isChecked())	checkBoxNum++;
//    if(ui->checkBox_14->isChecked())	checkBoxNum++;
//    if(ui->checkBox_15->isChecked())	checkBoxNum++;
//    if(ui->checkBox_16->isChecked())	checkBoxNum++;
//    if(ui->checkBox_17->isChecked())	checkBoxNum++;
//    if(ui->checkBox_18->isChecked())	checkBoxNum++;
//    if(ui->checkBox_19->isChecked())	checkBoxNum++;
//    if(ui->checkBox_20->isChecked())	checkBoxNum++;
//    if(ui->checkBox_21->isChecked())	checkBoxNum++;
//    if(ui->checkBox_22->isChecked())	checkBoxNum++;
//    if(ui->checkBox_23->isChecked())	checkBoxNum++;
//    if(ui->checkBox_24->isChecked())	checkBoxNum++;
//    if(ui->checkBox_25->isChecked())	checkBoxNum++;
//    if(ui->checkBox_26->isChecked())	checkBoxNum++;
//    if(ui->checkBox_27->isChecked())	checkBoxNum++;
//    if(ui->checkBox_28->isChecked())	checkBoxNum++;
//    if(ui->checkBox_29->isChecked())	checkBoxNum++;
//    if(ui->checkBox_30->isChecked())	checkBoxNum++;
//    if(ui->checkBox_31->isChecked())	checkBoxNum++;
//    if(ui->checkBox_32->isChecked())	checkBoxNum++;
//    if(ui->checkBox_33->isChecked())	checkBoxNum++;
//    if(ui->checkBox_34->isChecked())	checkBoxNum++;
//    if(ui->checkBox_35->isChecked())	checkBoxNum++;
//    if(ui->checkBox_36->isChecked())	checkBoxNum++;
//    if(ui->checkBox_37->isChecked())	checkBoxNum++;
//    if(ui->checkBox_38->isChecked())	checkBoxNum++;
//    if(ui->checkBox_39->isChecked())	checkBoxNum++;
//    if(ui->checkBox_40->isChecked())	checkBoxNum++;
//    if(ui->checkBox_41->isChecked())	checkBoxNum++;
//    if(ui->checkBox_42->isChecked())	checkBoxNum++;
//    if(ui->checkBox_43->isChecked())	checkBoxNum++;
//    if(ui->checkBox_44->isChecked())	checkBoxNum++;
//    if(ui->checkBox_45->isChecked())	checkBoxNum++;
//    if(ui->checkBox_46->isChecked())	checkBoxNum++;
//    if(ui->checkBox_47->isChecked())	checkBoxNum++;
//    if(ui->checkBox_48->isChecked())	checkBoxNum++;
//    if(ui->checkBox_49->isChecked())	checkBoxNum++;
//    if(ui->checkBox_50->isChecked())	checkBoxNum++;
//    if(ui->checkBox_51->isChecked())	checkBoxNum++;
//    if(ui->checkBox_52->isChecked())	checkBoxNum++;
//    if(ui->checkBox_53->isChecked())	checkBoxNum++;
//    if(ui->checkBox_54->isChecked())	checkBoxNum++;
//    if(ui->checkBox_55->isChecked())	checkBoxNum++;
//    if(ui->checkBox_56->isChecked())	checkBoxNum++;
//    if(ui->checkBox_57->isChecked())	checkBoxNum++;
//    if(ui->checkBox_58->isChecked())	checkBoxNum++;
//    if(ui->checkBox_59->isChecked())	checkBoxNum++;
//    if(ui->checkBox_60->isChecked())	checkBoxNum++;
//    if(ui->checkBox_61->isChecked())	checkBoxNum++;
//    if(ui->checkBox_62->isChecked())	checkBoxNum++;
//    if(ui->checkBox_63->isChecked())	checkBoxNum++;
//    if(ui->checkBox_64->isChecked())	checkBoxNum++;
//    if(ui->checkBox_65->isChecked())	checkBoxNum++;
//    if(ui->checkBox_66->isChecked())	checkBoxNum++;
//    if(ui->checkBox_67->isChecked())	checkBoxNum++;
//    if(ui->checkBox_68->isChecked())	checkBoxNum++;
//    if(ui->checkBox_69->isChecked())	checkBoxNum++;
//    if(ui->checkBox_70->isChecked())	checkBoxNum++;
//    if(ui->checkBox_71->isChecked())	checkBoxNum++;
//    if(ui->checkBox_72->isChecked())	checkBoxNum++;
//    if(ui->checkBox_73->isChecked())	checkBoxNum++;
//    if(ui->checkBox_74->isChecked())	checkBoxNum++;
//    if(ui->checkBox_75->isChecked())	checkBoxNum++;
//    if(ui->checkBox_76->isChecked())	checkBoxNum++;
//    if(ui->checkBox_77->isChecked())	checkBoxNum++;
//    if(ui->checkBox_78->isChecked())	checkBoxNum++;
//    if(ui->checkBox_79->isChecked())	checkBoxNum++;
//    if(ui->checkBox_80->isChecked())	checkBoxNum++;
//    if(ui->checkBox_81->isChecked())	checkBoxNum++;
//    if(checkBoxNum == 0)
//    {
//        QMessageBox::warning(NULL, "提示", "未勾选曲线！");
//        //判断打开串口是否打开
//        if(ui->btn_openPort->text()=="关闭串口")
//        {
//            return;
//        }


//    }
//    QString path = QFileDialog::getSaveFileName(this,"保存曲线","./","*.dat");

//    if(path.isEmpty())
//    {
//            return;
//    }
//    QFile fileSave(path);
//    if(!fileSave.open( QIODevice::WriteOnly ))
//      {
//          //无法打开要写入的文件
//          QMessageBox::warning(this, tr("打开写入文件"),
//                               tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));

//              return;

//      }
//    QVector<double> C1Vlatitude_save = C1Vlatitude_bk + C1Vlatitude;
//    QTextStream dataOut(&fileSave);
//    dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
//    dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
//    QDateTime current_date_time =QDateTime::currentDateTime();
//    QString dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
//    dataOut<<"<CurveProfile,"<<checkBoxNum<<","<<C1Vlatitude_save.size()*checkBoxNum<<","<<dayStr<<">"<<"\n";   //文件开始格式

//    QProgressDialog *progressDialog = new QProgressDialog(this);
//    QFont font("ZYSong18030", 12);
//    progressDialog->setFont(font);
//    progressDialog->setWindowModality(Qt::WindowModal);
//    progressDialog->setMinimumDuration(5);
//    progressDialog->setWindowTitle(tr("Please Wait"));
//    progressDialog->setLabelText(tr("Copying..."));
//    progressDialog->setCancelButtonText(tr("Cancel"));

//    if(1)//保存位置曲线
//    {
//        int C1VlatitudeNum = 0;
//        int C1VlongitudeNum = 0;
//        int C6UndampedLatFloatNum = 0;
//        int C6UndampedLongFloatNum = 0;
//        int C6UndampedHeightFloatNum = 0;

//        //保存纬度和经度曲线
//        if(ui->checkBox->isChecked() == true)
//            C1VlatitudeNum += C1Vlatitude_bk.size() + C1Vlatitude.size();
//        if(ui->checkBox_2->isChecked() == true)
//            C1VlongitudeNum += C1Vlongitude_bk.size() + C1Vlongitude.size();
//        if(ui->checkBox_73->isChecked() == true)
//            C6UndampedLatFloatNum += C6VC6UndampedLatFloat_bk.size() + C6VC6UndampedLatFloat.size();
//        if(ui->checkBox_74->isChecked() == true)
//            C6UndampedLongFloatNum += C6VC6UndampedLongFloat_bk.size() + C6VC6UndampedLongFloat.size();
//        if(ui->checkBox_75->isChecked() == true)
//            C6UndampedHeightFloatNum += C6VC6UndampedHeightFloat_bk.size() + C6VC6UndampedHeightFloat.size();
//        progressDialog->setRange(0, C1VlatitudeNum+C1VlongitudeNum+C6UndampedLatFloatNum+C6UndampedLongFloatNum+C6UndampedHeightFloatNum);
//        if(ui->checkBox->isChecked() == true)
//        {


//            dataOut<<tr("<纬度 °,")<<C1Vlatitude_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1Vlatitude_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;
//                }
//                dataOut<<QString::number(C1Vlatitude_save[i],'f',5)<<",";
//            }
//            dataOut<<tr("\n</纬度>")<<"\n";
//        }
//        if(ui->checkBox_2->isChecked() == true)
//        {
//            QVector<double> C1Vlongitude_save = C1Vlongitude_bk + C1Vlongitude;
//            dataOut<<tr("<经度 °,")<<C1Vlongitude_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1Vlongitude_save.size();i++)
//            {
//                progressDialog->setValue(C1VlatitudeNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<QString::number(C1Vlongitude_save[i],'f',5)<<",";
//            }
//            dataOut<<tr("\n</经度>")<<"\n";
//        }
//        if(ui->checkBox_73->isChecked() == true)
//        {
//            QVector<double> C6UndampedLatFloat_save = C6VC6UndampedLatFloat_bk + C6VC6UndampedLatFloat;
//            dataOut<<tr("<无阻尼纬度 °,")<<C6UndampedLatFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6UndampedLatFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VlatitudeNum+C1VlongitudeNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<QString::number(C6UndampedLatFloat_save[i],'f',5)<<",";
//            }
//            dataOut<<tr("\n</无阻尼纬度>")<<"\n";
//        }
//        if(ui->checkBox_74->isChecked() == true)
//        {
//            QVector<double> C6UndampedLongFloat_save = C6VC6UndampedLongFloat_bk + C6VC6UndampedLongFloat;
//            dataOut<<tr("<无阻尼经度 °,")<<C6UndampedLongFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6UndampedLongFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VlatitudeNum+C1VlongitudeNum+C6UndampedLatFloatNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<QString::number(C6UndampedLongFloat_save[i],'f',5)<<",";
//            }
//            dataOut<<tr("\n</无阻尼经度>")<<"\n";
//        }
//        if(ui->checkBox_75->isChecked() == true)
//        {
//            QVector<double> C6UndampedHeightFloat_save = C6VC6UndampedHeightFloat_bk + C6VC6UndampedHeightFloat;
//            dataOut<<tr("<无阻尼高度 m,")<<C6UndampedHeightFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6UndampedHeightFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VlatitudeNum+C1VlongitudeNum+C6UndampedLatFloatNum+C6UndampedLongFloatNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    if(ui->btn_openPort->text()=="关闭串口")
//                    return;

//                }
//                dataOut<<QString::number(C6UndampedHeightFloat_save[i],'f',5)<<",";
//            }
//            dataOut<<tr("\n</无阻尼高度>")<<"\n";
//        }
//    }

//    if(1)//保存航姿曲线
//    {
//        int C1VheadingAngularNum = 0;
//        int C1VrollAngleNum = 0;
//         int C1VpitchAngleNum = 0;
//         int C6UndampedRollAngleFloatNum = 0;
//         int C6UndampedPitchAngleFloatNum = 0;
//         int C6UndampedHeadingAngularFloatNum = 0;

//        if(ui->checkBox_5->isChecked() == true)
//            C1VheadingAngularNum += C1VheadingAngle_bk.size() + C1VheadingAngle.size();
//        if(ui->checkBox_3->isChecked() == true)
//            C1VrollAngleNum += C1VrollAngle_bk.size() + C1VrollAngle.size();
//        if(ui->checkBox_4->isChecked() == true)
//            C1VpitchAngleNum += C1VpitchAngle_bk.size() + C1VpitchAngle.size();

//        if(ui->checkBox_79->isChecked() == true)
//            C6UndampedRollAngleFloatNum += C6VC6UndampedRollAngleFloat_bk.size() + C6VC6UndampedRollAngleFloat.size();
//        if(ui->checkBox_80->isChecked() == true)
//            C6UndampedPitchAngleFloatNum += C6VC6UndampedPitchAngleFloat_bk.size() + C6VC6UndampedPitchAngleFloat.size();
//        if(ui->checkBox_81->isChecked() == true)
//            C6UndampedHeadingAngularFloatNum += C6VC6UndampedHeadingAngularFloat_bk.size() + C6VC6UndampedHeadingAngularFloat.size();
//        progressDialog->setRange(0, C1VheadingAngularNum+C1VrollAngleNum+C1VpitchAngleNum+C6UndampedRollAngleFloatNum+C6UndampedPitchAngleFloatNum+C6UndampedHeadingAngularFloatNum);
//        if(ui->checkBox_5->isChecked() == true)
//        {

//            QVector<double> C1VheadingAngular_save = C1VheadingAngle_bk + C1VheadingAngle;
//            dataOut<<tr("<航向 °,")<<C1VheadingAngular_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VheadingAngular_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<QString::number(C1VheadingAngular_save[i],'f',4)<<",";
//            }
//            dataOut<<tr("\n</航向>")<<"\n";
//        }
//        if(ui->checkBox_3->isChecked() == true)
//        {
//            QVector<double> C1VrollAngle_save = C1VrollAngle_bk + C1VrollAngle;
//            dataOut<<tr("<横摇角 °,")<<C1VrollAngle_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VrollAngle_save.size();i++)
//            {
//                progressDialog->setValue(C1VheadingAngularNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VrollAngle_save[i]<<",";
//            }
//            dataOut<<tr("\n</横摇角>")<<"\n";
//        }
//        if(ui->checkBox_4->isChecked() == true)
//        {
//            QVector<double> C1VpitchAngle_save = C1VpitchAngle_bk + C1VpitchAngle;
//            dataOut<<tr("<纵摇角 °,")<<C1VpitchAngle_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VpitchAngle_save.size();i++)
//            {
//                progressDialog->setValue(C1VheadingAngularNum+C1VrollAngleNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VpitchAngle_save[i]<<",";
//            }
//            dataOut<<tr("\n</纵摇角>")<<"\n";
//        }

//        if(ui->checkBox_79->isChecked() == true)
//        {
//            QVector<double> C6UndampedRollAngleFloat_save = C6VC6UndampedRollAngleFloat_bk + C6VC6UndampedRollAngleFloat;
//            dataOut<<tr("<无阻尼横摇角 °,")<<C6UndampedRollAngleFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6UndampedRollAngleFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VheadingAngularNum+C1VrollAngleNum+C1VpitchAngleNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;
//                }
//                dataOut<<C6UndampedRollAngleFloat_save[i]<<",";
//            }
//            dataOut<<tr("\n</无阻尼横摇角>")<<"\n";
//        }
//        if(ui->checkBox_80->isChecked() == true)
//        {
//            QVector<double> C6UndampedPitchAngleFloat_save = C6VC6UndampedPitchAngleFloat_bk + C6VC6UndampedPitchAngleFloat;
//            dataOut<<tr("<无阻尼纵摇角 °,")<<C6UndampedPitchAngleFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6UndampedPitchAngleFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VheadingAngularNum+C1VrollAngleNum+C1VpitchAngleNum+C6UndampedRollAngleFloatNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;
//                }
//                dataOut<<C6UndampedPitchAngleFloat_save[i]<<",";
//            }
//            dataOut<<tr("\n</无阻尼纵摇角>")<<"\n";
//        }
//        if(ui->checkBox_81->isChecked() == true)
//        {
//            QVector<double> C6UndampedHeadingAngularFloat_save = C6VC6UndampedHeadingAngularFloat_bk + C6VC6UndampedHeadingAngularFloat;
//            dataOut<<tr("<无阻尼航向角 °,")<<C6UndampedHeadingAngularFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6UndampedHeadingAngularFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VheadingAngularNum+C1VrollAngleNum+C1VpitchAngleNum+C6UndampedRollAngleFloatNum+C6UndampedPitchAngleFloatNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C6UndampedHeadingAngularFloat_save[i]<<",";
//            }
//            dataOut<<tr("\n</无阻尼航向角>")<<"\n";
//        }
//    }

//    if(1)//保存姿态角速度线
//    {
//        int C1VheadingAngularSpeedNum = 0;
//        int C1VrollAngleSpeedNum = 0;
//         int C1VpitchAngleSpeedNum = 0;

//        if(ui->checkBox_6->isChecked() == true)
//            C1VheadingAngularSpeedNum += C1VheadingAngularSpeed_bk.size() + C1VheadingAngularSpeed.size();
//        if(ui->checkBox_7->isChecked() == true)
//            C1VrollAngleSpeedNum += C1VrollAngleSpeed_bk.size() + C1VrollAngleSpeed.size();
//        if(ui->checkBox_8->isChecked() == true)
//            C1VpitchAngleSpeedNum += C1VpitchAngleSpeed_bk.size() + C1VpitchAngleSpeed.size();
//        progressDialog->setRange(0, C1VheadingAngularSpeedNum+C1VrollAngleSpeedNum+C1VpitchAngleSpeedNum);
//        if(ui->checkBox_6->isChecked() == true)
//        {

//            QVector<double> C1VheadingAngularSpeed_save = C1VheadingAngularSpeed_bk + C1VheadingAngularSpeed;
//            dataOut<<tr("<航向角速度 °/s,")<<C1VheadingAngularSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VheadingAngularSpeed_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VheadingAngularSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</航向角速度>")<<"\n";
//        }
//        if(ui->checkBox_7->isChecked() == true)
//        {
//            QVector<double> C1VrollAngleSpeed_save = C1VrollAngleSpeed_bk + C1VrollAngleSpeed;
//            dataOut<<tr("<横摇角速度 °/s,")<<C1VrollAngleSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VrollAngleSpeed_save.size();i++)
//            {
//                progressDialog->setValue(C1VheadingAngularSpeedNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VrollAngleSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</横摇角速度>")<<"\n";
//        }
//        if(ui->checkBox_8->isChecked() == true)
//        {
//            QVector<double> C1VpitchAngleSpeed_save = C1VpitchAngleSpeed_bk + C1VpitchAngleSpeed;
//            dataOut<<tr("<纵摇角速度 °/s,")<<C1VpitchAngleSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VpitchAngleSpeed_save.size();i++)
//            {
//                progressDialog->setValue(C1VheadingAngularSpeedNum+C1VpitchAngleSpeedNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VpitchAngleSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</纵摇角速度>")<<"\n";
//        }

//    }

//    if(1)//保存速度曲线
//    {
//        int C1VnorthSpeedNum = 0;
//        int C1VeastSpeedNum = 0;
//        int C6UndampedNorthSpeedFloatNum = 0;
//        int C6UndampedEastSpeedFloatNum = 0;
//        int C6VerticalVelocityFloatNum = 0;

//        if(ui->checkBox_9->isChecked() == true)
//            C1VnorthSpeedNum += C1VnorthSpeed_bk.size() + C1VnorthSpeed.size();
//        if(ui->checkBox_10->isChecked() == true)
//            C1VeastSpeedNum += C1VeastSpeed_bk.size() + C1VeastSpeed.size();
//        if(ui->checkBox_76->isChecked() == true)
//            C6UndampedNorthSpeedFloatNum += C6VC6UndampedNorthSpeedFloat_bk.size() + C6VC6UndampedNorthSpeedFloat.size();
//        if(ui->checkBox_77->isChecked() == true)
//            C6UndampedEastSpeedFloatNum += C6VC6UndampedEastSpeedFloat_bk.size() + C6VC6UndampedEastSpeedFloat.size();
//        if(ui->checkBox_78->isChecked() == true)
//            C6VerticalVelocityFloatNum += C6VC6VerticalVelocityFloat_bk.size() + C6VC6VerticalVelocityFloat.size();
//        progressDialog->setRange(0, C1VnorthSpeedNum+C1VeastSpeedNum+C6UndampedNorthSpeedFloatNum+C6UndampedEastSpeedFloatNum+C6VerticalVelocityFloatNum);
//        if(ui->checkBox_9->isChecked() == true)
//        {

//            QVector<double> C1VnorthSpeed_save = C1VnorthSpeed_bk + C1VnorthSpeed;
//            dataOut<<tr("<北速 kn,")<<C1VnorthSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VnorthSpeed_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VnorthSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</北速>")<<"\n";
//        }
//        if(ui->checkBox_10->isChecked() == true)
//        {
//            QVector<double> C1VeastSpeed_save = C1VeastSpeed_bk + C1VeastSpeed;
//            dataOut<<tr("<东速 kn,")<<C1VeastSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VeastSpeed_save.size();i++)
//            {
//                progressDialog->setValue(C1VnorthSpeedNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VeastSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</东速>")<<"\n";
//        }
//        if(ui->checkBox_76->isChecked() == true)
//        {
//            QVector<double> C6UndampedNorthSpeedFloat_save = C6VC6UndampedNorthSpeedFloat_bk + C6VC6UndampedNorthSpeedFloat;
//            dataOut<<tr("<无阻尼北速 kn,")<<C6UndampedNorthSpeedFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6UndampedNorthSpeedFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VnorthSpeedNum+C1VeastSpeedNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C6UndampedNorthSpeedFloat_save[i]<<",";
//            }
//            dataOut<<tr("\n</无阻尼北速>")<<"\n";
//        }
//        if(ui->checkBox_77->isChecked() == true)
//        {
//            QVector<double> C6UndampedEastSpeedFloat_save = C6VC6UndampedEastSpeedFloat_bk + C6VC6UndampedEastSpeedFloat;
//            dataOut<<tr("<无阻尼东速 kn,")<<C6UndampedEastSpeedFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6UndampedEastSpeedFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VnorthSpeedNum+C1VeastSpeedNum+C6UndampedNorthSpeedFloatNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C6UndampedEastSpeedFloat_save[i]<<",";
//            }
//            dataOut<<tr("\n</无阻尼东速>")<<"\n";
//        }
//        if(ui->checkBox_78->isChecked() == true)
//        {
//            QVector<double> C6VerticalVelocityFloat_save = C6VC6VerticalVelocityFloat_bk + C6VC6VerticalVelocityFloat;
//            dataOut<<tr("<无阻尼垂速 kn,")<<C6VerticalVelocityFloat_save.size()<<">"<<"\n";
//            for(int i = 0;i<C6VerticalVelocityFloat_save.size();i++)
//            {
//                progressDialog->setValue(C1VnorthSpeedNum+C1VeastSpeedNum+C6UndampedNorthSpeedFloatNum+C6UndampedEastSpeedFloatNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C6VerticalVelocityFloat_save[i]<<",";
//            }
//            dataOut<<tr("\n</无阻尼垂速>")<<"\n";
//        }
//    }

//    if(1)//保存瞬时线运动曲线
//    {
//        int C1VheaveNum = 0;
//        int C1VverticalVelocityNum = 0;
//        int C1VswayNum = 0;
//        int C1VtransverseVelocityNum = 0;
//        int C1VsurgeNum = 0;
//        int C1VlongitudinalVelocityNum = 0;
//        if(ui->checkBox_12->isChecked() == true)
//            C1VheaveNum += C1Vheave_bk.size() + C1Vheave.size();
//        if(ui->checkBox_13->isChecked() == true)
//            C1VverticalVelocityNum += C1VverticalVelocity_bk.size() + C1VverticalVelocity.size();
//        if(ui->checkBox_11->isChecked() == true)
//            C1VswayNum += C1Vsway_bk.size() + C1Vsway.size();

//        if(ui->checkBox_15->isChecked() == true)
//            C1VheaveNum += C1VtransverseVelocity_bk.size() + C1VtransverseVelocity.size();
//        if(ui->checkBox_16->isChecked() == true)
//            C1VverticalVelocityNum += C1Vsurge_bk.size() + C1Vsurge.size();
//        if(ui->checkBox_14->isChecked() == true)
//            C1VswayNum += C1VlongitudinalVelocity_bk.size() + C1VlongitudinalVelocity.size();
//        progressDialog->setRange(0, C1VheaveNum+C1VverticalVelocityNum+C1VswayNum+C1VtransverseVelocityNum+C1VsurgeNum+C1VlongitudinalVelocityNum);
//        if(ui->checkBox_12->isChecked() == true)
//        {

//            QVector<double> C1Vheave_save = C1Vheave_bk + C1Vheave;
//            dataOut<<tr("<垂荡 m,")<<C1Vheave_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1Vheave_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1Vheave_save[i]<<",";
//            }
//            dataOut<<tr("\n</垂荡>")<<"\n";
//        }
//        if(ui->checkBox_13->isChecked() == true)
//        {
//            QVector<double> C1VverticalVelocity_save = C1VverticalVelocity_bk + C1VverticalVelocity;
//            dataOut<<tr("<垂速 m/s,")<<C1VverticalVelocity_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VverticalVelocity_save.size();i++)
//            {
//                progressDialog->setValue(C1VheaveNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VverticalVelocity_save[i]<<",";
//            }
//            dataOut<<tr("\n</垂速>")<<"\n";
//        }
//        if(ui->checkBox_11->isChecked() == true)
//        {
//            QVector<double> C1Vsway_save = C1Vsway_bk + C1Vsway;
//            dataOut<<tr("<横荡 m,")<<C1Vsway_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1Vsway_save.size();i++)
//            {
//                progressDialog->setValue(C1VheaveNum+C1VverticalVelocityNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1Vsway_save[i]<<",";
//            }
//            dataOut<<tr("\n</横荡>")<<"\n";
//        }
//        if(ui->checkBox_15->isChecked() == true)
//        {
//            QVector<double> C1VtransverseVelocity_save = C1VtransverseVelocity_bk + C1VtransverseVelocity;
//            dataOut<<tr("<横速 m/s,")<<C1VtransverseVelocity_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VtransverseVelocity_save.size();i++)
//            {
//                progressDialog->setValue(C1VheaveNum+C1VverticalVelocityNum+C1VswayNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VtransverseVelocity_save[i]<<",";
//            }
//            dataOut<<tr("\n</横速>")<<"\n";
//        }
//        if(ui->checkBox_16->isChecked() == true)
//        {
//            QVector<double> C1Vsurge_save = C1Vsurge_bk + C1Vsurge;
//            dataOut<<tr("<纵荡 m,")<<C1Vsurge_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1Vsurge_save.size();i++)
//            {
//                progressDialog->setValue(C1VheaveNum+C1VverticalVelocityNum+C1VswayNum+C1VtransverseVelocityNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1Vsurge_save[i]<<",";
//            }
//            dataOut<<tr("\n</纵荡>")<<"\n";
//        }
//        if(ui->checkBox_14->isChecked() == true)
//        {
//            QVector<double> C1VlongitudinalVelocity_save = C1VlongitudinalVelocity_bk + C1VlongitudinalVelocity;
//            dataOut<<tr("<纵速 m/s,")<<C1VlongitudinalVelocity_save.size()<<">"<<"\n";
//            for(int i = 0;i<C1VlongitudinalVelocity_save.size();i++)
//            {
//                progressDialog->setValue(C1VheaveNum+C1VverticalVelocityNum+C1VswayNum+C1VtransverseVelocityNum+C1VsurgeNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C1VlongitudinalVelocity_save[i]<<",";
//            }
//            dataOut<<tr("\n</纵速>")<<"\n";
//        }

//    }

//#ifdef INSIDE
//    if(1)//不显示增量、补偿增量和差频（原始脉冲）曲线2022-01-20
//    {

//        if(1)//保存陀螺增量曲线
//        {
//            int C5VXGyroAngleIncreaseFloatNum = 0;
//            int C5VYGyroAngleIncreaseFloatNum = 0;
//            int C5VZGyroAngleIncreaseFloatNum = 0;

//            if(ui->checkBox_19->isChecked() == true)
//                C5VXGyroAngleIncreaseFloatNum += C5VXGyroAngleIncreaseFloat_bk.size() + C5VXGyroAngleIncreaseFloat.size();
//            if(ui->checkBox_18->isChecked() == true)
//                C5VYGyroAngleIncreaseFloatNum += C5VYGyroAngleIncreaseFloat_bk.size() + C5VYGyroAngleIncreaseFloat.size();
//            if(ui->checkBox_17->isChecked() == true)
//                C5VZGyroAngleIncreaseFloatNum += C5VZGyroAngleIncreaseFloat_bk.size() + C5VZGyroAngleIncreaseFloat.size();
//            progressDialog->setRange(0, C5VXGyroAngleIncreaseFloatNum+C5VYGyroAngleIncreaseFloatNum+C5VZGyroAngleIncreaseFloatNum);
//            if(ui->checkBox_19->isChecked() == true)
//            {

//                QVector<double> C5VXGyroAngleIncreaseFloat_save = C5VXGyroAngleIncreaseFloat_bk + C5VXGyroAngleIncreaseFloat;
//                dataOut<<tr("<X陀螺增量 °/h,")<<C5VXGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VXGyroAngleIncreaseFloat_save.size();i++)
//                {
//                    progressDialog->setValue(i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VXGyroAngleIncreaseFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</X陀螺增量>")<<"\n";
//            }
//            if(ui->checkBox_18->isChecked() == true)
//            {
//                QVector<double> C5VYGyroAngleIncreaseFloat_save = C5VYGyroAngleIncreaseFloat_bk + C5VYGyroAngleIncreaseFloat;
//                dataOut<<tr("<Y陀螺增量 °/h,")<<C5VYGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VYGyroAngleIncreaseFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXGyroAngleIncreaseFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VYGyroAngleIncreaseFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Y陀螺增量>")<<"\n";
//            }
//            if(ui->checkBox_17->isChecked() == true)
//            {
//                QVector<double> C5VZGyroAngleIncreaseFloat_save = C5VZGyroAngleIncreaseFloat_bk + C5VZGyroAngleIncreaseFloat;
//                dataOut<<tr("<Z陀螺增量 °/h,")<<C5VZGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VZGyroAngleIncreaseFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXGyroAngleIncreaseFloatNum+C5VYGyroAngleIncreaseFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VZGyroAngleIncreaseFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Z陀螺增量>")<<"\n";
//            }

//        }

//        if(1)//保存加表增量曲线
//        {
//            int C5VXAccelerometerSpeedIncrementFloatNum = 0;
//            int C5VYAccelerometerSpeedIncrementFloatNum = 0;
//            int C5VZAccelerometerSpeedIncrementFloatNum = 0;

//            if(ui->checkBox_20->isChecked() == true)
//                C5VXAccelerometerSpeedIncrementFloatNum += C5VXAccelerometerSpeedIncrementFloat_bk.size() + C5VXAccelerometerSpeedIncrementFloat.size();
//            if(ui->checkBox_21->isChecked() == true)
//                C5VYAccelerometerSpeedIncrementFloatNum += C5VYAccelerometerSpeedIncrementFloat_bk.size() + C5VYAccelerometerSpeedIncrementFloat.size();
//            if(ui->checkBox_22->isChecked() == true)
//                C5VZAccelerometerSpeedIncrementFloatNum += C5VZAccelerometerSpeedIncrementFloat_bk.size() + C5VZAccelerometerSpeedIncrementFloat.size();
//            progressDialog->setRange(0, C5VXAccelerometerSpeedIncrementFloatNum+C5VYAccelerometerSpeedIncrementFloatNum+C5VZAccelerometerSpeedIncrementFloatNum);
//            if(ui->checkBox_20->isChecked() == true)
//            {

//                QVector<double> C5VXAccelerometerSpeedIncrementFloat_save = C5VXAccelerometerSpeedIncrementFloat_bk + C5VXAccelerometerSpeedIncrementFloat;
//                dataOut<<tr("<X加表增量 m/s/s,")<<C5VXAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VXAccelerometerSpeedIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VXAccelerometerSpeedIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</X加表增量>")<<"\n";
//            }
//            if(ui->checkBox_21->isChecked() == true)
//            {
//                QVector<double> C5VYAccelerometerSpeedIncrementFloat_save = C5VYAccelerometerSpeedIncrementFloat_bk + C5VYAccelerometerSpeedIncrementFloat;
//                dataOut<<tr("<Y加表增量 m/s/s,")<<C5VYAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VYAccelerometerSpeedIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXAccelerometerSpeedIncrementFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VYAccelerometerSpeedIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Y加表增量>")<<"\n";
//            }
//            if(ui->checkBox_22->isChecked() == true)
//            {
//                QVector<double> C5VZAccelerometerSpeedIncrementFloat_save = C5VZAccelerometerSpeedIncrementFloat_bk + C5VZAccelerometerSpeedIncrementFloat;
//                dataOut<<tr("<Z加表增量 m/s/s,")<<C5VZAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VZAccelerometerSpeedIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXAccelerometerSpeedIncrementFloatNum+C5VZAccelerometerSpeedIncrementFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VZAccelerometerSpeedIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Z加表增量>")<<"\n";
//            }

//        }

//        if(1)//保存陀螺1s补偿后角增量曲线
//        {
//            int C5VXgyroCompensatedAngleIncrementFloatNum = 0;
//            int C5VYgyroCompensatedAngleIncrementFloatNum = 0;
//            int C5VZgyroCompensatedAngleIncrementFloatNum = 0;

//            if(ui->checkBox_23->isChecked() == true)
//                C5VXgyroCompensatedAngleIncrementFloatNum += C5VXgyroCompensatedAngleIncrementFloat_bk.size() + C5VXgyroCompensatedAngleIncrementFloat.size();
//            if(ui->checkBox_24->isChecked() == true)
//                C5VYgyroCompensatedAngleIncrementFloatNum += C5VYgyroCompensatedAngleIncrementFloat_bk.size() + C5VYgyroCompensatedAngleIncrementFloat.size();
//            if(ui->checkBox_25->isChecked() == true)
//                C5VZgyroCompensatedAngleIncrementFloatNum += C5VZgyroCompensatedAngleIncrementFloat_bk.size() + C5VZgyroCompensatedAngleIncrementFloat.size();
//            progressDialog->setRange(0, C5VXgyroCompensatedAngleIncrementFloatNum+C5VYgyroCompensatedAngleIncrementFloatNum+C5VZgyroCompensatedAngleIncrementFloatNum);
//            if(ui->checkBox_23->isChecked() == true)
//            {

//                QVector<double> C5VXgyroCompensatedAngleIncrementFloat_save = C5VXgyroCompensatedAngleIncrementFloat_bk + C5VXgyroCompensatedAngleIncrementFloat;
//                dataOut<<tr("<x陀螺1s补偿后角增量 °/h,")<<C5VXgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VXgyroCompensatedAngleIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VXgyroCompensatedAngleIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</x陀螺1s补偿后角增量>")<<"\n";
//            }
//            if(ui->checkBox_24->isChecked() == true)
//            {
//                QVector<double> C5VYgyroCompensatedAngleIncrementFloat_save = C5VYgyroCompensatedAngleIncrementFloat_bk + C5VYgyroCompensatedAngleIncrementFloat;
//                dataOut<<tr("<Y陀螺1s补偿后角增量 °/h,")<<C5VYgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VYgyroCompensatedAngleIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXgyroCompensatedAngleIncrementFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VYgyroCompensatedAngleIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Y陀螺1s补偿后角增量>")<<"\n";
//            }
//            if(ui->checkBox_25->isChecked() == true)
//            {
//                QVector<double> C5VZgyroCompensatedAngleIncrementFloat_save = C5VZgyroCompensatedAngleIncrementFloat_bk + C5VZgyroCompensatedAngleIncrementFloat;
//                dataOut<<tr("<Z陀螺1s补偿后角增量 °/h,")<<C5VZgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VZgyroCompensatedAngleIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXgyroCompensatedAngleIncrementFloatNum+C5VYgyroCompensatedAngleIncrementFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VZgyroCompensatedAngleIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Z陀螺1s补偿后角增量>")<<"\n";
//            }

//        }

//        if(1)//保存加表1s补偿后角增量曲线
//        {
//            int C5VXAccVelocityIncrementFloatNum = 0;
//            int C5VYAccVelocityIncrementFloatNum = 0;
//            int C5VZAccVelocityIncrementFloatNum = 0;

//            if(ui->checkBox_26->isChecked() == true)
//                C5VXAccVelocityIncrementFloatNum += C5VXAccVelocityIncrementFloat_bk.size() + C5VXAccVelocityIncrementFloat.size();
//            if(ui->checkBox_27->isChecked() == true)
//                C5VYAccVelocityIncrementFloatNum += C5VYAccVelocityIncrementFloat_bk.size() + C5VYAccVelocityIncrementFloat.size();
//            if(ui->checkBox_28->isChecked() == true)
//                C5VZAccVelocityIncrementFloatNum += C5VZAccVelocityIncrementFloat_bk.size() + C5VZAccVelocityIncrementFloat.size();
//            progressDialog->setRange(0, C5VXAccVelocityIncrementFloatNum+C5VYAccVelocityIncrementFloatNum+C5VZAccVelocityIncrementFloatNum);
//            if(ui->checkBox_26->isChecked() == true)
//            {

//                QVector<double> C5VXAccVelocityIncrementFloat_save = C5VXAccVelocityIncrementFloat_bk + C5VXAccVelocityIncrementFloat;
//                dataOut<<tr("<x加速度计1s补偿后速度增量 °/h,")<<C5VXAccVelocityIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VXAccVelocityIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VXAccVelocityIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</x加速度计1s补偿后速度增量>")<<"\n";
//            }
//            if(ui->checkBox_27->isChecked() == true)
//            {
//                QVector<double> C5VYAccVelocityIncrementFloat_save = C5VYAccVelocityIncrementFloat_bk + C5VYAccVelocityIncrementFloat;
//                dataOut<<tr("<Y加速度计1s补偿后速度增量 °/h,")<<C5VYAccVelocityIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VYAccVelocityIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXAccVelocityIncrementFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VYAccVelocityIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Y加速度计1s补偿后速度增量>")<<"\n";
//            }
//            if(ui->checkBox_28->isChecked() == true)
//            {
//                QVector<double> C5VZAccVelocityIncrementFloat_save = C5VZAccVelocityIncrementFloat_bk + C5VZAccVelocityIncrementFloat;
//                dataOut<<tr("<Z加速度计1s补偿后速度增量 °/h,")<<C5VZAccVelocityIncrementFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VZAccVelocityIncrementFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXAccVelocityIncrementFloatNum+C5VYAccVelocityIncrementFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VZAccVelocityIncrementFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Z加速度计1s补偿后速度增量>")<<"\n";
//            }

//        }

//        if(1)//保存陀螺差频曲线
//        {
//            int C5VXgyroDifFrequencyNum = 0;
//            int C5VYgyroDifFrequencyNum = 0;
//            int C5VZgyroDifFrequencyNum = 0;

//            if(ui->checkBox_29->isChecked() == true)
//                C5VXgyroDifFrequencyNum += C5VXgyroDifFrequency_bk.size() + C5VXgyroDifFrequency.size();
//            if(ui->checkBox_31->isChecked() == true)
//                C5VYgyroDifFrequencyNum += C5VYgyroDifFrequency_bk.size() + C5VYgyroDifFrequency.size();
//            if(ui->checkBox_30->isChecked() == true)
//                C5VZgyroDifFrequencyNum += C5VZgyroDifFrequency_bk.size() + C5VZgyroDifFrequency.size();
//            progressDialog->setRange(0, C5VXgyroDifFrequencyNum+C5VYgyroDifFrequencyNum+C5VZgyroDifFrequencyNum);
//            if(ui->checkBox_29->isChecked() == true)
//            {

//                QVector<double> C5VXgyroDifFrequency_save = C5VXgyroDifFrequency_bk + C5VXgyroDifFrequency;
//                dataOut<<tr("<X陀螺差频 p/s,")<<C5VXgyroDifFrequency_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VXgyroDifFrequency_save.size();i++)
//                {
//                    progressDialog->setValue(i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                       return;

//                    }
//                    dataOut<<C5VXgyroDifFrequency_save[i]<<",";
//                }
//                dataOut<<tr("\n</X陀螺差频>")<<"\n";
//            }
//            if(ui->checkBox_31->isChecked() == true)
//            {
//                QVector<double> C5VYgyroDifFrequency_save = C5VYgyroDifFrequency_bk + C5VYgyroDifFrequency;
//                dataOut<<tr("<Y陀螺差频 p/s,")<<C5VYgyroDifFrequency_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VYgyroDifFrequency_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXgyroDifFrequencyNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VYgyroDifFrequency_save[i]<<",";
//                }
//                dataOut<<tr("\n</Y陀螺差频>")<<"\n";
//            }
//            if(ui->checkBox_30->isChecked() == true)
//            {
//                QVector<double> C5VZgyroDifFrequency_save = C5VZgyroDifFrequency_bk + C5VZgyroDifFrequency;
//                dataOut<<tr("<Z陀螺差频 p/s,")<<C5VZgyroDifFrequency_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VZgyroDifFrequency_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXgyroDifFrequencyNum+C5VYgyroDifFrequencyNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VZgyroDifFrequency_save[i]<<",";
//                }
//                dataOut<<tr("\n</Z陀螺差频>")<<"\n";
//            }

//        }

//        if(1)//保存加速度计差频曲线
//        {
//            int C5VXaccelerometerDifFreNum = 0;
//            int C5VYaccelerometerDifFreNum = 0;
//            int C5VZaccelerometerDifFreNum = 0;

//            if(ui->checkBox_32->isChecked() == true)
//                C5VXaccelerometerDifFreNum += C5VXaccelerometerDifFre_bk.size() + C5VXaccelerometerDifFre.size();
//            if(ui->checkBox_33->isChecked() == true)
//                C5VYaccelerometerDifFreNum += C5VYaccelerometerDifFre_bk.size() + C5VYaccelerometerDifFre.size();
//            if(ui->checkBox_34->isChecked() == true)
//                C5VZaccelerometerDifFreNum += C5VZaccelerometerDifFre_bk.size() + C5VZaccelerometerDifFre.size();
//            progressDialog->setRange(0, C5VXaccelerometerDifFreNum+C5VYaccelerometerDifFreNum+C5VZaccelerometerDifFreNum);
//            if(ui->checkBox_32->isChecked() == true)
//            {
//                QVector<double> C5VXaccelerometerDifFre_save = C5VXaccelerometerDifFre_bk + C5VXaccelerometerDifFre;
//                dataOut<<tr("<X加速度计差频 p/s,")<<C5VXaccelerometerDifFre_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VXaccelerometerDifFre_save.size();i++)
//                {
//                    progressDialog->setValue(i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C5VXaccelerometerDifFre_save[i]<<",";
//                }
//                dataOut<<tr("\n</X加速度计差频>")<<"\n";
//            }
//            if(ui->checkBox_33->isChecked() == true)
//            {
//                QVector<double> C5VYaccelerometerDifFre_save = C5VYaccelerometerDifFre_bk + C5VYaccelerometerDifFre;
//                dataOut<<tr("<Y加速度计差频 p/s,")<<C5VYaccelerometerDifFre_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VYaccelerometerDifFre_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXaccelerometerDifFreNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                         return;

//                    }
//                    dataOut<<C5VYaccelerometerDifFre_save[i]<<",";
//                }
//                dataOut<<tr("\n</Y加速度计差频>")<<"\n";
//            }
//            if(ui->checkBox_34->isChecked() == true)
//            {
//                QVector<double> C5VZaccelerometerDifFre_save = C5VZaccelerometerDifFre_bk + C5VZaccelerometerDifFre;
//                dataOut<<tr("<Z加速度计差频 p/s,")<<C5VZaccelerometerDifFre_save.size()<<">"<<"\n";
//                for(int i = 0;i<C5VZaccelerometerDifFre_save.size();i++)
//                {
//                    progressDialog->setValue(C5VXaccelerometerDifFreNum+C5VYaccelerometerDifFreNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        if(ui->btn_openPort->text()=="关闭串口")
//                        return;

//                    }
//                    dataOut<<C5VZaccelerometerDifFre_save[i]<<",";
//                }
//                dataOut<<tr("\n</Z加速度计差频>")<<"\n";
//            }

//        }
//    }
//#endif
//    if(1)//保存陀螺温度1曲线
//    {
//        int C5VXgyroTemp1Num = 0;
//        int C5VYgyroTemp1Num = 0;
//         int C5VZgyroTemp1Num = 0;

//        if(ui->checkBox_37->isChecked() == true)
//            C5VXgyroTemp1Num += C5VXgyroTemp1_bk.size() + C5VXgyroTemp1.size();
//        if(ui->checkBox_35->isChecked() == true)
//            C5VYgyroTemp1Num += C5VYgyroTemp1_bk.size() + C5VYgyroTemp1.size();
//        if(ui->checkBox_36->isChecked() == true)
//            C5VZgyroTemp1Num += C5VZgyroTemp1_bk.size() + C5VZgyroTemp1.size();
//        progressDialog->setRange(0, C5VXgyroTemp1Num+C5VYgyroTemp1Num+C5VZgyroTemp1Num);
//        if(ui->checkBox_37->isChecked() == true)
//        {
//            QVector<double> C5VXgyroTemp1_save = C5VXgyroTemp1_bk + C5VXgyroTemp1;
//            dataOut<<tr("<X陀螺温度1 ℃,")<<C5VXgyroTemp1_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VXgyroTemp1_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VXgyroTemp1_save[i]<<",";
//            }
//            dataOut<<tr("\n</X陀螺温度1>")<<"\n";
//        }
//        if(ui->checkBox_35->isChecked() == true)
//        {
//            QVector<double> C5VYgyroTemp1_save = C5VYgyroTemp1_bk + C5VYgyroTemp1;
//            dataOut<<tr("<Y陀螺温度1 ℃,")<<C5VYgyroTemp1_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VYgyroTemp1_save.size();i++)
//            {
//                progressDialog->setValue(C5VXgyroTemp1Num+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VYgyroTemp1_save[i]<<",";
//            }
//            dataOut<<tr("\n</Y陀螺温度1>")<<"\n";
//        }
//        if(ui->checkBox_36->isChecked() == true)
//        {
//            QVector<double> C5VZgyroTemp1_save = C5VZgyroTemp1_bk + C5VZgyroTemp1;
//            dataOut<<tr("<Z陀螺温度1 ℃,")<<C5VZgyroTemp1_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VZgyroTemp1_save.size();i++)
//            {
//                progressDialog->setValue(C5VXgyroTemp1Num+C5VYgyroTemp1Num+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VZgyroTemp1_save[i]<<",";
//            }
//            dataOut<<tr("\n</Z陀螺温度1>")<<"\n";
//        }

//    }

//    if(1)//保存加速度计温度1曲线
//    {
//        int C5VXAccelerometerTempertureNum = 0;
//        int C5VYAccelerometerTempertureNum = 0;
//         int C5VZAccelerometerTempertureNum = 0;

//        if(ui->checkBox_40->isChecked() == true)
//            C5VXAccelerometerTempertureNum += C5VXAccelerometerTemperture_bk.size() + C5VXAccelerometerTemperture.size();
//        if(ui->checkBox_38->isChecked() == true)
//            C5VYAccelerometerTempertureNum += C5VYAccelerometerTemperture_bk.size() + C5VYAccelerometerTemperture.size();
//        if(ui->checkBox_39->isChecked() == true)
//            C5VZAccelerometerTempertureNum += C5VZAccelerometerTemperture_bk.size() + C5VZAccelerometerTemperture.size();
//        progressDialog->setRange(0, C5VXAccelerometerTempertureNum+C5VYAccelerometerTempertureNum+C5VZAccelerometerTempertureNum);
//        if(ui->checkBox_40->isChecked() == true)
//        {
//            QVector<double> C5VXAccelerometerTemperture_save = C5VXAccelerometerTemperture_bk + C5VXAccelerometerTemperture;
//            dataOut<<tr("<X加速度计温度1 ℃,")<<C5VXAccelerometerTemperture_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VXAccelerometerTemperture_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VXAccelerometerTemperture_save[i]<<",";
//            }
//            dataOut<<tr("\n</X加速度计温度1>")<<"\n";
//        }
//        if(ui->checkBox_38->isChecked() == true)
//        {
//            QVector<double> C5VYAccelerometerTemperture_save = C5VYAccelerometerTemperture_bk + C5VYAccelerometerTemperture;
//            dataOut<<tr("<Y加速度计温度1 ℃,")<<C5VYAccelerometerTemperture_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VYAccelerometerTemperture_save.size();i++)
//            {
//                progressDialog->setValue(C5VXAccelerometerTempertureNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VYAccelerometerTemperture_save[i]<<",";
//            }
//            dataOut<<tr("\n</Y加速度计温度1>")<<"\n";
//        }
//        if(ui->checkBox_39->isChecked() == true)
//        {
//            QVector<double> C5VZAccelerometerTemperture_save = C5VZAccelerometerTemperture_bk + C5VZAccelerometerTemperture;
//            dataOut<<tr("<Z加速度计温度1 ℃,")<<C5VZAccelerometerTemperture_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VZAccelerometerTemperture_save.size();i++)
//            {
//                progressDialog->setValue(C5VXAccelerometerTempertureNum+C5VYAccelerometerTempertureNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VZAccelerometerTemperture_save[i]<<",";
//            }
//            dataOut<<tr("\n</Z加速度计温度1>")<<"\n";
//        }

//    }
//    if(1)//保存陀螺温度2曲线
//    {
//        int C5VXgyroTemp2Num = 0;
//        int C5VYgyroTemp2Num = 0;
//         int C5VZgyroTemp2Num = 0;

//        if(ui->checkBox_42->isChecked() == true)
//            C5VXgyroTemp2Num += C5VXgyroTemp2_bk.size() + C5VXgyroTemp2.size();
//        if(ui->checkBox_43->isChecked() == true)
//            C5VYgyroTemp2Num += C5VYgyroTemp2_bk.size() + C5VYgyroTemp2.size();
//        if(ui->checkBox_41->isChecked() == true)
//            C5VZgyroTemp2Num += C5VZgyroTemp2_bk.size() + C5VZgyroTemp2.size();
//        progressDialog->setRange(0, C5VXgyroTemp2Num+C5VYgyroTemp2Num+C5VZgyroTemp2Num);
//        if(ui->checkBox_42->isChecked() == true)
//        {
//            QVector<double> C5VXgyroTemp2_save = C5VXgyroTemp2_bk + C5VXgyroTemp2;
//            dataOut<<tr("<X陀螺温度2 ℃,")<<C5VXgyroTemp2_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VXgyroTemp2_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VXgyroTemp2_save[i]<<",";
//            }
//            dataOut<<tr("\n</X陀螺温度2>")<<"\n";
//        }
//        if(ui->checkBox_43->isChecked() == true)
//        {
//            QVector<double> C5VYgyroTemp2_save = C5VYgyroTemp2_bk + C5VYgyroTemp2;
//            dataOut<<tr("<Y陀螺温度2 ℃,")<<C5VYgyroTemp2_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VYgyroTemp2_save.size();i++)
//            {
//                progressDialog->setValue(C5VXgyroTemp2Num+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VYgyroTemp2_save[i]<<",";
//            }
//            dataOut<<tr("\n</Y陀螺温度2>")<<"\n";
//        }
//        if(ui->checkBox_41->isChecked() == true)
//        {
//            QVector<double> C5VZgyroTemp2_save = C5VZgyroTemp2_bk + C5VZgyroTemp2;
//            dataOut<<tr("<Z陀螺温度2 ℃,")<<C5VZgyroTemp2_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VZgyroTemp2_save.size();i++)
//            {
//                progressDialog->setValue(C5VXgyroTemp2Num+C5VYgyroTemp2Num+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                   return;

//                }
//                dataOut<<C5VZgyroTemp2_save[i]<<",";
//            }
//            dataOut<<tr("\n</Z陀螺温度2>")<<"\n";
//        }

//    }
//    if(1)//保存陀螺抖幅曲线
//    {
//        int C5VXgyroAmplitudeJitterNum = 0;
//        int C5VYgyroAmplitudeJitterNum = 0;
//         int C5VZgyroAmplitudeJitterNum = 0;

//        if(ui->checkBox_45->isChecked() == true)
//            C5VXgyroAmplitudeJitterNum += C5VXgyroAmplitudeJitter_bk.size() + C5VXgyroAmplitudeJitter.size();
//        if(ui->checkBox_46->isChecked() == true)
//            C5VYgyroAmplitudeJitterNum += C5VYgyroAmplitudeJitter_bk.size() + C5VYgyroAmplitudeJitter.size();
//        if(ui->checkBox_44->isChecked() == true)
//            C5VZgyroAmplitudeJitterNum += C5VZgyroAmplitudeJitter_bk.size() + C5VZgyroAmplitudeJitter.size();
//        progressDialog->setRange(0, C5VXgyroAmplitudeJitterNum+C5VYgyroAmplitudeJitterNum+C5VZgyroAmplitudeJitterNum);
//        if(ui->checkBox_45->isChecked() == true)
//        {
//            QVector<double> C5VXgyroAmplitudeJitter_save = C5VXgyroAmplitudeJitter_bk + C5VXgyroAmplitudeJitter;
//            dataOut<<tr("<X陀螺抖幅 p/s,")<<C5VXgyroAmplitudeJitter_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VXgyroAmplitudeJitter_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VXgyroAmplitudeJitter_save[i]<<",";
//            }
//            dataOut<<tr("\n</X陀螺抖幅>")<<"\n";
//        }
//        if(ui->checkBox_46->isChecked() == true)
//        {
//            QVector<double> C5VYgyroAmplitudeJitter_save = C5VYgyroAmplitudeJitter_bk + C5VYgyroAmplitudeJitter;
//            dataOut<<tr("<Y陀螺抖幅 p/s,")<<C5VYgyroAmplitudeJitter_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VYgyroAmplitudeJitter_save.size();i++)
//            {
//                progressDialog->setValue(C5VXgyroAmplitudeJitterNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VYgyroAmplitudeJitter_save[i]<<",";
//            }
//            dataOut<<tr("\n</Y陀螺抖幅>")<<"\n";
//        }
//        if(ui->checkBox_44->isChecked() == true)
//        {
//            QVector<double> C5VZgyroAmplitudeJitter_save = C5VZgyroAmplitudeJitter_bk + C5VZgyroAmplitudeJitter;
//            dataOut<<tr("<Z陀螺抖幅 p/s,")<<C5VZgyroAmplitudeJitter_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VZgyroAmplitudeJitter_save.size();i++)
//            {
//                progressDialog->setValue(C5VXgyroAmplitudeJitterNum+C5VYgyroAmplitudeJitterNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VZgyroAmplitudeJitter_save[i]<<",";
//            }
//            dataOut<<tr("\n</Z陀螺抖幅>")<<"\n";
//        }

//    }

//    if(1)//保存陀螺抖频曲线
//    {
//        int C5VXgyroAmpl1itudeFreNum = 0;
//        int C5VYgyroAmpl1itudeFreNum = 0;
//         int C5VZgyroAmpl1itudeFreNum = 0;

//        if(ui->checkBox_48->isChecked() == true)
//            C5VXgyroAmpl1itudeFreNum += C5VXgyroAmpl1itudeFre_bk.size() + C5VXgyroAmpl1itudeFre.size();
//        if(ui->checkBox_49->isChecked() == true)
//            C5VYgyroAmpl1itudeFreNum += C5VYgyroAmpl1itudeFre_bk.size() + C5VYgyroAmpl1itudeFre.size();
//        if(ui->checkBox_47->isChecked() == true)
//            C5VZgyroAmpl1itudeFreNum += C5VZgyroAmpl1itudeFre_bk.size() + C5VZgyroAmpl1itudeFre.size();
//        progressDialog->setRange(0, C5VXgyroAmpl1itudeFreNum+C5VYgyroAmpl1itudeFreNum+C5VZgyroAmpl1itudeFreNum);
//        if(ui->checkBox_48->isChecked() == true)
//        {
//            QVector<double> C5VXgyroAmpl1itudeFre_save = C5VXgyroAmpl1itudeFre_bk + C5VXgyroAmpl1itudeFre;
//            dataOut<<tr("<X陀螺抖频 Hz,")<<C5VXgyroAmpl1itudeFre_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VXgyroAmpl1itudeFre_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                     return;

//                }
//                dataOut<<C5VXgyroAmpl1itudeFre_save[i]<<",";
//            }
//            dataOut<<tr("\n</X陀螺抖频>")<<"\n";
//        }
//        if(ui->checkBox_49->isChecked() == true)
//        {
//            QVector<double> C5VYgyroAmpl1itudeFre_save = C5VYgyroAmpl1itudeFre_bk + C5VYgyroAmpl1itudeFre;
//            dataOut<<tr("<Y陀螺抖频 Hz,")<<C5VYgyroAmpl1itudeFre_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VYgyroAmpl1itudeFre_save.size();i++)
//            {
//                progressDialog->setValue(C5VXgyroAmpl1itudeFreNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C5VYgyroAmpl1itudeFre_save[i]<<",";
//            }
//            dataOut<<tr("\n</Y陀螺抖频>")<<"\n";
//        }
//        if(ui->checkBox_47->isChecked() == true)
//        {
//            QVector<double> C5VZgyroAmpl1itudeFre_save = C5VZgyroAmpl1itudeFre_bk + C5VZgyroAmpl1itudeFre;
//            dataOut<<tr("<Z陀螺抖频 Hz,")<<C5VZgyroAmpl1itudeFre_save.size()<<">"<<"\n";
//            for(int i = 0;i<C5VZgyroAmpl1itudeFre_save.size();i++)
//            {
//                progressDialog->setValue(C5VXgyroAmpl1itudeFreNum+C5VYgyroAmpl1itudeFreNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                     return;

//                }
//                dataOut<<C5VZgyroAmpl1itudeFre_save[i]<<",";
//            }
//            dataOut<<tr("\n</Z陀螺抖频>")<<"\n";
//        }

//    }

//    if(1)//保存卫导曲线
//    {
//        int C3VlongitudeNum = 0;
//        int C3VGPSlatitudeNum = 0;
//         int C3VtogetherSpeedNum = 0;
//         int C3VheadingAngleNum = 0;
//         int C3VcombinedEastSpeedNum = 0;
//          int C3VcombinedNorthSpeedNum = 0;
//        if(ui->checkBox_54->isChecked() == true)
//            C3VlongitudeNum += C3Vlongitude_bk.size() + C3Vlongitude.size();
//        if(ui->checkBox_51->isChecked() == true)
//            C3VGPSlatitudeNum += C3VGPSlatitude_bk.size() + C3VGPSlatitude.size();
//        if(ui->checkBox_50->isChecked() == true)
//            C3VtogetherSpeedNum += C3VtogetherSpeed_bk.size() + C3VtogetherSpeed.size();

//        if(ui->checkBox_52->isChecked() == true)
//            C3VheadingAngleNum += C3VheadingAngle_bk.size() + C3VheadingAngle.size();
//        if(ui->checkBox_53->isChecked() == true)
//            C3VcombinedEastSpeedNum += C3VcombinedEastSpeed_bk.size() + C3VcombinedEastSpeed.size();
//        if(ui->checkBox_60->isChecked() == true)
//            C3VcombinedNorthSpeedNum += C3VcombinedNorthSpeed_bk.size() + C3VcombinedNorthSpeed.size();
//        progressDialog->setRange(0, C3VlongitudeNum+C3VGPSlatitudeNum+C3VtogetherSpeedNum+C3VheadingAngleNum+C3VcombinedEastSpeedNum+C3VcombinedNorthSpeedNum);
//        if(ui->checkBox_54->isChecked() == true)
//        {

//            QVector<double> C3Vlongitude_save = C3Vlongitude_bk + C3Vlongitude;
//            dataOut<<tr("<GPS经度 °,")<<C3Vlongitude_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3Vlongitude_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                   return;

//                }
//                dataOut<<C3Vlongitude_save[i]<<",";
//            }
//            dataOut<<tr("\n</GPS经度>")<<"\n";
//        }
//        if(ui->checkBox_51->isChecked() == true)
//        {
//            QVector<double> C3VGPSlatitude_save = C3VGPSlatitude_bk + C3VGPSlatitude;
//            dataOut<<tr("<GPS纬度 °,")<<C3VGPSlatitude_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VGPSlatitude_save.size();i++)
//            {
//                progressDialog->setValue(C3VlongitudeNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VGPSlatitude_save[i]<<",";
//            }
//            dataOut<<tr("\n</GPS纬度>")<<"\n";
//        }
//        if(ui->checkBox_50->isChecked() == true)
//        {
//            QVector<double> C3VtogetherSpeed_save = C3VtogetherSpeed_bk + C3VtogetherSpeed;
//            dataOut<<tr("<GPS合速 kn,")<<C3VtogetherSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VtogetherSpeed_save.size();i++)
//            {
//                progressDialog->setValue(C3VlongitudeNum+C3VGPSlatitudeNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VtogetherSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</GPS合速>")<<"\n";
//        }
//        if(ui->checkBox_52->isChecked() == true)
//        {
//            QVector<double> C3VheadingAngle_save = C3VheadingAngle_bk + C3VheadingAngle;
//            dataOut<<tr("<GPS航向 °,")<<C3VheadingAngle_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VheadingAngle_save.size();i++)
//            {
//                progressDialog->setValue(C3VlongitudeNum+C3VGPSlatitudeNum+C3VtogetherSpeedNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VheadingAngle_save[i]<<",";
//            }
//            dataOut<<tr("\n</GPS航向>")<<"\n";
//        }
//        if(ui->checkBox_53->isChecked() == true)
//        {
//            QVector<double> C3VcombinedEastSpeed_save = C3VcombinedEastSpeed_bk + C3VcombinedEastSpeed;
//            dataOut<<tr("<GPS东速 kn,")<<C3VcombinedEastSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VcombinedEastSpeed_save.size();i++)
//            {
//                progressDialog->setValue(C3VlongitudeNum+C3VGPSlatitudeNum+C3VtogetherSpeedNum+C3VheadingAngleNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VcombinedEastSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</GPS东速>")<<"\n";
//        }
//        if(ui->checkBox_60->isChecked() == true)
//        {
//            QVector<double> C3VcombinedNorthSpeed_save = C3VcombinedNorthSpeed_bk + C3VcombinedNorthSpeed;
//            dataOut<<tr("<GPS北速 kn,")<<C3VcombinedNorthSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VcombinedNorthSpeed_save.size();i++)
//            {
//                progressDialog->setValue(C3VlongitudeNum+C3VGPSlatitudeNum+C3VtogetherSpeedNum+C3VheadingAngleNum+C3VcombinedEastSpeedNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VcombinedNorthSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</GPS北速>")<<"\n";
//        }

//    }

//    if(1)//保存计程仪曲线
//    {
//        int C3VwaterXNum = 0;
//        int C3VwaterYNum = 0;
//        int C3VbottomXNum = 0;
//        int C3VbottomYNum = 0;
//        int C3VelectromagnetismSpeedNum = 0;

//        if(ui->checkBox_59->isChecked() == true)
//            C3VwaterXNum += C3VwaterX_bk.size() + C3VwaterX.size();
//        if(ui->checkBox_56->isChecked() == true)
//            C3VwaterYNum += C3VwaterY_bk.size() + C3VwaterY.size();
//        if(ui->checkBox_57->isChecked() == true)
//            C3VbottomXNum += C3VbottomX_bk.size() + C3VbottomX.size();

//        if(ui->checkBox_55->isChecked() == true)
//            C3VbottomYNum += C3VbottomY_bk.size() + C3VbottomY.size();
//        if(ui->checkBox_58->isChecked() == true)
//            C3VelectromagnetismSpeedNum += C3VelectromagnetismSpeed_bk.size() + C3VelectromagnetismSpeed.size();
//        progressDialog->setRange(0, C3VwaterXNum+C3VwaterYNum+C3VbottomXNum+C3VbottomYNum+C3VelectromagnetismSpeedNum);
//        if(ui->checkBox_59->isChecked() == true)
//        {

//            QVector<double> C3VwaterX_save = C3VwaterX_bk + C3VwaterX;
//            dataOut<<tr("<多普勒对水横向速度 kn,")<<C3VwaterX_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VwaterX_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VwaterX_save[i]<<",";
//            }
//            dataOut<<tr("\n</多普勒对水横向速度>")<<"\n";
//        }
//        if(ui->checkBox_56->isChecked() == true)
//        {
//            QVector<double> C3VwaterY_save = C3VwaterY_bk + C3VwaterY;
//            dataOut<<tr("<多普勒对水纵向速度 kn,")<<C3VwaterY_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VwaterY_save.size();i++)
//            {
//                progressDialog->setValue(C3VwaterXNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VwaterY_save[i]<<",";
//            }
//            dataOut<<tr("\n</多普勒对水纵向速度>")<<"\n";
//        }
//        if(ui->checkBox_57->isChecked() == true)
//        {
//            QVector<double> C3VbottomX_save = C3VbottomX_bk + C3VbottomX;
//            dataOut<<tr("<多普勒对底横向速度 kn,")<<C3VbottomX_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VbottomX_save.size();i++)
//            {
//                progressDialog->setValue(C3VwaterXNum+C3VwaterYNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VbottomX_save[i]<<",";
//            }
//            dataOut<<tr("\n</多普勒对底横向速度>")<<"\n";
//        }
//        if(ui->checkBox_55->isChecked() == true)
//        {
//            QVector<double> C3VbottomY_save = C3VbottomY_bk + C3VbottomY;
//            dataOut<<tr("<多普勒对底纵向速度 kn,")<<C3VbottomY_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VbottomY_save.size();i++)
//            {
//                progressDialog->setValue(C3VwaterXNum+C3VwaterYNum+C3VbottomXNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VbottomY_save[i]<<",";
//            }
//            dataOut<<tr("\n</多普勒对底纵向速度>")<<"\n";
//        }
//        if(ui->checkBox_58->isChecked() == true)
//        {
//            QVector<double> C3VelectromagnetismSpeed_save = C3VelectromagnetismSpeed_bk + C3VelectromagnetismSpeed;
//            dataOut<<tr("<电磁速度 kn,")<<C3VelectromagnetismSpeed_save.size()<<">"<<"\n";
//            for(int i = 0;i<C3VelectromagnetismSpeed_save.size();i++)
//            {
//                progressDialog->setValue(C3VwaterXNum+C3VwaterYNum+C3VbottomXNum+C3VbottomYNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<C3VelectromagnetismSpeed_save[i]<<",";
//            }
//            dataOut<<tr("\n</电磁速度>")<<"\n";
//        }
//    }
//#ifdef INSIDE
//    if(1)//不显示零偏曲线2022-01-20
//    {
//        if(1)//保存陀螺零偏曲线
//        {
//            int C6VC6XGroyFloatNum = 0;
//            int C6VC6YGroyFloatNum = 0;
//            int C6VC6ZGroyFloatNum = 0;

//            if(ui->checkBox_61->isChecked() == true)
//                C6VC6XGroyFloatNum += C6VC6XGroyFloat_bk.size() + C6VC6XGroyFloat.size();
//            if(ui->checkBox_63->isChecked() == true)
//                C6VC6YGroyFloatNum += C6VC6YGroyFloat_bk.size() + C6VC6YGroyFloat.size();
//            if(ui->checkBox_62->isChecked() == true)
//                C6VC6ZGroyFloatNum += C6VC6ZGroyFloat_bk.size() + C6VC6ZGroyFloat.size();
//            progressDialog->setRange(0, C6VC6XGroyFloatNum+C6VC6YGroyFloatNum+C6VC6ZGroyFloatNum);
//            if(ui->checkBox_61->isChecked() == true)
//            {
//                QVector<double> C6VC6XGroyFloat_save = C6VC6XGroyFloat_bk + C6VC6XGroyFloat;
//                dataOut<<tr("<X陀螺零偏 °/h,")<<C6VC6XGroyFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C6VC6XGroyFloat_save.size();i++)
//                {
//                    progressDialog->setValue(i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                       return;

//                    }
//                    dataOut<<C6VC6XGroyFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</X陀螺零偏>")<<"\n";
//            }
//            if(ui->checkBox_63->isChecked() == true)
//            {
//                QVector<double> C6VC6YGroyFloat_save = C6VC6YGroyFloat_bk + C6VC6YGroyFloat;
//                dataOut<<tr("<Y陀螺零偏 °/h,")<<C6VC6YGroyFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C6VC6YGroyFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C6VC6XGroyFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                       return;

//                    }
//                    dataOut<<C6VC6YGroyFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Y陀螺零偏>")<<"\n";
//            }
//            if(ui->checkBox_62->isChecked() == true)
//            {
//                QVector<double> C6VC6ZGroyFloat_save = C6VC6ZGroyFloat_bk + C6VC6ZGroyFloat;
//                dataOut<<tr("<Z陀螺零偏 °/h,")<<C6VC6ZGroyFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C6VC6ZGroyFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C6VC6XGroyFloatNum+C6VC6YGroyFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C6VC6ZGroyFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Z陀螺零偏>")<<"\n";
//            }
//        }
//        if(1)//保存加速度计零偏曲线
//        {
//            int C6VC6XAccelerometerFloatNum = 0;
//            int C6VC6YAccelerometerFloatNum = 0;
//            int C6VC6ZAccelerometerFloatNum = 0;

//            if(ui->checkBox_65->isChecked() == true)
//                C6VC6XAccelerometerFloatNum += C6VC6XAccelerometerFloat_bk.size() + C6VC6XAccelerometerFloat.size();
//            if(ui->checkBox_64->isChecked() == true)
//                C6VC6YAccelerometerFloatNum += C6VC6YAccelerometerFloat_bk.size() + C6VC6YAccelerometerFloat.size();
//            if(ui->checkBox_66->isChecked() == true)
//                C6VC6ZAccelerometerFloatNum += C6VC6ZAccelerometerFloat_bk.size() + C6VC6ZAccelerometerFloat.size();
//            progressDialog->setRange(0, C6VC6XAccelerometerFloatNum+C6VC6YAccelerometerFloatNum+C6VC6ZAccelerometerFloatNum);
//            if(ui->checkBox_65->isChecked() == true)
//            {
//                QVector<double> C6VC6XAccelerometerFloat_save = C6VC6XAccelerometerFloat_bk + C6VC6XAccelerometerFloat;
//                dataOut<<tr("<X加速度计零偏 mg,")<<C6VC6XAccelerometerFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C6VC6XAccelerometerFloat_save.size();i++)
//                {
//                    progressDialog->setValue(i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C6VC6XAccelerometerFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</X加速度计零偏>")<<"\n";
//            }
//            if(ui->checkBox_64->isChecked() == true)
//            {
//                QVector<double> C6VC6YAccelerometerFloat_save = C6VC6YAccelerometerFloat_bk + C6VC6YAccelerometerFloat;
//                dataOut<<tr("<Y加速度计零偏 mg,")<<C6VC6YAccelerometerFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C6VC6YAccelerometerFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C6VC6XAccelerometerFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                       return;

//                    }
//                    dataOut<<C6VC6YAccelerometerFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Y加速度计零偏>")<<"\n";
//            }
//            if(ui->checkBox_66->isChecked() == true)
//            {
//                QVector<double> C6VC6ZAccelerometerFloat_save = C6VC6ZAccelerometerFloat_bk + C6VC6ZAccelerometerFloat;
//                dataOut<<tr("<Z加速度计零偏 mg,")<<C6VC6ZAccelerometerFloat_save.size()<<">"<<"\n";
//                for(int i = 0;i<C6VC6ZAccelerometerFloat_save.size();i++)
//                {
//                    progressDialog->setValue(C6VC6XAccelerometerFloatNum+C6VC6YAccelerometerFloatNum+i);
//                    if(progressDialog->wasCanceled())
//                    {
//                        delete progressDialog;
//                        fileSave.close();
//                        fileSave.remove();
//                        return;

//                    }
//                    dataOut<<C6VC6ZAccelerometerFloat_save[i]<<",";
//                }
//                dataOut<<tr("\n</Z加速度计零偏>")<<"\n";
//            }
//        }
//    }
//#endif
//    if(1)//保存速度误差曲线
//    {
//        int VeastSpeedErrorNum = 0;
//        int VnorthSpeedErrorNum = 0;
//         int VtogetherSpeedErrorNum = 0;

//        if(ui->checkBox_67->isChecked() == true)
//            VeastSpeedErrorNum += VeastSpeedError_bk.size() + VeastSpeedError.size();
//        if(ui->checkBox_69->isChecked() == true)
//            VnorthSpeedErrorNum += VnorthSpeedError_bk.size() + VnorthSpeedError.size();
//        if(ui->checkBox_68->isChecked() == true)
//            VtogetherSpeedErrorNum += VtogetherSpeedError_bk.size() + VtogetherSpeedError.size();
//        progressDialog->setRange(0, VeastSpeedErrorNum+VnorthSpeedErrorNum+VtogetherSpeedErrorNum);
//        if(ui->checkBox_67->isChecked() == true)
//        {
//            QVector<double> VeastSpeedError_save = VeastSpeedError_bk + VeastSpeedError;
//            dataOut<<tr("<东速误差 kn,")<<VeastSpeedError_save.size()<<">"<<"\n";
//            for(int i = 0;i<VeastSpeedError_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                   return;

//                }
//                dataOut<<VeastSpeedError_save[i]<<",";
//            }
//            dataOut<<tr("\n</东速误差>")<<"\n";
//        }
//        if(ui->checkBox_68->isChecked() == true)
//        {
//            QVector<double> VnorthSpeedError_save = VnorthSpeedError_bk + VnorthSpeedError;
//            dataOut<<tr("<北速误差 kn,")<<VnorthSpeedError_save.size()<<">"<<"\n";
//            for(int i = 0;i<VnorthSpeedError_save.size();i++)
//            {
//                progressDialog->setValue(VeastSpeedErrorNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<VnorthSpeedError_save[i]<<",";
//            }
//            dataOut<<tr("\n</北速误差>")<<"\n";
//        }
//        if(ui->checkBox_68->isChecked() == true)
//        {
//            QVector<double> VtogetherSpeedError_save = VtogetherSpeedError_bk + VtogetherSpeedError;
//            dataOut<<tr("<合速误差 kn,")<<VtogetherSpeedError_save.size()<<">"<<"\n";
//            for(int i = 0;i<VtogetherSpeedError_save.size();i++)
//            {
//                progressDialog->setValue(VeastSpeedErrorNum+VnorthSpeedErrorNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                     return;

//                }
//                dataOut<<VtogetherSpeedError_save[i]<<",";
//            }
//            dataOut<<tr("\n</合速误差>")<<"\n";
//        }
//    }

//    if(1)//保存位置误差曲线
//    {
//        int VlatitudeErrorNum = 0;
//        int VlongitudeErrorNum = 0;
//         int VpositionErrorNum = 0;

//        if(ui->checkBox_70->isChecked() == true)
//            VlatitudeErrorNum += VlatitudeError_bk.size() + VlatitudeError.size();
//        if(ui->checkBox_72->isChecked() == true)
//            VlongitudeErrorNum += VlongitudeError_bk.size() + VlongitudeError.size();
//        if(ui->checkBox_71->isChecked() == true)
//            VpositionErrorNum += VpositionError_bk.size() + VpositionError.size();
//        progressDialog->setRange(0, VlatitudeErrorNum+VlongitudeErrorNum+VpositionErrorNum);
//        if(ui->checkBox_70->isChecked() == true)
//        {
//            QVector<double> VlatitudeError_save = VlatitudeError_bk + VlatitudeError;
//            dataOut<<tr("<纬度误差 nm,")<<VlatitudeError_save.size()<<">"<<"\n";
//            for(int i = 0;i<VlatitudeError_save.size();i++)
//            {
//                progressDialog->setValue(i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<VlatitudeError_save[i]<<",";
//            }
//            dataOut<<tr("\n</纬度误差>")<<"\n";
//        }
//        if(ui->checkBox_72->isChecked() == true)
//        {
//            QVector<double> VlongitudeError_save = VlongitudeError_bk + VlongitudeError;
//            dataOut<<tr("<经度误差 nm,")<<VlongitudeError_save.size()<<">"<<"\n";
//            for(int i = 0;i<VlongitudeError_save.size();i++)
//            {
//                progressDialog->setValue(VlatitudeErrorNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<VlongitudeError_save[i]<<",";
//            }
//            dataOut<<tr("\n</经度误差>")<<"\n";
//        }
//        if(ui->checkBox_71->isChecked() == true)
//        {
//            QVector<double> VpositionError_save = VpositionError_bk + VpositionError;
//            dataOut<<tr("<位置误差 nm,")<<VpositionError_save.size()<<">"<<"\n";
//            for(int i = 0;i<VpositionError_save.size();i++)
//            {
//                progressDialog->setValue(VlatitudeErrorNum+VlongitudeErrorNum+i);
//                if(progressDialog->wasCanceled())
//                {
//                    delete progressDialog;
//                    fileSave.close();
//                    fileSave.remove();
//                    return;

//                }
//                dataOut<<VpositionError_save[i]<<",";
//            }
//            dataOut<<tr("\n</位置误差>")<<"\n";
//        }
//    }

//    dataOut<<"</CurveProfile>";
//    fileSave.close();
//    delete progressDialog;
//    progressDialog = NULL;
//    QMessageBox::information(NULL, "提示", "保存成功！");
//    if(ui->btn_openPort->text()=="关闭串口")
//    {

//        serial_1->flush();

//    }

//}

void MainWindow::bookLog(QString bookStr)
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dayStr = current_date_time.toString("yyyy-MM-dd");
    //从界面中读取以前收到的数据
    QString oldString = ui->textBrowser->toPlainText();
    oldString = oldString + bookStr;
    //清空以前的显示
    ui->textBrowser->clear();
    //重新显示
    ui->textBrowser->append(oldString);
    QString fileName = tr("装订日志_")+dayStr;
    QFile fileSave(fileName);
   if(!fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
    {
        //无法打开要写入的文件
        QMessageBox::warning(this, tr("打开写入文件"),
                             tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
        return;
    }

    QTextStream dataOut(&fileSave);
    dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
    dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
    dataOut << bookStr;
    fileSave.close();

}
#ifdef QEXTSERIALPORT
void MainWindow::doDataSendWork(const QByteArray data)
{
        // 发送数据
    if(ui->btn_openPort->text()=="打开串口")
    {
        return;
    }
        serial_1->write(data);
}
#endif
void MainWindow::on_pushButton_11_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    sysHeightData->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    //判断打开串口是否打开

    sysBaseGData->show();
}

void MainWindow::on_pushButton_13_clicked()
{
    int saveCurveNum = 0;
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dayStr = current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
    QString dayStr2 = current_date_time.toString("yyyy-MM-dd");
    long totalCurveNum = 81;
    QProgressDialog *progressDialog = new QProgressDialog(this);
    QFont font("ZYSong18030", 12);
    progressDialog->setFont(font);
    progressDialog->setWindowModality(Qt::WindowModal);
    progressDialog->setMinimumDuration(5);
    progressDialog->setWindowTitle(tr("保存曲线"));
    progressDialog->setLabelText(tr("复制中..."));
    progressDialog->setCancelButtonText(tr("取消"));

    QDir dir;
    QString currentPath = "./curve/" + dayStr2;
    bool res = dir.mkpath(currentPath);
    if(!res)
    {
        QMessageBox::warning(NULL, "提示", "创建曲线文件夹失败！");
        return;
    }
    //保存所有曲线
    QString path = currentPath + "/curve_"+dayStr+".dat";
    if(path.isEmpty())
    {
        return;
    }
    QFile fileSave(path);
    if(!fileSave.open( QIODevice::WriteOnly ))
    {
        //无法打开要写入的文件
        QMessageBox::warning(this, tr("打开写入文件"),
                             tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
        return;
    }
    QTextStream dataOut(&fileSave);
    dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
    dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
    current_date_time =QDateTime::currentDateTime();
    
    QVector<double> C1Vlatitude_save = C1Vlatitude_bk + C1Vlatitude;
    QVector<double> C1Vlongitude_save = C1Vlongitude_bk + C1Vlongitude;
    
    QVector<double> C8VC8Height_save = C8VC8Height_bk + C8VC8Height;
    
    QVector<double> C6UndampedLatFloat_save = C6VC6UndampedLatFloat_bk + C6VC6UndampedLatFloat;
    
    QVector<double> C6UndampedLongFloat_save = C6VC6UndampedLongFloat_bk + C6VC6UndampedLongFloat;
    
    QVector<double> C6UndampedHeightFloat_save = C6VC6UndampedHeightFloat_bk + C6VC6UndampedHeightFloat;
    
    QVector<double> C1VheadingAngular_save = C1VheadingAngle + C1VheadingAngle_bk;
    
    QVector<double> C1VrollAngle_save = C1VrollAngle_bk + C1VrollAngle;
    
    QVector<double> C1VpitchAngle_save = C1VpitchAngle_bk + C1VpitchAngle;
    
    QVector<double> C6UndampedRollAngleFloat_save = C6VC6UndampedRollAngleFloat_bk + C6VC6UndampedRollAngleFloat;
    
    QVector<double> C6UndampedPitchAngleFloat_save = C6VC6UndampedPitchAngleFloat_bk + C6VC6UndampedPitchAngleFloat;
    
    QVector<double> C6UndampedHeadingAngularFloat_save = C6VC6UndampedHeadingAngularFloat_bk + C6VC6UndampedHeadingAngularFloat;
    
    QVector<double> C1VheadingAngularSpeed_save = C1VheadingAngularSpeed_bk + C1VheadingAngularSpeed;
    
    QVector<double> C1VrollAngleSpeed_save = C1VrollAngleSpeed_bk + C1VrollAngleSpeed;
    
    QVector<double> C1VpitchAngleSpeed_save = C1VpitchAngleSpeed_bk + C1VpitchAngleSpeed;
    
    QVector<double> C1VnorthSpeed_save = C1VnorthSpeed_bk + C1VnorthSpeed;
    
    QVector<double> C1VeastSpeed_save = C1VeastSpeed_bk + C1VeastSpeed;
    
    QVector<double> C8VC8UpSpeed_save = C8VC8UpSpeed_bk + C8VC8UpSpeed;
    
    QVector<double> C6UndampedNorthSpeedFloat_save = C6VC6UndampedNorthSpeedFloat_bk + C6VC6UndampedNorthSpeedFloat;
    
    QVector<double> C6UndampedEastSpeedFloat_save = C6VC6UndampedEastSpeedFloat_bk + C6VC6UndampedEastSpeedFloat;
    
    QVector<double> C6VerticalVelocityFloat_save = C6VC6VerticalVelocityFloat_bk + C6VC6VerticalVelocityFloat;
    
    QVector<double> C1Vheave_save = C1Vheave_bk + C1Vheave;
    
    QVector<double> C1VheaveC1VverticalVelocity_save = C1VverticalVelocity + C1VverticalVelocity_bk;
    
    QVector<double> C1Vsway_save = C1Vsway_bk + C1Vsway;
    
    QVector<double> C1VtransverseVelocity_save = C1VtransverseVelocity_bk + C1VtransverseVelocity;
    
    QVector<double> C1Vsurge_save = C1Vsurge_bk + C1Vsurge;
    
    QVector<double> C1VlongitudinalVelocity_save = C1VlongitudinalVelocity_bk + C1VlongitudinalVelocity;
    
    QVector<double> C5VXGyroAngleIncreaseFloat_save = C5VXGyroAngleIncreaseFloat_bk + C5VXGyroAngleIncreaseFloat;
    
    QVector<double> C5VYGyroAngleIncreaseFloat_save = C5VYGyroAngleIncreaseFloat_bk + C5VYGyroAngleIncreaseFloat;
    
    QVector<double> C5VZGyroAngleIncreaseFloat_save = C5VZGyroAngleIncreaseFloat_bk + C5VZGyroAngleIncreaseFloat;
    
    QVector<double> C5VXAccelerometerSpeedIncrementFloat_save = C5VXAccelerometerSpeedIncrementFloat_bk + C5VXAccelerometerSpeedIncrementFloat;
    
    QVector<double> C5VYAccelerometerSpeedIncrementFloat_save = C5VYAccelerometerSpeedIncrementFloat_bk + C5VYAccelerometerSpeedIncrementFloat;
    
    QVector<double> C5VZAccelerometerSpeedIncrementFloat_save = C5VZAccelerometerSpeedIncrementFloat_bk + C5VZAccelerometerSpeedIncrementFloat;
    
    QVector<double> C5VXgyroCompensatedAngleIncrementFloat_save = C5VXgyroCompensatedAngleIncrementFloat_bk + C5VXgyroCompensatedAngleIncrementFloat;
    
    QVector<double> C5VYgyroCompensatedAngleIncrementFloat_save = C5VYgyroCompensatedAngleIncrementFloat_bk + C5VYgyroCompensatedAngleIncrementFloat;
    
    QVector<double> C5VZgyroCompensatedAngleIncrementFloat_save = C5VZgyroCompensatedAngleIncrementFloat_bk + C5VZgyroCompensatedAngleIncrementFloat;
    
    QVector<double> C5VXAccVelocityIncrementFloat_save = C5VXAccVelocityIncrementFloat_bk + C5VXAccVelocityIncrementFloat;
    
    QVector<double> C5VYAccVelocityIncrementFloat_save = C5VYAccVelocityIncrementFloat_bk + C5VYAccVelocityIncrementFloat;
    
    QVector<double> C5VZAccVelocityIncrementFloat_save = C5VZAccVelocityIncrementFloat_bk + C5VZAccVelocityIncrementFloat;
    
    QVector<double> C5VXgyroDifFrequencyt_save = C5VXgyroDifFrequency_bk  + C5VXgyroDifFrequency;
    
    QVector<double> C5VYgyroDifFrequency_save = C5VYgyroDifFrequency_bk + C5VYgyroDifFrequency;
    
    QVector<double> C5VZgyroDifFrequency_save = C5VZgyroDifFrequency_bk + C5VZgyroDifFrequency;
    
    QVector<double> C5VXaccelerometerDifFre_save = C5VXaccelerometerDifFre_bk + C5VXaccelerometerDifFre;
    
    QVector<double> C5VYaccelerometerDifFre_save = C5VYaccelerometerDifFre_bk + C5VYaccelerometerDifFre;
    
    QVector<double> C5VZaccelerometerDifFre_save = C5VZaccelerometerDifFre_bk + C5VZaccelerometerDifFre;
    
    QVector<double> C5VXgyroTemp1_save = C5VXgyroTemp1_bk + C5VXgyroTemp1;
    
    QVector<double> C5VYgyroTemp1_save = C5VYgyroTemp1_bk + C5VYgyroTemp1;
    
    QVector<double> C5VZgyroTemp1_save = C5VZgyroTemp1_bk + C5VZgyroTemp1;
    
    QVector<double> C5VXAccelerometerTemperture_save = C5VXAccelerometerTemperture_bk + C5VXAccelerometerTemperture;
    
    QVector<double> C5VYAccelerometerTemperture_save = C5VYAccelerometerTemperture_bk + C5VYAccelerometerTemperture;
    
    QVector<double> C5VZAccelerometerTemperture_save = C5VZAccelerometerTemperture_bk + C5VZAccelerometerTemperture;
    
    QVector<double> C5VXgyroTemp2_save = C5VXgyroTemp2_bk + C5VXgyroTemp2;
    
    QVector<double> C5VYgyroTemp2_save = C5VYgyroTemp2_bk + C5VYgyroTemp2;
    
    QVector<double> C5VZgyroTemp2_save = C5VZgyroTemp2_bk + C5VZgyroTemp2;
    
    QVector<double> C5VXgyroAmplitudeJitter_save = C5VXgyroAmplitudeJitter_bk + C5VXgyroAmplitudeJitter;
    
    QVector<double> C5VYgyroAmplitudeJitter_save = C5VYgyroAmplitudeJitter_bk + C5VYgyroAmplitudeJitter;
    
    QVector<double> C5VZgyroAmplitudeJitter_save = C5VZgyroAmplitudeJitter_bk + C5VZgyroAmplitudeJitter;
    
    QVector<double> C5VXgyroAmpl1itudeFrer_save = C5VXgyroAmpl1itudeFre_bk + C5VXgyroAmpl1itudeFre;
    
    QVector<double> C5VYgyroAmpl1itudeFre_save = C5VYgyroAmpl1itudeFre_bk + C5VYgyroAmpl1itudeFre;
    
    QVector<double> C5VZgyroAmpl1itudeFre_save = C5VZgyroAmpl1itudeFre_bk + C5VZgyroAmpl1itudeFre;
    
    QVector<double> C3Vlongitude_save = C3Vlongitude_bk + C3Vlongitude;
    
    QVector<double> C3VGPSlatitude_save = C3VGPSlatitude_bk + C3VGPSlatitude;
    
    QVector<double> C8VC8GPSHeight_save = C8VC8GPSHeight_bk +C8VC8GPSHeight;
    
    QVector<double> C3VtogetherSpeed_save = C3VtogetherSpeed_bk + C3VtogetherSpeed;
    
    QVector<double> C3VheadingAngle_save = C3VheadingAngle_bk + C3VheadingAngle;
    
    QVector<double> C3VcombinedEastSpeed_save = C3VcombinedEastSpeed_bk + C3VcombinedEastSpeed;
    
    QVector<double> C3VcombinedNorthSpeed_save = C3VcombinedNorthSpeed_bk + C3VcombinedNorthSpeed;
    
    QVector<double> C8VC8GPTUpSpeed_save = C8VC8GPTUpSpeed_bk + C8VC8GPTUpSpeed;
    
    QVector<double> C3VwaterX_save = C3VwaterX_bk + C3VwaterX;
    
    QVector<double> C3VwaterY_save = C3VwaterY_bk + C3VwaterY;
    
    QVector<double> C3VbottomX_save = C3VbottomX_bk + C3VbottomX;
    
    QVector<double> C3VbottomY_save = C3VbottomY_bk + C3VbottomY;
    
    QVector<double> C3VelectromagnetismSpeed_save = C3VelectromagnetismSpeed_bk + C3VelectromagnetismSpeed;
    
    QVector<double> C8VC8LogDownSpeed2Ground_save = C8VC8LogDownSpeed2Ground_bk + C8VC8LogDownSpeed2Ground;
    
    QVector<double> C8VC8LogDownSpeed2Water_save = C8VC8LogDownSpeed2Water_bk + C8VC8LogDownSpeed2Water;
    
    QVector<double> C6VC6XGroyFloat_save = C6VC6XGroyFloat_bk + C6VC6XGroyFloat;
    
    QVector<double> C6VC6YGroyFloat_save = C6VC6YGroyFloat_bk + C6VC6YGroyFloat;
    
    QVector<double> C6VC6ZGroyFloat_save = C6VC6ZGroyFloat_bk + C6VC6ZGroyFloat;
    
    QVector<double> C6VC6XAccelerometerFloat_save = C6VC6XAccelerometerFloat_bk + C6VC6XAccelerometerFloat;
    
    QVector<double> C6VC6YAccelerometerFloat_save = C6VC6YAccelerometerFloat_bk + C6VC6YAccelerometerFloat;
    
    QVector<double> C6VC6ZAccelerometerFloat_save = C6VC6ZAccelerometerFloat_bk + C6VC6ZAccelerometerFloat;
    
    QVector<double> VeastSpeedError_save = VeastSpeedError_bk + VeastSpeedError;
    
    QVector<double> VnorthSpeedError_save = VnorthSpeedError_bk + VnorthSpeedError;
    
    QVector<double> VtogetherSpeedError_save = VtogetherSpeedError_bk + VtogetherSpeedError;
    
    QVector<double> VlatitudeError_save = VlatitudeError_bk + VlatitudeError;
    
    QVector<double> VlongitudeError_save = VlongitudeError_bk + VlongitudeError;
    
    QVector<double> VpositionError_save = VpositionError_bk + VpositionError;
    
    int iMaxi = findMaxRecord();
    progressDialog->setRange(0, iMaxi);
    dataOut<<"<CurveProfileNew>"<<","<<QString::number(iMaxi)<<"\n";
    for(int u64i = 1;u64i<=iMaxi;u64i++)
    {
        if(progressDialog->wasCanceled())
        {
            delete progressDialog;
            fileSave.close();
            fileSave.remove();

            return;
        }
        progressDialog->setValue(u64i);
        if(u64i<=C1Vlatitude_save.size())
            dataOut<<QString::number(C1Vlatitude_save[u64i-1],'f',5)<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1Vlongitude_save.size())
            dataOut<<QString::number(C1Vlongitude_save[u64i-1],'f',5)<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C8VC8Height_save.size())
            dataOut<<QString::number(C8VC8Height_save[u64i-1],'f',5)<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6UndampedLatFloat_save.size())
            dataOut<<QString::number(C6UndampedLatFloat_save[u64i-1],'f',5)<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6UndampedLongFloat_save.size())
            dataOut<<QString::number(C6UndampedLongFloat_save[u64i-1],'f',5)<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6UndampedHeightFloat_save.size())
            dataOut<<QString::number(C6UndampedHeightFloat_save[u64i-1],'f',5)<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VheadingAngular_save.size())
            dataOut<<QString::number(C1VheadingAngular_save[u64i-1],'f',4)<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VrollAngle_save.size())
            dataOut<<QString::number(C1VrollAngle_save[u64i-1],'f',4)<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VpitchAngle_save.size())
            dataOut<<C1VpitchAngle_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6UndampedRollAngleFloat_save.size())
            dataOut<<C6UndampedRollAngleFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6UndampedPitchAngleFloat_save.size())
            dataOut<<C6UndampedPitchAngleFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6UndampedHeadingAngularFloat_save.size())
            dataOut<<C6UndampedHeadingAngularFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VheadingAngularSpeed_save.size())
            dataOut<<C1VheadingAngularSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VrollAngleSpeed_save.size())
            dataOut<<C1VrollAngleSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VpitchAngleSpeed_save.size())
            dataOut<<C1VpitchAngleSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VnorthSpeed_save.size())
            dataOut<<C1VnorthSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VeastSpeed_save.size())
            dataOut<<C1VeastSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C8VC8UpSpeed_save.size())
            dataOut<<C8VC8UpSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6UndampedNorthSpeedFloat_save.size())
            dataOut<<C6UndampedNorthSpeedFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6UndampedEastSpeedFloat_save.size())
            dataOut<<C6UndampedEastSpeedFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6VerticalVelocityFloat_save.size())
            dataOut<<C6VerticalVelocityFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1Vheave_save.size())
            dataOut<<C1Vheave_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VheaveC1VverticalVelocity_save.size())
            dataOut<<C1VheaveC1VverticalVelocity_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1Vsway_save.size())
            dataOut<<C1Vsway_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VtransverseVelocity_save.size())
            dataOut<<C1VtransverseVelocity_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1Vsurge_save.size())
            dataOut<<C1Vsurge_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C1VlongitudinalVelocity_save.size())
            dataOut<<C1VlongitudinalVelocity_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXGyroAngleIncreaseFloat_save.size())
            dataOut<<C5VXGyroAngleIncreaseFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYGyroAngleIncreaseFloat_save.size())
            dataOut<<C5VYGyroAngleIncreaseFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZGyroAngleIncreaseFloat_save.size())
            dataOut<<C5VZGyroAngleIncreaseFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXAccelerometerSpeedIncrementFloat_save.size())
            dataOut<<C5VXAccelerometerSpeedIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYAccelerometerSpeedIncrementFloat_save.size())
            dataOut<<C5VYAccelerometerSpeedIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZAccelerometerSpeedIncrementFloat_save.size())
            dataOut<<C5VZAccelerometerSpeedIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXgyroCompensatedAngleIncrementFloat_save.size())
            dataOut<<C5VXgyroCompensatedAngleIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYgyroCompensatedAngleIncrementFloat_save.size())
            dataOut<<C5VYgyroCompensatedAngleIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZgyroCompensatedAngleIncrementFloat_save.size())
            dataOut<<C5VZgyroCompensatedAngleIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXAccVelocityIncrementFloat_save.size())
            dataOut<<C5VXAccVelocityIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYAccVelocityIncrementFloat_save.size())
            dataOut<<C5VYAccVelocityIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZAccVelocityIncrementFloat_save.size())
            dataOut<<C5VZAccVelocityIncrementFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXgyroDifFrequencyt_save.size())
            dataOut<<C5VXgyroDifFrequencyt_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYgyroDifFrequency_save.size())
            dataOut<<C5VYgyroDifFrequency_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZgyroDifFrequency_save.size())
            dataOut<<C5VZgyroDifFrequency_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXaccelerometerDifFre_save.size())
            dataOut<<C5VXaccelerometerDifFre_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYaccelerometerDifFre_save.size())
            dataOut<<C5VYaccelerometerDifFre_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZaccelerometerDifFre_save.size())
            dataOut<<C5VZaccelerometerDifFre_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXgyroTemp1_save.size())
            dataOut<<C5VXgyroTemp1_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYgyroTemp1_save.size())
            dataOut<<C5VYgyroTemp1_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }

        if(u64i<=C5VZgyroTemp1_save.size())
            dataOut<<C5VZgyroTemp1_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXAccelerometerTemperture_save.size())
            dataOut<<C5VXAccelerometerTemperture_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYAccelerometerTemperture_save.size())
            dataOut<<C5VYAccelerometerTemperture_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZAccelerometerTemperture_save.size())
            dataOut<<C5VZAccelerometerTemperture_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXgyroTemp2_save.size())
            dataOut<<C5VXgyroTemp2_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYgyroTemp2_save.size())
            dataOut<<C5VYgyroTemp2_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZgyroTemp2_save.size())
            dataOut<<C5VZgyroTemp2_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXgyroAmplitudeJitter_save.size())
            dataOut<<C5VXgyroAmplitudeJitter_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYgyroAmplitudeJitter_save.size())
            dataOut<<C5VYgyroAmplitudeJitter_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZgyroAmplitudeJitter_save.size())
            dataOut<<C5VZgyroAmplitudeJitter_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VXgyroAmpl1itudeFrer_save.size())
            dataOut<<C5VXgyroAmpl1itudeFrer_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VYgyroAmpl1itudeFre_save.size())
            dataOut<<C5VYgyroAmpl1itudeFre_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C5VZgyroAmpl1itudeFre_save.size())
            dataOut<<C5VZgyroAmpl1itudeFre_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VGPSlatitude_save.size())
            dataOut<<C3VGPSlatitude_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }

        if(u64i<=C3Vlongitude_save.size())
            dataOut<<C3Vlongitude_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C8VC8GPSHeight_save.size())
            dataOut<<C8VC8GPSHeight_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VtogetherSpeed_save.size())
            dataOut<<C3VtogetherSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VheadingAngle_save.size())
            dataOut<<C3VheadingAngle_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VcombinedEastSpeed_save.size())
            dataOut<<C3VcombinedEastSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VcombinedNorthSpeed_save.size())
            dataOut<<C3VcombinedNorthSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C8VC8GPTUpSpeed_save.size())
            dataOut<<C8VC8GPTUpSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VwaterX_save.size())
            dataOut<<C3VwaterX_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VwaterY_save.size())
            dataOut<<C3VwaterY_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VbottomX_save.size())
            dataOut<<C3VbottomX_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VbottomY_save.size())
            dataOut<<C3VbottomY_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C3VelectromagnetismSpeed_save.size())
            dataOut<<C3VelectromagnetismSpeed_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C8VC8LogDownSpeed2Ground_save.size())
            dataOut<<C8VC8LogDownSpeed2Ground_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C8VC8LogDownSpeed2Water_save.size())
            dataOut<<C8VC8LogDownSpeed2Water_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6VC6XGroyFloat_save.size())
            dataOut<<C6VC6XGroyFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6VC6YGroyFloat_save.size())
            dataOut<<C6VC6YGroyFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6VC6ZGroyFloat_save.size())
            dataOut<<C6VC6ZGroyFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6VC6XAccelerometerFloat_save.size())
            dataOut<<C6VC6XAccelerometerFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6VC6YAccelerometerFloat_save.size())
            dataOut<<C6VC6YAccelerometerFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=C6VC6ZAccelerometerFloat_save.size())
            dataOut<<C6VC6ZAccelerometerFloat_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=VeastSpeedError_save.size())
            dataOut<<VeastSpeedError_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=VnorthSpeedError_save.size())
            dataOut<<VnorthSpeedError_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=VtogetherSpeedError_save.size())
            dataOut<<VtogetherSpeedError_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=VlatitudeError_save.size())
            dataOut<<VlatitudeError_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=VlongitudeError_save.size())
            dataOut<<VlongitudeError_save[u64i-1]<<",";
        else
        {
            dataOut<<"N"<<",";
        }
        if(u64i<=VpositionError_save.size())
            dataOut<<VpositionError_save[u64i-1]<<","<<"\n";
        else
        {
            dataOut<<"N"<<","<<"\n";
        }

    }
    dataOut<<"</CurveProfileNew>";
    fileSave.close();

    delete progressDialog;
    progressDialog = NULL;
    QMessageBox::information(NULL, "提示", "保存成功！");

    if(ui->btn_openPort->text() !=QString("打开串口"))
    {
        serial_1->flush();
    }

}
int MainWindow::findMaxRecord()
{
    int iMaxRecord = 0;
    QVector<double> C1Vlatitude_save = C1Vlatitude_bk + C1Vlatitude;
    if(C1Vlatitude_save.size()>iMaxRecord)
        iMaxRecord = C1Vlatitude_save.size();
    QVector<double> C1Vlongitude_save = C1Vlongitude_bk + C1Vlongitude;
    if(C1Vlongitude_save.size()>iMaxRecord)
        iMaxRecord = C1Vlongitude_save.size();
    QVector<double> C8VC8Height_save = C8VC8Height_bk + C8VC8Height;
    if(C8VC8Height_save.size()>iMaxRecord)
        iMaxRecord = C8VC8Height_save.size();
    QVector<double> C6UndampedLatFloat_save = C6VC6UndampedLatFloat_bk + C6VC6UndampedLatFloat;
    if(C6UndampedLatFloat_save.size()>iMaxRecord)
        iMaxRecord = C6UndampedLatFloat_save.size();
    QVector<double> C6UndampedLongFloat_save = C6VC6UndampedLongFloat_bk + C6VC6UndampedLongFloat;
    if(C6UndampedLongFloat_save.size()>iMaxRecord)
        iMaxRecord = C6UndampedLongFloat_save.size();
    QVector<double> C6UndampedHeightFloat_save = C6VC6UndampedHeightFloat_bk + C6VC6UndampedHeightFloat;
    if(C6UndampedHeightFloat_save.size()>iMaxRecord)
        iMaxRecord = C6UndampedHeightFloat_save.size();
    QVector<double> C1VheadingAngular_save = C1VheadingAngle + C1VheadingAngle_bk;
    if(C1VheadingAngular_save.size()>iMaxRecord)
        iMaxRecord = C1VheadingAngular_save.size();
    QVector<double> C1VrollAngle_save = C1VrollAngle_bk + C1VrollAngle;
    if(C1VrollAngle_save.size()>iMaxRecord)
        iMaxRecord = C1VrollAngle_save.size();
    QVector<double> C1VpitchAngle_save = C1VpitchAngle_bk + C1VpitchAngle;
    if(C1VpitchAngle_save.size()>iMaxRecord)
        iMaxRecord = C1VpitchAngle_save.size();
    QVector<double> C6UndampedRollAngleFloat_save = C6VC6UndampedRollAngleFloat_bk + C6VC6UndampedRollAngleFloat;
    if(C6UndampedRollAngleFloat_save.size()>iMaxRecord)
        iMaxRecord = C6UndampedRollAngleFloat_save.size();
    QVector<double> C6UndampedPitchAngleFloat_save = C6VC6UndampedPitchAngleFloat_bk + C6VC6UndampedPitchAngleFloat;
    if(C6UndampedPitchAngleFloat_save.size()>iMaxRecord)
        iMaxRecord = C6UndampedPitchAngleFloat_save.size();
    QVector<double> C6UndampedHeadingAngularFloat_save = C6VC6UndampedHeadingAngularFloat_bk + C6VC6UndampedHeadingAngularFloat;
    if(C6UndampedHeadingAngularFloat_save.size()>iMaxRecord)
        iMaxRecord = C6UndampedHeadingAngularFloat_save.size();
    QVector<double> C1VheadingAngularSpeed_save = C1VheadingAngularSpeed_bk + C1VheadingAngularSpeed;
    if(C1VheadingAngularSpeed_save.size()>iMaxRecord)
        iMaxRecord = C1VheadingAngularSpeed_save.size();
    QVector<double> C1VrollAngleSpeed_save = C1VrollAngleSpeed_bk + C1VrollAngleSpeed;
    if(C1VrollAngleSpeed_save.size()>iMaxRecord)
        iMaxRecord = C1VrollAngleSpeed_save.size();
    QVector<double> C1VpitchAngleSpeed_save = C1VpitchAngleSpeed_bk + C1VpitchAngleSpeed;
    if(C1VpitchAngleSpeed_save.size()>iMaxRecord)
        iMaxRecord = C1VpitchAngleSpeed_save.size();
    QVector<double> C1VnorthSpeed_save = C1VnorthSpeed_bk + C1VnorthSpeed;
    if(C1VnorthSpeed_save.size()>iMaxRecord)
        iMaxRecord = C1VnorthSpeed_save.size();
    QVector<double> C1VeastSpeed_save = C1VeastSpeed_bk + C1VeastSpeed;
    if(C1VeastSpeed_save.size()>iMaxRecord)
        iMaxRecord = C1VeastSpeed_save.size();
    QVector<double> C8VC8UpSpeed_save = C8VC8UpSpeed_bk + C8VC8UpSpeed;
    if(C8VC8UpSpeed_save.size()>iMaxRecord)
        iMaxRecord = C8VC8UpSpeed_save.size();
    QVector<double> C6UndampedNorthSpeedFloat_save = C6VC6UndampedNorthSpeedFloat_bk + C6VC6UndampedNorthSpeedFloat;
    if(C6UndampedNorthSpeedFloat_save.size()>iMaxRecord)
        iMaxRecord = C6UndampedNorthSpeedFloat_save.size();
    QVector<double> C6UndampedEastSpeedFloat_save = C6VC6UndampedEastSpeedFloat_bk + C6VC6UndampedEastSpeedFloat;
    if(C6UndampedEastSpeedFloat_save.size()>iMaxRecord)
        iMaxRecord = C6UndampedEastSpeedFloat_save.size();
    QVector<double> C6VerticalVelocityFloat_save = C6VC6VerticalVelocityFloat_bk + C6VC6VerticalVelocityFloat;
    if(C6VerticalVelocityFloat_save.size()>iMaxRecord)
        iMaxRecord = C6VerticalVelocityFloat_save.size();
    QVector<double> C1Vheave_save = C1Vheave_bk + C1Vheave;
    if(C1Vheave_save.size()>iMaxRecord)
        iMaxRecord = C1Vheave_save.size();
    QVector<double> C1VheaveC1VverticalVelocity_save = C1VverticalVelocity + C1VverticalVelocity_bk;
    if(C1VheaveC1VverticalVelocity_save.size()>iMaxRecord)
        iMaxRecord = C1VheaveC1VverticalVelocity_save.size();
    QVector<double> C1Vsway_save = C1Vsway_bk + C1Vsway;
    if(C1Vsway_save.size()>iMaxRecord)
        iMaxRecord = C1Vsway_save.size();
    QVector<double> C1VtransverseVelocity_save = C1VtransverseVelocity_bk + C1VtransverseVelocity;
    if(C1VtransverseVelocity_save.size()>iMaxRecord)
        iMaxRecord = C1VtransverseVelocity_save.size();
    QVector<double> C1Vsurge_save = C1Vsurge_bk + C1Vsurge;
    if(C1Vsurge_save.size()>iMaxRecord)
        iMaxRecord = C1Vsurge_save.size();
    QVector<double> C1VlongitudinalVelocity_save = C1VlongitudinalVelocity_bk + C1VlongitudinalVelocity;
    if(C1VlongitudinalVelocity_save.size()>iMaxRecord)
        iMaxRecord = C1VlongitudinalVelocity_save.size();
    QVector<double> C5VXGyroAngleIncreaseFloat_save = C5VXGyroAngleIncreaseFloat_bk + C5VXGyroAngleIncreaseFloat;
    if(C5VXGyroAngleIncreaseFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VXGyroAngleIncreaseFloat_save.size();
    QVector<double> C5VYGyroAngleIncreaseFloat_save = C5VYGyroAngleIncreaseFloat_bk + C5VYGyroAngleIncreaseFloat;
    if(C5VYGyroAngleIncreaseFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VYGyroAngleIncreaseFloat_save.size();
    QVector<double> C5VZGyroAngleIncreaseFloat_save = C5VZGyroAngleIncreaseFloat_bk + C5VZGyroAngleIncreaseFloat;
    if(C5VZGyroAngleIncreaseFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VZGyroAngleIncreaseFloat_save.size();
    QVector<double> C5VXAccelerometerSpeedIncrementFloat_save = C5VXAccelerometerSpeedIncrementFloat_bk + C5VXAccelerometerSpeedIncrementFloat;
    if(C5VXAccelerometerSpeedIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VXAccelerometerSpeedIncrementFloat_save.size();
    QVector<double> C5VYAccelerometerSpeedIncrementFloat_save = C5VYAccelerometerSpeedIncrementFloat_bk + C5VYAccelerometerSpeedIncrementFloat;
    if(C5VYAccelerometerSpeedIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VYAccelerometerSpeedIncrementFloat_save.size();
    QVector<double> C5VZAccelerometerSpeedIncrementFloat_save = C5VZAccelerometerSpeedIncrementFloat_bk + C5VZAccelerometerSpeedIncrementFloat;
    if(C5VZAccelerometerSpeedIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VZAccelerometerSpeedIncrementFloat_save.size();
    QVector<double> C5VXgyroCompensatedAngleIncrementFloat_save = C5VXgyroCompensatedAngleIncrementFloat_bk + C5VXgyroCompensatedAngleIncrementFloat;
    if(C5VXgyroCompensatedAngleIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VXgyroCompensatedAngleIncrementFloat_save.size();
    QVector<double> C5VYgyroCompensatedAngleIncrementFloat_save = C5VYgyroCompensatedAngleIncrementFloat_bk + C5VYgyroCompensatedAngleIncrementFloat;
    if(C5VYgyroCompensatedAngleIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VYgyroCompensatedAngleIncrementFloat_save.size();
    QVector<double> C5VZgyroCompensatedAngleIncrementFloat_save = C5VZgyroCompensatedAngleIncrementFloat_bk + C5VZgyroCompensatedAngleIncrementFloat;
    if(C5VZgyroCompensatedAngleIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VZgyroCompensatedAngleIncrementFloat_save.size();
    QVector<double> C5VXAccVelocityIncrementFloat_save = C5VXAccVelocityIncrementFloat_bk + C5VXAccVelocityIncrementFloat;
    if(C5VXAccVelocityIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VXAccVelocityIncrementFloat_save.size();
    QVector<double> C5VYAccVelocityIncrementFloat_save = C5VYAccVelocityIncrementFloat_bk + C5VYAccVelocityIncrementFloat;
    if(C5VYAccVelocityIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VYAccVelocityIncrementFloat_save.size();
    QVector<double> C5VZAccVelocityIncrementFloat_save = C5VZAccVelocityIncrementFloat_bk + C5VZAccVelocityIncrementFloat;
    if(C5VZAccVelocityIncrementFloat_save.size()>iMaxRecord)
        iMaxRecord = C5VZAccVelocityIncrementFloat_save.size();
    QVector<double> C5VXgyroDifFrequencyt_save = C5VXgyroDifFrequency_bk  + C5VXgyroDifFrequency;
    if(C5VXgyroDifFrequencyt_save.size()>iMaxRecord)
        iMaxRecord = C5VXgyroDifFrequencyt_save.size();
    QVector<double> C5VYgyroDifFrequency_save = C5VYgyroDifFrequency_bk + C5VYgyroDifFrequency;
    if(C5VYgyroDifFrequency_save.size()>iMaxRecord)
        iMaxRecord = C5VYgyroDifFrequency_save.size();
    QVector<double> C5VZgyroDifFrequency_save = C5VZgyroDifFrequency_bk + C5VZgyroDifFrequency;
    if(C5VZgyroDifFrequency_save.size()>iMaxRecord)
        iMaxRecord = C5VZgyroDifFrequency_save.size();
    QVector<double> C5VXaccelerometerDifFre_save = C5VXaccelerometerDifFre_bk + C5VXaccelerometerDifFre;
    if(C5VXaccelerometerDifFre_save.size()>iMaxRecord)
        iMaxRecord = C5VXaccelerometerDifFre_save.size();
    QVector<double> C5VYaccelerometerDifFre_save = C5VYaccelerometerDifFre_bk + C5VYaccelerometerDifFre;
    if(C5VYaccelerometerDifFre_save.size()>iMaxRecord)
        iMaxRecord = C5VYaccelerometerDifFre_save.size();
    QVector<double> C5VZaccelerometerDifFre_save = C5VZaccelerometerDifFre_bk + C5VZaccelerometerDifFre;
    if(C5VZaccelerometerDifFre_save.size()>iMaxRecord)
        iMaxRecord = C5VZaccelerometerDifFre_save.size();
    QVector<double> C5VXgyroTemp1_save = C5VXgyroTemp1_bk + C5VXgyroTemp1;
    if(C5VXgyroTemp1_save.size()>iMaxRecord)
        iMaxRecord = C5VXgyroTemp1_save.size();
    QVector<double> C5VYgyroTemp1_save = C5VYgyroTemp1_bk + C5VYgyroTemp1;
    if(C5VYgyroTemp1_save.size()>iMaxRecord)
        iMaxRecord = C5VYgyroTemp1_save.size();
    QVector<double> C5VZgyroTemp1_save = C5VZgyroTemp1_bk + C5VZgyroTemp1;
    if(C5VZgyroTemp1_save.size()>iMaxRecord)
        iMaxRecord = C5VZgyroTemp1_save.size();
    QVector<double> C5VXAccelerometerTemperture_save = C5VXAccelerometerTemperture_bk + C5VXAccelerometerTemperture;
    if(C5VXAccelerometerTemperture_save.size()>iMaxRecord)
        iMaxRecord = C5VXAccelerometerTemperture_save.size();
    QVector<double> C5VYAccelerometerTemperture_save = C5VYAccelerometerTemperture_bk + C5VYAccelerometerTemperture;
    if(C5VYAccelerometerTemperture_save.size()>iMaxRecord)
        iMaxRecord = C5VYAccelerometerTemperture_save.size();
    QVector<double> C5VZAccelerometerTemperture_save = C5VZAccelerometerTemperture_bk + C5VZAccelerometerTemperture;
    if(C5VZAccelerometerTemperture_save.size()>iMaxRecord)
        iMaxRecord = C5VZAccelerometerTemperture_save.size();
    QVector<double> C5VXgyroTemp2_save = C5VXgyroTemp2_bk + C5VXgyroTemp2;
    if(C5VXgyroTemp2_save.size()>iMaxRecord)
        iMaxRecord = C5VXgyroTemp2_save.size();
    QVector<double> C5VYgyroTemp2_save = C5VYgyroTemp2_bk + C5VYgyroTemp2;
    if(C5VYgyroTemp2_save.size()>iMaxRecord)
        iMaxRecord = C5VYgyroTemp2_save.size();
    QVector<double> C5VZgyroTemp2_save = C5VZgyroTemp2_bk + C5VZgyroTemp2;
    if(C5VZgyroTemp2_save.size()>iMaxRecord)
        iMaxRecord = C5VZgyroTemp2_save.size();
    QVector<double> C5VXgyroAmplitudeJitter_save = C5VXgyroAmplitudeJitter_bk + C5VXgyroAmplitudeJitter;
    if(C5VXgyroAmplitudeJitter_save.size()>iMaxRecord)
        iMaxRecord = C5VXgyroAmplitudeJitter_save.size();
    QVector<double> C5VYgyroAmplitudeJitter_save = C5VYgyroAmplitudeJitter_bk + C5VYgyroAmplitudeJitter;
    if(C5VYgyroAmplitudeJitter_save.size()>iMaxRecord)
        iMaxRecord = C5VYgyroAmplitudeJitter_save.size();
    QVector<double> C5VZgyroAmplitudeJitter_save = C5VZgyroAmplitudeJitter_bk + C5VZgyroAmplitudeJitter;
    if(C5VZgyroAmplitudeJitter_save.size()>iMaxRecord)
        iMaxRecord = C5VZgyroAmplitudeJitter_save.size();
    QVector<double> C5VXgyroAmpl1itudeFrer_save = C5VXgyroAmpl1itudeFre_bk + C5VXgyroAmpl1itudeFre;
    if(C5VXgyroAmpl1itudeFrer_save.size()>iMaxRecord)
        iMaxRecord = C5VXgyroAmpl1itudeFrer_save.size();
    QVector<double> C5VYgyroAmpl1itudeFre_save = C5VYgyroAmpl1itudeFre_bk + C5VYgyroAmpl1itudeFre;
    if(C5VYgyroAmpl1itudeFre_save.size()>iMaxRecord)
        iMaxRecord = C5VYgyroAmpl1itudeFre_save.size();
    QVector<double> C5VZgyroAmpl1itudeFre_save = C5VZgyroAmpl1itudeFre_bk + C5VZgyroAmpl1itudeFre;
    if(C5VZgyroAmpl1itudeFre_save.size()>iMaxRecord)
        iMaxRecord = C5VZgyroAmpl1itudeFre_save.size();
    QVector<double> C3Vlongitude_save = C3Vlongitude_bk + C3Vlongitude;
    if(C3Vlongitude_save.size()>iMaxRecord)
        iMaxRecord = C3Vlongitude_save.size();
    QVector<double> C3VGPSlatitude_save = C3VGPSlatitude_bk + C3VGPSlatitude;
    if(C3VGPSlatitude_save.size()>iMaxRecord)
        iMaxRecord = C3VGPSlatitude_save.size();
    QVector<double> C8VC8GPSHeight_save = C8VC8GPSHeight_bk +C8VC8GPSHeight;
    if(C8VC8GPSHeight_save.size()>iMaxRecord)
        iMaxRecord = C8VC8GPSHeight_save.size();
    QVector<double> C3VtogetherSpeed_save = C3VtogetherSpeed_bk + C3VtogetherSpeed;
    if(C3VtogetherSpeed_save.size()>iMaxRecord)
        iMaxRecord = C3VtogetherSpeed_save.size();
    QVector<double> C3VheadingAngle_save = C3VheadingAngle_bk + C3VheadingAngle;
    if(C3VheadingAngle_save.size()>iMaxRecord)
        iMaxRecord = C3VheadingAngle_save.size();
    QVector<double> C3VcombinedEastSpeed_save = C3VcombinedEastSpeed_bk + C3VcombinedEastSpeed;
    if(C3VcombinedEastSpeed_save.size()>iMaxRecord)
        iMaxRecord = C3VcombinedEastSpeed_save.size();
    QVector<double> C3VcombinedNorthSpeed_save = C3VcombinedNorthSpeed_bk + C3VcombinedNorthSpeed;
    if(C3VcombinedNorthSpeed_save.size()>iMaxRecord)
        iMaxRecord = C3VcombinedNorthSpeed_save.size();
    QVector<double> C8VC8GPTUpSpeed_save = C8VC8GPTUpSpeed_bk + C8VC8GPTUpSpeed;
    if(C8VC8GPTUpSpeed_save.size()>iMaxRecord)
        iMaxRecord = C8VC8GPTUpSpeed_save.size();
    QVector<double> C3VwaterX_save = C3VwaterX_bk + C3VwaterX;
    if(C3VwaterX_save.size()>iMaxRecord)
        iMaxRecord = C3VwaterX_save.size();
    QVector<double> C3VwaterY_save = C3VwaterY_bk + C3VwaterY;
    if(C3VwaterY_save.size()>iMaxRecord)
        iMaxRecord = C3VwaterY_save.size();
    QVector<double> C3VbottomX_save = C3VbottomX_bk + C3VbottomX;
    if(C3VbottomX_save.size()>iMaxRecord)
        iMaxRecord = C3VbottomX_save.size();
    QVector<double> C3VbottomY_save = C3VbottomY_bk + C3VbottomY;
    if(C3VbottomY_save.size()>iMaxRecord)
        iMaxRecord = C3VbottomY_save.size();
    QVector<double> C3VelectromagnetismSpeed_save = C3VelectromagnetismSpeed_bk + C3VelectromagnetismSpeed;
    if(C3VelectromagnetismSpeed_save.size()>iMaxRecord)
        iMaxRecord = C3VelectromagnetismSpeed_save.size();
    QVector<double> C8VC8LogDownSpeed2Ground_save = C8VC8LogDownSpeed2Ground_bk + C8VC8LogDownSpeed2Ground;
    if(C8VC8LogDownSpeed2Ground_save.size()>iMaxRecord)
        iMaxRecord = C8VC8LogDownSpeed2Ground_save.size();
    QVector<double> C8VC8LogDownSpeed2Water_save = C8VC8LogDownSpeed2Water_bk + C8VC8LogDownSpeed2Water;
    if(C8VC8LogDownSpeed2Water_save.size()>iMaxRecord)
        iMaxRecord = C8VC8LogDownSpeed2Water_save.size();
    QVector<double> C6VC6XGroyFloat_save = C6VC6XGroyFloat_bk + C6VC6XGroyFloat;
    if(C6VC6XGroyFloat_save.size()>iMaxRecord)
        iMaxRecord = C6VC6XGroyFloat_save.size();
    QVector<double> C6VC6YGroyFloat_save = C6VC6YGroyFloat_bk + C6VC6YGroyFloat;
    if(C6VC6YGroyFloat_save.size()>iMaxRecord)
        iMaxRecord = C6VC6YGroyFloat_save.size();
    QVector<double> C6VC6ZGroyFloat_save = C6VC6ZGroyFloat_bk + C6VC6ZGroyFloat;
    if(C6VC6ZGroyFloat_save.size()>iMaxRecord)
        iMaxRecord = C6VC6ZGroyFloat_save.size();
    QVector<double> C6VC6XAccelerometerFloat_save = C6VC6XAccelerometerFloat_bk + C6VC6XAccelerometerFloat;
    if(C6VC6XAccelerometerFloat_save.size()>iMaxRecord)
        iMaxRecord = C6VC6XAccelerometerFloat_save.size();
    QVector<double> C6VC6YAccelerometerFloat_save = C6VC6YAccelerometerFloat_bk + C6VC6YAccelerometerFloat;
    if(C6VC6YAccelerometerFloat_save.size()>iMaxRecord)
        iMaxRecord = C6VC6YAccelerometerFloat_save.size();
    QVector<double> C6VC6ZAccelerometerFloat_save = C6VC6ZAccelerometerFloat_bk + C6VC6ZAccelerometerFloat;
    if(C6VC6ZAccelerometerFloat_save.size()>iMaxRecord)
        iMaxRecord = C6VC6ZAccelerometerFloat_save.size();
    QVector<double> VeastSpeedError_save = VeastSpeedError_bk + VeastSpeedError;
    if(VeastSpeedError_save.size()>iMaxRecord)
        iMaxRecord = VeastSpeedError_save.size();
    QVector<double> VnorthSpeedError_save = VnorthSpeedError_bk + VnorthSpeedError;
    if(VnorthSpeedError_save.size()>iMaxRecord)
        iMaxRecord = VnorthSpeedError_save.size();
    QVector<double> VtogetherSpeedError_save = VtogetherSpeedError_bk + VtogetherSpeedError;
    if(VtogetherSpeedError_save.size()>iMaxRecord)
        iMaxRecord = VtogetherSpeedError_save.size();
    QVector<double> VlatitudeError_save = VlatitudeError_bk + VlatitudeError;
    if(VlatitudeError_save.size()>iMaxRecord)
        iMaxRecord = VlatitudeError_save.size();
    QVector<double> VlongitudeError_save = VlongitudeError_bk + VlongitudeError;
    if(VlongitudeError_save.size()>iMaxRecord)
        iMaxRecord = VlongitudeError_save.size();
    QVector<double> VpositionError_save = VpositionError_bk + VpositionError;
    if(VpositionError_save.size()>iMaxRecord)
        iMaxRecord = VpositionError_save.size();

return iMaxRecord;

}
void MainWindow::on_action_3_triggered()
{
    isDegree = 1;
    ui->action_3->setChecked(true);
    ui->action_4->setChecked(false);

}

void MainWindow::on_action_4_triggered()
{
    isDegree = 0;
    ui->action_4->setChecked(true);
    ui->action_3->setChecked(false);

}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if(ui->btn_openPort->text() !=QString("打开串口"))
    {
        QMessageBox::warning(this,"关闭程序","请关闭串口后再退出！");
        e->ignore();

    }
}

void MainWindow::on_action_triggered()
{
    if(ui->action->isChecked() == false)
        ui->action->setChecked(false);
    else
        ui->action->setChecked(true);
}

void MainWindow::on_pushButton_15_clicked()
{
    int checkBoxNum = 0;
    int isReSet = 0;
    if(ui->checkBox->isChecked()) checkBoxNum++;
    if(ui->checkBox_2->isChecked())	checkBoxNum++;
    if(ui->checkBox_82->isChecked())	checkBoxNum++;
    if(ui->checkBox_3->isChecked())	checkBoxNum++;
    if(ui->checkBox_4->isChecked())	checkBoxNum++;
    if(ui->checkBox_5->isChecked())	checkBoxNum++;
    if(ui->checkBox_6->isChecked())	checkBoxNum++;
    if(ui->checkBox_7->isChecked())	checkBoxNum++;
    if(ui->checkBox_8->isChecked())	checkBoxNum++;
    if(ui->checkBox_9->isChecked())	checkBoxNum++;
    if(ui->checkBox_83->isChecked())	checkBoxNum++;
    if(ui->checkBox_10->isChecked())	checkBoxNum++;
    if(ui->checkBox_11->isChecked())	checkBoxNum++;
    if(ui->checkBox_12->isChecked())	checkBoxNum++;
    if(ui->checkBox_13->isChecked())	checkBoxNum++;
    if(ui->checkBox_14->isChecked())	checkBoxNum++;
    if(ui->checkBox_15->isChecked())	checkBoxNum++;
    if(ui->checkBox_16->isChecked())	checkBoxNum++;
    if(ui->checkBox_17->isChecked())	checkBoxNum++;
    if(ui->checkBox_18->isChecked())	checkBoxNum++;
    if(ui->checkBox_19->isChecked())	checkBoxNum++;
    if(ui->checkBox_20->isChecked())	checkBoxNum++;
    if(ui->checkBox_21->isChecked())	checkBoxNum++;
    if(ui->checkBox_22->isChecked())	checkBoxNum++;
    if(ui->checkBox_23->isChecked())	checkBoxNum++;
    if(ui->checkBox_24->isChecked())	checkBoxNum++;
    if(ui->checkBox_25->isChecked())	checkBoxNum++;
    if(ui->checkBox_26->isChecked())	checkBoxNum++;
    if(ui->checkBox_27->isChecked())	checkBoxNum++;
    if(ui->checkBox_28->isChecked())	checkBoxNum++;
    if(ui->checkBox_29->isChecked())	checkBoxNum++;
    if(ui->checkBox_30->isChecked())	checkBoxNum++;
    if(ui->checkBox_31->isChecked())	checkBoxNum++;
    if(ui->checkBox_32->isChecked())	checkBoxNum++;
    if(ui->checkBox_33->isChecked())	checkBoxNum++;
    if(ui->checkBox_34->isChecked())	checkBoxNum++;
    if(ui->checkBox_35->isChecked())	checkBoxNum++;
    if(ui->checkBox_36->isChecked())	checkBoxNum++;
    if(ui->checkBox_37->isChecked())	checkBoxNum++;
    if(ui->checkBox_38->isChecked())	checkBoxNum++;
    if(ui->checkBox_39->isChecked())	checkBoxNum++;
    if(ui->checkBox_40->isChecked())	checkBoxNum++;
    if(ui->checkBox_41->isChecked())	checkBoxNum++;
    if(ui->checkBox_42->isChecked())	checkBoxNum++;
    if(ui->checkBox_43->isChecked())	checkBoxNum++;
    if(ui->checkBox_44->isChecked())	checkBoxNum++;
    if(ui->checkBox_45->isChecked())	checkBoxNum++;
    if(ui->checkBox_46->isChecked())	checkBoxNum++;
    if(ui->checkBox_47->isChecked())	checkBoxNum++;
    if(ui->checkBox_48->isChecked())	checkBoxNum++;
    if(ui->checkBox_49->isChecked())	checkBoxNum++;
    if(ui->checkBox_50->isChecked())	checkBoxNum++;
    if(ui->checkBox_51->isChecked())	checkBoxNum++;
    if(ui->checkBox_52->isChecked())	checkBoxNum++;
    if(ui->checkBox_53->isChecked())	checkBoxNum++;
    if(ui->checkBox_54->isChecked())	checkBoxNum++;
    if(ui->checkBox_55->isChecked())	checkBoxNum++;
    if(ui->checkBox_56->isChecked())	checkBoxNum++;
    if(ui->checkBox_57->isChecked())	checkBoxNum++;
    if(ui->checkBox_58->isChecked())	checkBoxNum++;
    if(ui->checkBox_59->isChecked())	checkBoxNum++;
    if(ui->checkBox_60->isChecked())	checkBoxNum++;
    if(ui->checkBox_61->isChecked())	checkBoxNum++;
    if(ui->checkBox_62->isChecked())	checkBoxNum++;
    if(ui->checkBox_63->isChecked())	checkBoxNum++;
    if(ui->checkBox_64->isChecked())	checkBoxNum++;
    if(ui->checkBox_65->isChecked())	checkBoxNum++;
    if(ui->checkBox_66->isChecked())	checkBoxNum++;
    if(ui->checkBox_67->isChecked())	checkBoxNum++;
    if(ui->checkBox_68->isChecked())	checkBoxNum++;
    if(ui->checkBox_69->isChecked())	checkBoxNum++;
    if(ui->checkBox_70->isChecked())	checkBoxNum++;
    if(ui->checkBox_71->isChecked())	checkBoxNum++;
    if(ui->checkBox_72->isChecked())	checkBoxNum++;
    if(ui->checkBox_73->isChecked())	checkBoxNum++;
    if(ui->checkBox_74->isChecked())	checkBoxNum++;
    if(ui->checkBox_75->isChecked())	checkBoxNum++;
    if(ui->checkBox_76->isChecked())	checkBoxNum++;
    if(ui->checkBox_77->isChecked())	checkBoxNum++;
    if(ui->checkBox_78->isChecked())	checkBoxNum++;
    if(ui->checkBox_79->isChecked())	checkBoxNum++;
    if(ui->checkBox_80->isChecked())	checkBoxNum++;
    if(ui->checkBox_81->isChecked())	checkBoxNum++;
    if(ui->checkBox_84->isChecked())	checkBoxNum++;
    if(ui->checkBox_85->isChecked())	checkBoxNum++;
    if(ui->checkBox_86->isChecked())	checkBoxNum++;
    if(ui->checkBox_87->isChecked())	checkBoxNum++;
    if(checkBoxNum == 0)
    {
        return;
    }

    double biggest = -999999999;
    double smallest = 999999999;
    //经度、纬度
    if(ui->checkBox->isChecked())
    {
        auto C1Vlatitude_max = std::max_element(std::begin(C1Vlatitude), std::end(C1Vlatitude));
        auto C1Vlatitude_min = std::min_element(std::begin(C1Vlatitude), std::end(C1Vlatitude));

        if(*C1Vlatitude_max >= biggest)
            biggest = *C1Vlatitude_max;
        if(*C1Vlatitude_min <= smallest)
            smallest = *C1Vlatitude_min;
        isReSet = 1;
    }
    if(ui->checkBox_2->isChecked())
    {
        auto C1Vlongitude_max = std::max_element(std::begin(C1Vlongitude), std::end(C1Vlongitude));
        auto C1Vlongitude_min = std::min_element(std::begin(C1Vlongitude), std::end(C1Vlongitude));

        if(*C1Vlongitude_max >= biggest)
            biggest = *C1Vlongitude_max;
        if(*C1Vlongitude_min <= smallest)
            smallest = *C1Vlongitude_min;
        isReSet = 1;
    }
    if(ui->checkBox_82->isChecked())
    {
        auto C1Vlongitude_max = std::max_element(std::begin(C8VC8Height), std::end(C8VC8Height));
        auto C1Vlongitude_min = std::min_element(std::begin(C8VC8Height), std::end(C8VC8Height));

        if(*C1Vlongitude_max >= biggest)
            biggest = *C1Vlongitude_max;
        if(*C1Vlongitude_min <= smallest)
            smallest = *C1Vlongitude_min;
        isReSet = 1;
    }
    if(ui->checkBox_73->isChecked())
    {
        auto C6VC6UndampedLatFloat_max = std::max_element(std::begin(C6VC6UndampedLatFloat), std::end(C6VC6UndampedLatFloat));
        auto C6VC6UndampedLatFloat_min = std::min_element(std::begin(C6VC6UndampedLatFloat), std::end(C6VC6UndampedLatFloat));

        if(*C6VC6UndampedLatFloat_max >= biggest)
            biggest = *C6VC6UndampedLatFloat_max;
        if(*C6VC6UndampedLatFloat_min <= smallest)
            smallest = *C6VC6UndampedLatFloat_min;
        isReSet = 1;
    }
    if(ui->checkBox_74->isChecked())
    {
        auto C6VC6UndampedLongFloat_max = std::max_element(std::begin(C6VC6UndampedLongFloat), std::end(C6VC6UndampedLongFloat));
        auto C6VC6UndampedLongFloat_min = std::min_element(std::begin(C6VC6UndampedLongFloat), std::end(C6VC6UndampedLongFloat));

        if(*C6VC6UndampedLongFloat_max >= biggest)
            biggest = *C6VC6UndampedLongFloat_max;
        if(*C6VC6UndampedLongFloat_min <= smallest)
            smallest = *C6VC6UndampedLongFloat_min;
        isReSet = 1;
    }
    if(ui->checkBox_75->isChecked())
    {
        auto C6VC6UndampedHeightFloat_max = std::max_element(std::begin(C6VC6UndampedHeightFloat), std::end(C6VC6UndampedHeightFloat));
        auto C6VC6UndampedHeightFloat_min = std::min_element(std::begin(C6VC6UndampedHeightFloat), std::end(C6VC6UndampedHeightFloat));

        if(*C6VC6UndampedHeightFloat_max >= biggest)
            biggest = *C6VC6UndampedHeightFloat_max;
        if(*C6VC6UndampedHeightFloat_min <= smallest)
            smallest = *C6VC6UndampedHeightFloat_min;
        isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //航向、横摇、纵摇
    if(ui->checkBox_5->isChecked())
    {
        auto C1VheadingAngle_max = std::max_element(std::begin(C1VheadingAngle), std::end(C1VheadingAngle));
        auto C1VheadingAngle_min = std::min_element(std::begin(C1VheadingAngle), std::end(C1VheadingAngle));

        if(*C1VheadingAngle_max >= biggest)
            biggest = *C1VheadingAngle_max;
        if(*C1VheadingAngle_min <= smallest)
            smallest = *C1VheadingAngle_min;
        isReSet = 1;
    }
    if(ui->checkBox_3->isChecked())
    {
        auto C1VrollAngle_max = std::max_element(std::begin(C1VrollAngle), std::end(C1VrollAngle));
        auto C1VrollAngle_min = std::min_element(std::begin(C1VrollAngle), std::end(C1VrollAngle));

        if(*C1VrollAngle_max >= biggest)
            biggest = *C1VrollAngle_max;
        if(*C1VrollAngle_min <= smallest)
            smallest = *C1VrollAngle_min;
        isReSet = 1;
    }
    if(ui->checkBox_4->isChecked())
    {
        auto C1VpitchAngle_max = std::max_element(std::begin(C1VpitchAngle), std::end(C1VpitchAngle));
        auto C1VpitchAngle_min = std::min_element(std::begin(C1VpitchAngle), std::end(C1VpitchAngle));

        if(*C1VpitchAngle_max >= biggest)
            biggest = *C1VpitchAngle_max;
        if(*C1VpitchAngle_min <= smallest)
            smallest = *C1VpitchAngle_min;
        isReSet = 1;
    }
    if(ui->checkBox_79->isChecked())
    {
        auto C6VC6UndampedRollAngleFloat_max = std::max_element(std::begin(C6VC6UndampedRollAngleFloat), std::end(C6VC6UndampedRollAngleFloat));
        auto C6VC6UndampedRollAngleFloat_min = std::min_element(std::begin(C6VC6UndampedRollAngleFloat), std::end(C6VC6UndampedRollAngleFloat));

        if(*C6VC6UndampedRollAngleFloat_max >= biggest)
            biggest = *C6VC6UndampedRollAngleFloat_max;
        if(*C6VC6UndampedRollAngleFloat_min <= smallest)
            smallest = *C6VC6UndampedRollAngleFloat_min;
        isReSet = 1;
    }
    if(ui->checkBox_80->isChecked())
    {
        auto C6VC6UndampedPitchAngleFloat_max = std::max_element(std::begin(C6VC6UndampedPitchAngleFloat), std::end(C6VC6UndampedPitchAngleFloat));
        auto C6VC6UndampedPitchAngleFloat_min = std::min_element(std::begin(C6VC6UndampedPitchAngleFloat), std::end(C6VC6UndampedPitchAngleFloat));

        if(*C6VC6UndampedPitchAngleFloat_max >= biggest)
            biggest = *C6VC6UndampedPitchAngleFloat_max;
        if(*C6VC6UndampedPitchAngleFloat_min <= smallest)
            smallest = *C6VC6UndampedPitchAngleFloat_min;
        isReSet = 1;
    }
    if(ui->checkBox_81->isChecked())
    {
        auto C6VC6UndampedHeadingAngularFloat_max = std::max_element(std::begin(C6VC6UndampedHeadingAngularFloat), std::end(C6VC6UndampedHeadingAngularFloat));
        auto C6VC6UndampedHeadingAngularFloat_min = std::min_element(std::begin(C6VC6UndampedHeadingAngularFloat), std::end(C6VC6UndampedHeadingAngularFloat));

        if(*C6VC6UndampedHeadingAngularFloat_max >= biggest)
            biggest = *C6VC6UndampedHeadingAngularFloat_max;
        if(*C6VC6UndampedHeadingAngularFloat_min <= smallest)
            smallest = *C6VC6UndampedHeadingAngularFloat_min;
        isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //东速、北速
    if(ui->checkBox_9->isChecked())
    {
        auto C1VnorthSpeed_max = std::max_element(std::begin(C1VnorthSpeed), std::end(C1VnorthSpeed));
        auto C1VnorthSpeed_min = std::min_element(std::begin(C1VnorthSpeed), std::end(C1VnorthSpeed));

        if(*C1VnorthSpeed_max >= biggest)
            biggest = *C1VnorthSpeed_max;
        if(*C1VnorthSpeed_min <= smallest)
            smallest = *C1VnorthSpeed_min;
        isReSet = 1;
    }
    if(ui->checkBox_83->isChecked())
    {
        auto C1VnorthSpeed_max = std::max_element(std::begin(C8VC8UpSpeed), std::end(C8VC8UpSpeed));
        auto C1VnorthSpeed_min = std::min_element(std::begin(C8VC8UpSpeed), std::end(C8VC8UpSpeed));

        if(*C1VnorthSpeed_max >= biggest)
            biggest = *C1VnorthSpeed_max;
        if(*C1VnorthSpeed_min <= smallest)
            smallest = *C1VnorthSpeed_min;
        isReSet = 1;
    }
    if(ui->checkBox_10->isChecked())
    {
        auto C1VeastSpeed_max = std::max_element(std::begin(C1VeastSpeed), std::end(C1VeastSpeed));
        auto C1VeastSpeed_min = std::min_element(std::begin(C1VeastSpeed), std::end(C1VeastSpeed));

        if(*C1VeastSpeed_max >= biggest)
            biggest = *C1VeastSpeed_max;
        if(*C1VeastSpeed_min <= smallest)
            smallest = *C1VeastSpeed_min;
        isReSet = 1;
    }
    if(ui->checkBox_76->isChecked())
    {
        auto C6VC6UndampedNorthSpeedFloat_max = std::max_element(std::begin(C6VC6UndampedNorthSpeedFloat), std::end(C6VC6UndampedNorthSpeedFloat));
        auto C6VC6UndampedNorthSpeedFloat_min = std::min_element(std::begin(C6VC6UndampedNorthSpeedFloat), std::end(C6VC6UndampedNorthSpeedFloat));

        if(*C6VC6UndampedNorthSpeedFloat_max >= biggest)
            biggest = *C6VC6UndampedNorthSpeedFloat_max;
        if(*C6VC6UndampedNorthSpeedFloat_min <= smallest)
            smallest = *C6VC6UndampedNorthSpeedFloat_min;
        isReSet = 1;
    }
    if(ui->checkBox_77->isChecked())
    {
        auto C6VC6UndampedEastSpeedFloat_max = std::max_element(std::begin(C6VC6UndampedEastSpeedFloat), std::end(C6VC6UndampedEastSpeedFloat));
        auto C6VC6UndampedEastSpeedFloat_min = std::min_element(std::begin(C6VC6UndampedEastSpeedFloat), std::end(C6VC6UndampedEastSpeedFloat));

        if(*C6VC6UndampedEastSpeedFloat_max >= biggest)
            biggest = *C6VC6UndampedEastSpeedFloat_max;
        if(*C6VC6UndampedEastSpeedFloat_min <= smallest)
            smallest = *C6VC6UndampedEastSpeedFloat_min;
        isReSet = 1;
    }
    if(ui->checkBox_78->isChecked())
    {
        auto C6VC6VerticalVelocityFloat_max = std::max_element(std::begin(C6VC6VerticalVelocityFloat), std::end(C6VC6VerticalVelocityFloat));
        auto C6VC6VerticalVelocityFloat_min = std::min_element(std::begin(C6VC6VerticalVelocityFloat), std::end(C6VC6VerticalVelocityFloat));

        if(*C6VC6VerticalVelocityFloat_max >= biggest)
            biggest = *C6VC6VerticalVelocityFloat_max;
        if(*C6VC6VerticalVelocityFloat_min <= smallest)
            smallest = *C6VC6VerticalVelocityFloat_min;
        isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //航向角速度、横摇角速度、纵摇角速度
    if(ui->checkBox_6->isChecked())
    {
        auto C1VheadingAngularSpeed_max = std::max_element(std::begin(C1VheadingAngularSpeed), std::end(C1VheadingAngularSpeed));
        auto C1VheadingAngularSpeed_min = std::min_element(std::begin(C1VheadingAngularSpeed), std::end(C1VheadingAngularSpeed));

        if(*C1VheadingAngularSpeed_max >= biggest)
            biggest = *C1VheadingAngularSpeed_max;
        if(*C1VheadingAngularSpeed_min <= smallest)
            smallest = *C1VheadingAngularSpeed_min;
        isReSet = 1;
    }
    if(ui->checkBox_7->isChecked())
    {
        auto C1VrollAngleSpeed_max = std::max_element(std::begin(C1VrollAngleSpeed), std::end(C1VrollAngleSpeed));
        auto C1VrollAngleSpeed_min = std::min_element(std::begin(C1VrollAngleSpeed), std::end(C1VrollAngleSpeed));

        if(*C1VrollAngleSpeed_max >= biggest)
            biggest = *C1VrollAngleSpeed_max;
        if(*C1VrollAngleSpeed_min <= smallest)
            smallest = *C1VrollAngleSpeed_min;
        isReSet = 1;
    }
    if(ui->checkBox_8->isChecked())
    {
        auto C1VpitchAngle_max = std::max_element(std::begin(C1VpitchAngleSpeed), std::end(C1VpitchAngleSpeed));
        auto C1VpitchAngle_min = std::min_element(std::begin(C1VpitchAngleSpeed), std::end(C1VpitchAngleSpeed));

        if(*C1VpitchAngle_max >= biggest)
            biggest = *C1VpitchAngle_max;
        if(*C1VpitchAngle_min <= smallest)
            smallest = *C1VpitchAngle_min;
        isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //垂荡、垂速、横荡、横速、纵荡、纵速
    if(ui->checkBox_12->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(C1Vheave), std::end(C1Vheave));
        auto C1Vheave_min = std::min_element(std::begin(C1Vheave), std::end(C1Vheave));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
        isReSet = 1;
    }
    if(ui->checkBox_13->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(C1VverticalVelocity), std::end(C1VverticalVelocity));
        auto C1VverticalVelocity_min = std::min_element(std::begin(C1VverticalVelocity), std::end(C1VverticalVelocity));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
        isReSet = 1;
    }
    if(ui->checkBox_11->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(C1Vsway), std::end(C1Vsway));
        auto C1Vsway_min = std::min_element(std::begin(C1Vsway), std::end(C1Vsway));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;isReSet = 1;isReSet = 1;
    }
    if(ui->checkBox_15->isChecked())
    {
        auto C1VtransverseVelocity_max = std::max_element(std::begin(C1VtransverseVelocity), std::end(C1VtransverseVelocity));
        auto C1VtransverseVelocity_min = std::min_element(std::begin(C1VtransverseVelocity), std::end(C1VtransverseVelocity));

        if(*C1VtransverseVelocity_max >= biggest)
            biggest = *C1VtransverseVelocity_max;
        if(*C1VtransverseVelocity_min <= smallest)
            smallest = *C1VtransverseVelocity_min;isReSet = 1;isReSet = 1;
    }
    if(ui->checkBox_16->isChecked())
    {
        auto C1Vsurge_max = std::max_element(std::begin(C1Vsurge), std::end(C1Vsurge));
        auto C1Vsurge_min = std::min_element(std::begin(C1Vsurge), std::end(C1Vsurge));

        if(*C1Vsurge_max >= biggest)
            biggest = *C1Vsurge_max;
        if(*C1Vsurge_min <= smallest)
            smallest = *C1Vsurge_min;isReSet = 1;
    }
    if(ui->checkBox_14->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(C1Vsway), std::end(C1Vsway));
        auto C1Vsway_min = std::min_element(std::begin(C1Vsway), std::end(C1Vsway));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

#ifdef INSIDE
    if(1)//不显示增量和补偿增量2022-01-20
    {
        //X Y Z陀螺增量
        if(ui->checkBox_19->isChecked())
        {
            auto C5VXGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VXGyroAngleIncreaseFloat), std::end(C5VXGyroAngleIncreaseFloat));
            auto C5VXGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VXGyroAngleIncreaseFloat), std::end(C5VXGyroAngleIncreaseFloat));

            if(*C5VXGyroAngleIncreaseFloat_max >= biggest)
                biggest = *C5VXGyroAngleIncreaseFloat_max;
            if(*C5VXGyroAngleIncreaseFloat_min <= smallest)
                smallest = *C5VXGyroAngleIncreaseFloat_min;isReSet = 1;
        }
        if(ui->checkBox_18->isChecked())
        {
            auto C5VYGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VYGyroAngleIncreaseFloat), std::end(C5VYGyroAngleIncreaseFloat));
            auto C5VYGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VYGyroAngleIncreaseFloat), std::end(C5VYGyroAngleIncreaseFloat));

            if(*C5VYGyroAngleIncreaseFloat_max >= biggest)
                biggest = *C5VYGyroAngleIncreaseFloat_max;
            if(*C5VYGyroAngleIncreaseFloat_min <= smallest)
                smallest = *C5VYGyroAngleIncreaseFloat_min;isReSet = 1;
        }
        if(ui->checkBox_17->isChecked())
        {
            auto C5VZGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VZGyroAngleIncreaseFloat), std::end(C5VZGyroAngleIncreaseFloat));
            auto C5VZGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VZGyroAngleIncreaseFloat), std::end(C5VZGyroAngleIncreaseFloat));

            if(*C5VZGyroAngleIncreaseFloat_max >= biggest)
                biggest = *C5VZGyroAngleIncreaseFloat_max;
            if(*C5VZGyroAngleIncreaseFloat_min <= smallest)
                smallest = *C5VZGyroAngleIncreaseFloat_min;isReSet = 1;
        }
        if(isReSet == 1)
        {
            ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
            if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
            ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
            return;
        }

        //X Y Z加表增量
        if(ui->checkBox_20->isChecked())
        {
            auto C5VXAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VXAccelerometerSpeedIncrementFloat), std::end(C5VXAccelerometerSpeedIncrementFloat));
            auto C5VXAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VXAccelerometerSpeedIncrementFloat), std::end(C5VXAccelerometerSpeedIncrementFloat));

            if(*C5VXAccelerometerSpeedIncrementFloat_max >= biggest)
                biggest = *C5VXAccelerometerSpeedIncrementFloat_max;
            if(*C5VXAccelerometerSpeedIncrementFloat_min <= smallest)
                smallest = *C5VXAccelerometerSpeedIncrementFloat_min;isReSet = 1;
        }
        if(ui->checkBox_21->isChecked())
        {
            auto C5VYAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VYAccelerometerSpeedIncrementFloat), std::end(C5VYAccelerometerSpeedIncrementFloat));
            auto C5VYAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VYAccelerometerSpeedIncrementFloat), std::end(C5VYAccelerometerSpeedIncrementFloat));

            if(*C5VYAccelerometerSpeedIncrementFloat_max >= biggest)
                biggest = *C5VYAccelerometerSpeedIncrementFloat_max;
            if(*C5VYAccelerometerSpeedIncrementFloat_min <= smallest)
                smallest = *C5VYAccelerometerSpeedIncrementFloat_min;isReSet = 1;
        }
        if(ui->checkBox_22->isChecked())
        {
            auto C5VZAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VZAccelerometerSpeedIncrementFloat), std::end(C5VZAccelerometerSpeedIncrementFloat));
            auto C5VZAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VZAccelerometerSpeedIncrementFloat), std::end(C5VZAccelerometerSpeedIncrementFloat));

            if(*C5VZAccelerometerSpeedIncrementFloat_max >= biggest)
                biggest = *C5VZAccelerometerSpeedIncrementFloat_max;
            if(*C5VZAccelerometerSpeedIncrementFloat_min <= smallest)
                smallest = *C5VZAccelerometerSpeedIncrementFloat_min;isReSet = 1;
        }
        if(isReSet == 1)
        {
            ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
            if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
            ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
            return;
        }

        //X Y Z陀螺1s补偿后角增量
        if(ui->checkBox_23->isChecked())
        {
            auto C5VXAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VXgyroCompensatedAngleIncrementFloat), std::end(C5VXgyroCompensatedAngleIncrementFloat));
            auto C5VXAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VXgyroCompensatedAngleIncrementFloat), std::end(C5VXgyroCompensatedAngleIncrementFloat));

            if(*C5VXAccelerometerSpeedIncrementFloat_max >= biggest)
                biggest = *C5VXAccelerometerSpeedIncrementFloat_max;
            if(*C5VXAccelerometerSpeedIncrementFloat_min <= smallest)
                smallest = *C5VXAccelerometerSpeedIncrementFloat_min;isReSet = 1;
        }
        if(ui->checkBox_24->isChecked())
        {
            auto C5VYAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VYgyroCompensatedAngleIncrementFloat), std::end(C5VYgyroCompensatedAngleIncrementFloat));
            auto C5VYAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VYgyroCompensatedAngleIncrementFloat), std::end(C5VYgyroCompensatedAngleIncrementFloat));

            if(*C5VYAccelerometerSpeedIncrementFloat_max >= biggest)
                biggest = *C5VYAccelerometerSpeedIncrementFloat_max;
            if(*C5VYAccelerometerSpeedIncrementFloat_min <= smallest)
                smallest = *C5VYAccelerometerSpeedIncrementFloat_min;isReSet = 1;
        }
        if(ui->checkBox_25->isChecked())
        {
            auto C5VZAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VZgyroCompensatedAngleIncrementFloat), std::end(C5VZgyroCompensatedAngleIncrementFloat));
            auto C5VZAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VZgyroCompensatedAngleIncrementFloat), std::end(C5VZgyroCompensatedAngleIncrementFloat));

            if(*C5VZAccelerometerSpeedIncrementFloat_max >= biggest)
                biggest = *C5VZAccelerometerSpeedIncrementFloat_max;
            if(*C5VZAccelerometerSpeedIncrementFloat_min <= smallest)
                smallest = *C5VZAccelerometerSpeedIncrementFloat_min;isReSet = 1;
        }

        if(isReSet == 1)
        {
            ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
            if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
            ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
            return;
        }

        //X Y Z加速度计1s补偿后速度增量
        if(ui->checkBox_26->isChecked())
        {
            auto C5VXAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VXAccVelocityIncrementFloat), std::end(C5VXAccVelocityIncrementFloat));
            auto C5VXAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VXAccVelocityIncrementFloat), std::end(C5VXAccVelocityIncrementFloat));

            if(*C5VXAccVelocityIncrementFloat_max >= biggest)
                biggest = *C5VXAccVelocityIncrementFloat_max;
            if(*C5VXAccVelocityIncrementFloat_min <= smallest)
                smallest = *C5VXAccVelocityIncrementFloat_min;isReSet = 1;
        }
        if(ui->checkBox_27->isChecked())
        {
            auto C5VYAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VYAccVelocityIncrementFloat), std::end(C5VYAccVelocityIncrementFloat));
            auto C5VYAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VYAccVelocityIncrementFloat), std::end(C5VYAccVelocityIncrementFloat));

            if(*C5VYAccVelocityIncrementFloat_max >= biggest)
                biggest = *C5VYAccVelocityIncrementFloat_max;
            if(*C5VYAccVelocityIncrementFloat_min <= smallest)
                smallest = *C5VYAccVelocityIncrementFloat_min;isReSet = 1;
        }
        if(ui->checkBox_28->isChecked())
        {
            auto C5VZAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VZAccVelocityIncrementFloat), std::end(C5VZAccVelocityIncrementFloat));
            auto C5VZAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VZAccVelocityIncrementFloat), std::end(C5VZAccVelocityIncrementFloat));

            if(*C5VZAccVelocityIncrementFloat_max >= biggest)
                biggest = *C5VZAccVelocityIncrementFloat_max;
            if(*C5VZAccVelocityIncrementFloat_min <= smallest)
                smallest = *C5VZAccVelocityIncrementFloat_min;isReSet = 1;
        }
        if(isReSet == 1)
        {
            ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
            if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
            ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
            return;
        }
    }

    if(1)//不显示差频（原始脉冲）2022-01-20
    {
        //X Y Z陀螺差频
        if(ui->checkBox_29->isChecked())
        {
            auto C5VXgyroDifFrequency_max = std::max_element(std::begin(C5VXgyroDifFrequency), std::end(C5VXgyroDifFrequency));
            auto C5VXgyroDifFrequency_min = std::min_element(std::begin(C5VXgyroDifFrequency), std::end(C5VXgyroDifFrequency));

            if(*C5VXgyroDifFrequency_max >= biggest)
                biggest = *C5VXgyroDifFrequency_max;
            if(*C5VXgyroDifFrequency_min <= smallest)
                smallest = *C5VXgyroDifFrequency_min;isReSet = 1;
        }
        if(ui->checkBox_31->isChecked())
        {
            auto C5VYgyroDifFrequency_max = std::max_element(std::begin(C5VYgyroDifFrequency), std::end(C5VYgyroDifFrequency));
            auto C5VYgyroDifFrequency_min = std::min_element(std::begin(C5VYgyroDifFrequency), std::end(C5VYgyroDifFrequency));

            if(*C5VYgyroDifFrequency_max >= biggest)
                biggest = *C5VYgyroDifFrequency_max;
            if(*C5VYgyroDifFrequency_min <= smallest)
                smallest = *C5VYgyroDifFrequency_min;isReSet = 1;
        }
        if(ui->checkBox_30->isChecked())
        {
            auto C5VZgyroDifFrequency_max = std::max_element(std::begin(C5VZgyroDifFrequency), std::end(C5VZgyroDifFrequency));
            auto C5VZgyroDifFrequency_min = std::min_element(std::begin(C5VZgyroDifFrequency), std::end(C5VZgyroDifFrequency));

            if(*C5VZgyroDifFrequency_max >= biggest)
                biggest = *C5VZgyroDifFrequency_max;
            if(*C5VZgyroDifFrequency_min <= smallest)
                smallest = *C5VZgyroDifFrequency_min;isReSet = 1;
        }
        if(isReSet == 1)
        {
            ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
            if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
            ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
            return;
        }

        //X Y Z加速度计差频
        if(ui->checkBox_32->isChecked())
        {
            auto C5VXaccelerometerDifFre_max = std::max_element(std::begin(C5VXaccelerometerDifFre), std::end(C5VXaccelerometerDifFre));
            auto C5VXaccelerometerDifFre_min = std::min_element(std::begin(C5VXaccelerometerDifFre), std::end(C5VXaccelerometerDifFre));

            if(*C5VXaccelerometerDifFre_max >= biggest)
                biggest = *C5VXaccelerometerDifFre_max;
            if(*C5VXaccelerometerDifFre_min <= smallest)
                smallest = *C5VXaccelerometerDifFre_min;isReSet = 1;
        }
        if(ui->checkBox_33->isChecked())
        {
            auto C5VYaccelerometerDifFre_max = std::max_element(std::begin(C5VYaccelerometerDifFre), std::end(C5VYaccelerometerDifFre));
            auto C5VYaccelerometerDifFre_min = std::min_element(std::begin(C5VYaccelerometerDifFre), std::end(C5VYaccelerometerDifFre));

            if(*C5VYaccelerometerDifFre_max >= biggest)
                biggest = *C5VYaccelerometerDifFre_max;
            if(*C5VYaccelerometerDifFre_min <= smallest)
                smallest = *C5VYaccelerometerDifFre_min;isReSet = 1;
        }
        if(ui->checkBox_34->isChecked())
        {
            auto C5VZaccelerometerDifFre_max = std::max_element(std::begin(C5VZaccelerometerDifFre), std::end(C5VZaccelerometerDifFre));
            auto C5VZaccelerometerDifFre_min = std::min_element(std::begin(C5VZaccelerometerDifFre), std::end(C5VZaccelerometerDifFre));

            if(*C5VZaccelerometerDifFre_max >= biggest)
                biggest = *C5VZaccelerometerDifFre_max;
            if(*C5VZaccelerometerDifFre_min <= smallest)
                smallest = *C5VZaccelerometerDifFre_min;isReSet = 1;
        }
        if(isReSet == 1)
        {
            ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
            if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
            ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
            return;
        }
    }
#endif
    //X Y Z陀螺温度1数据
    if(ui->checkBox_37->isChecked())
    {
        auto C5VXgyroTemp1_max = std::max_element(std::begin(C5VXgyroTemp1), std::end(C5VXgyroTemp1));
        auto C5VXgyroTemp1_min = std::min_element(std::begin(C5VXgyroTemp1), std::end(C5VXgyroTemp1));

        if(*C5VXgyroTemp1_max >= biggest)
            biggest = *C5VXgyroTemp1_max;
        if(*C5VXgyroTemp1_min <= smallest)
            smallest = *C5VXgyroTemp1_min;isReSet = 1;
    }
    if(ui->checkBox_35->isChecked())
    {
        auto C5VYgyroTemp1_max = std::max_element(std::begin(C5VYgyroTemp1), std::end(C5VYgyroTemp1));
        auto C5VYgyroTemp1_min = std::min_element(std::begin(C5VYgyroTemp1), std::end(C5VYgyroTemp1));

        if(*C5VYgyroTemp1_max >= biggest)
            biggest = *C5VYgyroTemp1_max;
        if(*C5VYgyroTemp1_min <= smallest)
            smallest = *C5VYgyroTemp1_min;isReSet = 1;
    }
    if(ui->checkBox_36->isChecked())
    {
        auto C5VZgyroTemp1_max = std::max_element(std::begin(C5VZgyroTemp1), std::end(C5VZgyroTemp1));
        auto C5VZgyroTemp1_min = std::min_element(std::begin(C5VZgyroTemp1), std::end(C5VZgyroTemp1));

        if(*C5VZgyroTemp1_max >= biggest)
            biggest = *C5VZgyroTemp1_max;
        if(*C5VZgyroTemp1_min <= smallest)
            smallest = *C5VZgyroTemp1_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //X Y Z加速度计温度1数据
    if(ui->checkBox_40->isChecked())
    {
        auto C5VXAccelerometerTemperture_max = std::max_element(std::begin(C5VXAccelerometerTemperture), std::end(C5VXAccelerometerTemperture));
        auto C5VXAccelerometerTemperture_min = std::min_element(std::begin(C5VXAccelerometerTemperture), std::end(C5VXAccelerometerTemperture));

        if(*C5VXAccelerometerTemperture_max >= biggest)
            biggest = *C5VXAccelerometerTemperture_max;
        if(*C5VXAccelerometerTemperture_min <= smallest)
            smallest = *C5VXAccelerometerTemperture_min;isReSet = 1;
    }
    if(ui->checkBox_38->isChecked())
    {
        auto C5VYAccelerometerTemperture_max = std::max_element(std::begin(C5VYAccelerometerTemperture), std::end(C5VYAccelerometerTemperture));
        auto C5VYAccelerometerTemperture_min = std::min_element(std::begin(C5VYAccelerometerTemperture), std::end(C5VYAccelerometerTemperture));

        if(*C5VYAccelerometerTemperture_max >= biggest)
            biggest = *C5VYAccelerometerTemperture_max;
        if(*C5VYAccelerometerTemperture_min <= smallest)
            smallest = *C5VYAccelerometerTemperture_min;isReSet = 1;
    }
    if(ui->checkBox_39->isChecked())
    {
        auto C5VZAccelerometerTemperture_max = std::max_element(std::begin(C5VZAccelerometerTemperture), std::end(C5VZAccelerometerTemperture));
        auto C5VZAccelerometerTemperture_min = std::min_element(std::begin(C5VZAccelerometerTemperture), std::end(C5VZAccelerometerTemperture));

        if(*C5VZAccelerometerTemperture_max >= biggest)
            biggest = *C5VZAccelerometerTemperture_max;
        if(*C5VZAccelerometerTemperture_min <= smallest)
            smallest = *C5VZAccelerometerTemperture_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //X Y Z陀螺温度2数据
    if(ui->checkBox_42->isChecked())
    {
        auto C5VXgyroTemp2_max = std::max_element(std::begin(C5VXgyroTemp2), std::end(C5VXgyroTemp2));
        auto C5VXgyroTemp2_min = std::min_element(std::begin(C5VXgyroTemp2), std::end(C5VXgyroTemp2));

        if(*C5VXgyroTemp2_max >= biggest)
            biggest = *C5VXgyroTemp2_max;
        if(*C5VXgyroTemp2_min <= smallest)
            smallest = *C5VXgyroTemp2_min;isReSet = 1;
    }
    if(ui->checkBox_43->isChecked())
    {
        auto C5VYgyroTemp2_max = std::max_element(std::begin(C5VYgyroTemp2), std::end(C5VYgyroTemp2));
        auto C5VYgyroTemp2_min = std::min_element(std::begin(C5VYgyroTemp2), std::end(C5VYgyroTemp2));

        if(*C5VYgyroTemp2_max >= biggest)
            biggest = *C5VYgyroTemp2_max;
        if(*C5VYgyroTemp2_min <= smallest)
            smallest = *C5VYgyroTemp2_min;isReSet = 1;
    }
    if(ui->checkBox_41->isChecked())
    {
        auto C5VZgyroTemp2_max = std::max_element(std::begin(C5VZgyroTemp2), std::end(C5VZgyroTemp2));
        auto C5VZgyroTemp2_min = std::min_element(std::begin(C5VZgyroTemp2), std::end(C5VZgyroTemp2));

        if(*C5VZgyroTemp2_max >= biggest)
            biggest = *C5VZgyroTemp2_max;
        if(*C5VZgyroTemp2_min <= smallest)
            smallest = *C5VZgyroTemp2_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //X Y Z陀螺抖幅数据
    if(ui->checkBox_45->isChecked())
    {
        auto C5VXgyroAmplitudeJitter_max = std::max_element(std::begin(C5VXgyroAmplitudeJitter), std::end(C5VXgyroAmplitudeJitter));
        auto C5VXgyroAmplitudeJitter_min = std::min_element(std::begin(C5VXgyroAmplitudeJitter), std::end(C5VXgyroAmplitudeJitter));

        if(*C5VXgyroAmplitudeJitter_max >= biggest)
            biggest = *C5VXgyroAmplitudeJitter_max;
        if(*C5VXgyroAmplitudeJitter_min <= smallest)
            smallest = *C5VXgyroAmplitudeJitter_min;isReSet = 1;
    }
    if(ui->checkBox_46->isChecked())
    {
        auto C5VYgyroAmplitudeJitter_max = std::max_element(std::begin(C5VYgyroAmplitudeJitter), std::end(C5VYgyroAmplitudeJitter));
        auto C5VYgyroAmplitudeJitter_min = std::min_element(std::begin(C5VYgyroAmplitudeJitter), std::end(C5VYgyroAmplitudeJitter));

        if(*C5VYgyroAmplitudeJitter_max >= biggest)
            biggest = *C5VYgyroAmplitudeJitter_max;
        if(*C5VYgyroAmplitudeJitter_min <= smallest)
            smallest = *C5VYgyroAmplitudeJitter_min;isReSet = 1;
    }
    if(ui->checkBox_44->isChecked())
    {
        auto C5VZgyroAmplitudeJitter_max = std::max_element(std::begin(C5VZgyroAmplitudeJitter), std::end(C5VZgyroAmplitudeJitter));
        auto C5VZgyroAmplitudeJitter_min = std::min_element(std::begin(C5VZgyroAmplitudeJitter), std::end(C5VZgyroAmplitudeJitter));

        if(*C5VZgyroAmplitudeJitter_max >= biggest)
            biggest = *C5VZgyroAmplitudeJitter_max;
        if(*C5VZgyroAmplitudeJitter_min <= smallest)
            smallest = *C5VZgyroAmplitudeJitter_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //X Y Z陀螺抖频数据
    if(ui->checkBox_48->isChecked())
    {
        auto C5VXgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VXgyroAmpl1itudeFre), std::end(C5VXgyroAmpl1itudeFre));
        auto C5VXgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VXgyroAmpl1itudeFre), std::end(C5VXgyroAmpl1itudeFre));

        if(*C5VXgyroAmpl1itudeFre_max >= biggest)
            biggest = *C5VXgyroAmpl1itudeFre_max;
        if(*C5VXgyroAmpl1itudeFre_min <= smallest)
            smallest = *C5VXgyroAmpl1itudeFre_min;isReSet = 1;
    }
    if(ui->checkBox_49->isChecked())
    {
        auto C5VYgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VYgyroAmpl1itudeFre), std::end(C5VYgyroAmpl1itudeFre));
        auto C5VYgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VYgyroAmpl1itudeFre), std::end(C5VYgyroAmpl1itudeFre));

        if(*C5VYgyroAmpl1itudeFre_max >= biggest)
            biggest = *C5VYgyroAmpl1itudeFre_max;
        if(*C5VYgyroAmpl1itudeFre_min <= smallest)
            smallest = *C5VYgyroAmpl1itudeFre_min;isReSet = 1;
    }
    if(ui->checkBox_47->isChecked())
    {
        auto C5VZgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VZgyroAmpl1itudeFre), std::end(C5VZgyroAmpl1itudeFre));
        auto C5VZgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VZgyroAmpl1itudeFre), std::end(C5VZgyroAmpl1itudeFre));

        if(*C5VZgyroAmpl1itudeFre_max >= biggest)
            biggest = *C5VZgyroAmpl1itudeFre_max;
        if(*C5VZgyroAmpl1itudeFre_min <= smallest)
            smallest = *C5VZgyroAmpl1itudeFre_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //GPS纬度
    if(ui->checkBox_51->isChecked())
    {
        auto C3VGPSlatitude_max = std::max_element(std::begin(C3VGPSlatitude), std::end(C3VGPSlatitude));
        auto C3VGPSlatitude_min = std::min_element(std::begin(C3VGPSlatitude), std::end(C3VGPSlatitude));

        if(*C3VGPSlatitude_max >= biggest)
            biggest = *C3VGPSlatitude_max;
        if(*C3VGPSlatitude_min <= smallest)
            smallest = *C3VGPSlatitude_min;isReSet = 1;
    }
    if(ui->checkBox_54->isChecked())
    {
        auto C3Vlongitude_max = std::max_element(std::begin(C3Vlongitude), std::end(C3Vlongitude));
        auto C3Vlongitude_min = std::min_element(std::begin(C3Vlongitude), std::end(C3Vlongitude));

        if(*C3Vlongitude_max >= biggest)
            biggest = *C3Vlongitude_max;
        if(*C3Vlongitude_min <= smallest)
            smallest = *C3Vlongitude_min;isReSet = 1;
    }
    if(ui->checkBox_50->isChecked())
    {
        auto C3VtogetherSpeed_max = std::max_element(std::begin(C3VtogetherSpeed), std::end(C3VtogetherSpeed));
        auto C3VtogetherSpeed_min = std::min_element(std::begin(C3VtogetherSpeed), std::end(C3VtogetherSpeed));

        if(*C3VtogetherSpeed_max >= biggest)
            biggest = *C3VtogetherSpeed_max;
        if(*C3VtogetherSpeed_min <= smallest)
            smallest = *C3VtogetherSpeed_min;isReSet = 1;
    }

    if(ui->checkBox_52->isChecked())
    {
        auto C3VheadingAngle_max = std::max_element(std::begin(C3VheadingAngle), std::end(C3VheadingAngle));
        auto C3VheadingAngle_min = std::min_element(std::begin(C3VheadingAngle), std::end(C3VheadingAngle));

        if(*C3VheadingAngle_max >= biggest)
            biggest = *C3VheadingAngle_max;
        if(*C3VheadingAngle_min <= smallest)
            smallest = *C3VheadingAngle_min;isReSet = 1;
    }
    if(ui->checkBox_53->isChecked())
    {
        auto C3VcombinedEastSpeed_max = std::max_element(std::begin(C3VcombinedEastSpeed), std::end(C3VcombinedEastSpeed));
        auto C3VcombinedEastSpeed_min = std::min_element(std::begin(C3VcombinedEastSpeed), std::end(C3VcombinedEastSpeed));

        if(*C3VcombinedEastSpeed_max >= biggest)
            biggest = *C3VcombinedEastSpeed_max;
        if(*C3VcombinedEastSpeed_min <= smallest)
            smallest = *C3VcombinedEastSpeed_min;isReSet = 1;
    }
    if(ui->checkBox_60->isChecked())
    {
        auto C3VcombinedNorthSpeed_max = std::max_element(std::begin(C3VcombinedNorthSpeed), std::end(C3VcombinedNorthSpeed));
        auto C3VcombinedNorthSpeed_min = std::min_element(std::begin(C3VcombinedNorthSpeed), std::end(C3VcombinedNorthSpeed));

        if(*C3VcombinedNorthSpeed_max >= biggest)
            biggest = *C3VcombinedNorthSpeed_max;
        if(*C3VcombinedNorthSpeed_min <= smallest)
            smallest = *C3VcombinedNorthSpeed_min;isReSet = 1;
    }
    if(ui->checkBox_84->isChecked())
    {
        auto C8VC8GPSHeight_max = std::max_element(std::begin(C8VC8GPSHeight), std::end(C8VC8GPSHeight));
        auto C8VC8GPSHeight_min = std::min_element(std::begin(C8VC8GPSHeight), std::end(C8VC8GPSHeight));

        if(*C8VC8GPSHeight_max >= biggest)
            biggest = *C8VC8GPSHeight_max;
        if(*C8VC8GPSHeight_min <= smallest)
            smallest = *C8VC8GPSHeight_min;isReSet = 1;
    }
    if(ui->checkBox_87->isChecked())
    {
        auto C8VC8GPTUpSpeed_max = std::max_element(std::begin(C8VC8GPTUpSpeed), std::end(C8VC8GPTUpSpeed));
        auto C8VC8GPTUpSpeed_min = std::min_element(std::begin(C8VC8GPTUpSpeed), std::end(C8VC8GPTUpSpeed));

        if(*C8VC8GPTUpSpeed_max >= biggest)
            biggest = *C8VC8GPTUpSpeed_max;
        if(*C8VC8GPTUpSpeed_min <= smallest)
            smallest = *C8VC8GPTUpSpeed_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C3curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //多普勒,电磁
    if(ui->checkBox_59->isChecked())
    {
        auto C3VwaterX_max = std::max_element(std::begin(C3VwaterX), std::end(C3VwaterX));
        auto C3VwaterX_min = std::min_element(std::begin(C3VwaterX), std::end(C3VwaterX));

        if(*C3VwaterX_max >= biggest)
            biggest = *C3VwaterX_max;
        if(*C3VwaterX_min <= smallest)
            smallest = *C3VwaterX_min;isReSet = 1;
    }
    if(ui->checkBox_56->isChecked())
    {
        auto C3VwaterY_max = std::max_element(std::begin(C3VwaterY), std::end(C3VwaterY));
        auto C3VwaterY_min = std::min_element(std::begin(C3VwaterY), std::end(C3VwaterY));

        if(*C3VwaterY_max >= biggest)
            biggest = *C3VwaterY_max;
        if(*C3VwaterY_min <= smallest)
            smallest = *C3VwaterY_min;isReSet = 1;
    }

    if(ui->checkBox_57->isChecked())
    {
        auto C3VbottomX_max = std::max_element(std::begin(C3VbottomX), std::end(C3VbottomX));
        auto C3VbottomX_min = std::min_element(std::begin(C3VbottomX), std::end(C3VbottomX));

        if(*C3VbottomX_max >= biggest)
            biggest = *C3VbottomX_max;
        if(*C3VbottomX_min <= smallest)
            smallest = *C3VbottomX_min;isReSet = 1;
    }
    if(ui->checkBox_55->isChecked())
    {
        auto C3VbottomY_max = std::max_element(std::begin(C3VbottomY), std::end(C3VbottomY));
        auto C3VbottomY_min = std::min_element(std::begin(C3VbottomY), std::end(C3VbottomY));

        if(*C3VbottomY_max >= biggest)
            biggest = *C3VbottomY_max;
        if(*C3VbottomY_min <= smallest)
            smallest = *C3VbottomY_min;isReSet = 1;
    }
    if(ui->checkBox_58->isChecked())
    {
        auto C3VelectromagnetismSpeed_max = std::max_element(std::begin(C3VelectromagnetismSpeed), std::end(C3VelectromagnetismSpeed));
        auto C3VelectromagnetismSpeed_min = std::min_element(std::begin(C3VelectromagnetismSpeed), std::end(C3VelectromagnetismSpeed));

        if(*C3VelectromagnetismSpeed_max >= biggest)
            biggest = *C3VelectromagnetismSpeed_max;
        if(*C3VelectromagnetismSpeed_min <= smallest)
            smallest = *C3VelectromagnetismSpeed_min;isReSet = 1;
    }
    if(ui->checkBox_85->isChecked())
    {
        auto C3VelectromagnetismSpeed_max = std::max_element(std::begin(C8VC8LogDownSpeed2Water), std::end(C8VC8LogDownSpeed2Water));
        auto C3VelectromagnetismSpeed_min = std::min_element(std::begin(C8VC8LogDownSpeed2Water), std::end(C8VC8LogDownSpeed2Water));

        if(*C3VelectromagnetismSpeed_max >= biggest)
            biggest = *C3VelectromagnetismSpeed_max;
        if(*C3VelectromagnetismSpeed_min <= smallest)
            smallest = *C3VelectromagnetismSpeed_min;isReSet = 1;
    }
    if(ui->checkBox_86->isChecked())
    {
        auto C3VelectromagnetismSpeed_max = std::max_element(std::begin(C8VC8LogDownSpeed2Ground), std::end(C8VC8LogDownSpeed2Ground));
        auto C3VelectromagnetismSpeed_min = std::min_element(std::begin(C8VC8LogDownSpeed2Ground), std::end(C8VC8LogDownSpeed2Ground));

        if(*C3VelectromagnetismSpeed_max >= biggest)
            biggest = *C3VelectromagnetismSpeed_max;
        if(*C3VelectromagnetismSpeed_min <= smallest)
            smallest = *C3VelectromagnetismSpeed_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C3curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

#ifdef INSIDE
    if(1)
    {
        //X Y Z陀螺零偏
        if(ui->checkBox_61->isChecked())
        {
            auto C6VC6XGroyFloat_max = std::max_element(std::begin(C6VC6XGroyFloat), std::end(C6VC6XGroyFloat));
            auto C6VC6XGroyFloat_min = std::min_element(std::begin(C6VC6XGroyFloat), std::end(C6VC6XGroyFloat));

            if(*C6VC6XGroyFloat_max >= biggest)
                biggest = *C6VC6XGroyFloat_max;
            if(*C6VC6XGroyFloat_min <= smallest)
                smallest = *C6VC6XGroyFloat_min;isReSet = 1;
        }
        if(ui->checkBox_63->isChecked())
        {
            auto C6VC6YGroyFloat_max = std::max_element(std::begin(C6VC6YGroyFloat), std::end(C6VC6YGroyFloat));
            auto C6VC6YGroyFloat_min = std::min_element(std::begin(C6VC6YGroyFloat), std::end(C6VC6YGroyFloat));

            if(*C6VC6YGroyFloat_max >= biggest)
                biggest = *C6VC6YGroyFloat_max;
            if(*C6VC6YGroyFloat_min <= smallest)
                smallest = *C6VC6YGroyFloat_min;isReSet = 1;
        }
        if(ui->checkBox_62->isChecked())
        {
            auto C6VC6ZGroyFloat_max = std::max_element(std::begin(C6VC6ZGroyFloat), std::end(C6VC6ZGroyFloat));
            auto C6VC6ZGroyFloat_min = std::min_element(std::begin(C6VC6ZGroyFloat), std::end(C6VC6ZGroyFloat));

            if(*C6VC6ZGroyFloat_max >= biggest)
                biggest = *C6VC6ZGroyFloat_max;
            if(*C6VC6ZGroyFloat_min <= smallest)
                smallest = *C6VC6ZGroyFloat_min;isReSet = 1;
        }
        if(isReSet == 1)
        {
            ui->customPlot2->xAxis->setRange(0, C6curveX.size()*1.5, Qt::AlignLeft);
            if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
            ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
            return;
        }

        //X Y Z加速度计零偏
        if(ui->checkBox_65->isChecked())
        {
            auto C6VC6XAccelerometerFloat_max = std::max_element(std::begin(C6VC6XAccelerometerFloat), std::end(C6VC6XAccelerometerFloat));
            auto C6VC6XAccelerometerFloat_min = std::min_element(std::begin(C6VC6XAccelerometerFloat), std::end(C6VC6XAccelerometerFloat));

            if(*C6VC6XAccelerometerFloat_max >= biggest)
                biggest = *C6VC6XAccelerometerFloat_max;
            if(*C6VC6XAccelerometerFloat_min <= smallest)
                smallest = *C6VC6XAccelerometerFloat_min;isReSet = 1;
        }
        if(ui->checkBox_64->isChecked())
        {
            auto C6VC6YAccelerometerFloat_max = std::max_element(std::begin(C6VC6YAccelerometerFloat), std::end(C6VC6YAccelerometerFloat));
            auto C6VC6YAccelerometerFloat_min = std::min_element(std::begin(C6VC6YAccelerometerFloat), std::end(C6VC6YAccelerometerFloat));

            if(*C6VC6YAccelerometerFloat_max >= biggest)
                biggest = *C6VC6YAccelerometerFloat_max;
            if(*C6VC6YAccelerometerFloat_min <= smallest)
                smallest = *C6VC6YAccelerometerFloat_min;isReSet = 1;
        }
        if(ui->checkBox_66->isChecked())
        {
            auto C6VC6ZAccelerometerFloat_max = std::max_element(std::begin(C6VC6ZAccelerometerFloat), std::end(C6VC6ZAccelerometerFloat));
            auto C6VC6ZAccelerometerFloat_min = std::min_element(std::begin(C6VC6ZAccelerometerFloat), std::end(C6VC6ZAccelerometerFloat));

            if(*C6VC6ZAccelerometerFloat_max >= biggest)
                biggest = *C6VC6ZAccelerometerFloat_max;
            if(*C6VC6ZAccelerometerFloat_min <= smallest)
                smallest = *C6VC6ZAccelerometerFloat_min;isReSet = 1;
        }
        if(isReSet == 1)
        {
            ui->customPlot2->xAxis->setRange(0, C6curveX.size()*1.5, Qt::AlignLeft);
            if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
            ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
            return;
        }

    }
#endif
    //速度误差
    if(ui->checkBox_67->isChecked())
    {
        auto VeastSpeedError_max = std::max_element(std::begin(VeastSpeedError), std::end(VeastSpeedError));
        auto VeastSpeedError_min = std::min_element(std::begin(VeastSpeedError), std::end(VeastSpeedError));

        if(*VeastSpeedError_max >= biggest)
            biggest = *VeastSpeedError_max;
        if(*VeastSpeedError_min <= smallest)
            smallest = *VeastSpeedError_min;isReSet = 1;
    }
    if(ui->checkBox_69->isChecked())
    {
        auto VnorthSpeedError_max = std::max_element(std::begin(VnorthSpeedError), std::end(VnorthSpeedError));
        auto VnorthSpeedError_min = std::min_element(std::begin(VnorthSpeedError), std::end(VnorthSpeedError));

        if(*VnorthSpeedError_max >= biggest)
            biggest = *VnorthSpeedError_max;
        if(*VnorthSpeedError_min <= smallest)
            smallest = *VnorthSpeedError_min;isReSet = 1;
    }
    if(ui->checkBox_68->isChecked())
    {
        auto VtogetherSpeedError_max = std::max_element(std::begin(VtogetherSpeedError), std::end(VtogetherSpeedError));
        auto VtogetherSpeedError_min = std::min_element(std::begin(VtogetherSpeedError), std::end(VtogetherSpeedError));

        if(*VtogetherSpeedError_max >= biggest)
            biggest = *VtogetherSpeedError_max;
        if(*VtogetherSpeedError_min <= smallest)
            smallest = *VtogetherSpeedError_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

    //位置误差
    if(ui->checkBox_70->isChecked())
    {
        auto VlatitudeError_max = std::max_element(std::begin(VlatitudeError), std::end(VlatitudeError));
        auto VlatitudeError_min = std::min_element(std::begin(VlatitudeError), std::end(VlatitudeError));

        if(*VlatitudeError_max >= biggest)
            biggest = *VlatitudeError_max;
        if(*VlatitudeError_min <= smallest)
            smallest = *VlatitudeError_min;isReSet = 1;
    }
    if(ui->checkBox_72->isChecked())
    {
        auto VlongitudeError_max = std::max_element(std::begin(VlongitudeError), std::end(VlongitudeError));
        auto VlongitudeError_min = std::min_element(std::begin(VlongitudeError), std::end(VlongitudeError));

        if(*VlongitudeError_max >= biggest)
            biggest = *VlongitudeError_max;
        if(*VlongitudeError_min <= smallest)
            smallest = *VlongitudeError_min;isReSet = 1;
    }
    if(ui->checkBox_71->isChecked())
    {
        auto VpositionError_max = std::max_element(std::begin(VpositionError), std::end(VpositionError));
        auto VpositionError_min = std::min_element(std::begin(VpositionError), std::end(VpositionError));

        if(*VpositionError_max >= biggest)
            biggest = *VpositionError_max;
        if(*VpositionError_min <= smallest)
            smallest = *VpositionError_min;isReSet = 1;
    }
    if(isReSet == 1)
    {
        ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }
        ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
        return;
    }

}

void MainWindow::set_checkBox_1_2_73_74_75()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox->isChecked())
    {
        auto C1Vlatitude_max = std::max_element(std::begin(C1Vlatitude), std::end(C1Vlatitude));
        auto C1Vlatitude_min = std::min_element(std::begin(C1Vlatitude), std::end(C1Vlatitude));

        if(*C1Vlatitude_max >= biggest)
            biggest = *C1Vlatitude_max;
        if(*C1Vlatitude_min <= smallest)
            smallest = *C1Vlatitude_min;
    }
    if(ui->checkBox_2->isChecked())
    {
        auto C1Vlongitude_max = std::max_element(std::begin(C1Vlongitude), std::end(C1Vlongitude));
        auto C1Vlongitude_min = std::min_element(std::begin(C1Vlongitude), std::end(C1Vlongitude));

        if(*C1Vlongitude_max >= biggest)
            biggest = *C1Vlongitude_max;
        if(*C1Vlongitude_min <= smallest)
            smallest = *C1Vlongitude_min;
    }
    if(ui->checkBox_82->isChecked())
    {
        auto C1Vlongitude_max = std::max_element(std::begin(C8VC8Height), std::end(C8VC8Height));
        auto C1Vlongitude_min = std::min_element(std::begin(C8VC8Height), std::end(C8VC8Height));

        if(*C1Vlongitude_max >= biggest)
            biggest = *C1Vlongitude_max;
        if(*C1Vlongitude_min <= smallest)
            smallest = *C1Vlongitude_min;
    }
    if(ui->checkBox_73->isChecked())
    {
        auto C6UndampedLatFloat_max = std::max_element(std::begin(C6VC6UndampedLatFloat), std::end(C6VC6UndampedLatFloat));
        auto C6UndampedLatFloat_min = std::min_element(std::begin(C6VC6UndampedLatFloat), std::end(C6VC6UndampedLatFloat));

        if(*C6UndampedLatFloat_max >= biggest)
            biggest = *C6UndampedLatFloat_max;
        if(*C6UndampedLatFloat_min <= smallest)
            smallest = *C6UndampedLatFloat_min;
    }
    if(ui->checkBox_74->isChecked())
    {
        auto C6UndampedLongFloat_max = std::max_element(std::begin(C6VC6UndampedLongFloat), std::end(C6VC6UndampedLongFloat));
        auto C6UndampedLongFloat_min = std::min_element(std::begin(C6VC6UndampedLongFloat), std::end(C6VC6UndampedLongFloat));

        if(*C6UndampedLongFloat_max >= biggest)
            biggest = *C6UndampedLongFloat_max;
        if(*C6UndampedLongFloat_min <= smallest)
            smallest = *C6UndampedLongFloat_min;
    }
    if(ui->checkBox_75->isChecked())
    {
        auto C6UndampedHeightFloat_max = std::max_element(std::begin(C6VC6UndampedHeightFloat), std::end(C6VC6UndampedHeightFloat));
        auto C6UndampedHeightFloat_min = std::min_element(std::begin(C6VC6UndampedHeightFloat), std::end(C6VC6UndampedHeightFloat));

        if(*C6UndampedHeightFloat_max >= biggest)
            biggest = *C6UndampedHeightFloat_max;
        if(*C6UndampedHeightFloat_min <= smallest)
            smallest = *C6UndampedHeightFloat_min;
    }
    ui->customPlot2->xAxis->setRange(0, C6curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }


}
void MainWindow::set_checkBox_5_3_4_79_80_81()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_5->isChecked())
    {
        auto C1VheadingAngle_max = std::max_element(std::begin(C1VheadingAngle), std::end(C1VheadingAngle));
        auto C1VheadingAngle_min = std::min_element(std::begin(C1VheadingAngle), std::end(C1VheadingAngle));

        if(*C1VheadingAngle_max >= biggest)
            biggest = *C1VheadingAngle_max;
        if(*C1VheadingAngle_min <= smallest)
            smallest = *C1VheadingAngle_min;
    }
    if(ui->checkBox_3->isChecked())
    {
        auto C1VrollAngle_max = std::max_element(std::begin(C1VrollAngle), std::end(C1VrollAngle));
        auto C1VrollAngle_min = std::min_element(std::begin(C1VrollAngle), std::end(C1VrollAngle));

        if(*C1VrollAngle_max >= biggest)
            biggest = *C1VrollAngle_max;
        if(*C1VrollAngle_min <= smallest)
            smallest = *C1VrollAngle_min;
    }
    if(ui->checkBox_4->isChecked())
    {
        auto C1VpitchAngle_max = std::max_element(std::begin(C1VpitchAngle), std::end(C1VpitchAngle));
        auto C1VpitchAngle_min = std::min_element(std::begin(C1VpitchAngle), std::end(C1VpitchAngle));

        if(*C1VpitchAngle_max >= biggest)
            biggest = *C1VpitchAngle_max;
        if(*C1VpitchAngle_min <= smallest)
            smallest = *C1VpitchAngle_min;
    }
    if(ui->checkBox_79->isChecked())
    {
        auto C6UndampedRollAngleFloat_max = std::max_element(std::begin(C6VC6UndampedRollAngleFloat), std::end(C6VC6UndampedRollAngleFloat));
        auto C6UndampedRollAngleFloat_min = std::min_element(std::begin(C6VC6UndampedRollAngleFloat), std::end(C6VC6UndampedRollAngleFloat));

        if(*C6UndampedRollAngleFloat_max >= biggest)
            biggest = *C6UndampedRollAngleFloat_max;
        if(*C6UndampedRollAngleFloat_min <= smallest)
            smallest = *C6UndampedRollAngleFloat_min;
    }
    if(ui->checkBox_80->isChecked())
    {
        auto C6UndampedPitchAngleFloat_max = std::max_element(std::begin(C6VC6UndampedPitchAngleFloat), std::end(C6VC6UndampedPitchAngleFloat));
        auto C6UndampedPitchAngleFloat_min = std::min_element(std::begin(C6VC6UndampedPitchAngleFloat), std::end(C6VC6UndampedPitchAngleFloat));

        if(*C6UndampedPitchAngleFloat_max >= biggest)
            biggest = *C6UndampedPitchAngleFloat_max;
        if(*C6UndampedPitchAngleFloat_min <= smallest)
            smallest = *C6UndampedPitchAngleFloat_min;
    }
    if(ui->checkBox_81->isChecked())
    {
        auto C6UndampedHeadingAngularFloat_max = std::max_element(std::begin(C6VC6UndampedHeadingAngularFloat), std::end(C6VC6UndampedHeadingAngularFloat));
        auto C6UndampedHeadingAngularFloat_min = std::min_element(std::begin(C6VC6UndampedHeadingAngularFloat), std::end(C6VC6UndampedHeadingAngularFloat));

        if(*C6UndampedHeadingAngularFloat_max >= biggest)
            biggest = *C6UndampedHeadingAngularFloat_max;
        if(*C6UndampedHeadingAngularFloat_min <= smallest)
            smallest = *C6UndampedHeadingAngularFloat_min;
    }
    ui->customPlot2->xAxis->setRange(0, C6curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }


}
void MainWindow::set_checkBox_9_10_76_77_78()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_9->isChecked())
    {
        auto C1VnorthSpeed_max = std::max_element(std::begin(C1VnorthSpeed), std::end(C1VnorthSpeed));
        auto C1VnorthSpeed_min = std::min_element(std::begin(C1VnorthSpeed), std::end(C1VnorthSpeed));

        if(*C1VnorthSpeed_max >= biggest)
            biggest = *C1VnorthSpeed_max;
        if(*C1VnorthSpeed_min <= smallest)
            smallest = *C1VnorthSpeed_min;
    }
    if(ui->checkBox_83->isChecked())
    {
        auto C1VnorthSpeed_max = std::max_element(std::begin(C8VC8UpSpeed), std::end(C8VC8UpSpeed));
        auto C1VnorthSpeed_min = std::min_element(std::begin(C8VC8UpSpeed), std::end(C8VC8UpSpeed));

        if(*C1VnorthSpeed_max >= biggest)
            biggest = *C1VnorthSpeed_max;
        if(*C1VnorthSpeed_min <= smallest)
            smallest = *C1VnorthSpeed_min;
    }
    if(ui->checkBox_10->isChecked())
    {
        auto C1VeastSpeed_max = std::max_element(std::begin(C1VeastSpeed), std::end(C1VeastSpeed));
        auto C1VeastSpeed_min = std::min_element(std::begin(C1VeastSpeed), std::end(C1VeastSpeed));

        if(*C1VeastSpeed_max >= biggest)
            biggest = *C1VeastSpeed_max;
        if(*C1VeastSpeed_min <= smallest)
            smallest = *C1VeastSpeed_min;
    }
    if(ui->checkBox_76->isChecked())
    {
        auto C6UndampedNorthSpeedFloat_max = std::max_element(std::begin(C6VC6UndampedNorthSpeedFloat), std::end(C6VC6UndampedNorthSpeedFloat));
        auto C6UndampedNorthSpeedFloat_min = std::min_element(std::begin(C6VC6UndampedNorthSpeedFloat), std::end(C6VC6UndampedNorthSpeedFloat));

        if(*C6UndampedNorthSpeedFloat_max >= biggest)
            biggest = *C6UndampedNorthSpeedFloat_max;
        if(*C6UndampedNorthSpeedFloat_min <= smallest)
            smallest = *C6UndampedNorthSpeedFloat_min;
    }
    if(ui->checkBox_77->isChecked())
    {
        auto C6UndampedEastSpeedFloat_max = std::max_element(std::begin(C6VC6UndampedEastSpeedFloat), std::end(C6VC6UndampedEastSpeedFloat));
        auto C6UndampedEastSpeedFloat_min = std::min_element(std::begin(C6VC6UndampedEastSpeedFloat), std::end(C6VC6UndampedEastSpeedFloat));

        if(*C6UndampedEastSpeedFloat_max >= biggest)
            biggest = *C6UndampedEastSpeedFloat_max;
        if(*C6UndampedEastSpeedFloat_min <= smallest)
            smallest = *C6UndampedEastSpeedFloat_min;
    }
    if(ui->checkBox_78->isChecked())
    {
        auto C6VerticalVelocityFloat_max = std::max_element(std::begin(C6VC6VerticalVelocityFloat), std::end(C6VC6VerticalVelocityFloat));
        auto C6VerticalVelocityFloat_min = std::min_element(std::begin(C6VC6VerticalVelocityFloat), std::end(C6VC6VerticalVelocityFloat));

        if(*C6VerticalVelocityFloat_max >= biggest)
            biggest = *C6VerticalVelocityFloat_max;
        if(*C6VerticalVelocityFloat_min <= smallest)
            smallest = *C6VerticalVelocityFloat_min;
    }
    ui->customPlot2->xAxis->setRange(0, C6curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }


}
void MainWindow::set_checkBox_6_7_8()
{
    double biggest = -999999999;
    double smallest = 999999999;
    if(ui->checkBox_6->isChecked())
    {
        auto C1VheadingAngle_max = std::max_element(std::begin(C1VheadingAngularSpeed), std::end(C1VheadingAngularSpeed));
        auto C1VheadingAngle_min = std::min_element(std::begin(C1VheadingAngularSpeed), std::end(C1VheadingAngularSpeed));

        if(*C1VheadingAngle_max >= biggest)
            biggest = *C1VheadingAngle_max;
        if(*C1VheadingAngle_min <= smallest)
            smallest = *C1VheadingAngle_min;
    }
    if(ui->checkBox_7->isChecked())
    {
        auto C1VrollAngle_max = std::max_element(std::begin(C1VrollAngleSpeed), std::end(C1VrollAngleSpeed));
        auto C1VrollAngle_min = std::min_element(std::begin(C1VrollAngleSpeed), std::end(C1VrollAngleSpeed));

        if(*C1VrollAngle_max >= biggest)
            biggest = *C1VrollAngle_max;
        if(*C1VrollAngle_min <= smallest)
            smallest = *C1VrollAngle_min;
    }
    if(ui->checkBox_8->isChecked())
    {
        auto C1VpitchAngle_max = std::max_element(std::begin(C1VpitchAngleSpeed), std::end(C1VpitchAngleSpeed));
        auto C1VpitchAngle_min = std::min_element(std::begin(C1VpitchAngleSpeed), std::end(C1VpitchAngleSpeed));

        if(*C1VpitchAngle_max >= biggest)
            biggest = *C1VpitchAngle_max;
        if(*C1VpitchAngle_min <= smallest)
            smallest = *C1VpitchAngle_min;
    }
    ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}

void MainWindow::set_checkBox_12_13_11_15_16_14()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_12->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(C1Vheave), std::end(C1Vheave));
        auto C1Vheave_min = std::min_element(std::begin(C1Vheave), std::end(C1Vheave));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_13->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(C1VverticalVelocity), std::end(C1VverticalVelocity));
        auto C1VverticalVelocity_min = std::min_element(std::begin(C1VverticalVelocity), std::end(C1VverticalVelocity));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_11->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(C1Vsway), std::end(C1Vsway));
        auto C1Vsway_min = std::min_element(std::begin(C1Vsway), std::end(C1Vsway));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_15->isChecked())
    {
        auto C1VtransverseVelocity_max = std::max_element(std::begin(C1VtransverseVelocity), std::end(C1VtransverseVelocity));
        auto C1VtransverseVelocity_min = std::min_element(std::begin(C1VtransverseVelocity), std::end(C1VtransverseVelocity));

        if(*C1VtransverseVelocity_max >= biggest)
            biggest = *C1VtransverseVelocity_max;
        if(*C1VtransverseVelocity_min <= smallest)
            smallest = *C1VtransverseVelocity_min;
    }
    if(ui->checkBox_16->isChecked())
    {
        auto C1Vsurge_max = std::max_element(std::begin(C1Vsurge), std::end(C1Vsurge));
        auto C1Vsurge_min = std::min_element(std::begin(C1Vsurge), std::end(C1Vsurge));

        if(*C1Vsurge_max >= biggest)
            biggest = *C1Vsurge_max;
        if(*C1Vsurge_min <= smallest)
            smallest = *C1Vsurge_min;
    }
    if(ui->checkBox_14->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(C1Vsway), std::end(C1Vsway));
        auto C1Vsway_min = std::min_element(std::begin(C1Vsway), std::end(C1Vsway));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }


}
void MainWindow::set_checkBox_19_18_17()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_19->isChecked())
    {
        auto C5VXGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VXGyroAngleIncreaseFloat), std::end(C5VXGyroAngleIncreaseFloat));
        auto C5VXGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VXGyroAngleIncreaseFloat), std::end(C5VXGyroAngleIncreaseFloat));

        if(*C5VXGyroAngleIncreaseFloat_max >= biggest)
            biggest = *C5VXGyroAngleIncreaseFloat_max;
        if(*C5VXGyroAngleIncreaseFloat_min <= smallest)
            smallest = *C5VXGyroAngleIncreaseFloat_min;
    }
    if(ui->checkBox_18->isChecked())
    {
        auto C5VYGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VYGyroAngleIncreaseFloat), std::end(C5VYGyroAngleIncreaseFloat));
        auto C5VYGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VYGyroAngleIncreaseFloat), std::end(C5VYGyroAngleIncreaseFloat));

        if(*C5VYGyroAngleIncreaseFloat_max >= biggest)
            biggest = *C5VYGyroAngleIncreaseFloat_max;
        if(*C5VYGyroAngleIncreaseFloat_min <= smallest)
            smallest = *C5VYGyroAngleIncreaseFloat_min;
    }
    if(ui->checkBox_17->isChecked())
    {
        auto C5VZGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VZGyroAngleIncreaseFloat), std::end(C5VZGyroAngleIncreaseFloat));
        auto C5VZGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VZGyroAngleIncreaseFloat), std::end(C5VZGyroAngleIncreaseFloat));

        if(*C5VZGyroAngleIncreaseFloat_max >= biggest)
            biggest = *C5VZGyroAngleIncreaseFloat_max;
        if(*C5VZGyroAngleIncreaseFloat_min <= smallest)
            smallest = *C5VZGyroAngleIncreaseFloat_min;
    }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }


}
void MainWindow::set_checkBox_20_21_22()
{
    //X Y Z加表增量
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_20->isChecked())
   {
       auto C5VXAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VXAccelerometerSpeedIncrementFloat), std::end(C5VXAccelerometerSpeedIncrementFloat));
       auto C5VXAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VXAccelerometerSpeedIncrementFloat), std::end(C5VXAccelerometerSpeedIncrementFloat));

       if(*C5VXAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VXAccelerometerSpeedIncrementFloat_max;
       if(*C5VXAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VXAccelerometerSpeedIncrementFloat_min;
   }
   if(ui->checkBox_21->isChecked())
   {
       auto C5VYAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VYAccelerometerSpeedIncrementFloat), std::end(C5VYAccelerometerSpeedIncrementFloat));
       auto C5VYAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VYAccelerometerSpeedIncrementFloat), std::end(C5VYAccelerometerSpeedIncrementFloat));

       if(*C5VYAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VYAccelerometerSpeedIncrementFloat_max;
       if(*C5VYAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VYAccelerometerSpeedIncrementFloat_min;
   }
   if(ui->checkBox_22->isChecked())
   {
       auto C5VZAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VZAccelerometerSpeedIncrementFloat), std::end(C5VZAccelerometerSpeedIncrementFloat));
       auto C5VZAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VZAccelerometerSpeedIncrementFloat), std::end(C5VZAccelerometerSpeedIncrementFloat));

       if(*C5VZAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VZAccelerometerSpeedIncrementFloat_max;
       if(*C5VZAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VZAccelerometerSpeedIncrementFloat_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}
void MainWindow::set_checkBox_23_24_25()
{
    //X Y Z陀螺1s补偿后角增量
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_23->isChecked())
   {
       auto C5VXAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VXgyroCompensatedAngleIncrementFloat), std::end(C5VXgyroCompensatedAngleIncrementFloat));
       auto C5VXAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VXgyroCompensatedAngleIncrementFloat), std::end(C5VXgyroCompensatedAngleIncrementFloat));

       if(*C5VXAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VXAccelerometerSpeedIncrementFloat_max;
       if(*C5VXAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VXAccelerometerSpeedIncrementFloat_min;
   }
   if(ui->checkBox_24->isChecked())
   {
       auto C5VYAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VYgyroCompensatedAngleIncrementFloat), std::end(C5VYgyroCompensatedAngleIncrementFloat));
       auto C5VYAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VYgyroCompensatedAngleIncrementFloat), std::end(C5VYgyroCompensatedAngleIncrementFloat));

       if(*C5VYAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VYAccelerometerSpeedIncrementFloat_max;
       if(*C5VYAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VYAccelerometerSpeedIncrementFloat_min;
   }
   if(ui->checkBox_25->isChecked())
   {
       auto C5VZAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VZgyroCompensatedAngleIncrementFloat), std::end(C5VZgyroCompensatedAngleIncrementFloat));
       auto C5VZAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VZgyroCompensatedAngleIncrementFloat), std::end(C5VZgyroCompensatedAngleIncrementFloat));

       if(*C5VZAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VZAccelerometerSpeedIncrementFloat_max;
       if(*C5VZAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VZAccelerometerSpeedIncrementFloat_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}

void MainWindow::set_checkBox_26_27_28()
{
    //X Y Z加速度计1s补偿后速度增量
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_26->isChecked())
   {
       auto C5VXAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VXAccVelocityIncrementFloat), std::end(C5VXAccVelocityIncrementFloat));
       auto C5VXAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VXAccVelocityIncrementFloat), std::end(C5VXAccVelocityIncrementFloat));

       if(*C5VXAccVelocityIncrementFloat_max >= biggest)
           biggest = *C5VXAccVelocityIncrementFloat_max;
       if(*C5VXAccVelocityIncrementFloat_min <= smallest)
           smallest = *C5VXAccVelocityIncrementFloat_min;
   }
   if(ui->checkBox_27->isChecked())
   {
       auto C5VYAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VYAccVelocityIncrementFloat), std::end(C5VYAccVelocityIncrementFloat));
       auto C5VYAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VYAccVelocityIncrementFloat), std::end(C5VYAccVelocityIncrementFloat));

       if(*C5VYAccVelocityIncrementFloat_max >= biggest)
           biggest = *C5VYAccVelocityIncrementFloat_max;
       if(*C5VYAccVelocityIncrementFloat_min <= smallest)
           smallest = *C5VYAccVelocityIncrementFloat_min;
   }
   if(ui->checkBox_28->isChecked())
   {
       auto C5VZAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VZAccVelocityIncrementFloat), std::end(C5VZAccVelocityIncrementFloat));
       auto C5VZAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VZAccVelocityIncrementFloat), std::end(C5VZAccVelocityIncrementFloat));

       if(*C5VZAccVelocityIncrementFloat_max >= biggest)
           biggest = *C5VZAccVelocityIncrementFloat_max;
       if(*C5VZAccVelocityIncrementFloat_min <= smallest)
           smallest = *C5VZAccVelocityIncrementFloat_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}

void MainWindow::set_checkBox_29_30_31()
{
    //X Y Z陀螺差频
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_29->isChecked())
   {
       auto C5VXgyroDifFrequency_max = std::max_element(std::begin(C5VXgyroDifFrequency), std::end(C5VXgyroDifFrequency));
       auto C5VXgyroDifFrequency_min = std::min_element(std::begin(C5VXgyroDifFrequency), std::end(C5VXgyroDifFrequency));

       if(*C5VXgyroDifFrequency_max >= biggest)
           biggest = *C5VXgyroDifFrequency_max;
       if(*C5VXgyroDifFrequency_min <= smallest)
           smallest = *C5VXgyroDifFrequency_min;
   }
   if(ui->checkBox_31->isChecked())
   {
       auto C5VYgyroDifFrequency_max = std::max_element(std::begin(C5VYgyroDifFrequency), std::end(C5VYgyroDifFrequency));
       auto C5VYgyroDifFrequency_min = std::min_element(std::begin(C5VYgyroDifFrequency), std::end(C5VYgyroDifFrequency));

       if(*C5VYgyroDifFrequency_max >= biggest)
           biggest = *C5VYgyroDifFrequency_max;
       if(*C5VYgyroDifFrequency_min <= smallest)
           smallest = *C5VYgyroDifFrequency_min;
   }
   if(ui->checkBox_30->isChecked())
   {
       auto C5VZgyroDifFrequency_max = std::max_element(std::begin(C5VZgyroDifFrequency), std::end(C5VZgyroDifFrequency));
       auto C5VZgyroDifFrequency_min = std::min_element(std::begin(C5VZgyroDifFrequency), std::end(C5VZgyroDifFrequency));

       if(*C5VZgyroDifFrequency_max >= biggest)
           biggest = *C5VZgyroDifFrequency_max;
       if(*C5VZgyroDifFrequency_min <= smallest)
           smallest = *C5VZgyroDifFrequency_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}

void MainWindow::set_checkBox_32_33_34()
{
    //X Y Z加速度计差频
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_32->isChecked())
   {
       auto C5VXaccelerometerDifFre_max = std::max_element(std::begin(C5VXaccelerometerDifFre), std::end(C5VXaccelerometerDifFre));
       auto C5VXaccelerometerDifFre_min = std::min_element(std::begin(C5VXaccelerometerDifFre), std::end(C5VXaccelerometerDifFre));

       if(*C5VXaccelerometerDifFre_max >= biggest)
           biggest = *C5VXaccelerometerDifFre_max;
       if(*C5VXaccelerometerDifFre_min <= smallest)
           smallest = *C5VXaccelerometerDifFre_min;
   }
   if(ui->checkBox_33->isChecked())
   {
       auto C5VYaccelerometerDifFre_max = std::max_element(std::begin(C5VYaccelerometerDifFre), std::end(C5VYaccelerometerDifFre));
       auto C5VYaccelerometerDifFre_min = std::min_element(std::begin(C5VYaccelerometerDifFre), std::end(C5VYaccelerometerDifFre));

       if(*C5VYaccelerometerDifFre_max >= biggest)
           biggest = *C5VYaccelerometerDifFre_max;
       if(*C5VYaccelerometerDifFre_min <= smallest)
           smallest = *C5VYaccelerometerDifFre_min;
   }
   if(ui->checkBox_34->isChecked())
   {
       auto C5VZaccelerometerDifFre_max = std::max_element(std::begin(C5VZaccelerometerDifFre), std::end(C5VZaccelerometerDifFre));
       auto C5VZaccelerometerDifFre_min = std::min_element(std::begin(C5VZaccelerometerDifFre), std::end(C5VZaccelerometerDifFre));

       if(*C5VZaccelerometerDifFre_max >= biggest)
           biggest = *C5VZaccelerometerDifFre_max;
       if(*C5VZaccelerometerDifFre_min <= smallest)
           smallest = *C5VZaccelerometerDifFre_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}
void MainWindow::set_checkBox_37_35_36()
{
    //X Y Z陀螺温度1数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_37->isChecked())
   {
       auto C5VXgyroTemp1_max = std::max_element(std::begin(C5VXgyroTemp1), std::end(C5VXgyroTemp1));
       auto C5VXgyroTemp1_min = std::min_element(std::begin(C5VXgyroTemp1), std::end(C5VXgyroTemp1));

       if(*C5VXgyroTemp1_max >= biggest)
           biggest = *C5VXgyroTemp1_max;
       if(*C5VXgyroTemp1_min <= smallest)
           smallest = *C5VXgyroTemp1_min;
   }
   if(ui->checkBox_35->isChecked())
   {
       auto C5VYgyroTemp1_max = std::max_element(std::begin(C5VYgyroTemp1), std::end(C5VYgyroTemp1));
       auto C5VYgyroTemp1_min = std::min_element(std::begin(C5VYgyroTemp1), std::end(C5VYgyroTemp1));

       if(*C5VYgyroTemp1_max >= biggest)
           biggest = *C5VYgyroTemp1_max;
       if(*C5VYgyroTemp1_min <= smallest)
           smallest = *C5VYgyroTemp1_min;
   }
   if(ui->checkBox_36->isChecked())
   {
       auto C5VZgyroTemp1_max = std::max_element(std::begin(C5VZgyroTemp1), std::end(C5VZgyroTemp1));
       auto C5VZgyroTemp1_min = std::min_element(std::begin(C5VZgyroTemp1), std::end(C5VZgyroTemp1));

       if(*C5VZgyroTemp1_max >= biggest)
           biggest = *C5VZgyroTemp1_max;
       if(*C5VZgyroTemp1_min <= smallest)
           smallest = *C5VZgyroTemp1_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}
void MainWindow::set_checkBox_40_38_39()
{
    //X Y Z加速度计温度1数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_40->isChecked())
   {
       auto C5VXAccelerometerTemperture_max = std::max_element(std::begin(C5VXAccelerometerTemperture), std::end(C5VXAccelerometerTemperture));
       auto C5VXAccelerometerTemperture_min = std::min_element(std::begin(C5VXAccelerometerTemperture), std::end(C5VXAccelerometerTemperture));

       if(*C5VXAccelerometerTemperture_max >= biggest)
           biggest = *C5VXAccelerometerTemperture_max;
       if(*C5VXAccelerometerTemperture_min <= smallest)
           smallest = *C5VXAccelerometerTemperture_min;
   }
   if(ui->checkBox_38->isChecked())
   {
       auto C5VYAccelerometerTemperture_max = std::max_element(std::begin(C5VYAccelerometerTemperture), std::end(C5VYAccelerometerTemperture));
       auto C5VYAccelerometerTemperture_min = std::min_element(std::begin(C5VYAccelerometerTemperture), std::end(C5VYAccelerometerTemperture));

       if(*C5VYAccelerometerTemperture_max >= biggest)
           biggest = *C5VYAccelerometerTemperture_max;
       if(*C5VYAccelerometerTemperture_min <= smallest)
           smallest = *C5VYAccelerometerTemperture_min;
   }
   if(ui->checkBox_39->isChecked())
   {
       auto C5VZAccelerometerTemperture_max = std::max_element(std::begin(C5VZAccelerometerTemperture), std::end(C5VZAccelerometerTemperture));
       auto C5VZAccelerometerTemperture_min = std::min_element(std::begin(C5VZAccelerometerTemperture), std::end(C5VZAccelerometerTemperture));

       if(*C5VZAccelerometerTemperture_max >= biggest)
           biggest = *C5VZAccelerometerTemperture_max;
       if(*C5VZAccelerometerTemperture_min <= smallest)
           smallest = *C5VZAccelerometerTemperture_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}
void MainWindow::set_checkBox_42_43_41()
{
    //X Y Z陀螺温度2数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_42->isChecked())
   {
       auto C5VXgyroTemp2_max = std::max_element(std::begin(C5VXgyroTemp2), std::end(C5VXgyroTemp2));
       auto C5VXgyroTemp2_min = std::min_element(std::begin(C5VXgyroTemp2), std::end(C5VXgyroTemp2));

       if(*C5VXgyroTemp2_max >= biggest)
           biggest = *C5VXgyroTemp2_max;
       if(*C5VXgyroTemp2_min <= smallest)
           smallest = *C5VXgyroTemp2_min;
   }
   if(ui->checkBox_43->isChecked())
   {
       auto C5VYgyroTemp2_max = std::max_element(std::begin(C5VYgyroTemp2), std::end(C5VYgyroTemp2));
       auto C5VYgyroTemp2_min = std::min_element(std::begin(C5VYgyroTemp2), std::end(C5VYgyroTemp2));

       if(*C5VYgyroTemp2_max >= biggest)
           biggest = *C5VYgyroTemp2_max;
       if(*C5VYgyroTemp2_min <= smallest)
           smallest = *C5VYgyroTemp2_min;
   }
   if(ui->checkBox_41->isChecked())
   {
       auto C5VZgyroTemp2_max = std::max_element(std::begin(C5VZgyroTemp2), std::end(C5VZgyroTemp2));
       auto C5VZgyroTemp2_min = std::min_element(std::begin(C5VZgyroTemp2), std::end(C5VZgyroTemp2));

       if(*C5VZgyroTemp2_max >= biggest)
           biggest = *C5VZgyroTemp2_max;
       if(*C5VZgyroTemp2_min <= smallest)
           smallest = *C5VZgyroTemp2_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}
void MainWindow::set_checkBox_45_46_44()
{
    //X Y Z陀螺抖幅数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_45->isChecked())
   {
       auto C5VXgyroAmplitudeJitter_max = std::max_element(std::begin(C5VXgyroAmplitudeJitter), std::end(C5VXgyroAmplitudeJitter));
       auto C5VXgyroAmplitudeJitter_min = std::min_element(std::begin(C5VXgyroAmplitudeJitter), std::end(C5VXgyroAmplitudeJitter));

       if(*C5VXgyroAmplitudeJitter_max >= biggest)
           biggest = *C5VXgyroAmplitudeJitter_max;
       if(*C5VXgyroAmplitudeJitter_min <= smallest)
           smallest = *C5VXgyroAmplitudeJitter_min;
   }
   if(ui->checkBox_46->isChecked())
   {
       auto C5VYgyroAmplitudeJitter_max = std::max_element(std::begin(C5VYgyroAmplitudeJitter), std::end(C5VYgyroAmplitudeJitter));
       auto C5VYgyroAmplitudeJitter_min = std::min_element(std::begin(C5VYgyroAmplitudeJitter), std::end(C5VYgyroAmplitudeJitter));

       if(*C5VYgyroAmplitudeJitter_max >= biggest)
           biggest = *C5VYgyroAmplitudeJitter_max;
       if(*C5VYgyroAmplitudeJitter_min <= smallest)
           smallest = *C5VYgyroAmplitudeJitter_min;
   }
   if(ui->checkBox_44->isChecked())
   {
       auto C5VZgyroAmplitudeJitter_max = std::max_element(std::begin(C5VZgyroAmplitudeJitter), std::end(C5VZgyroAmplitudeJitter));
       auto C5VZgyroAmplitudeJitter_min = std::min_element(std::begin(C5VZgyroAmplitudeJitter), std::end(C5VZgyroAmplitudeJitter));

       if(*C5VZgyroAmplitudeJitter_max >= biggest)
           biggest = *C5VZgyroAmplitudeJitter_max;
       if(*C5VZgyroAmplitudeJitter_min <= smallest)
           smallest = *C5VZgyroAmplitudeJitter_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }
}
void MainWindow::set_checkBox_48_49_47()
{
    //X Y Z陀螺抖频数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_48->isChecked())
   {
       auto C5VXgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VXgyroAmpl1itudeFre), std::end(C5VXgyroAmpl1itudeFre));
       auto C5VXgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VXgyroAmpl1itudeFre), std::end(C5VXgyroAmpl1itudeFre));

       if(*C5VXgyroAmpl1itudeFre_max >= biggest)
           biggest = *C5VXgyroAmpl1itudeFre_max;
       if(*C5VXgyroAmpl1itudeFre_min <= smallest)
           smallest = *C5VXgyroAmpl1itudeFre_min;
   }
   if(ui->checkBox_49->isChecked())
   {
       auto C5VYgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VYgyroAmpl1itudeFre), std::end(C5VYgyroAmpl1itudeFre));
       auto C5VYgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VYgyroAmpl1itudeFre), std::end(C5VYgyroAmpl1itudeFre));

       if(*C5VYgyroAmpl1itudeFre_max >= biggest)
           biggest = *C5VYgyroAmpl1itudeFre_max;
       if(*C5VYgyroAmpl1itudeFre_min <= smallest)
           smallest = *C5VYgyroAmpl1itudeFre_min;
   }
   if(ui->checkBox_47->isChecked())
   {
       auto C5VZgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VZgyroAmpl1itudeFre), std::end(C5VZgyroAmpl1itudeFre));
       auto C5VZgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VZgyroAmpl1itudeFre), std::end(C5VZgyroAmpl1itudeFre));

       if(*C5VZgyroAmpl1itudeFre_max >= biggest)
           biggest = *C5VZgyroAmpl1itudeFre_max;
       if(*C5VZgyroAmpl1itudeFre_min <= smallest)
           smallest = *C5VZgyroAmpl1itudeFre_min;
   }
    ui->customPlot2->xAxis->setRange(0, C5curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}
void MainWindow::set_checkBox_51_54_50_52_53_60()
{
    //GPS纬度
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_51->isChecked())
   {
       auto C3VGPSlatitude_max = std::max_element(std::begin(C3VGPSlatitude), std::end(C3VGPSlatitude));
       auto C3VGPSlatitude_min = std::min_element(std::begin(C3VGPSlatitude), std::end(C3VGPSlatitude));

       if(*C3VGPSlatitude_max >= biggest)
           biggest = *C3VGPSlatitude_max;
       if(*C3VGPSlatitude_min <= smallest)
           smallest = *C3VGPSlatitude_min;
   }
   if(ui->checkBox_54->isChecked())
   {
       auto C3Vlongitude_max = std::max_element(std::begin(C3Vlongitude), std::end(C3Vlongitude));
       auto C3Vlongitude_min = std::min_element(std::begin(C3Vlongitude), std::end(C3Vlongitude));

       if(*C3Vlongitude_max >= biggest)
           biggest = *C3Vlongitude_max;
       if(*C3Vlongitude_min <= smallest)
           smallest = *C3Vlongitude_min;
   }
   if(ui->checkBox_50->isChecked())
   {
       auto C3VtogetherSpeed_max = std::max_element(std::begin(C3VtogetherSpeed), std::end(C3VtogetherSpeed));
       auto C3VtogetherSpeed_min = std::min_element(std::begin(C3VtogetherSpeed), std::end(C3VtogetherSpeed));

       if(*C3VtogetherSpeed_max >= biggest)
           biggest = *C3VtogetherSpeed_max;
       if(*C3VtogetherSpeed_min <= smallest)
           smallest = *C3VtogetherSpeed_min;
   }

   if(ui->checkBox_52->isChecked())
   {
       auto C3VheadingAngle_max = std::max_element(std::begin(C3VheadingAngle), std::end(C3VheadingAngle));
       auto C3VheadingAngle_min = std::min_element(std::begin(C3VheadingAngle), std::end(C3VheadingAngle));

       if(*C3VheadingAngle_max >= biggest)
           biggest = *C3VheadingAngle_max;
       if(*C3VheadingAngle_min <= smallest)
           smallest = *C3VheadingAngle_min;
   }
   if(ui->checkBox_53->isChecked())
   {
       auto C3VcombinedEastSpeed_max = std::max_element(std::begin(C3VcombinedEastSpeed), std::end(C3VcombinedEastSpeed));
       auto C3VcombinedEastSpeed_min = std::min_element(std::begin(C3VcombinedEastSpeed), std::end(C3VcombinedEastSpeed));

       if(*C3VcombinedEastSpeed_max >= biggest)
           biggest = *C3VcombinedEastSpeed_max;
       if(*C3VcombinedEastSpeed_min <= smallest)
           smallest = *C3VcombinedEastSpeed_min;
   }
   if(ui->checkBox_60->isChecked())
   {
       auto C3VcombinedNorthSpeed_max = std::max_element(std::begin(C3VcombinedNorthSpeed), std::end(C3VcombinedNorthSpeed));
       auto C3VcombinedNorthSpeed_min = std::min_element(std::begin(C3VcombinedNorthSpeed), std::end(C3VcombinedNorthSpeed));

       if(*C3VcombinedNorthSpeed_max >= biggest)
           biggest = *C3VcombinedNorthSpeed_max;
       if(*C3VcombinedNorthSpeed_min <= smallest)
           smallest = *C3VcombinedNorthSpeed_min;
   }
   if(ui->checkBox_84->isChecked())
   {
       auto C3VcombinedNorthSpeed_max = std::max_element(std::begin(C8VC8GPSHeight), std::end(C8VC8GPSHeight));
       auto C3VcombinedNorthSpeed_min = std::min_element(std::begin(C8VC8GPSHeight), std::end(C8VC8GPSHeight));

       if(*C3VcombinedNorthSpeed_max >= biggest)
           biggest = *C3VcombinedNorthSpeed_max;
       if(*C3VcombinedNorthSpeed_min <= smallest)
           smallest = *C3VcombinedNorthSpeed_min;
   }
   if(ui->checkBox_87->isChecked())
   {
       auto C3VcombinedNorthSpeed_max = std::max_element(std::begin(C8VC8GPTUpSpeed), std::end(C8VC8GPTUpSpeed));
       auto C3VcombinedNorthSpeed_min = std::min_element(std::begin(C8VC8GPTUpSpeed), std::end(C8VC8GPTUpSpeed));

       if(*C3VcombinedNorthSpeed_max >= biggest)
           biggest = *C3VcombinedNorthSpeed_max;
       if(*C3VcombinedNorthSpeed_min <= smallest)
           smallest = *C3VcombinedNorthSpeed_min;
   }
    ui->customPlot2->xAxis->setRange(0, C3curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}
void MainWindow::set_checkBox_59_56_57_55_58()
{
    //多普勒,电磁
    double biggest = -999999999;
    double smallest = 999999999;
    if(ui->checkBox_59->isChecked())
    {
        auto C3VwaterX_max = std::max_element(std::begin(C3VwaterX), std::end(C3VwaterX));
        auto C3VwaterX_min = std::min_element(std::begin(C3VwaterX), std::end(C3VwaterX));

        if(*C3VwaterX_max >= biggest)
            biggest = *C3VwaterX_max;
        if(*C3VwaterX_min <= smallest)
            smallest = *C3VwaterX_min;
    }
    if(ui->checkBox_56->isChecked())
    {
        auto C3VwaterY_max = std::max_element(std::begin(C3VwaterY), std::end(C3VwaterY));
        auto C3VwaterY_min = std::min_element(std::begin(C3VwaterY), std::end(C3VwaterY));

        if(*C3VwaterY_max >= biggest)
            biggest = *C3VwaterY_max;
        if(*C3VwaterY_min <= smallest)
            smallest = *C3VwaterY_min;
    }

    if(ui->checkBox_57->isChecked())
    {
        auto C3VbottomX_max = std::max_element(std::begin(C3VbottomX), std::end(C3VbottomX));
        auto C3VbottomX_min = std::min_element(std::begin(C3VbottomX), std::end(C3VbottomX));

        if(*C3VbottomX_max >= biggest)
            biggest = *C3VbottomX_max;
        if(*C3VbottomX_min <= smallest)
            smallest = *C3VbottomX_min;
    }
    if(ui->checkBox_55->isChecked())
    {
        auto C3VbottomY_max = std::max_element(std::begin(C3VbottomY), std::end(C3VbottomY));
        auto C3VbottomY_min = std::min_element(std::begin(C3VbottomY), std::end(C3VbottomY));

        if(*C3VbottomY_max >= biggest)
            biggest = *C3VbottomY_max;
        if(*C3VbottomY_min <= smallest)
            smallest = *C3VbottomY_min;
    }
    if(ui->checkBox_58->isChecked())
    {
        auto C3VelectromagnetismSpeed_max = std::max_element(std::begin(C3VelectromagnetismSpeed), std::end(C3VelectromagnetismSpeed));
        auto C3VelectromagnetismSpeed_min = std::min_element(std::begin(C3VelectromagnetismSpeed), std::end(C3VelectromagnetismSpeed));

        if(*C3VelectromagnetismSpeed_max >= biggest)
            biggest = *C3VelectromagnetismSpeed_max;
        if(*C3VelectromagnetismSpeed_min <= smallest)
            smallest = *C3VelectromagnetismSpeed_min;
    }
    if(ui->checkBox_85->isChecked())
    {
        auto C3VelectromagnetismSpeed_max = std::max_element(std::begin(C8VC8LogDownSpeed2Water), std::end(C8VC8LogDownSpeed2Water));
        auto C3VelectromagnetismSpeed_min = std::min_element(std::begin(C8VC8LogDownSpeed2Water), std::end(C8VC8LogDownSpeed2Water));

        if(*C3VelectromagnetismSpeed_max >= biggest)
            biggest = *C3VelectromagnetismSpeed_max;
        if(*C3VelectromagnetismSpeed_min <= smallest)
            smallest = *C3VelectromagnetismSpeed_min;
    }
    if(ui->checkBox_86->isChecked())
    {
        auto C3VelectromagnetismSpeed_max = std::max_element(std::begin(C8VC8LogDownSpeed2Ground), std::end(C8VC8LogDownSpeed2Ground));
        auto C3VelectromagnetismSpeed_min = std::min_element(std::begin(C8VC8LogDownSpeed2Ground), std::end(C8VC8LogDownSpeed2Ground));

        if(*C3VelectromagnetismSpeed_max >= biggest)
            biggest = *C3VelectromagnetismSpeed_max;
        if(*C3VelectromagnetismSpeed_min <= smallest)
            smallest = *C3VelectromagnetismSpeed_min;
    }
     ui->customPlot2->xAxis->setRange(0, C3curveX.size()*1.5, Qt::AlignLeft);

     //判断最大值和最小值是否相等
     if(biggest == smallest)
     {
                 if(biggest != 0)
             ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
         else
             ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
     }
     else
     {
         ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
     }

}
void MainWindow::set_checkBox_61_63_62()
{
    //X Y Z陀螺零偏
    double biggest = -999999999;
    double smallest = 999999999;
     if(ui->checkBox_61->isChecked())
     {
         auto C6VC6XGroyFloat_max = std::max_element(std::begin(C6VC6XGroyFloat), std::end(C6VC6XGroyFloat));
         auto C6VC6XGroyFloat_min = std::min_element(std::begin(C6VC6XGroyFloat), std::end(C6VC6XGroyFloat));

         if(*C6VC6XGroyFloat_max >= biggest)
             biggest = *C6VC6XGroyFloat_max;
         if(*C6VC6XGroyFloat_min <= smallest)
             smallest = *C6VC6XGroyFloat_min;
     }
     if(ui->checkBox_63->isChecked())
     {
         auto C6VC6YGroyFloat_max = std::max_element(std::begin(C6VC6YGroyFloat), std::end(C6VC6YGroyFloat));
         auto C6VC6YGroyFloat_min = std::min_element(std::begin(C6VC6YGroyFloat), std::end(C6VC6YGroyFloat));

         if(*C6VC6YGroyFloat_max >= biggest)
             biggest = *C6VC6YGroyFloat_max;
         if(*C6VC6YGroyFloat_min <= smallest)
             smallest = *C6VC6YGroyFloat_min;
     }
     if(ui->checkBox_62->isChecked())
     {
         auto C6VC6ZGroyFloat_max = std::max_element(std::begin(C6VC6ZGroyFloat), std::end(C6VC6ZGroyFloat));
         auto C6VC6ZGroyFloat_min = std::min_element(std::begin(C6VC6ZGroyFloat), std::end(C6VC6ZGroyFloat));

         if(*C6VC6ZGroyFloat_max >= biggest)
             biggest = *C6VC6ZGroyFloat_max;
         if(*C6VC6ZGroyFloat_min <= smallest)
             smallest = *C6VC6ZGroyFloat_min;
     }
      ui->customPlot2->xAxis->setRange(0, C6curveX.size()*1.5, Qt::AlignLeft);

      //判断最大值和最小值是否相等
      if(biggest == smallest)
      {
                  if(biggest != 0)
              ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
          else
              ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
      }
      else
      {
          ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
      }


}
void MainWindow::set_checkBox_65_64_66()
{
    //X Y Z加速度计零偏
    double biggest = -999999999;
    double smallest = 999999999;
     if(ui->checkBox_65->isChecked())
     {
         auto C6VC6XAccelerometerFloat_max = std::max_element(std::begin(C6VC6XAccelerometerFloat), std::end(C6VC6XAccelerometerFloat));
         auto C6VC6XAccelerometerFloat_min = std::min_element(std::begin(C6VC6XAccelerometerFloat), std::end(C6VC6XAccelerometerFloat));

         if(*C6VC6XAccelerometerFloat_max >= biggest)
             biggest = *C6VC6XAccelerometerFloat_max;
         if(*C6VC6XAccelerometerFloat_min <= smallest)
             smallest = *C6VC6XAccelerometerFloat_min;
     }
     if(ui->checkBox_64->isChecked())
     {
         auto C6VC6YAccelerometerFloat_max = std::max_element(std::begin(C6VC6YAccelerometerFloat), std::end(C6VC6YAccelerometerFloat));
         auto C6VC6YAccelerometerFloat_min = std::min_element(std::begin(C6VC6YAccelerometerFloat), std::end(C6VC6YAccelerometerFloat));

         if(*C6VC6YAccelerometerFloat_max >= biggest)
             biggest = *C6VC6YAccelerometerFloat_max;
         if(*C6VC6YAccelerometerFloat_min <= smallest)
             smallest = *C6VC6YAccelerometerFloat_min;
     }
     if(ui->checkBox_66->isChecked())
     {
         auto C6VC6ZAccelerometerFloat_max = std::max_element(std::begin(C6VC6ZAccelerometerFloat), std::end(C6VC6ZAccelerometerFloat));
         auto C6VC6ZAccelerometerFloat_min = std::min_element(std::begin(C6VC6ZAccelerometerFloat), std::end(C6VC6ZAccelerometerFloat));

         if(*C6VC6ZAccelerometerFloat_max >= biggest)
             biggest = *C6VC6ZAccelerometerFloat_max;
         if(*C6VC6ZAccelerometerFloat_min <= smallest)
             smallest = *C6VC6ZAccelerometerFloat_min;
     }
      ui->customPlot2->xAxis->setRange(0, C6curveX.size()*1.5, Qt::AlignLeft);

      //判断最大值和最小值是否相等
      if(biggest == smallest)
      {
                  if(biggest != 0)
              ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
          else
              ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
      }
      else
      {
          ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
      }

}
void MainWindow::set_checkBox_67_69_68()
{
    //速度误差
    double biggest = -999999999;
    double smallest = 999999999;
    if(ui->checkBox_67->isChecked())
    {
        auto VeastSpeedError_max = std::max_element(std::begin(VeastSpeedError), std::end(VeastSpeedError));
        auto VeastSpeedError_min = std::min_element(std::begin(VeastSpeedError), std::end(VeastSpeedError));

        if(*VeastSpeedError_max >= biggest)
            biggest = *VeastSpeedError_max;
        if(*VeastSpeedError_min <= smallest)
            smallest = *VeastSpeedError_min;
    }
    if(ui->checkBox_69->isChecked())
    {
        auto VnorthSpeedError_max = std::max_element(std::begin(VnorthSpeedError), std::end(VnorthSpeedError));
        auto VnorthSpeedError_min = std::min_element(std::begin(VnorthSpeedError), std::end(VnorthSpeedError));

        if(*VnorthSpeedError_max >= biggest)
            biggest = *VnorthSpeedError_max;
        if(*VnorthSpeedError_min <= smallest)
            smallest = *VnorthSpeedError_min;
    }
    if(ui->checkBox_68->isChecked())
    {
        auto VtogetherSpeedError_max = std::max_element(std::begin(VtogetherSpeedError), std::end(VtogetherSpeedError));
        auto VtogetherSpeedError_min = std::min_element(std::begin(VtogetherSpeedError), std::end(VtogetherSpeedError));

        if(*VtogetherSpeedError_max >= biggest)
            biggest = *VtogetherSpeedError_max;
        if(*VtogetherSpeedError_min <= smallest)
            smallest = *VtogetherSpeedError_min;
    }
    ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);

    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}
void MainWindow::set_checkBox_70_72_71()
{
    //位置误差
    double biggest = -999999999;
    double smallest = 999999999;
    if(ui->checkBox_70->isChecked())
    {
        auto VlatitudeError_max = std::max_element(std::begin(VlatitudeError), std::end(VlatitudeError));
        auto VlatitudeError_min = std::min_element(std::begin(VlatitudeError), std::end(VlatitudeError));

        if(*VlatitudeError_max >= biggest)
            biggest = *VlatitudeError_max;
        if(*VlatitudeError_min <= smallest)
            smallest = *VlatitudeError_min;
    }
    if(ui->checkBox_72->isChecked())
    {
        auto VlongitudeError_max = std::max_element(std::begin(VlongitudeError), std::end(VlongitudeError));
        auto VlongitudeError_min = std::min_element(std::begin(VlongitudeError), std::end(VlongitudeError));

        if(*VlongitudeError_max >= biggest)
            biggest = *VlongitudeError_max;
        if(*VlongitudeError_min <= smallest)
            smallest = *VlongitudeError_min;
    }
    if(ui->checkBox_71->isChecked())
    {
        auto VpositionError_max = std::max_element(std::begin(VpositionError), std::end(VpositionError));
        auto VpositionError_min = std::min_element(std::begin(VpositionError), std::end(VpositionError));

        if(*VpositionError_max >= biggest)
            biggest = *VpositionError_max;
        if(*VpositionError_min <= smallest)
            smallest = *VpositionError_min;
    }
    ui->customPlot2->xAxis->setRange(0, C1curveX.size()*1.5, Qt::AlignLeft);


    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
                if(biggest != 0)
            ui->customPlot2->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot2->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot2->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent* event)
{

    if(event->button()==Qt::LeftButton)
        if(ui->tabWidget->currentIndex()==5)
            on_pushButton_15_clicked();
        else if(ui->tabWidget->currentIndex()==6)
            resetY();
}



void MainWindow::on_pushButton_10_clicked()
{
    ui->checkBox_91->setChecked(0);
    ui->checkBox_88->setChecked(0);
    ui->checkBox_93->setChecked(0);
    ui->checkBox_90->setChecked(0);
    ui->checkBox_89->setChecked(0);
    ui->checkBox_92->setChecked(0);

    ui->checkBox_94->setChecked(0);
    ui->checkBox_95->setChecked(0);
    ui->checkBox_96->setChecked(0);
    ui->checkBox_97->setChecked(0);
    ui->checkBox_98->setChecked(0);
    ui->checkBox_99->setChecked(0);


    ui->checkBox_100->setChecked(0);
    ui->checkBox_101->setChecked(0);
    ui->checkBox_102->setChecked(0);

    ui->checkBox_106->setChecked(0);
    ui->checkBox_108->setChecked(0);
    ui->checkBox_103->setChecked(0);
    ui->checkBox_105->setChecked(0);
    ui->checkBox_104->setChecked(0);
    ui->checkBox_107->setChecked(0);


    ui->checkBox_109->setChecked(0);
    ui->checkBox_110->setChecked(0);
    ui->checkBox_111->setChecked(0);
    ui->checkBox_112->setChecked(0);
    ui->checkBox_113->setChecked(0);
    ui->checkBox_114->setChecked(0);

    ui->checkBox_115->setChecked(0);
    ui->checkBox_116->setChecked(0);
    ui->checkBox_117->setChecked(0);

    ui->checkBox_118->setChecked(0);
    ui->checkBox_119->setChecked(0);
    ui->checkBox_120->setChecked(0);

    ui->checkBox_121->setChecked(0);
    ui->checkBox_122->setChecked(0);
    ui->checkBox_123->setChecked(0);

    ui->checkBox_124->setChecked(0);
    ui->checkBox_125->setChecked(0);
    ui->checkBox_126->setChecked(0);

    ui->checkBox_127->setChecked(0);
    ui->checkBox_128->setChecked(0);
    ui->checkBox_129->setChecked(0);

    ui->checkBox_130->setChecked(0);
    ui->checkBox_131->setChecked(0);
    ui->checkBox_132->setChecked(0);

    ui->checkBox_133->setChecked(0);
    ui->checkBox_134->setChecked(0);
    ui->checkBox_135->setChecked(0);

    ui->checkBox_136->setChecked(0);
    ui->checkBox_137->setChecked(0);
    ui->checkBox_138->setChecked(0);

    ui->checkBox_139->setChecked(0);
    ui->checkBox_140->setChecked(0);
    ui->checkBox_141->setChecked(0);

    ui->checkBox_142->setChecked(0);
    ui->checkBox_143->setChecked(0);
    ui->checkBox_144->setChecked(0);

    ui->checkBox_145->setChecked(0);
    ui->checkBox_146->setChecked(0);
    ui->checkBox_147->setChecked(0);

    ui->checkBox_148->setChecked(0);
    ui->checkBox_149->setChecked(0);
    ui->checkBox_150->setChecked(0);
    ui->checkBox_151->setChecked(0);
    ui->checkBox_152->setChecked(0);
    ui->checkBox_153->setChecked(0);
    ui->checkBox_154->setChecked(0);
    ui->checkBox_155->setChecked(0);

    ui->checkBox_156->setChecked(0);
    ui->checkBox_157->setChecked(0);
    ui->checkBox_158->setChecked(0);
    ui->checkBox_159->setChecked(0);
    ui->checkBox_160->setChecked(0);
    ui->checkBox_161->setChecked(0);
    ui->checkBox_162->setChecked(0);

    ui->checkBox_163->setChecked(0);
    ui->checkBox_164->setChecked(0);
    ui->checkBox_165->setChecked(0);

    ui->checkBox_166->setChecked(0);
    ui->checkBox_167->setChecked(0);
    ui->checkBox_168->setChecked(0);

    ui->checkBox_169->setChecked(0);
    ui->checkBox_170->setChecked(0);
    ui->checkBox_171->setChecked(0);

    ui->checkBox_172->setChecked(0);
    ui->checkBox_173->setChecked(0);
    ui->checkBox_174->setChecked(0);

    QVector<double>().swap(valueVector1);
    QVector<double>().swap(valueVector2);
    QVector<double>().swap(valueVector3);
    QVector<double>().swap(valueVector4);
    QVector<double>().swap(valueVector5);
    QVector<double>().swap(valueVector6);
    QVector<double>().swap(valueVector7);
    QVector<double>().swap(valueVector8);
    QVector<double>().swap(valueVector9);
    QVector<double>().swap(valueVector10);
    QVector<double>().swap(valueVector11);
    QVector<double>().swap(valueVector12);
    QVector<double>().swap(valueVector13);
    QVector<double>().swap(valueVector14);
    QVector<double>().swap(valueVector15);
    QVector<double>().swap(valueVector16);
    QVector<double>().swap(valueVector17);
    QVector<double>().swap(valueVector18);
    QVector<double>().swap(valueVector19);
    QVector<double>().swap(valueVector20);
    QVector<double>().swap(valueVector21);
    QVector<double>().swap(valueVector22);
    QVector<double>().swap(valueVector23);
    QVector<double>().swap(valueVector24);
    QVector<double>().swap(valueVector25);
    QVector<double>().swap(valueVector26);
    QVector<double>().swap(valueVector27);
    QVector<double>().swap(valueVector28);
    QVector<double>().swap(valueVector29);
    QVector<double>().swap(valueVector30);
    QVector<double>().swap(valueVector31);
    QVector<double>().swap(valueVector32);
    QVector<double>().swap(valueVector33);
    QVector<double>().swap(valueVector34);
    QVector<double>().swap(valueVector35);
    QVector<double>().swap(valueVector36);
    QVector<double>().swap(valueVector37);
    QVector<double>().swap(valueVector38);
    QVector<double>().swap(valueVector39);
    QVector<double>().swap(valueVector40);
    QVector<double>().swap(valueVector41);
    QVector<double>().swap(valueVector42);
    QVector<double>().swap(valueVector43);
    QVector<double>().swap(valueVector44);
    QVector<double>().swap(valueVector45);
    QVector<double>().swap(valueVector46);
    QVector<double>().swap(valueVector47);
    QVector<double>().swap(valueVector48);
    QVector<double>().swap(valueVector49);
    QVector<double>().swap(valueVector50);
    QVector<double>().swap(valueVector51);
    QVector<double>().swap(valueVector52);
    QVector<double>().swap(valueVector53);
    QVector<double>().swap(valueVector54);
    QVector<double>().swap(valueVector55);
    QVector<double>().swap(valueVector56);
    QVector<double>().swap(valueVector57);
    QVector<double>().swap(valueVector58);
    QVector<double>().swap(valueVector59);
    QVector<double>().swap(valueVector60);
    QVector<double>().swap(valueVector61);
    QVector<double>().swap(valueVector62);
    QVector<double>().swap(valueVector63);
    QVector<double>().swap(valueVector64);
    QVector<double>().swap(valueVector65);
    QVector<double>().swap(valueVector66);
    QVector<double>().swap(valueVector67);
    QVector<double>().swap(valueVector68);
    QVector<double>().swap(valueVector69);
    QVector<double>().swap(valueVector70);
    QVector<double>().swap(valueVector71);
    QVector<double>().swap(valueVector72);
    QVector<double>().swap(valueVector73);
    QVector<double>().swap(valueVector74);
    QVector<double>().swap(valueVector75);
    QVector<double>().swap(valueVector76);
    QVector<double>().swap(valueVector77);
    QVector<double>().swap(valueVector78);
    QVector<double>().swap(valueVector79);
    QVector<double>().swap(valueVector80);
    QVector<double>().swap(valueVector81);
    QVector<double>().swap(valueVector82);
    QVector<double>().swap(valueVector83);
    QVector<double>().swap(valueVector84);
    QVector<double>().swap(valueVector85);
    QVector<double>().swap(valueVector86);
    QVector<double>().swap(valueVector87);
    QVector<double>().swap(valueVector1X);
    QVector<double>().swap(valueVector2X);
    QVector<double>().swap(valueVector3X);
    QVector<double>().swap(valueVector4X);
    QVector<double>().swap(valueVector5X);
    QVector<double>().swap(valueVector6X);
    QVector<double>().swap(valueVector7X);
    QVector<double>().swap(valueVector8X);
    QVector<double>().swap(valueVector9X);
    QVector<double>().swap(valueVector10X);
    QVector<double>().swap(valueVector11X);
    QVector<double>().swap(valueVector12X);
    QVector<double>().swap(valueVector13X);
    QVector<double>().swap(valueVector14X);
    QVector<double>().swap(valueVector15X);
    QVector<double>().swap(valueVector16X);
    QVector<double>().swap(valueVector17X);
    QVector<double>().swap(valueVector18X);
    QVector<double>().swap(valueVector19X);
    QVector<double>().swap(valueVector20X);
    QVector<double>().swap(valueVector21X);
    QVector<double>().swap(valueVector22X);
    QVector<double>().swap(valueVector23X);
    QVector<double>().swap(valueVector24X);
    QVector<double>().swap(valueVector25X);
    QVector<double>().swap(valueVector26X);
    QVector<double>().swap(valueVector27X);
    QVector<double>().swap(valueVector28X);
    QVector<double>().swap(valueVector29X);
    QVector<double>().swap(valueVector30X);
    QVector<double>().swap(valueVector31X);
    QVector<double>().swap(valueVector32X);
    QVector<double>().swap(valueVector33X);
    QVector<double>().swap(valueVector34X);
    QVector<double>().swap(valueVector35X);
    QVector<double>().swap(valueVector36X);
    QVector<double>().swap(valueVector37X);
    QVector<double>().swap(valueVector38X);
    QVector<double>().swap(valueVector39X);
    QVector<double>().swap(valueVector40X);
    QVector<double>().swap(valueVector41X);
    QVector<double>().swap(valueVector42X);
    QVector<double>().swap(valueVector43X);
    QVector<double>().swap(valueVector44X);
    QVector<double>().swap(valueVector45X);
    QVector<double>().swap(valueVector46X);
    QVector<double>().swap(valueVector47X);
    QVector<double>().swap(valueVector48X);
    QVector<double>().swap(valueVector49X);
    QVector<double>().swap(valueVector50X);
    QVector<double>().swap(valueVector51X);
    QVector<double>().swap(valueVector52X);
    QVector<double>().swap(valueVector53X);
    QVector<double>().swap(valueVector54X);
    QVector<double>().swap(valueVector55X);
    QVector<double>().swap(valueVector56X);
    QVector<double>().swap(valueVector57X);
    QVector<double>().swap(valueVector58X);
    QVector<double>().swap(valueVector59X);
    QVector<double>().swap(valueVector60X);
    QVector<double>().swap(valueVector61X);
    QVector<double>().swap(valueVector62X);
    QVector<double>().swap(valueVector63X);
    QVector<double>().swap(valueVector64X);
    QVector<double>().swap(valueVector65X);
    QVector<double>().swap(valueVector66X);
    QVector<double>().swap(valueVector67X);
    QVector<double>().swap(valueVector68X);
    QVector<double>().swap(valueVector69X);
    QVector<double>().swap(valueVector70X);
    QVector<double>().swap(valueVector71X);
    QVector<double>().swap(valueVector72X);
    QVector<double>().swap(valueVector73X);
    QVector<double>().swap(valueVector74X);
    QVector<double>().swap(valueVector75X);
    QVector<double>().swap(valueVector76X);
    QVector<double>().swap(valueVector77X);
    QVector<double>().swap(valueVector78X);
    QVector<double>().swap(valueVector79X);
    QVector<double>().swap(valueVector80X);
    QVector<double>().swap(valueVector81X);
    QVector<double>().swap(valueVector82X);
    QVector<double>().swap(valueVector83X);
    QVector<double>().swap(valueVector84X);
    QVector<double>().swap(valueVector85X);
    QVector<double>().swap(valueVector86X);
    QVector<double>().swap(valueVector87X);

    QCustomPlot* customPlot = ui->customPlot3;
    ui->customPlot3->clearGraphs();
    ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);
    graphPointNum = 0;
    QString path = QFileDialog::getOpenFileName(this,tr("打开曲线"),"./","*.dat");
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开曲线文件"),
                                 tr("打开曲线文件失败，请检查文件名和是否具有读取权限！"));
            return;
        }

        QTextStream stream(&file);
        stream.setCodec("utf-8");  // 要读的文件是utf-8编码
        stream.setGenerateByteOrderMark(true);  // 带bom的utf8
        QString start = stream.readLine();

        QStringList startList = start.split(",");
        if(startList[0] != "<CurveProfileNew>")
        {
            //曲线格式错误
            QMessageBox::warning(this, tr("打开曲线文件"),
                                 tr("文件格式错误！"));
            return;
        }
        graphPointNum = startList[1].toUInt();

        QProgressDialog *progressDialog = new QProgressDialog(this);
        QFont font("ZYSong18030", 12);
        progressDialog->setFont(font);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(5);
        progressDialog->setWindowTitle(tr("打开曲线"));
        progressDialog->setLabelText(tr("打开中..."));
        progressDialog->setCancelButtonText(tr("取消"));
        progressDialog->setRange(0, graphPointNum);
        long  currentPoint = 0;

        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            if(line == "</CurveProfileNew>")
                break;
            QStringList lineList = line.split(",");

            if(lineList[0]!="N")
            {
                valueVector1.append( lineList[0].toFloat());
                valueVector1X.append(currentPoint);
            }
            if(lineList[1]!="N")
            {
                valueVector2.append( lineList[1].toFloat());
                valueVector2X.append(currentPoint);
            }
            if(lineList[2]!="N")
            {
                valueVector3.append( lineList[2].toFloat());
                valueVector3X.append(currentPoint);
            }
            if(lineList[3]!="N")
            {
                valueVector4.append( lineList[3].toFloat());
                valueVector4X.append(currentPoint);
            }
            if(lineList[4]!="N")
            {
                valueVector5.append( lineList[4].toFloat());
                valueVector5X.append(currentPoint);
            }
            if(lineList[5]!="N")
            {
                valueVector6.append( lineList[5].toFloat());
                valueVector6X.append(currentPoint);
            }
            if(lineList[6]!="N")
            {
                valueVector7.append( lineList[6].toFloat());
                valueVector7X.append(currentPoint);
            }
            if(lineList[7]!="N")
            {
                valueVector8.append( lineList[7].toFloat());
                valueVector8X.append(currentPoint);
            }
            if(lineList[8]!="N")
            {
                valueVector9.append( lineList[8].toFloat());
                valueVector9X.append(currentPoint);
            }
            if(lineList[9]!="N")
            {
                valueVector10.append( lineList[9].toFloat());
                valueVector10X.append(currentPoint);
            }
            if(lineList[10]!="N")
            {
                valueVector11.append( lineList[10].toFloat());
                valueVector11X.append(currentPoint);
            }
            if(lineList[11]!="N")
            {
                valueVector12.append( lineList[11].toFloat());
                valueVector12X.append(currentPoint);
            }
            if(lineList[12]!="N")
            {
                valueVector13.append( lineList[12].toFloat());
                valueVector13X.append(currentPoint);
            }
            if(lineList[13]!="N")
            {
                valueVector14.append( lineList[13].toFloat());
                valueVector14X.append(currentPoint);
            }
            if(lineList[14]!="N")
            {
                valueVector15.append( lineList[14].toFloat());
                valueVector15X.append(currentPoint);
            }
            if(lineList[15]!="N")
            {
                valueVector16.append( lineList[15].toFloat());
                valueVector16X.append(currentPoint);
            }
            if(lineList[16]!="N")
            {
                valueVector17.append( lineList[16].toFloat());
                valueVector17X.append(currentPoint);
            }
            if(lineList[17]!="N")
            {
                valueVector18.append( lineList[17].toFloat());
                valueVector18X.append(currentPoint);
            }
            if(lineList[18]!="N")
            {
                valueVector19.append( lineList[18].toFloat());
                valueVector19X.append(currentPoint);
            }
            if(lineList[19]!="N")
            {
                valueVector20.append( lineList[19].toFloat());
                valueVector20X.append(currentPoint);
            }
            if(lineList[20]!="N")
            {
                valueVector21.append( lineList[20].toFloat());
                valueVector21X.append(currentPoint);
            }
            if(lineList[21]!="N")
            {
                valueVector22.append( lineList[21].toFloat());
                valueVector22X.append(currentPoint);
            }
            if(lineList[22]!="N")
            {
                valueVector23.append( lineList[22].toFloat());
                valueVector23X.append(currentPoint);
            }
            if(lineList[23]!="N")
            {
                valueVector24.append( lineList[23].toFloat());
                valueVector24X.append(currentPoint);
            }
            if(lineList[24]!="N")
            {
                valueVector25.append( lineList[24].toFloat());
                valueVector25X.append(currentPoint);
            }
            if(lineList[25]!="N")
            {
                valueVector26.append( lineList[25].toFloat());
                valueVector26X.append(currentPoint);
            }
            if(lineList[26]!="N")
            {
                valueVector27.append( lineList[26].toFloat());
                valueVector27X.append(currentPoint);
            }
            if(lineList[27]!="N")
            {
                valueVector28.append( lineList[27].toFloat());
                valueVector28X.append(currentPoint);
            }
            if(lineList[28]!="N")
            {
                valueVector29.append( lineList[28].toFloat());
                valueVector29X.append(currentPoint);
            }
            if(lineList[29]!="N")
            {
                valueVector30.append( lineList[29].toFloat());
                valueVector30X.append(currentPoint);
            }
            if(lineList[30]!="N")
            {
                valueVector31.append( lineList[30].toFloat());
                valueVector31X.append(currentPoint);
            }
            if(lineList[31]!="N")
            {
                valueVector32.append( lineList[31].toFloat());
                valueVector32X.append(currentPoint);
            }
            if(lineList[32]!="N")
            {
                valueVector33.append( lineList[32].toFloat());
                valueVector33X.append(currentPoint);
            }
            if(lineList[33]!="N")
            {
                valueVector34.append( lineList[33].toFloat());
                valueVector34X.append(currentPoint);
            }
            if(lineList[34]!="N")
            {
                valueVector35.append( lineList[34].toFloat());
                valueVector35X.append(currentPoint);
            }
            if(lineList[35]!="N")
            {
                valueVector36.append( lineList[35].toFloat());
                valueVector36X.append(currentPoint);
            }
            if(lineList[36]!="N")
            {
                valueVector37.append( lineList[36].toFloat());
                valueVector37X.append(currentPoint);
            }
            if(lineList[37]!="N")
            {
                valueVector38.append( lineList[37].toFloat());
                valueVector38X.append(currentPoint);
            }
            if(lineList[38]!="N")
            {
                valueVector39.append( lineList[38].toFloat());
                valueVector39X.append(currentPoint);
            }
            if(lineList[39]!="N")
            {
                valueVector40.append( lineList[39].toFloat());
                valueVector40X.append(currentPoint);
            }
            if(lineList[40]!="N")
            {
                valueVector41.append( lineList[40].toFloat());
                valueVector41X.append(currentPoint);
            }
            if(lineList[41]!="N")
            {
                valueVector42.append( lineList[41].toFloat());
                valueVector42X.append(currentPoint);
            }
            if(lineList[42]!="N")
            {
                valueVector43.append( lineList[42].toFloat());
                valueVector43X.append(currentPoint);
            }
            if(lineList[43]!="N")
            {
                valueVector44.append( lineList[43].toFloat());
                valueVector44X.append(currentPoint);
            }
            if(lineList[44]!="N")
            {
                valueVector45.append( lineList[44].toFloat());
                valueVector45X.append(currentPoint);
            }
            if(lineList[45]!="N")
            {
                valueVector46.append( lineList[45].toFloat());
                valueVector46X.append(currentPoint);
            }
            if(lineList[46]!="N")
            {
                valueVector47.append( lineList[46].toFloat());
                valueVector47X.append(currentPoint);
            }
            if(lineList[47]!="N")
            {
                valueVector48.append( lineList[47].toFloat());
                valueVector48X.append(currentPoint);
            }
            if(lineList[48]!="N")
            {
                valueVector49.append( lineList[48].toFloat());
                valueVector49X.append(currentPoint);
            }
            if(lineList[49]!="N")
            {
                valueVector50.append( lineList[49].toFloat());
                valueVector50X.append(currentPoint);
            }
            if(lineList[50]!="N")
            {
                valueVector51.append( lineList[50].toFloat());
                valueVector51X.append(currentPoint);
            }
            if(lineList[51]!="N")
            {
                valueVector52.append( lineList[51].toFloat());
                valueVector52X.append(currentPoint);
            }
            if(lineList[52]!="N")
            {
                valueVector53.append( lineList[52].toFloat());
                valueVector53X.append(currentPoint);
            }
            if(lineList[53]!="N")
            {
                valueVector54.append( lineList[53].toFloat());
                valueVector54X.append(currentPoint);
            }
            if(lineList[54]!="N")
            {
                valueVector55.append( lineList[54].toFloat());
                valueVector55X.append(currentPoint);
            }
            if(lineList[55]!="N")
            {
                valueVector56.append( lineList[55].toFloat());
                valueVector56X.append(currentPoint);
            }
            if(lineList[56]!="N")
            {
                valueVector57.append( lineList[56].toFloat());
                valueVector57X.append(currentPoint);
            }
            if(lineList[57]!="N")
            {
                valueVector58.append( lineList[57].toFloat());
                valueVector58X.append(currentPoint);
            }
            if(lineList[58]!="N")
            {
                valueVector59.append( lineList[58].toFloat());
                valueVector59X.append(currentPoint);
            }
            if(lineList[59]!="N")
            {
                valueVector60.append( lineList[59].toFloat());
                valueVector60X.append(currentPoint);
            }
            if(lineList[60]!="N")
            {
                valueVector61.append( lineList[60].toFloat());
                valueVector61X.append(currentPoint);
            }
            if(lineList[61]!="N")
            {
                valueVector62.append( lineList[61].toFloat());
                valueVector62X.append(currentPoint);
            }
            if(lineList[62]!="N")
            {
                valueVector63.append( lineList[62].toFloat());
                valueVector63X.append(currentPoint);
            }
            if(lineList[63]!="N")
            {
                valueVector64.append( lineList[63].toFloat());
                valueVector64X.append(currentPoint);
            }
            if(lineList[64]!="N")
            {
                valueVector65.append( lineList[64].toFloat());
                valueVector65X.append(currentPoint);
            }
            if(lineList[65]!="N")
            {
                valueVector66.append( lineList[65].toFloat());
                valueVector66X.append(currentPoint);
            }
            if(lineList[66]!="N")
            {
                valueVector67.append( lineList[66].toFloat());
                valueVector67X.append(currentPoint);
            }
            if(lineList[67]!="N")
            {
                valueVector68.append( lineList[67].toFloat());
                valueVector68X.append(currentPoint);
            }
            if(lineList[68]!="N")
            {
                valueVector69.append( lineList[68].toFloat());
                valueVector69X.append(currentPoint);
            }
            if(lineList[69]!="N")
            {
                valueVector70.append( lineList[69].toFloat());
                valueVector70X.append(currentPoint);
            }
            if(lineList[70]!="N")
            {
                valueVector71.append( lineList[70].toFloat());
                valueVector71X.append(currentPoint);
            }
            if(lineList[71]!="N")
            {
                valueVector72.append( lineList[71].toFloat());
                valueVector72X.append(currentPoint);
            }
            if(lineList[72]!="N")
            {
                valueVector73.append( lineList[72].toFloat());
                valueVector73X.append(currentPoint);
            }
            if(lineList[73]!="N")
            {
                valueVector74.append( lineList[73].toFloat());
                valueVector74X.append(currentPoint);
            }
            if(lineList[74]!="N")
            {
                valueVector75.append( lineList[74].toFloat());
                valueVector75X.append(currentPoint);
            }
            if(lineList[75]!="N")
            {
                valueVector76.append( lineList[75].toFloat());
                valueVector76X.append(currentPoint);
            }
            if(lineList[76]!="N")
            {
                valueVector77.append( lineList[76].toFloat());
                valueVector77X.append(currentPoint);
            }
            if(lineList[77]!="N")
            {
                valueVector78.append( lineList[77].toFloat());
                valueVector78X.append(currentPoint);
            }
            if(lineList[78]!="N")
            {
                valueVector79.append( lineList[78].toFloat());
                valueVector79X.append(currentPoint);
            }
            if(lineList[79]!="N")
            {
                valueVector80.append( lineList[79].toFloat());
                valueVector80X.append(currentPoint);
            }
            if(lineList[80]!="N")
            {
                valueVector81.append( lineList[80].toFloat());
                valueVector81X.append(currentPoint);
            }
            if(lineList[81]!="N")
            {
                valueVector82.append( lineList[81].toFloat());
                valueVector82X.append(currentPoint);
            }
            if(lineList[82]!="N")
            {
                valueVector83.append( lineList[82].toFloat());
                valueVector83X.append(currentPoint);
            }
            if(lineList[83]!="N")
            {
                valueVector84.append( lineList[83].toFloat());
                valueVector84X.append(currentPoint);
            }
            if(lineList[84]!="N")
            {
                valueVector85.append( lineList[84].toFloat());
                valueVector85X.append(currentPoint);
            }
            if(lineList[85]!="N")
            {
                valueVector86.append( lineList[85].toFloat());
                valueVector86X.append(currentPoint);
            }
            if(lineList[86]!="N")
            {
                valueVector87.append( lineList[86].toFloat());
                valueVector87X.append(currentPoint);
            }
            currentPoint++;
            progressDialog->setValue(currentPoint);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                file.close();
                progressDialog =NULL;
                return;
            }
        }
        delete progressDialog;
        file.close();
        progressDialog = NULL;
        QMessageBox::information(NULL, "提示", "打开成功！");
    }
}
//void MainWindow::drawAllCurve()
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;
//    //if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    //if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    //if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    //if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    //if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    //if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    //if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    //if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }

//}

//void MainWindow::on_checkBox1_stateChanged(int arg1)
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;

//    if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }

//}


//void MainWindow::on_checkBox2_stateChanged(int arg1)
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;

//    if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//}

//void MainWindow::on_checkBox3_stateChanged(int arg1)
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;

//    if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//}

//void MainWindow::on_checkBox4_stateChanged(int arg1)
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;

//    if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//}

//void MainWindow::on_checkBox5_stateChanged(int arg1)
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;

//    if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//}

//void MainWindow::on_checkBox6_stateChanged(int arg1)
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;

//    if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//}


//void MainWindow::on_checkBox6_2_stateChanged(int arg1)
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;

//    if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//}

//void MainWindow::on_checkBox6_3_stateChanged(int arg1)
//{
//    QCustomPlot* customPlot = ui->customPlot3;

//    int graphNum = 0;

//    if(ui->checkBox1->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector1);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(128,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//       reSet();  //调整Y轴为最大
//       customPlot->replot(QCustomPlot::rpQueuedReplot);
//    }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,143,122));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox4->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(255,0,128));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector4);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox5->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(147,108,0));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector5);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,0,255));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,71,75));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_2);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        graphNum = customPlot->graphCount();
//        customPlot->addGraph();
//        QPen pen;
//        pen.setColor(QColor(0,200,244));
//        customPlot->graph(graphNum)->setPen(pen);

//        customPlot->yAxis->setNumberPrecision(7);
//        customPlot->graph(graphNum)->setData(X,valueVector6_3);
//        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
//        reSet();  //调整Y轴为最大
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//     }
//    else
//    {
//        customPlot->clearGraphs();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);
//        drawAllCurve();
//        customPlot->replot(QCustomPlot::rpQueuedReplot);

//    }
//}

//void MainWindow::reSet()
//{
//    double biggest = -999999999;
//    double smallest = 999999999;

//    if(ui->checkBox1->isChecked())
//    {
//        auto C1Vheave_max = std::max_element(std::begin(valueVector1), std::end(valueVector1));
//        auto C1Vheave_min = std::min_element(std::begin(valueVector1), std::end(valueVector1));

//        if(*C1Vheave_max >= biggest)
//            biggest = *C1Vheave_max;
//        if(*C1Vheave_min <= smallest)
//            smallest = *C1Vheave_min;
//    }
//    if(ui->checkBox2->isChecked())
//    {
//        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector2), std::end(valueVector2));
//        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector2), std::end(valueVector2));

//        if(*C1VverticalVelocity_max >= biggest)
//            biggest = *C1VverticalVelocity_max;
//        if(*C1VverticalVelocity_min <= smallest)
//            smallest = *C1VverticalVelocity_min;
//    }
//    if(ui->checkBox3->isChecked())
//    {
//        auto C1Vsway_max = std::max_element(std::begin(valueVector3), std::end(valueVector3));
//        auto C1Vsway_min = std::min_element(std::begin(valueVector3), std::end(valueVector3));

//        if(*C1Vsway_max >= biggest)
//            biggest = *C1Vsway_max;
//        if(*C1Vsway_min <= smallest)
//            smallest = *C1Vsway_min;
//    }

//    if(ui->checkBox4->isChecked())
//    {
//        auto C1VtransverseVelocity_max = std::max_element(std::begin(valueVector4), std::end(valueVector4));
//        auto C1VtransverseVelocity_min = std::min_element(std::begin(valueVector4), std::end(valueVector4));

//        if(*C1VtransverseVelocity_max >= biggest)
//            biggest = *C1VtransverseVelocity_max;
//        if(*C1VtransverseVelocity_min <= smallest)
//            smallest = *C1VtransverseVelocity_min;
//    }
//    if(ui->checkBox5->isChecked())
//    {
//        auto C1Vsurge_max = std::max_element(std::begin(valueVector5), std::end(valueVector5));
//        auto C1Vsurge_min = std::min_element(std::begin(valueVector5), std::end(valueVector5));

//        if(*C1Vsurge_max >= biggest)
//            biggest = *C1Vsurge_max;
//        if(*C1Vsurge_min <= smallest)
//            smallest = *C1Vsurge_min;
//    }
//    if(ui->checkBox6->isChecked())
//    {
//        auto C1Vsway_max = std::max_element(std::begin(valueVector6), std::end(valueVector6));
//        auto C1Vsway_min = std::min_element(std::begin(valueVector6), std::end(valueVector6));

//        if(*C1Vsway_max >= biggest)
//            biggest = *C1Vsway_max;
//        if(*C1Vsway_min <= smallest)
//            smallest = *C1Vsway_min;
//    }
//    if(ui->checkBox6_2->isChecked())
//    {
//        auto C1Vsway_max = std::max_element(std::begin(valueVector6_2), std::end(valueVector6_2));
//        auto C1Vsway_min = std::min_element(std::begin(valueVector6_2), std::end(valueVector6_2));

//        if(*C1Vsway_max >= biggest)
//            biggest = *C1Vsway_max;
//        if(*C1Vsway_min <= smallest)
//            smallest = *C1Vsway_min;
//    }
//    if(ui->checkBox6_3->isChecked())
//    {
//        auto C1Vsway_max = std::max_element(std::begin(valueVector6_3), std::end(valueVector6_3));
//        auto C1Vsway_min = std::min_element(std::begin(valueVector6_3), std::end(valueVector6_3));

//        if(*C1Vsway_max >= biggest)
//            biggest = *C1Vsway_max;
//        if(*C1Vsway_min <= smallest)
//            smallest = *C1Vsway_min;
//    }
//  ui->customPlot3->xAxis->setRange(0, X.size(), Qt::AlignLeft);
//    //判断最大值和最小值是否相等
//    if(biggest == smallest)
//    {
//                if(biggest != 0)
//            ui->customPlot3->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
//        else
//            ui->customPlot3->yAxis->setRange(-5, 10, Qt::AlignLeft);
//    }
//    else
//    {
//        ui->customPlot3->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
//    }


//    ui->customPlot3->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);
//    ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);

//}

void MainWindow::on_action_ms_triggered()
{
    handleResultDelayData->show();
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(index == 1)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(index == 2)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(index == 3)
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if(index == 4)
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(index == 5)
    {
        ui->stackedWidget->setCurrentIndex(11);
    }
    else if(index == 6)
    {
        ui->stackedWidget->setCurrentIndex(12);
    }

    else if(index == 7)
    {
        ui->stackedWidget->setCurrentIndex(13);
    }

    else if(index == 8)
    {
        ui->stackedWidget->setCurrentIndex(14);
    }

    else if(index == 9)
    {
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(index == 10)
    {
        ui->stackedWidget->setCurrentIndex(16);
    }
    else if(index == 11)
    {
        ui->stackedWidget->setCurrentIndex(17);
    }
    else if(index == 12)
    {
        ui->stackedWidget->setCurrentIndex(20);
    }
    else if(index == 13)
    {
        ui->stackedWidget->setCurrentIndex(21);
    }
    ui->checkBox->setChecked(0);
    ui->checkBox->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_2->setChecked(0);
    ui->checkBox_2->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_82->setChecked(0);

    ui->checkBox_3->setChecked(0);
    ui->checkBox_3->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_4->setChecked(0);
    ui->checkBox_4->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_5->setChecked(0);
    ui->checkBox_5->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_6->setChecked(0);
    ui->checkBox_6->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_7->setChecked(0);
    ui->checkBox_7->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_8->setChecked(0);
    ui->checkBox_8->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_9->setChecked(0);
    ui->checkBox_9->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_10->setChecked(0);
    ui->checkBox_10->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_11->setChecked(0);
    ui->checkBox_11->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_12->setChecked(0);
    ui->checkBox_12->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_13->setChecked(0);
    ui->checkBox_13->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_14->setChecked(0);
    ui->checkBox_14->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_15->setChecked(0);
    ui->checkBox_15->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");

    ui->checkBox_16->setChecked(0);
    ui->checkBox_16->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

    ui->checkBox_17->setChecked(0);
    ui->checkBox_17->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_18->setChecked(0);
    ui->checkBox_18->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_19->setChecked(0);
    ui->checkBox_19->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_20->setChecked(0);
    ui->checkBox_20->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_21->setChecked(0);
    ui->checkBox_21->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_22->setChecked(0);
    ui->checkBox_22->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_23->setChecked(0);
    ui->checkBox_23->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_24->setChecked(0);
    ui->checkBox_24->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_25->setChecked(0);
    ui->checkBox_25->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_26->setChecked(0);
    ui->checkBox_27->setChecked(0);
    ui->checkBox_28->setChecked(0);
    ui->checkBox_29->setChecked(0);
    ui->checkBox_30->setChecked(0);
    ui->checkBox_31->setChecked(0);
    ui->checkBox_32->setChecked(0);
    ui->checkBox_33->setChecked(0);
    ui->checkBox_34->setChecked(0);
    ui->checkBox_35->setChecked(0);
    ui->checkBox_36->setChecked(0);
    ui->checkBox_37->setChecked(0);
    ui->checkBox_40->setChecked(0);
    ui->checkBox_38->setChecked(0);
    ui->checkBox_39->setChecked(0);
    ui->checkBox_42->setChecked(0);
    ui->checkBox_43->setChecked(0);
    ui->checkBox_41->setChecked(0);
    ui->checkBox_45->setChecked(0);
    ui->checkBox_46->setChecked(0);
    ui->checkBox_44->setChecked(0);
    ui->checkBox_48->setChecked(0);
    ui->checkBox_49->setChecked(0);
    ui->checkBox_47->setChecked(0);
    ui->checkBox_50->setChecked(0);
    ui->checkBox_51->setChecked(0);
    ui->checkBox_52->setChecked(0);
    ui->checkBox_53->setChecked(0);
    ui->checkBox_54->setChecked(0);
    ui->checkBox_55->setChecked(0);
    ui->checkBox_56->setChecked(0);
    ui->checkBox_57->setChecked(0);
    ui->checkBox_58->setChecked(0);
    ui->checkBox_59->setChecked(0);
    ui->checkBox_60->setChecked(0);
    ui->checkBox_61->setChecked(0);
    ui->checkBox_62->setChecked(0);
    ui->checkBox_63->setChecked(0);
    ui->checkBox_64->setChecked(0);
    ui->checkBox_65->setChecked(0);
    ui->checkBox_66->setChecked(0);
    ui->checkBox_67->setChecked(0);
    ui->checkBox_68->setChecked(0);
    ui->checkBox_69->setChecked(0);
    ui->checkBox_70->setChecked(0);
    ui->checkBox_71->setChecked(0);
    ui->checkBox_72->setChecked(0);


    ui->checkBox_73->setChecked(0);
    ui->checkBox_74->setChecked(0);
    ui->checkBox_75->setChecked(0);
    ui->checkBox_76->setChecked(0);
    ui->checkBox_77->setChecked(0);
    ui->checkBox_78->setChecked(0);
    ui->checkBox_79->setChecked(0);
    ui->checkBox_80->setChecked(0);
    ui->checkBox_81->setChecked(0);
    ui->checkBox_82->setChecked(0);
    ui->checkBox_83->setChecked(0);
    ui->checkBox_84->setChecked(0);
    ui->checkBox_85->setChecked(0);
    ui->checkBox_86->setChecked(0);
    ui->checkBox_87->setChecked(0);



    C8HeightRun = 0;
    C8HeightNum = 0;

    C8UpSpeedRun = 0;
    C8UpSpeedNum = 0;


    C8LogDownSpeed2GroundRun = 0;
    C8LogDownSpeed2GroundNum = 0;


    C8LogDownSpeed2WaterRun = 0;
    C8LogDownSpeed2WaterNum = 0;


    C1latitudeCurveRun=0;               //判断C1纬度曲线是否存在
    C1latitudeGraphNum=0;              //纬度在当前画图板中是第几条曲线


    C1headingAngleRun=0;                //判断C1航向曲线是否存在
    C1headingAngleNum=0;              //航向在当前画图板qreal rollAngle中是第几条曲线


    C1longitudeRun=0;                //判断C1经度曲线是否存在
    C1longitudeNum=0;              //经度在当前画图板中是第几条曲线

    C1rollAngleRun=0;                //判断C1横摇角曲线是否存在
    C1rollAngleNum=0;              //横摇角在当前画图板中是第几条曲线


    C1pitchAngleRun=0;                //判断C1纵摇角曲线是否存在
    C1pitchAngleNum=0;              //纵摇角在当前画图板中是第几条曲线


    C1northSpeedRun=0;                //判断C1北速曲线是否存在
    C1northSpeedNum=0;              //北速在当前画图板中是第几条曲线

    C1eastSpeedRun=0;                //判断C1东速曲线是否存在
    C1eastSpeedNum=0;              //东速在当前画图板中是第几条曲线


    C1headingAngularSpeedRun=0;                //判断C1航向角速度曲线是否存在
    C1headingAngularSpeedNum=0;


    C1rollAngleSpeedRun=0;                //判断C1横摇角速度曲线是否存在
    C1rollAngleSpeedNum=0;

    C1pitchAngleSpeedRun=0;                //判断C1纵摇角速度曲线是否存在
    C1pitchAngleSpeedNum=0;


    C1heaveRun=0;                //判断C1垂荡曲线是否存在
    C1heaveNum=0;


    C1verticalVelocityRun=0;                //判断C1垂速曲线是否存在
    C1verticalVelocityNum=0;


    C1swayRun=0;                //判断C1横荡曲线是否存在
    C1swayNum=0;


    C1transverseVelocityRun=0;                //判断C1横速曲线是否存在
    C1transverseVelocityNum=0;


    C1surgeRun=0;                //判断C1纵荡曲线是否存在
    C1surgeNum=0;


    C1longitudinalVelocityRun=0;                //判断C1纵速曲线是否存在
    C1longitudinalVelocityNum=0;


    C5XGyroAngleIncreaseFloatRun=0;                //判断C5X陀螺增量曲线是否存在
    C5XGyroAngleIncreaseFloatNum=0;


    C5YGyroAngleIncreaseFloatRun=0;                //判断C5Y陀螺增量曲线是否存在
    C5YGyroAngleIncreaseFloatNum=0;


    C5ZGyroAngleIncreaseFloatRun=0;                //判断C5Z陀螺增量曲线是否存在
    C5ZGyroAngleIncreaseFloatNum=0;


    C5XAccelerometerSpeedIncrementFloatRun=0;                //判断C5X加表增量曲线是否存在
    C5XAccelerometerSpeedIncrementFloatNum=0;


    C5YAccelerometerSpeedIncrementFloatRun=0;                //判断C5Y加表增量曲线是否存在
    C5YAccelerometerSpeedIncrementFloatNum=0;


    C5ZAccelerometerSpeedIncrementFloatRun=0;                //判断C5Z加表增量曲线是否存在
    C5ZAccelerometerSpeedIncrementFloatNum=0;


    C5XgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的x陀螺1s补偿后角增量曲线是否存在
    C5XgyroCompensatedAngleIncrementFloatNum=0;

    C5YgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的Y陀螺1s补偿后角增量曲线是否存在
    C5YgyroCompensatedAngleIncrementFloatNum=0;


    C5ZgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的Z陀螺1s补偿后角增量曲线是否存在
    C5ZgyroCompensatedAngleIncrementFloatNum=0;


    C5XAccVelocityIncrementFloatRun=0;                //判断C5的x加速度计1s补偿后速度增量曲线是否存在
    C5XAccVelocityIncrementFloatNum=0;


    C5YAccVelocityIncrementFloatRun=0;                //判断C5的Y加速度计1s补偿后速度增量曲线是否存在
    C5YAccVelocityIncrementFloatNum=0;


    C5ZAccVelocityIncrementFloatRun=0;                //判断C5的Z加速度计1s补偿后速度增量曲线是否存在
    C5ZAccVelocityIncrementFloatNum=0;


    C5XgyroDifFrequencyRun=0;                //判断C5的X陀螺差频曲线是否存在
    C5XgyroDifFrequencyNum=0;


    C5YgyroDifFrequencyRun=0;                //判断C5的Y陀螺差频曲线是否存在
    C5YgyroDifFrequencyNum=0;


    C5ZgyroDifFrequencyRun=0;                //判断C5的Z陀螺差频曲线是否存在
    C5ZgyroDifFrequencyNum=0;


    C5XaccelerometerDifFreRun=0;                //判断C5的X加速度计差频曲线是否存在
    C5XaccelerometerDifFreNum=0;


    C5YaccelerometerDifFreRun=0;                //判断C5的Y加速度计差频曲线是否存在
    C5YaccelerometerDifFreNum=0;


    C5ZaccelerometerDifFreRun=0;                //判断C5的Z加速度计差频曲线是否存在
    C5ZaccelerometerDifFreNum=0;


    C5XgyroTemp1Run=0;                //判断C5的X陀螺温度1是否存在
    C5XgyroTemp1Num=0;


    C5YgyroTemp1Run=0;                //判断C5的Y陀螺温度1是否存在
    C5YgyroTemp1Num=0;


    C5ZgyroTemp1Run=0;                //判断C5的Z陀螺温度1曲线是否存在
    C5ZgyroTemp1Num=0;


    C5XAccelerometerTempertureRun=0;                //判断C5的X加速度计温度1是否存在
    C5XAccelerometerTempertureNum=0;


    C5YAccelerometerTempertureRun=0;                //判断C5的Y加速度计温度1是否存在
    C5YAccelerometerTempertureNum=0;


    C5ZAccelerometerTempertureRun=0;                //判断C5的Z加速度计温度1曲线是否存在
    C5ZAccelerometerTempertureNum=0;


    C5XgyroTemp2Run=0;                //判断C5的X陀螺温度2是否存在
    C5XgyroTemp2Num=0;


    C5YgyroTemp2Run=0;                //判断C5的Y陀螺温度2是否存在
    C5YgyroTemp2Num=0;


    C5ZgyroTemp2Run=0;                //判断C5的Z陀螺温度2曲线是否存在
    C5ZgyroTemp2Num=0;


    C5XgyroAmplitudeJitterRun=0;                //判断C5的X陀螺抖幅曲线是否存在
    C5XgyroAmplitudeJitterNum=0;

    C5YgyroAmplitudeJitterRun=0;                //判断C5的Y陀螺抖幅曲线是否存在
    C5YgyroAmplitudeJitterNum=0;


    C5ZgyroAmplitudeJitterRun=0;                //判断C5的Z陀螺抖幅曲线是否存在
    C5ZgyroAmplitudeJitterNum=0;


    C5XgyroAmpl1itudeFreRun=0;                //判断C5的X陀螺抖频曲线是否存在
    C5XgyroAmpl1itudeFreNum=0;


    C5YgyroAmpl1itudeFreRun=0;                //判断C5的Y陀螺抖频曲线是否存在
    C5YgyroAmpl1itudeFreNum=0;


    C5ZgyroAmpl1itudeFreRun=0;                //判断C5的Z陀螺抖频曲线是否存在
    C5ZgyroAmpl1itudeFreNum=0;

    C3longitudeRun=0;                //判断C3的GPS经度曲线是否存在
    C3longitudeNum=0;


    C3GPSlatitudeRun=0;                //判断C3的GPS纬度曲线是否存在
    C3GPSlatitudeNum=0;


    C3togetherSpeedRun=0;                //判断C3的GPS合速曲线是否存在
    C3togetherSpeedNum=0;


    C3headingAngleRun=0;                //判断C3的GPS航向曲线是否存在
    C3headingAngleNum=0;


    C3combinedEastSpeedRun=0;                //判断C3的GPS东速曲线是否存在
    C3combinedEastSpeedNum=0;


    C3combinedNorthSpeedRun=0;                //判断C3的GPS北速曲线是否存在
    C3combinedNorthSpeedNum=0;


    C3waterXRun=0;                //判断C3的G多普勒对水横向速度曲线是否存在
    C3waterXNum=0;


    C3waterYRun=0;                //判断C3的G多普勒对水纵向速度曲线是否存在
    C3waterYNum=0;

    C3bottomXRun=0;                //判断C3的G多普勒对底横向速度曲线是否存在
    C3bottomXNum=0;

    C3bottomYRun=0;                //判断C3的G多普勒对底纵向速度曲线是否存在
    C3bottomYNum=0;

    C3electromagnetismSpeedRun=0;                //判断C3的电磁速度曲线是否存在
    C3electromagnetismSpeedNum=0;


    C6XGroyFloatRun=0;                //判断C6的X陀螺零偏曲线是否存在
    C6XGroyFloatNum=0;


    C6YGroyFloatRun=0;                //判断C6的Y陀螺零偏曲线是否存在
    C6YGroyFloatNum=0;


    C6ZGroyFloatRun=0;                //判断C6的Z陀螺零偏曲线是否存在
    C6ZGroyFloatNum=0;


    C6XAccelerometerFloatRun=0;                //判断C6的X加速度计零偏曲线是否存在
    C6XAccelerometerFloatNum=0;


    C6YAccelerometerFloatRun=0;                //判断C6的Y加速度计零偏曲线是否存在
    C6YAccelerometerFloatNum=0;

    C6ZAccelerometerFloatRun=0;                //判断C6的Z加速度计零偏曲线是否存在
    C6ZAccelerometerFloatNum=0;


    eastSpeedErrorRun=0;                //判断东速误差曲线是否存在
    eastSpeedErrorNum=0;


    northSpeedErrorRun=0;                //判断北速误差曲线是否存在
    northSpeedErrorNum=0;

    togetherSpeedErrorRun=0;                //判断合速速误差曲线是否存在
    togetherSpeedErrorNum=0;

    latitudeErrorRun=0;                //判断纬度误差曲线是否存在
    latitudeErrorNum=0;

    longitudeErrorRun=0;                //判断经度误差曲线是否存在
    longitudeErrorNum=0;


    positionErrorRun=0;                //判断位置误差曲线是否存在
    positionErrorNum=0;


    C6UndampedRollAngleFloatRun=0;                //判断C6无阻尼横摇角曲线是否存在
    C6UndampedRollAngleFloatNum=0;

    C6UndampedPitchAngleFloatRun=0;                //判断C6的无阻尼纵摇角曲线是否存在
    C6UndampedPitchAngleFloatNum=0;

    C6UndampedHeadingAngularFloatRun=0;                //判断C6的无阻尼航向角曲线是否存在
    C6UndampedHeadingAngularFloatNum=0;

    C6UndampedNorthSpeedFloatRun=0;                //判断C6的无阻尼北速是否存在
    C6UndampedNorthSpeedFloatNum=0;

    C6UndampedEastSpeedFloatRun=0;                //判断C6的无阻尼东速曲线是否存在
    C6UndampedEastSpeedFloatNum=0;

    C6VerticalVelocityFloatRun=0;                //判断C6的无阻尼垂速曲线是否存在
    C6VerticalVelocityFloatNum=0;

    C6UndampedLatFloatRun=0;                //判断C6的无阻尼纬度曲线是否存在
    C6UndampedLatFloatNum=0;

    C6UndampedLongFloatRun=0;                //判断C6的无阻尼经度曲线是否存在
    C6UndampedLongFloatNum=0;

    C6UndampedHeightFloatRun=0;                //判断C6的无阻尼高度曲线是否存在
    C6UndampedHeightFloatNum=0;

    ui->customPlot2->clearGraphs();
    ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);
}


void MainWindow::C1getCurveData()
{
    C1Vlatitude.append(latitude);
    C1curveX.append(C1m_xLength);
    C1VheadingAngle.append(headingAngle);
    C1Vlongitude.append(longitude);
    C1VrollAngle.append(rollAngle);
    C1VpitchAngle.append(pitchAngle);
    C1VnorthSpeed.append(northSpeed);
    C1VeastSpeed.append(eastSpeed);

    C1VheadingAngularSpeed.append(headingAngularSpeed);
    C1VrollAngleSpeed.append(rollAngleSpeed);
    C1VpitchAngleSpeed.append(pitchAngleSpeed);

    C1Vheave.append(heave);
    C1VverticalVelocity.append(verticalVelocity);
    C1Vsway.append(sway);
    C1VtransverseVelocity.append(transverseVelocity);
    C1Vsurge.append(surge);
    C1VlongitudinalVelocity.append(longitudinalVelocity);

    VeastSpeedError.append(eastSpeedError);
    VnorthSpeedError.append(northSpeedError);
    VtogetherSpeedError.append(togetherSpeedError);
    VlatitudeError.append(latitudeError);
    VlongitudeError.append(longitudeError);
    VpositionError.append(positionError);

    C1m_xLength++;
}

void MainWindow::C3getCurveData()
{
    C3curveX.append(C3m_xLength);
    C3Vlongitude.append(C3longitude);
    C3VGPSlatitude.append(C3GPSlatitude);
    C3VtogetherSpeed.append(C3togetherSpeed);
    C3VheadingAngle.append(C3headingAngle);
    C3VcombinedEastSpeed.append(C3combinedEastSpeed);
    C3VcombinedNorthSpeed.append(C3combinedNorthSpeed);

    C3VwaterX.append(C3waterX);
    C3VwaterY.append(C3waterY);
    C3VbottomX.append(C3bottomX);
    C3VbottomY.append(C3bottomY);

    C3VelectromagnetismSpeed.append(C3electromagnetismSpeed);
    C3m_xLength++;
}
void MainWindow::C5getCurveData()
{
    C5curveX.append(C5m_xLength);


    C5VXGyroAngleIncreaseFloat.append(C5XGyroAngleIncreaseFloat);
    C5VYGyroAngleIncreaseFloat.append(C5YGyroAngleIncreaseFloat);
    C5VZGyroAngleIncreaseFloat.append(C5ZGyroAngleIncreaseFloat);

    C5VXAccelerometerSpeedIncrementFloat.append(C5XAccelerometerSpeedIncrementFloat);
    C5VYAccelerometerSpeedIncrementFloat.append(C5YAccelerometerSpeedIncrementFloat);
    C5VZAccelerometerSpeedIncrementFloat.append(C5ZAccelerometerSpeedIncrementFloat);

    C5VXgyroCompensatedAngleIncrementFloat.append(C5XgyroCompensatedAngleIncrementFloat);
    C5VYgyroCompensatedAngleIncrementFloat.append(C5YgyroCompensatedAngleIncrementFloat);
    C5VZgyroCompensatedAngleIncrementFloat.append(C5ZgyroCompensatedAngleIncrementFloat);

    C5VXAccVelocityIncrementFloat.append(C5XAccVelocityIncrementFloat);
    C5VYAccVelocityIncrementFloat.append(C5YAccVelocityIncrementFloat);
    C5VZAccVelocityIncrementFloat.append(C5ZAccVelocityIncrementFloat);

    C5VXgyroDifFrequency.append(C5XgyroDifFrequency);
    C5VYgyroDifFrequency.append(C5YgyroDifFrequency);
    C5VZgyroDifFrequency.append(C5ZgyroDifFrequency);

    C5VXaccelerometerDifFre.append(C5XaccelerometerDifFre);
    C5VYaccelerometerDifFre.append(C5YaccelerometerDifFre);
    C5VZaccelerometerDifFre.append(C5ZaccelerometerDifFre);


    C5VXgyroTemp1.append(C5XgyroTemp1);
    C5VYgyroTemp1.append(C5YgyroTemp1);
    C5VZgyroTemp1.append(C5ZgyroTemp1);

    C5VXAccelerometerTemperture.append(C5XAccelerometerTemperture);
    C5VYAccelerometerTemperture.append(C5YAccelerometerTemperture);
    C5VZAccelerometerTemperture.append(C5ZAccelerometerTemperture);

    C5VXgyroTemp2.append(C5XgyroTemp2);
    C5VYgyroTemp2.append(C5YgyroTemp2);
    C5VZgyroTemp2.append(C5ZgyroTemp2);

    C5VXgyroAmplitudeJitter.append(C5XgyroAmplitudeJitter);
    C5VYgyroAmplitudeJitter.append(C5YgyroAmplitudeJitter);
    C5VZgyroAmplitudeJitter.append(C5ZgyroAmplitudeJitter);

    C5VXgyroAmpl1itudeFre.append(C5XgyroAmpl1itudeFre);
    C5VYgyroAmpl1itudeFre.append(C5YgyroAmpl1itudeFre);
    C5VZgyroAmpl1itudeFre.append(C5ZgyroAmpl1itudeFre);



    C5m_xLength++;
}
void MainWindow::C6getCurveData()
{
    C6curveX.append(C6m_xLength);
    C6VC6UndampedRollAngleFloat.append(C6UndampedRollAngleFloat);
    C6VC6UndampedPitchAngleFloat.append(C6UndampedPitchAngleFloat);
    C6VC6UndampedHeadingAngularFloat.append(C6UndampedHeadingAngularFloat);
    C6VC6UndampedNorthSpeedFloat.append(C6UndampedNorthSpeedFloat);
    C6VC6UndampedEastSpeedFloat.append(C6UndampedEastSpeedFloat);
    C6VC6VerticalVelocityFloat.append(C6VerticalVelocityFloat);
    C6VC6UndampedLatFloat.append(C6UndampedLatFloat);
    C6VC6UndampedLongFloat.append(C6UndampedLongFloat);
    C6VC6UndampedHeightFloat.append(C6UndampedHeightFloat);

    C6VC6XGroyFloat.append(C6XGroyFloat);
    C6VC6YGroyFloat.append(C6YGroyFloat);
    C6VC6ZGroyFloat.append(C6ZGroyFloat);
    C6VC6XAccelerometerFloat.append(C6XAccelerometerFloat);
    C6VC6YAccelerometerFloat.append(C6YAccelerometerFloat);
    C6VC6ZAccelerometerFloat.append(C6ZAccelerometerFloat);
    C6m_xLength++;
}

void MainWindow::C8getCurveData()
{
    C8curveX.append(C8m_xLength);
    C8VC8Height.append(C8Height);
    C8VC8UpSpeed.append(C8UpSpeed);
    C8VC8GPSHeight.append(C8GPSHeight);
    C8VC8GPTUpSpeed.append(C8GPTUpSpeed);
    C8VC8LogDownSpeed2Ground.append(C8LogDownSpeed2Ground);
    C8VC8LogDownSpeed2Water.append(C8LogDownSpeed2Water);

    C8m_xLength++;
}



void MainWindow::on_pushButton_9_clicked()
{
    //弹窗确认
    QMessageBox::StandardButton rb;

    rb = QMessageBox::question(this, tr("确认"),tr("确认要发送指令吗？"),QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);

    //如果按下了不是按钮
    if (rb == QMessageBox::No)
    {
        return;
    }
    QByteArray data;
    if(ui->comboBox_6->currentText() == "使能")
    {
         data = QByteArray::fromHex("EB90150217");
    }
    else
    {
         data = QByteArray::fromHex("EB90150116");
    }

    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("装订/查询：") + ui->comboBox_6->currentText() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    bookLog(sendBookDataStr);
    doDataSendWork(data);
}


void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->stackedWidget_2->setCurrentIndex(0);
    }
    else if(index == 1)
    {
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(index == 2)
    {
        ui->stackedWidget_2->setCurrentIndex(2);
    }
    else if(index == 3)
    {
        ui->stackedWidget_2->setCurrentIndex(3);
    }
    else if(index == 4)
    {
        ui->stackedWidget_2->setCurrentIndex(4);
    }
    else if(index == 5)
    {
        ui->stackedWidget_2->setCurrentIndex(5);
    }
    else if(index == 6)
    {
        ui->stackedWidget_2->setCurrentIndex(6);
    }

    else if(index == 7)
    {
        ui->stackedWidget_2->setCurrentIndex(7);
    }

    else if(index == 8)
    {
        ui->stackedWidget_2->setCurrentIndex(8);
    }

    else if(index == 9)
    {
        ui->stackedWidget_2->setCurrentIndex(9);
    }
    else if(index == 10)
    {
        ui->stackedWidget_2->setCurrentIndex(10);
    }
    else if(index == 11)
    {
        ui->stackedWidget_2->setCurrentIndex(11);
    }
    else if(index == 12)
    {
        ui->stackedWidget_2->setCurrentIndex(12);
    }
    else if(index == 13)
    {
        ui->stackedWidget_2->setCurrentIndex(13);
    }
    else if(index == 14)
    {
        ui->stackedWidget_2->setCurrentIndex(14);
    }
    else if(index == 15)
    {
        ui->stackedWidget_2->setCurrentIndex(15);
    }
    else if(index == 16)
    {
        ui->stackedWidget_2->setCurrentIndex(16);
    }
    else if(index == 17)
    {
        ui->stackedWidget_2->setCurrentIndex(17);
    }
    else if(index == 18)
    {
        ui->stackedWidget_2->setCurrentIndex(18);
    }
    else if(index == 19)
    {
        ui->stackedWidget_2->setCurrentIndex(19);
    }
    else if(index == 20)
    {
        ui->stackedWidget_2->setCurrentIndex(20);
    }
    else if(index == 21)
    {
        ui->stackedWidget_2->setCurrentIndex(21);
    }
    ui->checkBox_91->setChecked(0);
    ui->checkBox_88->setChecked(0);
    ui->checkBox_93->setChecked(0);
    ui->checkBox_90->setChecked(0);
    ui->checkBox_89->setChecked(0);
    ui->checkBox_92->setChecked(0);

    ui->checkBox_94->setChecked(0);
    ui->checkBox_95->setChecked(0);
    ui->checkBox_96->setChecked(0);
    ui->checkBox_97->setChecked(0);
    ui->checkBox_98->setChecked(0);
    ui->checkBox_99->setChecked(0);


    ui->checkBox_100->setChecked(0);
    ui->checkBox_101->setChecked(0);
    ui->checkBox_102->setChecked(0);

    ui->checkBox_106->setChecked(0);
    ui->checkBox_108->setChecked(0);
    ui->checkBox_103->setChecked(0);
    ui->checkBox_105->setChecked(0);
    ui->checkBox_104->setChecked(0);
    ui->checkBox_107->setChecked(0);


    ui->checkBox_109->setChecked(0);
    ui->checkBox_110->setChecked(0);
    ui->checkBox_111->setChecked(0);
    ui->checkBox_112->setChecked(0);
    ui->checkBox_113->setChecked(0);
    ui->checkBox_114->setChecked(0);

    ui->checkBox_115->setChecked(0);
    ui->checkBox_116->setChecked(0);
    ui->checkBox_117->setChecked(0);

    ui->checkBox_118->setChecked(0);
    ui->checkBox_119->setChecked(0);
    ui->checkBox_120->setChecked(0);

    ui->checkBox_121->setChecked(0);
    ui->checkBox_122->setChecked(0);
    ui->checkBox_123->setChecked(0);

    ui->checkBox_124->setChecked(0);
    ui->checkBox_125->setChecked(0);
    ui->checkBox_126->setChecked(0);

    ui->checkBox_127->setChecked(0);
    ui->checkBox_128->setChecked(0);
    ui->checkBox_129->setChecked(0);

    ui->checkBox_130->setChecked(0);
    ui->checkBox_131->setChecked(0);
    ui->checkBox_132->setChecked(0);

    ui->checkBox_133->setChecked(0);
    ui->checkBox_134->setChecked(0);
    ui->checkBox_135->setChecked(0);

    ui->checkBox_136->setChecked(0);
    ui->checkBox_137->setChecked(0);
    ui->checkBox_138->setChecked(0);

    ui->checkBox_139->setChecked(0);
    ui->checkBox_140->setChecked(0);
    ui->checkBox_141->setChecked(0);

    ui->checkBox_142->setChecked(0);
    ui->checkBox_143->setChecked(0);
    ui->checkBox_144->setChecked(0);

    ui->checkBox_145->setChecked(0);
    ui->checkBox_146->setChecked(0);
    ui->checkBox_147->setChecked(0);

    ui->checkBox_148->setChecked(0);
    ui->checkBox_149->setChecked(0);
    ui->checkBox_150->setChecked(0);
    ui->checkBox_151->setChecked(0);
    ui->checkBox_152->setChecked(0);
    ui->checkBox_153->setChecked(0);
    ui->checkBox_154->setChecked(0);
    ui->checkBox_155->setChecked(0);

    ui->checkBox_156->setChecked(0);
    ui->checkBox_157->setChecked(0);
    ui->checkBox_158->setChecked(0);
    ui->checkBox_159->setChecked(0);
    ui->checkBox_160->setChecked(0);
    ui->checkBox_161->setChecked(0);
    ui->checkBox_162->setChecked(0);

    ui->checkBox_163->setChecked(0);
    ui->checkBox_164->setChecked(0);
    ui->checkBox_165->setChecked(0);

    ui->checkBox_166->setChecked(0);
    ui->checkBox_167->setChecked(0);
    ui->checkBox_168->setChecked(0);

    ui->checkBox_169->setChecked(0);
    ui->checkBox_170->setChecked(0);
    ui->checkBox_171->setChecked(0);

    ui->checkBox_172->setChecked(0);
    ui->checkBox_173->setChecked(0);
    ui->checkBox_174->setChecked(0);
    ui->customPlot3->clearGraphs();
    ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);

}


void MainWindow::drawAllHisCurve()
{
    ui->customPlot3->clearGraphs();
    QCustomPlot* customPlot = ui->customPlot3;
    customPlot->replot(QCustomPlot::rpQueuedReplot);
    int graphNum = 0;
    if(ui->checkBox_91->isChecked())
    {
        graphNum = customPlot->graphCount();
        customPlot->addGraph();
        QPen pen;
        pen.setColor(QColor(255,0,0));
        customPlot->graph(graphNum)->setPen(pen);

        customPlot->yAxis->setNumberPrecision(7);
        customPlot->graph(graphNum)->setData(valueVector1X,valueVector1);
        customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
        resetY();  //调整Y轴为最大
        customPlot->replot(QCustomPlot::rpQueuedReplot);
    }
   if(ui->checkBox_88->isChecked())
   {
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector2X,valueVector2);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_93->isChecked())
   {
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector3X,valueVector3);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_90->isChecked())
   {
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector4X,valueVector4);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_89->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,128));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector5X,valueVector5);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_92->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(147,108,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector6X,valueVector6);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   /******************************************************************************/
   if(ui->checkBox_94->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector8X,valueVector8);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_95->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector9X,valueVector9);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_96->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector7X,valueVector7);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_97->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,128));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector10X,valueVector10);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_98->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(147,108,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector11X,valueVector11);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_99->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector12X,valueVector12);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/

   if(ui->checkBox_100->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector13X,valueVector13);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_101->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector14X,valueVector14);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_102->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector15X,valueVector15);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_106->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector16X,valueVector16);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_103->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector17X,valueVector17);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);

   }
   if(ui->checkBox_108->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,0,25));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector18X,valueVector18);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_105->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector19X,valueVector19);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_104->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,128));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector20X,valueVector20);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_107->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(147,108,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector21X,valueVector21);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/

   if(ui->checkBox_113->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(147,108,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector22X,valueVector22);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_111->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector23X,valueVector23);
       customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_112->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,128));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector24X,valueVector24);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_110->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector25X,valueVector25);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_109->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector26X,valueVector26);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_114->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector27X,valueVector27);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_117->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector28X,valueVector28);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_116->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector29X,valueVector29);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_115->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector30X,valueVector30);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_120->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector31X,valueVector31);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_118->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector32X,valueVector32);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_119->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector33X,valueVector33);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_123->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector34X,valueVector34);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_122->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector35X,valueVector35);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_121->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector36X,valueVector36);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_124->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector37X,valueVector37);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_125->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector38X,valueVector38);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_126->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector39X,valueVector39);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_127->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector40X,valueVector40);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_128->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector41X,valueVector41);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_129->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector42X,valueVector42);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_130->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector43X,valueVector43);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_131->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector44X,valueVector44);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_132->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector45X,valueVector45);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_133->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector46X,valueVector46);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_134->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector47X,valueVector47);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_135->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector48X,valueVector48);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_137->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector49X,valueVector49);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_138->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector50X,valueVector50);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_136->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector51X,valueVector51);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_141->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector52X,valueVector52);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_140->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector53X,valueVector53);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_139->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector54X,valueVector54);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_143->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector55X,valueVector55);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_144->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector56X,valueVector56);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_142->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector57X,valueVector57);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_145->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector58X,valueVector58);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_146->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector59X,valueVector59);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_147->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector60X,valueVector60);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_151->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,128));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector61X,valueVector61);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_152->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(147,108,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector62X,valueVector62);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_153->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector63X,valueVector63);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_149->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector64X,valueVector64);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_150->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector65X,valueVector65);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_148->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector66X,valueVector66);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_154->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,71,75));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector67X,valueVector67);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_155->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,200,244));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector68X,valueVector68);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_157->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector69X,valueVector69);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_158->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector70X,valueVector70);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_159->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,128));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector75X,valueVector75);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_156->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector71X,valueVector71);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_161->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector72X,valueVector72);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_162->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,71,75));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector74X,valueVector74);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_160->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(147,108,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector73X,valueVector73);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_163->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector76X,valueVector76);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_164->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector77X,valueVector77);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_165->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector78X,valueVector78);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_166->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector79X,valueVector79);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_167->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector80X,valueVector80);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_168->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector81X,valueVector81);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_169->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector82X,valueVector82);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_170->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector83X,valueVector83);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_171->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector84X,valueVector84);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
/******************************************************************************/
   if(ui->checkBox_172->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(255,0,0));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector85X,valueVector85);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_173->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(128,0,255));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector86X,valueVector86);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
   if(ui->checkBox_174->isChecked()){
       graphNum = customPlot->graphCount();
       customPlot->addGraph();
       QPen pen;
       pen.setColor(QColor(0,143,122));
       customPlot->graph(graphNum)->setPen(pen);

       customPlot->yAxis->setNumberPrecision(7);
       customPlot->graph(graphNum)->setData(valueVector87X,valueVector87);
       customPlot->graph(graphNum)->rescaleAxes();
       resetY();  //调整Y轴为最大
       customPlot->replot(QCustomPlot::rpQueuedReplot);
   }
}

void MainWindow::setY88_89_90_91_92_93()
{
        double biggest = -999999999;
        double smallest = 999999999;

        if(ui->checkBox_91->isChecked())
        {
            auto C1Vheave_max = std::max_element(std::begin(valueVector1), std::end(valueVector1));
            auto C1Vheave_min = std::min_element(std::begin(valueVector1), std::end(valueVector1));

            if(*C1Vheave_max >= biggest)
                biggest = *C1Vheave_max;
            if(*C1Vheave_min <= smallest)
                smallest = *C1Vheave_min;
        }
        if(ui->checkBox_88->isChecked())
        {
            auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector2), std::end(valueVector2));
            auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector2), std::end(valueVector2));

            if(*C1VverticalVelocity_max >= biggest)
                biggest = *C1VverticalVelocity_max;
            if(*C1VverticalVelocity_min <= smallest)
                smallest = *C1VverticalVelocity_min;
        }
        if(ui->checkBox_93->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector3), std::end(valueVector3));
            auto C1Vsway_min = std::min_element(std::begin(valueVector3), std::end(valueVector3));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }

        if(ui->checkBox_90->isChecked())
        {
            auto C1VtransverseVelocity_max = std::max_element(std::begin(valueVector4), std::end(valueVector4));
            auto C1VtransverseVelocity_min = std::min_element(std::begin(valueVector4), std::end(valueVector4));

            if(*C1VtransverseVelocity_max >= biggest)
                biggest = *C1VtransverseVelocity_max;
            if(*C1VtransverseVelocity_min <= smallest)
                smallest = *C1VtransverseVelocity_min;
        }
        if(ui->checkBox_89->isChecked())
        {
            auto C1Vsurge_max = std::max_element(std::begin(valueVector5), std::end(valueVector5));
            auto C1Vsurge_min = std::min_element(std::begin(valueVector5), std::end(valueVector5));

            if(*C1Vsurge_max >= biggest)
                biggest = *C1Vsurge_max;
            if(*C1Vsurge_min <= smallest)
                smallest = *C1Vsurge_min;
        }
        if(ui->checkBox_92->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector6), std::end(valueVector6));
            auto C1Vsway_min = std::min_element(std::begin(valueVector6), std::end(valueVector6));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }

        ui->customPlot3->xAxis->setRange(0, X.size(), Qt::AlignLeft);
        //判断最大值和最小值是否相等
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot3->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot3->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot3->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }

        ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);
}
void MainWindow::setY94_95_96_97_98_99()
{
        double biggest = -999999999;
        double smallest = 999999999;

        if(ui->checkBox_94->isChecked())
        {
            auto C1Vheave_max = std::max_element(std::begin(valueVector8), std::end(valueVector8));
            auto C1Vheave_min = std::min_element(std::begin(valueVector8), std::end(valueVector8));

            if(*C1Vheave_max >= biggest)
                biggest = *C1Vheave_max;
            if(*C1Vheave_min <= smallest)
                smallest = *C1Vheave_min;
        }
        if(ui->checkBox_95->isChecked())
        {
            auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector9), std::end(valueVector9));
            auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector9), std::end(valueVector9));

            if(*C1VverticalVelocity_max >= biggest)
                biggest = *C1VverticalVelocity_max;
            if(*C1VverticalVelocity_min <= smallest)
                smallest = *C1VverticalVelocity_min;
        }
        if(ui->checkBox_96->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector7), std::end(valueVector7));
            auto C1Vsway_min = std::min_element(std::begin(valueVector7), std::end(valueVector7));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }

        if(ui->checkBox_97->isChecked())
        {
            auto C1VtransverseVelocity_max = std::max_element(std::begin(valueVector10), std::end(valueVector10));
            auto C1VtransverseVelocity_min = std::min_element(std::begin(valueVector10), std::end(valueVector10));

            if(*C1VtransverseVelocity_max >= biggest)
                biggest = *C1VtransverseVelocity_max;
            if(*C1VtransverseVelocity_min <= smallest)
                smallest = *C1VtransverseVelocity_min;
        }
        if(ui->checkBox_98->isChecked())
        {
            auto C1Vsurge_max = std::max_element(std::begin(valueVector11), std::end(valueVector11));
            auto C1Vsurge_min = std::min_element(std::begin(valueVector11), std::end(valueVector11));

            if(*C1Vsurge_max >= biggest)
                biggest = *C1Vsurge_max;
            if(*C1Vsurge_min <= smallest)
                smallest = *C1Vsurge_min;
        }
        if(ui->checkBox_99->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector12), std::end(valueVector12));
            auto C1Vsway_min = std::min_element(std::begin(valueVector12), std::end(valueVector12));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }

        ui->customPlot3->xAxis->setRange(0, X.size(), Qt::AlignLeft);
        //判断最大值和最小值是否相等
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot3->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot3->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot3->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }

        ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);
}
void MainWindow::setY100_101_102()
{
        double biggest = -999999999;
        double smallest = 999999999;

        if(ui->checkBox_100->isChecked())
        {
            auto C1Vheave_max = std::max_element(std::begin(valueVector13), std::end(valueVector13));
            auto C1Vheave_min = std::min_element(std::begin(valueVector13), std::end(valueVector13));

            if(*C1Vheave_max >= biggest)
                biggest = *C1Vheave_max;
            if(*C1Vheave_min <= smallest)
                smallest = *C1Vheave_min;
        }
        if(ui->checkBox_101->isChecked())
        {
            auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector14), std::end(valueVector14));
            auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector14), std::end(valueVector14));

            if(*C1VverticalVelocity_max >= biggest)
                biggest = *C1VverticalVelocity_max;
            if(*C1VverticalVelocity_min <= smallest)
                smallest = *C1VverticalVelocity_min;
        }
        if(ui->checkBox_102->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector15), std::end(valueVector15));
            auto C1Vsway_min = std::min_element(std::begin(valueVector15), std::end(valueVector15));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }

        ui->customPlot3->xAxis->setRange(0, X.size(), Qt::AlignLeft);
        //判断最大值和最小值是否相等
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot3->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot3->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot3->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }

        ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);
}
void MainWindow::setY106_103_108_105_104_107()
{
        double biggest = -999999999;
        double smallest = 999999999;

        if(ui->checkBox_106->isChecked())
        {
            auto C1Vheave_max = std::max_element(std::begin(valueVector16), std::end(valueVector16));
            auto C1Vheave_min = std::min_element(std::begin(valueVector16), std::end(valueVector16));

            if(*C1Vheave_max >= biggest)
                biggest = *C1Vheave_max;
            if(*C1Vheave_min <= smallest)
                smallest = *C1Vheave_min;
        }
        if(ui->checkBox_103->isChecked())
        {
            auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector17), std::end(valueVector17));
            auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector17), std::end(valueVector17));

            if(*C1VverticalVelocity_max >= biggest)
                biggest = *C1VverticalVelocity_max;
            if(*C1VverticalVelocity_min <= smallest)
                smallest = *C1VverticalVelocity_min;
        }
        if(ui->checkBox_108->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector18), std::end(valueVector18));
            auto C1Vsway_min = std::min_element(std::begin(valueVector18), std::end(valueVector18));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }
        if(ui->checkBox_105->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector19), std::end(valueVector19));
            auto C1Vsway_min = std::min_element(std::begin(valueVector19), std::end(valueVector19));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }
        if(ui->checkBox_104->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector20), std::end(valueVector20));
            auto C1Vsway_min = std::min_element(std::begin(valueVector20), std::end(valueVector20));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }
        if(ui->checkBox_107->isChecked())
        {
            auto C1Vsway_max = std::max_element(std::begin(valueVector21), std::end(valueVector21));
            auto C1Vsway_min = std::min_element(std::begin(valueVector21), std::end(valueVector21));

            if(*C1Vsway_max >= biggest)
                biggest = *C1Vsway_max;
            if(*C1Vsway_min <= smallest)
                smallest = *C1Vsway_min;
        }

        ui->customPlot3->xAxis->setRange(0, X.size(), Qt::AlignLeft);
        //判断最大值和最小值是否相等
        if(biggest == smallest)
        {
            if(biggest != 0)
                ui->customPlot3->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
            else
                ui->customPlot3->yAxis->setRange(-5, 10, Qt::AlignLeft);
        }
        else
        {
            ui->customPlot3->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
        }

        ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::resetY()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_91->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector1), std::end(valueVector1));
        auto C1Vheave_min = std::min_element(std::begin(valueVector1), std::end(valueVector1));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_88->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector2), std::end(valueVector2));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector2), std::end(valueVector2));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_93->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector3), std::end(valueVector3));
        auto C1Vsway_min = std::min_element(std::begin(valueVector3), std::end(valueVector3));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_90->isChecked())
    {
        auto C1VtransverseVelocity_max = std::max_element(std::begin(valueVector4), std::end(valueVector4));
        auto C1VtransverseVelocity_min = std::min_element(std::begin(valueVector4), std::end(valueVector4));

        if(*C1VtransverseVelocity_max >= biggest)
            biggest = *C1VtransverseVelocity_max;
        if(*C1VtransverseVelocity_min <= smallest)
            smallest = *C1VtransverseVelocity_min;
    }
    if(ui->checkBox_89->isChecked())
    {
        auto C1Vsurge_max = std::max_element(std::begin(valueVector5), std::end(valueVector5));
        auto C1Vsurge_min = std::min_element(std::begin(valueVector5), std::end(valueVector5));

        if(*C1Vsurge_max >= biggest)
            biggest = *C1Vsurge_max;
        if(*C1Vsurge_min <= smallest)
            smallest = *C1Vsurge_min;
    }
    if(ui->checkBox_92->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector6), std::end(valueVector6));
        auto C1Vsway_min = std::min_element(std::begin(valueVector6), std::end(valueVector6));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }


    if(ui->checkBox_94->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector8), std::end(valueVector8));
        auto C1Vheave_min = std::min_element(std::begin(valueVector8), std::end(valueVector8));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_95->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector9), std::end(valueVector9));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector9), std::end(valueVector9));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_96->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector7), std::end(valueVector7));
        auto C1Vsway_min = std::min_element(std::begin(valueVector7), std::end(valueVector7));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_97->isChecked())
    {
        auto C1VtransverseVelocity_max = std::max_element(std::begin(valueVector10), std::end(valueVector10));
        auto C1VtransverseVelocity_min = std::min_element(std::begin(valueVector10), std::end(valueVector10));

        if(*C1VtransverseVelocity_max >= biggest)
            biggest = *C1VtransverseVelocity_max;
        if(*C1VtransverseVelocity_min <= smallest)
            smallest = *C1VtransverseVelocity_min;
    }
    if(ui->checkBox_98->isChecked())
    {
        auto C1Vsurge_max = std::max_element(std::begin(valueVector11), std::end(valueVector11));
        auto C1Vsurge_min = std::min_element(std::begin(valueVector11), std::end(valueVector11));

        if(*C1Vsurge_max >= biggest)
            biggest = *C1Vsurge_max;
        if(*C1Vsurge_min <= smallest)
            smallest = *C1Vsurge_min;
    }
    if(ui->checkBox_99->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector12), std::end(valueVector12));
        auto C1Vsway_min = std::min_element(std::begin(valueVector12), std::end(valueVector12));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_100->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector13), std::end(valueVector13));
        auto C1Vheave_min = std::min_element(std::begin(valueVector13), std::end(valueVector13));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_101->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector14), std::end(valueVector14));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector14), std::end(valueVector14));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_102->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector15), std::end(valueVector15));
        auto C1Vsway_min = std::min_element(std::begin(valueVector15), std::end(valueVector15));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_106->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector16), std::end(valueVector16));
        auto C1Vheave_min = std::min_element(std::begin(valueVector16), std::end(valueVector16));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_103->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector17), std::end(valueVector17));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector17), std::end(valueVector17));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_108->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector18), std::end(valueVector18));
        auto C1Vsway_min = std::min_element(std::begin(valueVector18), std::end(valueVector18));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_105->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector19), std::end(valueVector19));
        auto C1Vsway_min = std::min_element(std::begin(valueVector19), std::end(valueVector19));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_104->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector20), std::end(valueVector20));
        auto C1Vsway_min = std::min_element(std::begin(valueVector20), std::end(valueVector20));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_107->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector21), std::end(valueVector21));
        auto C1Vsway_min = std::min_element(std::begin(valueVector21), std::end(valueVector21));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_113->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector22), std::end(valueVector22));
        auto C1Vheave_min = std::min_element(std::begin(valueVector22), std::end(valueVector22));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_111->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector23), std::end(valueVector23));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector23), std::end(valueVector23));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_112->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector24), std::end(valueVector24));
        auto C1Vsway_min = std::min_element(std::begin(valueVector24), std::end(valueVector24));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_110->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector25), std::end(valueVector25));
        auto C1Vsway_min = std::min_element(std::begin(valueVector25), std::end(valueVector25));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_109->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector26), std::end(valueVector26));
        auto C1Vsway_min = std::min_element(std::begin(valueVector26), std::end(valueVector26));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_114->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector27), std::end(valueVector27));
        auto C1Vsway_min = std::min_element(std::begin(valueVector27), std::end(valueVector27));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_117->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector28), std::end(valueVector28));
        auto C1Vheave_min = std::min_element(std::begin(valueVector28), std::end(valueVector28));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_116->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector29), std::end(valueVector29));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector29), std::end(valueVector29));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_115->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector30), std::end(valueVector30));
        auto C1Vsway_min = std::min_element(std::begin(valueVector30), std::end(valueVector30));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_120->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector31), std::end(valueVector31));
        auto C1Vheave_min = std::min_element(std::begin(valueVector31), std::end(valueVector31));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_118->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector32), std::end(valueVector32));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector32), std::end(valueVector32));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_119->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector33), std::end(valueVector33));
        auto C1Vsway_min = std::min_element(std::begin(valueVector33), std::end(valueVector33));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }


    if(ui->checkBox_123->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector34), std::end(valueVector34));
        auto C1Vheave_min = std::min_element(std::begin(valueVector34), std::end(valueVector34));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_122->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector35), std::end(valueVector35));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector35), std::end(valueVector35));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_121->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector36), std::end(valueVector36));
        auto C1Vsway_min = std::min_element(std::begin(valueVector36), std::end(valueVector36));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_124->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector37), std::end(valueVector37));
        auto C1Vheave_min = std::min_element(std::begin(valueVector37), std::end(valueVector37));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_125->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector38), std::end(valueVector38));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector38), std::end(valueVector38));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_126->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector39), std::end(valueVector39));
        auto C1Vsway_min = std::min_element(std::begin(valueVector39), std::end(valueVector39));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_127->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector40), std::end(valueVector40));
        auto C1Vheave_min = std::min_element(std::begin(valueVector40), std::end(valueVector40));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_128->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector41), std::end(valueVector41));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector41), std::end(valueVector41));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_129->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector42), std::end(valueVector42));
        auto C1Vsway_min = std::min_element(std::begin(valueVector42), std::end(valueVector42));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_130->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector43), std::end(valueVector43));
        auto C1Vheave_min = std::min_element(std::begin(valueVector43), std::end(valueVector43));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_131->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector44), std::end(valueVector44));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector44), std::end(valueVector44));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_132->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector45), std::end(valueVector45));
        auto C1Vsway_min = std::min_element(std::begin(valueVector45), std::end(valueVector45));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_133->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector46), std::end(valueVector46));
        auto C1Vheave_min = std::min_element(std::begin(valueVector46), std::end(valueVector46));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_134->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector47), std::end(valueVector47));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector47), std::end(valueVector47));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_135->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector48), std::end(valueVector48));
        auto C1Vsway_min = std::min_element(std::begin(valueVector48), std::end(valueVector48));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_137->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector49), std::end(valueVector49));
        auto C1Vheave_min = std::min_element(std::begin(valueVector49), std::end(valueVector49));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_138->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector50), std::end(valueVector50));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector50), std::end(valueVector50));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_136->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector51), std::end(valueVector51));
        auto C1Vsway_min = std::min_element(std::begin(valueVector51), std::end(valueVector51));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_141->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector52), std::end(valueVector52));
        auto C1Vheave_min = std::min_element(std::begin(valueVector52), std::end(valueVector52));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_140->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector53), std::end(valueVector53));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector53), std::end(valueVector53));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_139->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector54), std::end(valueVector54));
        auto C1Vsway_min = std::min_element(std::begin(valueVector54), std::end(valueVector54));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_143->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector55), std::end(valueVector55));
        auto C1Vheave_min = std::min_element(std::begin(valueVector55), std::end(valueVector55));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_144->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector56), std::end(valueVector56));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector56), std::end(valueVector56));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_142->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector57), std::end(valueVector57));
        auto C1Vsway_min = std::min_element(std::begin(valueVector57), std::end(valueVector57));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_145->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector58), std::end(valueVector58));
        auto C1Vheave_min = std::min_element(std::begin(valueVector58), std::end(valueVector58));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_146->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector59), std::end(valueVector59));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector59), std::end(valueVector59));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_147->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector60), std::end(valueVector60));
        auto C1Vsway_min = std::min_element(std::begin(valueVector60), std::end(valueVector60));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_151->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector61), std::end(valueVector61));
        auto C1Vheave_min = std::min_element(std::begin(valueVector61), std::end(valueVector61));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_152->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector62), std::end(valueVector62));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector62), std::end(valueVector62));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_153->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector63), std::end(valueVector63));
        auto C1Vsway_min = std::min_element(std::begin(valueVector63), std::end(valueVector63));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_149->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(valueVector64), std::end(valueVector64));
        auto C1Vheave_min = std::min_element(std::begin(valueVector64), std::end(valueVector64));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_150->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector65), std::end(valueVector65));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector65), std::end(valueVector65));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_148->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector66), std::end(valueVector66));
        auto C1Vsway_min = std::min_element(std::begin(valueVector66), std::end(valueVector66));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_154->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector67), std::end(valueVector67));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector67), std::end(valueVector67));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_155->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector68), std::end(valueVector68));
        auto C1Vsway_min = std::min_element(std::begin(valueVector68), std::end(valueVector68));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }


    if(ui->checkBox_157->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector69), std::end(valueVector69));
        auto C1Vsway_min = std::min_element(std::begin(valueVector69), std::end(valueVector69));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_158->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector70), std::end(valueVector70));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector70), std::end(valueVector70));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_159->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector75), std::end(valueVector75));
        auto C1Vsway_min = std::min_element(std::begin(valueVector75), std::end(valueVector75));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    } if(ui->checkBox_156->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector71), std::end(valueVector71));
        auto C1Vsway_min = std::min_element(std::begin(valueVector71), std::end(valueVector71));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_161->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector72), std::end(valueVector72));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector72), std::end(valueVector72));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_162->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector74), std::end(valueVector74));
        auto C1Vsway_min = std::min_element(std::begin(valueVector74), std::end(valueVector74));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_160->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector73), std::end(valueVector73));
        auto C1Vsway_min = std::min_element(std::begin(valueVector73), std::end(valueVector73));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_163->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector76), std::end(valueVector76));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector76), std::end(valueVector76));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_164->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector77), std::end(valueVector77));
        auto C1Vsway_min = std::min_element(std::begin(valueVector77), std::end(valueVector77));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_165->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector78), std::end(valueVector78));
        auto C1Vsway_min = std::min_element(std::begin(valueVector78), std::end(valueVector78));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_166->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector79), std::end(valueVector79));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector79), std::end(valueVector79));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_167->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector80), std::end(valueVector80));
        auto C1Vsway_min = std::min_element(std::begin(valueVector80), std::end(valueVector80));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_168->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector81), std::end(valueVector81));
        auto C1Vsway_min = std::min_element(std::begin(valueVector81), std::end(valueVector81));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_169->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector82), std::end(valueVector82));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector82), std::end(valueVector82));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_170->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector83), std::end(valueVector83));
        auto C1Vsway_min = std::min_element(std::begin(valueVector83), std::end(valueVector83));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_171->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector84), std::end(valueVector84));
        auto C1Vsway_min = std::min_element(std::begin(valueVector84), std::end(valueVector84));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_172->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(valueVector85), std::end(valueVector85));
        auto C1VverticalVelocity_min = std::min_element(std::begin(valueVector85), std::end(valueVector85));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_173->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector86), std::end(valueVector86));
        auto C1Vsway_min = std::min_element(std::begin(valueVector86), std::end(valueVector86));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    if(ui->checkBox_174->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(valueVector87), std::end(valueVector87));
        auto C1Vsway_min = std::min_element(std::begin(valueVector87), std::end(valueVector87));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    ui->customPlot3->xAxis->setRange(0,graphPointNum, Qt::AlignLeft);
    //判断最大值和最小值是否相等
    if(biggest == smallest)
    {
        if(biggest != 0)
            ui->customPlot3->yAxis->setRange(biggest-0.5*biggest, biggest, Qt::AlignLeft);
        else
            ui->customPlot3->yAxis->setRange(-5, 10, Qt::AlignLeft);
    }
    else
    {
        ui->customPlot3->yAxis->setRange(smallest, biggest-smallest, Qt::AlignLeft);
    }
    ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);

}
void MainWindow::on_checkBox_91_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_91->setChecked(0);
        return;
    }

    drawAllHisCurve();

}


void MainWindow::on_checkBox_88_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_88->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_93_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_93->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_90_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_90->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_89_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_89->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_92_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_92->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_94_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_94->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_95_toggled(bool checked)
{
    if(graphPointNum==0 && checked == 1)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_95->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_96_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_96->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_97_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_97->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_98_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_98->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_99_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_99->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_100_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_100->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_101_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_101->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_102_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_102->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_106_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_106->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_103_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_103->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_108_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_108->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_105_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_105->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_104_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_104->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_107_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_107->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_113_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_113->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_111_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_111->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_112_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_112->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_110_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_110->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_109_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_109->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_114_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_114->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_117_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_117->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_116_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_116->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_115_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_115->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_120_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_120->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_118_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_118->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_119_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_119->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_123_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_123->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_122_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_122->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_121_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_121->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_124_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_124->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_125_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_125->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_126_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_126->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_127_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_127->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_128_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_128->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_129_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_129->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_130_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_130->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_131_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_131->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_132_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_132->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_133_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_133->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_134_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_134->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_135_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_135->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_137_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_137->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_138_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_138->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_136_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_136->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_141_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_141->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_140_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_140->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_139_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_139->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_143_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_143->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_144_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_144->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_142_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_142->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_145_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_145->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_146_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_146->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_147_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_147->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_151_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_151->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_152_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_152->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_153_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_153->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_149_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_149->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_150_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_150->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_148_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_148->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_154_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_154->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_155_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_155->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_157_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_157->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_158_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_158->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_159_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_159->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_156_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_156->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_161_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_161->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_162_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_162->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_160_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_160->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_163_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_163->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_164_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_164->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_165_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_165->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_166_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_166->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_167_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_167->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_168_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_168->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_169_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_169->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_170_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_170->setChecked(0);
        return;
    }
    drawAllHisCurve();
}

void MainWindow::on_checkBox_171_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_171->setChecked(0);
        return;
    }
    drawAllHisCurve();
}


void MainWindow::on_checkBox_172_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_172->setChecked(0);
        return;
    }
    drawAllHisCurve();

}

void MainWindow::on_checkBox_173_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_173->setChecked(0);
        return;
    }
    drawAllHisCurve();

}

void MainWindow::on_checkBox_174_toggled(bool checked)
{
    if(graphPointNum==0 && checked == true)    {
        QMessageBox::information(NULL, "提示", "无历史曲线数据！");
        ui->checkBox_174->setChecked(0);
        return;
    }
    drawAllHisCurve();

}


void MainWindow::on_pushButton_111_clicked()
{
    resetY();
}
