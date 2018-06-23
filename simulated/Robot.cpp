#include "Robot.h"

Robot::Robot(QGraphicsPixmapItem *parent, int id, bool state, int m_x, int m_y, RobotTeamColor team, Sizes size, float linear_speed, float theta_speed)
    :QObject(), QGraphicsPixmapItem(parent), id(id), state(state), m_x(m_x), m_y(m_y), team(team), size(size), linear_speed(linear_speed), theta_speed(theta_speed) {

    QString tmp = "";

    if (team == RobotTeamColor::BLUE) {

        tmp = (":/img/robots/blue_")
                + QString::number(this->size)
                + QString("x")
                + QString::number(this->size)
                + QString(".png");


    } else if (team == RobotTeamColor::YELLOW) {

        tmp = QString(":/img/robots/yellow_")
                + QString::number(this->size)
                + QString("x")
                + QString::number(this->size)
                + QString(".png");

    } else {

        tmp = QString(":/img/robots/unknow_")
                + QString::number(this->size)
                + QString("x")
                + QString::number(this->size)
                + QString(".png");

    }

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);


    setFlag(QGraphicsItem::ItemIsFocusable);
    setPixmap(QPixmap(tmp));
    setTransformOriginPoint(this->size / 2, this->size / 2);
    setRotation(this->theta_speed);
    setPos(this->m_x, this->m_y);

}

Robot::~Robot() {}


void Robot::update(int id, bool state, float linear_speed, float theta_speed) {

    this->id            = id;
    this->state         = state;
    this->linear_speed  = linear_speed;
    this->theta_speed   = theta_speed;
}

void Robot::move() {

    setRotation(this->theta_speed);

    if (this->state) {

        if (this->m_x < (Ui::FIELD_PLAYABLE_WIDTH - this->size / 2) && this->m_x > ((Ui::FIELD_PLAYABLE_WIDTH - Ui::FIELD_PLAYABLE_WIDTH) + this->size)) {
            this->m_x += (round(qCos(this->theta_speed)) * this->linear_speed);
        }
        if (this->m_y < (Ui::FIELD_PLAYABLE_HEIGHT - this->size / 2) && this->m_y > ((Ui::FIELD_PLAYABLE_HEIGHT - Ui::FIELD_PLAYABLE_HEIGHT) + this->size)) {
            this->m_y += (round(qSin(qDegreesToRadians(this->theta_speed))) * this->linear_speed);
        }

        setPos(this->m_x, this->m_y);

    } else {

        /*qDebug() << "I can't move sir, help me, am I dying? Please, I don't wanna die. Robot " << this->get_id()
                 << " is dying, err... inative.";*/
    }

}

int Robot::get_id() const {
    return this->id;
}
