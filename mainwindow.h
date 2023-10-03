 #ifndef MAINWINDOW_H
 #define MAINWINDOW_H

 #include <iostream>
 #include <QWidget>
 #include <QPushButton>
#include <QButtonGroup>
 #include <QMessageBox>
 #include <QIcon>
 #include <QComboBox>
 #include <QVBoxLayout>
 #include <QRadioButton>
 #include <QLabel>
 #include <QLineEdit>
 #include <QFile>
 #include <QString>
 #include <string>
 #include <QDir>
#include <QDebug>
#include <QPainter>
#include <QValidator>
#include <QRegularExpressionValidator>

 class MainWindow : public QWidget {
     Q_OBJECT

 public:
     MainWindow(QWidget *parent = nullptr);

 private slots:
     void handleButtonClick();
     void readFile(QString filename);

 private:
     QPushButton *button;
     QComboBox *fileExtension;
     QComboBox *timer;
     QLabel *label;

     QButtonGroup *deleteInputFileBtnG;
     QRadioButton *yesRadioButton;
     QRadioButton *noRadioButton;

     QButtonGroup *repeationFileNameBtnG;
     QRadioButton *rewriteRadioButton;
     QRadioButton *modifyRadioButton;

     QButtonGroup *programWorkOrderBtnG;
     QRadioButton *workByTimerRadioButton;
     QRadioButton *oneTimeStartRadioButton;

     QLineEdit *inputFilePath;
     QComboBox *inputFilePathDrop;
     QLineEdit *outputFilePath;
     QLineEdit *eightBitInput;
     QVBoxLayout *layout;
     QRegularExpressionValidator *validator;
 };

 #endif // MAINWINDOW_H
