#ifndef EVENTTYPEITEM_H
#define EVENTTYPEITEM_H

#include <QString>
#include <QTextStream>
#include <QDebug>

class EventTypeItem
{
public:
    EventTypeItem();
    EventTypeItem(const EventTypeItem& object);
    ~EventTypeItem();
    EventTypeItem(int gradientColor, int type, QString label);
    int getGradientColor() const;
    void setGradientColor(int value);

    int getType() const;
    void setType(int value);

    QString getLabel() const;
    void setLabel(const QString &value);

    friend QTextStream& operator<<(QTextStream& out, EventTypeItem item);
    friend QTextStream& operator<<(QTextStream& out, EventTypeItem* item);

protected:
    int gradientColor;
    int type;
    QString label;
};

#endif // EVENTTYPEITEM_H