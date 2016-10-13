//
//  main.cpp
//  learn_libevent
//
//  Created by heyong on 16/10/11.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>

#include <event2/event.h>

using namespace std;

void my_cb(evutil_socket_t fd, short what, void *arg)
{
    cout << "event occrence every 2 seconds." << endl;
}

int main() {
    event_base *eb;
    eb = event_base_new();
    if (!eb) {
        cout << "open event base error!" << endl;
        return -1;
    }

    timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    
    event *ev = event_new(eb, -1, EV_PERSIST | EV_TIMEOUT, my_cb, NULL);
    
    event_add(ev, &tv);
    
    event_base_dispatch(eb);
    
    return 0;
}
