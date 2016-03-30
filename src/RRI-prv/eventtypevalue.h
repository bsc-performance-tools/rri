/*  RRI - Relevant Routine Identifier
*  Copyright (C) 2016  Damien Dosimont
*  
*  This file is part of RRI.
*  
*  RRI is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*  
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*  
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EVENTTYPEVALUE_H
#define EVENTTYPEVALUE_H

#include <QString>
#include <QTextStream>
#include <QDebug>

class EventTypeValue
{
public:
    EventTypeValue();
    EventTypeValue(const EventTypeValue& object);
    ~EventTypeValue();
    EventTypeValue(int value, QString label);
    int getValue() const;
    void setValue(int value);
    QString getLabel() const;
    void setLabel(const QString &value);

    friend QTextStream& operator<<(QTextStream& out, EventTypeValue value);
    friend QTextStream& operator<<(QTextStream& out, EventTypeValue* value);

protected:
    int value;
    QString label;
};

#endif // EVENTTYPEVALUE_H
