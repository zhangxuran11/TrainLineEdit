#include "soft_keyboard.h"
#include<QVariant>
void Soft_Keyboard::show()
{
    currentEditWidget = sender();
    QDialog::show();
}
void Soft_Keyboard::show(const QModelIndex& _modelIndex)
{
    QTableWidget* tableWidget;
    QListWidget* listWidget;
    currentEditWidget = sender();
    modelIndex = _modelIndex;
    QDialog::show();
    tableWidget = dynamic_cast<QTableWidget*>(currentEditWidget);
    if(tableWidget != NULL)
    {
        QTableWidgetItem* item = tableWidget->item(modelIndex.row(),modelIndex.column());
        if(item == NULL)
        {
            item = new QTableWidgetItem("");
            tableWidget->setItem(modelIndex.row(),modelIndex.column(),item);
        }
    }
    listWidget = dynamic_cast<QListWidget*>(currentEditWidget);
    if(listWidget != NULL)
    {
        QListWidgetItem* item = listWidget->item(modelIndex.row());
        if(item == NULL)
        {
            item = new QListWidgetItem("");
            listWidget->insertItem(modelIndex.row(),item);
        }
    }

}

Soft_Keyboard::Soft_Keyboard(QWidget *parent) : QDialog(parent)
{

    currentEditWidget = NULL;
    this->resize(550, 500);
    this->setMaximumSize(550,500);
    this->setWindowTitle("Keyboard");

    hBoxLayout = new QHBoxLayout;
    vBoxLayout = new QVBoxLayout;

    tabWidget = new QTabWidget;
    tabWidget->setFixedSize(550, 400);

    soft_Keyboard_Numbers = new Soft_Keyboard_Numbers;
    soft_Keyboard_Complete = new Soft_Keyboard_Complete;
    soft_keyboard_Capital_Letter = new Soft_keyboard_Capital_Letter;
    soft_Keyboard_Lowercase_Letter = new Soft_Keyboard_Lowercase_Letter;
    soft_Keyboard_Symbol = new Soft_Keyboard_Symbol;

    connect_Letter_PushBtn_Click();

    tabWidget->addTab(soft_Keyboard_Numbers,"Numbers");
    tabWidget->addTab(soft_Keyboard_Complete,"Complete");
    tabWidget->addTab(soft_keyboard_Capital_Letter,"Capital Letter");
    tabWidget->addTab(soft_Keyboard_Lowercase_Letter,"Lowercase Letter");
    tabWidget->addTab(soft_Keyboard_Symbol,"Symbol");

    tabWidget->setFocusPolicy(Qt::NoFocus);

    tabWidget->setStyleSheet("QTabBar::tab {min-width:100px;min-height:26px;color: black;border:1px solid; border-color:rgb(200, 200, 200); border-top-left-radius:4; border-top-right-radius:4;} \
                                  QTabBar::tab:!selected {margin-top: 5px;background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,stop:0 rgba(232, 232, 232, 255), stop:1 rgba(195, 196, 200, 255));} \
                                  QTabBar::tab:selected {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,stop:0 rgba(188, 222, 237, 255), stop:1 rgba(116, 173, 196, 255));} ");

    tabWidget->setAttribute(Qt::WA_AttributeCount, true);
    pushBtn_Clean = new QPushButton("Clean");
    pushBtn_Space = new QPushButton("Space");
    pushBtn_Backspace = new QPushButton("BackSpace");
    pushBtn_Quit = new QPushButton("Quit");

    pushBtn_Clean->setStyleSheet("width:120px; height: 35px; color:rgb(39, 83, 102); border:none; border-radius:10px; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,stop:0 rgba(188, 222, 237, 255), stop:1 rgba(116, 173, 196, 255)); font-size:20px;");
    pushBtn_Space->setStyleSheet("width:120px; height: 35px; color:rgb(39, 83, 102); border:none; border-radius:10px; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,stop:0 rgba(188, 222, 237, 255), stop:1 rgba(116, 173, 196, 255)); font-size:20px;");
    pushBtn_Backspace->setStyleSheet("width:120px; height: 35px; color:rgb(39, 83, 102); border:none; border-radius:10px; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,stop:0 rgba(188, 222, 237, 255), stop:1 rgba(116, 173, 196, 255)); font-size:20px;");
    pushBtn_Quit->setStyleSheet("width:120px; height: 35px; color:rgb(39, 83, 102); border:none; border-radius:10px; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,stop:0 rgba(188, 222, 237, 255), stop:1 rgba(116, 173, 196, 255)); font-size:20px;");

    pushBtn_Clean->setFocusPolicy(Qt::NoFocus);
    pushBtn_Space->setFocusPolicy(Qt::NoFocus);
    pushBtn_Backspace->setFocusPolicy(Qt::NoFocus);
    pushBtn_Quit->setFocusPolicy(Qt::NoFocus);

    connect(pushBtn_Clean, SIGNAL(clicked()), this, SLOT(slot_Clean_PushBtn_Clicked()));
    connect(pushBtn_Space, SIGNAL(clicked()), this, SLOT(slot_Space_PushBtn_Clicked()));
    connect(pushBtn_Backspace, SIGNAL(clicked()), this, SLOT(slot_BackSpace_PusnBtn_Clicked()));
    connect(pushBtn_Quit, SIGNAL(clicked()), this, SLOT(close()));

    hBoxLayout->addStretch();
    hBoxLayout->addWidget(pushBtn_Clean);
    hBoxLayout->addStretch();
    hBoxLayout->addWidget(pushBtn_Space);
    hBoxLayout->addStretch();
    hBoxLayout->addWidget(pushBtn_Backspace);
    hBoxLayout->addStretch();
    hBoxLayout->addWidget(pushBtn_Quit);
    hBoxLayout->addStretch();

    vBoxLayout->addWidget(tabWidget);
    vBoxLayout->addLayout(hBoxLayout);

    setLayout(vBoxLayout);
    this->setModal(false);

//    setAttribute(Qt::WA_X11DoNotAcceptFocus, true);
    setAttribute(Qt::WA_ShowWithoutActivating, true);
    this->setStyleSheet("background-color: rgb(227, 232, 234);");
}

