//
// Created by user on 28.03.2024.
//
#include <iostream>
#include <numeric>
#include "../rocket/rocket.h"
void system_one(Rocket &ATAKA,std::vector<double>& dV_dT, std::vector<double>& dtetta_dT, std::vector<double>& dx_dT, std::vector<double>& dy_dT,std::vector<double>& dm_dT, int i);
void system_two(Rocket &ATAKA,std::vector<double> &dV_dT, std::vector<double>& dtetta_dT, std::vector<double>& dx_dT, std::vector<double>& dy_dT,std::vector<double>& dm_dT,int i);
double n_y(double V,double tetta,double x,double y,double i);

// полная система, объединяющая 2 режима
void system(Rocket &ATAKA ,std::vector<double>& dV_dT, std::vector<double>& dtetta_dT, std::vector<double>& dx_dT, std::vector<double>& dy_dT,std::vector<double>& dm_dT, int i){
    int steps_in_sec = 100;
    while (i <=ATAKA.get_mode_1_work_time() * steps_in_sec ){
        system_one(ATAKA,dV_dT,dtetta_dT,dx_dT,dy_dT,dm_dT,i);
        i++;
    }
    while (i <=ATAKA.get_mode_2_work_time()* steps_in_sec ){
        system_two(ATAKA,dV_dT,dtetta_dT,dx_dT,dy_dT,dm_dT,i);
        i++;
    }

}
//тут система для первого режима
void system_one(Rocket &ATAKA,std::vector<double>& dV_dT, std::vector<double>& dtetta_dT, std::vector<double>& dx_dT, std::vector<double>& dy_dT,std::vector<double>& dm_dT, int i){
    double C_x = 0.6;
    double rho = 1.2 * 100000;
    double S_m = 3.14 * (ATAKA.get_d()*ATAKA.get_d())/4;
    double S_kr = 0.07;
    double V = std::accumulate(dV_dT.begin(), dV_dT.end(), 0);// скорость (сумма изменения )
    double tetta = std::accumulate(dtetta_dT.begin(), dtetta_dT.end(), 0);// угол (сумма изменения )
    double x = std::accumulate(dx_dT.begin(),dx_dT.end(), 0);// х (сумма изменения )
    double y = std::accumulate(dy_dT.begin(),dy_dT.end(), 0);// у (сумма изменения )

    dV_dT.push_back( ATAKA.get_req_traction_1()- C_x*S_m*(rho * V*V/2) ); //изменение скорости(пушится в массив)
    dtetta_dT.push_back((9.81/V)*(n_y(V,tetta,x,y,i) - cos(tetta)));//изменение тетта (пушится в массив)
    dx_dT.push_back(V*cos(tetta));
    dy_dT.push_back(V*sin(tetta));
    dm_dT.push_back(-(ATAKA.get_req_traction_1()/ATAKA.get_I_ud_1_mode()));

};

//тут система для второго режима
void system_two(Rocket &ATAKA,std::vector<double> &dV_dT, std::vector<double>& dtetta_dT, std::vector<double>& dx_dT, std::vector<double>& dy_dT,std::vector<double>& dm_dT,int i){

};

//функция радиуса
double r(double x,double y,int i){

}

// функция перегрузки
double n_y(double V,double tetta,double x,double y,double i){
//    double r_t = ()/(r(x,y,i));// тут можно усложнить
    return

};

