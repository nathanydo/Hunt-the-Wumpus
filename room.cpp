#include "room.h"

using namespace std;

//Room Implementation

Room::Room(){
    this->e = nullptr;
    this->has_player = false;
}

Room::~Room(){
    if(this->e != nullptr){
        delete this->e;
        this->e = nullptr;
    }
}

void Room::set_has_player(const bool player){
    this->has_player = player;
}

bool Room::get_has_player() const{
    return this->has_player;
}

void Room::make_room_empty(){
    delete this->e;
    this->e = nullptr;
    
}

bool Room::is_empty() const{
    if(e == nullptr){
        return true;
    }
    return false;
}

void Room::assign(Event* event){
    this->e = event;
}

char Room::get_char() const{
    if(this->e == nullptr){
        return ' ';
    }
    return e->get_event_char();
}

void Room::print_warnings(bool event){
    if(event == false){
        this->e->print_percept();
    }
    else;
    return;
}

void Room::events(){
    this->e->call_event();
    if(this->e->get_event_char() == 'G'){
        delete this->e;
        this->e = nullptr;
    }
    if(this->e->get_event_char() == 'A'){
        delete this->e;
        this->e = nullptr;
    }
}
