#include "timeassignmentdialog.h"
#include "ui_timeassignmentdialog.h"

#include <QMap>
#include <QStringBuilder>
#include <QDebug>

#include "projectsmodel.h"
#include "zeiterfassungsettings.h"

TimeAssignmentDialog::TimeAssignmentDialog(ProjectsModel &projectsModel, const ZeiterfassungSettings &settings, QWidget *parent) :
    ZeiterfassungDialog(parent),
    ui(new Ui::TimeAssignmentDialog)
{
    ui->setupUi(this);

    ui->comboBoxProject->setModel(&projectsModel);

    for(const auto &text : settings.texts())
        ui->comboBoxText->addItem(text);
    ui->comboBoxText->clearEditText();
}

TimeAssignmentDialog::~TimeAssignmentDialog()
{
    delete ui;
}

QTime TimeAssignmentDialog::getTime() const
{
    return ui->timeEditTime->time();
}

void TimeAssignmentDialog::setTime(const QTime &time)
{
    ui->timeEditTime->setTime(time);
}

QTime TimeAssignmentDialog::getTimespan() const
{
    return ui->timeEditTimespan->time();
}

void TimeAssignmentDialog::setTimespan(const QTime &timespan)
{
    ui->timeEditTimespan->setTime(timespan);
}

QString TimeAssignmentDialog::getProject() const
{
    return ui->comboBoxProject->currentData(Qt::UserRole).toString();
}

QString TimeAssignmentDialog::getWorkpackage() const
{
    return ui->comboBoxProject->currentData(Qt::EditRole).toString();
}

void TimeAssignmentDialog::setProject(const QString &project, const QString &workpackage)
{
    qCritical() << "not implemented";
}

QString TimeAssignmentDialog::getText() const
{
    return ui->comboBoxText->currentText();
}

void TimeAssignmentDialog::setText(const QString &text)
{
    ui->comboBoxText->setCurrentText(text);
}
