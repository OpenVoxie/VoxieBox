#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QDateTime>
#include <QPointer>
#include <QElapsedTimer>
#include <QFile>
#include "PortListener.h"

class Widget : public QGLWidget
{
  Q_OBJECT

public:
  explicit Widget(int delay_before, int delay_after, int max_time, int num_images, QString *serial_device, QString *camera_ip, QString * image_prefix, bool interlace_levels, bool numbers,QWidget *parent = 0,QGLFormat *format=0, bool rotate = false,QString *file_list_name=0);
  ~Widget();
  enum State {Stopped = 0, Drawing, EndOfSet, WaitingAfter};
    
protected:
  void resizeGL(int width, int height);
  void perspectiveProjection();
  void paintEvent(QPaintEvent *);
  PortListener *listener;
  //  tcpClient *cam_sock;
  QString * m_serial_device;
  QString * m_camera_ip;
  QString * m_image_prefix;



private:
  QTimer * m_timer;
  QElapsedTimer * m_timespent;
  QElapsedTimer * m_timelastdraw;
  QDateTime m_startTime, m_endTime;
  QList<QPixmap> m_pixmap;
  //    QPainter * m_painter;
  int m_current;
  State m_state;
  int m_direction;
  unsigned int m_delay_before;
  unsigned int m_delay_after;
  bool m_interlace_levels;
  int m_num_images;
  unsigned int m_max_time;
  int m_total;
  unsigned char m_port_value;
  bool m_first_run;
  bool m_numbers;
  int m_curr_angle; 
  unsigned int m_draw_count;
  bool m_rotate; 
  QString *m_file_list_name;
  QFile *flist;
  bool file_list;

  qreal aspect,textx,texty;
private slots:

void startShow();
};

#endif // WIDGET_H
