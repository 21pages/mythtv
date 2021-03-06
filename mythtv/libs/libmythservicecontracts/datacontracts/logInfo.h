//////////////////////////////////////////////////////////////////////////////
// Program Name: logInfo.h
// Created     : Dec. 15, 2015
//
// Copyright (c) 2015 Bill Meek, from: 2010 David Blain <dblain@mythtv.org>
//
// Licensed under the GPL v2 or later, see COPYING for details
//
//////////////////////////////////////////////////////////////////////////////

#ifndef LOGINFO_H_
#define LOGINFO_H_

#include <QString>

#include "serviceexp.h"
#include "datacontracthelper.h"

namespace DTC
{

class SERVICE_PUBLIC LogInfo : public QObject
{
    Q_OBJECT

    Q_CLASSINFO( "version"    , "1.0" );
    Q_CLASSINFO( "defaultProp", "LogArgs" );

    Q_PROPERTY( QString  LogArgs      READ LogArgs   WRITE setLogArgs   )

    PROPERTYIMP( QString,  LogArgs   )

    public:

        static inline void InitializeCustomTypes();

    public:

        LogInfo(QObject *parent = 0)
            : QObject    ( parent ),
              m_LogArgs  ( ""     )
        {
        }

        LogInfo( const LogInfo &src )
        {
            Copy( src );
        }

        void Copy( const LogInfo &src )
        {
            m_LogArgs   = src.m_LogArgs  ;
        }
};

typedef LogInfo* LogInfoPtr;

} // namespace DTC

Q_DECLARE_METATYPE( DTC::LogInfo  )
Q_DECLARE_METATYPE( DTC::LogInfo* )

namespace DTC
{
inline void LogInfo::InitializeCustomTypes()
{
    qRegisterMetaType< LogInfo  >();
    qRegisterMetaType< LogInfo* >();
}
}

#endif
