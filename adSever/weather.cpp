#include "weather.h"
#include <QDebug>

QString Weather::current_wd="";
Weather::Weather( QLabel *_label , QComboBox *_city_cb, QComboBox *_area_cb, QObject *parent) :
    QObject(parent)
{
    label = _label;
    city_cb = _city_cb;
    area_cb = _area_cb;

    timer = new QTimer;
    net_manager = new QNetworkAccessManager;
    net_request = new QNetworkRequest;

    connect(net_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readyWeather()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWd()));

    QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName ("WeatherCode.db");
    if(db.open ())
    {
        qDebug()<<"open suc" ;
    }

    query = new QSqlQuery(db);

    QString cmd ="select citypy from citycode where code\
                like '101%%0100' or code like '101%%0101'";
    query->exec(cmd);
    while(query->next())
    {
        QString msg = query->value ("citypy").toString ();
        if(!msg.isEmpty ())
          {
            city_cb->addItem(msg);
          }
     }
    findArea(city_cb->currentText());
    getWeather(area_cb->currentText());

    timer->start(5000);
}

Weather::~Weather()
{
    delete net_manager;
    delete net_request;
    delete query;
    delete timer;
}

void Weather::showWeather(QString weather)
{
    label->setText(weather);
    Weather::current_wd = weather;
    emit broadcast(QString::number(WEATHER)+"|"+weather);
}
//从数据查询特定城市的代码
void Weather::findArea(QString _city)
{
    QString cmd =QString("select city from citycode where citypy='%1'").arg(_city);
    query->exec(cmd);
    area_cb->clear();
    while(query->next())
    {
        QString msg = query->value("city").toString();

        if(!msg.isEmpty())
        {
            area_cb->addItem(msg);
        }
    }
}

//从中国气象网获取天气信息
void Weather::getWeather(QString _city)
{
    city = _city;
    QString cmd =QString("select code from citycode where city='%1'").arg(_city);
    query->exec(cmd);

    query->next();
    QString code = query->value("code").toString();
    if(!code.isEmpty())
    {
        cmd = QString("http://www.weather.com.cn/adat/sk/%1.html").arg(code);
        net_request->setUrl(cmd);
        net_reply = net_manager->get(*net_request);
    }

}

//解析json数据，获得天气信息
void Weather::readyWeather()
{
    QString msg = net_reply->readAll();


    QJsonParseError jserr;
    QJsonObject obj;
    QJsonDocument   document = QJsonDocument::fromJson(msg.toUtf8(), &jserr);
    if(jserr.error ==QJsonParseError::NoError)
    {
        if(document.isObject())
        {
            obj = document.object();
            obj = obj.value("weatherinfo").toObject();
            msg = obj.value("city").toString()+"\n"
                    +obj.value("temp").toString()+"  "
                    +obj.value("WD").toString()+"  ";
                  //  +obj.value("SD").toString();
            showWeather(msg);
        }
    }
}


void Weather::updateWd()
{
    getWeather(city);
}







