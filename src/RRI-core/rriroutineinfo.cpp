#include "rriroutineinfo.h"

RRIRoutineInfo::RRIRoutineInfo():
    index(-1),
    id(-1),
    count(1),
    file("void"),
    name("void"),
    percentageDuration(0),
    averageCallStackLevel(0)
{

}

RRIRoutineInfo::RRIRoutineInfo(RRIRoutineInfo * rRIRoutineInfo):
                                  index(rRIRoutineInfo->getIndex()),
                                  id(rRIRoutineInfo->getId()),
                                  count(rRIRoutineInfo->getCount()),
                                  file(rRIRoutineInfo->getFile()),
                                  name(rRIRoutineInfo->getName()),
                                  percentageDuration(rRIRoutineInfo->getPercentageDuration()),
                                  averageCallStackLevel(rRIRoutineInfo->getAverageCallStackLevel())
{

}

int RRIRoutineInfo::getIndex() const
{
    return index;
}

void RRIRoutineInfo::setIndex(int value)
{
    index = value;
}

int RRIRoutineInfo::getId() const
{
    return id;
}

void RRIRoutineInfo::setId(int value)
{
    id = value;
}

QString RRIRoutineInfo::getFile() const
{
    return file;
}

void RRIRoutineInfo::setFile(const QString &value)
{
    file = value;
}

QString RRIRoutineInfo::getName() const
{
    return name;
}

void RRIRoutineInfo::setName(const QString &value)
{
    name = value;
}

double RRIRoutineInfo::getPercentageDuration() const
{
    return percentageDuration;
}

void RRIRoutineInfo::initPercentageDuration(double value)
{
    percentageDuration = value;
}

void RRIRoutineInfo::addToPercentageDuration(double value)
{
    percentageDuration += value;
}

void RRIRoutineInfo::normalizePercentageDuration(double value)
{
    if (value>0){
        percentageDuration /= (double)value;
    }
}

void RRIRoutineInfo::setPercentageDuration(double value)
{
    percentageDuration = value;
}

double RRIRoutineInfo::getAverageCallStackLevel() const
{
    return averageCallStackLevel;
}

void RRIRoutineInfo::initAverageCallStackLevel(double value)
{
    averageCallStackLevel = value;
    count++;
}

void RRIRoutineInfo::addToAverageCallStackLevel(double value)
{
    averageCallStackLevel += value;
    count++;
}

void RRIRoutineInfo::normalizeAverageCallStackLevel()
{
    if (count!=0){
        averageCallStackLevel /= (double)count;
        count=1;
    }
}

void RRIRoutineInfo::setAverageCallStackLevel(double value)
{
    averageCallStackLevel = value;
    count=1;
}

int RRIRoutineInfo::getCount() const
{
    return count;
}

QString RRIRoutineInfo::toString()
{
    return file+":"+name;
}

