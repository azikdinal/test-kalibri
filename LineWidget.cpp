#include <QWidget>
#include <QPainter>

class LineWidget : public QWidget
{
    Q_OBJECT

public:
    LineWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);
        QPainter painter(this);
        QPen pen(Qt::black); // Set line color
        painter.setPen(pen);
        painter.drawLine(10, 10, width() - 10, 10); // Draw a horizontal line at y=10
    }
};
