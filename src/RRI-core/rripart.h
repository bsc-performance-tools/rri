#ifndef RRIPART_H
#define RRIPART_H

#include <QMap>
#include "part.h"
#include "rriobject.h"
#include "rritimeslice.h"
#include "debug.h"

using std::vector;

class RRIPart : public Part
{
public:
    RRIPart(Part* part);
    ~RRIPart();
    void setRoutines(QVector<RRITimeSlice*> timeSlices);
    QMap<int, RRIRoutineInfo*> getRoutines() const;

private:
    int routineNumber;
    QMap<int, RRIRoutineInfo*> routines;

};

#endif // RRIPART_H
