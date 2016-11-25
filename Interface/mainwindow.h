#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <qcustomplot.h>


typedef enum {
    FUNCTION, REEL, VARIABLE, OPERATEUR, PARENT_OPEN, PARENT_CLOSE
} Lexeme;

typedef enum {
    PLUS, MOINS, MULT, DIV
} Operateur;

typedef enum {
    SIN, COS, TAN, SQRT, LOG, LN
} Fonction;

typedef enum {
    ERR101 = 101,
    ERR102 = 102,
    ERR103 = 103,
    ERR201 = 201,
    ERR202 = 202,
    ERR203 = 203,
    ERR301 = 301,
    ERR302 = 302,
    ERR303 = 303,
    ERR304 = 304,
    ERR305 = 305,
    ERR401 = 401,
    ERR402 = 402,
    ERR403 = 403
} CodeErreur;

/* Gestion erreurs */
typedef struct {
    CodeErreur codeErreur;
    char *message;
} Erreur;

/* Partie 1 : Analyse Lexicale*/
typedef union {
    Fonction fonction;
    Operateur operateur;
    float value;
} Valeur;

typedef struct {
    Lexeme lexeme;
    Valeur valeur;
    int priorite;
} Jeton;

/* Partie 2 : Analyse Syntaxique */
typedef struct Noeud {
    Jeton jeton;
    Noeud* jeton_g;
    Noeud* jeton_d;
    Noeud* parent;
} Noeud;

/* Partie 3 : Evaluation */

/* Partie 4 : Graphique */

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
};

#endif // MAINWINDOW_H
