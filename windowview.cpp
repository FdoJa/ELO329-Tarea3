#include "windowview.h"
#include <QBrush>

WindowView::WindowView(int x, int y, int angle, MagneticSensorView * mv){
    makeWindowView();
    mv->setParentItem(this);
    installMagneticSensor(*mv);
    magnet = &(mv->getMagnetView());
    QTransform transform;
    transform.translate(x,y);
    transform.rotate(angle);
    setTransform(transform);
}

void WindowView::makeWindowView() {
    QGraphicsRectItem * origenPillar = new QGraphicsRectItem(0, 0, 20, 20, this);
    origenPillar->setBrush(Qt::blue);

    switchPillar = new QGraphicsRectItem(180, 0, 20, 20, this);
    switchPillar->setBrush(Qt::blue);

    QGraphicsRectItem * fixedGlas = new QGraphicsRectItem(21, 4, 82, 6, this);
    fixedGlas->setBrush(Qt::lightGray);

    windowPanel = new QGraphicsRectItem(97, 11, 82, 6, this);
    windowPanel->setBrush(Qt::lightGray);

    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(fixedGlas);
    addToGroup(windowPanel);
}

void WindowView::setWindowModel(Window *m){
    model=m;
}

void WindowView::installMagneticSensor(MagneticSensorView & mv){
    mv.getMagnetView().setRect(windowPanel->rect().right()-mv.getMagnetView().rect().width(),
                               windowPanel->rect().bottom(),
                               mv.getMagnetView().rect().width(),
                               mv.getMagnetView().rect().height());

    mv.getSwitchView().setRect(switchPillar->boundingRect().x()+switchPillar->boundingRect().width()/2-10,
                               switchPillar->boundingRect().height(),
                               mv.getSwitchView().rect().width(),
                               mv.getSwitchView().rect().height());

    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}

void WindowView::setOpen() {
    qreal slideDistance = 82; // Distancia que la ventanaPanel debe deslizarse hacia la derecha
    windowPanel->setPos(windowPanel->x() + slideDistance, windowPanel->y());
    magnet->setPos(windowPanel->x(), windowPanel->y());
}

void WindowView::setClose() {
    qreal slideDistance = 82; // Distancia que la ventanaPanel debe deslizarse hacia la izquierda
    windowPanel->setPos(windowPanel->x() - slideDistance, windowPanel->y());
    magnet->setPos(windowPanel->x(), windowPanel->y());
}

void WindowView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}

WindowView::~WindowView(){
    delete windowPanel;
    delete switchPillar;
}
