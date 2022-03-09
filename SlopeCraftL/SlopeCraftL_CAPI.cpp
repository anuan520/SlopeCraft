/*
 Copyright © 2021-2022  TokiNoBug
This file is part of SlopeCraft.

    SlopeCraft is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SlopeCraft is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SlopeCraft.  If not, see <https://www.gnu.org/licenses/>.

    Contact with me:
    github:https://github.com/ToKiNoBug
    bilibili:https://space.bilibili.com/351429231
*/

#include "SlopeCraftL.h"
#include "simpleBlock.h"
#include "TokiSlopeCraft.h"
using namespace SlopeCraft;

#ifdef SLOPECRAFTL_CAPI
extern "C" {
AbstractBlock * SCL_EXPORT createBlock() {
    return new simpleBlock;
}

unsigned long long SCL_EXPORT blockSize(const AbstractBlock * t) {
    return t->size();
}

///id of this block
const char* SCL_EXPORT getId(const AbstractBlock * t) {
    return t->getId();
}

///first version
unsigned char SCL_EXPORT getVersion(const AbstractBlock * t) {
    return t->getVersion();
}
///id in 1.12
const char* SCL_EXPORT getIdOld(const AbstractBlock * t) {
    return t->getIdOld();
}
///if this block needs a glass block under it
bool SCL_EXPORT getNeedGlass(const AbstractBlock * t) {
    return t->getNeedGlass();
}
///if this block emits light
bool SCL_EXPORT getDoGlow(const AbstractBlock * t) {
    return t->getDoGlow();
}
///if this block can be stolen by enderman
bool SCL_EXPORT getEndermanPickable(const AbstractBlock * t) {
    return t->getEndermanPickable();
}
///if this block can be burnt
bool SCL_EXPORT getBurnable(const AbstractBlock * t) {
    return t->getBurnable();
}
///if this block can be used in wall-map
bool SCL_EXPORT getWallUseable(const AbstractBlock * t) {
    return t->getWallUseable();
}

///set block id
void SCL_EXPORT setId(AbstractBlock * t,const char* id) {
    t->setId(id);
}
///set first version
void SCL_EXPORT setVersion(AbstractBlock * t,unsigned char v) {
    t->setVersion(v);
}
///set id in 1.12
void SCL_EXPORT setIdOld(AbstractBlock * t,const char* io) {
    t->setIdOld(io);
}
///set if this block needs a glass block under it
void SCL_EXPORT setNeedGlass(AbstractBlock * t,bool ng) {
    t->setNeedGlass(ng);
}
///set if this block emits light
void SCL_EXPORT setDoGlow(AbstractBlock * t,bool dg) {
    t->setDoGlow(dg);
}
///set if this block can be stolen by enderman
void SCL_EXPORT setEndermanPickable(AbstractBlock * t,bool ep) {
    t->setEndermanPickable(ep);
}
///set if this block can be burnt
void SCL_EXPORT setBurnable(AbstractBlock * t,bool b) {
    t->setBurnable(b);
}
///set if this block can be used in wall-map
void SCL_EXPORT setWallUseable(AbstractBlock * t,bool wu) {
    t->setWallUseable(wu);
}
///let *b equal to *this
void SCL_EXPORT copyTo(AbstractBlock * t,AbstractBlock * b) {
    t->copyTo(b);
}
///set this block to air
void SCL_EXPORT clear(AbstractBlock * t) {
    t->clear();
}
///replacement for operator delete
void SCL_EXPORT destroyBlock(AbstractBlock * t) {
    t->destroy();
}


///create a Kernel object
Kernel * SCL_EXPORT createKernel() {
    return Kernel::create();
}

void SCL_EXPORT getColorMapPtrs(const float** a,const unsigned char** b,int* c) {
    Kernel::getColorMapPtrs(a,b,c);
}
//full palette
const float * SCL_EXPORT getBasicColorMapPtrs() {
    return Kernel::getBasicColorMapPtrs();
}

const char * SCL_EXPORT getSCLVersion() {
    return Kernel::getSCLVersion();
}

unsigned long long SCL_EXPORT mcVersion2VersionNumber(gameVersion gv) {
    return Kernel::mcVersion2VersionNumber(gv);
}

//can do in nothing:
///real size of Kernel
unsigned long long SCL_EXPORT kernelSize(Kernel * k) {
    return k->size();
}
///revert to a previous step
void SCL_EXPORT decreaseStep(Kernel * k,step s) {
    k->decreaseStep(s);
}
///replacement for operator delete
void SCL_EXPORT destroyKernel(Kernel * k) {
    k->destroy();
}
///configure colorsheets
bool SCL_EXPORT setColorSet(Kernel * k,
                         const char* _RGB,
                         const char* HSV,
                         const char* Lab,
                            const char* XYZ) {
    k->setColorSet(_RGB,HSV,Lab,XYZ);
}


//can do in colorSetReady:
///get current step
step SCL_EXPORT queryStep(const Kernel * k) {
    return k->queryStep();
}
///set map type and blocklist
bool SCL_EXPORT setType(Kernel * k,
             mapTypes a,
             gameVersion b,
             const bool c[64],
             const AbstractBlock * d[64]) {
    return k->setType(a,b,c,d);
}
///get TokiNoBug's url
void SCL_EXPORT getAuthorURL(const Kernel * k,int * count,char ** dest) {
    k->getAuthorURL(count,dest);
}
///get palette (base colors only) in ARGB32
void SCL_EXPORT getARGB32(const Kernel * k,unsigned int * a) {
    k->getARGB32(a);
}


//can do in wait4Image:
///set original image from ARGB32 matrix (col-major)
void SCL_EXPORT setRawImage(Kernel * k,const unsigned int * src, short rows,short cols) {
    k->setRawImage(src,rows,cols);
}
///get accessible color count
unsigned short SCL_EXPORT getColorCount(const Kernel * k) {
    return k->getColorCount();
}
///make a structure that includes all accessible blocks
void SCL_EXPORT makeTests(Kernel * k,const AbstractBlock **a,
                   const unsigned char *b,
                          const char *c,char*d) {
    k->makeTests(a,b,c,d);
}

//can do in convertionReady:
///convert original image to map
bool SCL_EXPORT convert(Kernel * k,convertAlgo ca,bool dither) {
    k->convert(ca,dither);
}
///get image rows
short SCL_EXPORT getImageRows(const Kernel * k) {
    return k->getImageRows();
}
///get image cols
short SCL_EXPORT getImageCols(const Kernel * k) {
    return k->getImageCols();
}
///query if map is buildable in vanilla survival
bool SCL_EXPORT isVanilla(const Kernel * k) {
    return k->isVanilla();
}
///query if map is a flat one
bool SCL_EXPORT isFlat(const Kernel * k) {
    return k->isFlat();
}

//can do in converted:
///construct 3D structure
bool SCL_EXPORT build(Kernel * k,
           compressSettings cs,
           unsigned short mAH,
           glassBridgeSettings gbs,
           unsigned short bl,
                      bool fireProof,bool endermanProof) {
    return k->build(cs,mAH,gbs,bl,fireProof,endermanProof);
}

///get converted image
void SCL_EXPORT getConvertedImage(const Kernel * k,
                                  short * rows,
                                  short * cols,
                                  unsigned int * dest) {
    k->getConvertedImage(rows,cols,dest);
}
///export as map data files
void SCL_EXPORT exportAsData(const Kernel * k,const char * FolderPath,
                          const int indexStart,
                          int* fileCount,
                             char ** dest) {
    k->exportAsData(FolderPath,indexStart,fileCount,dest);
}
///get converted map(in mapColor array)
void SCL_EXPORT getConvertedMap(const Kernel * k,short * rows,short * cols,unsigned char *c) {
    k->getConvertedMap(rows,cols,c);
}

//can do in builded:
///export map into litematica files (*.litematic)
void SCL_EXPORT exportAsLitematic(const Kernel * k,const char * TargetName,
                       const char * LiteName,
                       const char * author,
                       const char * RegionName,
                                  char * FileName) {
    k->exportAsLitematic(TargetName,LiteName,author,RegionName,FileName);
}
///export map into Structure files (*.NBT)
void SCL_EXPORT exportAsStructure(const Kernel * k,
                                  const char * TargetName,
                                  char * FileName) {
    k->exportAsStructure(TargetName,FileName);
}

///get x,y,z size
void SCL_EXPORT get3DSize(const Kernel * k,int * x,int * y,int * z) {
    int _x,_y,_z;
    k->get3DSize(_x,_y,_z);
    if(x!=nullptr)
        *x=_x;
    if(y!=nullptr)
        *y=_y;
    if(z!=nullptr)
        *z=_z;
}

///get 3d structure's size
int SCL_EXPORT getHeight(const Kernel * k) {
    return k->getHeight();
}
///get 3d structure's size
int SCL_EXPORT getXRange(const Kernel * k) {
    return k->getXRange();
}
///get 3d structure's size
int SCL_EXPORT getZRange(const Kernel * k) {
    return k->getZRange();
}
///get block count in total and in detail
void SCL_EXPORT getBlockCountsInTypes(const Kernel * k,int * total, int detail[64]) {
    k->getBlockCounts(total,detail);
}
///get sum block count
int SCL_EXPORT getBlockCounts(const Kernel * k) {
    return k->getBlockCounts();
}
///get 3d structure in 3d-matrix (col major)
const unsigned char * SCL_EXPORT getBuild(const Kernel * k,int* xSize,int* ySize,int* zSize) {
    return k->getBuild(xSize,ySize,zSize);
}

///function ptr to window object
void SCL_EXPORT setWindPtr(Kernel * k,void * p) {
    k->setWindPtr(p);
}
///a function ptr to show progress of converting and exporting
void SCL_EXPORT setProgressRangeSet(Kernel * k,void(*p)(void*,int,int,int)) {
    k->setProgressRangeSet(p);
}
///a function ptr to add progress value
void SCL_EXPORT setProgressAdd(Kernel * k,void(*p)(void*,int)) {
    k->setProgressAdd(p);
}
///a function ptr to prevent window from being syncoped
void SCL_EXPORT setKeepAwake(Kernel * k,void(*p)(void*)) {
    k->setKeepAwake(p);
}

///a function ptr to show progress of compressing and bridge-building
void SCL_EXPORT setAlgoProgressRangeSet(Kernel * k,void(*p)(void*,int,int,int)) {
    k->setAlgoProgressRangeSet(p);
}
///a function ptr to add progress value of compressing and bridge-building
void SCL_EXPORT setAlgoProgressAdd(Kernel * k,void(*p)(void*,int)) {
    k->setAlgoProgressAdd(p);
}

///a function ptr to report error when something wrong happens
void SCL_EXPORT setReportError(Kernel * k,void(*p)(void*,errorFlag)) {
    k->setReportError(p);
}
///a function ptr to report working statue especially when busy
void SCL_EXPORT setReportWorkingStatue(Kernel * k,void(*p)(void*,workStatues)) {
    k->setReportWorkingStatue(p);
}


}   //  extern "C"

#endif  //  ifdef SLOPECRAFTL_CAPI
