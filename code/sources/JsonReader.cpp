#include "headers/JsonReader.h"
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QIODevice>
#include <QString>
#include <QFile>


namespace dynengines {

    void JsonReader::Read() {

        QString val;
        QFile file;
        file.setFileName("blocks.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();
        //qWarning() << val;
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject sett2 = d.object();
        QJsonValue value = sett2.value(QString("boxes"));
       // qWarning() << value;
        QJsonObject item = value.toObject();
        //qWarning() << tr("QJsonObject of description: ") << item;

        /* incase of string value get value and convert into string*/
        //qWarning() << tr("QJsonObject[appName] of description: ") << item["width"];
        QJsonValue subobj = item["width"];
        //qWarning() << subobj.toString();

        /* incase of array get array and convert into string*/
        //qWarning() << tr("QJsonObject[appName] of value: ") << item["height5"];
        QJsonArray test = item["imp"].toArray();
        //qWarning() << test[1].toString();

    }

}
