/****************************************************************************
** Meta object code from reading C++ file 'FTPClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FTPClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FTPClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FTPClient_t {
    QByteArrayData data[45];
    char stringdata0[986];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FTPClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FTPClient_t qt_meta_stringdata_FTPClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FTPClient"
QT_MOC_LITERAL(1, 10, 26), // "slotActionConnectTriggered"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 29), // "slotActionDisconnectTriggered"
QT_MOC_LITERAL(4, 68, 23), // "slotActionQuitTriggered"
QT_MOC_LITERAL(5, 92, 28), // "slotPushButtonConnectClicked"
QT_MOC_LITERAL(6, 121, 31), // "slotPushButtonDisconnectClicked"
QT_MOC_LITERAL(7, 153, 27), // "slotPushButtonUploadClicked"
QT_MOC_LITERAL(8, 181, 29), // "slotPushButtonDownloadClicked"
QT_MOC_LITERAL(9, 211, 35), // "slotPushButtonParentDirLocalC..."
QT_MOC_LITERAL(10, 247, 36), // "slotPushButtonParentDirRemote..."
QT_MOC_LITERAL(11, 284, 32), // "slotPushButtonRenameLocalClicked"
QT_MOC_LITERAL(12, 317, 32), // "slotPushButtonDeleteLocalClicked"
QT_MOC_LITERAL(13, 350, 33), // "slotPushButtonRenameRemoteCli..."
QT_MOC_LITERAL(14, 384, 33), // "slotPushButtonDeleteRemoteCli..."
QT_MOC_LITERAL(15, 418, 34), // "slotListWidgetFileLocalItemCl..."
QT_MOC_LITERAL(16, 453, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(17, 470, 4), // "item"
QT_MOC_LITERAL(18, 475, 40), // "slotListWidgetFileLocalItemDo..."
QT_MOC_LITERAL(19, 516, 34), // "slotLineEditPathLocalReturnPr..."
QT_MOC_LITERAL(20, 551, 35), // "slotListWidgetFileRemoteItemC..."
QT_MOC_LITERAL(21, 587, 41), // "slotListWidgetFileRemoteItemD..."
QT_MOC_LITERAL(22, 629, 35), // "slotLineEditPathRemoteReturnP..."
QT_MOC_LITERAL(23, 665, 22), // "slotFtpCommandFinished"
QT_MOC_LITERAL(24, 688, 2), // "id"
QT_MOC_LITERAL(25, 691, 5), // "error"
QT_MOC_LITERAL(26, 697, 21), // "slotFtpCommandStarted"
QT_MOC_LITERAL(27, 719, 27), // "slotFtpDataTransferProgress"
QT_MOC_LITERAL(28, 747, 4), // "done"
QT_MOC_LITERAL(29, 752, 5), // "total"
QT_MOC_LITERAL(30, 758, 11), // "slotFtpDone"
QT_MOC_LITERAL(31, 770, 15), // "slotFtpListInfo"
QT_MOC_LITERAL(32, 786, 8), // "QUrlInfo"
QT_MOC_LITERAL(33, 795, 1), // "i"
QT_MOC_LITERAL(34, 797, 22), // "slotFtpRawCommandReply"
QT_MOC_LITERAL(35, 820, 9), // "replyCode"
QT_MOC_LITERAL(36, 830, 6), // "detail"
QT_MOC_LITERAL(37, 837, 16), // "slotFtpReadyRead"
QT_MOC_LITERAL(38, 854, 19), // "slotFtpStateChanged"
QT_MOC_LITERAL(39, 874, 5), // "state"
QT_MOC_LITERAL(40, 880, 15), // "slotFtpLoggedIn"
QT_MOC_LITERAL(41, 896, 21), // "slotFtpUploadFinished"
QT_MOC_LITERAL(42, 918, 23), // "slotFtpDownloadFinished"
QT_MOC_LITERAL(43, 942, 21), // "slotFtpRenameFinished"
QT_MOC_LITERAL(44, 964, 21) // "slotFtpDeleteFinished"

    },
    "FTPClient\0slotActionConnectTriggered\0"
    "\0slotActionDisconnectTriggered\0"
    "slotActionQuitTriggered\0"
    "slotPushButtonConnectClicked\0"
    "slotPushButtonDisconnectClicked\0"
    "slotPushButtonUploadClicked\0"
    "slotPushButtonDownloadClicked\0"
    "slotPushButtonParentDirLocalClicked\0"
    "slotPushButtonParentDirRemoteClicked\0"
    "slotPushButtonRenameLocalClicked\0"
    "slotPushButtonDeleteLocalClicked\0"
    "slotPushButtonRenameRemoteClicked\0"
    "slotPushButtonDeleteRemoteClicked\0"
    "slotListWidgetFileLocalItemClicked\0"
    "QListWidgetItem*\0item\0"
    "slotListWidgetFileLocalItemDoubleClicked\0"
    "slotLineEditPathLocalReturnPressed\0"
    "slotListWidgetFileRemoteItemClicked\0"
    "slotListWidgetFileRemoteItemDoubleClicked\0"
    "slotLineEditPathRemoteReturnPressed\0"
    "slotFtpCommandFinished\0id\0error\0"
    "slotFtpCommandStarted\0slotFtpDataTransferProgress\0"
    "done\0total\0slotFtpDone\0slotFtpListInfo\0"
    "QUrlInfo\0i\0slotFtpRawCommandReply\0"
    "replyCode\0detail\0slotFtpReadyRead\0"
    "slotFtpStateChanged\0state\0slotFtpLoggedIn\0"
    "slotFtpUploadFinished\0slotFtpDownloadFinished\0"
    "slotFtpRenameFinished\0slotFtpDeleteFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FTPClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  174,    2, 0x08 /* Private */,
       3,    0,  175,    2, 0x08 /* Private */,
       4,    0,  176,    2, 0x08 /* Private */,
       5,    0,  177,    2, 0x08 /* Private */,
       6,    0,  178,    2, 0x08 /* Private */,
       7,    0,  179,    2, 0x08 /* Private */,
       8,    0,  180,    2, 0x08 /* Private */,
       9,    0,  181,    2, 0x08 /* Private */,
      10,    0,  182,    2, 0x08 /* Private */,
      11,    0,  183,    2, 0x08 /* Private */,
      12,    0,  184,    2, 0x08 /* Private */,
      13,    0,  185,    2, 0x08 /* Private */,
      14,    0,  186,    2, 0x08 /* Private */,
      15,    1,  187,    2, 0x08 /* Private */,
      18,    1,  190,    2, 0x08 /* Private */,
      19,    0,  193,    2, 0x08 /* Private */,
      20,    1,  194,    2, 0x08 /* Private */,
      21,    1,  197,    2, 0x08 /* Private */,
      22,    0,  200,    2, 0x08 /* Private */,
      23,    2,  201,    2, 0x08 /* Private */,
      26,    1,  206,    2, 0x08 /* Private */,
      27,    2,  209,    2, 0x08 /* Private */,
      30,    1,  214,    2, 0x08 /* Private */,
      31,    1,  217,    2, 0x08 /* Private */,
      34,    2,  220,    2, 0x08 /* Private */,
      37,    0,  225,    2, 0x08 /* Private */,
      38,    1,  226,    2, 0x08 /* Private */,
      40,    2,  229,    2, 0x08 /* Private */,
      41,    2,  234,    2, 0x08 /* Private */,
      42,    2,  239,    2, 0x08 /* Private */,
      43,    2,  244,    2, 0x08 /* Private */,
      44,    2,  249,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   24,   25,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   28,   29,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   35,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   24,   25,

       0        // eod
};

void FTPClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FTPClient *_t = static_cast<FTPClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotActionConnectTriggered(); break;
        case 1: _t->slotActionDisconnectTriggered(); break;
        case 2: _t->slotActionQuitTriggered(); break;
        case 3: _t->slotPushButtonConnectClicked(); break;
        case 4: _t->slotPushButtonDisconnectClicked(); break;
        case 5: _t->slotPushButtonUploadClicked(); break;
        case 6: _t->slotPushButtonDownloadClicked(); break;
        case 7: _t->slotPushButtonParentDirLocalClicked(); break;
        case 8: _t->slotPushButtonParentDirRemoteClicked(); break;
        case 9: _t->slotPushButtonRenameLocalClicked(); break;
        case 10: _t->slotPushButtonDeleteLocalClicked(); break;
        case 11: _t->slotPushButtonRenameRemoteClicked(); break;
        case 12: _t->slotPushButtonDeleteRemoteClicked(); break;
        case 13: _t->slotListWidgetFileLocalItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->slotListWidgetFileLocalItemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 15: _t->slotLineEditPathLocalReturnPressed(); break;
        case 16: _t->slotListWidgetFileRemoteItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 17: _t->slotListWidgetFileRemoteItemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 18: _t->slotLineEditPathRemoteReturnPressed(); break;
        case 19: _t->slotFtpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->slotFtpCommandStarted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->slotFtpDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 22: _t->slotFtpDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->slotFtpListInfo((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 24: _t->slotFtpRawCommandReply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 25: _t->slotFtpReadyRead(); break;
        case 26: _t->slotFtpStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->slotFtpLoggedIn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 28: _t->slotFtpUploadFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 29: _t->slotFtpDownloadFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->slotFtpRenameFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 31: _t->slotFtpDeleteFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject FTPClient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FTPClient.data,
      qt_meta_data_FTPClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FTPClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FTPClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FTPClient.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FTPClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
