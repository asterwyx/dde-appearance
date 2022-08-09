#ifndef THEMETHUMB_H
#define THEMETHUMB_H

#include <QDebug>
#include <QObject>
#include <time.h>
#include <QDir>
#include <glib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <QGSettings>
#include <QDBusInterface>
#include <QImage>
#include <QPainter>
#include <QProcess>
#include <X11/Xcursor/Xcursor.h>

QString getScaleDir();
QString getTypeDir(QString type0, int version);
void init(double scalFactor0);
void removeUnusedScaleDirs();
void removeAllTypesOldVersionDirs();
void removeOldVersionDirs(QString scaleDir, QString type0, int version);
void removeUnusedDirs(QString pattern, QString userDir);
bool checkScaleFactor();
double getScaleFactor();
QString getCursor(QString id, QString descFile);
bool genCursor(QString descFile,int width,int height,double scaleFactor,QString out);
bool genGtk(QString descFile,int width,int height,double scaleFactor,QString dest);
QImage CompositeImages(QVector<QImage*>, int width, int height, int inconSize,int padding);
QImage* loadXCursor(QString fileName, int size);
QImage* fromXCurorImageToQImage(XcursorImage* image);
QVector<QImage*> getIcons(QString dir, int size);
QString getGtk(QString id, QString descFile);
QString getIcon(QString id, QString descFile);
bool shouldGenerateNew(QString descFile, QString out);
bool shouldGenerateNewCursor(QString descFile, QString out);
QString prepareOutputPath(QString type0, QString id, int version);
//bool gen(QString descFile, int width, int height, float scaleFactor, QString out);


#endif // THEMETHUMB_H