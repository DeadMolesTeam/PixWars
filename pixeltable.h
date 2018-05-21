#ifndef PIXELTABLE_H
#define PIXELTABLE_H

#include <QObject>
#include <QQmlListProperty>
#include <qpix.h>
#include <string>

class PixelTable : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Qpix> data READ data NOTIFY dataChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_CLASSINFO("DefaultProperty", "data")
public:
    PixelTable(QObject *parent = nullptr);

    Q_INVOKABLE void getField(QString url);

    QQmlListProperty<Qpix> data();

    Q_INVOKABLE void add(unsigned int id);
    Q_INVOKABLE void setQpixById(QString url, unsigned int id, const unsigned new_color);

    void setQpixById(unsigned int id, const unsigned new_color, time_t unlock_time);
    Q_INVOKABLE void checkPixels(QString url);

    Q_INVOKABLE QString unblockQpixIn(unsigned int id);

    int count() const;

signals:
    void dataChanged();
    void countChanged();

public slots:

private:
    static void appendData(QQmlListProperty<Qpix> *list, Qpix *value);
    static int countData(QQmlListProperty<Qpix> *list);
    static Qpix *atData(QQmlListProperty<Qpix> *list, int index);
    static void clearData(QQmlListProperty<Qpix> *list);

    QList<Qpix*> listPixels;

public slots:
    void getPixelsSlot();
    void paintPixelSlot();
    void updatePixelsSlot();
};

#endif // PIXELTABLE_H
