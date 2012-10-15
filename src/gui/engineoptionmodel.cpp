#include "engineoptionmodel.h"
#include "engineoptiondata.h"

EngineOptionModel::EngineOptionModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    m_columnNames << tr("Name") << tr("Default") << tr("Min") << tr("Max") << tr("Value");
}

QModelIndex EngineOptionModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid())
        return QModelIndex();
    return createIndex(row, column);
}

QModelIndex EngineOptionModel::parent(const QModelIndex &) const
{
    return QModelIndex();
}

int EngineOptionModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_pOptionDataList ? m_pOptionDataList->size() : 0;
}

int EngineOptionModel::columnCount(const QModelIndex &) const
{
    return m_columnNames.count();
}

bool EngineOptionModel::hasChildren(const QModelIndex &parent) const
{
    return !parent.isValid();
}

QVariant EngineOptionModel::data(const QModelIndex &index, int role) const
{
    if ((role != Qt::DisplayRole) || !m_pOptionDataList || !m_pValueMap)
        return QVariant();

    if (index.isValid())
    {
        const EngineOptionData* pOptionData = &m_pOptionDataList->at(index.row());
        Q_ASSERT(pOptionData);

        switch (index.column())
        {
        case 0: return pOptionData->m_name;
        case 1: return pOptionData->m_defVal;
        case 2: return pOptionData->m_minVal;
        case 3: return pOptionData->m_maxVal;
        case 4:
            {
            if (m_pValueMap->contains(pOptionData->m_name))
                return (*m_pValueMap)[pOptionData->m_name];
            }
            break;
        }
    }

    return QVariant();
}

QVariant EngineOptionModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("%1").arg(m_columnNames.at(section));
    else
        return QString("%1").arg(section);
}