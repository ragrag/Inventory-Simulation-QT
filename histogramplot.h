#ifndef HISTOGRAMPLOT_H
#define HISTOGRAMPLOT_H

#include <qwt_plot.h>
#include <map>
#include <string>

using namespace std;
class HistogramPlot: public QwtPlot
{
    Q_OBJECT

public:
     HistogramPlot( QWidget * = NULL,string xbottom="",map<float,int> mp= map<float,int>());

public Q_SLOTS:


private:
    void populate();
    map <float,int> mp;

private Q_SLOTS:
    void showItem( const QVariant &, bool on );
};

#endif
