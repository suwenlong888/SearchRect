#include "muitemdelegate.h"
#include "QPainter"
MuItemDelegate::MuItemDelegate(QWidget *parent)
	: QStyledItemDelegate(parent)
{

}

MuItemDelegate::~MuItemDelegate()
{

}
QSize MuItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	Q_UNUSED(index);
	QStringList itemData = index.data(Qt::UserRole + 1).toStringList();
	//QStringList itemData = var.value<QStringList>();
	if (itemData.size() > 0) 
	{
		if (itemData[3] == "title")
		{
			return QSize(option.rect.width(), 20);
		}
		else
		{
			return QSize(option.rect.width(), 30);
		}
	}

	return QStyledItemDelegate::sizeHint(option, index);
	
}

//重写paint函数：

void MuItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	if (index.isValid())
	{
		painter->save();
		QStringList itemData = index.data(Qt::UserRole + 1).toStringList();
		//QVariant var = index.data(Qt::UserRole + 1);
		//MuItemData itemData = var.value<MuItemData>();
		QRectF rect;

		if (index.column() < 0)
		{
			return;
		}
		// item 矩形区域
		if (itemData[3] == "item")
		{
			rect.setX(option.rect.x());
			rect.setY(option.rect.y());
			rect.setWidth(option.rect.width() - 1);
			rect.setHeight(option.rect.height() - 1);
		}
		else
		{
			rect.setX(option.rect.x());
			rect.setY(option.rect.y());
			rect.setWidth(option.rect.width() - 1);
			rect.setHeight(option.rect.height() - 1);
		}

		QPainterPath path;

		path.moveTo(rect.topRight());
		path.lineTo(rect.topLeft());
		path.quadTo(rect.topLeft(), rect.topLeft());
		path.lineTo(rect.bottomLeft());
		path.quadTo(rect.bottomLeft(), rect.bottomLeft());
		path.lineTo(rect.bottomRight());
		path.quadTo(rect.bottomRight(), rect.bottomRight());
		path.lineTo(rect.topRight());
		path.quadTo(rect.topRight(), rect.topRight());



		// 鼠标悬停或者选中时改变背景色
		if (itemData[3] == "item")
		{
			if (option.state.testFlag(QStyle::State_MouseOver)) {
				painter->setPen(QPen(QColor("#ebeced")));
				painter->setBrush(QColor("#ebeced"));
				painter->drawPath(path);
			}
			if (option.state.testFlag(QStyle::State_Selected)) {
				painter->setPen(QPen(QColor("#e3e3e5")));
				painter->setBrush(QColor("#e3e3e5"));
				painter->drawPath(path);
			}
		}
		QRectF iconRect;
		QRectF singerRect;
		QRectF songNbRect;
		// 绘制图片，歌手，数量位置区域
		if (itemData[3] == "item")
		{
			iconRect = QRect(rect.left() + 20, rect.top() + 5, 20,  20);
			singerRect = QRect(iconRect.right() + 20, iconRect.top(), rect.width() - 10 - iconRect.width(), 20);
			songNbRect = QRect(rect.right() - 30, singerRect.top(), rect.width() - 10 - iconRect.width(), 20);
		}
		else
		{
			iconRect = QRect(rect.left() + 5, rect.top() + 5, 0, 0);
			singerRect = QRect(iconRect.right(), iconRect.top() - 5, rect.width() - 10 - iconRect.width(), 20);
			//songNbRect = QRect(singerRect.left(), singerRect.bottom() + 5, rect.width() - 10 - iconRect.width(), 20);
		}

		painter->drawImage(iconRect, QImage(itemData[0]));
		painter->setPen(QPen(Qt::black));
		painter->setFont(QFont("Microsoft Yahei", 10));
		painter->drawText(singerRect, itemData[1]);

		painter->setPen(QPen(Qt::gray));
		painter->drawText(songNbRect, itemData[2]);

		painter->restore();
	}
}