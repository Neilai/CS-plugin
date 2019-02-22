#include "dialog.h"
#include "ui_dialog.h"
#include<iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->threadData.GameHandle = OpenProcess(PROCESS_ALL_ACCESS, 1, GetProcessID(L"cstrike.exe"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_checkBox_clicked(bool checked)
{

      if(checked){
          wall(&this->threadData);
      }
      else{
          goback(&this->threadData);
      }
}

void Dialog::on_checkBox_2_clicked(bool checked)
{
    if(checked){
        this->Thread_bullet = CreateThread(NULL, 0, bullet, &this->threadData, 0, NULL);
    }
    else{
       TerminateThread(this->Thread_bullet,0);
    }

}

void Dialog::on_checkBox_3_clicked(bool checked)
{
    if(checked){
        this->Thread_blood = CreateThread(NULL, 0, blood, &this->threadData, 0, NULL);
    }
    else{
       TerminateThread(this->Thread_blood,0);
    }
}

void Dialog::on_checkBox_4_clicked(bool checked)
{
    if(checked){
        this->Thread_fly = CreateThread(NULL, 0, fly, &this->threadData, 0, NULL);
    }
    else{
       TerminateThread(this->Thread_fly,0);
       goLand(&this->threadData);
    }
}

void Dialog::on_checkBox_5_clicked(bool checked)
{
    if(checked){
        this->Thread_down = CreateThread(NULL, 0, down, &this->threadData, 0, NULL);
    }
    else{
       TerminateThread(this->Thread_down,0);
       goLand(&this->threadData);
    }
}

void Dialog::on_checkBox_6_clicked(bool checked)
{
    if(checked){
        this->Thread_recoil = CreateThread(NULL, 0, recoil, &this->threadData, 0, NULL);
    }
    else{
       TerminateThread(this->Thread_recoil,0);
    }
}
