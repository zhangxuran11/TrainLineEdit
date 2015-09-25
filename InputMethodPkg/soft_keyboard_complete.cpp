#include "soft_keyboard_complete.h"

Soft_Keyboard_Complete::Soft_Keyboard_Complete(QWidget *parent) : QWidget(parent)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");

    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    unsigned int key_Complete[87]={
        '\x0e\x01',
        '\x0e\x02',
        '\x0e\x03',
        '\x0e\x04',
        '\x0e\x05',
        '\x0e\x06',
        '\x0e\x07',
        '\x0e\x08',
        '\x0e\x09',
        '\x0e\x0a',
        '\x0e\x0b',
        '\x0e\x0c',
        '\x0e\x0d',
        '\x0e\x0e',
        '\x0e\x0f',
        '\x0e\x10',
        '\x0e\x11',
        '\x0e\x12',
        '\x0e\x13',
        '\x0e\x14',
        '\x0e\x15',
        '\x0e\x16',
        '\x0e\x17',
        '\x0e\x18',
        '\x0e\x19',
        '\x0e\x1a',
        '\x0e\x1b',
        '\x0e\x1c',
        '\x0e\x1d',
        '\x0e\x1e',
        '\x0e\x1f',
        '\x0e\x20',
        '\x0e\x21',
        '\x0e\x22',
        '\x0e\x23',
        '\x0e\x24',
        '\x0e\x25',
        '\x0e\x26',
        '\x0e\x27',
        '\x0e\x28',
        '\x0e\x29',
        '\x0e\x2a',
        '\x0e\x2b',
        '\x0e\x2c',
        '\x0e\x2d',
        '\x0e\x2e',
        '\x0e\x2f',
        '\x0e\x30',
        '\x0e\x31',
        '\x0e\x32',
        '\x0e\x33',
        '\x0e\x34',
        '\x0e\x35',
        '\x0e\x36',
        '\x0e\x37',
        '\x0e\x38',
        '\x0e\x39',
        '\x0e\x3a',
        '\x0e\x3f',
        '\x0e\x40',
        '\x0e\x41',
        '\x0e\x42',
        '\x0e\x43',
        '\x0e\x44',
        '\x0e\x45',
        '\x0e\x46',
        '\x0e\x47',
        '\x0e\x48',
        '\x0e\x49',
        '\x0e\x4a',
        '\x0e\x4b',
        '\x0e\x4c',
        '\x0e\x4d',
        '\x0e\x4e',
        '\x0e\x4f',
        '\x0e\x50',
        '\x0e\x51',
        '\x0e\x52',
        '\x0e\x53',
        '\x0e\x54',
        '\x0e\x55',
        '\x0e\x56',
        '\x0e\x57',
        '\x0e\x58',
        '\x0e\x59',
        '\x0e\x5a',
        '\x0e\x5b'
    };

    for(int i=0; i<87; i++)
    {
        pushBtn_Complete[i] = new QPushButton(QString("%1").arg(QString::fromUcs4(&key_Complete[i], 1)));
        pushBtn_Complete[i]->setFocusPolicy(Qt::NoFocus);
        pushBtn_Complete[i]->setFixedHeight(40);
        pushBtn_Complete[i]->setStyleSheet("color:rgb(39, 83, 102); border:none; border-radius:10px; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,stop:0 rgba(188, 222, 237, 255), stop:1 rgba(116, 173, 196, 255)); font-size:20px;");
    }

    gridLayout = new QGridLayout;
    gridLayout->setVerticalSpacing(2);
    gridLayout->setHorizontalSpacing(2);
    int rows = 8, columns = 12, btnid = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(btnid < 87){
                gridLayout->addWidget(pushBtn_Complete[btnid], i, j);
                btnid++;
            }
            else{
                break;
            }
        }
    }

    vBoxLayout = new QVBoxLayout;
    vBoxLayout->addLayout(gridLayout);
    vBoxLayout->addStretch();

    setLayout(vBoxLayout);
}

Soft_Keyboard_Complete::~Soft_Keyboard_Complete()
{

}

