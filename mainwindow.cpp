#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>


using namespace std;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
  srand(QDateTime::currentDateTime().toTime_t());
  ui->setupUi(this);

  ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                  QCP::iSelectLegend | QCP::iSelectPlottables);
  ui->customPlot->xAxis->setRange(-8, 8);
  ui->customPlot->yAxis->setRange(-5, 5);
  ui->customPlot->axisRect()->setupFullAxesBox();

  ui->customPlot->plotLayout()->insertRow(0);
  QCPTextElement *title = new QCPTextElement(ui->customPlot, "Télécom Grapheur", QFont("sans", 17, QFont::Bold));
  ui->customPlot->plotLayout()->addElement(0, 0, title);

  ui->customPlot->xAxis->setLabel("Axe X");
  ui->customPlot->yAxis->setLabel("Axe Y");
  ui->customPlot->legend->setVisible(true);
  QFont legendFont = font();
  legendFont.setPointSize(10);
  ui->customPlot->legend->setFont(legendFont);
  ui->customPlot->legend->setSelectedFont(legendFont);
  ui->customPlot->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items

  //initialisation erreur
  ui->erreurMessage->setVisible(false);
  ui->pushButton->setVisible(false);


  ui->customPlot->rescaleAxes();

  // connect slot that ties some axis selections together (especially opposite axes):
  connect(ui->customPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
  // connect slots that takes care that when an axis is selected, only that direction can be dragged and zoomed:
  connect(ui->customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
  connect(ui->customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));

  // make bottom and left axes transfer their ranges to top and right axes:
  connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

  // connect some interaction slots:
  connect(ui->customPlot, SIGNAL(axisDoubleClick(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)), this, SLOT(axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)));
  connect(ui->customPlot, SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)));
  connect(title, SIGNAL(doubleClicked(QMouseEvent*)), this, SLOT(titleDoubleClick(QMouseEvent*)));

  // connect slot that shows a message in the status bar when a graph is clicked:
  connect(ui->customPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));

  // setup policy and connect slot for context menu popup:
  ui->customPlot->setContextMenuPolicy(Qt::CustomContextMenu);
  connect(ui->customPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));

  this->aLexicale = new AnalyseLexicale();
  this->aSyntaxique = new ASyntaxique();
  this->evaluation = new Evaluation();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::titleDoubleClick(QMouseEvent* event)
{
  Q_UNUSED(event)
  if (QCPTextElement *title = qobject_cast<QCPTextElement*>(sender()))
  {
    // Set the plot title by double clicking on it
    bool ok;
    QString newTitle = QInputDialog::getText(this, "QCustomPlot example", "New plot title:", QLineEdit::Normal, title->text(), &ok);
    if (ok)
    {
      title->setText(newTitle);
      ui->customPlot->replot();
    }
  }
}

void MainWindow::axisLabelDoubleClick(QCPAxis *axis, QCPAxis::SelectablePart part)
{
  // Set an axis label by double clicking on it
  if (part == QCPAxis::spAxisLabel) // only react when the actual axis label is clicked, not tick label or axis backbone
  {
    bool ok;
    QString newLabel = QInputDialog::getText(this, "QCustomPlot example", "New axis label:", QLineEdit::Normal, axis->label(), &ok);
    if (ok)
    {
      axis->setLabel(newLabel);
      ui->customPlot->replot();
    }
  }
}


void MainWindow::legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item)
{
  // Rename a graph by double clicking on its legend item
  Q_UNUSED(legend)
  if (item) // only react if item was clicked (user could have clicked on border padding of legend where there is no item, then item is 0)
  {
    QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem*>(item);
    bool ok;
    QString newName = QInputDialog::getText(this, "QCustomPlot example", "New graph name:", QLineEdit::Normal, plItem->plottable()->name(), &ok);
    if (ok)
    {
      plItem->plottable()->setName(newName);
      ui->customPlot->replot();
    }
  }
}

void MainWindow::selectionChanged()
{
  /*
   normally, axis base line, axis tick labels and axis labels are selectable separately, but we want
   the user only to be able to select the axis as a whole, so we tie the selected states of the tick labels
   and the axis base line together. However, the axis label shall be selectable individually.

   The selection state of the left and right axes shall be synchronized as well as the state of the
   bottom and top axes.

   Further, we want to synchronize the selection of the graphs with the selection state of the respective
   legend item belonging to that graph. So the user can select a graph by either clicking on the graph itself
   or on its legend item.
  */

  // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      ui->customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
  {
    ui->customPlot->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    ui->customPlot->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }
  // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      ui->customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
  {
    ui->customPlot->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    ui->customPlot->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }

  // synchronize selection of graphs with selection of corresponding legend items:
  for (int i=0; i<ui->customPlot->graphCount(); ++i)
  {
    QCPGraph *graph = ui->customPlot->graph(i);
    QCPPlottableLegendItem *item = ui->customPlot->legend->itemWithPlottable(graph);
    if (item->selected() || graph->selected())
    {
      item->setSelected(true);
      graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
    }
  }
}

void MainWindow::mousePress()
{
  // if an axis is selected, only allow the direction of that axis to be dragged
  // if no axis is selected, both directions may be dragged
if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->xAxis->orientation());
  else if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->yAxis->orientation());
  else
    ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void MainWindow::mouseWheel()
{
  // if an axis is selected, only allow the direction of that axis to be zoomed
  // if no axis is selected, both directions may be zoomed

  if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->xAxis->orientation());
  else if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->yAxis->orientation());
  else
    ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}

