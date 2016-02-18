#ifndef REDISTRIBUTEDMODEL_H
#define REDISTRIBUTEDMODEL_H

#include <QVector>
#include <QString>

#include "microscopicmodel.h"
#include "macroscopicmodel.h"
#include "part.h"

class RedistributedModel
{
public:
    RedistributedModel();
    RedistributedModel(MicroscopicModel* microscopicModel, MacroscopicModel* macroscopicModel);
    virtual ~RedistributedModel() {}
    MicroscopicModel *getMicroscopicModel() const;
    void setMicroscopicModel(MicroscopicModel *value);
    MacroscopicModel *getMacroscopicModel() const;
    void setMacroscopicModel(MacroscopicModel *value);
    virtual QVector<QString> getParts()=0;
protected:
    MicroscopicModel* microscopicModel;
    MacroscopicModel* macroscopicModel;
    Vector<QString> partMap;
};

#endif // REDISTRIBUTEDMODEL_H
