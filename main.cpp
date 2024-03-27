// Параша по расчету внешней баллистики Атаки. Она двухрежимная, бог знает какая схема, утка вроде
// задачу стараюсь выполнить в ООП, чтобы было красиво, но всякого полиморфизма тут не ждите, в падлу думать.
//Класс ракеты в одноименном файле, в нем также некая инструкиция по использованию и обозначения
#include <iostream>
#include "rocket/rocket.h"
#include "system/system.cpp"
int main(){
    Rocket ATAKA;
    std::cout <<"отн запас топлива для 1 режима: "<< ATAKA.get_mu_1()<< std::endl;
    std::cout <<"время работы на 1 режиме: "<< ATAKA.get_mode_1_work_time()<< std::endl;
    std::cout <<"время работы на 2 режиме: "<< ATAKA.get_mode_2_work_time()<< std::endl;
    std::cout<<"отн запас топлива для 2 режима: "<<  ATAKA.get_mu_2()<< std::endl;
    std::cout <<"стартовая масса: "<< ATAKA.get_m_0()<< std::endl;
    std::cout <<"потребная масса топлива на 1 режиме: "<< ATAKA.get_req_fuel_mass_1()<< std::endl;
    std::cout <<"потребная масса топлива на 2 режиме: "<< ATAKA.get_req_fuel_mass_2()<< std::endl;
    std::cout <<"потребная масса топлива суммарная: "<< ATAKA.get_req_fuel_full_mass()<< std::endl;
    std::cout <<"потребная тяга на 1 режиме "<< ATAKA.get_req_traction_1()<< std::endl;
    std::cout <<"потребная тяга на 2 режиме "<< ATAKA.get_req_traction_2()<< std::endl;
    std::cout <<"суммарный потребный импульс "<< ATAKA.I_summ_req()<< std::endl;
//     вызов функции, решающая систему уравнений и выводящая графики
    system(ATAKA);
    return 0;
}