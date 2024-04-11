// Параша по расчету внешней баллистики Атаки. Она двухрежимная, бог знает какая схема, утка вроде
// задачу стараюсь выполнить в ООП, чтобы было красиво.
//Класс ракеты в одноименном файле, в нем также некая инструкиция по использованию и обозначения, аналогично и с классом цели.
#include <iostream>
#include "rocket/rocket.h"
#include "system/system.cpp"
#include "target/target.h"

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

    std::vector<double> dV_dT;
    dV_dT.push_back(ATAKA.get_initial_speed());
    std::vector<double> dtetta_dT;
    std::vector<double> dx_dT;
    dx_dT.push_back(0);
    std::vector<double> dy_dT;
    dy_dT.push_back(0);
    std::vector<double> dm_dT;
    dm_dT.push_back(ATAKA.get_m_0());

    int i = 0;

    system(ATAKA, dV_dT, dtetta_dT,dx_dT,dy_dT, dm_dT, i);
    std::cout<<  "\nскорость: \n";
    for (double k : dV_dT) {
        std::cout<< k << " ";
    }
    std::cout<<  "\nугол: \n";
    for (double k : dtetta_dT) {
        std::cout<< k << " ";
    }
    std::cout<<  "\nмасса: \n";
    for (double k : dm_dT) {
        std::cout<< k << " ";
    }
    return 0;
}