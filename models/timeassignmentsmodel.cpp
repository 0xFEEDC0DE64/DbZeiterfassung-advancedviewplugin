#include "timeassignmentsmodel.h"

#include "stripswidget.h"

TimeAssignmentsModel::TimeAssignmentsModel(StripsWidget &stripsWidget, QObject *parent) :
    QAbstractListModel(parent),
    m_stripsWidget(stripsWidget)
{
    connect(&stripsWidget, &StripsWidget::timeAssignmentsChanged, this, &TimeAssignmentsModel::timeAssignmentsChanged);
    connect(&stripsWidget, &StripsWidget::refreshingTimeAssignmentsChanged, this, &TimeAssignmentsModel::refreshingChanged);
}

StripsWidget &TimeAssignmentsModel::stripsWidget() const
{
    return m_stripsWidget;
}

bool TimeAssignmentsModel::enabled() const
{
    return !m_stripsWidget.refreshingTimeAssignments();
}

int TimeAssignmentsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return m_stripsWidget.timeAssignments().count();
}

int TimeAssignmentsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return Columns::Count;
}

QVariant TimeAssignmentsModel::data(const QModelIndex &index, int role) const
{
    Q_ASSERT(index.row() < m_stripsWidget.timeAssignments().count());
    const auto &timeAssignment = m_stripsWidget.timeAssignments().at(index.row());

    switch(role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch(index.column())
        {
        case Columns::Id:          return timeAssignment.id;
        case Columns::Time:        return timeAssignment.time;
        case Columns::Timespan:    return timeAssignment.timespan;
        case Columns::Project:     return timeAssignment.project;
        case Columns::Workpackage: return timeAssignment.workpackage;
        case Columns::Text:        return timeAssignment.text;
        }
    }

    return QVariant();
}

QVariant TimeAssignmentsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch(orientation)
    {
    case Qt::Horizontal:
        switch(role)
        {
        case Qt::DisplayRole:
        case Qt::EditRole:
            switch(section)
            {
            case Columns::Id:          return tr("ID");
            case Columns::Time:        return tr("Time");
            case Columns::Timespan:    return tr("Timespan");
            case Columns::Project:     return tr("Project");
            case Columns::Workpackage: return tr("Workpackage");
            case Columns::Text:        return tr("Text");
            }
        }
    default:
        qt_noop();
    }

    return QVariant();
}

void TimeAssignmentsModel::timeAssignmentsChanged()
{
    beginResetModel();
    endResetModel();
}

void TimeAssignmentsModel::refreshingChanged(bool refreshing)
{
    Q_EMIT enabledChanged(!refreshing);
}
