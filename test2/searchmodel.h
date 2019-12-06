#ifndef SEARCHMODEL_H
#define SEARCHMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include "muitemdelegate.h"
class SearchModel : public QAbstractListModel
{
	Q_OBJECT

public:
	
	SearchModel(QObject *parent);
	~SearchModel();

	void insertTestData(QStringList icons, QStringList singers, QStringList types);
	void insertRow(QString icons, QString singers, QString type);

	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	virtual Qt::ItemFlags flags(const QModelIndex & index) const override;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	void addCount();
private:
	int m_count;
	QVector<MuItemData> muitemdatas;
};

#endif // SEARCHMODEL_H
