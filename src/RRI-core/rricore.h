#ifndef RRICORE_H
#define RRICORE_H

#include <QObject>
#include <QFileInfo>
#include <QDebug>
#include "rricore_global.h"
#include "constants.h"
#include "rrimodel.h"
#include "omacroscopicmodel.h"
#include "parameters.h"
#include "debug.h"

using InputData::DataType;

class CORESHARED_EXPORT RRICore
{

public:
    RRICore();
    bool buildMicroscopicModel();
    void initMacroscopicModels();
    void buildMacroscopicModels();
    void selectMacroscopicModel();
    Parameters* getParameters() const;
    MacroscopicModel* getMacroscopicModel() const;
    MicroscopicModel* getMicroscopicModel() const;

private:
    Parameters* parameters;
    MicroscopicModel* microscopicModel;
    MacroscopicModel* macroscopicModel;


};

#endif // RRICORE_H
