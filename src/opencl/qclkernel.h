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

#ifndef QCLKERNEL_H
#define QCLKERNEL_H

#include "qclglobal.h"
#include "qclevent.h"
#include "qclworksize.h"
#include <QtCore/qstring.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qtconcurrentrun.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(CL)

class QCLContext;
class QCLProgram;
class QCLMemoryObject;
class QCLVectorBase;
class QCLSampler;
class QCLDevice;
class QVector2D;
class QVector3D;
class QVector4D;
class QMatrix4x4;
class QPoint;
class QPointF;
class QColor;

class QCLKernelPrivate;

class Q_CL_EXPORT QCLKernel
{
public:
    QCLKernel();
    QCLKernel(QCLContext *context, cl_kernel id);
    QCLKernel(const QCLKernel &other);
    ~QCLKernel();

    QCLKernel &operator=(const QCLKernel &other);

    bool isNull() const;

    bool operator==(const QCLKernel &other) const;
    bool operator!=(const QCLKernel &other) const;

    cl_kernel kernelId() const;
    QCLContext *context() const;

    QCLProgram program() const;
    QString name() const;
    int argCount() const;

    QCLWorkSize declaredWorkGroupSize() const;
    QCLWorkSize declaredWorkGroupSize(const QCLDevice &device) const;

    QCLWorkSize globalWorkSize() const;
    void setGlobalWorkSize(const QCLWorkSize &size);
    void setGlobalWorkSize(size_t width, size_t height);
    void setGlobalWorkSize(size_t width, size_t height, size_t depth);

    QCLWorkSize localWorkSize() const;
    void setLocalWorkSize(const QCLWorkSize &size);
    void setLocalWorkSize(size_t width, size_t height);
    void setLocalWorkSize(size_t width, size_t height, size_t depth);

    QCLWorkSize bestLocalWorkSizeImage2D() const;
    QCLWorkSize bestLocalWorkSizeImage3D() const;

    size_t preferredWorkSizeMultiple() const;

    void setArg(int index, cl_int value);
    void setArg(int index, cl_uint value);
    void setArg(int index, cl_long value);
    void setArg(int index, cl_ulong value);
    void setArg(int index, float value);
    void setArg(int index, const QVector2D &value);
    void setArg(int index, const QVector3D &value);
    void setArg(int index, const QVector4D &value);
    void setArg(int index, const QColor &value);
    void setArg(int index, Qt::GlobalColor value);
    void setArg(int index, const QPoint &value);
    void setArg(int index, const QPointF &value);
    void setArg(int index, const QMatrix4x4 &value);
    void setArg(int index, const QCLMemoryObject &value);
#if defined(qdoc)
    void setArg(int index, const QCLVector<T> &value);
#else
    void setArg(int index, const QCLVectorBase &value);
#endif
    void setArg(int index, const QCLSampler &value);
    void setArg(int index, const void *data, size_t size);

    QCLEvent run();
    QCLEvent run(const QCLEventList &after);

    inline QCLEvent operator()() { return run(); }

    template <typename T1>
    inline QCLEvent operator()(const T1 &arg1)
    {
        setArg(0, arg1);
        return run();
    }