Soft_Keyboard::~Soft_Keyboard()
{
}

void Soft_Keyboard::connect_Letter_PushBtn_Click(){
    for(int i = 0; i < 21; i++){
        connect(soft_Keyboard_Numbers->pushBtn_Numbers[i], SIGNAL(clicked()), this, SLOT(slot_Letter_PushBtn_Clicked()));
    }
    for(int i = 0; i < 87; i++){
        connect(soft_Keyboard_Complete->pushBtn_Complete[i], SIGNAL(clicked()), this, SLOT(slot_Letter_PushBtn_Clicked()));
    }
    for(int i = 0; i < 26; i++){
        connect(soft_keyboard_Capital_Letter->pushBtn_Capital_Letter[i], SIGNAL(clicked()), this, SLOT(slot_Letter_PushBtn_Clicked()));
    }
    for(int i = 0; i < 26; i++){
        connect(soft_Keyboard_Lowercase_Letter->pushBtn_Lowercase_Letter[i], SIGNAL(clicked()), this, SLOT(slot_Letter_PushBtn_Clicked()));
    }
    for(int i = 0; i < 32; i++){
        connect(soft_Keyboard_Symbol->pushBtn_Symbol[i], SIGNAL(clicked()), this, SLOT(slot_Letter_PushBtn_Clicked()));
    }
}

