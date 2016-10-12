//
//  main.cpp
//  learn_libevent
//
//  Created by heyong on 16/10/11.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>

#include "event2/event.h"

using namespace std;

//void onTime(int sock, short event, void *arg)
//{
//    cout << "Game Over!" << endl;
//    
//    struct timeval tv;
//    tv.tv_sec = 1;
//    tv.tv_usec = 0;
//    
//    event_add((struct event *)arg, &tv);
//}

int main() {
    struct event_base *eb;
//    eb = event_base_new();
//    if (!eb) {
//        cout << "open event base error!" << endl;
//        return -1;
//    }
//
//    struct timeval tv;
//    tv.tv_sec = 1;
//    tv.tv_usec = 0;
//    
//    struct event *ev = event_new(eb, -1, EV_PERSIST | EV_TIMEOUT, onTime, NULL);
//    
//    event_add(ev, &tv);
//    
//    event_base_dispatch(eb);
    
    return 0;
}
