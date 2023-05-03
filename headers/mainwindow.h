#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWindow>

QT_BEGIN_NAMESPACE
class QOpenGLContext;
class QOpenGLPaintDevice;
class QString;
QT_END_NAMESPACE

class MainWindow : public QWindow
{
  public:
    MainWindow(QWindow *parent = nullptr);
    MainWindow(int w, int h, QString title, QWindow *parent = nullptr);

    ~MainWindow();

  protected:
  private:
    const int defaultWidth = 600;
    const int defaultHeight = 400;

    QOpenGLContext *m_context = nullptr;
    QOpenGLPaintDevice *m_device = nullptr;
};

#endif // MAINWINDOW_H
