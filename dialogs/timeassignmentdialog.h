#pragma once

#include "zeiterfassungdialog.h"

class ProjectsModel;
class ZeiterfassungSettings;

namespace Ui { class TimeAssignmentDialog; }

class TimeAssignmentDialog : public ZeiterfassungDialog
{
    Q_OBJECT

public:
    explicit TimeAssignmentDialog(ProjectsModel &projectsModel, const ZeiterfassungSettings &settings, QWidget *parent = Q_NULLPTR);
    ~TimeAssignmentDialog();

    QTime getTime() const;
    void setTime(const QTime &time);

    QTime getTimespan() const;
    void setTimespan(const QTime &timespan);

    QString getProject() const;
    QString getWorkpackage() const;
    void setProject(const QString &project, const QString &workpackage);

    QString getText() const;
    void setText(const QString &text);

private:
    Ui::TimeAssignmentDialog *ui;
};
