#include "histogramplot.h"

#include <qwt_plot_layout.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_renderer.h>
#include <qwt_legend.h>
#include <qwt_legend_label.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>
#include <qpen.h>

#include <QString>
#include <iostream>
using namespace std;
class Histogram: public QwtPlotHistogram
{
public:
    Histogram( const QString &, const QColor & );

    void setColor( const QColor & );
    void setValues( uint numValues, const double *,map<float,int>  );
};

Histogram::Histogram( const QString &title, const QColor &symbolColor ):
    QwtPlotHistogram( title )
{
    setStyle( QwtPlotHistogram::Columns );

    setColor( symbolColor );
}

void Histogram::setColor( const QColor &color )
{
    QColor c = color;
    c.setAlpha( 180 );
    setBrush( QBrush( c ) );
}

void Histogram::setValues( uint numValues, const double *values,map <float,int> mp )
{
    QVector<QwtIntervalSample> samples( numValues );

    vector <double> vec;
    for (auto v:mp)
    {
        vec.push_back(v.first);
    }

    for(int i=0;i<numValues-1;i++)
    {
        QwtInterval interval( double( vec[i] ), vec[i+1] );
        interval.setBorderFlags( QwtInterval::ExcludeMaximum );

        samples[i] = QwtIntervalSample( values[i], interval );

    }


    setData( new QwtIntervalSeriesData( samples ) );
}

 HistogramPlot::HistogramPlot( QWidget *parent ,  string xbottom,map<float,int> mp):
    QwtPlot( parent )
{



    this->mp = mp;
   setTitle("Histogram");

    QwtPlotCanvas *canvas = new QwtPlotCanvas();
    canvas->setPalette( Qt::gray );
    canvas->setBorderRadius( 10 );
    setCanvas( canvas );

    plotLayout()->setAlignCanvasToScales( true );

    setAxisTitle( QwtPlot::yLeft,"Frequency");
    setAxisTitle( QwtPlot::xBottom, QString::fromStdString(xbottom));

    QwtLegend *legend = new QwtLegend;
    legend->setDefaultItemMode( QwtLegendData::Checkable );
    insertLegend( legend, QwtPlot::RightLegend );

    populate();

    connect( legend, SIGNAL( checked( const QVariant &, bool, int ) ),
        SLOT( showItem( const QVariant &, bool ) ) );

    replot(); // creating the legend items


    setAutoReplot( true );
}

void HistogramPlot::populate()
{
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableX( false );
    grid->enableY( true );
    grid->enableXMin( false );
    grid->enableYMin( false );
    grid->setMajorPen( Qt::black, 0, Qt::DotLine );
    grid->attach( this );

    double values[10000];
  int i=0;
  for (auto v:mp)
  {
    values[i] = v.second;
    i++;
  }

    Histogram *histogramPlost = new Histogram( "", Qt::red );
    histogramPlost->setValues(
        mp.size(), values ,mp);
    histogramPlost->attach( this );

}

void HistogramPlot::showItem( const QVariant &itemInfo, bool on )
{
    QwtPlotItem *plotItem = infoToItem( itemInfo );
    if ( plotItem )
        plotItem->setVisible( on );
}

