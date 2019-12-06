#ifndef TEST2_H
#define TEST2_H

#include <QtWidgets/QMainWindow>
//#include "ui_test2.h"
#include <QMetaType>
#include "searchmodel.h"
#include "QListView"
#include "QComboBox"
#include "QGridLayout"
#include "QWidget"
class test2 : public QMainWindow
{
	Q_OBJECT

public:
	test2(QWidget * parent = 0);
	~test2();

private:
	//Ui::test2Class ui;
	bool m_flag;
	int m_nTimerID;
	virtual void timerEvent(QTimerEvent * event);
	int m_num;
	SearchModel * m_pModel;
	QWidget * m_centralWidget;
	QGridLayout * m_gridLayout;
	QListView * m_listView;
	QComboBox * m_comboBox;
};

#endif // TEST2_H
