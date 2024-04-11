//
// Created by user on 11.04.2024.
//

#pragma once
//класс цели, она типа немного двигается, причем линейно, если цель двигается нелинейно, то тут будет все усложняться

class target {
private:
    double target_x_initial = 0; // начальная координата цели по х
    double target_y_initial = 0; // начальная координата цели по у
    double target_speed = 8.3;  // тут в метрах в секунду , в км в час - 30

};


