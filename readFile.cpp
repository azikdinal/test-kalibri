#include "mainwindow.h"


void MainWindow::readFile(QString filepath) {
    QString outputFilePath = "C:/Users/HomePC/Desktop/QT PROJECTS/untitled/test/newFile.txt";

//    // Проверка на схожеcть названий входного и выходного файлов
//    bool isFilesSameName = filepath == outputFilePath;

//    if(isFilesSameName) {
//        if(repeationFileNameBtnG->checkedId() == -3) {
//            if(outputFilePath.mid(0, outputFilePath.length() - 4))
//            outputFilePath = outputFilePath.mid(0, outputFilePath.length() - 4) + " (1)" + outputFilePath.right(4);
//        } else {
//            outputFilePath = filepath;
//        }
//    }

    QFile file(filepath);
    QFile outputFile(outputFilePath);

    if(!file.open(QIODevice::ReadOnly) || !outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open";
        return;
    }

    QTextStream in(&file);
    QTextStream out(&outputFile);


    while (!in.atEnd()){
        QString line = in.readLine();
        QString newLine;

        for(int i = 0; i < line.length(); i++) {
            int num = line[i].unicode() ^ 0x5a; // Модификация текста XOR
            QChar newChar(num);
            newLine.append(newChar);
        }
        // Запись измененного текста в файл
        out << newLine;
    }

    file.close();
    outputFile.close();

     // Удаление файла
    //-------------------------------------
    bool deleteInputFile = deleteInputFileBtnG->checkedId() == -2;

    if(deleteInputFile) {
        QFile::remove(filepath);
    }
    //-------------------------------------
}
