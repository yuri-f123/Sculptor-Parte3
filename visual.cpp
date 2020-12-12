#include "visual.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include "sculptor.h"

Visual::Visual(QWidget *parent) : QWidget(parent){

    tamX=5; tamY=5; tamZ=5; tempTamX=1; tempTamY=1; tempTamZ=1; raio=1; raiox=1; raioy=1; raioz=1;
    posZ=0; boxX=1; boxY=1; boxZ=1;
    r=0; g=0; b=0; a=1, fig=0;
    mouse = false;
    m = new Sculptor(tamX, tamY, tamZ);
}

void Visual::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0, 0, width(), height());

    for(float i=(float)(width()/tamX); i<=width(); i=i+(float)(width()/tamX)){
        painter.drawLine(i, 0, i, height());
    }
    for(float j=(float)(height()/tamY); j<=height(); j=j+(float)(height()/tamY)){
        painter.drawLine(0, j, width(), j);
    }

    for(int i=0; i<tamX; i++){
        for(int j=0; j<tamY; j++){
            for(int k=0; k<tamZ; k++){
                if(m->isItOn(i, j, k) == 1 && posZ == k){
                    brush.setColor(QColor(m->getR(i,j,k),m->getG(i,j,k),m->getB(i,j,k)));
                    brush.setStyle(Qt::SolidPattern);
                    painter.setBrush(brush);
                    painter.drawEllipse(i*(float)(width()/tamX), j*(float)(height()/tamY), width()/tamX, height()/tamY);
                }
            }
        }
    }

}

void Visual::mousePressEvent(QMouseEvent *event){

    emit clickX(event->x());
    emit clickY(event->y());
    int posX = event->x()/(width()/tamX);
    int posY = event->y()/(height()/tamY);

    mouse = true;

    desenho(fig, posX, posY);
}

void Visual::mouseMoveEvent(QMouseEvent *event){
    emit clickX(event->x());
    emit clickY(event->y());
    int posX = event->x()/(width()/tamX);
    int posY = event->y()/(height()/tamY);

    if(mouse){
        desenho(fig, posX, posY);
    }
}

void Visual::mouseReleaseEvent(QMouseEvent *event){
    mouse = false;
}

void Visual::desenho(int f, int posX, int posY){
    switch(f){
        case 0:
            m->setColor(r/255.0, g/255.0, b/255.0, a);
            m->putVoxel(posX, posY, posZ);
            repaint();
            break;
        case 1:
            m->cutVoxel(posX, posY, posZ);
            repaint();
            break;
        case 2:
            m->setColor(r/255.0, g/255.0, b/255.0, a);
            m->putBox(posX, posX+boxX-1, posY, posY+boxY-1, posZ, posZ+boxZ-1);
            repaint();
            break;
        case 3:
            m->cutBox(posX, posX+boxX-1, posY, posY+boxY-1, posZ, posZ+boxZ-1);
            repaint();
            break;
        case 4:
            m->setColor(r/255.0, g/255.0, b/255.0, a);
            m->putSphere(posX, posY, posZ, raio);
            repaint();
            break;
        case 5:
            m->cutSphere(posX, posY, posZ, raio);
            repaint();
            break;
        case 6:
            m->setColor(r/255.0, g/255.0, b/255.0, a);
            m->putEllipsoid(posX, posY, posZ, raiox, raioy, raioz);
            repaint();
            break;
        case 7:
            m->cutEllipsoid(posX, posY, posZ, raiox, raioy, raioz);
            repaint();
            break;
    }
}

void Visual::salvarDesenho(char* filename){
    m->writeOFF(filename);
}

void Visual::setTam(){
    delete m;
    tamX = tempTamX; tamY = tempTamY; tamZ = tempTamZ;
    m = new Sculptor(tamX, tamY, tamZ);
    repaint();
}

void Visual::tempSetTamX(int x){
    tempTamX = x;
}

void Visual::tempSetTamY(int y){
    tempTamY = y;
}

void Visual::tempSetTamZ(int z){
    tempTamZ = z;
}

void Visual::setR(int _r){
    r = _r;
}

void Visual::setG(int _g){
    g = _g;
}

void Visual::setB(int _b){
    b = _b;
}

void Visual::setRaio(int r){
    raio = r;
}

void Visual::setRaioX(int rx){
    raiox = rx;
}

void Visual::setRaioY(int ry){
    raioy = ry;
}

void Visual::setRaioZ(int rz){
    raioz = rz;
}

void Visual::setZ(int _z){
    posZ = _z;
    repaint();
}

void Visual::setBoxX(int x){
    boxX = x;
}

void Visual::setBoxY(int y){
    boxY = y;
}

void Visual::setBoxZ(int z){
    boxZ = z;
}

int Visual::getTamZ(){
    return tamZ;
}

void Visual::fig0(){
    fig = 0;
}

void Visual::fig1(){
    fig = 1;
}

void Visual::fig2(){
    fig = 2;
}

void Visual::fig3(){
    fig = 3;
}

void Visual::fig4(){
    fig = 4;
}

void Visual::fig5(){
    fig = 5;
}

void Visual::fig6(){
    fig = 6;
}

void Visual::fig7(){
    fig = 7;
}
