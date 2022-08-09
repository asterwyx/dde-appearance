#include "appearance1.h"
#include "../modules/common/commondefine.h"
#include "../modules/dconfig/dconfigsettings.h"

#include <iostream>

Appearance1::Appearance1(QObject *parent)
    :QObject(parent),
     appearanceManager(new AppearanceManager())
{
    registerScaleFactorsMetaType();
    connect(appearanceManager.data(),SIGNAL(Changed(QString, QString)),this,
            SLOT(handleChangeSignal(const QString&, const QString&)));

    connect(appearanceManager.data(),SIGNAL(Refreshed(QString)),this,
            SLOT(handleRefreshedSignal(const QString)));
}

Appearance1::~Appearance1()
{

}

QString Appearance1::background() const
{
    return appearanceManager->getBackground();
}

double Appearance1::fontSize() const
{
    return appearanceManager->getFontSize();
}

void Appearance1::setFontSize(double value)
{
    appearanceManager->setFontSize(value);
}

QString Appearance1::gtkTheme() const
{
    return appearanceManager->getGtkTheme();
}

QString Appearance1::iconTheme() const
{
    return appearanceManager->getIconTheme();
}

QString Appearance1::cursorTheme() const
{
    return appearanceManager->getCursorTheme();
}

QString Appearance1::monospaceFont() const
{
    return appearanceManager->getMonospaceFont();
}

double Appearance1::opaticy() const
{
    return appearanceManager->getOpaticy();
}

void Appearance1::setOpaticy(double value)
{
    appearanceManager->setOpaticy(value);
}

QString Appearance1::qtActiveColor() const
{
    return appearanceManager->getQtActiveColor();
}

void Appearance1::setQtActiveColor(const QString &value)
{
    appearanceManager->setQtActiveColor(value);
}

QString Appearance1::standarFont() const
{
    return appearanceManager->getStandarFont();
}

QString Appearance1::wallpaperSlideShow() const
{
    return appearanceManager->getWallpaperSlideShow();
}

void Appearance1::setWallpaperSlideShow(const QString &value)
{
    appearanceManager->setWallpaperSlideShow(value);
}

QString Appearance1::wallpaperURls() const
{
    return appearanceManager->getWallpaperURls();
}

int Appearance1::windowRadius() const
{
    return appearanceManager->getWindowRadius();
}

void Appearance1::setWindowRadius(int value)
{
    appearanceManager->setWindowRadius(value);
}

void Appearance1::Delete(const QString &ty, const QString &name)
{
   appearanceManager->deleteThermByType(ty,name);
}

double Appearance1::GetScaleFactor()
{
    return appearanceManager->getScaleFactor();
}


ScaleFactors Appearance1::GetScreenScaleFactors()
{
    return appearanceManager->getScreenScaleFactors();
}

QString Appearance1::GetWallpaperSlideShow(const QString &monitorName)
{
    return appearanceManager->doGetWallpaperSlideShow(monitorName);
}

QString Appearance1::List(const QString &ty)
{
    QString type = ty.toLower();
    return appearanceManager->doList(type);
}

void Appearance1::Reset()
{
    QStringList keys{GSKEYGTKTHEME,GSKEYICONTHEM,GSKEYCURSORTHEME,GSKEYFONTSIZE};

    appearanceManager->doResetSettingBykeys(keys);

    appearanceManager->doResetFonts();

}

void Appearance1::SetMonitorBackground(const QString& monitorName, const QString& imageGile)
{
    QString file = appearanceManager->doSetMonitorBackground(monitorName,imageGile);

    if(!file.isEmpty())
    {
        appearanceManager->doSetWsLoop(monitorName,file);
    }
}

void Appearance1::SetScaleFactor(double scale)
{
    appearanceManager->setScaleFactor(scale);
}

void Appearance1::SetScreenScaleFactors(ScaleFactors scaleFactors)
{
    appearanceManager->setScreenScaleFactors(scaleFactors);
}

void Appearance1::SetWallpaperSlideShow(const QString &monitorName, const QString &slideShow)
{
    appearanceManager->doSetWallpaperSlideShow(monitorName,slideShow);
}

QString Appearance1::Show(const QString &ty, const QStringList &names)
{
    return appearanceManager->doShow(ty,names);
}

QString Appearance1::Thumbnail(const QString &ty, const QString &name)
{
    return appearanceManager->doThumbnail(ty,name);
}

void Appearance1::Set(const QString &ty,const QString &value)
{
    QString type = ty.toLower();
    appearanceManager->doSetByType(ty,value);
}

void Appearance1::handleChangeSignal(const QString& type, const QString& value)
{
    Q_EMIT Changed(type,value);
}

void Appearance1::handleRefreshedSignal(const QString &type)
{
    Q_EMIT Refreshed(type);
}

void Appearance1::SetCurrentWorkspaceBackground(const QString &uri)
{

}

QString Appearance1::GetCurrentWorkspaceBackground()
{
    return "";
}

void Appearance1::SetCurrentWorkspaceBackgroundForMonitor(const QString &uri, const QString &strMonitorName)
{

}

QString Appearance1::GetCurrentWorkspaceBackgroundForMonitor(const QString &strMonitorName)
{
    return "";
}

void Appearance1::SetWorkspaceBackgroundForMonitor(const int &index, const QString &uri, const QString &strMonitorName)
{

}

QString Appearance1::GetWorkspaceBackgroundForMonitor(const int &index,const QString &strMonitorName)
{
    return "";
}