#ifndef MAGICFISH_H
#define MAGICFISH_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

QT_BEGIN_NAMESPACE
class QVariantAnimation;
QT_END_NAMESPACE

class QDESIGNER_WIDGET_EXPORT MagicFish : public QWidget
{
    Q_OBJECT
public:
    explicit MagicFish(QWidget *parent = nullptr);


    void setFishR(int value);
    void setCurrentAngle(qreal angle);
    void setFinAnimation(bool start);

    QPointF getHeadPos() const;

    qreal getFishR() const;
    qreal getAngle();
    QRectF geometry() const;

    void setWave(qreal value);

    QColor getHeadColor() const;
    void setHeadColor(const QColor &headColor);

    QColor getBodyColor() const;
    void setBodyColor(const QColor &bodyColor);

    QColor getFinColor() const;
    void setFinColor(const QColor &finColor);

    QColor getTailColor() const;
    void setTailColor(const QColor &tailColor);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

private:
    QPointF calcPoint(const QPointF &pos, qreal length, qreal angle);
    void paintMyPoint(QPainter *painter, const QPointF pos);
    void paintMyFishFins(QPainter *painter, const QPointF &pos, bool is_left, qreal father_angle);
    void paintMyBody(QPainter *painter, const QPointF &pos, qreal seg_r, qreal MP, qreal father_angle);
    void paintMyBody2(QPainter *painter, const QPointF &pos, qreal seg_r, qreal MP, qreal father_angle);
    void paintMyTail(QPainter *painter, const QPointF &pos, qreal length, qreal max_w, qreal angle);

private:
    qreal m_bodyHeight;
    qreal m_fishRadius; // fish head r
    qreal m_finLen;
    int m_headAlpha;
    int m_bodyAlpha;
    int m_finAlpha;
    qreal m_mainAngle;
    int m_curValue;
    qreal m_wave;

    QVariantAnimation *m_animation;
    bool m_startFin;
    bool m_paintPoint;

    QPointF m_headPos;

    QColor m_headColor;
    QColor m_bodyColor;
    QColor m_finColor;
    QColor m_tailColor;
};
#endif // MAGICFISH_H
