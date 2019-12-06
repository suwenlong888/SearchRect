#ifndef MUITEMDELEGATE_H
#define MUITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QMetaType>

typedef struct {
	QString m_iconPath;
	QString m_singer;
	QString m_songsNb;
	QString m_type;
} MuItemData;

Q_DECLARE_METATYPE(MuItemData)
class MuItemDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	MuItemDelegate(QWidget *parent);
	~MuItemDelegate();
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
	
};

#endif // MUITEMDELEGATE_H
