//
// Created by user on 28.03.2024.
//
#include <iostream>
#include <numeric>
#include "../rocket/rocket.h"

void system_one(Rocket &ATAKA,std::vector<double> dV_dT, std::vector<double> dtetta_dT, std::vector<double> dx_dT, std::vector<double> dy_dT,std::vector<double> dm_dT, double i);
void system_two(Rocket &ATAKA,std::vector<double> dV_dT, std::vector<double> dtetta_dT, std::vector<double> dx_dT, std::vector<double> dy_dT,std::vector<double> dm_dT,double i);
void system(Rocket &ATAKA ){
    std::vector<double> dV_dT;
    dV_dT.push_back(ATAKA.get_initial_speed());
    std::vector<double> dtetta_dT;
    dV_dT.push_back(ATAKA.get_initial_speed()); // какая тетта изначальная?
    std::vector<double> dx_dT;
    dV_dT.push_back(0);
    std::vector<double> dy_dT;
    dV_dT.push_back(0);
    std::vector<double> dm_dT;
    dV_dT.push_back(ATAKA.get_m_0());

    double i = 0;
    while (i <=ATAKA.get_mode_1_work_time() ){
        system_one(ATAKA,dV_dT,dtetta_dT,dx_dT,dy_dT,dm_dT,i);
        i++;
    }
    while (i <=ATAKA.get_mode_2_work_time() ){
        system_two(ATAKA,dV_dT,dtetta_dT,dx_dT,dy_dT,dm_dT,i);
        i++;
    }
}

void system_one(Rocket &ATAKA,std::vector<double> dV_dT, std::vector<double> dtetta_dT, std::vector<double> dx_dT, std::vector<double> dy_dT,std::vector<double> dm_dT,double i){
    double C_x = 0.6;
    dV_dT[i] = ATAKA.get_req_traction_1() - C_x ; // тут с Cx какая- то залупивка + нужно добавить площадь ракеты плюс распределение плотности
    double V = std::accumulate(dV_dT.begin(), dV_dT.end(), 0);

    dtetta_dT[i] = (9.81/ V); // как лучше перегрузку взять?
};
void system_two(Rocket &ATAKA,std::vector<double> dV_dT, std::vector<double> dtetta_dT, std::vector<double> dx_dT, std::vector<double> dy_dT,std::vector<double> dm_dT,double i ){

};

