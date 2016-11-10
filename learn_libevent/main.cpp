//
//  main.cpp
//  learn_libevent
//
//  Created by heyong on 16/10/11.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>
#include <sys/types.h>

#include <event2/event.h>
#include <evhttp.h>

using namespace std;

void my_cb(evutil_socket_t fd, short what, void *arg)
{
    cout << "event occrence every 2 seconds." << endl;
}

void generic_request_handler(struct evhttp_request *req, void *arg)
{
    struct evbuffer *returnbuffer = evbuffer_new();
    
    evbuffer_add_printf(returnbuffer, "Thanks for the request!");
    evhttp_send_reply(req, HTTP_OK, "Client", returnbuffer);
    evbuffer_free(returnbuffer);
    
    return;
}

int main() {
//    event_base *eb;
//    eb = event_base_new();
//    if (!eb) {
//        cout << "open event base error!" << endl;
//        return -1;
//    }
//
//    timeval tv;
//    tv.tv_sec = 2;
//    tv.tv_usec = 0;
//    
//    event *ev = event_new(eb, -1, EV_PERSIST | EV_TIMEOUT, my_cb, NULL);
//    
//    evutil_socket_t evfd = event_get_fd(ev);
//    
//    event_add(ev, &tv);
//    
//    event_base_dispatch(eb);
//    
//    return 0;
    
    short http_port = 8999;
    char *http_addr = "192.168.0.22";
    struct evhttp *http_server = NULL;
    
    event_init();
    http_server = evhttp_start(http_addr, http_port);
    evhttp_set_gencb(http_server, generic_request_handler, NULL);
    
    fprintf(stderr, "Server started on port %d\n", http_port);
    
    event_dispatch();
    
    return 0;
}
