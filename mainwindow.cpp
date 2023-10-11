 #include "mainwindow.h"

 MainWindow::MainWindow(QWidget *parent)
     : QWidget(parent) {
     setWindowTitle("Форматор файлов");

     // Схема окна
     layout = new QVBoxLayout(this);
     QIcon icon("C:/Users/HomePC/Desktop/QT PROJECTS/untitled/images.png");
     setWindowIcon(icon);

     // Текст "Каталог"
     label = new QLabel("Каталог", this);
     layout->addWidget(label);

     // Ввод пути папки входного файла
     //---------------------------------
     inputFilePath = new QLineEdit(this);
     inputFilePath->setPlaceholderText("Введите путь к папке...");
     layout->addWidget(inputFilePath);
     //---------------------------------

     // Селектор маски входного файла
     //---------------------------------
     label = new QLabel("Расширение файла", this);
     layout->addWidget(label);

     fileExtension = new QComboBox(this);
     fileExtension->addItem(".txt");
     fileExtension->addItem(".bin");
     fileExtension->addItem(".exe");
     layout->addWidget(fileExtension);
     //---------------------------------

     // Удаление входного файла после чтения
     //----------------------------------
     label = new QLabel("Удалять входные файлы?", this);
     layout->addWidget(label);

     deleteInputFileBtnG = new QButtonGroup(this);
     yesRadioButton = new QRadioButton("Да", this);
     noRadioButton = new QRadioButton("Нет", this);
     deleteInputFileBtnG->addButton(yesRadioButton);
     deleteInputFileBtnG->addButton(noRadioButton);

     noRadioButton->setChecked(true);

     layout->addWidget(yesRadioButton);
     layout->addWidget(noRadioButton);
     //---------------------------------

     // Конечный путь
     //--------------------------------------
     label = new QLabel("Сохрнить в:", this);
     layout->addWidget(label);

     outputFilePath = new QLineEdit(this);
     outputFilePath->setPlaceholderText("Введите путь к папке...");
     layout->addWidget(outputFilePath);
     //--------------------------------------

     // Радио-кнопки повторение имени входного файла
     //--------------------------------------------
     label = new QLabel("Действия при повторении имени выходного файла?", this);
     layout->addWidget(label);

     repeationFileNameBtnG = new QButtonGroup(this);
     rewriteRadioButton = new QRadioButton("Перезапись", this);
     modifyRadioButton = new QRadioButton("Модификация (добавить счетчик к имени)", this);

     repeationFileNameBtnG->addButton(rewriteRadioButton);
     repeationFileNameBtnG->addButton(modifyRadioButton);

     rewriteRadioButton->setChecked(true);

     layout->addWidget(rewriteRadioButton);
     layout->addWidget(modifyRadioButton);
     //--------------------------------------------

     // Вопрос для удаления входного файла
     label = new QLabel("Какой порядок работы программы?", this);
     layout->addWidget(label);

     // Радио-кнопки повторение имени входного файла
     programWorkOrderBtnG = new QButtonGroup(this);
     oneTimeStartRadioButton = new QRadioButton("Разовый запуск", this);
     workByTimerRadioButton = new QRadioButton("Работа по таймеру", this);

     workByTimerRadioButton->setChecked(true);
     programWorkOrderBtnG->addButton(workByTimerRadioButton);
     programWorkOrderBtnG->addButton(oneTimeStartRadioButton);

     layout->addWidget(workByTimerRadioButton);
     layout->addWidget(oneTimeStartRadioButton);

     // Вопрос для удаления входного файла
     label = new QLabel("Какова периодичность таймера?", this);
     layout->addWidget(label);

     // Селектор времени таймера
     //---------------------------------
     timer = new QComboBox(this);
     timer->addItem("1 сек.");
     timer->addItem("2 сек.");
     timer->addItem("5 сек.");
     layout->addWidget(timer);

     label = new QLabel("Свое значение (сек.", this);
     layout->addWidget(label);

     // Свое значение
     outputFilePath = new QLineEdit(this);
     layout->addWidget(outputFilePath);
     //---------------------------------

     // 8-бит значение
     //---------------------------------
     label = new QLabel("8-бит значение (0-F)", this);
     layout->addWidget(label);


     eightBitInput = new QLineEdit(this);
     eightBitInput->setPlaceholderText("Введите значение...");

     validator = new QRegularExpressionValidator(QRegularExpression("[0-9, A-F, a-f]*"), eightBitInput);
     eightBitInput->setValidator(validator);

     eightBitInput->setMaxLength(8);

     layout->addWidget(eightBitInput);
     //---------------------------------

     // Кнопка
     //---------------------------------
     button = new QPushButton("Преобразовать", this);
     layout->addWidget(button);

     connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
     //---------------------------------

     // Размер окна
     resize(300, 200);
     move(200, 100);
     setLayout(layout);
 }

