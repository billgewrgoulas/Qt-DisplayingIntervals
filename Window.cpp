#include "renderarea.h"
#include "Window.h"
#include "createIntervals.h"

#include <QtWidgets>

const int IdRole = Qt::UserRole;

Window::Window()
{

    int size = 10;
    createIntervals *ci = new createIntervals(size);
    dummyInterval *intervalArray = new dummyInterval[size];
    ci->getIntervals(intervalArray);

    this->renderArea = new RenderArea(intervalArray, size);
    this->newBtn = new QPushButton("Generate");
    newBtn->setMaximumWidth(100);

    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    penWidthLabel = new QLabel(tr("Pen &Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    penStyleLabel = new QLabel(tr("&Pen Style:"));
    penStyleLabel->setBuddy(penStyleComboBox);

    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
    penCapComboBox->addItem(tr("Round"), Qt::RoundCap);

    penCapLabel = new QLabel(tr("Pen &Cap:"));
    penCapLabel->setBuddy(penCapComboBox);

    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);

    penJoinLabel = new QLabel(tr("Pen &Join:"));
    penJoinLabel->setBuddy(penJoinComboBox);
//! [3]

//! [4]
    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("Linear Gradient"),
            static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem(tr("Radial Gradient"),
            static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem(tr("Conical Gradient"),
            static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem(tr("Texture"), static_cast<int>(Qt::TexturePattern));
    brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    brushStyleLabel = new QLabel(tr("&Brush:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);


    //connect buttons and dropdowns to signals
    connect(penWidthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &Window::penChanged);
    connect(penStyleComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::penChanged);
    connect(penCapComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::penChanged);
    connect(penJoinComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::penChanged);
    connect(brushStyleComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::brushChanged);
    connect(newBtn, &QPushButton::released, this, &Window::handleNewBtn);


    QGridLayout *mainLayout = new QGridLayout;
    QHBoxLayout *rowLayout = new QHBoxLayout;

    mainLayout->setColumnStretch(3, 1);

    /*mainLayout->addWidget(penStyleLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(penStyleComboBox, 4, 1);
    mainLayout->addWidget(brushStyleLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(brushStyleComboBox, 4, 3);*/

    rowLayout->addWidget(newBtn);
    rowLayout->addWidget(penStyleLabel, Qt::AlignRight);
    rowLayout->addWidget(penStyleComboBox, Qt::AlignRight);
    rowLayout->addWidget(brushStyleLabel, Qt::AlignRight);
    rowLayout->addWidget(brushStyleComboBox, Qt::AlignRight);
    mainLayout->addLayout(rowLayout, 0, 0);

    mainLayout->addWidget(renderArea, 1, 0, 1, 5);

    /*mainLayout->addWidget(penCapLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(penCapComboBox, 3, 3);
    mainLayout->addWidget(penJoinLabel, 2, 2, Qt::AlignRight);
    mainLayout->addWidget(penJoinComboBox, 2, 3);
    mainLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(penWidthSpinBox, 3, 1);*/

    setLayout(mainLayout);
    penChanged();
    brushChanged();

    setWindowTitle(tr("Basic Drawing"));
}

void Window::handleNewBtn(){

    int size = 10;
    createIntervals *ci = new createIntervals(size);
    dummyInterval *intervalArray = new dummyInterval[size];
    ci->getIntervals(intervalArray);

    this->renderArea->UpdateIntervals(intervalArray);

}

void Window::penChanged()
{
    int width = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
            penStyleComboBox->currentIndex(), IdRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(
            penCapComboBox->currentIndex(), IdRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
            penJoinComboBox->currentIndex(), IdRole).toInt());

    renderArea->setPen(QPen(Qt::blue, width, style, cap, join));
}

void Window::brushChanged()
{
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(

    brushStyleComboBox->currentIndex(), IdRole).toInt());
    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(linearGradient);
//! [14] //! [15]
    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(radialGradient);
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(conicalGradient);
    } else if (style == Qt::TexturePattern) {
        renderArea->setBrush(QBrush(QPixmap(":/images/brick.png")));
    } else {
        renderArea->setBrush(QBrush(Qt::green, style));
    }
}
