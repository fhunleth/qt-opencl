/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtOpenCL module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

const sampler_t samp = CLK_ADDRESS_CLAMP_TO_EDGE |
                       CLK_FILTER_LINEAR;

__kernel void colorize(__read_only image2d_t srcImage,
                       __write_only image2d_t dstImage,
                       float4 color)
{
    int2 pos = (int2)(get_global_id(0), get_global_id(1));
    float4 srcColor = read_imagef(srcImage, samp, pos);
    float gray = srcColor.x * 11.0f / 32.0f +
                 srcColor.y * 16.0f / 32.0f +
                 srcColor.z * 5.0f / 32.0f;
    float4 pixel = (float4)(color.xyz * gray, srcColor.w);
    write_imagef(dstImage, pos, clamp(pixel, 0.0f, 1.0f));
}