void Soft_Keyboard::slot_Letter_PushBtn_Clicked(){
    QPushButton *aPushButton = dynamic_cast<QPushButton*>(sender());
    QTextEdit *currentTextEdit = dynamic_cast<QTextEdit*>(currentEditWidget);
    QLineEdit* currentLineEdit = dynamic_cast<QLineEdit*>(currentEditWidget);
    QListWidget* listWidget = dynamic_cast<QListWidget*>(currentEditWidget);
    QTableWidget* tableWidget = dynamic_cast<QTableWidget*>(currentEditWidget);
    QString text;
    if(aPushButton->text() == "&&")
        text = "&";
    else
        text = aPushButton->text();
    if(currentLineEdit != NULL){
        currentLineEdit->insert(text);
        goto label_end;
    }
    if(currentTextEdit != NULL){
        currentTextEdit->append(text);
        goto label_end;
    }
    if(listWidget != NULL){
        QListWidgetItem* item = listWidget->item(modelIndex.row());
        item->setText(item->text() + text);
        goto label_end;
    }
    if(tableWidget != NULL){

        QTableWidgetItem* item = tableWidget->item(modelIndex.row(),modelIndex.column());
        item->setText(item->text() + text);
        goto label_end;
    }
label_end:
    return;
}

void Soft_Keyboard::slot_Clean_PushBtn_Clicked(){
    QTextEdit *currentTextEdit = dynamic_cast<QTextEdit*>(currentEditWidget);
    QLineEdit* currentLineEdit = dynamic_cast<QLineEdit*>(currentEditWidget);
    QListWidget* listWidget = dynamic_cast<QListWidget*>(currentEditWidget);
    QTableWidget* tableWidget = dynamic_cast<QTableWidget*>(currentEditWidget);

    if(currentLineEdit != NULL){
        currentLineEdit->insert("");
        goto label_end;
    }
    if(currentTextEdit != NULL){
        currentTextEdit->insertPlainText("");
        goto label_end;
    }
    if(listWidget != NULL){
        QListWidgetItem* item = listWidget->item(modelIndex.row());
        item->setText("");
        goto label_end;
    }
    if(tableWidget != NULL){
        QTableWidgetItem* item = tableWidget->item(modelIndex.row(),modelIndex.column());
        item->setText("");
        goto label_end;
    }
label_end:
    return;
}

void Soft_Keyboard::slot_Space_PushBtn_Clicked(){
    QTextEdit *currentTextEdit = dynamic_cast<QTextEdit*>(currentEditWidget);
    QLineEdit* currentLineEdit = dynamic_cast<QLineEdit*>(currentEditWidget);
    QListWidget* listWidget = dynamic_cast<QListWidget*>(currentEditWidget);
    QTableWidget* tableWidget = dynamic_cast<QTableWidget*>(currentEditWidget);
    QString text = " ";
    if(currentLineEdit != NULL){
        currentLineEdit->insert(text);
        goto label_end;
    }
    if(currentTextEdit != NULL){
        currentTextEdit->append(text);
        goto label_end;
    }
    if(listWidget != NULL){
        QListWidgetItem* item = listWidget->item(modelIndex.row());
        item->setText(item->text() + text);
        goto label_end;
    }
    if(tableWidget != NULL){

        QTableWidgetItem* item = tableWidget->item(modelIndex.row(),modelIndex.column());
        item->setText(item->text() + text);
        goto label_end;
    }
label_end:
    return;
}

void Soft_Keyboard::slot_BackSpace_PusnBtn_Clicked(){
    QTextEdit *currentTextEdit = dynamic_cast<QTextEdit*>(currentEditWidget);
    QLineEdit* currentLineEdit = dynamic_cast<QLineEdit*>(currentEditWidget);
    QListWidget* listWidget = dynamic_cast<QListWidget*>(currentEditWidget);
    QTableWidget* tableWidget = dynamic_cast<QTableWidget*>(currentEditWidget);

    if(currentLineEdit != NULL){
        currentLineEdit->backspace();
        goto label_end;
    }
    if(currentTextEdit != NULL){
        currentTextEdit->textCursor().deletePreviousChar();
        goto label_end;
    }
    if(listWidget != NULL){
        QListWidgetItem* item = listWidget->item(modelIndex.row());
        item->setText(item->text().remove(item->text().length()-1,1));
        goto label_end;
    }
    if(tableWidget != NULL){

        QTableWidgetItem* item = tableWidget->item(modelIndex.row(),modelIndex.column());
        item->setText(item->text().remove(item->text().length()-1,1));
        goto label_end;
    }
label_end:
    return;
}
