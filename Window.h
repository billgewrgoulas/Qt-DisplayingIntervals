#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "dummyinterval.h"
#include <QtWidgets>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE
class RenderArea;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private slots:
    void penChanged();
    void brushChanged();
    void handleNewBtn();

private:
    RenderArea *renderArea;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QPushButton *newBtn;
};

#endif // WINDOW_H