    template <typename T1, typename T2>
    inline QCLEvent operator()(const T1 &arg1, const T2 &arg2)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        return run();
    }

    template <typename T1, typename T2, typename T3>
    inline QCLEvent operator()
        (const T1 &arg1, const T2 &arg2, const T3 &arg3)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        setArg(2, arg3);
        return run();
    }

    template <typename T1, typename T2, typename T3, typename T4>
    inline QCLEvent operator()
        (const T1 &arg1, const T2 &arg2, const T3 &arg3, const T4 &arg4)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        setArg(2, arg3);
        setArg(3, arg4);
        return run();
    }

    template <typename T1, typename T2, typename T3, typename T4,
              typename T5>
    inline QCLEvent operator()
        (const T1 &arg1, const T2 &arg2, const T3 &arg3, const T4 &arg4,
         const T5 &arg5)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        setArg(2, arg3);
        setArg(3, arg4);
        setArg(4, arg5);
        return run();
    }

    template <typename T1, typename T2, typename T3, typename T4,
              typename T5, typename T6>
    inline QCLEvent operator()
        (const T1 &arg1, const T2 &arg2, const T3 &arg3, const T4 &arg4,
         const T5 &arg5, const T6 &arg6)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        setArg(2, arg3);
        setArg(3, arg4);
        setArg(4, arg5);
        setArg(5, arg6);
        return run();
    }

    template <typename T1, typename T2, typename T3, typename T4,
              typename T5, typename T6, typename T7>
    inline QCLEvent operator()
        (const T1 &arg1, const T2 &arg2, const T3 &arg3, const T4 &arg4,
         const T5 &arg5, const T6 &arg6, const T7 &arg7)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        setArg(2, arg3);
        setArg(3, arg4);
        setArg(4, arg5);
        setArg(5, arg6);
        setArg(6, arg7);
        return run();
    }

    template <typename T1, typename T2, typename T3, typename T4,
              typename T5, typename T6, typename T7, typename T8>
    inline QCLEvent operator()
        (const T1 &arg1, const T2 &arg2, const T3 &arg3, const T4 &arg4,
         const T5 &arg5, const T6 &arg6, const T7 &arg7, const T8 &arg8)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        setArg(2, arg3);
        setArg(3, arg4);
        setArg(4, arg5);
        setArg(5, arg6);
        setArg(6, arg7);
        setArg(7, arg8);
        return run();
    }

    template <typename T1, typename T2, typename T3, typename T4,
              typename T5, typename T6, typename T7, typename T8,
              typename T9>
    inline QCLEvent operator()
        (const T1 &arg1, const T2 &arg2, const T3 &arg3, const T4 &arg4,
         const T5 &arg5, const T6 &arg6, const T7 &arg7, const T8 &arg8,
         const T9 &arg9)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        setArg(2, arg3);
        setArg(3, arg4);
        setArg(4, arg5);
        setArg(5, arg6);
        setArg(6, arg7);
        setArg(7, arg8);
        setArg(8, arg9);
        return run();
    }

    template <typename T1, typename T2, typename T3, typename T4,
              typename T5, typename T6, typename T7, typename T8,
              typename T9, typename T10>
    inline QCLEvent operator()
        (const T1 &arg1, const T2 &arg2, const T3 &arg3, const T4 &arg4,
         const T5 &arg5, const T6 &arg6, const T7 &arg7, const T8 &arg8,
         const T9 &arg9, const T10 &arg10)
    {
        setArg(0, arg1);
        setArg(1, arg2);
        setArg(2, arg3);
        setArg(3, arg4);
        setArg(4, arg5);
        setArg(5, arg6);
        setArg(6, arg7);
        setArg(7, arg8);
        setArg(8, arg9);
        setArg(9, arg10);
        return run();
    }

private:
    QScopedPointer<QCLKernelPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QCLKernel)
};

inline void QCLKernel::setGlobalWorkSize(size_t width, size_t height)
{
    setGlobalWorkSize(QCLWorkSize(width, height));
}

inline void QCLKernel::setGlobalWorkSize(size_t width, size_t height, size_t depth)
{
    setGlobalWorkSize(QCLWorkSize(width, height, depth));
}

inline void QCLKernel::setLocalWorkSize(size_t width, size_t height)
{
    setLocalWorkSize(QCLWorkSize(width, height));
}

inline void QCLKernel::setLocalWorkSize(size_t width, size_t height, size_t depth)
{
    setLocalWorkSize(QCLWorkSize(width, height, depth));
}

#ifndef QT_NO_CONCURRENT

// Convenience function definitions that make it possible to say
// QtConcurrent::run(kernel, ...) and have it do the right thing.
namespace QtConcurrent
{

inline QCLEvent run(QCLKernel &kernel)
{
    return kernel();
}
template <typename Arg1>
inline QCLEvent run(QCLKernel &kernel, const Arg1 &arg1)
{
    return kernel(arg1);
}
template <typename Arg1, typename Arg2>
inline QCLEvent run(QCLKernel &kernel, const Arg1 &arg1, const Arg2 &arg2)
{
    return kernel(arg1, arg2);
}
template <typename Arg1, typename Arg2, typename Arg3>
inline QCLEvent run(QCLKernel &kernel, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3)
{
    return kernel(arg1, arg2, arg3);
}
template <typename Arg1, typename Arg2, typename Arg3, typename Arg4>
inline QCLEvent run(QCLKernel &kernel, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4)
{
    return kernel(arg1, arg2, arg3, arg4);
}
template <typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
inline QCLEvent run(QCLKernel &kernel, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5)
{
    return kernel(arg1, arg2, arg3, arg4, arg5);
}

} // namespace QtConcurrent

#endif // QT_NO_CONCURRENT

QT_END_NAMESPACE

QT_END_HEADER

#endif
