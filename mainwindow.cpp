#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //srand(time(NULL));
     srand(1); //Random with a seed of 1
     if(!ui->customRunsCheckbox->isChecked()) //set checkboxes for custom run/days/period to disabled
     {
         ui->customRunsText->setEnabled(false);
         ui->customJobsText->setEnabled(false);
          ui->customTHSText->setEnabled(false);
     }

       this->runList =   vector <vector < pair <int, pair <vector<System> ,Result> >  > > (9); //A list containing all trials all minimum values and all review periods
     this->runListUnsorted =   vector <vector < pair <int, pair <vector<System> ,Result> >  > >(9);//Same list as previous list but will be unsorted to retain order
     reviewPeriod=2; //default review period

}

MainWindow::~MainWindow()
{
    delete ui;
}




//sorting comparator function for the run list
bool cmp( pair <int, pair <vector<System> ,Result> >   a ,pair <int, pair <vector<System> ,Result>   > b)
{
return a.second.second.shortageDays < b.second.second.shortageDays;
}

void MainWindow::on_beginSimulationBtn_clicked()
{

        //Probability tables
    vector <int > d ={0,1,2,3,4} ;
    vector <double> dp = {0.05, 0.28, 0.37, 0.20, 0.10};
    vector <int> l = {1,2,3};
    vector <double> lp = {0.55 , 0.35, 0.10};

    System sys = System(d,dp,l,lp,make_pair(2,5)); //System initilization

        //Check if custom parameters are selected and set them
    if(ui->customRunsCheckbox->isChecked())
    {
        runs =  ui->customRunsText->toPlainText().toInt();
        days = ui->customJobsText->toPlainText().toInt();
        minimumThreshold = ui->customTHSText->toPlainText().toInt();
    }
    else { //default parameters
        days = 100;
        runs = 30;
        minimumThreshold = 4;
    }



    Result res;
    vector <System> systems;
clear();
for(int i=1;i<=8;i++) //iterate over all minimum thresholds
{
    for(int j=1;j<=30;j++) //Try all review periods from 1 to 30
    {
        res =  Result();
        systems.clear();
        for(int k=0;k<runs;k++) //Iterate over runs and accumilate them
        {

            sys.buildSystem(days,4,2,j,i);
            res = res+sys.calculateSystem();
            systems.push_back(sys);
        }
        res = res/runs; //Calculate run averages

        runListUnsorted[i].push_back(make_pair(j,make_pair(systems,res)));
        runList[i].push_back(make_pair(j,make_pair(systems,res)));
    }
    sort(runList[i].begin(),runList[i].end(),cmp); //sort the runlist according to lowed shortages
}



ui->minimumList->clear();
  for(int i=1;i<=8;i++)
  {
      ui->minimumList->addItem("Minimum Threshold :"+QString::number(i)+ ", Minimum Shortage : "+QString::number(runList[i][0].second.second.shortageDays));
  }

display(runs,days,minimumThreshold,reviewPeriod);
}

void MainWindow::display(int runs,int days,int minimumThreshold,int reviewPeriod)
{
    //Displaying
        this->minimumThreshold = minimumThreshold;
        this->reviewPeriod = reviewPeriod;
        ui->reviewPeriodLabel->setText("Review Periods (Sorted by Shortage Days, THS : "+QString::number(minimumThreshold));
          ui->resultsLabel->setText("Results : "+QString::number(runs) +" runs, "+QString::number(days)+" Days\n"+"Minimum Threshold : "+QString::number(minimumThreshold)+", Review Period : "+QString::number(reviewPeriod));

            //Settings the table of the results
           ui->resultsTable->setItem(0,0,new QTableWidgetItem(   QString::number(2)));
           ui->resultsTable->setItem(1,0,new QTableWidgetItem(   QString::number(1.55)));
          for(int i=0;i<5;i++)
          {
              ui->resultsTable->setItem(i+2,0,new QTableWidgetItem(   QString::number(runListUnsorted[minimumThreshold][reviewPeriod-1].second.second[i])  ));
          }

          ui->resultsTable->horizontalHeader()->setVisible(false);



          ui->reviewPeriodList->clear();
            for(int i=0;i<runList[minimumThreshold].size();i++)
            {
                ui->reviewPeriodList->addItem("Review Period :"+QString::number(runList[minimumThreshold][i].first)+ " Shortage : "+QString::number(runList[minimumThreshold][i].second.second.shortageDays));
            }


            ui->dayList->clear();
              for(int i=1;i<=runs;i++)
              {
                  ui->dayList->addItem("Run :"+QString::number(i));
              }



}

void MainWindow::clear() //Clear the runlist history
{
for(int i=0;i<9;i++)
{
    runList[i].clear();
    runListUnsorted[i].clear();
}
}
void MainWindow::on_customRunsCheckbox_toggled(bool checked) //Custom parameters checkbox handler
{
    if(checked)
    {
        ui->customRunsText->setEnabled(true);
        ui->customJobsText->setEnabled(true);
        ui->customTHSText->setEnabled(true);
    }
    else {
        ui->customRunsText->setEnabled(false);
        ui->customJobsText->setEnabled(false);
        ui->customTHSText->setEnabled(false);
        ui->customRunsText->setText("");
        ui->customJobsText->setText("");
        ui->customTHSText->setText("");

    }
}


void MainWindow::on_selectMinimumThreshold_clicked() //Display info for selected minimum threshold
{

    int idx =ui->minimumList->currentIndex().row();
    if(idx!=-1)
    {
          display(runs,days,idx+1,reviewPeriod);
    }
}

void MainWindow::on_viewReviewPeriod_Btn_clicked() //Display info for selected review period
{

    int idx =ui->reviewPeriodList->currentIndex().row();
    if(idx!=-1)
    {
          display(runs,days,minimumThreshold,runList[minimumThreshold][idx].first);
    }
}

void MainWindow::on_viewRun_Btn_clicked() //View individual run data
{

    int idx =ui->dayList->currentIndex().row();
    if(idx!=-1)
    {
          runWindowObj = new runwindow(this,runListUnsorted[minimumThreshold][reviewPeriod-1].second.first[idx]);
          runWindowObj->show();
    }
}

void MainWindow::on_probability_Btn_clicked() //View probabilty and charts data
{
    vector <int > d ={0,1,2,3,4} ;
    vector <double> dp = {0.05, 0.28, 0.37, 0.20, 0.10};
    vector <int> l = {1,2,3};
    vector <double> lp = {0.55 , 0.35, 0.10};

    System system = System(d,dp,l,lp,make_pair(2,5));


      probabilityTableWindow = new probabilityTable(this,system);
      probabilityTableWindow->show();
}

void MainWindow::on_charts_Btn_clicked()
{
    chartsWindow = new ChartWindow(this,runListUnsorted[minimumThreshold][reviewPeriod].second.first);
    chartsWindow->show();
}
