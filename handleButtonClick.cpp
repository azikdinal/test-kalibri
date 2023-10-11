#include "mainwindow.h"

void MainWindow::handleButtonClick() {
    QString directoryPath = inputFilePath->text();

    QDir dir(directoryPath);


    // Проверяем правилен ли указанный путь
    if (dir.exists()) {
        dir.setFilter(QDir::Files);

        // Берем все файлы в заданной директории
        QFileInfoList fileList = dir.entryInfoList();

        QString filename;
        QString extension = fileExtension->currentText();
        // Если есть файл с данным расширением попытаться открыть его
        for (const QFileInfo &fileInfo : fileList) {
            filename = fileInfo.fileName();
            if(extension == filename.right(4)) {
                readFile(fileInfo.absoluteFilePath());
            }
        }
    } else {
        return;
    }

    QMessageBox::information(this, "Message", directoryPath);
}
