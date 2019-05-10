#ifndef MAGICPOOL_H
#define MAGICPOOL_H

#include "magicfish.h"
#include <QPainterPath>
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT MagicPool : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(bool moving READ moving CONSTANT)
    Q_PROPERTY(QColor fishHeadColor READ getFishHeadColor WRITE setFishHeadColor)
    Q_PROPERTY(QColor fishBodyColor READ getFishBodyColor WRITE setFishBodyColor)
    Q_PROPERTY(QColor fishFinColor READ getFishFinColor WRITE setFishFinColor)
    Q_PROPERTY(QColor fishTailColor READ getFishTailColor WRITE setFishTailColor)
public:
    MagicPool(QWidget *parent = nullptr);

    bool moving() const { return m_moving; }

    QColor getFishHeadColor() const;
    void setFishHeadColor(const QColor &fishHeadColor);

    QColor getFishBodyColor() const;
    void setFishBodyColor(const QColor &fishBodyColor);

    QColor getFishFinColor() const;
    void setFishFinColor(const QColor &fishFinColor);

    QColor getFishTailColor() const;
    void setFishTailColor(const QColor &fishTailColor);

public slots:
    void updateValue();
    void updateMove();
    void moveFish(qreal x, qreal y, bool hasCircle);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;
private:
    qreal calcIncludedAngle(const QPointF &center, const QPointF &head, const QPointF &touch);
    QPointF calcPoint(const QPointF &pos, qreal length, qreal angle);
    qreal getLength(const QPointF &pos1, const QPointF &pos2);
    void randomMove();

    /**
     * @brief 返回[0~1)之间的伪随机数，返回值为double类型
     */
    double getRandom() const;
private:
    bool m_moving;
    bool m_startCircle;
    QTimer *m_circleTimer;
    QTimer *m_moveTimer;
    int m_circleRadius;
    int m_circleAlpha;
    QPointF m_pos;

    MagicFish *m_fish;

    QPainterPath m_path;
    qreal m_moveStep;
};

#endif // MAGICPOOL_H
