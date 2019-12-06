#include "searchmodel.h"
#include "muitemdelegate.h"

SearchModel::SearchModel(QObject *parent)
	: QAbstractListModel(parent)
{
	m_count = 0;
}

SearchModel::~SearchModel()
{

}
int SearchModel::rowCount(const QModelIndex &parent /* = QModelIndex() */) const
{
	return muitemdatas.size();
}

int SearchModel::columnCount(const QModelIndex &parent /* = QModelIndex() */) const
{
	return 1;
}
QVariant SearchModel::data(const QModelIndex &index, int role) const
{
	int r = index.row();
	if (Qt::UserRole + 1 == role)
	{
		//自己从model中拿数据给view
		//"名称"
		int r = index.row();
		int c = index.column();
		if (r >= muitemdatas.size())
		{
			return "";
		}
		QStringList list;
		list.append(muitemdatas.at(r).m_iconPath);
		list.append(muitemdatas.at(r).m_singer);
		list.append(muitemdatas.at(r).m_songsNb);
		list.append(muitemdatas.at(r).m_type);
		return list;
	}
	return QVariant();
	
}
void SearchModel::insertTestData(QStringList icons, QStringList singers, QStringList types)
{
	beginResetModel();
	for (int j = 0; j < icons.size(); ++j, ++m_count)
	{
		MuItemData itemData;

		itemData.m_singer = singers.at(j);
		itemData.m_songsNb = QString::number(j * j);
		itemData.m_iconPath = icons.at(j);
		itemData.m_type = types.at(j);
		muitemdatas.append(itemData);
	}
	endResetModel();
}
void SearchModel::insertRow(QString icons, QString singers, QString type)
{
	beginResetModel();

	MuItemData itemData;
	itemData.m_singer = singers;
	itemData.m_songsNb = QString::number(m_count * m_count);
	itemData.m_iconPath = icons;
	itemData.m_type = type;
	muitemdatas.append(itemData);

	endResetModel();
}

QVariant SearchModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	return __super::headerData(section, orientation, role);
}

Qt::ItemFlags SearchModel::flags(const QModelIndex & index) const
{
	return __super::flags(index);
}

void SearchModel::addCount()
{
	m_count++;
}
