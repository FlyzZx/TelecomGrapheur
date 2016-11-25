#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <qcustomplot.h>
#include "data.h"
#include "analyselexicale.h"
#include "ASyntaxique.h"
#include "evaluation.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
private slots:
  void titleDoubleClick(QMouseEvent *event);
  void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
  void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);
  void selectionChanged();
  void mousePress();
  void mouseWheel();
  void chargeGraph();
  void removeSelectedGraph();
  void removeAllGraphs();
  void contextMenuRequest(QPoint pos);
  void moveLegend();
  void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);
  void afficheErreur(char *tmp);


  void on_valider_clicked();

  void on_Nettoyer_clicked();



  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  AnalyseLexicale *aLexicale;
  ASyntaxique *aSyntaxique;
  Evaluation *evaluation;
};

#endif // MAINWINDOW_H
