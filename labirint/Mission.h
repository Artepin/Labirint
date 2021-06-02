#pragma once
#include <sstream>
///////////////////////////////////НОМЕР МИССИИ//////////////////////////////////
int getCurrentMission(int x);//ф-ция номера миссия, которая меняет номер миссии, в зависимости от координаты игрока Х (сюда будем передавать эту координату)
std::string getTextMission(int currentMission);