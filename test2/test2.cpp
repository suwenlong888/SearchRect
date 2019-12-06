#include "test2.h"
#include "MuItemDelegate.h"
#include <QStandardItemModel>
#include <QObject>
#include "QComboBox"
#include <searchmodel.h>
#include "QTimer"
#include <QTimerEvent>  
#include "QListView"
#include "QAction"
QStringList icons = {
	"../images/UK.png", "../images/UK.png", "../images/UK.png",
	"../images/UK.png", "../images/UK.png", "../images/UK.png",
};
QStringList singers = {
	"MC-Hotdog", "Li", "Author",
	"PACT", "Yang", "Zhang",
};
QStringList types = {
	"item", "item", "item",
	"item", "item", "item",
};

test2::test2(QWidget *parent)
	: QMainWindow(parent)
{
	m_centralWidget = new QWidget(this);
	//centralWidget->setObjectName(QStringLiteral("centralWidget"));
	this->resize(600,500);
	m_gridLayout = new QGridLayout(m_centralWidget);
	m_gridLayout->setSpacing(6);
	m_gridLayout->setContentsMargins(11, 11, 11, 11);
	m_gridLayout->setObjectName(QStringLiteral("gridLayout"));
	
	m_listView = new QListView(m_centralWidget);
	m_listView->move(10, 10);
	//listView->setObjectName(QStringLiteral("listView"));
	m_listView->setResizeMode(QListView::Adjust);

	m_gridLayout->addWidget(m_listView, 0, 0, 1, 1);

	m_comboBox = new QComboBox(m_centralWidget);
	
	//comboBox->setObjectName(QStringLiteral("comboBox"));
	m_comboBox->setMinimumSize(QSize(231, 20));
	m_comboBox->setMaximumSize(QSize(231, 20));

	m_gridLayout->addWidget(m_comboBox, 0, 1, 1, 1);
	m_comboBox->move(10, 10);
	setCentralWidget(m_centralWidget);
	m_centralWidget->show();
	
	m_num = 0;
	//2 1s增加一条数据
	m_nTimerID = this->startTimer(1000);
	//ui.setupUi(this);
	
	//model 放出去
	//1 代码格式整理
	m_pModel = new SearchModel(this);
	m_pModel->insertRow("../images/aa.jpg", "UK", "title");
	m_pModel->insertTestData(icons, singers, types);
	m_pModel->insertRow("../images/aa.jpg", "US", "title");
	MuItemDelegate *pItemDelegate = new MuItemDelegate(this);
	//comboBox->setEnabled(true);
	//ui.comboBox->addItem("aaaa");
	//ui.comboBox->addItem("bbb");
	m_listView->setModel(m_pModel);
	m_comboBox->setModel(m_pModel);
	m_listView->setItemDelegate(pItemDelegate);
	m_comboBox->setItemDelegate(pItemDelegate);
	/*
	ui.listView->setModel(pModel);
	ui.comboBox->setModel(pModel);
	ui.listView->setItemDelegate(pItemDelegate);
	ui.comboBox->setItemDelegate(pItemDelegate);
	*/
}

test2::~test2()
{

}
void test2::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == m_nTimerID)
	{
		//icons.append("../images/aa.jpg");
		//singers.append(QString::number(num++));
		m_pModel->insertRow("../images/US.png", QString::number(m_num++), "item");
		m_pModel->addCount();
	}
}