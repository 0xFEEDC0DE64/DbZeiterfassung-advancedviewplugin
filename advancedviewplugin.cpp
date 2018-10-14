#include "advancedviewplugin.h"

#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include <QLocale>
#include <QBoxLayout>

#include "utils/fileutils.h"

#include "mainwindow.h"
#include "stripswidget.h"

#include "advancedviewwidget.h"

AdvancedViewPlugin::AdvancedViewPlugin(QObject *parent) :
    ZeiterfassungPlugin(parent)
{
    qDebug() << "called";

    if(m_translator.load(QLocale(), QStringLiteral("advancedviewplugin"), QStringLiteral("_"), translationsDir()))
    {
        if(!QCoreApplication::installTranslator(&m_translator))
        {
            qWarning() << "could not install translation advancedviewplugin";
        }
    }
    else
    {
        qWarning() << "could not load translation advancedviewplugin";
    }
}

void AdvancedViewPlugin::attachTo(MainWindow &mainWindow)
{
    for(auto stripsWidget : mainWindow.stripsWidgets())
        stripsWidget->headerLayout()->addWidget(new AdvancedViewWidget(*stripsWidget));
}
