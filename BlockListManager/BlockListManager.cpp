#include "BlockListManager.h"

BlockListManager::BlockListManager(QHBoxLayout * _area,
                                   QObject *parent) : QObject(parent)
{
    area=_area;
    QGroupBox * qgb=nullptr;
    QGridLayout * qgl=nullptr;
    TokiBaseColor * tbc=nullptr;
    tbcs.clear();
for(uchar baseColor=0;baseColor<64;baseColor++) {
    if(baseColorNames[baseColor].isEmpty())
        break;
    area->addWidget(qgb=new QGroupBox(baseColorNames[baseColor]));
    qgl=new QGridLayout;
    qgb->setLayout(qgl);
    tbc=new TokiBaseColor(baseColor,qgl);
    tbcs.push_back(tbc);

    connect(this,SIGNAL(translate(Language)),tbc,SLOT(translate(Language)));
}
}

BlockListManager::~BlockListManager() {
    for(uchar i=0;i<tbcs.size();i++)
        delete tbcs[i];
}

void BlockListManager::addBlocks(const QJsonArray & jArray,QString imgDir) {
    std::vector<std::queue<QJsonObject>> tasks;
    tasks.resize(tbcs.size());
    for(ushort i=0;i<tasks.size();i++)
        while(!tasks[i].empty())
            tasks[i].pop();
    imgDir.replace("\\","/");
    QJsonObject temp;
    uchar baseColor;
    for(unsigned int i=0;i<jArray.size();i++) {
        temp=jArray[i].toObject();

        if(!isValidBlockInfo(temp)) {
            qDebug()<<"出现不合法的json信息："<<temp;
            continue;
        }
        if(!temp.contains("version"))temp["version"]=0;
        if(!temp.contains("idOld"))   temp["idOld"]="";
        if(!temp.contains("needGlass")) temp["needGlass"]=false;
        if(!temp.contains("isGlowing")) temp["isGlowing"]=false;
        if(!temp.contains("icon")) temp["icon"]="";

        baseColor=temp.value("baseColor").toInt();
        tasks[baseColor].push(temp);
    }
    for(ushort i=0;i<tasks.size();i++) {
        while(!tasks[i].empty()) {
            tbcs[i]->addTokiBlock(tasks[i].front(),imgDir);
            tasks[i].pop();
        }
    }

}

bool isValidBlockInfo(const QJsonObject & json) {
    return (json.contains("id")&&
         json.contains("nameZH")&&
         json.contains("nameEN")&&
         json.contains("baseColor"));
}

const QString BlockListManager:: baseColorNames[64]={
    "00 None",
    "01 Grass",
    "02 Sand",
    "03 Wool",
    "04 Fire",
    "05 Ice",
    "06 Metal",
    "07 Plant",
    "08 Snow",
    "09 Clay",
    "10 Dirt",
    "11 Stone",
    "12 Water",
    "13 Wood",
    "14 Quartz",
    "15 ColorOrange",
    "16 ColorMagenta",
    "17 ColorLightBlue",
    "18 ColorYellow",
    "19 ColorLime",
    "20 ColorPink",
    "21 ColorGray",
    "22 ColorLightGray",
    "23 ColorCyan",
    "24 ColorPurple",
    "25 ColorBlue",
    "26 ColorBrown",
    "27 ColorGreen",
    "28 ColorRed",
    "29 ColorBlack",
    "30 Gold",
    "31 Diamond",
    "32 Lapis",
    "33 Emerald",
    "34 Podzol",
    "35 Nether",
    "36 TerracottaWhite",
    "37 TerracottaOrange",
    "38 TerracottaMagenta",
    "39 TerracottaLightBlue",
    "40 TerracottaYellow",
    "41 TerracottaLime",
    "42 TerracottaPink",
    "43 TerracottaGray",
    "44 TerracottaLightGray",
    "45 TerracottaCyan",
    "46 TerracottaPurple",
    "47 TerracottaBlue",
    "48 TerracottaBrown",
    "49 TerracottaGreen",
    "50 TerracottaRed",
    "51 TerracottaBlack",
    "52 CrimsonNylium",
    "53 CrimsonStem",
    "54 CrimsonHyphae",
    "55 WarpedNylium",
    "56 WarpedStem",
    "57 WarpedHyphae",
    "58 WarpedWartBlock",
    "59 Deepslate",
    "60 RawIron",
    "61 GlowLichen",
    "",
    ""
};
