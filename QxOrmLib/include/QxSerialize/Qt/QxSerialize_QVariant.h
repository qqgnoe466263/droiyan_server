/****************************************************************************
**
** http://www.qxorm.com/
** Copyright (C) 2013 Lionel Marty (contact@qxorm.com)
**
** This file is part of the QxOrm library
**
** This software is provided 'as-is', without any express or implied
** warranty. In no event will the authors be held liable for any
** damages arising from the use of this software
**
** Commercial Usage
** Licensees holding valid commercial QxOrm licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Lionel Marty
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file 'license.gpl3.txt' included in the
** packaging of this file. Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met : http://www.gnu.org/copyleft/gpl.html
**
** If you are unsure which license is appropriate for your use, or
** if you have questions regarding the use of this file, please contact :
** contact@qxorm.com
**
****************************************************************************/

#ifdef _QX_ENABLE_BOOST_SERIALIZATION
#ifndef _QX_SERIALIZE_QVARIANT_H_
#define _QX_SERIALIZE_QVARIANT_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/nvp.hpp>

#include <QtCore/qvariant.h>

#include <QxSerialize/Qt/QxSerialize_QString.h>
#include <QxSerialize/Qt/QxSerialize_QDate.h>
#include <QxSerialize/Qt/QxSerialize_QDateTime.h>
#include <QxSerialize/Qt/QxSerialize_QTime.h>
#include <QxSerialize/Qt/QxSerialize_QByteArray.h>
#include <QxSerialize/Qt/QxSerialize_QBrush.h>
#include <QxSerialize/Qt/QxSerialize_QColor.h>
#include <QxSerialize/Qt/QxSerialize_QFont.h>
#include <QxSerialize/Qt/QxSerialize_QImage.h>
#include <QxSerialize/Qt/QxSerialize_QPixmap.h>
#include <QxSerialize/Qt/QxSerialize_QPoint.h>
#include <QxSerialize/Qt/QxSerialize_QRect.h>
#include <QxSerialize/Qt/QxSerialize_QRegExp.h>
#include <QxSerialize/Qt/QxSerialize_QRegion.h>
#include <QxSerialize/Qt/QxSerialize_QSize.h>
#include <QxSerialize/Qt/QxSerialize_QUrl.h>

#include <QxSerialize/QxSerializeFastCompil.h>

BOOST_CLASS_VERSION(QVariant, 0)

QX_SERIALIZE_FAST_COMPIL_SAVE_LOAD_HPP(QX_DLL_EXPORT, QVariant)

#endif // _QX_SERIALIZE_QVARIANT_H_
#endif // _QX_ENABLE_BOOST_SERIALIZATION