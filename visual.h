#ifndef VISUAL_H
#define VISUAL_H

#include <QWidget>
#include "sculptor.h"

/**
 * @brief A classe Visual - Responsável por mostrar o desenho que está sendo feito na tela
 */

class Visual : public QWidget{
    Q_OBJECT
private:
    int tamX, tamY, tamZ, tempTamX, tempTamY, tempTamZ, raio, raiox, raioy, raioz, posZ, boxX, boxY, boxZ, fig;
    float r, g, b, a=1;
    Sculptor *m;
    bool mouse;
public:
    explicit Visual(QWidget *parent = nullptr);
    /**
     * @brief paintEvent - Função responsável por desenhar na tela o desenho
     * @param event
     */
    void paintEvent(QPaintEvent *event);
    /**
     * @brief mousePressEvent - Função que desenha o objeto selecionado quando o mouse for pressionado
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);
    /**
     * @brief mouseMoveEvent - Função que desenha o objeto selecionado enquanto o mouse estiver pressionado
     * @param event
     */
    void mouseMoveEvent(QMouseEvent *event);
    /**
     * @brief mouseReleaseEvent - Função que determina quando o mouse não está sendo pressionado
     * @param event
     */
    void mouseReleaseEvent(QMouseEvent *event);
    /**
     * @brief desenho - Função que desenha o objeto selecionado
     * @param f - Determina qual objeto será desenhado
     * @param posX - Determina a posição no eixo x do objeto
     * @param posY - Determina a posição no eixo y do objeto
     */
    void desenho(int f, int posX, int posY);
    /**
     * @brief salvarDesenho - Função que salva o desenho
     * @param filename - Caminho e nome do arquivo a ser criado
     */
    void salvarDesenho(char* filename);
signals:
    /**
     * @brief clickX - Emite a posição do mouse no eixo x quando o mouse for pressionado
     */
    void clickX(int);
    /**
     * @brief clickY - Emite a posição do mouse no eixo y quando o mouse for pressionado
     */
    void clickY(int);
public slots:
    /**
     * @brief setTam - Slot que cria um novo desenho de acordo com o tamanho selecionado nos sliders
     */
    void setTam();
    /**
     * @brief tempSetTamX - Armazena temporariamente o valor do slider para o tamanho no eixo x do desenho
     * para ser utilizado caso o usuário queira criar um novo desenho
     * @param x - Tamanho no eixo x
     */
    void tempSetTamX(int x);
    /**
     * @brief tempSetTamY - Armazena temporariamente o valor do slider para o tamanho no eixo y do desenho
     * para ser utilizado caso o usuário queira criar um novo desenho
     * @param y - Tamanho no eixo y
     */
    void tempSetTamY(int y);
    /**
     * @brief tempSetTamZ - Armazena temporariamente o valor do slider para o tamanho no eixo z do desenho
     * para ser utilizado caso o usuário queira criar um novo desenho
     * @param z - Tamanho no eixo z
     */
    void tempSetTamZ(int z);
    /**
     * @brief setR - Muda o valor r da cor do objeto a ser desenhado
     * @param _r - Valor r da cor (de 0 a 255)
     */
    void setR(int _r);
    /**
     * @brief setG - Muda o valor g da cor do objeto a ser desenhado
     * @param _g - Valor g da cor (de 0 a 255)
     */
    void setG(int _g);
    /**
     * @brief setB - Muda o valor b da cor do objeto a ser desenhado
     * @param _b - Valor b da cor (de 0 a 255)
     */
    void setB(int _b);
    /**
     * @brief setRaio - Muda o tamanho do raio da esfera a ser desenhada
     * @param r - Tamanho do raio
     */
    void setRaio(int r);
    /**
     * @brief setRaioX - Muda o tamanho do raio no eixo x da elipse a ser desenhada
     * @param rx - Tamanho do raio no eixo x
     */
    void setRaioX(int rx);
    /**
     * @brief setRaioY - Muda o tamanho do raio no eixo y da elipse a ser desenhada
     * @param ry - Tamanho do raio no eixo y
     */
    void setRaioY(int ry);
    /**
     * @brief setRaioZ - Muda o tamanho do raio no eixo z da elipse a ser desenhada
     * @param rz - Tamanho do raio no eixo z
     */
    void setRaioZ(int rz);
    /**
     * @brief setZ - Muda o plano do desenho que está sendo visualizado
     * @param _z - Número do plano (de 0 a 50, porém só é válido se o espaço selecionado na criação do desenho
     * for grande o suficiente)
     */
    void setZ(int _z);
    /**
     * @brief setBoxX - Muda o tamanho no eixo x da caixa a ser desenhada
     * @param x - Tamanho da caixa no eixo x
     */
    void setBoxX(int x);
    /**
     * @brief setBoxY - Muda o tamanho no eixo y da caixa a ser desenhada
     * @param y - Tamanho da caixa no eixo y
     */
    void setBoxY(int y);
    /**
     * @brief setBoxZ - Muda o tamanho no eixo z da caixa a ser desenhada
     * @param z - Tamanho da caixa no eixo z
     */
    void setBoxZ(int z);
    /**
     * @brief getTamZ
     * @return Retorna o tamanho no eixo z do desenho
     */
    int getTamZ();
    /**
     * @brief fig0 - Seleciona a figura a ser desenhada (putVoxel)
     */
    void fig0();
    /**
     * @brief fig1 - Seleciona a figura a ser desenhada (cutVoxel)
     */
    void fig1();
    /**
     * @brief fig2 - Seleciona a figura a ser desenhada (putBox)
     */
    void fig2();
    /**
     * @brief fig3 - Seleciona a figura a ser desenhada (cutBox)
     */
    void fig3();
    /**
     * @brief fig4 - Seleciona a figura a ser desenhada (putSphere)
     */
    void fig4();
    /**
     * @brief fig5 - Seleciona a figura a ser desenhada (cutSphere)
     */
    void fig5();
    /**
     * @brief fig6 - Seleciona a figura a ser desenhada (putEllipsoid)
     */
    void fig6();
    /**
     * @brief fig7 - Seleciona a figura a ser desenhada (cutEllipsoid)
     */
    void fig7();
};

#endif // VISUAL_H
