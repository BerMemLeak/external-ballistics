#pragma once
#include <math.h>

class Rocket {
public:
    double get_mu_1(){
        return this->mu_1;
    }//геттер относительного запаса топлива на 1 режиме
    double get_mu_2(){
        return this->mu_2;
    }//геттер относительного запаса топлива на втором режиме
    double get_mode_1_work_time(){
        return this->mode_1_work_time;
    }//время работы на первом режиме
    double get_mode_2_work_time(){
        return this->mode_2_work_time;
    }//время работы на первом режиме
    double get_m_0(){
        return this->m_0;
    } // стартовая масса ракеты
    double get_req_fuel_mass_2(){
        return this->req_fuel_mass_2;
    } // потребная масса топлива на 2 режиме
    double get_req_fuel_mass_1(){
        return this->req_fuel_mass_1;
    } // потребная масса топлива на 1 режиме
    double get_req_fuel_full_mass(){
        return this->req_fuel_mass_1 + this->req_fuel_mass_2;
    } // потребная суммарная масса
    double get_req_traction_1(){
        return this->thrust_to_weight_ratio_1_mode * this->m_0 * 9.81;
    }//потребная тяга на первом режиме
    double get_req_traction_2(){
        return this->thrust_to_weight_ratio_2_mode *this->m_0 *9.81;
    }//потребная тяга на втором режиме
    double I_summ_req(){
        return get_req_traction_1()*mode_1_work_time + get_req_traction_2()*mode_2_work_time;
    }//суммарный потребный импульс
    double get_initial_speed(){
        return this->initial_speed;
    }

private:
    //исходники
    double d = 0.13; // диаметр в метрах
    double payload_mass = 17; //масса полезной нагрузки кг
    double warhead_mass = 5; //масса боевой части в кг
    double initial_speed = 55; //начальная скорость в м/с
    double work_speed = 560; // скорость на маршевом участке в м/с
    double constructive_coefficient_A = 0.17; // коэффициент конструктивно-массового совершенства
    double constructive_coefficient_B = 1.7; // коэффициент конструктивно-массового совершенства
    double I_ud_1_mode = 2450; // уд имп на 1 режиме
    double I_ud_2_mode = 1650; // уд имп на 1 режиме
    double full_work_time = 5; //время работы в секундах
    double thrust_to_weight_ratio_1_mode = 38; // тяговооруженность на 1 режиме
    double thrust_to_weight_ratio_2_mode = 4.5; // тяговооруженность на 2 режиме
    // вычисляем
    double mu_1 = 1-exp(-((work_speed - initial_speed)/(I_ud_1_mode))); // относительный запас топлива на 1 режиме
    double mode_1_work_time = (mu_1 * I_ud_1_mode )/(thrust_to_weight_ratio_1_mode * 9.8); //время работы 1 режима в секундах
    double mode_2_work_time = full_work_time-mode_1_work_time;//время работы 2 режима в секундах
    double mu_2 = (thrust_to_weight_ratio_2_mode * 9.81*mode_2_work_time)/(I_ud_2_mode); // относительный запас топлива на 2 режиме
    double m_0 = payload_mass/(1-constructive_coefficient_B*(mu_1+(1-mu_1)*mu_2));  //стартовая масса ракеты без вышибного заряда
    double req_fuel_mass_2 = m_0 * mu_2 * (1 - mu_1);
    double req_fuel_mass_1 = m_0 * mu_1;
};


