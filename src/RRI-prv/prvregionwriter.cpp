#include "prvregionwriter.h"

PrvRegionWriter::PrvRegionWriter():parser(new RegionParser()), block(new EventTypeBlock())
{

}

PrvRegionWriter::~PrvRegionWriter()
{
    delete block;
    delete parser;
}

void PrvRegionWriter::setEventTypeBlockItems()
{
    //int i=0;
    int basename=BASENAME_RRI;
    for (Region* region : parser->getRegionMap().values()){
        mapBaseName.insert(region->getName(), basename);
    }
    block->addItem(0, basename, "RRI functions");
    block->addValue("End");
}

void PrvRegionWriter::pushRRIRegionHeader()
{
    QTextStream* output=outputPrvFile->getPrvStream();
    *output<<"#RRI"<<endl;
}

void PrvRegionWriter::pushRRIRegion(QString region, RRICore *core)
{
    QTextStream* output=outputPrvFile->getPrvStream();
    QVector<Part*> parts=core->getParts();
    for (int i=0; i< parts.size(); i++){
        if (core->getRedistributedModel()->getPartsAsString()[i].compare("void")!=0){
            if (!block->getValueMap().contains(core->getRedistributedModel()->getPartsAsString()[i])){
                block->addValue(core->getRedistributedModel()->getPartsAsInteger()[i],core->getRedistributedModel()->getPartsAsString()[i]);
            }
            *output<<"2:"<<parser->getRegionMap()[region]->getTask()<<
                ":"<<parser->getRegionMap()[region]->getApplication()<<
                ":"<<parser->getRegionMap()[region]->getProcess()<<
                ":"<<parser->getRegionMap()[region]->getThread()<<
                ":"<<parser->getRegionMap()[region]->getStart()+(long)(parser->getRegionMap()[region]->getDuration()*parts[i]->getFirstRelative())<<
                ":"<<mapBaseName[region]<<
                ":"<<block->getValueMap()[core->getRedistributedModel()->getPartsAsString()[i]]->getValue()<<endl;
            *output<<"2:"<<parser->getRegionMap()[region]->getTask()<<
                ":"<<parser->getRegionMap()[region]->getApplication()<<
                ":"<<parser->getRegionMap()[region]->getProcess()<<
                ":"<<parser->getRegionMap()[region]->getThread()<<
                ":"<<parser->getRegionMap()[region]->getStart()+(long)(parser->getRegionMap()[region]->getDuration()*parts[i]->getLastRelative())<<
                ":"<<mapBaseName[region]<<
                ":"<<0<<endl;
        }
    }
}

void PrvRegionWriter::pushRRIEventTypeBlock()
{
    QTextStream* output=outputPrvFile->getPcfStream();
    *output<<*block;
}

void PrvRegionWriter::parseRegions(QTextStream* regionStream)
{
    parser->buildRegions(regionStream);
}

PrvFileManager *PrvRegionWriter::getInputPrvFile() const
{
    return inputPrvFile;
}

void PrvRegionWriter::setInputPrvFile(PrvFileManager *value)
{
    inputPrvFile = value;
}

PrvFileManager *PrvRegionWriter::getOutputPrvFile() const
{
    return outputPrvFile;
}

void PrvRegionWriter::setOutputPrvFile(PrvFileManager *value)
{
    outputPrvFile = value;
}