void MainWindow::chargeGraph()
{
  //Bornes min max
  double xmin = ui->xMin->value();
  double xmax = ui->xMax->value();
  double ymin = ui->yMin->value();
  double ymax = ui->yMax->value();

  //Chaine d'entrée
  string inputString = ui->expression->text().toStdString();

  vector<Jeton> jetonTab = aLexicale->aToken(inputString);
  if(jetonTab.size() != 0) {
      vector<Erreur> errTab = aSyntaxique->checkSyntax(jetonTab);
      if(errTab.size() == 0) {
          jetonTab = aSyntaxique->setPriorite(jetonTab);
          //Gestion des erreurs de bornes
          if(xmin>=xmax || ymin>=ymax){
                Erreur e1;
                e1.codeErreur=ERR401;
                e1.message="Vérifiez vos bornes ...";
                listeErreurs.push_back(e1);
          }
          else{

                  ui->customPlot->xAxis->setRange(xmin-1, xmax+1);
                  ui->customPlot->yAxis->setRange(ymin-1, ymax+1);

                  //Calcul du nombre de pas à dessiner
                  float precision = ui->precision->value();
                  double taille = (xmax-xmin)/precision;

                  QVector<double> x((int)taille * (1/precision) + 1);
                  QVector<double> y((int)taille * (1/precision) + 1);

                  int k=0;
                  for (double i=xmin; i<xmax+1; i+=precision)
                  {
                    Noeud *racine = aSyntaxique->creerArbre(jetonTab);
                    x[k] = i;
                    y[k] = this->evaluation->evaluation(racine, i);
                    k++;
                  }
                  vector<Erreur> errEval = this->evaluation->getErreurs();
                  if(errEval.size() > 0) {
                      for(int i = 0; i < errEval.size(); i++) {
                          listeErreurs.push_back(errEval[i]);
                      }
                  }
                  QVector<double> x1(k);
                  QVector<double> y1(k);
                  for(int j=0;j<k;j++){
                      x1[j]=x[j];
                      y1[j]=y[j];
                  }

                  ui->customPlot->addGraph();
                  ui->customPlot->graph()->setName(QString("Y = " + ui->expression->text()).arg(ui->customPlot->graphCount()-1));
                  ui->customPlot->graph()->setData(x1, y1);

                  //style du graphique
                  ui->customPlot->graph()->setLineStyle((QCPGraph::LineStyle)(1));
                  //if (rand()%100 > 50)

                  //style du point
                  ui->customPlot->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(1)));
                  QPen graphPen;
                  graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
                  graphPen.setWidthF(rand()/(double)RAND_MAX*2+1);
                  ui->customPlot->graph()->setPen(graphPen);
                  ui->customPlot->replot();
              }
      } else {
          for(int i = 0; i < errTab.size(); i++) {
              listeErreurs.push_back(errTab[i]);
          }
      }
  }
}




void MainWindow::removeSelectedGraph()
{
  if (ui->customPlot->selectedGraphs().size() > 0)
  {
    ui->customPlot->removeGraph(ui->customPlot->selectedGraphs().first());
    ui->customPlot->replot();
  }
}

void MainWindow::removeAllGraphs()
{
  ui->customPlot->clearGraphs();
  ui->customPlot->replot();
}

void MainWindow::contextMenuRequest(QPoint pos)
{
  QMenu *menu = new QMenu(this);
  menu->setAttribute(Qt::WA_DeleteOnClose);

  //Menu contextuel sur la légende
  if (ui->customPlot->legend->selectTest(pos, false) >= 0)
  {
    menu->addAction("Placer dans le coin supérieur gauche", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignLeft));
    menu->addAction("Placer au centre", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
    menu->addAction("Placer dans le coin supérieur droit", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignRight));
    menu->addAction("Placer dans le coin inférieure droit", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignRight));
    menu->addAction("Placer dans le coin inférieure gauche", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
  }
  else
  {//Menu contextuel sur les courbes
    if (ui->customPlot->selectedGraphs().size() > 0)
      menu->addAction("Supprimer la courbe sélectionnée", this, SLOT(removeSelectedGraph()));
    if (ui->customPlot->graphCount() > 0)
      menu->addAction("Supprimer toutes les courbes", this, SLOT(removeAllGraphs()));
  }

  menu->popup(ui->customPlot->mapToGlobal(pos));
}

void MainWindow::moveLegend()
{
  if (QAction* contextAction = qobject_cast<QAction*>(sender())) // make sure this slot is really called by a context menu action, so it carries the data we need
  {
    bool ok;
    int dataInt = contextAction->data().toInt(&ok);
    if (ok)
    {
      ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment)dataInt);
      ui->customPlot->replot();
    }
  }
}

void MainWindow::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
  // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
  // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
  double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
  QString message = QString("Clicked on graph '%1' at data point #%2 with value %3.").arg(plottable->name()).arg(dataIndex).arg(dataValue);
  ui->statusBar->showMessage(message, 2500);
}

void MainWindow::on_valider_clicked()
{
    listeErreurs.clear();
    chargeGraph();
    if(listeErreurs.size()!=0)
        for(int i=0;i<listeErreurs.size();i++){
            char tmpC[100];
             sprintf(tmpC, "%d", listeErreurs[i].codeErreur);
             strcat(tmpC," erreur : ");
             strcat(tmpC,listeErreurs[i].message);
            afficheErreur(tmpC);
        }
}

void MainWindow::afficheErreur(char *tmp){

    ui->erreurMessage->setText(tmp);
    ui->erreurMessage->setStyleSheet("QLabel {  color : red;}");
    ui->erreurMessage->setVisible(true);
    ui->pushButton->setVisible(true);
}

void MainWindow::on_Nettoyer_clicked()
{
    removeAllGraphs();
}

void MainWindow::on_pushButton_clicked()
{
    ui->erreurMessage->setVisible(false);
    ui->pushButton->setVisible(false);
}
